#pragma once
#include "../gameManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "../gameObjects/pongPaddle.hpp"
#include "../scenes/scene.hpp"
#include "../scenes/MainMenuScene.hpp"
#include <array>

#ifdef DEBUG
#endif

#define TEAM_COUNT 2
#define TUTORIAL_POPUP_COUNT 5

#define MATCH_POINT 5

class PongScene : public Minigame
{
	/**
		@brief A custom minigame object used for displaying scenes and handling game objects for Pong.
	**/
	private:
		TextMenuItem *losePrompt, *winPrompt;
		TextMenuItem *scoreBoard[TEAM_COUNT];

		SpriteMenuItem *popup, *wallpaper, *wPopup, *lPopup;
		SpriteMenuItem* tutorial[TUTORIAL_POPUP_COUNT];
		m3dCI::Button *retryBtn, *exitBtn;
		int points[TEAM_COUNT];
		int tutCount;

		int ballID, paddleID, enemyID;
		
		enum PongState
		{
			TutorialMessage,
			Requesting,
			Execute,
			Win,
			Lose
		};
		PongState currentState;
	public:
		/**
		 *  @brief Default Constructor, should be inherited by child class constructors.
		 */
		PongScene(bool showTutorial = true);

		/**
		 *  @brief Default Destructor, should be inherited by child class destructor.
		 */
		~PongScene();

		/**
		*  @brief Sets the scene backgrounds, popup windows, and game objects.
		*/
		void initialize();

		/**
		*  @brief Displays the scene backgrounds, popup windows, and game objects to the screen.
		*/
		void draw();
		
		/**
		*	@brief Responsible for loading objects.
		*	Useful later for loading save states.
		**/
		void load();
        
		/**
		*	@brief Responsible for updating objects.
		*	This is called each game frame.
		**/
		void unload();

		/**
			@brief Resets all game objects to their origin and sets the points to 0
		**/
		void reset();
        
		/**
		*  @brief Sets the current state of the game, handles collisions, and calculates the score, and requests user code.
		*/
		void update();

		/**
		*  @brief Converts user code to Lua and executes it in the sandbox.
		*/
		void SubmitPongCode(std::vector<CommandObject*> luaCode);

		/**
		*	@brief Responsible for setting initial values.
		*	(Redundant with Initialize?).
		**/
		void onEnter();


		/**
		*	@brief Responsible for deleting objects created via OnEnter.
		*	(Redundant with closeGame?).
		**/
		void onExit();

		/**
		*	@brief Responsible for determining if the Win Condition was met.
		*	@return The Win Condition 
		**/
		bool checkWinCond();

		/**
		*	@brief Responsible for loading the Scene.
		**/
		void loadScene();
		

		/**
		*	@brief Responsible for loading objects necessary for the Win Screen.
		**/
		void loadWinScr();

		/**
		*	@brief Responsible for loading objects necessary for the Lose Screen.
		**/
		void loadLoseScr();

		/**
		*	@brief Responsible for requesting specific UI Elements.
		**/
		void requestUI();

		/**
		*	@brief Responsible for properly closing out of the Minigame.
		**/
		void closeGame();
};
