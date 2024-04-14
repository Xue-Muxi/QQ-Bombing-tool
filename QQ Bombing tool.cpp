#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{
	while(true)
	{
		int choose;
		cout << "请注意：在使用本功能前将要轰炸对方的文字、图片复制好，并将对方的窗口打开且使光标在输入框内闪动。" << endl;
		Sleep(1200);

		int j = 1;
		int outnumber;

		cout << "请暂时将对方的备注改为“name”" << endl;

		HWND hwnd = FindWindow(L"TXGuiFoundation", L"name");

		cout << "设置你想输出的次数(非法输入将导致程序终止)" << endl;
		cin >> outnumber;

		while (cin.fail())
		{
			cout << "检测到非法输入,程序终止" << endl;
			return -1;
		}

		for (int i = 0;i <= outnumber;i++)
		{
			SendMessage(hwnd, WM_PASTE, 0, 0);
			SendMessage(hwnd, WM_KEYDOWN, VK_RETURN, 0);
			while (j <= outnumber)
			{
				cout << "这是第" << j << "次轰炸" << endl;
				j++;
			}
		}
		cout << "********************************" << endl;
		cout << "如若想结束程序请选择ture(非法输入将导致程序终止)" << endl;
		cout << "false（默认）" << endl;
		cout << "1.ture" << endl;
		cin >> choose;

		while (cin.fail())
		{
			cout << "检测到非法输入,程序终止" << endl;
			return -2;
		}

		if (choose==1)
		{
			break;
		}
	}
	return 0;
}
