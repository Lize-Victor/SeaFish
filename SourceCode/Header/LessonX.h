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
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class CGameMain
{
private:
	int m_iGameState; // ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������
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
	CGameMain();  // ���캯��
	~CGameMain(); // ��������

	// Get����
	int GetGameState() { return m_iGameState; }

	// Set����
	void SetGameState(const int iState) { m_iGameState = iState; }

	// ��Ϸ��ѭ����
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

	//�Զ��庯��
	CSprite *GetSpriteByName(const char* SpriteName);
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain g_GameMain;

#endif // _LESSON_X_H_