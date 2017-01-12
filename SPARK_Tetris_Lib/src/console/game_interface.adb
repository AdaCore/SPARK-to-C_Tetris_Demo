with Ada.Text_IO;       use Ada.Text_IO;
with Ada.Real_Time;     use Ada.Real_Time;

package body Game_Interface is

   Screen : array (0 .. 128,
                   0 .. 64) of Boolean :=
     (others => (others => False));

   Score_Save : Unsigned_32 := 0;
   Level_Save : Unsigned_32 := 0;

   procedure Clear_Screen is
   begin
      Screen := (others => (others => False));
   end Clear_Screen;

   function Image (Int : Integer) return String with Inline_Always;

   function Image (Int : Integer) return String is
      Str : constant String := Int'Img;
   begin
      return Str (Str'First + 1 .. Str'Last);
   end Image;

   procedure Update_Screen is
   begin
      Put (ASCII.ESC & "[2J");
      for Y in Screen'Range (2) loop
         for X in Screen'Range (1) loop
            Put (ASCII.ESC & "[" & Image (X) & ";" & Image (Y + 1) & "H");
            Put ((if Screen (X, Y) then '#' else ' '));
         end loop;
      end loop;
      Put_Line ("Score:" & Score_Save'Img & " Level:" & Level_Save'Img);
      Clear_Screen;
   end Update_Screen;

   procedure Set_Screen_Pixel (X : Integer; Y : Integer) is
   begin
      Screen (X, Y) := True;
   end Set_Screen_Pixel;

   procedure Delay_Ms (Ms : Unsigned_32) is
   begin
      delay until Clock + Milliseconds (Integer (Ms));
   end Delay_Ms;

   procedure Display_Score (Score : Unsigned_32; Level : Unsigned_32) is
   begin
      Score_Save := Score;
      Level_Save := Level;
   end Display_Score;

   procedure Game_Over is
   begin
      Put_Line ("Game Over!!!");
   end Game_Over;

   function Button_Right_Pressed return Integer is (0);

   function Button_Turn_Pressed return Integer is (0);

   function Button_Left_Pressed return Integer is (0);

   function Button_Down_Pressed return Integer is (0);

end Game_Interface;
