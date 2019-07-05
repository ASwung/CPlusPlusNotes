//// StringLibrary.cpp: 定义控制台应用程序的入口点。
////
//
#include "stdafx.h"
//#include <string>  // 注意是<string>，不是<string.h>，带.h的是C语言中的头文件
//using namespace std;
//// 使用下面命名空间也可以
///*  
//	using  std::string;  
//	using  std::wstring;  string 和 wstring的用法是一样的  分别对应着 char 和 wchar_t
//*/
//
//int main()
//{
//	string str1("green apple");
//	string str2("red apple");
//	int result = str1.compare(6,4,"apple");
//// compare() 的六种重载:
///*
//		int result = str1.compare(str2);   // 返回 负数
//   1、 以 string 对象作为 参数
//	  原型:  int compare(const basic_string& _Right) const _NOEXCEPT
//	  功能:  把调用此方法的 string 对象 与 const 形参 _Right 作比较(ASCII值)
//	  返回值:调用的对象 比 形参大 返回正数，小 返回负数，相等 返回零
//
//		int result = str1.compare("ASwung");  // 返回正数
//   2、 以 const char* 作为 参数
//      原型: int compare(_In_z_ const _Elem * const _Ptr) const _NOEXCEPT
//	  功能:  把调用此方法的 string 对象 与 const 形参 const_Ptr 作比较(ASCII值)
//      返回值:调用的对象 比 形参大 返回正数，小 返回负数，相等 返回零
//
//		int result = str1.compare("ASwung");  // 返回正数
//   3、 以 const char* 作为 参数
//	  原型: int compare(_In_z_ const _Elem * const _Ptr) const _NOEXCEPT
//	  功能:  把调用此方法的 string 对象 与 const 形参 const_Ptr 作比较(ASCII值)
//	  返回值:调用的对象 比 形参大 返回正数，小 返回负数，相等 返回零
//*/
//// string类的构造函数：
//	string str1("green apple");   // 用 c 字符串 s 初始化				原型: string(const char *s); 
//	
//	string str2(3, 'A');		   // 用 n 个字符 c 初始化(AAA)		    原型: string(int n, char c); 
//   
//	string str3;				   // 默认构造函数，空的 string 对象	原型: string();
//
//	string str4 = "hello";		   // 复制构造函数					    原型: string(const string& str);
//	 // 注: 如果构造的 string 太长而无法表达时，会抛出 length_error 异常 
//	 /*-------------------------------------------------------------------------------------------------------------------------*/
//
//// string类的字符操作：
//	char ch = str1[1];		 // 原型: const char &operator[](int n)const;    char &operator[](int n);
//	ch = str1.at(4);		 // 原型: const char &at(int n)const;			  char &at(int n);
//	
//	ch = str1.front();       // 获得 string 对象字符串的 第一个字符     原型: char &front();
//	char &reference_ch = str2.back();   // 获得 string 对象字符串的 最后一个字符('\0' 除外，也可通过引用来改变 string 对象里的值)
//    // 注: operator[] 和 at() 均返回当前字符串中 第 n 个字符的位置(从零开始)，但 at() 函数提供范围检查，当越界时会抛出 out_of_range 异常，
//    //   	   下标运算符[]不提供检查访问。
//	/*-------------------------------------------------------------------------------------------------------------------------*/
//	const char *ch_Array = str1.data();    // 返回一个没有 '\0' 终止的c字符数组     原型: const char *data()const;
//		
//	const char *ch_Str = str1.c_str();		// 返回一个有 '\0' 终止的c字符串			 原型: const char *c_str()const;
//
//	char A_str[888] = { 0 };
//	int result = str1.copy(A_str, 3, 1);	// 把当前串中以 pos 开始的  n 个字符拷贝到  以 s 为起始位置的字符数组中，返回实际拷贝的数目(n)
//	 // 原型: int copy(char *s, int n, int pos = 0) const;   参数一不能为 char*  要是 char 数组，因为复制过来的值需要空间储存
//
//// string的特性描述:
//	 result = str1.capacity();   // 返回当前容量（即string中不必增加内存即可存放的元素个数）    原型: int capacity()const; 
//
//	 result = str2.max_size();   // 返回string对象中可存放的最大字符串的长度（取决于内存的大小）        原型:  int max_size()const;  
//
//	 result = str1.size();		// 返回当前字符串的大小       原型: int size()const;  
//	 result = str1.length();   // 返回当前字符串的长度		  原型: int length()const;   
//     // 注:  str1.size() == str1.lenth();   size() 与 lenth() 完全相等
//	 /*------------------------------------------------------------------------------------------------------------------------*/
//	 bool ret = str1.empty();   // 当前字符串是否为空(为空返回 true  否则返回 false)      原型: bool empty()const;   
//	
//	 str1.resize(15, 'W');  // 把字符串当前大小置为len，并用字符c填充不足的部分(可以访问)	原型: void resize(int len, char c);
//	 str1.reserve(20);    // 把 string 对象 str1 的容量改为 NewCapa (可能等于或者大于这个值)，但不可访问，会越界    
						  // 原型: void reserve(size_type NewCapa);

