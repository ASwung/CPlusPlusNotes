#pragma once									/* class 1(.h) */
class cPeople		// 类名一般以 c 开头
{
public:
	cPeople(); //构造函数，创建对象时对 对象的初始化操作（与类同名，无返回值）
			   // 如果一个类中没有构造函数，系统会自动生成一个无参构造函数。
	cPeople(int age, char* sex, char *name);	// 重载的构造函数

	~cPeople(); //析构函数 类的对象销毁时自动调用；内存的清理
				// 析构函数允许类自动完成类似清理工作，不必调用其他成员函数

// 行为
	void walk(); //成员函数
	static int sum;  // 类的静态成员变量：必须在类外赋值。所有对象共用的一个值(所有对象全部共享同一个值) 因为内存地址是不变的
	static void sleep(); // 类的静态成员函数：static 成员函数内 不可以 访问非 static 成员变量 以及 非 static 成员函数  定义方式： 返回类型 类名::函数名() (不需加 static 关键字)
	static void drink() {}

	const int count = 10;   // const 成员变量： 只能在 声明时或者构造函数以 初始化列表的方式 进行赋值: cpeople::cpeople(int value): count(10) 
	int GetCount() const; // const 成员函数: 不能在 const 成员函数里 调用非 const 的成员函数（可以调用非 const 成员变量）,并且在常量成员函数里也不能修改任何数据成员 
	void GetAge() const {}

	static const int total;   // 静态常量成员变量: 只能在 声明时或者类外 进行初始化：const int cpeople::total = 0; 

/*
	const 成员变量： 不能被改变，必须初始化 (两种初始化方式：在变量声明时 和 构造函数列表初始化)
	const 成员函数： 只读函数，在函数内不能改变类的值(成员变量的值)  (两个要求：在函数里不能调用任何非 const 成员函数 和 在函数里不能修改当前对象的任何数据成员)

	当 const 的对象调用成员函数时，这个成员函数必须为 const,因为要保证 对象在这个函数里 不被修改;
	也就是: const cPeople people1;  people1.work()  错误  因为 work() 这个成员函数不是 const 的
	应该这样: const cPeople people2;   people2.GetCount()  正确  因为 GetCount() 这个成员函数是 const 的

	static 成员变量： 只能在类外初始化，不需对象也可访问 也可被修改，格式：className::m_value = 0;
	static 成员函数： 在 static 成员函数里不能访问任何非 static 成员变量，没有 this 指针，不需对象也可访问  格式: className::func();
*/

// 属性(一般声明为 私有，再定义 接口函数来访问)：
private:
	int m_age;			// 一般对创建类的属性成员名时，以这样的格式：m_ 开头 
	char m_sex[3];
	char* m_name;
};

// 类：具有相同属性和行为的对象的集合。
// 对象：某一类型数据的一个实体。

/* class 类名称
{
public: 数据成员（成员变量）;		公有：在类的内部和外部都可以访问
成员函数;

protected:数据成员;					保护: 在类的内部和子类中可以访问
成员函数;

private: 数据成员;					私有：只能在类的内部访问
成员函数;
};	//类定义结束必须有“; ”   */


// 单例模式：  一个类只能创建一个对象 
class cCar {
	cCar()
	{
		m_value = 55;
	}

	cCar(char* id, char* manufacturer, int weight)
	{

	}
	~cCar()		// 让构造函数与析构函数默认为 private 
	{

	}
	int m_value;
public:
	static cCar* GetInstance()   // 静态成员函数 实现单例模式 
	{
		static cCar* pCar = new cCar;
		return pCar;
	}
};














