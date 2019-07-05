// VistualInheritance.cpp: 定义控制台应用程序的入口点。
//
/*******************************************************************************************
	文件名称: Virtual Inheritance
	文件描述: 实现一个虚继承类项目
	编译环境: VS2017  VS2008-VS2017
	最后修改:
	<2017年12月3日>  <创建工程>  <ASwung>
**********************************************************************************************/
#include "stdafx.h"
#include "VirtualInheritance.h"
#include <graphics.h>
#include <mmsystem.h>   // 播放音乐
#pragma comment(lib,"winmm.lib")

const int Size = 3;
int main()
{
	//initgraph(500, 600);
	//PlaySound(L"陈一发儿-董小姐.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC); //播放声音 wav  .mp3格式不行
	//// 有时播放不出可能是因为 字符编码问题 设置为 UTF-8 带签名，造成给出的第一个参数 歌曲名称识别不出 所以播放不出来

	cWorker worker("WeiW", 9527, 20);
	cChildren children("ZhangChen", 17750, 8);
	cChildLabourer childlabourer("ASwung", 12101, 4, 10, 22);
	
	cPerson *person[Size] = { 0 };
	char choice;
	for (int i = 0; i < Size; ++i)
	{
		cout << "Enter the employee category:\n"<< "w: worker  c: children  " << "l: childlabourer  q: quit\n";
		cin >> choice;
		if (strchr("wclq", towlower(choice)) == NULL)
		{
			cout << "Please enter \"wclq\" random letter\n";
			--i;
			continue;
		}
		if (towlower(choice) == 'q')
		{
			break;
		}
		switch (towlower(choice))
		{
		case 'w':person[i] = new cWorker; break;
		case 'c':person[i] = new cChildren; break;
		case 'l':person[i] = new cChildLabourer; break;
		}
		while (cin.get() != '\n')
		{

		}
		person[i]->Set();
	}
	for (int i = 0; i < Size; ++i)
	{
		if (person[i] == NULL)
		{
			break;
		}
		person[i]->Show();
	}
	for (int j = 0; j < Size; ++j)
	{
		delete person[j];
	}
	system("pause");
    return 0;
}

