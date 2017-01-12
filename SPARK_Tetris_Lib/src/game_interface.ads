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

with Interfaces; use Interfaces;

package Game_Interface is

   Zoom : constant := 3;
   --  Number of pixel to represent one block in the game

   procedure Clear_Screen;

   procedure Update_Screen;

   procedure Set_Screen_Pixel (X : Integer; Y : Integer);

   procedure Display_Score (Score : Unsigned_32; Level : Unsigned_32);

   procedure Game_Over;

   procedure Delay_Ms (Ms : Unsigned_32);

   function Button_Right_Pressed return Integer;

   function Button_Turn_Pressed return Integer;

   function Button_Left_Pressed return Integer;

   function Button_Down_Pressed return Integer;

end Game_Interface;
