#include "stdio.h"
#include "math.h"

typedef struct studentTag {
    char name[10];
    int age;
    double gpa;
} student;

typedef struct Point {
    int x;
    int y;
} Point;

int get_distance(Point p1, Point p2) {
    int dist = (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
    return sqrt(dist);
}

int main(void) {
    student s = { "brian", 12, 3.0};
    printf("%s + %d + %f", s.name, s.age, s.gpa);
    Point p1 = {1, 2}, p2 = {9, 8};
    printf("%d, %d + %d, %d", p1.x, p1.y, p2.x, p2.y);
    printf("%d", get_distance(p1, p2));
   
    return 0;
}