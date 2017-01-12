package body Game_Interface is

   procedure Arduboy_Clear_Screen;
   pragma Import (C, Arduboy_Clear_Screen, "clear_screen");

   procedure Arduboy_Update_Screen;
   pragma Import (C, Arduboy_Update_Screen, "update_screen");

   procedure Arduboy_Game_Over;
   pragma Import (C, Arduboy_Game_Over, "game_over");

   procedure Arduboy_Set_Screen_Pixel (X : Integer; Y : Integer);
   pragma Import (C, Arduboy_Set_Screen_Pixel, "set_screen_pixel");

   procedure Arduboy_Delay_Ms (Ms : Unsigned_32);
   pragma Import (C, Arduboy_Delay_Ms, "delay_ms");

   procedure Arduboy_Display_Score (Score : Unsigned_32; Level : Unsigned_32);
   pragma Import (C, Arduboy_Display_Score, "display_score");

   function Arduboy_Right_Pressed return Integer;
   pragma Import (C, Arduboy_Right_Pressed, "button_right_pressed");

   function Arduboy_Turn_Pressed return Integer;
   pragma Import (C, Arduboy_Turn_Pressed, "button_turn_pressed");

   function Arduboy_Left_Pressed return Integer;
   pragma Import (C, Arduboy_Left_Pressed, "button_left_pressed");

   function Arduboy_Down_Pressed return Integer;
   pragma Import (C, Arduboy_Down_Pressed, "button_down_pressed");

   procedure Clear_Screen is
   begin
      Arduboy_Clear_Screen;
   end Clear_Screen;

   procedure Update_Screen is
   begin
      Arduboy_Update_Screen;
   end Update_Screen;

   procedure Set_Screen_Pixel (X : Integer; Y : Integer) is
   begin
      Arduboy_Set_Screen_Pixel (X, Y);
   end Set_Screen_Pixel;

   procedure Display_Score (Score : Unsigned_32; Level : Unsigned_32) is
   begin
      Arduboy_Display_Score (Score, Level);
   end Display_Score;

   procedure Delay_Ms (Ms : Unsigned_32) is
   begin
      Arduboy_Delay_Ms (Ms);
   end Delay_Ms;

   procedure Game_Over is
   begin
      Arduboy_Game_Over;
   end;

   function Button_Right_Pressed return Integer is (Arduboy_Right_Pressed);
   function Button_Turn_Pressed return Integer is (Arduboy_Turn_Pressed);
   function Button_Left_Pressed return Integer is (Arduboy_Left_Pressed);
   function Button_Down_Pressed return Integer is (Arduboy_Down_Pressed);

end Game_Interface;
