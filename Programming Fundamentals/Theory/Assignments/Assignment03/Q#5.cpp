#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Species {
    char speciesName[100];
    int supplyCount;
    char** supplyList;
};

struct Species* initializeSpecies(int* speciesCount) {
    int i;
    printf("\nEnter the number of species: ");
    scanf("%d", speciesCount);
    struct Species* speciesArray = (struct Species*)malloc(*speciesCount * sizeof(struct Species));
    for (i = 0; i < *speciesCount; i++) {
        printf("\nEnter the name of the species: ");
        scanf("%s", speciesArray[i].speciesName);
        speciesArray[i].supplyCount = 0;
        speciesArray[i].supplyList = NULL;
    }
    return speciesArray;
}

void addSupplies(struct Species* speciesArray, int speciesCount) {
    int i, j;
    for (i = 0; i < speciesCount; i++) {
        printf("\nEnter the number of supplies for %s: ", speciesArray[i].speciesName);
        scanf("%d", &speciesArray[i].supplyCount);
        speciesArray[i].supplyList = (char**)realloc(speciesArray[i].supplyList, speciesArray[i].supplyCount * sizeof(char*));
        for (j = 0; j < speciesArray[i].supplyCount; j++) {
            speciesArray[i].supplyList[j] = (char*)malloc(100 * sizeof(char));
            printf("\nEnter the name of supply %d: ", j + 1);
            scanf("%s", speciesArray[i].supplyList[j]);
        }
    }
}

void updateSupply(struct Species* speciesArray, int speciesCount) {
    char targetSpecies[100], targetSupply[100];
    int i, j, foundSpecies = 0, foundSupply = 0;
    printf("\nEnter the name of the species to update: ");
    scanf("%s", targetSpecies);
    for (i = 0; i < speciesCount; i++) {
        if (strcmp(targetSpecies, speciesArray[i].speciesName) == 0) {
            foundSpecies = 1;
            printf("\nEnter the supply to replace: ");
            scanf("%s", targetSupply);
            for (j = 0; j < speciesArray[i].supplyCount; j++) {
                if (strcmp(targetSupply, speciesArray[i].supplyList[j]) == 0) {
                    foundSupply = 1;
                    printf("\nEnter the new supply: ");
                    scanf("%s", speciesArray[i].supplyList[j]);
                    printf("\nSupply updated\n");
                }
            }
            if (!foundSupply) {
                printf("\nSupply not found\n");
            }
        }
    }
    if (!foundSpecies) {
        printf("\nSpecies not found\n");
    }
}

void deleteSpecies(struct Species* speciesArray, int* speciesCount) {
    char targetSpecies[100];
    int i, j, found = 0;
    printf("\nEnter the name of the species to delete: ");
    scanf("%s", targetSpecies);
    for (i = 0; i < *speciesCount; i++) {
        if (strcmp(targetSpecies, speciesArray[i].speciesName) == 0) {
            found = 1;
            for (j = 0; j < speciesArray[i].supplyCount; j++) {
                free(speciesArray[i].supplyList[j]);
            }
            free(speciesArray[i].supplyList);
            for (j = i; j < (*speciesCount) - 1; j++) {
                speciesArray[j] = speciesArray[j + 1];
            }
            (*speciesCount)--;
            speciesArray = (struct Species*)realloc(speciesArray, (*speciesCount) * sizeof(struct Species));
            break;
        }
    }
    if (!found) {
        printf("\nSpecies not found\n");
    }
}

void displayAllSpecies(struct Species* speciesArray, int speciesCount) {
    printf("\nSpecies and their supplies:\n");
    for (int i = 0; i < speciesCount; i++) {
        printf("%s: ", speciesArray[i].speciesName);
        for (int j = 0; j < speciesArray[i].supplyCount; j++) {
            printf("%s ", speciesArray[i].supplyList[j]);
        }
        printf("\n");
    }
}

int main() {
    int speciesCount = 0, option = -1;
    struct Species* speciesArray = initializeSpecies(&speciesCount);
    while (option != 5) {
        printf("\n1: Add Supplies\n");
        printf("2: Update Supplies\n");
        printf("3: Delete Species\n");
        printf("4: Display Species\n");
        printf("5: Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        getchar();
        switch (option) {
            case 1:
                addSupplies(speciesArray, speciesCount);
                break;
            case 2:
                updateSupply(speciesArray, speciesCount);
                break;
            case 3:
                deleteSpecies(speciesArray, &speciesCount);
                break;
            case 4:
                displayAllSpecies(speciesArray, speciesCount);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    }
    for (int i = 0; i < speciesCount; i++) {
        for (int j = 0; j < speciesArray[i].supplyCount; j++) {
            free(speciesArray[i].supplyList[j]);
        }
        free(speciesArray[i].supplyList);
    }
    free(speciesArray);
    return 0;
}

