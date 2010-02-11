#pragma once

//const UCHAR	t_Data=0;
//const UCHAR	t_EOF=1;
//const UCHAR	t_Segement=2;
//const UCHAR	t_Linear=4;
#define		t_Data			0
#define		t_EOF			1
#define		t_Segement		2
#define		t_SegementStart 3
#define		t_Linear		4
#define		t_LinearStart	5

const UCHAR LineMaxNum=16;

class CHexFileLine
{
public:
	CHexFileLine(void);
	CHexFileLine(const CHexFileLine&);
	CHexFileLine& operator=(const CHexFileLine&);
	~CHexFileLine(void);
	UCHAR	RecordNumber;
	int	RecordAddress;
	UCHAR	RecordType;
	UCHAR	Records[LineMaxNum];
	UCHAR	SumAll;
};

class	CHexFile
{
public:
	CHexFile(const CString fname);
	~CHexFile();
	CHexFileLine	*Lines;
	int		LineCount;
	CString		FormatLine(int LineIndex);
private:
	CHexFile();
	void	GetLineHead(char* fp,CHexFileLine& HexLine);
	void	GetOneLine(char* fp,CHexFileLine& HexLine);
};

/*                             Read me
һ��Intel HEX�ļ����԰���������ʮ�����Ƽ�¼,ÿ����¼�������,������һ����¼�ĸ�ʽ. 

:llaaaatt[dd...]cc 

ÿһ����ĸ�Ƕ�����һ��,ÿһ����ĸ��һ��ʮ����������,ÿһ������������ʮ�������������,�������ֽڵ�����. 

:ð�� ��ÿһ��Intel HEX��¼�Ŀ�ʼ 

ll ��������¼�ĳ�����,����ʾ����(dd)���ֽ���Ŀ. 

aaaa �ǵ�ַ��,����ʾ���ݵ���ʼ��ַ 
<��������ݼ�¼,���ʾ��Ҫ��¼��������¼�е�������EPROM�е�ƫ�Ƶ�ַ, 
���ڲ�֧����չ�ε�ַ����չ���Ե�ַ��,��89C51,����Ǵ�����¼����ʼ��ַ> 

tt ������ʾ����HEX��¼������,���п����������⼸������ 
00 ----���ݼ�¼ 
01 ----�ļ�������¼ 
02 ----��չ�ε�ַ��¼ 
04 ----��չ���Ե�ַ��¼ 

dd ��������,��ʾһ���ֽڵ�����,һ����¼�����ж�������ֽ�,�ֽ���Ŀ���� 
�鿴ll���˵�� 

cc ��Ч�����,��ʾ��¼��Ч���,���㷽���ǽ�������¼ð�ſ�ʼ��������ĸ��
<��������Ч���ֺ�ð��> ����ʾ��ʮ���������� 
<һ����ĸ��ʾһ��ʮ��������,������һ��ʮ��������Ϊһ���ֽ�> 

��������Ȼ��ģ��256�õ������������������Ĳ��뼴�Ǳ�Ч���ֽ�cc. 
<����: 
:0300000002005E9D 
cc=0x01+NOT((0x03+0x00+0x00+0x00+0x02+0x00+0x5E)%0x100)=0x01+0x9C=0x9D 

C��������: 
UCHAR cc; 
cc=(UCHAR)~(0x03+0x00+0x00+0x00+0x02+0x00+0x5E); 
cc++;
//*/