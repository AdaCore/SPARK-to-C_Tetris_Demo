------------------------------------------------------------------------------
--                                                                          --
--                             GNAT EXAMPLE                                 --
--                                                                          --
--                      Copyright (C) 2017, AdaCore                         --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 3,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.                                     --
--                                                                          --
-- As a special exception under Section 7 of GPL version 3, you are granted --
-- additional permissions described in the GCC Runtime Library Exception,   --
-- version 3.1, as published by the Free Software Foundation.               --
--                                                                          --
-- You should have received a copy of the GNU General Public License and    --
-- a copy of the GCC Runtime Library Exception along with this program;     --
-- see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see    --
-- <http://www.gnu.org/licenses/>.                                          --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

with Interfaces;        use Interfaces;
with Tetris_Functional; use Tetris_Functional;
with Game_Interface;    use Game_Interface;

procedure Main_Tetris is

   function Fall_Period return Unsigned_32;
   --  Time to wait between each game step

   Speed_Up : Boolean := False;
   --  Is the currrent piece falling faster

   Level_Nbr    : Natural := 0;
   Score        : Natural := 0;

   Line_Counter : Natural := 0;
   --  Used to compute the level

   Nbr_Of_Complete_Lines : Natural;

   procedure Draw_Board (With_Piece : Boolean);
   --  Draw on the OLED screen the board and the falling piece

   function Random_Piece return Piece;
   --  Generate a new random piece

   Next_Piece : Piece;
   --  Next piece to be inserted in the game

   -----------------
   -- Fall_Period --
   -----------------

   function Fall_Period return Unsigned_32 is
      Interval : constant Unsigned_32 :=
        ((11 - Unsigned_32 (Level_Nbr) mod 11) * 10);
   begin
      return (if Speed_Up then Interval / 3 else Interval);
   end Fall_Period;

   ----------------
   -- Draw_Board --
   ----------------

   procedure Draw_Board (With_Piece : Boolean) is
      X_Start : constant := 1;
      Y_Start : constant := 0;

      procedure Draw_Block (X : Natural; Y : Natural);
      procedure Draw_Piece (P        : Piece;
                            Offset_X : Natural := 0;
                            Offset_Y : Natural := 0);

      ----------------
      -- Draw_Block --
      ----------------

      procedure Draw_Block (X : Natural; Y : Natural) is
         X_Pos : constant Natural := Zoom * (X - X_Coord'First);
         Y_Pos : constant Natural := Zoom * (Y - Y_Coord'First);
      begin
         for I in 1 .. Zoom loop
            for J in 1 .. Zoom loop
               Set_Screen_Pixel (X_Pos + I - 1 + X_Start,
                                 Y_Pos + J - 1 + Y_Start);
            end loop;
         end loop;
      end Draw_Block;

      ----------------
      -- Draw_Piece --
      ----------------

      procedure Draw_Piece (P        : Piece;
                            Offset_X : Natural := 0;
                            Offset_Y : Natural := 0)
      is
      begin
         case P.S is
            when O =>
               Draw_Block (P.X + Offset_X, P.Y + Offset_Y);
               Draw_Block (P.X + Offset_X, P.Y + 1 + Offset_Y);
               Draw_Block (P.X + 1 + Offset_X, P.Y + Offset_Y);
               Draw_Block (P.X + 1 + Offset_X, P.Y + 1 + Offset_Y);

            when I =>
               for Y in I_Delta loop
                  for X in I_Delta loop
                     if Possible_I_Shapes (P.D) (Y, X) then
                        Draw_Block (P.X + X + Offset_X, P.Y + Y + Offset_Y);
                     end if;
                  end loop;
               end loop;

            when Three_Shape =>
               for Y in Three_Delta loop
                  for X in Three_Delta loop
                     if Possible_Three_Shapes
                       (P.S, P.D) (Y, X)
                     then
                        Draw_Block (P.X + X + Offset_X, P.Y + Y + Offset_Y);
                     end if;
                  end loop;
               end loop;
         end case;
      end Draw_Piece;
   begin

      Display_Score (Unsigned_32 (Score), Unsigned_32 (Level_Nbr));

      --  Vertical boarders
      for Y in Y_Start .. Y_Size * Zoom loop
         Set_Screen_Pixel (X_Start - 1, Y);
         Set_Screen_Pixel (X_Start + X_Size * Zoom, Y);
      end loop;

      --  Bottom boarder
      for X in X_Start .. X_Size * Zoom loop
         Set_Screen_Pixel (X, Y_Coord'Last * Zoom);
      end loop;

      --  The board
      for Y in Y_Coord loop
         for X in X_Coord loop
            if Cur_Board (Y)(X) /= Empty then
               Draw_Block (X, Y);
            end if;
         end loop;
      end loop;

      --  The current piece
      if With_Piece then
         Draw_Piece (Cur_Piece);
      end if;

      --  Preview of the next piece displayed to the right of the board
      Draw_Piece (Next_Piece, Offset_X => 7, Offset_Y => 1);

      Update_Screen;
   end Draw_Board;

   ------------------
   -- Random_Piece --
   ------------------

   --  Simple random generator.
   Rnd : Unsigned_32 := 137;

   function Random_Piece return Piece is
   begin
      Rnd := Rnd * 1103515245 + 12345;
      return (S => Cell'Val (1 + ((Rnd / 65536) mod 7)),
              D => North,
              X => X_Size / 2,
              Y => Y_Coord'First);
   end Random_Piece;

   Success : Boolean;
begin

   Next_Piece := Random_Piece;

   --  Game loop
   Game : loop
      --  Clear board
      Cur_Board := (others => (others => Empty));
      Clear_Screen;
      Update_Screen;

      Piece : loop
         --  Add a new piece
         Cur_Piece  := Next_Piece;
         Next_Piece := Random_Piece;

         Cur_State := Piece_Falling;

         --  Stop the game when the piece cannot appear
         exit Piece when not Valid_Configuration;

         --  Clear speed up for this new piece
         Speed_Up := False;

         --  Make the piece falling
         Fall : loop

            --  At most 2 rotations or moves per fall
            for J in 1 .. 2 loop
               --  Check button
               if Button_Right_Pressed /= 0 then
                  Do_Action (Move_Right, Success);
               elsif Button_Turn_Pressed /= 0 then
                  Do_Action (Turn_Clockwise, Success);
               elsif Button_Left_Pressed /= 0 then
                  Do_Action (Move_Left, Success);
               elsif Button_Down_Pressed /= 0 then
                  Speed_Up := True;
               end if;

               Draw_Board (True);

               Delay_Ms (Fall_Period);
            end loop;

            --  Fall and continue unless the piece hits the ground
            Do_Action (Move_Down, Success);
            exit Fall when not Success;

            Draw_Board (True);
         end loop Fall;

         --  Done with that piece
         Cur_State := Piece_Blocked;

         Include_Piece_In_Board;
         Delete_Complete_Lines (Nbr_Of_Complete_Lines);

         case Nbr_Of_Complete_Lines is
         when 1 => Score := Score + 4 * (Level_Nbr + 1);
         when 2 => Score := Score + 10 * (Level_Nbr + 1);
         when 3 => Score := Score + 30 * (Level_Nbr + 1);
         when 4 => Score := Score + 120 * (Level_Nbr + 1);
         when others => null;
         end case;

         Line_Counter := Line_Counter + Nbr_Of_Complete_Lines;

         if Line_Counter >= 10 and then Level_Nbr < 10 then
            Level_Nbr    := Level_Nbr + 1;
            Line_Counter := Line_Counter - 10;
         end if;

         Delay_Ms (Fall_Period);
      end loop Piece;

      --  Lost!
      Game_Over;

      declare
         Toggle : Boolean := True;
      begin
         loop
            --  Wait for any button
            exit when Button_Right_Pressed /= 0
              or Button_Turn_Pressed /= 0
              or Button_Left_Pressed /= 0
              or Button_Down_Pressed /= 0;

            --  Change the seed of the random generator
            Rnd := Rnd + 1;

            Delay_Ms (500);

            Toggle := not Toggle;
         end loop;
      end;

      Delay_Ms (1000);
      Score        := 0;
      Level_Nbr    := 0;
      Line_Counter := 0;
   end loop Game;
end Main_Tetris;
