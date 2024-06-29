//
// Created by shehbaz on 5/10/2024.
//

#include <algorithm>
#include "Game.h"
#include "Actor.h"
#include "DrawComponent.h"

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
  // Process actor inputs
}

void Game::UpdateGame()
{
  // Update actors
}

void Game::GenerateOutput()
{
  BeginDrawing();

  ClearBackground(GRAY);

  // Render draw components of actors

  EndDrawing();
}

bool Game::IsRunning() const
{
  return (!WindowShouldClose() && mIsRunning);
}

void Game::Shutdown()
{
  UnloadData();
  CloseWindow();
}

void Game::AddActor(Actor* actor)
{
  mActorsMap[actor->GetGameState()]->emplace_back(actor);
}

void Game::RemoveActor(Actor *actor)
{
  std::vector<Actor*>* actors = mActorsMap[actor->GetGameState()];
  auto iter = std::find(actors->begin(), actors->end(), actor);
  if (iter != actors->end())
  {
    actors->erase(iter);
  }
}

void Game::AddDraw(DrawComponent *draw)
{
  std::vector<DrawComponent*>* draws = mDrawsMap[draw->GetOwner()->GetGameState()];
  int myDrawOrder = draw->GetDrawOrder();
  auto iter = draws->begin();
  while (iter != draws->end())
  {
    if (myDrawOrder < (*iter)->GetDrawOrder())
    {
      break;
    }
    ++iter;
  }
  draws->insert(iter, draw);
}

void Game::RemoveDraw(DrawComponent *draw)
{
  std::vector<DrawComponent*>* draws = mDrawsMap[draw->GetOwner()->GetGameState()];

  auto iter = std::find(draws->begin(), draws->end(), draw);
  if (iter != draws->end())
  {
    draws->erase(iter);
  }
}

void Game::UnloadData()
{
  // Delete the actors in the hash map's vector
  for (auto& pair : mActorsMap)
  {
    while (!pair.second->empty())
    {
      delete pair.second->back();
    }
  }
}

