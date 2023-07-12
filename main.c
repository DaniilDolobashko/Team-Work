#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct
{
    int id;
    char name[100];
    float price;
} Product;

void addToCart(Product *product, int quantity, float *total)
{
    float itemTotal = product->price * quantity;
    *total += itemTotal;
    printf("Товар додано до корзини. Загальна вартість: %.2f\n", *total);
}

void listProducts(Product *inventory, int count)
{
    printf("Список продуктів:\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d, Назва: %s, Ціна: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].price);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Product inventory[5];
    int count = 5;

    inventory[0].id = 1;
    strcpy(inventory[0].name, "Телефон 1");
    inventory[0].price = 100.0;

    inventory[1].id = 2;
    strcpy(inventory[1].name, "Телефон 2");
    inventory[1].price = 200.0;

    inventory[2].id = 3;
    strcpy(inventory[2].name, "Телефон 3");
    inventory[2].price = 150.0;

    inventory[3].id = 4;
    strcpy(inventory[3].name, "Телефон 4");
    inventory[3].price = 400.0;

    inventory[4].id = 5;
    strcpy(inventory[4].name, "Телефон 5");
    inventory[4].price = 250.0;

    int choice;
    float total = 0.0;

    do
    {
        printf("Меню:\n");
        printf("1. Вивести список продуктів\n");
        printf("2. Додати продукт до корзини\n");
        printf("3. Вивести загальну вартість корзини\n");
        printf("4. Вийти\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            listProducts(inventory, count);
            break;
        case 2:
            int productId, quantity;
            printf("Введіть ID продукту: ");
            scanf("%d", &productId);
            printf("Введіть кількість: ");
            scanf("%d", &quantity);

            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (inventory[i].id == productId)
                {
                    addToCart(&inventory[i], quantity, &total);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Продукт з ID %d не знайдено\n", productId);
            }
            break;
        case 3:
            printf("Загальна вартість корзини: %.2f\n", total);
            break;
        case 4:
            printf("Дякую за використання магазину!\n");
            break;
        default:
            printf("Невірний вибір. Спробуйте ще раз.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
