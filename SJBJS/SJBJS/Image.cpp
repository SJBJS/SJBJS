#include "Image.h"
HWND				g_hWnd = NULL;
int	g_iCellSize = 0;
Image::Image(TCHAR* szFileName, tagImageInfo Info)
{
	m_Info = Info;

	HDC hdc = GetDC(g_hWnd);
	m_MemDC = CreateCompatibleDC(hdc);
	m_bit = GetBit(szFileName);
	m_obit = (HBITMAP)SelectObject(m_MemDC, m_bit);

	ReleaseDC(g_hWnd, hdc);
}

Image::~Image()
{
	SelectObject(m_MemDC, m_obit);
	DeleteObject(m_bit);
	DeleteDC(m_MemDC);
}

// -----------------------------------------------------------------------------
// Name: GetBit
// Desc: ��Ʈ���� ���� ������ HBITMAP���� ����
// -----------------------------------------------------------------------------
HBITMAP Image::GetBit(TCHAR* szFileName)
{
	HANDLE				hFile;
	BITMAPFILEHEADER	fh;
	BITMAPINFO*			ih;
	DWORD				dwRead;
	DWORD				dwInfoSize;
	HBITMAP				bit;
	
	hFile = CreateFile(szFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(hFile, &fh, sizeof(fh), &dwRead, NULL);
	dwInfoSize = fh.bfOffBits - sizeof(fh);
	ih = (BITMAPINFO*) new BYTE[dwInfoSize];
	ReadFile(hFile, ih, dwInfoSize, &dwRead, NULL);

	ih->bmiHeader.biHeight *= -1;
	bit = CreateDIBSection(NULL, ih, DIB_RGB_COLORS, (void**)&m_pData, NULL, 0);
	ih->bmiHeader.biHeight *= -1;

	m_Info.nWidth = ih->bmiHeader.biWidth;
	m_Info.nHeight = ih->bmiHeader.biHeight;
	m_Info.nFWidth = m_Info.nWidth / m_Info.nFrameXMax;
	m_Info.nFHeight = m_Info.nHeight / m_Info.nFrameYMax;
	m_dwPitch = (m_Info.nWidth * (ih->bmiHeader.biBitCount >> 3)) + 3 & ~3;

	ReadFile(hFile, m_pData, fh.bfSize - fh.bfOffBits, &dwRead, NULL);
	Flip();

	CloseHandle(hFile);
	delete[] ih;

	return bit;
}

// -----------------------------------------------------------------------------
// Name: Flip
// Desc: 
// -----------------------------------------------------------------------------
void Image::Flip(void)
{
	int			i;

	BYTE*	pTemp;

	pTemp = new BYTE[m_dwPitch];

	for (i = 0; i < m_Info.nHeight / 2; i++)
	{
		memcpy(pTemp, &m_pData[i * m_dwPitch], m_dwPitch);
		memcpy(&m_pData[i * m_dwPitch], &m_pData[(m_Info.nHeight - 1 - i)  * m_dwPitch], m_dwPitch);
		memcpy(&m_pData[(m_Info.nHeight - 1 - i)  * m_dwPitch], pTemp, m_dwPitch);
	}
	delete[] pTemp;
}

// -----------------------------------------------------------------------------
// Name: Render
// Desc: ȭ�� ��� �ִϸ��̼� ���
// -----------------------------------------------------------------------------
void Image::Render(HDC hDest, int nX, int nY, bool bColorKey, int nFrameX, int nFrameY)
{
	if (bColorKey)
	{
		TransparentBlt(hDest, nX, nY, m_Info.nFWidth, m_Info.nFHeight,
			m_MemDC, nFrameX * m_Info.nFWidth, nFrameY * m_Info.nFHeight, m_Info.nFWidth, m_Info.nFHeight, RGB_VALUE);
	}
	else
	{
		BitBlt(hDest, nX, nY, m_Info.nFWidth, m_Info.nFHeight, m_MemDC,
			nFrameX * m_Info.nFWidth, nFrameY * m_Info.nFHeight, SRCCOPY);
	}
}

// -----------------------------------------------------------------------------
// Name: Render
// Desc: ȭ�� ��� ������ �����θ� ���
// -----------------------------------------------------------------------------
void Image::Render(HDC hDest, int iDestLeft, int iDestTop, int iDestRight, int iDestBottom, int iSourLeft, int iSourTop, int iSourRight, int iSourBottom)
{
	TransparentBlt(hDest, iDestLeft, iDestTop, iDestRight, iDestBottom, m_MemDC, iSourLeft, iSourTop, iSourRight, iSourBottom, RGB_VALUE);
}

// -----------------------------------------------------------------------------
// Name: RenderAlpha
// Desc: ������ �����ؼ� ����Ѵ�
// -----------------------------------------------------------------------------
void Image::RenderAlpha(HDC hDest, HDC hAlpha, int nX, int nY, bool bColorKey, int nFrameX, int nFrameY, int Alpha)
{
	int TempX = 1, TempY = 1;
	int TempRivisionX = 0, TempRivisionY = 0;

	if (nX < 0)
	{
		TempX = 0;
		TempRivisionX = nX * -1;
	}

	if (nY < 0)
	{
		TempY = 0;
		TempRivisionY = nY * -1;
	}

	// ���ĺ��� MemDC�� ����� �����Ѵ�
	TransparentBlt(hAlpha, 0, 0, m_Info.nFWidth, m_Info.nFHeight, hDest, nX * TempX, nY * TempY,
		m_Info.nFWidth - TempRivisionX, m_Info.nFHeight - TempRivisionY, RGB_VALUE);

	// ���ĺ��� MemDC�� ���� ����� �����Ѵ�
	TransparentBlt(hAlpha, 0, 0, m_Info.nFWidth, m_Info.nFHeight, m_MemDC, nFrameX * m_Info.nFWidth * TempX + TempRivisionX, nFrameY * m_Info.nFHeight * TempY + TempRivisionY,
		m_Info.nFWidth - TempRivisionX, m_Info.nFHeight - TempRivisionY, RGB_VALUE);

	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = Alpha; // ���� ����
	bf.AlphaFormat = 0;

	// ����ۿ� �ϼ��� ���ĺ��� MemDC�� ������
	AlphaBlend(hDest, nX * TempX, nY * TempY, m_Info.nFWidth - TempRivisionX, m_Info.nFHeight - TempRivisionY,
		hAlpha, 0, 0, m_Info.nFWidth, m_Info.nFHeight, bf);
}

void Image::RenderAlpha(HDC hDest, HDC hAlpha, int nX, int nY, int nRight, int nBottom, int nSourX, int nSourY, int Alpha)
{
	if (Alpha == 255)
	{
		TransparentBlt(hDest, nX, nY, nRight, nBottom, m_MemDC, nSourX, nSourY, g_iCellSize, g_iCellSize, RGB_VALUE);
		return;
	}

	// ���ĺ��� MemDC�� ����� �����Ѵ�
	TransparentBlt(hAlpha, 0, 0, g_iCellSize, g_iCellSize, hDest, nX, nY, g_iCellSize, g_iCellSize, RGB_VALUE);

	// ���ĺ��� MemDC�� ���� ����� �����Ѵ�
	TransparentBlt(hAlpha, 0, 0, g_iCellSize, g_iCellSize, m_MemDC, nSourX, nSourY, g_iCellSize, g_iCellSize, RGB_VALUE);

	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = Alpha; // ���� ����
	bf.AlphaFormat = 0;

	// ����ۿ� �ϼ��� ���ĺ��� MemDC�� ������
	AlphaBlend(hDest, nX, nY, nRight, nBottom, hAlpha, 0, 0, g_iCellSize, g_iCellSize, bf);
}



// �� CImage Class
// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
// �� CImageManager Class



CImageManager::CImageManager()
{
}
CImageManager::~CImageManager()
{
	Release();
}

bool CImageManager::Init()
{
	// HDC ����
	m_hdc = GetDC(g_hWnd);

	// �̹��� ����
	CreateImage(TEXT("Image/back.bmp"), 1, 1);
	CreateImage(TEXT("Image/dlgback.bmp"), 1, 1);
	CreateImage(TEXT("Image/minimap.bmp"), 1, 1);
	CreateImage(TEXT("Image/client.bmp"), 1, 1);
	CreateImage(TEXT("Image/alpha.bmp"), 1, 1);
	CreateImage(TEXT("Image/map.bmp"), 1, 1);
	CreateImage(TEXT("Image/Tile1.bmp"), 1, 1);
	CreateImage(TEXT("Image/Tile2.bmp"), 1, 1);
	CreateImage(TEXT("Image/Tile3.bmp"), 1, 1);
	CreateImage(TEXT("Image/Select.bmp"), 1, 1);


	// �����, ���� ���� �޸� ����
	/*m_back = m_vImage[IMG_BACK]->GetMemDC();
	m_dlgback = m_vImage[IMG_DLGBACK]->GetMemDC();
	m_dlgminimap = m_vImage[IMG_DLGMINIMAP]->GetMemDC();
	m_Alpha = m_vImage[IMG_ALPHA]->GetMemDC();
*/
	return true;
}


bool CImageManager::Release()
{
	for (int i = 0; i < (int)m_vImage.size(); i++)
	{
		delete m_vImage[i];
	}
	m_vImage.clear();

	return true;
}

void CImageManager::CreateImage(TCHAR* szFileName, int FrameXMax, int FrameYMax)
{
	tagImageInfo Info;
	memset(&Info, 0x0000, sizeof(Info));
	Info.nFrameXMax = FrameXMax;
	Info.nFrameYMax = FrameYMax;

	Image* TempImage = new Image(szFileName, Info);

	m_vImage.push_back(TempImage);
}