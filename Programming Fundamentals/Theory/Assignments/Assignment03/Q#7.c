#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    double rating;
    int duration;
    char format[50];
} Media;

	double** createEngagementMatrix(int userCount, int categoryCount);

	void updateEngagement(double** matrix, int user, int category, double value);

double*** createDevicePreferences(int userCount, int deviceCount);
void setDevicePreference(double*** preferences, int user, int device, int attribute, double value);
Media*** createMediaLibrary(int categoryCount, int itemCount);

void addMedia(Media*** library, int category, int item, Media info);
void freeEngagementMatrix(double** matrix, int userCount);
void freeDevicePreferences(double*** preferences, int userCount, int deviceCount);

void freeMediaLibrary(Media*** library, int categoryCount, int itemCount);

int main() {
    int userCount, categoryCount, deviceCount, itemCount, user, category;
    userCount = 3;
    categoryCount = 3;
    deviceCount = 2;
    itemCount = 2;

    double** engagementMatrix = createEngagementMatrix(userCount, categoryCount);
    updateEngagement(engagementMatrix, 0, 0, 3.5);
    updateEngagement(engagementMatrix, 1, 2, 4.2);

    double*** devicePreferences = createDevicePreferences(userCount, deviceCount);
    setDevicePreference(devicePreferences, 0, 0, 0, 1080);

    Media*** mediaLibrary = createMediaLibrary(categoryCount, itemCount);
    Media movie = {"Action Adventure", 4.5, 120, "1080p"};
    addMedia(mediaLibrary, 0, 0, movie);

    for (user = 0; user < userCount; user++) {
        for (category = 0; category < categoryCount; category++) {
            printf("%.2f ", engagementMatrix[user][category]);
        }
        printf("\n");
    }

    freeEngagementMatrix(engagementMatrix, userCount);
    freeDevicePreferences(devicePreferences, userCount, deviceCount);
    freeMediaLibrary(mediaLibrary, categoryCount, itemCount);

    return 0;
}

double** createEngagementMatrix(int userCount, int categoryCount) {
    double** matrix;
    int i;
    matrix = malloc(userCount * sizeof(double*));
    for (i = 0; i < userCount; i++) {
        matrix[i] = calloc(categoryCount, sizeof(double));
    }
    return matrix;
}

void updateEngagement(double** matrix, int user, int category, double value) {
    matrix[user][category] = value;
}

double*** createDevicePreferences(int userCount, int deviceCount) {
    double*** preferences;
    int i, j;
    preferences = malloc(userCount * sizeof(double**));
    for (i = 0; i < userCount; i++) {
        preferences[i] = malloc(deviceCount * sizeof(double*));
        for (j = 0; j < deviceCount; j++) {
            preferences[i][j] = calloc(3, sizeof(double));
        }
    }
    return preferences;
}

void setDevicePreference(double*** preferences, int user, int device, int attribute, double value) {
    preferences[user][device][attribute] = value;
}

Media*** createMediaLibrary(int categoryCount, int itemCount) {
    Media*** library;
    int i, j;
    library = malloc(categoryCount * sizeof(Media**));
    for (i = 0; i < categoryCount; i++) {
        library[i] = malloc(itemCount * sizeof(Media*));
        for (j = 0; j < itemCount; j++) {
            library[i][j] = malloc(sizeof(Media));
        }
    }
    return library;
}

void addMedia(Media*** library, int category, int item, Media info) {
    *library[category][item] = info;
}

void freeEngagementMatrix(double** matrix, int userCount) {
    int i;
    for (i = 0; i < userCount; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeDevicePreferences(double*** preferences, int userCount, int deviceCount) {
    int i, j;
    for (i = 0; i < userCount; i++) {
        for (j = 0; j < deviceCount; j++) {
            free(preferences[i][j]);
        }
        free(preferences[i]);
    }
    free(preferences);
}

void freeMediaLibrary(Media*** library, int categoryCount, int itemCount) {
    int i, j;
    for (i = 0; i < categoryCount; i++) {
        for (j = 0; j < itemCount; j++) {
            free(library[i][j]);
        }
        free(library[i]);
    }
    free(library);
}

