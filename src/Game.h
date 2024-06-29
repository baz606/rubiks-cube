//
// Created by shehbaz on 5/10/2024.
//

#ifndef RUBIKS_CUBE_GAME_H
#define RUBIKS_CUBE_GAME_H

#include "raylib.h"
#include <unordered_map>
#include <vector>

class Actor;
class DrawComponent;

class Game
{
public:

  enum GameState
  {
    PLAYING
  };

  Game(int screenWidth, int screenHeight, const char* title);

  void Initialize();
  void RunGame();
  void Shutdown();

  // Add/Remove actors from the game
  void AddActor(Actor* actor);
  void RemoveActor(Actor* actor);

  // Add/Remove Draw Components
  void AddDraw (DrawComponent *draw);
  void RemoveDraw (DrawComponent *draw);


  [[nodiscard]] bool IsRunning() const;

private:
  // Main game loop
  void ProcessInput();
  void UpdateGame();
  void GenerateOutput();

  // Deallocate any memory on the heap
  void UnloadData();

  int mScreenWidth;
  int mScreenHeight;
  const char* mTitle;
  GameState mGameState;
  bool mIsRunning;

  // Actor HashMap -> Update actors based on game state
  std::unordered_map<GameState, std::vector<Actor*>*> mActorsMap;
  // DrawComponent HashMap -> Render actor draw component based on game state
  std::unordered_map<GameState, std::vector<DrawComponent*>*> mDrawsMap;
};


#endif //RUBIKS_CUBE_GAME_H
