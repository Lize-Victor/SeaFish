/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include <Windows.h>
#include <vector>
using std::vector;
/////////////////////////////////////////////////////////////////////////////////
//
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class CGameMain
{
private:
	int m_iGameState; // 游戏状态，0：结束或者等待开始；1：初始化；2：游戏进行中
	CSprite *m_pYellowFish;
	CSprite *m_pBlueFish;
	CSprite *m_pFollowMouseFish;

	vector<CSprite*> RockFishs;

	float m_fScreenTop;
	float m_fScreenBottom;
	float m_fScreenLeft;
	float m_fScreenRight;

	float m_fSpeedRight;
	float m_fSpeedLeft;
	float m_fSpeedTop;
	float m_fSpeedBottom;
public:
	CGameMain();  // 构造函数
	~CGameMain(); // 析构函数

	// Get方法
	int GetGameState() { return m_iGameState; }

	// Set方法
	void SetGameState(const int iState) { m_iGameState = iState; }

	// 游戏主循环等
	void GameMainLoop(float fDeltaTime);
	void GameInit();
	void GameRun(float fDeltaTime);
	void GameEnd();
	void OnMouseMove(const float fMouseX, const float fMouseY);
	void OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY);
	void OnMouseUp(const int iMouseType, const float fMouseX, const float fMouseY);
	void OnKeyDown(const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress);
	void OnKeyUp(const int iKey);
	void OnSpriteColSprite(const char *szSrcName, const char *szTarName);
	void OnSpriteColWorldLimit(const char *szName, const int iColSide);

	//自定义函数
	CSprite *GetSpriteByName(const char* SpriteName);
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain g_GameMain;

#endif // _LESSON_X_H_