#include <stdio.h>
#include <math.h>

float calculardistancias(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularperimetro(float puntos [4][3], float *a, float *b, float *c, float *d, float *e, float *f, float *baricentro);
float calculararea(float a, float b, float c);
float calcularvolumen(float puntos [4][3], float area1, float *baricentro);

int main(int argc, char const *argv[])
{
    float puntos[5][3] = {{0,0,0},{3,0,0},{0,0,3},{1,7,1}};
    float per, a, b, c, d, e, f, barcentro;

    calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f, &barcentro);
    float area1 = calculararea(a, b, c);
    float area2 = calculararea(b, d, e);
    float area3 = calculararea(a, e, f);
    float area4 = calculararea(e, f, a);
    float areasuperficial = area1 + area2 + area3;
    float volumen = calcularVolumen(puntos, area1, &barcentro);

    printf("El perimetro es: %f\n", a + b + c + d + e + f);
    printf("El area base es: %f\n", area1);
    printf("El area superficial es: %f\n", areasuperficial);
    printf("El volumen es: %f\n", volumen);
    
    return 0;
}

float calculardistancias(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    return dist;
}

float calcularperimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f, float *baricentro)
{
    *a = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c = calcularDistancias(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *d = calcularDistancias(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e = calcularDistancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f = calcularDistancias(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *baricentro = calcularDistancias(puntos[4][0], puntos[4][1], puntos[4][2], puntos[3][0], puntos[3][1], puntos[3][2]);
}

float calcularArea(float a, float b, float c)
{
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

float calcularVolumen(float puntos[4][3], float area1, float *barcentro)
{
    float volumen = (1 / 3.0) * area1 * (*barcentro);
    return volumen;
}