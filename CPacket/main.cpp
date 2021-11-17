// CPacket.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CPacket.h"

int main()
{
	CPacket *test = new CPacket(100);


	//test1
	char arr_src[10];
	arr_src[0] = '0';
	arr_src[1] = '1';
	arr_src[2] = '2';
	arr_src[3] = '3';
	arr_src[4] = '4';
	arr_src[5] = '5';
	arr_src[6] = '6';
	arr_src[7] = '7';
	arr_src[8] = '8';
	arr_src[9] = '9';

	*test << (SHORT)0 << (SHORT)1 << (SHORT)2 << (SHORT)3 << (SHORT)4 << (SHORT)5;

	SHORT arr_dest1;
	SHORT arr_dest2;
	SHORT arr_dest3;
	SHORT arr_dest4;
	SHORT arr_dest5;


	*test >> arr_dest1 >> arr_dest2 >> arr_dest3 >> arr_dest4 >> arr_dest5;


	test->Clear();

	//test2
	*test << (float)0.1 << (float)1.1 << (float)2.1 << (float)3.1 << (float)4.1 << (float) 5.1;

	float float_dest1;
	float float_dest2;
	float float_dest3;
	float float_dest4;
	float float_dest5;

	*test >> float_dest1 >> float_dest2 >> float_dest3 >> float_dest4 >> float_dest5;

	test->Clear();


	//test3 double
	*test << 0.1 << 1.1 << 2.1 << 3.1 << 4.1 << 5.1;

	double double_dest1;
	double double_dest2;
	double double_dest3;
	double double_dest4;
	double double_dest5;
	double double_dest6;

	*test >> double_dest1 >> double_dest2 >> double_dest3 >> double_dest4 >> double_dest5 >> double_dest6;

	test->Clear();




}


