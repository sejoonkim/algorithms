#include "stdio.h"
#define MAX(a, b) ((a > b) ? a : b);
#define MAX_DEGREE 101
typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

void print_poly(polynomial p){
    for (int i = p.degree; i > 0; i--) {
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%.1f \n", p.coef[p.degree]);
}

polynomial poly_add1(polynomial A, polynomial B) {
    polynomial C; // result
    int Apos = 0, Bpos = 0, Cpos = 0; // indexes for arrays
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(degree_a, degree_b);

    while (Apos <= A.degree && Bpos <= B.degree) {
        if (degree_a > degree_b) { // A항 > B항
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (A.coef[Apos] + B.coef[Bpos] == 0 && degree_a == degree_b && degree_a == A.degree) {
            C.coef[Cpos++] = 0;
            C.degree--;
        }
        else if (degree_a == degree_b) {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--; degree_b--;
        }
        else {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

int main(void) {
    polynomial a= {5, {3, 6, 0, 0, 0, 10}};
    polynomial b= {5, {-3, 7, 0, 5, 0, 1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c = poly_add1(a, b);
    printf("-------------------------------------------------\n");
    print_poly(c);
    return 0;
}