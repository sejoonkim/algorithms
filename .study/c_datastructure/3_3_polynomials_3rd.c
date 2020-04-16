#include <stdio.h>
#include <stdlib.h>

typedef struct poly {
    int degree;
    int *coef;
} poly;

int fitst(char *p);
int cut(char *p, int pos, int* expo);
void add(poly a, poly b);

int main(int argc, char *argv[]) {
    poly p, q;
    char str2[100];
    char str[100];
    int i = 0, expo, temp;
    int cnt = 0, j = 0;

    printf("input first polynomial: ");
    scanf("%s", str);

    printf("input second polynomial: ");
    scanf("%s", str2);

    p.degree = first(str);
    q.degree = first(str2);

    printf("%s\n", str);
    printf("%s\n", str2);

    p.coef = (int*)calloc((p.degree+1), sizeof(int));
    q.coef = (int*)calloc((q.degree+1), sizeof(int));

    for (i = 0; i < p.degree; i++) {
        temp = cut(str, i, &expo);
        p.coef[p.degree-expo] = temp;
    }

    for (i = 0; i < q.degree; i++) {
        temp = cut(str2, i, &expo);
        q.coef[q.degree-expo] = temp;
    }

    printf("exponent of highest polynomial : %d\n", q.degree);
    printf("coef : { ");
    for (j = 0; j < p.degree + 1; j++) {
        printf("%2d, ", p.coef[j]);
    }
    printf("}\n");

    add(p, q);
    return 0;
}

int first(char *p) {
    int i = 0;
    while (*p != '\0') {
        if (*p =='^') {
            return *(p+1) - '0';
        }
        i++, p++;
    }
    return 1;
}

int cut(char *p, int pos, int *expo) {
    int i = 0;
    int cnt = -1;
    char temp[10];

    while (*p != '\0') {
        if (pos == 0) {
            while (1) {
                temp[i++] = *p;
                p++;
                if(*p == 'x') {
                    temp[i] = '\0';
                    (*expo) = *(p+2) - '\0';
                    return atoi(temp);
                }
            }
        }
        else {
            while(1) {
                temp[i++] = *p;
                p++;
                if (*p == '\0') {
                    temp[i] = '\0';
                    (*expo) = 0;
                    return atoi(temp);
                }
                if (*p == 'x') break;
            }
            p++;

            if (*p == '^') {
                cnt++;
            }
                if(cnt == pos) {
                    temp[i] = '\0';
                    (*expo) = *(p+1) - '\0';

                    return atoi(temp);
                }
            }
        }
    }
}