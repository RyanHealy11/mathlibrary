#include "raylib.h"
#include "transform2d.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	transform2d mommy;
	mommy.localPos = { 200,200 };
	//mommy.localRot = 50;
	vec2 momWorld = mommy.worldPosition();
	Rectangle momrec{ momWorld.x, momWorld.y, 100,100 };
	
	transform2d child;
	child.localPos = { 50,50 };
	child.setParent(&mommy);
	vec2 childworld = child.worldPosition();
	Rectangle childrec{ childworld.x,childworld.y,50,50 };
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		childworld = child.worldPosition();
		momWorld = mommy.worldPosition();

		momrec.x = momWorld.x;
		momrec.y = momWorld.y;
		childrec.x = childworld.x;
		childrec.y = childworld.y;

		if (IsKeyDown(KEY_DOWN)) 
		{
			mommy.translate({0, 100 * GetFrameTime()});
		}
		if (IsKeyDown(KEY_UP))
		{
			mommy.translate({ 0, -100 * GetFrameTime() });
		}
		if (IsKeyDown(KEY_LEFT))
		{
			mommy.translate({ -100 * GetFrameTime(), 0 });
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			mommy.translate({ 100 * GetFrameTime(), 0 });
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		Rectangle bitch{ 20,20,20,20 };
		//DrawRectangle( 10,10,10,10, BLUE);
		DrawRectanglePro(momrec, {momrec.width/2,momrec.height/2},mommy.localRot,BLUE);
		DrawRectanglePro(childrec, { childrec.width / 2, childrec.height / 2 }, child.localRot, RED);
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}