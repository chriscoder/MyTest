// CRCTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <sstream>
#include "CRC.h"
using namespace std;
string unsignedCharToHex(unsigned char ch, string pre = "0x")
{
    const std::string hexStr = "0123456789ABCDEF";
    std::stringstream ss;
    ss << pre << hexStr[ch >> 4] << hexStr[ch & 0xf] << " ";
    return ss.str();
}
int main()
{
    std::cout << "Hello World!\n";
    unsigned char* src = new unsigned char[263];
    memset(src, 0xBB, 263);
    src[0] = 0x55;
    src[1] = 0xAA;
    src[2] = 0xFF;
    src[3] = 0x01;
    src[4] = 0x03;
    src[5] = 0x01; 

    unsigned int dwNumOfBytes = (unsigned int)259;
    unsigned short checksum = CRC::CalCRC16(src + 2, dwNumOfBytes);
    unsigned char ii[2];
    memcpy(ii, &checksum, 2);
    unsigned char i01 = ii[0];
    unsigned char i02 = ii[1];
    unsigned char i1 = checksum;
    unsigned char i2 = checksum >> 8;
    cout <<"checksum:0x"<< hex << checksum << endl; //输出十六进制数
    cout << "ii[0]:" << unsignedCharToHex(ii[0]) << endl; //输出十六进制数
    cout << "ii[1]:" << hex << unsignedCharToHex(ii[1]) << endl; //输出十六进制数
    cout << "checksum 低八位:" << hex << unsignedCharToHex(i1) << endl; //输出十六进制数
    cout << "checksum 高八位:" << hex << unsignedCharToHex(i2) << endl; //输出十六进制数
    system("pause");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
