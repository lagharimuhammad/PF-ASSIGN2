#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50


typedef struct WeatherForecast
{
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;


typedef struct Crop
{
    char cropType[MAX_NAME_LENGTH];
    char growthStage[MAX_NAME_LENGTH];
    float expectedYield;
    WeatherForecast *forecast; 
} Crop;


typedef struct Equipment
{
    char equipmentName[MAX_NAME_LENGTH];
    char status[MAX_NAME_LENGTH];
    float fuelLevel;
    char activitySchedule[MAX_NAME_LENGTH];
} Equipment;


typedef struct SensorData
{
    float soilNutrients;
    float pHLevel;
    int pestActivity;
} SensorData;


typedef struct Field
{
    float latitude;
    float longitude;
    float soilHealth;
    float moistureLevel;
    Crop *crops; 
    int cropCount;
    Equipment *equipment; 
    int equipmentCount;
    SensorData *sensors; 
    int sensorCount;
} Field;


typedef struct RegionalHub
{
    Field *fields;
    int fieldCount;
    float totalYield;
    float resourceDistribution;
    char emergencyPlan[MAX_NAME_LENGTH];
} RegionalHub;


typedef struct CentralAnalyticsServer
{
    RegionalHub *hubs; 
    int hubCount;
} CentralAnalyticsServer;


Field* initializeField(float latitude, float longitude, int cropCount, int equipmentCount, int sensorCount);
RegionalHub* initializeRegionalHub(int fieldCount);
CentralAnalyticsServer* initializeAnalyticsServer(int hubCount);
void inputFieldData(Field *field);
void inputCropData(Crop *crop);
void generateInsights(CentralAnalyticsServer *server);
void displayRegionalHubData(const RegionalHub *hub);
void freeMemory(CentralAnalyticsServer *server);


Field* initializeField(float latitude, float longitude, int cropCount, int equipmentCount, int sensorCount) {
    Field *field = (Field*)malloc(sizeof(Field));
    if (!field) 
	{
        printf("Memory allocation failed for Field\n");
        exit(1);
    }

    field->latitude = latitude;
    field->longitude = longitude;
    field->soilHealth = 0.0f; 
    field->moistureLevel = 0.0f; 
    field->cropCount = cropCount;
    field->equipmentCount = equipmentCount;
    field->sensorCount = sensorCount;

    field->crops = (Crop*)malloc(cropCount * sizeof(Crop));
    field->equipment = (Equipment*)malloc(equipmentCount * sizeof(Equipment));
    field->sensors = (SensorData*)malloc(sensorCount * sizeof(SensorData));

    if (!field->crops || !field->equipment || !field->sensors) 
	{
        printf("Memory allocation failed for field components\n");
        exit(1);
    }

    return field;
}


RegionalHub* initializeRegionalHub(int fieldCount) 
{
    RegionalHub *hub = (RegionalHub*)malloc(sizeof(RegionalHub));
    if (!hub) 
	{
        printf("Memory allocation failed for RegionalHub\n");
        exit(1);
    }

    hub->fieldCount = fieldCount;
    hub->fields = (Field*)malloc(fieldCount * sizeof(Field));
    hub->totalYield = 0.0f;
    hub->resourceDistribution = 0.0f;
    strcpy(hub->emergencyPlan, "Default Emergency Plan");

    if (!hub->fields) 
	{
        printf("Memory allocation failed for hub fields\n");
        exit(1);
    }

    return hub;
}


CentralAnalyticsServer* initializeAnalyticsServer(int hubCount) 
{
    CentralAnalyticsServer *server = (CentralAnalyticsServer*)malloc(sizeof(CentralAnalyticsServer));
    if (!server) 
	{
        printf("Memory allocation failed for CentralAnalyticsServer\n");
        exit(1);
    }

    server->hubCount = hubCount;
    server->hubs = (RegionalHub*)malloc(hubCount * sizeof(RegionalHub));

    if (!server->hubs) 
	{
        printf("Memory allocation failed for hubs\n");
        exit(1);
    }

    return server;
}


void inputFieldData(Field *field) 
{
    printf("Enter soil health for the field at (%.2f, %.2f): ", field->latitude, field->longitude);
    scanf("%f", &field->soilHealth);
    printf("Enter moisture level for the field: ");
    scanf("%f", &field->moistureLevel);
}


void inputCropData(Crop *crop) 
{
    printf("Enter crop type: ");
    scanf("%s", crop->cropType);
    printf("Enter growth stage: ");
    scanf("%s", crop->growthStage);
    printf("Enter expected yield: ");
    scanf("%f", &crop->expectedYield);
}


void generateInsights(CentralAnalyticsServer *server) 
{
    printf("\nGenerating insights for %d regional hubs...\n", server->hubCount);
    for (int i = 0; i < server->hubCount; i++) 
	{
        RegionalHub *hub = &server->hubs[i];
        hub->totalYield = 0.0f;

        for (int j = 0; j < hub->fieldCount; j++) 
		{
            Field *field = &hub->fields[j];
            for (int k = 0; k < field->cropCount; k++) 
			{
                hub->totalYield += field->crops[k].expectedYield;
            }
        }

        printf("Total yield for hub %d: %.2f\n", i + 1, hub->totalYield);
    }
}


void displayRegionalHubData(const RegionalHub *hub) 
{
    printf("\nRegional Hub Data:\n");
    for (int i = 0; i < hub->fieldCount; i++) 
	{
        Field *field = &hub->fields[i];
        printf("Field (Lat: %.2f, Long: %.2f) - Soil Health: %.2f, Moisture: %.2f\n", 
                field->latitude, field->longitude, field->soilHealth, field->moistureLevel);
    }
}


void freeMemory(CentralAnalyticsServer *server) 
{
    for (int i = 0; i < server->hubCount; i++) 
	{
        RegionalHub *hub = &server->hubs[i];

        for (int j = 0; j < hub->fieldCount; j++) 
		{
            Field *field = &hub->fields[j];
            free(field->crops);
            free(field->equipment);
            free(field->sensors);
        }

        free(hub->fields);
    }

    free(server->hubs);
    free(server);
}


int main() {
    int hubCount = 1, fieldCount = 2, cropCount = 2, equipmentCount = 2, sensorCount = 2;

    CentralAnalyticsServer *server = initializeAnalyticsServer(hubCount);
    server->hubs[0] = *initializeRegionalHub(fieldCount);

    for (int i = 0; i < fieldCount; i++) 
	{
        Field *field = initializeField(34.05 + i, -118.24 - i, cropCount, equipmentCount, sensorCount);
        inputFieldData(field);

        for (int j = 0; j < cropCount; j++) 
		{
            inputCropData(&field->crops[j]);
        }

        server->hubs[0].fields[i] = *field;
    }

    generateInsights(server);
    displayRegionalHubData(&server->hubs[0]);

    freeMemory(server);
    return 0;
}

