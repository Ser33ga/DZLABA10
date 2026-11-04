#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

double area_triangle(double a, double h);
void print_definition(void);
void draw_triangle(int h, char ch);
double compare_triangles(double s1, double s2);

void main() {
	setlocale(LC_ALL, "RUS");

	int choice;
	int draw_h;
	double a, h, s;
	double a1, h1, a2, h2, s1, s2, diff;
	char ch;

	do {
		printf("\nМеню операций для равнобедренного треугольника:\n");
		printf("1 - Рассчитать площадь фигуры\n");
		printf("2 - Вывести определение фигуры\n");
		printf("3 - Нарисовать фигуру\n");
		printf("4 - Сравнить два треугольника по площади\n");
		printf("0 - Выход\n");
		printf("Выберите операцию: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Введите длину основания: ");
			scanf("%lf", &a);
			printf("Введите высоту: ");
			scanf("%lf", &h);
			if (a <= 0 || h <= 0) {
				printf("Ошибка: размеры должны быть больше нуля.\n");
			}
			else {
				s = area_triangle(a, h);
				printf("Площадь треугольника: %.2lf\n", s);
			}
			break;

		case 2:
			print_definition();
			break;

		case 3:
			printf("Введите высоту треугольника: ");
			scanf("%d", &draw_h);
			if (draw_h <= 0) {
				printf("Ошибка: высота должна быть больше нуля.\n");
			}
			else {
				printf("Введите символ для рисования: ");
				scanf(" %c", &ch);
				draw_triangle(draw_h, ch);
			}
			break;

		case 4:
			printf("Первый треугольник:\n");
			printf("Введите основание и высоту: ");
			scanf("%lf %lf", &a1, &h1);
			printf("Второй треугольник:\n");
			printf("Введите основание и высоту: ");
			scanf("%lf %lf", &a2, &h2);
			if (a1 <= 0 || h1 <= 0 || a2 <= 0 || h2 <= 0) {
				printf("Ошибка: размеры должны быть больше нуля.\n");
			}
			else {
				s1 = area_triangle(a1, h1);
				s2 = area_triangle(a2, h2);
				diff = compare_triangles(s1, s2);
				printf("Площадь первого: %.2lf, площадь второго: %.2lf\n", s1, s2);
				if (diff > 0) {
					printf("Первый треугольник больше второго на %.2lf\n", diff);
				}
				else if (diff < 0) {
					printf("Второй треугольник больше первого на %.2lf\n", -diff);
				}
				else {
					printf("Площади треугольников равны\n");
				}
			}
			break;

		case 0:
			printf("Завершение программы.\n");
			break;

		default:
			printf("Неверный пункт меню, попробуйте снова.\n");
			break;
		}
	} while (choice != 0);
}

double area_triangle(double a, double h) {
	return 0.5 * a * h;
}

void print_definition(void) {
	printf("Равнобедренный треугольник — треугольник, у которого две стороны равны между собой.\n");
}

void draw_triangle(int h, char ch) {
	int i, j;
	for (i = 0; i < h; i++) {
		for (j = 0; j < h + i; j++) {
			if (j < h - 1 - i) {
				printf(" ");
			}
			else {
				printf("%c", ch);
			}
		}
		printf("\n");
	}
}

double compare_triangles(double s1, double s2) {
	return s1 - s2;
}