//// string类的输入输出操作:
//	// string类重载运算符operator >> 用于输入，同样重载运算符operator << 用于输出操作。
//	 cin >> str1;
//	 operator>>(cin, str1);   // 读到 空格(换行、制表 isspace() 为 true 的字符)时 停止，不读取空格(会把空格留在 输入流中)
//	// 注: 前两种输入方式，都是以换行符'\n'为结束符，不会读取 '\n'，会把它留在输入流中
//	/*------------------------------------------------------------------------------------------------------------------------*/
//	 getline(cin, str1);	    // 用于从输入流in中读取字符串到s中，以换行符'\n'为结束符(读取 但丢弃'\n')	  原型: getline(istream &in, string &s);
//	 getline(cin, str1, ':');  // 用于从输入流in中读取字符串到s中，以指定的 delimit 为结束符(读取 但丢弃)	  原型: getline(istream &in, string &s,char delimit);
//	
//	 char info[100];
//	 cin.getline(info, 100, ';');   //	C 风格字符串的输入方法，最多读取 count 个字符到字符串中，读到 delimit 时结束，读取 但丢弃 delimit
//										// 原型:  istream & getline(char* str,unsigned count,char delimit)
//
//// string的赋值：
//	string str = str1.operator= (str2);		// str1 = str2  把字符串 s 赋给当前字符串      原型: string &operator=(const string &s);
//	str = str1.operator= ("ppp");			// 把字符串 "ppp" 赋值给 str1 对象			    原型: string &operator=(const char* s);
//	str = str1.operator= ('x');				// 把字符 "x" 赋值给 str1 对象					原型: string &operator=(const char ch);
//	str = str1.assign("ASwung");		    // 用 c 类型字符串 s 赋值(返回赋值后的值)		原型: string &assign(const char *s);
//	str = str1.assign(str2);				// 把对象 str2 赋给当前字符串						原型：string &assign(const string &s);
//	 // 注： 这五个都能将一个字符串(字符)赋值给 调用此方法的 string 对象，返回赋值后的值。 只是参数 或 函数名不一样
//	/*--------------------------------------------------------------------------------------------------------------------------*/
//	str = str1.assign("AeIoU",4);		    // 用 c 字符串 s(不能为 string 对象，否则复制的是从 n 开始的字符) 开始的  n 个字符赋值        
//											// 原型：string &assign(const char *s, int n);
//
//	str = str1.assign(5, 'o');				// 用 n 个字符 c 赋值给当前字符串			    原型: string &assign(int n, char c);
//	 // 注:  这个两个函数都能将 指定的 字符串 或 字符 的个数  赋值给调用此方法的 string 对象  区别是一个是指定的字符串，一个是 重复字符
//	 /*-------------------------------------------------------------------------------------------------------------------------*/
//	str = str1.assign(str2, 2, 3);   // 把字符串 s 中从 start 开始的 n 个字符 赋给当前字符串  
//									  // 原型: string &assign(const string &s, int start, int n);
//
//									  // 把 first 和 last 迭代器之间的部分赋给字符串   
//									  // 原型： string &assign(const_iterator first, const_itertor last);
//
//// string 的连接：
//	str = str1.operator+= (str2);		// 把字符串 s 连接到当前字符串的结尾		原型: string &operator+=(const string &s);
//	str = str1.operator+= ("xxx");		// 把字符串 s 连接到当前字符串的结尾		原型: string &operator+=(const char* s);
//	str = str1.operator+= ('o');		// 把字符 ch 连接到当前字符串的结尾		    原型: string &operator+=(const char ch);
//	str = str1.append("qwer");		    // 把 c 类型字符串 s 连接到当前字符串结尾  原型: string &append(const char *s);     
//	str = str1.append(str4);			// 同 operator+=()			原型： string &append(const string &s);   
//	 // 注： 这几个函数能把字符串 或者 字符 或者 string对象保存着的字符串 连接到 调用它们的 string 对象里  返回连接后的值
//	 /*------------------------------------------------------------------------------------------------------------------------*/
//	str = str1.append("LlL", 2);		// 把 c 类型字符串(string 对象也可) s 的前 n 个字符连接到当前字符串结尾   
//										// 原型： string &append(const char *s, int n);
//	str = str1.append(str4, 2, 10);	     // 把 string 对象(char* 也可) s 中从 pos 开始的 n 个字符连接到当前字符串的结尾
//											 // 原型: string &append(const string &s, int pos, int n);
//
//	str = str1.append(5, 'k');		    // 在当前字符串结尾添加 n 个字符 c    原型：	string &append(int n, char c); 
//
//									// 把迭代器 first 和 last 之间的部分连接到当前字符串的结尾
//									// 原型： string &append(const_iterator first, const_iterator last);
//
//// string 的比较：
//	
//	// 运算符"==",">", "<", ">=", "<=", "!=" 重载用于字符串的比较
//	bool ret = str1 == str2;  // 比较两个string对象(也能为字符串)是否相等(相等返回 true)    原型: bool operator==(const string &s1, const string &s2)const;
//	ret = str1 != str2;	  // 比较两个字符串是否 不相等(不相等返回 true)    原型: bool operator！=(const string &s1, const string &s2)const;
//	ret = str1 >= str2;	  // 比较第一个字符串是否大于等于第二个字符串(是 返回 true)  原型: bool operator>=(const string &s1, const string &s2)const;
//	ret = str1 <= str2;	 // 比较第一个字符串是否小于等于第二个字符串(是 返回 true)  原型: bool operator<=(const string &s1, const string &s2)const;
//	ret = str1 < str2;   // 比较第一个字符串是否小于等于第二个字符串(是 返回 true)    原型: bool operator<(const string &s1, const string &s2)const;
//	ret = str1 > str2;   // 比较第一个字符串是否大于第二个字符串(是 返回 true)   原型: bool operator>(const string &s1, const string &s2)const;
//	/*--------------------------------------------------------------------------------------------------------------------------*/
//	result = str1.compare(str2);  // 比较string 对象里的字符串 与 s(也能为 char*)的大小(string对象大 返回正数)  原型: int compare(const string &s) const;
//	
//	result = str1.compare(2, 4, str4); // 比较当前字符串 从pos开始的 n 个字符组成的字符串 与 s(也能为 char*) 的大小(string对象大 返回正数)
//										// 原型: int compare(int pos, int n, const string &s)const;
//	result = str1.compare(2, 4, str4, 1, 3);		// 原型: int compare(int pos, int n, const string &s, int pos2, int n2)const;
//				 // 比较当前字符串从 pos 开始的 n 个字符组成的字符串  与 s(也能为 char*) 中 pos2 开始的 n2 个字符组成的字符串 的大小
//
//	result = str1.compare(2, 4, "zzllo", 1);// 与上一个功能一样(不能指定第二个字符串的个数) 
//											 // 原型: int compare(int pos, int n, const char *s, int pos2) const;
//	// 注: compare函数在 > 时返回 1，< 时返回 -1， == 时返回 0  ----------------------------------------------------------------*/
//
//
//// string 的子串：
//	str = str1.substr(2, 3); // 返回 pos 开始的 n 个字符组成的字符串(不给第二个参数，则默认为全部)  
//							  // 原型：string substr(int pos = 0, int n = npos) const;
//
//// string 的交换：
//	str1.swap(str4);	 // 交换 string 对象与 对象s2(不能使用 char* 类型) 的值     原型: void swap(string &s2);   
//
//// string 类的查找函数：
//	int index = str1.find('u', 2);    // 从 pos 开始查找 字符 c 在当前字符串 的位置      原型: int find(char c, int pos = 0) const;
//
//	index = str1.find("un", 2);				 // 从 pos 开始查找 字符串 s(string 对象也行) 在当前串中 的位置（没找着 返回 string::npos）  
//		// 原型: int find(const char *s, int pos = 0) const;   或    int find(const char *s, int pos = 0) const;
//
//	index = str1.find("wun",1, 2);			// 从 pos 开始查找 字符串 s(不能为 string 对象) 中前 n 个字符 在当前串中 的位置    
//											// 原型: int find(const char *s, int pos, int n) const;
//	/* 注： 这三个是 从前向后的查找 如果找到了将返回 需要查找的字符、字符串、string 对象 首次出现的首字母 索引，
//	       没找到 返回 string::npos(是string对象能够存储的最大字符数，需要用 unsigned 类型来接收，用 int 会得到 -1)   */
//
//	index = str1.rfind('u', 4);    // 从 pos(在当前 string 对象 字符串中对应的字符下标) 开始 从后向前查找字符 c 在当前串中 的位置
//								    // 原型: int rfind(char c, int pos = npos) const;
//
//	index = str1.rfind("un", 2);		 // 从 pos 开始 从后向前查找 字符串 s(string 对象也行) 在当前串中 的位置（没找着 返回 -1）  
//			// 原型: int rfind(const char *s, int pos = npos) const;   或   int rfind(const string& s, int pos = npos) const;
//
//	index = str1.rfind("wun", str1.size() - 1, 2);     // 原型: int rfind(const char *s, int pos, int n = npos) const;
//											 // 从 pos 开始 从后向前查找 字符串 s(不能为 string 对象) 中前 n 个字符 在当前串中 的位置		
//	// 注： 这三个是 从后向前 的查找 (输入的起点下标 pos 一定要在 查找的字符或字符串 的后面，否则 查找不到 返回 -1 string::npos)
//    /*-------------------------------------------------------------------------------------------------------------------------*/
//	index = str1.find_first_of('S', 1); // 从 pos 开始查找字符 c 第一次出现的位置   原型: int find_first_of(char c, int pos = 0) const;
//	
//	index = str1.find_first_of("oo", 1);    // 从 pos 开始查找 字符串 s(string 对象也行) 在 string 对象中 第一次出现的位置   
//      // 原型: int find_first_of(const char *s, int pos = 0) const;   或  int find_first_of(const string &s, int pos = 0) const;
//
//	index = str1.find_first_of("ngde", 3 , 2);   	// 原型: int find_first_of(const char *s, int pos, int n) const;
//									// 从 pos 开始查找 字符串 s(不能为 string 对象) 的前 n 个字符 在 string 对象中 第一次出现的位置   
//	// 注:  这三个是 查找字符 或 字符串 在 string 对象中 第一次出现的 位置 (上面九个函数，成功返回 对应下标，否则 返回 -1)
//	/*-------------------------------------------------------------------------------------------------------------------------*/
//
//	index = str1.find_first_not_of('A', 0);		// 在 string 对象中从 pos 开始查找 第一个不为 字符c 的下标位置   
//													// 原型: int find_first_not_of(char c, int pos = 0) const;
//
//	index = str1.find_first_not_of("wu", 1); // 在 string 对象中从 pos 开始查找 第一个不为字符串 s(string 对象也行)中任一字符 的下标位置
//	// 原型: int find_first_not_of(const char *s, int pos = 0) const; 或 int find_first_not_of(const string &s, int pos = 0) const;
//	
//	index = str1.find_first_not_of("SwU_N", 0, 2);		// 原型: int find_first_not_of(const char *s, int pos, int n) const;
//					//  在 string 对象中从 pos 开始查找 字符串 s(不能为 string 对象) 的前 n 个字符中任一字符 第一次没有出现 的位置 
//	
//	// 注: 这三个是 查找字符 或 字符串 在 string 对象中 第一次没有出现 的位置 (成功返回 对应下标，否则返回 -1(npos))
//	/*-------------------------------------------------------------------------------------------------------------------------*/
//	index = str1.find_last_of('n'); // 从 pos 开始 从后向前查找字符 c 第一次出现的位置(第二个参数 可不写，默认从最后一个找) 
//													// 原型: int find_last_of(char c, int pos = npos) const;
//
//	index = str1.find_last_of("AS", str1.size() - 1); // 从 pos 开始 从后向前查找字符串 s(也能是 string 对象)中任一字符 第一次出现的位置
//	// 原型: int find_last_of(const char *s, int pos = npos) const;  或   int find_last_of(const string &s, int pos = npos) const;
//	
//	index = str1.find_last_of("Sw", str1.length() - 1); 	// 原型: int find_last_of(const char *s, int pos, int n = npos) const;
//  // 从 pos 开始查找 字符串 s(不能为 string 对象) 的前 n 个字符(可不写，默认为字符串 s 的全部字符) 在 string 对象中 第一次出现的位置
//
//  // 注： 这三个是 从后向前 的查找 (输入的起点下标 pos 一定要在 查找的字符或字符串 的后面，否则 查找不到 返回 -1 string::npos)
//  /*-------------------------------------------------------------------------------------------------------------------------*/
//	
//	index = str1.find_last_not_of('S'); // 在 string 对象中从 pos(可不写，默认为 最后) 开始 从后向前查找 第一个不为 字符c 的下标位置 
//														// 原型: int find_last_not_of(char c, int pos = npos) const;
//
//	str2 = "wu"; // 从 pos(在当前 string 对象 字符串中对应的字符下标，可不写，默认为 最后) 开始 从后向前查找字符 c 在当前串中 的位置
//	index = str1.find_last_not_of(str2); 
//	// 原型: int find_last_not_of(const char *s, int pos = npos) const;  int find_last_not_of(const string &s, int pos = npos) const;
//	
//	index = str1.find_last_not_of("ung", str1.length() - 1, 2); // 原型: int find_last_not_of(const char *s, int pos, int n) const;
//		// 从 pos 开始 从后向前查找 字符串 s(不能为 string 对象) 中前 n 个字符的任一字符 第一个不在 string 对象中 的位置			
//	
//   // 注: 这三个是 查找字符 或 字符串在 string 对象中 从后向前查找 第一次没有出现 的位置(成功返回 对应下标，否则返回 -1(npos))
//	// find_last_of 和 find_last_not_of 与 find_first_of 和 find_first_not_of 相似，只不过是从后向前查找
//
//// string类的替换函数：
//	char * str_array = "osoii";
//	str = str1.replace(1, 4, str_array);	   // 把 string 对象从 p0 开始的 n0 个字符替换成 字符串 s(也能是 string 对象)
//			 // 原型: string &replace(int p0, int n0, const char *s);    或    string &replace(int p0, int n0, const string &s);
//
//	str = str1.replace(1, 4, str_array, 3);  // 把 string 对象从 p0 开始的 n0 个字符替换成 字符串 s(也能是 string 对象)的前 n 个字符
//											  // 原型: string &replace(int p0, int n0, const char *s, int n);
//			
//	str = str1.replace(1, 4, str4, 1); 	 // 原型: string &replace(int p0, int n0, const string &s, int pos, int n = npos); 
//	    // 把 string 对象从 p0 开始的 n0 个字符替换成 字符串 s 从 pos 开始的前 n 个字符(最后一个参数可不写，默认到 最后一个字符)
//
//	str = str1.replace(1, 4, 2, 'M');  	 // 把 string 对象从 p0 开始的 n0 个字符替换成 n 个字符 c
//											 // 原型: string &replace(int p0, int n0, int n, char c);
//
//	// 注： 这四个函数是把 string 对象从 p0 开始的 n0 个字符 替换成字符串 或者 string 对象里的串 或者 字符(返回替换后的 string 对象)
//	/*-------------------------------------------------------------------------------------------------------------------------*/
//											 // 把 [first0，last0）之间的部分替换为 字符串 s(也能为 string 对象)
//    // 原型: string &replace(iterator first0, iterator last0, const char *s); 或 string &replace(iterator first0, iterator last0, const string &s);
//	
//	string &replace(iterator first0, iterator last0, const char *s, int n);// 把[first0，last0）之间的部分替换为 s 的前 n 个字符
//
//	string &replace(iterator first0, iterator last0, int n, char c);// 把[first0，last0）之间的部分替换为 n 个字符 c
//	string &replace(iterator first0, iterator last0, const_iterator first, const_iterator last);// 把[first0，last0）之间的部分替换成 [first，last）之间的字符串
//	// 这四个函数是把 first0，last0 之间的 部分替换成 字符串 或者 字符 或者 string 对象(返回替换后的 string 对象)
//	/*-------------------------------------------------------------------------------------------------------------------------*/
//
////	string类的插入函数：
//	str = str1.insert(2, "wowkk");			// 在 p0 位置插入字符串 s(也能为 string 对象)
//							// 原型: string &insert(int p0, const char *s);    或    string &insert(int p0, const string &s);
//
//	str = str1.insert(2, str_array, 3);   // 在 p0 位置插入字符串 s(不能为 string 对象，否则将调用下面一个)的前 n 个字符
//										// 原型: string &insert(int p0, const char *s, int n);									
//
//	str = str1.insert(2, str4, 1, 3);      // 在 p0 位置插入字符串 s(也能为 char* ) 中 pos 开始的前 n(可不写，默认为 到最后)个字符
//											// 原型: string &insert(int p0, const string &s, int pos, int n = npos);
//	
//	str = str1.insert(1, 4, 'x');		// 此函数在 p0 处插入 n 个字符 c      原型: string &insert(int p0, int n, char c);
//	// 注： 这四个函数能从 string 对象的 p0 处 插入字符 或者 字符串 或者 string 对象中的串 （返回 插入后的 string 对象） 
//	/*-------------------------------------------------------------------------------------------------------------------------*/
//	iterator insert(iterator it, char c);//在it处插入字符c，返回插入后迭代器的位置
//	void insert(iterator it, const_iterator first, const_iterator last);//在it处插入[first，last）之间的字符
//	void insert(iterator it, int n, char c);//在it处插入n个字符c
//
//
//
////	string类的删除函数
//		iterator erase(iterator first, iterator last);//删除[first，last）之间的所有字符，返回删除后迭代器的位置
//	iterator erase(iterator it);//删除it指向的字符，返回删除后迭代器的位置
//
//	str = str1.erase(1, 3);  // 删除 pos 开始的 n 个字符，返回修改后的 string 对象  原型: string &erase(int pos = 0, int n = npos);
//	
//
//
////	string类的迭代器处理：
//		string类提供了向前和向后遍历的迭代器iterator，迭代器提供了访问各个字符的语法，类似于指针操作，迭代器不检查范围。
//		用string::iterator或string::const_iterator声明迭代器变量，const_iterator不允许改变迭代的内容。常用迭代器函数有：
//		const_iterator begin()const;
//	iterator begin();                //返回string的起始位置
//	const_iterator end()const;
//	iterator end();                    //返回string的最后一个字符后面的位置
//	const_iterator rbegin()const;
//	iterator rbegin();                //返回string的最后一个字符的位置
//	const_iterator rend()const;
//	iterator rend();                    //返回string第一个字符位置的前面
//	rbegin和rend用于从后向前的迭代访问，通过设置迭代器string::reverse_iterator, string::const_reverse_iterator实现
//
//
//		字符串流处理：
//		通过定义ostringstream和istringstream变量实现，#include <sstream>头文件中
//		例如：
//		string input("hello,this is a test");
//	istringstream is(input);
//	string s1, s2, s3, s4;
//	is >> s1 >> s2 >> s3 >> s4;//s1="hello,this",s2="is",s3="a",s4="test"
//	ostringstream os;
//	os << s1 << s2 << s3 << s4;
//	cout << os.str();
//
//	以上就是对C++ string类的一个简要介绍。用的好的话它所具有的功能不会比MFC中的CString类逊色多少，呵呵，个人意见！
//
//		最后要介绍如何在Win32 应用程序中引用MFC中的部分类，例如CString。
//
//		1.在工程目录下右键选择"Properties”--->"Configuration Properties”--->“General”--->"Use of MFC"--->"Use MFC in a Static Library"，
//
//		默认的是："Use Standard Windows Libraries"
//	system("pause");
//    return 0;
//}
//
