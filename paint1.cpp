#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Paint made by LV11coding");

    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);

    BeginTextureMode(target);
    ClearBackground(RAYWHITE);
    EndTextureMode();

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        int x = GetMouseX();
        int y = GetMouseY();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || (GetGestureDetected() == GESTURE_DRAG))
        {
            BeginTextureMode(target);
            DrawCircle(x, y, 20, BLACK);
            EndTextureMode();
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        Rectangle cool = (Rectangle){0, 0, (float)target.texture.width, (float)-target.texture.height};
        DrawTextureRec(target.texture, cool, (Vector2){0, 0}, WHITE);
        
        DrawCircle(GetMouseX(), GetMouseY(), 20, BLACK);

        EndDrawing();
    }
    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}