
#ifndef  __PACKET__
#define  __PACKET__

#include "stdafx.h"

class CPacket
{
public:

	/*---------------------------------------------------------------
	Packet Enum.

	----------------------------------------------------------------*/
	enum en_PACKET
	{
		eBUFFER_DEFAULT = 1024		// ��Ŷ�� �⺻ ���� ������.
	};

	//////////////////////////////////////////////////////////////////////////
	// ������, �ı���.
	//
	// Return:
	//////////////////////////////////////////////////////////////////////////
	CPacket();
	CPacket(int iBufferSize);

	virtual	~CPacket();


	//////////////////////////////////////////////////////////////////////////
	// ��Ŷ  �ı�.
	//
	// Parameters: ����.
	// Return: ����.
	//////////////////////////////////////////////////////////////////////////
	void	Destroy(void);


	//////////////////////////////////////////////////////////////////////////
	// ��Ŷ û��.
	//
	// Parameters: ����.
	// Return: ����.
	//////////////////////////////////////////////////////////////////////////
	void	Clear(void);


	//////////////////////////////////////////////////////////////////////////
	// ���� ������ ���.
	//
	// Parameters: ����.
	// Return: (int)��Ŷ ���� ������ ���.
	//////////////////////////////////////////////////////////////////////////
	int	GetBufferSize(void);
	//////////////////////////////////////////////////////////////////////////
	// ���� ������� ������ ���.
	//
	// Parameters: ����.
	// Return: (int)������� ����Ÿ ������.
	//////////////////////////////////////////////////////////////////////////
	int		GetDataSize(void);



	//////////////////////////////////////////////////////////////////////////
	// ���� ������ ���.
	//
	// Parameters: ����.
	// Return: (char *)���� ������.
	//////////////////////////////////////////////////////////////////////////
	char	*GetBufferPtr(void);

	//////////////////////////////////////////////////////////////////////////
	// ���� Pos �̵�. (�����̵��� �ȵ�)
	// GetBufferPtr �Լ��� �̿��Ͽ� �ܺο��� ������ ���� ������ ������ ��� ���. 
	//
	// Parameters: (int) �̵� ������.
	// Return: (int) �̵��� ������.
	//////////////////////////////////////////////////////////////////////////
	int		MoveIdxRear(int _idx_offset);
	int		MoveIdxFront(int _idx_offset);






	/* ============================================================================= */
	// ������ ���۷�����.
	/* ============================================================================= */
	CPacket	&operator = (CPacket &clSrcPacket);

	//////////////////////////////////////////////////////////////////////////
	// �ֱ�.	�� ���� Ÿ�Ը��� ��� ����.
	//////////////////////////////////////////////////////////////////////////
	CPacket	&operator << (BYTE byValue);
	CPacket	&operator << (char chValue);

	CPacket	&operator << (short shValue);
	CPacket	&operator << (WORD wValue);

	CPacket	&operator << (int iValue);
	CPacket	&operator << (DWORD dwValue);
	CPacket	&operator << (float fValue);

	CPacket	&operator << (__int64 iValue);
	CPacket	&operator << (double dValue);


	//////////////////////////////////////////////////////////////////////////
	// ����.	�� ���� Ÿ�Ը��� ��� ����.
	//////////////////////////////////////////////////////////////////////////
	CPacket	&operator >> (BYTE &byValue);
	CPacket	&operator >> (char &chValue);

	CPacket	&operator >> (short &shValue);
	CPacket	&operator >> (WORD &wValue);

	CPacket	&operator >> (int &iValue);
	CPacket	&operator >> (DWORD &dwValue);
	CPacket	&operator >> (float &fValue);

	CPacket	&operator >> (__int64 &iValue);
	CPacket	&operator >> (double &dValue);




	//////////////////////////////////////////////////////////////////////////
	// ����Ÿ ���.
	//
	// Parameters: (char *)Dest ������. (int)Size.
	// Return: (int)������ ������.
	//////////////////////////////////////////////////////////////////////////
	int		GetData(char *dest_buffer, int _idx_offset);

	//////////////////////////////////////////////////////////////////////////
	// ����Ÿ ����.
	//
	// Parameters: (char *)Src ������. (int)SrcSize.
	// Return: (int)������ ������.
	//////////////////////////////////////////////////////////////////////////
	int		PutData(char *src_buffer, int sz_byte_src);




protected:

	char *_queue_buffer;

	int _idx_front;
	int _idx_rear;

	int _total_sz_byte_buffer;
	int _total_sz_byte_data;

	union TYPE_FLOAT
	{
		char data[4];
		float value;
	};

	union TYPE_DOUBLE
	{
		char data[8];
		double value;
	};

};

#endif
