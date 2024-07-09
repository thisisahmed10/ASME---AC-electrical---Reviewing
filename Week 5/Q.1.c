#include <stdio.h>
#include <math.h>
#define SQRT_3  sqrt(3.0)
#define PI 3.14159

typedef enum {
    CIRCLE,
    SQUARE,
    PENTAGON,
    HEXAGON
} ShapeType;

struct Shape {
    ShapeType type;
    union {
        float radius;
        float side_length;
    } dimensions;
};

float calculate_area(struct Shape* shape) {
    switch (shape->type) {
        case CIRCLE:
            return PI * (shape->dimensions.radius * shape->dimensions.radius);
        case SQUARE:
            return shape->dimensions.side_length * shape->dimensions.side_length;
        case PENTAGON:
            return 5 * shape->dimensions.side_length*shape->dimensions.side_length/(0.726542528*4);
        case HEXAGON:
            return 3.0f * SQRT_3 * pow(shape->dimensions.side_length, 2.0f) / 2.0f;
        default:
            printf("Invalid shape type\n");
            return -1.0f;
    }
}

float calculate_circumference(struct Shape* shape) {
    switch (shape->type) {
        case CIRCLE:
            return 2 * PI * shape->dimensions.radius;
        case SQUARE:
            return 4 * shape->dimensions.side_length;
        case PENTAGON:
            return 5 * shape->dimensions.side_length;
        case HEXAGON:
            return 6 * shape->dimensions.side_length;
        default:
            printf("Invalid shape type\n");
            return -1.0f;
    }
}

int main() {
    printf("\nCharacteristics of circle, type 1\n");
    printf("Characteristics of square, type 2\n");
    printf("Characteristics of pentagon, type 3\n");
    printf("Characteristics of hexagon, type 4\n");
    int key;
    if (scanf("%d", &key) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer number.\n");
        return 1; // Indicate error
    }
    if(key == 1){
        printf("Radius: ");
        struct Shape circle;
        circle.type = CIRCLE;
        if (scanf("%f", &circle.dimensions.radius) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter an integer number.\n");
            return 1; // Indicate error
        }
        printf("%d", circle.dimensions.radius);
        printf("Circle Area: %.2f\n", calculate_area(&circle));
        printf("Circle Circumference: %.2f\n", calculate_circumference(&circle));
    }else if(key == 2){
        printf("Side length: ");
        struct Shape sqr;
        sqr.type = SQUARE;
        if (scanf("%f", &sqr.dimensions.side_length) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter an integer number.\n");
            return 1; // Indicate error
        }
        printf("Square Area: %.2f\n", calculate_area(&sqr));
        printf("Square Circumference: %.2f\n", calculate_circumference(&sqr));
    }else if(key == 3){
        printf("Side length: ");
        struct Shape pen;
        pen.type = PENTAGON;
        if (scanf("%f", &pen.dimensions.side_length) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter an integer number.\n");
            return 1; // Indicate error
        }
        printf("Square Area: %.2f\n", calculate_area(&pen));
        printf("Square Circumference: %.2f\n", calculate_circumference(&pen));
    }else if(key == 4){
        printf("Side length: ");
        struct Shape hex;
        hex.type = HEXAGON;
        if (scanf("%f", &hex.dimensions.side_length) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter an integer number.\n");
            return 1; // Indicate error
        }
        printf("Square Area: %.2f\n", calculate_area(&hex));
        printf("Square Circumference: %.2f\n", calculate_circumference(&hex));
    }
    return 0;
}
