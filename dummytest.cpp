#include "raylib.h"
#include <iostream>

using namespace std;

int main(void)
{
    const int screenWidth = 1500;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Paint made by LV11coding");

    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);
    
    Color clr[5] = {BLACK, BLUE, YELLOW, RED, ORANGE};
    int num = 0;
    bool ch = true;

    BeginTextureMode(target);
    ClearBackground(RAYWHITE);
    EndTextureMode();

    SetTargetFPS(60);
    GetFontDefault();
    
    while (!WindowShouldClose())
    {
        int x = GetMouseX();
        int y = GetMouseY();

                if (IsKeyPressed(KEY_SPACE) == true){
                    num++;
                }
                if (num >= 5){
                    num = 0;
                }
                
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || (GetGestureDetected() == GESTURE_DRAG))
                {
                    BeginTextureMode(target);
                    DrawCircle(x, y, 20, clr[num]);
                    EndTextureMode();
                }
                
                if (ch == false){
                        if (IsKeyPressed(KEY_C) == true){
                        BeginTextureMode(target);
                        ClearBackground(RAYWHITE);
                        EndTextureMode();
                    }
                }
                BeginDrawing();
                if (ch){
                    if (IsKeyPressed(KEY_ENTER) == false){
                        DrawText("Instructions:", 650, 50, 50, RAYWHITE);
                        DrawText("Left click on mouse to draw", 500, 300, 50, RAYWHITE);
                        DrawText("Press Space to change colors", 400, 500, 50, RAYWHITE);
                        DrawText("Press Enter to exit instructions and start drawing", 100, 700, 50, RAYWHITE);
                    }
                    else {
                        ch = false;
                    }
                }
                else {
                    ClearBackground(RAYWHITE);

                    Rectangle cool = (Rectangle){0, 0, (float)target.texture.width, (float)-target.texture.height};
                    DrawTextureRec(target.texture, cool, (Vector2){0, 0}, WHITE);

                    DrawCircle(GetMouseX(), GetMouseY(), 20, clr[num]);
                }
                EndDrawing();
            }
    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}


// Clear function suggested by AndreyDimitrov3 on GitHub //