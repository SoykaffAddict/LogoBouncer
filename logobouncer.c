#include <stdio.h>
#include <raylib.h>
#include <time.h>

// Colors avaiable to logo
Color logo_color[] = {
	YELLOW,
	GREEN,
	PURPLE,
	RED,
	PINK,
	SKYBLUE,
	VIOLET,
	BEIGE,
	WHITE,
	LIME,
};

const int color_size = sizeof(logo_color) / sizeof(Color) - 1;

int main(void)
{
	// Screen isn't resizable
	const int SCREENWIDTH = 800;
	const int SCREENHEIGHT = 600;
	const float LOGO_SCALE = 0.10;

	// Loads
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Logo bouncer");
	SetTargetFPS(60);

	Image logo_i = LoadImage("dvd.png");
	ImageColorInvert(&logo_i);
	ImageResize(&logo_i, logo_i.width * LOGO_SCALE, 
			logo_i.height * LOGO_SCALE);

	Texture2D logo_t = LoadTextureFromImage(logo_i);
	Vector2 logo_pos = {0, 0};
	Vector2 logo_direction = {1, 1};
	int logo_speed = 100;

	while (!WindowShouldClose()) {
		//Updates
		int color_index;
		SetRandomSeed(time(0));

		if (logo_pos.x + logo_t.width >= SCREENWIDTH) {
			logo_direction.x = -logo_direction.x;
			color_index = GetRandomValue(0, color_size);
		} else if (logo_pos.x <= 0) {
			logo_direction.x = -logo_direction.x;
			color_index = GetRandomValue(0, color_size);
		} else if (logo_pos.y + logo_t.height >= SCREENHEIGHT) {
			logo_direction.y = -logo_direction.y;
			color_index = GetRandomValue(0, color_size);
		} else if (logo_pos.y <= 0) {
			logo_direction.y = -logo_direction.y;
			color_index = GetRandomValue(0, color_size);
		}

		float dt = GetFrameTime();
		logo_pos.x += logo_speed * logo_direction.x * dt;
		logo_pos.y += logo_speed * logo_direction.y * dt;


		//Drawing
		BeginDrawing();
			ClearBackground(BLACK);
			DrawTextureV(logo_t, logo_pos, logo_color[color_index]);
			DrawFPS(0,0);
		EndDrawing();
	}
}
