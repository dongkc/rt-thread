// һЩ���õġ����õĽӿ�

#ifndef __OPENLOONGSON_PUBLIC_H
#define __OPENLOONGSON_PUBLIC_H


#include <stdio.h>


// pmon�ṩ�Ĵ�ӡ��������main()����
struct callvectors {
	int     (*open) (char *, int, int);
	int     (*close) (int);
	int     (*read) (int, void *, int);
	int     (*write) (int, void *, int);
	long long   (*lseek) (int, long long, int);
	int     (*printf) (const char *, ...);
	void    (*cacheflush) (void);
	char    *(*gets) (char *);
};
#define	myprintf (*callvec->printf)
#define	mygets   (*callvec->gets)
extern struct callvectors *callvec;


#define MIN(a, b)           ((a) > (b) ? (b) : (a))
#define MAX(a, b)           ((a) > (b) ? (a) : (b))

typedef enum
{
    FALSE=0, 
    TRUE=1
}BOOL;

/*
 * ��ָ���Ĵ�����ָ��λ��1
 * @reg �Ĵ�����ַ
 * @bit ��Ҫ��1����һbit
 */
void reg_set_one_bit(volatile unsigned int *reg, unsigned int bit);


/*
 * ��ָ���Ĵ�����ָ��λ����
 * @reg �Ĵ�����ַ
 * @bit ��Ҫ�������һbit
 */
void reg_clr_one_bit(volatile unsigned int *reg, unsigned int bit);


/*
 * ��ȡָ���Ĵ�����ָ��λ��ֵ
 * @reg �Ĵ�����ַ
 * @bit ��Ҫ��ȡֵ����һbit
 * @ret ָ��λ��ֵ
 */
unsigned int reg_get_bit(volatile unsigned int *reg, unsigned int bit);


/*
 * ��Ĵ�����дһ��32bit������
 * @data ��д�������
 * @addr �Ĵ�����ַ
 */
void reg_write_32(unsigned int data, volatile unsigned int *addr);


/*
 * �ӼĴ�������һ��32bit����
 * @addr �Ĵ�����ַ
 * @ret ����������
 */
unsigned int reg_read_32(volatile unsigned int *addr);


/**
 * ffs - find first bit set
 * @x: the word to search
 */
int ls1c_ffs(int x);


#endif
