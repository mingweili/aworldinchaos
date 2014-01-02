#ifndef PLAYER_H
#define PLAYER_H

#include "..\\主体\\MyHGE.h"
#include "..\\资源管理\\ResourceManager.h"

//ÓÃÀ´ÅÐ¶Ï¾«ÁéÃæ²¿³¯Ïò
#define   FaceLeft       -1
#define   FaceRight       1

enum PlayerState{WALKING = 0, FALLING, CLIMBING_DOWN, CLIMBING_UP, TRANSFORMING, DRILL};
enum GameState{DEAD = 0, SUCCESS, GOON};


#define PLAYERHEIGHT 80  
#define PLAYERWIDTH  60  

#define GRAVITY 25

//Ð¡ÈËÃ¿´Î×ßµÄÎ»ÒÆ
#define WALKSPEED 5

enum KEYDIRECTION{KEY_LEFT, KEY_RIGHT};

class Player
{
public :
	static Player* getPlayer(unsigned int  = 0);

	int getWidth(){ return width;};
	void setWidth(int width){this -> width = width;};

	int getHeight(){ return height; };
	void setHeight(int height) { this -> height = height; };

	inline void setX(float _x){x = _x;};
	inline void setY(float _y){y = _y;};

	inline void setNextPosition(float _next_x, float _next_y) {next_x = _next_x; next_y = _next_y;};

	inline void setSpeedX(float _SpeedX){SpeedX = _SpeedX;};
	inline void setSpeedY(float _SpeedY){SpeedY = _SpeedY;};

	inline float getX() const {return x;};
	inline float getY() const {return y;};

	inline float getSpeedX() const {return SpeedX;};
	inline float getSpeedY() const {return SpeedY;};

	inline float getDx() const {return dx;};
	inline float getDy() const {return dy;};

	inline void setDx(float _dx){dx = _dx;};
	inline void setDy(float _dy){dy = _dy;};

	inline KEYDIRECTION getKeyDirection() {return KeyDirection;};

	inline PlayerState getState() const {return state;};
	
	inline void setState(PlayerState _state)
	{
		state = _state;
		switch (state)
		{
		case WALKING : 
			anima = anima_walk;
			break;
		case FALLING :
			anima = anima_fall;
			break;
		case CLIMBING_UP :
		case CLIMBING_DOWN :
			anima = anima_climb;
			break;
		case DRILL :
			anima = anima_climb;
			break;
		default :
			anima = anima_walk;
			break;
		}
	};

	inline void setSuper() {super = true;};
	inline bool getSuper() {return super;};

	inline HEFFECT getSound()
	{
		if(state == WALKING)
			return YellSound;
		else if(state == FALLING)
			return ShoutSound;
	};

	void KeyboardInput();
    
	void logic()
	{
		//ÒÔºóÔÙ´Ë´¦Ð´Ð¡ÈËÊ±¼äµÄÂß¼­
	};

	void UpdatePos( float );

	void render();

private :
	static Player* instance;
	Player();
	static int level_id;

	//Ð¡ÈËµÄ¿í¡¢¸ß
	static int width;
	static int height;

	//x£¬y×ø±ê
	static float x;
	static float y;	

	//ÓÃÓÚ×ê¶´Ê±µÄÏÂÒ»¸ö×ø±ê
	float next_x;
	float next_y;
	
	//·ÖËÙ¶È
	float SpeedX;
	float SpeedY;

	float dx;
	float dy;


	//renderËùÓÃµÄÖ¸Õë
	hgeAnimation* anima;
	hgeAnimation* anima_walk;
	hgeAnimation* anima_fall;
    hgeAnimation* anima_climb;
	//ÓÃÀ´¸Ä±ä¾«ÁéµÄ³¯Ïò
	int facepoint;

	//ÓÃÀ´ÅÐ¶Ïµ±Ç°ÔËÐÐ×´Ì¬
	int anima_currentstate;
	KEYDIRECTION KeyDirection;

	//Íæ¼ÒµÄ×´Ì¬
	PlayerState state;

	bool super;

	HEFFECT YellSound;
	HEFFECT ShoutSound;
};

#endif