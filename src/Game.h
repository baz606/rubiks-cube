//
// Created by shehbaz on 5/10/2024.
//

#ifndef RUBIKS_CUBE_GAME_H
#define RUBIKS_CUBE_GAME_H


class Game
{
public:
  Game(int screenWidth, int screenHeight, const char* title);

  void Initialize();
  void RunGame();
  void Shutdown();
  bool IsRunning() const;

  void ProcessInput();
  void UpdateGame();
  void GenerateOutput();

private:
  int mScreenWidth;
  int mScreenHeight;
  const char* mTitle;
  bool mIsRunning;
};


#endif //RUBIKS_CUBE_GAME_H
