#pragma once
#pragma once
#include <vector>
#include <minwindef.h>
#include "System.h"
using namespace std;
struct tagImageInfo
{
	int				nWidth;
	int				nHeight;
	int				nFWidth;
	int				nFHeight;
	int				nFrameXMax;		// ���������� ������ �׸�����
	int				nFrameYMax;		// ���������� ������ �׸�����
};

typedef struct tagTileInfo
{
	bool			IsUseFlag;
	int				Alpha;
	int				ImageIndex;
	POINT			ptSelectPos;
}TILEINFO;


template<class T> class CSSINGLETON
{
private:
	static T* m_pInstance;

public:
	CSSINGLETON() { m_pInstance = (T*)this; }
	~CSSINGLETON() { m_pInstance = 0; }
	static T& GetInstance() { return (*m_pInstance); }
	static T* GetInstancePtr() { return m_pInstance; }
};
template <class T> T* CSSINGLETON<T>::m_pInstance = 0;

class Image
{
private:
	HDC						m_MemDC;		// �޸�DC (�̰��� �׸��� �����ȴ�)
	HBITMAP					m_bit, m_obit;
	BYTE*					m_pData;
	DWORD					m_dwPitch;
	tagImageInfo			m_Info;


private:
	HBITMAP GetBit(TCHAR* szFileName);
	void Flip();


public:
	Image(TCHAR* szFileName, tagImageInfo Info);
	virtual ~Image();

	void Render(HDC hDest, int nX, int nY, bool bColorKey = false, int nFrameX = 0, int nFrameY = 0);
	void Render(HDC hDest, int iDestLeft, int iDestTop, int iDestRight, int iDestBottom, int iSourLeft, int iSourTop, int iSourRight, int iSourBottom);
	void RenderAlpha(HDC hDest, HDC hAlpha, int nX, int nY, bool bColorKey = false, int nFrameX = 0, int nFrameY = 0, int Alpha = 255);
	void RenderAlpha(HDC hDest, HDC hAlpha, int nX, int nY, int nRight, int nBottom, int nSourX, int nSourY, int Alpha);

	HDC GetMemDC() { return m_MemDC; }
	int GetImageWidth() const { return m_Info.nFWidth; }
	int GetImageHeight() const { return m_Info.nFHeight; }
	int GetMaxFrameX() { return m_Info.nFrameXMax; }
};

class CImageManager : public CSSINGLETON < CImageManager >
{
private:
	std::vector<Image*>	m_vImage;

	HDC						m_hdc;				// ȭ�� DC
	HDC						m_MDlghdc;
	HDC						m_back;				// ������ DC (������۸�)
	HDC						m_dlgback;
	HDC						m_dlgminimap;
	HDC						m_Alpha;			// ���ĺ��� DC (����)


public:
	CImageManager();
	virtual ~CImageManager();

	bool Init();								// �ʱ�ȭ (�����ڿ����ϰԵɰ�� HDC = GetDC(g_hWnd) ���� ���װ�����)
	bool Release();
	void CreateImage(TCHAR* szFileName, int FrameXMax, int FrameYMax);

	Image* GetImage(int Number) { return m_vImage[Number]; }
	HDC GetHdc() { return m_hdc; }
	HDC GetBack() { return m_back; }
	HDC GetDlgBack() { return m_dlgback; }
	HDC GetDlgMinimap() { return m_dlgminimap; }
	HDC GetAlpha() { return m_Alpha; }

	Image* operator[](int Index) { return m_vImage[Index]; }
};

#define S_IMAGE	CImageManager::GetInstance()
#define RGB_VALUE RGB(255, 0, 255)