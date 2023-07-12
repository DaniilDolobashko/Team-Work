#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    char brand[20];
    char compatibility[100];
    char connector[20];
    float price, memory, leigth, speed;
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

void listOfPhones(Product* inventoryOfPhones, int countPhones) {
    printf("Список продуктів:\n");
    for (int i = 0; i < countPhones; i++) {
        printf("ID: %d, Назва: %s %s, Пам'ять: %.0f GB, Ціна: %.2f грн\n", inventoryOfPhones[i].id, inventoryOfPhones[i].brand, inventoryOfPhones[i].name, inventoryOfPhones[i].memory, inventoryOfPhones[i].price);
    }
}

void listOfChargers(Product* inventoryOfChargers, int countChargers) {
    printf("Список продуктів:\n");
    for (int i = 0; i < countChargers; i++) {
        printf("ID: %d, Назва: %s %s, Довжина: %.0f m, Роз'єм: %s, Ціна: %.2f грн\n", inventoryOfChargers[i].id, inventoryOfChargers[i].brand, inventoryOfChargers[i].name, inventoryOfChargers[i].leigth, inventoryOfChargers[i].connector, inventoryOfChargers[i].price);
    }
}

void listOfCase(Product* inventoryOfCase, int countCase) {
    printf("Список продуктів:\n");
    for (int i = 0; i < countCase; i++) {
        printf("ID: %d, Назва: %s %s, Сумісний з %s, Ціна: %.2f грн\n", inventoryOfCase[i].id, inventoryOfCase[i].brand, inventoryOfCase[i].name, inventoryOfCase[i].compatibility, inventoryOfCase[i].price);
    }
}

