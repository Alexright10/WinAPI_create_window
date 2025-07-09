#include "framework.h"
#include "HeadSource.h"

extern HINSTANCE hInst;
extern HWND hWndS;
LRESULT CALLBACK SashaWind(HWND, UINT, WPARAM, LPARAM);


BOOL Base::new_Win()
{
	WNDCLASSEXW wcexn = {0};

    wcexn.cbSize = sizeof(WNDCLASSEX);

    wcexn.style = CS_HREDRAW | CS_VREDRAW;
    wcexn.lpfnWndProc = SashaWind;
   // wcexn.cbClsExtra = 0; 
   // wcexn.cbWndExtra = 0;
    wcexn.hInstance = hInst;
   // wcexn.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcexn.hCursor = LoadCursor(nullptr, IDC_CROSS);
    wcexn.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
 //   wcexn.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcexn.lpszClassName = _T("Sasha_Proc");
    //wcexn.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

     RegisterClassExW(&wcexn);

          hWndS = CreateWindowW(_T("Sasha_Proc"), _T("FirsWind"), WS_OVERLAPPEDWINDOW,
             CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst, nullptr);

         if (!hWndS)
         {
             return FALSE;
         }

         ShowWindow(hWndS, SW_SHOW);
         UpdateWindow(hWndS);

         return TRUE;
     
}
void Base::createMap()
{
    TCHAR str[10];
    int x, y;
    for (x = -20; x < 21; ++x)
        ms[x] = x * x;
    map<int, int> :: iterator it;
    int i = 0 ,z,h;
    HDC hdc = GetDC(hWndS);
    for (it = ms.begin(); it != ms.end(); ++it) {
        z = it->first;
        _itot_s(z, str, 10);
        TextOut(hdc, 0, i, str,_tcsclen(str));
        z = it->second;
        _itot_s(z, str, 10);
        TextOut(hdc, 30, i, str, _tcsclen(str));
        i += 20;
    }
    MoveToEx(hdc, 0, 400, NULL);
    LineTo(hdc, 800, 400);
    MoveToEx(hdc, 400, 0, NULL);
    LineTo(hdc, 400, 800);
    it = ms.begin();
    MoveToEx(hdc, 400 + it->first * 10, 400 - it->second, NULL);
    ReleaseDC(hWndS, hdc);
}
void Base::paintg()
{
    HDC hdc = GetDC(hWndS);
    it = ms.begin();
    MoveToEx(hdc,400 + it->first * 10,0,NULL);
    for (it = ms.begin(); it != ms.end(); ++it)
    {
      //  SetPixel(hdc, 400 + it->first * 10, 400 - it->second, RGB(0, 0, 255));
        LineTo(hdc, 400 + it->first * 10, 400 - it->second);
    }
    ReleaseDC(hWndS, hdc);
}
void Base::set(HDC hdc)
{
    TextOut(hdc, 400, 500, _T("A"), 1);
}
