//puwanut theeranuluk 66070503477
#include <stdio.h>
#include <math.h>

struct Student {
    char name[20];
    double score;
};

int main() {
    int n;
    scanf("%d", &n);
    struct Student students[n];

    for (int i = 0; i < n; i++) {
        scanf("%s", students[i].name);
        scanf("%lf", &students[i].score);
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].score;
    }

    double mean = sum / n;
    double sd, temp = 0.0;

    for (int i = 0; i < n; i++) {
        temp += pow((students[i].score - mean), 2);
    }

    sd = sqrt(temp / n);
    double max = students[0].score, min = students[0].score;
    int pos_max = 0, pos_min = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].score > max) {
            max = students[i].score;
            pos_max = i;
        }
        if (students[i].score < min) {
            min = students[i].score;
            pos_min = i;
        }
    }
    printf("%.2lf %.2lf %s %s\n", mean, sd, students[pos_max].name, students[pos_min].name);
    return 0;
}
