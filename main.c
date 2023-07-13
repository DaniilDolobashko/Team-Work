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

void removeFromCart(int productId, CartItem* cart, int* cartSize, float* total) {
    int found = 0;
    for (int i = 0; i < *cartSize; i++) {
        if (cart[i].product.id == productId) {
            *total -= cart[i].product.price * cart[i].quantity;
            for (int j = i; j < (*cartSize - 1); j++) {
                cart[j] = cart[j + 1];
            }
            (*cartSize)--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Товар видалено з корзини.\n");
    } else {
        printf("Продукт з ID %d не знайдено в корзині.\n", productId);
    }
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
int totalPlusDelivery = 0;
int choice, choiceOfCategory, deliveryChoice, deliveryTime, department, payChoice, cardCVV, cardNumber, cardDate;
float total = 0.0;
char surname[20], name[20], middleName[20], sex[10], mail[100], deliveryAdress[100];

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
            printf("3. Видалити товар з корзини\n");
            printf("4. Перейти до оформлення замовлення\n"); 
            printf("5. Вийти з меню\n");
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
printf("Введіть ID товару, який потрібно видалити з корзини: ");
scanf("%d", &productId);
removeFromCart(productId, cart, &cartSize, &total);
break;
case 4:
printf("\nОФОРМЛЕННЯ ЗАМОВЛЕННЯ\n\n");
printf("Оберіть метод доставки:\n");
printf("1 - Самовивіз з магазину (Київ) - безкоштовно\n");
printf("2 - Доставка кур'єром - 100 грн\n");
printf("3 - Доставка Новою Поштою - 80 грн\n");
printf("4 - Доставка Укрпоштою - 50 грн\n");
scanf("%d", &deliveryChoice);
switch (deliveryChoice) {
                case 1:
                    printf("Наш магазин знаходиться в Києві за адресою: Сагайдачного вул., 51.\n");
                    printf("Графік роботи: Пн-Пт - 10:00-18:00\n");
                    printf("Ви можете забрати ваш товар починаючи з наступного робочого дня!\n");
                    
                    
                    printf("\nДо сплати: %d\n", total);
                    printf("Оберіть метод оплати:\n");
printf("1 - Оплата при отриманні\n");
printf("2 - Оплатити онлайн\n");
scanf("%d", &payChoice);
                    switch (payChoice) {
    case 1:
        printf("Добре, очікуємо вас в нашому магазині!\n");
        break;
    case 2:
        printf("Будь ласка, введіть дані вашої картки.\n");
        printf("Номер:\n");
        scanf("%d", &cardNumber);
        printf("Термін дії (впишіть у наступному форматі: XXXX):\n");
        scanf("%d", &cardDate);
        printf("CVV:\n");
        scanf("%d", &cardCVV);
        printf("Оплачено! Чекаємо на Вас у нашому магазині!\n");
        break;
    default:
        printf("Невірне значення. \n");
        break;
}                  
break;
                case 2:
                    printf("Ведіть адресу доставки:\n");
                    scanf("%s", &deliveryAdress);
                    printf("О котрій годині завтра вам буде зручно отримати замовлення?\n");
                    scanf("%d", &deliveryTime);
                    printf("Очійкуйте нашого кур'єра завтра близько %d години\n", deliveryTime);

                    totalPlusDelivery = total+100;
                    printf("\nДо сплати: %d\n", totalPlusDelivery);
                    printf("Оберіть метод оплати:\n");
printf("1 - Оплата при отриманні\n");
printf("2 - Оплатити онлайн\n");
scanf("%d", &payChoice);
                    switch (payChoice) {
    case 1:
        printf("Добре, очікуйте на нашого кур'єра!\n");
        break;
    case 2:
        printf("Будь ласка, введіть дані вашої картки.\n");
        printf("Номер:\n");
        scanf("%d", &cardNumber);
        printf("Термін дії:\n");
        scanf("%d", &cardDate);
        printf("CVV:\n");
        scanf("%d", &cardCVV);
        printf("Оплачено! Очікуйте на нашого кур'єра!\n");
        break;
    default:
        printf("Невірне значення. \n");
        break;
}           
break;

                    
    case 3:
        printf("Введіть номер відділення:\n");
        scanf("%d", &department);
        printf("Очікуйте ваше замовлення в %d відділенні!\n", department);
        
         totalPlusDelivery = total+80;
                    printf("\nДо сплати: %d\n", totalPlusDelivery);
                    printf("Оберіть метод оплати:\n");
printf("1 - Оплата при отриманні\n");
printf("2 - Оплатити онлайн\n");
scanf("%d", &payChoice);
                    switch (payChoice) {
    case 1:
        printf("Добре, очікуйте на доставку!\n");
        break;
    case 2:
        printf("Будь ласка, введіть дані вашої картки.\n");
        printf("Номер:\n");
        scanf("%d", &cardNumber);
        printf("Термін дії:\n");
        scanf("%d", &cardDate);
        printf("CVV:\n");
        scanf("%d", &cardCVV);
        printf("Оплачено! Очікуйте на доставку!\n");
        break;
    default:
        printf("Невірне значення. \n");
        break;
}     
break;


    case 4:
        printf("Введіть номер відділення:\n");
        scanf("%d", &department);
        printf("Очікуйте ваше замовлення в %d відділенні!\n", department);

        totalPlusDelivery = total+50;
                    printf("\nДо сплати: %d\n", totalPlusDelivery);
                    printf("Оберіть метод оплати:\n");
printf("1 - Оплата при отриманні\n");
printf("2 - Оплатити онлайн\n");
scanf("%d", &payChoice);
                    switch (payChoice) {
    case 1:
        printf("Добре, очікуйте на доставку!\n");
        break;
    case 2:
        printf("Будь ласка, введіть дані вашої картки.\n");
        printf("Номер:\n");
        scanf("%d", &cardNumber);
        printf("Термін дії:\n");
        scanf("%d", &cardDate);
        printf("CVV:\n");
        scanf("%d", &cardCVV);
        printf("Оплачено! Очікуйте на доставку!\n");
        break;
    default:
        printf("Невірне значення. \n");
        break;
}     
break;

    default:
        printf("Невірне значення.\n");
        break;
}
                
                
break;
case 5:
printf("Ви вийшли з меню\n");
break;
default:
printf("Невірний вибір. Спробуйте ще раз.\n");
break;
}
} while (choice != 5);
} else if (strcmp(menuChoice, "покинути") != 0) {
printf("Невірна відповідь. Спробуйте ще раз.\n");
}
} while (strcmp(menuChoice, "покинути") != 0);
printf("Дякую за використання магазину!\n");
    return 0;
}
