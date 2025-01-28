#include<iostream>//包含输入输出流
#include<Windows.h>//包含WinAPI

using namespace std;//引入std命名空间

int main()//程序入口
{
	while(true)//主循环
	{
		int choose;
		cout << "请注意：在使用本功能前将要轰炸对方的文字、图片复制好，并将对方的窗口打开且使光标在输入框内闪动。" << endl;
		Sleep(1200);

		int j = 1;
		int outnumber;

		cout << "请暂时将对方的备注改为“name”" << endl;

		HWND hwnd = FindWindow(L"TXGuiFoundation", L"name");//查找qq窗口类和窗口标题

		cout << "设置你想输出的次数(非法输入将导致程序终止)" << endl;
		cin >> outnumber;

		while (cin.fail())//当从流中提取有效字段失败时
		{
			cout << "检测到非法输入,程序终止" << endl;
			return -1;
		}

		for (int i = 0;i <= outnumber;i++)//循环输出
		{
			SendMessage(hwnd, WM_PASTE, 0, 0);//向qq窗口发送将剪贴板的当前内容复制到位于当前插入点位置的信息
			SendMessage(hwnd, WM_KEYDOWN, VK_RETURN, 0);//向qq窗口发送发出编辑板中内容的消息
			while (j <= outnumber)//反馈输出执行状态
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

		while (cin.fail())//当从流中提取有效字段失败时
		{
			cout << "检测到非法输入,程序终止" << endl;
			return -2;
		}

		if (choose==1)//当轰炸结束后选择结束程序时
		{
			break;//退出主循环
		}
	}
	return 0;//程序结束返回0
}
