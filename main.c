#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    char brand[20];
    float price, memory;
} Product;

typedef struct {
    Product product;
    int quantity;
} CartItem;

void addToCart(Product* product, int quantity, CartItem* cart, int* cartSize) {
    cart[*cartSize].product = *product;
    cart[*cartSize].quantity = quantity;
    (*cartSize)++;
    printf("Товар додано до корзини.\n");
}

void addSumCart(Product* product, int quantity, float* total) {
    float itemTotal = product->price * quantity;
    *total += itemTotal;
    printf("Товар додано до корзини. Загальна вартість: %.2f\n", *total);
}

void displayCart(CartItem* cart, int cartSize) {
    if (cartSize == 0) {
        printf("Корзина порожня.\n");
        return;
    }

    printf("Товари у корзині:\n");
    for (int i = 0; i < cartSize; i++) {
        printf("Товар: %s\n", cart[i].product.name);
        printf("Ціна: %.2f\n", cart[i].product.price);
        printf("Кількість: %d\n", cart[i].quantity);
        printf("-----------------------------\n");
    }
}

void listProducts(Product* inventory, int count) {
    printf("Список продуктів:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Назва: %s %s, Пам'ять: %.0f GB, Ціна: %.2f грн\n", inventory[i].id, inventory[i].brand, inventory[i].name, inventory[i].memory, inventory[i].price);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int productId, quantity;

    Product inventory[5];
    int count = 5;

    inventory[0].id = 1;
    strcpy(inventory[0].brand, "Xiaomi");
    strcpy(inventory[0].name, "Телефон 1");
    inventory[0].memory = 128;
    inventory[0].price = 100.0;


    inventory[1].id = 2;
    strcpy(inventory[0].brand, "Samsung");
    strcpy(inventory[1].name, "Телефон 2");
    inventory[0].memory = 128;
    inventory[1].price = 200.0;

    inventory[2].id = 3;
    strcpy(inventory[0].brand, "Xiaomi");
    strcpy(inventory[2].name, "Телефон 3");
    inventory[0].memory = 64;
    inventory[2].price = 150.0;

    inventory[3].id = 4;
    strcpy(inventory[0].brand, "Apple");
    strcpy(inventory[3].name, "Телефон 4");
    inventory[0].memory = 256;
    inventory[3].price = 400.0;

    inventory[4].id = 5;
    strcpy(inventory[0].brand, "Xiaomi");
    strcpy(inventory[4].name, "Телефон 5");
    inventory[0].memory = 128;
    inventory[4].price = 250.0;

    CartItem cart[10];
    int cartSize = 0; 
    int choice;
    float total = 0.0;
    char surname[20], name[20], middleName[20], sex[10], mail[100];

    printf("Дорогий покупець, вітаємо тебе в нашому інтернет-магазині \"СІШКА\"\n\n");
    printf("Для початку пройдемо реєстрацію. Будь ласка, заповніть наступні поля:\n");
    printf("Прізвище: ");
    scanf("%s", &surname);
    printf("Ім'я: ");
    scanf("%s", &name);
    printf("По-батькові: ");
    scanf("%s", &middleName);
    printf("Стать (це потрібно для того, щоб ми могли рекомендувати вам відповідні товари): ");
    scanf("%s", &sex);
    printf("E-mail: ");
    scanf("%s", &mail);
    printf("\n%s, вітаємо Вас з успішною реєстрацією!\n", name);
    
    char menuChoice[15];

    do {
    printf("Якщо ви бажаєте продовжити, впишіть \"так\", щоб покинути магазин напишіть \"покинути\": \n");
    scanf("%s", &menuChoice);

    if (strcmp(menuChoice, "так") == 0) {
    do {
        printf("Меню:\n");
        printf("1. Вивести список продуктів\n");
        printf("2. Додати продукт до корзини\n");
        printf("3. Переглянути вміст корзини\n");
        printf("4. Вийти\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listProducts(inventory, count);
                break;
            case 2:
                printf("Введіть ID продукту: ");
                scanf("%d", &productId);
                printf("Введіть кількість: ");
                scanf("%d", &quantity);

                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == productId) {
                        addToCart(&inventory[i], quantity, cart, &cartSize);
                        found = 1;
                        break;
                    }
                }
                
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == productId) {
                        addSumCart(&inventory[i], quantity, &total);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Продукт з ID %d не знайдено\n", productId);
                }
                break;
            case 3:
                displayCart(cart, cartSize);
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
    }
        else if (strcmp(menuChoice, "покинути") != 0) {
            printf("Невірна відповідь. Спробуйте ще раз.\n");
        }
    } while (strcmp(menuChoice, "покинути") != 0);


    return 0;
}
