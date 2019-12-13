/**********************************************************************************
 *
 * 10.
 * 编写一个程序，提示用户输入3组数据，每组数包含5个double类型的数。该程序完成：
 * a. 把用户输入的数据存储在3x5的数组中；
 * b. 计算每组（5个）数据的平均值；
 * c. 计算所有数据的平均值；
 * d. 找出这25个数的最大值;
 * e. 打印结果；
 * 每个任务要求用单独的程序完成。
 *
 **********************************************************************************/

#include <stdio.h>

#define ROW     3
#define COL     5

void display(void);
void get_number(double(*)[COL], int row, int col);
double avr_row(const double*, int col);
double avr_all(const double(*)[COL], int row, int col);
double find_max(const double(*) [COL], int row, int col);
void result_print(double* avr_row, int row_len, double avr_all, double max);

int main(void)
{
	double d[ROW][COL];

	display();

	get_number(d, ROW, COL);

	double avr_r[ROW];
	for (int i = 0; i < ROW; ++i)
		avr_r[i] = avr_row(d[i], COL);

	double avr_a = avr_all(d, ROW, COL);

	double max = find_max(d, ROW, COL);

	result_print(avr_r, ROW, avr_a, max);

	return 0;
}

void display(void)
{
	printf("Please enter 5 double_type numbers for 3 times:\n");
}

void get_number(double(*d)[COL], int row, int col)
{
	for (int i = 0; i < row; ++i) {
		printf("Please enter the %d's 5 numbers:    ", i);
		for (int j = 0; j < col; ++j) {
			scanf("%lf", &d[i][j]);      
		}
	}
}

double avr_row(const double* d, int col)
{
	double sum = 0;
	for (int i = 0; i < col; ++i) {
		sum += *(d + i);
	}
	double avr = sum / col;

	return avr;
}

double avr_all(const double(*d)[COL], int row, int col)
{
	double sum = 0;
	for (int i = 0; i < row * col; ++i)
		sum += *(*d + i);                                                       // 由于数组内存连续，所以可以将行列合起来当成一维数组
	double avr = sum / (row * col);
	return avr;
}

double find_max(const double(*d)[COL], int row, int col)
{
	double max = **d;
	for (int i = 0; i < row * col; ++i)
		if (*(*d + i) > max) max = *(*d + i);

	return max;
}

void result_print(double* avr_row, int row_len, double avr_all, double max)
{
	printf("The average of every row are: ");
	for (int i = 0; i < row_len; ++i)
		printf("%lf     ", *(avr_row + i));
	printf("\n");

	printf("The average of all numbers are: %lf", avr_all);
	printf("\nThe maximun of the all number is: %lf\n", max);
}

/* 
 * Note:
 * 不能向 void ** 型参数传递 d[3][5] 中的 d， 类型不匹配，d的类型为：double (*)[5];
 * 声明指针： double (*p)[col] 时col必须是常量，不能是变量；
 */