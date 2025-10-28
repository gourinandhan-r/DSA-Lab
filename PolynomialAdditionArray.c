#include <stdio.h>
int main() {
    int deg1, deg2;
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    int poly1[deg1 + 1];
    printf("Enter coefficients of first polynomial (from highest degree to constant term): ");
    for (int i = 0; i <= deg1; i++)
        scanf("%d", &poly1[i]);
    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);
    int poly2[deg2 + 1];
    printf("Enter coefficients of second polynomial (from highest degree to constant term): ");
    for (int i = 0; i <= deg2; i++)
        scanf("%d", &poly2[i]);
    int maxDeg = (deg1 > deg2) ? deg1 : deg2;
    int result[maxDeg + 1];
    for (int i = 0; i <= maxDeg; i++) {
        int a = (i <= maxDeg - deg1 - 1) ? 0 : poly1[i - (maxDeg - deg1)];
        int b = (i <= maxDeg - deg2 - 1) ? 0 : poly2[i - (maxDeg - deg2)];
        result[i] = a + b;
    }
    printf("Resultant polynomial: ");
    for (int i = 0; i <= maxDeg; i++) {
        if (result[i] != 0) {
            printf("%dx^%d ", result[i], maxDeg - i);
            if (i < maxDeg) printf("+ ");
        }
    }
    printf("\n");

    return 0;
}
