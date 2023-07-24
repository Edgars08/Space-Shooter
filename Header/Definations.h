#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 700

enum DIRECTION
{
    mStill,
    mLeft,
    mRight
};

#define SPLASH_STATE_SHOW_TIME 3.0f
#define SPACE_SHIP_SPEED 600.0f
#define SPACE_SPEED 300.0f
#define LASER_SPEED 600.0f
#define METEOR_SPEED 400.0f
#define METEOR_SPAWNTIME_1 3.0f
#define METEOR_SPAWNTIME_2 6.0f
#define INITIAL_METEOR_HEIGHT 100.0f
#define EXPLOSION_TIME 0.50f
#define LOSE_POINTS 10
#define LIFE_MAX 100

// FILEPATHS
#define SPLASH_SCENE_BACKGROUND_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\Labels\\Logo_2(enlarge).png"
#define GAME_STATE_BACKGROUND_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\Backgrounds\\Free_Shmup_Sprites_Starfield.png"
#define MAINMENU_TITLE_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\Labels\\space_shot_0.png"
#define START_BUTTON_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\Labels\\pngkey.com-start-button.png"
#define EXIT_BUTTON_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\Labels\\pngkey.com-exit.png"
#define SPACE_SHIP_PLAYER_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\PNG\\playerShip1_blue.png"
#define LASER_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\PNG\\Lasers\\laserBlue03.png"
#define METEOR_1_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\PNG\\Meteors\\meteorBrown_big3.png"
#define METEOR_3_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\PNG\\Meteors\\meteorBrown_small1.png"
#define METEOR_2_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\PNG\\Meteors\\meteorGrey_big3.png"
#define METEOR_4_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\PNG\\Meteors\\meteorGrey_small2.png"
#define EXPLOSION_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\Labels\\bomb_explosion2.png"
#define FONT_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\Space-Shooter\\Res\\Bonus\\kenvector_future.ttf"