void listOfPowerBank(Product* inventoryOfPowerBank, int countPowerBank) {
    printf("Список продуктів:\n");
    for (int i = 0; i < countPowerBank; i++) {
        printf("ID: %d, Назва: %s %s, Швидкість: %.0f W, Ціна: %.2f грн\n", inventoryOfPowerBank[i].id, inventoryOfPowerBank[i].brand, inventoryOfPowerBank[i].name, inventoryOfPowerBank[0].speed, inventoryOfPowerBank[i].price);
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int productId, quantity;

    Product inventoryOfPhones[5];
    int countPhones = 5;

    inventoryOfPhones[0].id = 1;
    strcpy(inventoryOfPhones[0].brand, "Xiaomi");
    strcpy(inventoryOfPhones[0].name, "Телефон 1");
    inventoryOfPhones[0].memory = 128;
    inventoryOfPhones[0].price = 100.0;


    inventoryOfPhones[1].id = 2;
    strcpy(inventoryOfPhones[1].brand, "Samsung");
    strcpy(inventoryOfPhones[1].name, "Телефон 2");
    inventoryOfPhones[1].memory = 128;
    inventoryOfPhones[1].price = 200.0;

    inventoryOfPhones[2].id = 3;
    strcpy(inventoryOfPhones[2].brand, "Xiaomi");
    strcpy(inventoryOfPhones[2].name, "Телефон 3");
    inventoryOfPhones[2].memory = 64;
    inventoryOfPhones[2].price = 150.0;

    inventoryOfPhones[3].id = 4;
    strcpy(inventoryOfPhones[3].brand, "Apple");
    strcpy(inventoryOfPhones[3].name, "Телефон 4");
    inventoryOfPhones[3].memory = 256;
    inventoryOfPhones[3].price = 400.0;

    inventoryOfPhones[4].id = 5;
    strcpy(inventoryOfPhones[4].brand, "Xiaomi");
    strcpy(inventoryOfPhones[4].name, "Телефон 5");
    inventoryOfPhones[4].memory = 128;
    inventoryOfPhones[4].price = 250.0;


    Product inventoryOfChargers[1];
    int countChargers = 1;

    inventoryOfChargers[0].id = 6;
    strcpy(inventoryOfChargers[0].brand, "Xiaomi");
    strcpy(inventoryOfChargers[0].name, "Швидкий шнур");
    strcpy(inventoryOfChargers[0].connector, "Type C");
    inventoryOfChargers[0].leigth = 1;
    inventoryOfChargers[0].price = 50.0;
    
    
    Product inventoryOfCase[1];
    int countCase = 1;

    inventoryOfCase[0].id = 7;
    strcpy(inventoryOfCase[0].brand, "Xiaomi");
    strcpy(inventoryOfCase[0].name, "Super Case");
    strcpy(inventoryOfCase[0].compatibility, "Телефон 2"); 
    inventoryOfCase[0].price = 20.0;
    
    
    Product inventoryOfPowerBank[1];
    int countPowerBank = 1;

    inventoryOfPowerBank[0].id = 8;
    strcpy(inventoryOfPowerBank[0].brand, "Xiaomi");
    strcpy(inventoryOfPowerBank[0].name, "Супер фаст чардж");
    inventoryOfPowerBank[0].speed = 18;
    inventoryOfPowerBank[0].price = 80.0;
    
    
    
    CartItem cart[10];
    int cartSize = 0; 
    int choice, choiceOfCategory;
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
    printf("Стать: ");
    scanf("%s", &sex);
    printf("E-mail: ");
    scanf("%s", &mail);
    printf("\n%s, вітаємо Вас з успішною реєстрацією!\n", name);
    
    char menuChoice[15];

    do {
        printf("Якщо ви бажаєте продовжити використання магазину, впишіть \"продовжити\", щоб покинути напишіть \"покинути\": \n");
        scanf("%s", menuChoice);

        if (strcmp(menuChoice, "продовжити") == 0) {
            do {
                printf("Меню:\n");
                printf("1. Перейти до покупок\n");
                printf("2. Переглянути вміст корзини\n");
                printf("3. Вийти з меню\n");
                printf("Ваш вибір: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        do {
                            printf("Оберіть категорію товару, що вас цікавить\n");
                            printf("1. Смартфони\n");
                            printf("2. Зарядні пристрої\n");
                            printf("3. Чохли\n");
                            printf("4. Павербанки\n");
                            printf("5. Додати товар до корзини\n");
                            printf("6. Повернутись назад\n");
                            printf("Ваш вибір: ");
                            scanf("%d", &choiceOfCategory);

                            switch (choiceOfCategory) {
                                case 1:
                                    listOfPhones(inventoryOfPhones, countPhones);
                                    break;
                                case 2:
                                    listOfChargers(inventoryOfChargers, countChargers);
                                    break;
                                case 3:
                                    listOfCase(inventoryOfCase, countCase);
                                    break;
                                case 4:
                                    listOfPowerBank(inventoryOfPowerBank, countPowerBank);
                                    break;
                                case 5:
                        printf("Введіть ID продукту: ");
                        scanf("%d", &productId);
                        printf("Введіть кількість: ");
                        scanf("%d", &quantity);

                        int found = 0;
                        for (int i = 0; i < countPhones; i++) {
                            if (inventoryOfPhones[i].id == productId) {
                                addToCart(&inventoryOfPhones[i], quantity, cart, &cartSize);
                                addSumCart(&inventoryOfPhones[i], quantity, &total);
                                found = 1;
                                break;
                            }
                        }
                        for (int i = 0; i < countChargers; i++) {
                            if (inventoryOfChargers[i].id == productId) {
                                addToCart(&inventoryOfChargers[i], quantity, cart, &cartSize);
                                addSumCart(&inventoryOfChargers[i], quantity, &total);
                                found = 1;
                                break;
                            }
                        }
                        for (int i = 0; i < countCase; i++) {
                            if (inventoryOfCase[i].id == productId) {
                                addToCart(&inventoryOfCase[i], quantity, cart, &cartSize);
                                addSumCart(&inventoryOfCase[i], quantity, &total);
                                found = 1;
                                break;
                            }
                        }
                        for (int i = 0; i < countPowerBank; i++) {
                            if (inventoryOfPowerBank[i].id == productId) {
                                addToCart(&inventoryOfPowerBank[i], quantity, cart, &cartSize);
                                addSumCart(&inventoryOfPowerBank[i], quantity, &total);
                                found = 1;
                                break;
                            }
                        }


                        if (!found) {
                            printf("Продукт з ID %d не знайдено\n", productId);
                        }
                        break;
                                case 6:
                                    printf("Ви повернулись до головного меню\n");
                                    break;
                                default:
                                    printf("Невірний вибір категорії. Спробуйте ще раз.\n");
                                    break;
                            }
                        } while (choiceOfCategory != 5);
                        break;
                    case 2:
                        displayCart(cart, cartSize);
                        printf("Загальна вартість корзини: %.2f\n", total);
                        break;
                    case 3:
                        printf("Ви вийшли з меню\n");
                        break;
                    default:
                        printf("Невірний вибір. Спробуйте ще раз.\n");
                        break;
                }
            } while (choice != 3);
        } else if (strcmp(menuChoice, "покинути") != 0) {
            printf("Невірна відповідь. Спробуйте ще раз.\n");
        }
    } while (strcmp(menuChoice, "покинути") != 0);
    printf("Дякую за використання магазину!\n");
    
    return 0;
}
