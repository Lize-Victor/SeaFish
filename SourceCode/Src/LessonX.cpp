/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"
#include <string.h>
#include <cmath>
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain g_GameMain;

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
	m_iGameState = 1;
	m_pYellowFish = new CSprite("yellowfish");
	m_pBlueFish = new CSprite("bluefish");
	m_pFollowMouseFish = new CSprite("followMouseFish");
	m_fScreenBottom = 0;
	m_fScreenRight = 0;
	m_fScreenLeft = 0;
	m_fScreenTop = 0;

	m_fSpeedBottom = 0;
	m_fSpeedLeft = 0;
	m_fSpeedRight = 0;
	m_fSpeedTop = 0;
}
//==============================================================================
//
// ��������
CGameMain::~CGameMain()
{
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop(float fDeltaTime)
{
	switch (GetGameState())
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
	{
		GameInit();
		SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
	}
	break;

	// ��Ϸ�����У�����������Ϸ�߼�
	case 2:
	case 3:
	{
		// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
		if (true)
		{
			GameRun(fDeltaTime);
		}
		else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
		{
			SetGameState(0);
			GameEnd();
		}
	}
	break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void CGameMain::GameInit()
{
	m_pYellowFish->SetSpriteLinearVelocity(20, 0);
	m_fScreenBottom = CSystem::GetScreenBottom();
	m_fScreenRight = CSystem::GetScreenRight();
	m_fScreenTop = CSystem::GetScreenTop();
	m_fScreenLeft = CSystem::GetScreenLeft();
	m_pYellowFish->SetSpriteWorldLimit(WORLD_LIMIT_NULL, m_fScreenLeft, m_fScreenTop, m_fScreenRight, m_fScreenBottom);

	for (int i = 0; i < 3; i++)
	{
		char *destFish = CSystem::MakeSpriteName("rockfish", i);
		CSprite *tmpFish = new CSprite(destFish);
		tmpFish->CloneSprite("rockfishTemplate");
		float tempFishX = CSystem::RandomRange(m_fScreenLeft + 10.f, m_fScreenRight - 10.f);
		float tempFishY = CSystem::RandomRange(m_fScreenTop, m_fScreenBottom);
		tmpFish->SetSpritePosition(tempFishX, tempFishY);
		float fSpeedX = CSystem::RandomRange(3, 20);
		tmpFish->SetSpriteLinearVelocity(fSpeedX, 0);
		RockFishs.push_back(tmpFish);
		tmpFish->SetSpriteWorldLimit(WORLD_LIMIT_NULL, m_fScreenLeft - 20.f, m_fScreenTop, m_fScreenRight + 20.f, m_fScreenBottom);
	}
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun(float fDeltaTime)
{
}
//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseMove(const float fMouseX, const float fMouseY)
{
	if (m_iGameState == 2)
	{
		m_pFollowMouseFish->SetSpritePosition(fMouseX, fMouseY);
		m_iGameState = 3;
	}
	float distance = sqrt(pow(fMouseX - m_pFollowMouseFish->GetSpritePositionX(), 2) + pow(fMouseY - m_pFollowMouseFish->GetSpritePositionY(), 2));
	float speed = 5 * distance;
	if (fMouseX > m_pFollowMouseFish->GetSpritePositionX())
	{
		m_pFollowMouseFish->SetSpriteFlipX(false);
	}
	else if (fMouseX < m_pFollowMouseFish->GetSpritePositionX())
	{
		m_pFollowMouseFish->SetSpriteFlipX(true);
	}

	m_pFollowMouseFish->SpriteMoveTo(fMouseX, fMouseY, speed, true);
}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY)
{
}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseUp(const int iMouseType, const float fMouseX, const float fMouseY)
{
}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void CGameMain::OnKeyDown(const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress)
{
	switch (iKey)
	{
	case KEY_D:
		m_fSpeedRight = 20;
		break;
	case KEY_A:
		m_fSpeedLeft = -20;
		break;
	case KEY_W:
		m_fSpeedTop = -20;
		break;
	case KEY_S:
		m_fSpeedBottom = 20;
		break;
	default:
		break;
	}
	if (m_fSpeedRight + m_fSpeedLeft)
	{
		if (m_fSpeedRight + m_fSpeedLeft < 0)
			m_pBlueFish->SetSpriteFlipX(true);
		else
			m_pBlueFish->SetSpriteFlipX(false);
	}
	m_pBlueFish->SetSpriteLinearVelocity(m_fSpeedRight + m_fSpeedLeft, m_fSpeedTop + m_fSpeedBottom);
}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void CGameMain::OnKeyUp(const int iKey)
{
	switch (iKey)
	{
	case KEY_D:
		m_fSpeedRight = 0;
		break;
	case KEY_A:
		m_fSpeedLeft = 0;
		break;
	case KEY_W:
		m_fSpeedTop = 0;
		break;
	case KEY_S:
		m_fSpeedBottom = 0;
		break;
	default:
		break;
	}
	if (m_fSpeedRight + m_fSpeedLeft)
	{
		if (m_fSpeedRight + m_fSpeedLeft < 0)
			m_pBlueFish->SetSpriteFlipX(true);
		else
			m_pBlueFish->SetSpriteFlipX(false);
	}
	m_pBlueFish->SetSpriteLinearVelocity(m_fSpeedRight + m_fSpeedLeft, m_fSpeedTop + m_fSpeedBottom);
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void CGameMain::OnSpriteColSprite(const char *szSrcName, const char *szTarName)
{
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit(const char *szName, const int iColSide)
{
	CSprite *tempFish = GetSpriteByName(szName);
	// m_pYellowFish->SetSpriteLinearVelocity(0, 0);
	if (!strcmp(szName, "yellowfish"))
	{
		if (iColSide == 1)
		{
			m_pYellowFish->SetSpriteFlipX(true);
			m_pYellowFish->SetSpriteLinearVelocity(-20, 0);
		}
		else if (iColSide == 0)
		{
			m_pYellowFish->SetSpriteFlipX(false);
			m_pYellowFish->SetSpriteLinearVelocity(20, 0);
		}
	}
	else if (tempFish != nullptr)
	{
		if (iColSide == 1)
		{
			tempFish->SetSpriteLinearVelocity(-15, 0);
			tempFish->SetSpriteFlipX(true);
		}
		else if (iColSide == 0)
		{
			tempFish->SetSpriteLinearVelocity(15, 0);
			tempFish->SetSpriteFlipX(false);
		}
	}
}
//===========================================================================
//
// ���ݾ������ֲ��Ҿ���
// ����ֵ ���ҵ� ����ָ��
// ����ֵ ���Ҳ��� ��ָ��
CSprite *CGameMain::GetSpriteByName(const char *SpriteName)
{
	for (int i = 0; i < RockFishs.size(); i++)
	{
		if (!strcmp(RockFishs[i]->GetName(), SpriteName))
			return RockFishs[i];
	}
	return nullptr;
}
