//
// Created by shehbaz on 5/10/2024.
//

#include "raylib.h"

#include "Game.h"

Game::Game(int screenWidth, int screenHeight, const char *title)
:mScreenWidth(screenWidth)
,mScreenHeight(screenHeight)
,mTitle(title)
,mIsRunning(true)
{
}

void Game::Initialize()
{
  InitWindow(mScreenWidth, mScreenHeight, mTitle);
  SetTargetFPS(60);
  SetTraceLogLevel(LOG_ERROR);
}

void Game::RunGame()
{
  ProcessInput();
  UpdateGame();
  GenerateOutput();
}

void Game::ProcessInput()
{
}

void Game::UpdateGame()
{
}

void Game::GenerateOutput()
{
  BeginDrawing();

  ClearBackground(GRAY);

  const char* text = "Hello Rubik's Cube!";
  Vector2 textLength = MeasureTextEx(GetFontDefault(), text, 48, 1.f);
  DrawTextPro(GetFontDefault(), text, { (float)mScreenWidth / 2, (float)mScreenHeight / 2 },
              { textLength.x / 2, textLength.y / 2 }, 0.f, 48, 1.f, VIOLET);

  EndDrawing();
}

bool Game::IsRunning() const
{
  return (!WindowShouldClose() && mIsRunning);
}

void Game::Shutdown()
{
  CloseWindow();
}

