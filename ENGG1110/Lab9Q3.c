
/**
* ENGG1110 Problem Solving by Programming
*
* I declare that the assignment here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* http://www.cuhk.edu.hk/policy/academichonesty/
*
* Student Name : Ankhbayar Enkhtaivan
* Student ID   : 1155185142
* Class/Section: ENGG1110D
* Date         : 06/04/2023
*/

/* include header file */
#include <stdio.h>
#include <math.h>

// DO NOT change this
typedef struct {
  double x, y;      // 2D rectilinear coordinates of a point
} Point;

double computeDistance(Point p1, Point p2) {
  // Write your code here

    // sqrt((x2-x1)^2 + (y2-y1)^2)

    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

}

double computeTriangleArea(Point p1, Point p2, Point p3) {
  // Write your code here


    double a = computeDistance(p1, p2);
    double b = computeDistance(p2, p3);
    double c = computeDistance(p3, p1);
    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));

}

int main(void) {
  // Don't modify the following line
  Point p1, p2, p3; // 3 points in the triangle
  // Write your code here
  
    scanf("%lf %lf", &p1.x, &p1.y);
    scanf("%lf %lf", &p2.x, &p2.y);
    scanf("%lf %lf", &p3.x, &p3.y);

    printf("p1:(%.1f, %.1f), p2:(%.1f, %.1f), p3:(%.1f, %.1f)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    printf("area = %.1f\n", computeTriangleArea(p1, p2, p3));

  return 0;
}
