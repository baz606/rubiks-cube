//
// Created by shehbaz on 5/12/2024.
//

#ifndef RUBIKS_CUBE_ACTOR_H
#define RUBIKS_CUBE_ACTOR_H

#include <vector>
#include <unordered_map>
#include <string>

#include "Game.h"
#include "Component.h"

class Actor
{
public:

  Actor(Game* game, Game::GameState gameState);

  void Update(float deltaTime);
  void UpdateComponent(float deltaTime);
  virtual void UpdateActor(float deltaTime);

  // Setters and Getters
  void SetPosition(const Vector2& pos) { mPosition = pos; }
  void SetPosition(float x, float y) { mPosition.x = x; mPosition.y = y; }
  void SetScale(float scale) { mScale = scale; }
  void SetRotation(float rotation) { mRotation = rotation; }

  const Vector2& GetPosition() const { return mPosition; }
  float GetScale() const { return mScale; }
  float GetRotation() const { return mRotation; }
  Game* GetGame() const { return mGame; }


private:
  // Transform
  Vector2 mPosition;
  float mScale;
  float mRotation;

  std::vector<Component*> mComponents;
  std::unordered_map<std::string, Component*> mComponentsMap;

  // The game and the game state this actor has
  Game* mGame;
  Game::GameState mGameState;
};


#endif //RUBIKS_CUBE_ACTOR_H
