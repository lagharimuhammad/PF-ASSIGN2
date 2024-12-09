#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM_USERS 5
#define NUM_CATEGORIES 3
#define NUM_DEVICES 3
#define NUM_CONTENT 5


typedef struct content_metadata
{
    char title[100];
    float rating;
    int runtime;
    char encoding_format[50];
} content_metadata;


typedef struct device_preferences
{
    int resolution;  
    int playback_history;  
    int bandwidth_usage;  
} device_preferences;


typedef struct user_profile
{
    float* engagementScores;  
} user_profile;


float** initialize_engagement_matrix(int num_of_users, int num_of_categories) 
{
    float** engagement_matrix = (float**)malloc(num_of_users * sizeof(float*));

    for (int i = 0; i < num_of_users; i++) 
    {
        engagement_matrix[i] = (float*)malloc(num_of_categories * sizeof(float));

        for (int j = 0; j < num_of_categories; j++) 
        {
            engagement_matrix[i][j] = 0.0f;
        }
    }
    return engagement_matrix;
}


device_preferences*** initialize_device_matrix(int num_of_users, int num_of_devices) 
{
    device_preferences*** device_matrix = (device_preferences***)malloc(num_of_users * sizeof(device_preferences**));

    for (int i = 0; i < num_of_users; i++) 
    {
        device_matrix[i] = (device_preferences**)malloc(num_of_devices * sizeof(device_preferences*));

        for (int j = 0; j < num_of_devices; j++) 
        {
            device_matrix[i][j] = (device_preferences*)malloc(sizeof(device_preferences));
            device_matrix[i][j]->resolution = 1080; 
            device_matrix[i][j]->playback_history = 0;  
            device_matrix[i][j]->bandwidth_usage = 0;
        }
    }
    return device_matrix;
}


content_metadata*** initialize_content_metadata_matrix(int num_of_categories, int num_of_content) 
{
    content_metadata*** content_matrix = (content_metadata***)malloc(num_of_categories * sizeof(content_metadata**));

    for (int i = 0; i < num_of_categories; i++) 
    {
        content_matrix[i] = (content_metadata**)malloc(num_of_content * sizeof(content_metadata*));

        for (int j = 0; j < num_of_content; j++) 
        {
            content_matrix[i][j] = (content_metadata*)malloc(sizeof(content_metadata));
            strcpy(content_matrix[i][j]->title, "untitled");
            content_matrix[i][j]->rating = 0.0f;
            content_matrix[i][j]->runtime = 0;
            strcpy(content_matrix[i][j]->encoding_format, "unknown");
        }
    }
    return content_matrix;
}

void update_engagement_score(float** engagement_matrix, int user_index, int category_index, float score) 
{
    engagement_matrix[user_index][category_index] = score;
}

void update_device_preference(device_preferences*** device_matrix, int user_index, int device_index, int resolution, int playback_history, int bandwidth_usage) 
{
    device_matrix[user_index][device_index]->resolution = resolution;
    device_matrix[user_index][device_index]->playback_history = playback_history;
    device_matrix[user_index][device_index]->bandwidth_usage = bandwidth_usage;
}

void update_content_metadata(content_metadata*** content_matrix, int category_index, int content_index, const char* title, float rating, int runtime, const char* encoding_format) 
{
    strcpy(content_matrix[category_index][content_index]->title, title);
    content_matrix[category_index][content_index]->rating = rating;
    content_matrix[category_index][content_index]->runtime = runtime;
    strcpy(content_matrix[category_index][content_index]->encoding_format, encoding_format);
}


void print_engagement_matrix(float** engagement_matrix, int num_of_users, int num_of_categories) 
{
    printf("Engagement Matrix:\n");
    for (int i = 0; i < num_of_users; i++) 
    {
        for (int j = 0; j < num_of_categories; j++) 
        {
            printf("%.2f ", engagement_matrix[i][j]);
        }
        printf("\n");
    }
}

void printDevice_matrix(device_preferences*** device_matrix, int num_of_users, int num_of_devices) 
{
    printf("\nDevice Matrix:\n");
    for (int i = 0; i < num_of_users; i++) 
    {
        for (int j = 0; j < num_of_devices; j++) 
        {
            printf("User %d, Device %d: Resolution %dp, Playback History: %d minutes, Bandwidth Usage: %dMB\n", i, j, device_matrix[i][j]->resolution, device_matrix[i][j]->playback_history, device_matrix[i][j]->bandwidth_usage);
        }
    }
}

void printcontent_metadataMatrix(content_metadata*** content_matrix, int num_of_categories, int num_of_content) 
{
    printf("\nContent Metadata Matrix:\n");
    for (int i = 0; i < num_of_categories; i++) 
    {
        for (int j = 0; j < num_of_content; j++) 
        {
            printf("Category %d, Content %d: Title: %s, Rating: %.1f, Runtime: %d minutes, Format: %s\n", i, j, content_matrix[i][j]->title, content_matrix[i][j]->rating, content_matrix[i][j]->runtime, content_matrix[i][j]->encoding_format);
        }
    }
}

int main() 
{
   
    float** engagement_matrix = initialize_engagement_matrix(NUM_USERS, NUM_CATEGORIES);
    device_preferences*** device_matrix = initialize_device_matrix(NUM_USERS, NUM_DEVICES);
    content_metadata*** content_matrix = initialize_content_metadata_matrix(NUM_CATEGORIES, NUM_CONTENT);

    update_engagement_score(engagement_matrix, 0, 1, 5.0f);
    update_device_preference(device_matrix, 0, 2, 80, 120, 500);  
    
    update_content_metadata(content_matrix, 1, 2, "Sample", 4.5f, 120, "MP4");

    print_engagement_matrix(engagement_matrix, NUM_USERS, NUM_CATEGORIES);
    printDevice_matrix(device_matrix, NUM_USERS, NUM_DEVICES);
    printcontent_metadataMatrix(content_matrix, NUM_CATEGORIES, NUM_CONTENT);

    for (int i = 0; i < NUM_USERS; i++) 
    {
        free(engagement_matrix[i]);
    }
    free(engagement_matrix);

    for (int i = 0; i < NUM_USERS; i++) 
    {
        for (int j = 0; j < NUM_DEVICES; j++) 
        {
            free(device_matrix[i][j]);
        }
        free(device_matrix[i]);
    }
    free(device_matrix);

    for (int i = 0; i < NUM_CATEGORIES; i++) 
    {
        for (int j = 0; j < NUM_CONTENT; j++) 
        {
            free(content_matrix[i][j]);
        }
        free(content_matrix[i]);
    }
    free(content_matrix);

    return 0;
}

