#include <Windows.h>
#include <stdlib.h>
#include <time.h>

const wchar_t g_szClassName[] = L"myWindowClass";

int rand_Spots();


int rand_Spots()
{
	int spots;
	spots = (rand() % 6 + 1);
	return spots;
}



// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	HPEN hPen;
	HBRUSH hBrush;
	HFONT hFont;
	int fontHeight;
	RECT rect;



	static bool isRectangle = true;
	bool b[7];
	static int rRed = 128;
	static int rGreen = 128;
	static int rBlue = 128;
	static int dRed = 50;
	static int dGreen = 50;
	static int dBlue = 50;
	static int penWidth = 5;
	static int xc1 = 100;
	static int xc2 = 100;
	static int xc3 = 300;
	static int xc4 = 300;
	static int xc5 = 500;
	static int xc6 = 500;
	static int yc1 = 100;
	static int yc2 = 200;
	static int yc3 = 100;
	static int yc4 = 200;
	static int yc5 = 100;
	static int yc6 = 200;
	static int width = 100;
	static int height = 100;
	static int spots1;
	static int spots2;
	static int spots3;
	static int spots4;
	static int spots5;
	static int spots6;
	int even = 0;



	switch (msg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		hPen = CreatePen(PS_SOLID, penWidth, RGB(dRed, dGreen, dBlue));
		hBrush = CreateSolidBrush(RGB(rRed, dGreen, dBlue));
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);




		//Create fonts
		fontHeight = 40;
		hFont = CreateFont(fontHeight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"Times New Roman");
		SelectObject(hDC, hFont);




		//First Domino

		Rectangle(hDC, xc1 - (width / 2), yc1 - (height / 2), xc1 + (width / 2), yc1 + (height / 2));
		Rectangle(hDC, xc2 - (width / 2), yc2 - (height / 2), xc2 + (width / 2), yc2 + (height / 2));


		/*Drawing Dots on Domino*/
		/*spots1 = rand_Spots();
		spots2 = rand_Spots();
		spots3 = rand_Spots();
		spots4 = rand_Spots();
		spots5 = rand_Spots();
		spots6 = rand_Spots();*/

		for (int i = 0; i < 7; i++)
		{
			b[i] = false;

			switch (spots1)
			{
			case 0:
				break;

			case 1:
				b[3] = true;
				break;

			case 2:
				b[0] = true;
				b[6] = true;
				break;
			case 3:
				b[0] = true;
				b[3] = true;
				b[6] = true;
				break;
			case 4:
				b[0] = true;
				b[2] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 5:
				b[0] = true;
				b[2] = true;
				b[3] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 6:
				b[0] = true;
				b[1] = true;
				b[2] = true;
				b[4] = true;
				b[5] = true;
				b[6] = true;
				break;
			}
		}


		// Square 1 
		if (b[0])
		{
			Ellipse(hDC, (xc1 - (width / 12) + (-35)), (yc1 - (width / 12) + (-35)), (xc1 + (width / 12) + (-35)), (yc1 + (width / 12) + (-35)));
		}
		if (b[1])
		{
			Ellipse(hDC, (xc1 - (width / 12) + (-35)), (yc1 - (width / 12) + 0), (xc1 + (width / 12) + (-35)), (yc1 + (width / 12) + 0));
		}
		if (b[2])
		{
			Ellipse(hDC, (xc1 - (width / 12) + (-35)), (yc1 - (width / 12) + 35.5), (xc1 + (width / 12) + (-35)), (yc1 + (width / 12) + 35.5));
		}
		if (b[3])
		{
			Ellipse(hDC, xc1 - (width / 12), yc1 - (height / 12), xc1 + (width / 12), yc1 + (height / 12));
		}
		if (b[4])
		{
			Ellipse(hDC, (xc1 - (width / 12) + 27.5), (yc1 - (width / 12) + (-35)), (xc1 + (width / 12) + 27.5), (yc1 + (width / 12) + (-35)));
		}
		if (b[5])
		{
			Ellipse(hDC, (xc1 - (width / 12) + 27.5), (yc1 - (width / 12) + 0), (xc1 + (width / 12) + 27.5), (yc1 + (width / 12) + 0));
		}
		if (b[6])
		{
			Ellipse(hDC, (xc1 - (width / 12) + 27.5), (yc1 - (width / 12) + 35.5), (xc1 + (width / 12) + 27.5), (yc1 + (width / 12) + 35.5));
		}

		for (int i = 0; i < 7; i++)
		{
			b[i] = false;

			switch (spots2)
			{
			case 0:
				break;

			case 1:
				b[3] = true;
				break;

			case 2:
				b[0] = true;
				b[6] = true;
				break;
			case 3:
				b[0] = true;
				b[3] = true;
				b[6] = true;
				break;
			case 4:
				b[0] = true;
				b[2] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 5:
				b[0] = true;
				b[2] = true;
				b[3] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 6:
				b[0] = true;
				b[1] = true;
				b[2] = true;
				b[4] = true;
				b[5] = true;
				b[6] = true;
				break;
			}
		}


		// Square 2 

		if (b[0])
		{
			Ellipse(hDC, (xc2 - (width / 12) + (-35)), (yc2 - (width / 12) + (-35)), (xc2 + (width / 12) + (-35)), (yc2 + (width / 12) + (-35)));
		}
		if (b[1])
		{
			Ellipse(hDC, (xc2 - (width / 12) + (-35)), (yc2 - (width / 12) + 0), (xc2 + (width / 12) + (-35)), (yc2 + (width / 12) + 0));
		}
		if (b[2])
		{
			Ellipse(hDC, (xc2 - (width / 12) + (-35)), (yc2 - (width / 12) + 35.5), (xc2 + (width / 12) + (-35)), (yc2 + (width / 12) + 35.5));
		}
		if (b[3])
		{
			Ellipse(hDC, xc2 - (width / 12), yc2 - (height / 12), xc2 + (width / 12), yc2 + (height / 12));
		}
		if (b[4])
		{
			Ellipse(hDC, (xc2 - (width / 12) + 27.5), (yc2 - (width / 12) + (-35)), (xc2 + (width / 12) + 27.5), (yc2 + (width / 12) + (-35)));
		}
		if (b[5])
		{
			Ellipse(hDC, (xc2 - (width / 12) + 27.5), (yc2 - (width / 12) + 0), (xc2 + (width / 12) + 27.5), (yc2 + (width / 12) + 0));
		}
		if (b[6])
		{
			Ellipse(hDC, (xc2 - (width / 12) + 27.5), (yc2 - (width / 12) + 35.5), (xc2 + (width / 12) + 27.5), (yc2 + (width / 12) + 35.5));
		}



		//Second Domino
		Rectangle(hDC, xc3 - (width / 2), yc3 - (height / 2), xc3 + (width / 2), yc3 + (height / 2));
		Rectangle(hDC, xc4 - (width / 2), yc4 - (height / 2), xc4 + (width / 2), yc4 + (height / 2));

		for (int i = 0; i < 7; i++)
		{
			b[i] = false;

			switch (spots3)
			{
			case 0:
				break;

			case 1:
				b[3] = true;
				break;

			case 2:
				b[0] = true;
				b[6] = true;
				break;
			case 3:
				b[0] = true;
				b[3] = true;
				b[6] = true;
				break;
			case 4:
				b[0] = true;
				b[2] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 5:
				b[0] = true;
				b[2] = true;
				b[3] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 6:
				b[0] = true;
				b[1] = true;
				b[2] = true;
				b[4] = true;
				b[5] = true;
				b[6] = true;
				break;
			}
		}


		//Square 3
		if (b[0])
		{
			Ellipse(hDC, (xc3 - (width / 12) + (-35)), (yc3 - (width / 12) + (-35)), (xc3 + (width / 12) + (-35)), (yc3 + (width / 12) + (-35)));
		}
		if (b[1])
		{
			Ellipse(hDC, (xc3 - (width / 12) + (-35)), (yc3 - (width / 12) + 0), (xc3 + (width / 12) + (-35)), (yc3 + (width / 12) + 0));
		}
		if (b[2])
		{
			Ellipse(hDC, (xc3 - (width / 12) + (-35)), (yc3 - (width / 12) + 35.5), (xc3 + (width / 12) + (-35)), (yc3 + (width / 12) + 35.5));
		}
		if (b[3])
		{
			Ellipse(hDC, xc3 - (width / 12), yc3 - (height / 12), xc3 + (width / 12), yc3 + (height / 12));
		}
		if (b[4])
		{
			Ellipse(hDC, (xc3 - (width / 12) + 27.5), (yc3 - (width / 12) + (-35)), (xc3 + (width / 12) + 27.5), (yc3 + (width / 12) + (-35)));
		}
		if (b[5])
		{
			Ellipse(hDC, (xc3 - (width / 12) + 27.5), (yc3 - (width / 12) + 0), (xc3 + (width / 12) + 27.5), (yc3 + (width / 12) + 0));
		}
		if (b[6])
		{
			Ellipse(hDC, (xc3 - (width / 12) + 27.5), (yc3 - (width / 12) + 35.5), (xc3 + (width / 12) + 27.5), (yc3 + (width / 12) + 35.5));
		}

		for (int i = 0; i < 7; i++)
		{
			b[i] = false;

			switch (spots4)
			{
			case 0:
				break;

			case 1:
				b[3] = true;
				break;

			case 2:
				b[0] = true;
				b[6] = true;
				break;
			case 3:
				b[0] = true;
				b[3] = true;
				b[6] = true;
				break;
			case 4:
				b[0] = true;
				b[2] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 5:
				b[0] = true;
				b[2] = true;
				b[3] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 6:
				b[0] = true;
				b[1] = true;
				b[2] = true;
				b[4] = true;
				b[5] = true;
				b[6] = true;
				break;
			}
		}

		//square 4
		if (b[0])
		{
			Ellipse(hDC, (xc4 - (width / 12) + (-35)), (yc4 - (width / 12) + (-35)), (xc4 + (width / 12) + (-35)), (yc4 + (width / 12) + (-35)));
		}
		if (b[1])
		{
			Ellipse(hDC, (xc4 - (width / 12) + (-35)), (yc4 - (width / 12) + 0), (xc4 + (width / 12) + (-35)), (yc4 + (width / 12) + 0));
		}
		if (b[2])
		{
			Ellipse(hDC, (xc4 - (width / 12) + (-35)), (yc4 - (width / 12) + 35.5), (xc4 + (width / 12) + (-35)), (yc4 + (width / 12) + 35.5));
		}
		if (b[3])
		{
			Ellipse(hDC, xc4 - (width / 12), yc4 - (height / 12), xc4 + (width / 12), yc4 + (height / 12));
		}
		if (b[4])
		{
			Ellipse(hDC, (xc4 - (width / 12) + 27.5), (yc4 - (width / 12) + (-35)), (xc4 + (width / 12) + 27.5), (yc4 + (width / 12) + (-35)));
		}
		if (b[5])
		{
			Ellipse(hDC, (xc4 - (width / 12) + 27.5), (yc4 - (width / 12) + 0), (xc4 + (width / 12) + 27.5), (yc4 + (width / 12) + 0));
		}
		if (b[6])
		{
			Ellipse(hDC, (xc4 - (width / 12) + 27.5), (yc4 - (width / 12) + 35.5), (xc4 + (width / 12) + 27.5), (yc4 + (width / 12) + 35.5));
		}

		////Third Domino
		Rectangle(hDC, xc5 - (width / 2), yc5 - (height / 2), xc5 + (width / 2), yc5 + (height / 2));
		Rectangle(hDC, xc6 - (width / 2), yc6 - (height / 2), xc6 + (width / 2), yc6 + (height / 2));

		for (int i = 0; i < 7; i++)
		{
			b[i] = false;

			switch (spots5)
			{
			case 0:
				break;

			case 1:
				b[3] = true;
				break;

			case 2:
				b[0] = true;
				b[6] = true;
				break;
			case 3:
				b[0] = true;
				b[3] = true;
				b[6] = true;
				break;
			case 4:
				b[0] = true;
				b[2] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 5:
				b[0] = true;
				b[2] = true;
				b[3] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 6:
				b[0] = true;
				b[1] = true;
				b[2] = true;
				b[4] = true;
				b[5] = true;
				b[6] = true;
				break;
			}
		}

		for (int i = 0; i < 7; i++)
		{
			b[i] = false;

			switch (spots5)
			{
			case 0:
				break;

			case 1:
				b[3] = true;
				break;

			case 2:
				b[0] = true;
				b[6] = true;
				break;
			case 3:
				b[0] = true;
				b[3] = true;
				b[6] = true;
				break;
			case 4:
				b[0] = true;
				b[2] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 5:
				b[0] = true;
				b[2] = true;
				b[3] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 6:
				b[0] = true;
				b[1] = true;
				b[2] = true;
				b[4] = true;
				b[5] = true;
				b[6] = true;
				break;
			}
		}

		//square 5
		if (b[0])
		{
			Ellipse(hDC, (xc5 - (width / 12) + (-35)), (yc5 - (width / 12) + (-35)), (xc5 + (width / 12) + (-35)), (yc5 + (width / 12) + (-35)));
		}
		if (b[1])
		{
			Ellipse(hDC, (xc5 - (width / 12) + (-35)), (yc5 - (width / 12) + 0), (xc5 + (width / 12) + (-35)), (yc5 + (width / 12) + 0));
		}
		if (b[2])
		{
			Ellipse(hDC, (xc5 - (width / 12) + (-35)), (yc5 - (width / 12) + 35.5), (xc5 + (width / 12) + (-35)), (yc5 + (width / 12) + 35.5));
		}
		if (b[3])
		{
			Ellipse(hDC, xc5 - (width / 12), yc5 - (height / 12), xc5 + (width / 12), yc5 + (height / 12));
		}
		if (b[4])
		{
			Ellipse(hDC, (xc5 - (width / 12) + 27.5), (yc5 - (width / 12) + (-35)), (xc5 + (width / 12) + 27.5), (yc5 + (width / 12) + (-35)));
		}
		if (b[5])
		{
			Ellipse(hDC, (xc5 - (width / 12) + 27.5), (yc5 - (width / 12) + 0), (xc5 + (width / 12) + 27.5), (yc5 + (width / 12) + 0));
		}
		if (b[6])
		{
			Ellipse(hDC, (xc5 - (width / 12) + 27.5), (yc5 - (width / 12) + 35.5), (xc5 + (width / 12) + 27.5), (yc5 + (width / 12) + 35.5));
		}


		for (int i = 0; i < 7; i++)
		{
			b[i] = false;

			switch (spots6)
			{
			case 0:
				break;

			case 1:
				b[3] = true;
				break;

			case 2:
				b[0] = true;
				b[6] = true;
				break;
			case 3:
				b[0] = true;
				b[3] = true;
				b[6] = true;
				break;
			case 4:
				b[0] = true;
				b[2] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 5:
				b[0] = true;
				b[2] = true;
				b[3] = true;
				b[4] = true;
				b[6] = true;
				break;
			case 6:
				b[0] = true;
				b[1] = true;
				b[2] = true;
				b[4] = true;
				b[5] = true;
				b[6] = true;
				break;
			}
		}

		//square 6
		if (b[0])
		{
			Ellipse(hDC, (xc6 - (width / 12) + (-35)), (yc6 - (width / 12) + (-35)), (xc6 + (width / 12) + (-35)), (yc6 + (width / 12) + (-35)));
		}
		if (b[1])
		{
			Ellipse(hDC, (xc6 - (width / 12) + (-35)), (yc6 - (width / 12) + 0), (xc6 + (width / 12) + (-35)), (yc6 + (width / 12) + 0));
		}
		if (b[2])
		{
			Ellipse(hDC, (xc6 - (width / 12) + (-35)), (yc6 - (width / 12) + 35.5), (xc6 + (width / 12) + (-35)), (yc6 + (width / 12) + 35.5));
		}
		if (b[3])
		{
			Ellipse(hDC, xc6 - (width / 12), yc6 - (height / 12), xc6 + (width / 12), yc6 + (height / 12));
		}
		if (b[4])
		{
			Ellipse(hDC, (xc6 - (width / 12) + 27.5), (yc6 - (width / 12) + (-35)), (xc6 + (width / 12) + 27.5), (yc6 + (width / 12) + (-35)));
		}
		if (b[5])
		{
			Ellipse(hDC, (xc6 - (width / 12) + 27.5), (yc6 - (width / 12) + 0), (xc6 + (width / 12) + 27.5), (yc6 + (width / 12) + 0));
		}
		if (b[6])
		{
			Ellipse(hDC, (xc6 - (width / 12) + 27.5), (yc6 - (width / 12) + 35.5), (xc6 + (width / 12) + 27.5), (yc6 + (width / 12) + 35.5));
		}

		//Draw some text
		rect.top = 350;
		rect.bottom = 550;
		rect.left = 100;
		rect.right = 550;

		if ((spots1 + spots2) % 2 == 0)
		{
			even++;
		}
		if ((spots3 + spots4) % 2 == 0)
		{
			even++;
		}
		if ((spots5 + spots6) % 2 == 0)
		{
			even++;
		}


		if (even == 3)
		{
			DrawText(hDC, L"There are 3 even Dominos!", -1, &rect, DT_CENTER | DT_WORDBREAK);
		}
		else if (even == 2)
		{
			DrawText(hDC, L"There are 2 even Dominos!", -1, &rect, DT_CENTER | DT_WORDBREAK);
		}
		else if (even == 1)
		{
			DrawText(hDC, L"There are 1 even Dominos!", -1, &rect, DT_CENTER | DT_WORDBREAK);
		}
		else
		{
			DrawText(hDC, L"There are 0 even Dominos!", -1, &rect, DT_CENTER | DT_WORDBREAK);
		}






		//DrawText(hDC, L"There are X even Dominos!", -1, &rect, DT_CENTER | DT_WORDBREAK);			//Centered

		DeleteObject(hBrush);
		DeleteObject(hFont);
		DeleteObject(hPen);
		EndPaint(hwnd, &ps);
		break;
	case WM_CHAR:
		if (wParam == ' ')
		{
			spots1 = rand_Spots();
			spots2 = rand_Spots();
			spots3 = rand_Spots();
			spots4 = rand_Spots();
			spots5 = rand_Spots();
			spots6 = rand_Spots();
		}

		else if (wParam == 'e')
		{
			isRectangle = false;
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == 'c')
		{
			rRed = rand() % 128;
			rGreen = rand() % 128;
			rBlue = rand() % 128;

			dRed = rand() % 256;
			dGreen = rand() % 256;
			dBlue = rand() % 256;
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == 'w')
		{
			penWidth = 1 + rand() % 20;
			InvalidateRect(hwnd, NULL, true);
		}
		break;
	case WM_KEYDOWN:
		if (wParam == VK_PRIOR)
		{
			/*xz *= 1.1;
			xz *= 1.1;*/
			InvalidateRect(hwnd, NULL, true);
		}
		if (wParam == VK_NEXT)
		{
			/*zx *= 1.0 / 1.1;
			zy *= 1.0 / 1.1;*/
			InvalidateRect(hwnd, NULL, true);
		}
		if (wParam == VK_SPACE)
		{
			InvalidateRect(hwnd, NULL, true);
		}
		if (wParam == VK_RIGHT)
		{
			xc1 += 5;
			xc2 += 5;
			xc3 += 5;
			xc4 += 5;
			xc5 += 5;
			xc6 += 5;
			InvalidateRect(hwnd, NULL, true);
		}
		if (wParam == VK_LEFT)
		{
			xc1 -= 5;
			xc2 -= 5;
			xc3 -= 5;
			xc4 -= 5;
			xc5 -= 5;
			xc6 -= 5;
			InvalidateRect(hwnd, NULL, true);
		}
		if (wParam == VK_UP)
		{
			yc1 -= 5;
			yc2 -= 5;
			yc3 -= 5;
			yc4 -= 5;
			yc5 -= 5;
			yc6 -= 5;
			InvalidateRect(hwnd, NULL, true);
		}
		if (wParam == VK_DOWN)
		{
			yc1 += 5;
			yc2 += 5;
			yc3 += 5;
			yc4 += 5;
			yc5 += 5;
			yc6 += 5;
			InvalidateRect(hwnd, NULL, true);
		}
		/*if (wParam == VK_SPACE)
		{

		InvalidateRect(hwnd, NULL, true);
		} */
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Window Registration Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		L"Tyler Bourque",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, L"Window Creation Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Step 3: The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}