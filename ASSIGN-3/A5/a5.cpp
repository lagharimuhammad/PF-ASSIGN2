#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct species_inventory
{
    char **supplies;
    int supply_count;
} species_inventory;


species_inventory* initialize_inventory(int num_species) 
{
    species_inventory *inventory = (species_inventory*)malloc(num_species * sizeof(species_inventory));

    for (int i = 0; i < num_species; i++) {
        inventory[i].supplies = NULL;
        inventory[i].supply_count = 0;
    }
    return inventory;
}

void add_supplies(species_inventory *species_inventory) 
{
    int num_of_supplies;
    printf("Enter the number of supplies: ");
    scanf("%d", &num_of_supplies);
    getchar();

    species_inventory->supplies = (char**)realloc(species_inventory->supplies, num_of_supplies * sizeof(char*));
    species_inventory->supply_count = num_of_supplies;

    for (int i = 0; i < num_of_supplies; i++) 
	{
        species_inventory->supplies[i] = (char*)malloc(50 * sizeof(char));
        printf("Enter the name of supply %d: ", i + 1);
        fgets(species_inventory->supplies[i], 50, stdin);
        species_inventory->supplies[i][strcspn(species_inventory->supplies[i], "\n")] = '\0'; 
    }
}

void update_supply(species_inventory *species_inventory) 
{
    int supply_index;
    printf("Enter the supply index to update (0-%d): ", species_inventory->supply_count - 1);
    scanf("%d", &supply_index);
    getchar();

    if (supply_index >= 0 && supply_index < species_inventory->supply_count) 
	{
        printf("Enter the new name for supply %d: ", supply_index);
        fgets(species_inventory->supplies[supply_index], 50, stdin);
        species_inventory->supplies[supply_index][strcspn(species_inventory->supplies[supply_index], "\n")] = '\0';
    } 
	else 
	{
        printf("invalid supply index!\n");
    }
}

void remove_species(species_inventory *species_inventory) 
{
    for (int i = 0; i < species_inventory->supply_count; i++) 
        free(species_inventory->supplies[i]);
    
    free(species_inventory->supplies);
    species_inventory->supplies = NULL;
    species_inventory->supply_count = 0;
}

void display_inventory(species_inventory *species_inventory) 
{
    if (species_inventory->supply_count == 0) 
	{
        printf("No supplies found for this species.\n");
    } 
	else 
	{
        printf("Supplies for this species:\n");
        for (int i = 0; i < species_inventory->supply_count; i++) 
		{
            printf("- %s\n", species_inventory->supplies[i]);
        }
    }
}


void free_inventory(species_inventory *inventory, int num_species) 
{
    for (int i = 0; i < num_species; i++) 
	{
        remove_species(&inventory[i]);
    }
    free(inventory);
}

int main() 
{
    int num_species;
    printf("Enter the number of species: ");
    scanf("%d", &num_species);
    getchar();

    species_inventory *inventory = initialize_inventory(num_species);

    char species_names[3][50] = {"Dogs", "Cats", "Birds"};

    int choice, species_index;

    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
        {
            case 1:
                printf("Enter species index (0-%d): ", num_species - 1);
                scanf("%d", &species_index);
                getchar();

                if (species_index >= 0 && species_index < num_species) 
				{
                    printf("Adding supplies for species: %s\n", species_names[species_index]);
                    add_supplies(&inventory[species_index]);
                } 
				else 
				{
                    printf("Invalid species index!\n");
                }
                break;
                
            case 2:
                printf("Enter species index (0-%d): ", num_species - 1);
                scanf("%d", &species_index);
                getchar();

                if (species_index >= 0 && species_index < num_species) 
				{
                    printf("Updating supplies for species: %s\n", species_names[species_index]);
                    update_supply(&inventory[species_index]);
                } 
				else 
				{
                    printf("Invalid species index!\n");
                }
                break;
                
            case 3:
                printf("Enter species index (0-%d): ", num_species - 1);
                scanf("%d", &species_index);
                getchar();

                if (species_index >= 0 && species_index < num_species) 
				{
                    printf("Removing species: %s\n", species_names[species_index]);
                    remove_species(&inventory[species_index]);
                } 
				else 
				{
                    printf("invalid species");
                }
                break;
                
            case 4:
                printf("Enter species index (0-%d): ", num_species - 1);
                scanf("%d", &species_index);
                getchar();

                if (species_index >= 0 && species_index < num_species) 
				{
                    printf("Inventory for species: %s\n", species_names[species_index]);
                    display_inventory(&inventory[species_index]);
                } 
				else 
				{
                    printf("Invalid species index!\n");
                }
                break;
                
            case 5:
                printf("Exiting the program...\n");
                free_inventory(inventory, num_species);
                return 0;
                
            default:
                printf("invalid choice");
        }
    }

    return 0;
}

