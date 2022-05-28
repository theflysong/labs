#include <iostream>
using namespace std;

#define BMP_LEN (255)
unsigned long long qbmp[BMP_LEN] = {};

#define BITS (64) 

#define lowbit(x) ((x)&(-(x)))

int num(unsigned long long x) {
	switch (x) {
		case 0x0000000000000001: return  0;
		case 0x0000000000000002: return  1;
		case 0x0000000000000004: return  2;
		case 0x0000000000000008: return  3;
		case 0x0000000000000010: return  4;
		case 0x0000000000000020: return  5;
		case 0x0000000000000040: return  6;
		case 0x0000000000000080: return  7;
		case 0x0000000000000100: return  8;
		case 0x0000000000000200: return  9;
		case 0x0000000000000400: return 10;
		case 0x0000000000000800: return 11;
		case 0x0000000000001000: return 12;
		case 0x0000000000002000: return 13;
		case 0x0000000000004000: return 14;
		case 0x0000000000008000: return 15;
		case 0x0000000000010000: return 16;
		case 0x0000000000020000: return 17;
		case 0x0000000000040000: return 18;
		case 0x0000000000080000: return 19;
		case 0x0000000000100000: return 20;
		case 0x0000000000200000: return 21;
		case 0x0000000000400000: return 22;
		case 0x0000000000800000: return 23;
		case 0x0000000001000000: return 24;
		case 0x0000000002000000: return 25;
		case 0x0000000004000000: return 26;
		case 0x0000000008000000: return 27;
		case 0x0000000010000000: return 28;
		case 0x0000000020000000: return 29;
		case 0x0000000040000000: return 30;
		case 0x0000000080000000: return 31;
		case 0x0000000100000000: return 32;
		case 0x0000000200000000: return 33;
		case 0x0000000400000000: return 34;
		case 0x0000000800000000: return 35;
		case 0x0000001000000000: return 36;
		case 0x0000002000000000: return 37;
		case 0x0000004000000000: return 38;
		case 0x0000008000000000: return 39;
		case 0x0000010000000000: return 40;
		case 0x0000020000000000: return 41;
		case 0x0000040000000000: return 42;
		case 0x0000080000000000: return 43;
		case 0x0000100000000000: return 44;
		case 0x0000200000000000: return 45;
		case 0x0000400000000000: return 46;
		case 0x0000800000000000: return 47;
		case 0x0001000000000000: return 48;
		case 0x0002000000000000: return 49;
		case 0x0004000000000000: return 50;
		case 0x0008000000000000: return 51;
		case 0x0010000000000000: return 52;
		case 0x0020000000000000: return 53;
		case 0x0040000000000000: return 54;
		case 0x0080000000000000: return 55;
		case 0x0100000000000000: return 56;
		case 0x0200000000000000: return 57;
		case 0x0400000000000000: return 58;
		case 0x0800000000000000: return 59;
		case 0x1000000000000000: return 60;
		case 0x2000000000000000: return 61;
		case 0x4000000000000000: return 62;
		case 0x8000000000000000: return 63;
		case 0x0000000000000000: return 64;
	}
	return 0;
}

int n, m;

void printx(int x) {
	for (int i = 0 ; i < 63 ; i ++) {
		putchar (((x >> i) & 1) + '0');
	}
	putchar ('\n');
}

int main(int argc, const char **argv) {
	cin >> n >> m;
	getchar();
	for (int i = 0 ; i < n / BITS ; i ++) {
		unsigned long long c = 0;
		for (int j = 0 ; j < BITS ; j ++) {
			unsigned long long ch = getchar();
			c |= ((unsigned long long)(ch - '0')) << j; 
		}
		qbmp[i] = c;
	}
	qbmp[n / BITS] = 0xFFFFFFFFFFFFFFFF;
	qbmp[n / BITS + 1] = 0xFFFFFFFFFFFFFFFF;
	qbmp[n / BITS + 2] = 0xFFFFFFFFFFFFFFFF;
	putchar ('\n');
	unsigned long long x = qbmp[0];
	int c = 1, p = 0;
	while (c <= (n / BITS + 1)) {
		printf ("c %d p %d\n", c, p); 
		printf ("CUR       "); printx(x);
		unsigned int free = num(lowbit(x));
		x >>= free;
		printf ("MOVE FREE "); printx(x);
		unsigned int busy = num(lowbit(~x));
		x >>= busy;
		printf ("MOVE BUSY "); printx(x);
		unsigned long long next = qbmp[c] >> p;
		next |= qbmp[c + 1] << p;
		x |= next << (BITS - free - busy);
		printf ("ADD       "); printx(next << (BITS - free - busy)); 
		printf ("NOW       "); printx(x);
		p += free + busy;
		if (p >= BITS) {
			p -= BITS;
			c ++;
		}
		printf ("free: %d ; busy %d\n", free, busy);
	}
	return 0;
}
