#include "raylib.h"
#include <iostream>

using namespace std;

int main(void)
{
    const int screenWidth = 1500;
    const int screenHeight = 1000;
    
    InitWindow(screenWidth, screenHeight, "Paint made by LV11coding");

    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);
    
    Color clr[14] = {BLACK, BLUE, YELLOW, RED, ORANGE, GREEN, PINK, SKYBLUE, LIME, BROWN, GOLD, GRAY, VIOLET, RAYWHITE};
    int num = 0;
    bool ch = true;
    int numdel = 0;
    bool pres = false;
    int brs = 20;

    BeginTextureMode(target);
    ClearBackground(RAYWHITE);
    EndTextureMode();

    SetTargetFPS(60);
    //HideCursor();
    GetFontDefault();
    
    while (!WindowShouldClose())
    {
        if (ch == false){
                int x = GetMouseX();
                int y = GetMouseY();

                if (IsKeyPressed(KEY_RIGHT) == true){
                    num++;
                }
                else if (IsKeyPressed(KEY_LEFT) == true)
                {
                    num--;
                }
                if (num >= 14){
                    num = 0;
                }
                else if (num < 0){
                    num = 13;
                }
                
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || (GetGestureDetected() == GESTURE_DRAG))
                {
                    BeginTextureMode(target);
                    DrawCircle(x, y, brs, clr[num]);
                    EndTextureMode();
                }
                if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
                    if (pres == false){
                        numdel = num;
                        num = 13;
                        pres = true;
                    }
                }
                else if (pres && IsMouseButtonDown(MOUSE_BUTTON_RIGHT) == false){
                    num = numdel;
                    numdel = 0;
                    pres = false;
                }
                
                if (IsKeyPressed(KEY_C) == true){
                    BeginTextureMode(target);
                    ClearBackground(RAYWHITE);
                    EndTextureMode();
                }
                
                brs += GetMouseWheelMove()*4;
                if (brs < 5){
                    brs = 5;
                }
                else if (brs > 200){
                    brs = 200;
                }
        }
                BeginDrawing();
                if (ch){
                    if (IsKeyPressed(KEY_ENTER) == false){
                        ClearBackground(DARKBLUE);
                        DrawText("Instructions:", 600, 20, 50, SKYBLUE);
                        DrawText("Left click on mouse to draw", 400, 100, 50, RAYWHITE);
                        DrawText("Right click on mouse to erase", 340, 250, 50, RAYWHITE);
                        DrawText("Right and Left key to change color", 250, 400, 50, RAYWHITE);
                        DrawText("Scroll mouse-wheel to change brush size", 300, 550, 50, RAYWHITE);
                        DrawText("Press C to clear the whole screen", 300, 700, 50, RAYWHITE);
                        DrawText("Press Enter to exit instructions and start drawing", 100, 850, 50, RAYWHITE);
                    }
                    else {
                        ch = false;
                    }
                }
                else {
                    ClearBackground(RAYWHITE);

                    Rectangle cool = (Rectangle){0, 0, (float)target.texture.width, (float)-target.texture.height};
                    DrawTextureRec(target.texture, cool, (Vector2){0, 0}, WHITE);

                    DrawCircle(GetMouseX(), GetMouseY(), brs, clr[num]);
                }
                EndDrawing();
            }
    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}
