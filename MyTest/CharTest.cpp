#include<iostream>

using namespace std;
void testStringCopy();
void testCopy();
const char* doCopy();
int main()
{ 
	testCopy();
	//testStringCopy(); 
	system("PAUSE ");
	return 0;
}
void testCopy()
{
	const char* myStr = doCopy();
	std:cout << myStr << endl;

	while (*myStr != '\0')
	{
		std::cout << *myStr++;  // ++优先级高于*
	}
	std::cout << endl;
}
const char* doCopy()
{
	//const char* c;
	//string s = "1234";
	//c = s.c_str(); //c最后指向的内容是垃圾,因为s对象被析构,其内容被处理

	string s = "12345";
	char* c = new char[s.length() + 1]; 
	strcpy_s(c, s.length() + 1, s.c_str());
	return c;
}

void testStringCopy()
{
	string src = "123456";
	char* cpy_s = new char[src.length() + 1];
	char cpy_s_c[20];
	strcpy_s(cpy_s, src.length() + 1, src.c_str());
	strcpy_s(cpy_s_c, 7, src.c_str());

	char* cpy = new char[src.length() + 1];
	char cpy_c[20];
	strcpy(cpy, src.c_str());
	strcpy(cpy_c, src.c_str());

	std::cout << "cpy_s: " << cpy_s << endl;
	std::cout << "cpy_s_c: " << cpy_s_c << endl;

	std::cout << "cpy: " << cpy << endl;
	std::cout << "cpy_c: " << cpy_c << endl;
}