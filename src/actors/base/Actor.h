//
// Created by shehbaz on 5/12/2024.
//

#ifndef RUBIKS_CUBE_ACTOR_H
#define RUBIKS_CUBE_ACTOR_H

#include <string>
#include <vector>
#include <unordered_map>
#include "raylib.h"
#include "Game.h"

class Component;

class Actor
{
public:
  Actor(Game* game, Game::GameState gameState);
  virtual ~Actor();

  void Update(float deltaTime);
  void UpdateComponents(float deltaTime);
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
  Game::GameState GetGameState() const { return mGameState; }

  // Add/Remove components
  void AddComponent(Component* component);
  void RemoveComponent(Component* component);

  // Add/Remove components from hash map
  void AddComponentToMap(std::string& name, Component* component);
  void RemoveComponentFromMap(std::string& name);

  // Get component from hash map
  Component* GetComponent(const std::string& name);


private:
  // Transform
  Vector2 mPosition{};
  float mScale{};
  float mRotation{};

  std::vector<Component*> mComponents;
  std::unordered_map<std::string, Component*> mComponentsMap;

  // The game and the game state this actor has
  Game* mGame{};
  Game::GameState mGameState;
};


#endif //RUBIKS_CUBE_ACTOR_H
