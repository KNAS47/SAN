#include <stdio.h>

int printSet(int set[], int size) {
    if (size == 0) {
        printf("empty\n");
    } else {
        for (int i = 0; i < size; i++) {
            printf("%d ", set[i]);
        }
        printf("\n");
    }
}

int intoSet(int inputArray[], int *set, int size) {
    int found;
    int setSize = 0;
    for (int i = 0; i < size; i++) {
        found = 0;
        for (int j = 0; j < setSize; j++) {
            if (inputArray[i] == set[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            set[setSize++] = inputArray[i];
        }
    }
    return setSize;
}

int isInSet(int value, int checkSet[], int setSize) {
    for (int i = 0; i < setSize; i++) {
        if (value == checkSet[i]) {
            return 1;
        }
    }
    return 0;
}

int bubbleSort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int showSetUnion(int setA[], int sizeA, int setB[], int sizeB) {
    int resultArray[sizeA + sizeB];
    int resultSize = 0;

    for (int i = 0; i < sizeA; i++) {
        resultArray[resultSize++] = setA[i];
    }

    for (int i = 0; i < sizeB; i++) {
        if (!isInSet(setB[i], resultArray, resultSize)) {
            resultArray[resultSize++] = setB[i];
        }
    }

    bubbleSort(resultArray, resultSize);
    printSet(resultArray, resultSize);
}

int showIntersection(int setA[], int sizeA, int setB[], int sizeB) {
    int result[sizeA];
    int resultSize = 0;

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                result[resultSize++] = setA[i];
                break;
            }
        }
    }

    bubbleSort(result, resultSize);
    printSet(result, resultSize);
}

int showDifference(int setA[], int sizeA, int setB[], int sizeB) {
    int result[sizeA];
    int resultSize = 0;

    for (int i = 0; i < sizeA; i++) {
        if (!isInSet(setA[i], setB, sizeB)) {
            result[resultSize++] = setA[i];
        }
    }

    bubbleSort(result, resultSize);
    printSet(result, resultSize);
}

int showComplement(int set[], int setSize, int minRange, int maxRange) {
    int result[maxRange - minRange + 1];
    int resultSize = 0;

    for (int i = minRange; i <= maxRange; i++) {
        if (!isInSet(i, set, setSize)) {
            result[resultSize++] = i;
        }
    }

    printSet(result, resultSize);
}

int main() {
    int rangeStart, rangeEnd;
    scanf("%d %d", &rangeStart, &rangeEnd);

    int sizeA;
    scanf("%d", &sizeA);
    int arrayA[sizeA], countA = 0, inputValueA;

    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &inputValueA);
        if (inputValueA >= rangeStart && inputValueA <= rangeEnd) {
            arrayA[countA++] = inputValueA;
        }
    }
    sizeA = countA;

    int setA[sizeA];
    int setASize = intoSet(arrayA, setA, sizeA);

    int sizeB;
    scanf("%d", &sizeB);
    int arrayB[sizeB], countB = 0;

    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &inputValueA);
        if (inputValueA >= rangeStart && inputValueA <= rangeEnd) {
            arrayB[countB++] = inputValueA;
        }
    }
    sizeB = countB;

    int setB[sizeB];
    int setBSize = intoSet(arrayB, setB, sizeB);

    printSet(setA, setASize);
    printSet(setB, setBSize);
    showSetUnion(setA, setASize, setB, setBSize); //AnB
    showIntersection(setA, setASize, setB, setBSize); // ซ้ำ
    showDifference(setA, setASize, setB, setBSize); // aไม่เอาb
    showDifference(setB, setBSize, setA, setASize); // bไม่เอาa
    showComplement(setA, setASize, rangeStart, rangeEnd); //universe not a
    showComplement(setB, setBSize, rangeStart, rangeEnd); //universe not b

    return 0;
}
