#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void filterForPhonesByBrand(Product inventoryOfPhones[], int numPhones) {
    char brandFilter[20];
    printf("\nВведіть назву бренду: ");
    scanf("%s", brandFilter);

    printf("\nРезультати після фільтрації за брендом %s:\n", brandFilter);

    bool foundProducts = false;

    for (int i = 0; i < numPhones; i++) {
        if (strcmp(inventoryOfPhones[i].brand, brandFilter) == 0) {
            foundProducts = true;
            printf("\nID: %d, Назва: %s %s, Пам'ять: %.0f GB, Ціна: %.2f грн\n",
                   inventoryOfPhones[i].id,
                   inventoryOfPhones[i].brand,
                   inventoryOfPhones[i].name,
                   inventoryOfPhones[i].memory,
                   inventoryOfPhones[i].price);
        }
    }

    if (!foundProducts) {
        printf("\nТоварів бренду за фільтром %s не знайдено.\n", brandFilter);
    }
}

void filterForPhonesByMemory(Product inventoryOfPhones[], int numPhones) {
    float minMemory, maxMemory;
    printf("\nВведіть мінімальний обсяг пам'яті: ");
    scanf("%f", &minMemory);
    printf("Введіть максимальний обсяг пам'яті: ");
    scanf("%f", &maxMemory);

    printf("\nРезультати після фільтрації за обсягом пам'яті %.0f GB - %.0f GB:\n", minMemory, maxMemory);

    
    bool foundProducts = false;

    for (int i = 0; i < numPhones; i++) {
        if (inventoryOfPhones[i].memory >= minMemory && inventoryOfPhones[i].memory <= maxMemory) {
            foundProducts = true; 
            printf("\nID: %d, Назва: %s %s, Пам'ять: %.0f GB, Ціна: %.2f грн\n",
                   inventoryOfPhones[i].id,
                   inventoryOfPhones[i].brand,
                   inventoryOfPhones[i].name,
                   inventoryOfPhones[i].memory,
                   inventoryOfPhones[i].price);
        }
    }

    
    if (!foundProducts) {
        printf("Товарів у заданому діапазоні пам'яті не знайдено.\n");
    }
}

void filterForPhonesByPrice(Product inventoryOfPhones[], int numPhones) {
    float minPriceFilter, maxPriceFilter;
    printf("\nВведіть мінімальну ціну: ");
    scanf("%f", &minPriceFilter);
    printf("Введіть максимальну ціну: ");
    scanf("%f", &maxPriceFilter);

    printf("\nРезультати після фільтрації за ціною %.2f грн - %.2f грн:\n", minPriceFilter, maxPriceFilter);

    bool foundProducts = false;

    for (int i = 0; i < numPhones; i++) {
        if (inventoryOfPhones[i].price >= minPriceFilter && inventoryOfPhones[i].price <= maxPriceFilter) {
            foundProducts = true;
            printf("\nID: %d, Назва: %s %s, Пам'ять: %.0f GB, Ціна: %.2f грн\n",
                inventoryOfPhones[i].id, inventoryOfPhones[i].brand, inventoryOfPhones[i].name,
                inventoryOfPhones[i].memory, inventoryOfPhones[i].price);
        }
    }

    if (!foundProducts) {
        printf("\nТоварів за фільтром ціни %.2f грн - %.2f грн не знайдено.\n", minPriceFilter, maxPriceFilter);
    }
}


int main() {

    int productId, quantity;

    Product inventoryOfPhones[30];
    int countPhones = 30;

    inventoryOfPhones[0].id = 1;
    strcpy(inventoryOfPhones[0].brand, "Apple");
    strcpy(inventoryOfPhones[0].name, "Iphone 14");
    inventoryOfPhones[0].memory = 128;
    inventoryOfPhones[0].price = 33499;


    inventoryOfPhones[1].id = 2;
    strcpy(inventoryOfPhones[1].brand, "Apple");
    strcpy(inventoryOfPhones[1].name, "Iphone 14 Pro");
    inventoryOfPhones[1].memory = 128;
    inventoryOfPhones[1].price = 49999;

    inventoryOfPhones[2].id = 3;
    strcpy(inventoryOfPhones[2].brand, "Apple");
    strcpy(inventoryOfPhones[2].name, "Iphone 14 Pro Max");
    inventoryOfPhones[2].memory = 128;
    inventoryOfPhones[2].price = 54999;

    inventoryOfPhones[3].id = 4;
    strcpy(inventoryOfPhones[3].brand, "Apple");
    strcpy(inventoryOfPhones[3].name, "Iphone 14 Plus");
    inventoryOfPhones[3].memory = 128;
    inventoryOfPhones[3].price = 43999;

    inventoryOfPhones[4].id = 5;
    strcpy(inventoryOfPhones[4].brand, "Apple");
    strcpy(inventoryOfPhones[4].name, "Iphone 13");
    inventoryOfPhones[4].memory = 128;
    inventoryOfPhones[4].price = 33499;

    inventoryOfPhones[5].id = 6;
    strcpy(inventoryOfPhones[5].brand, "Apple");
    strcpy(inventoryOfPhones[5].name, "Iphone 11");
    inventoryOfPhones[5].memory = 64;
    inventoryOfPhones[5].price = 20499;

    inventoryOfPhones[6].id = 7;
    strcpy(inventoryOfPhones[6].brand, "Xiaomi");
    strcpy(inventoryOfPhones[6].name, "Redmi Note 12 Pro 4G");
    inventoryOfPhones[6].memory = 256;
    inventoryOfPhones[6].price = 11999;

    inventoryOfPhones[7].id = 8;
    strcpy(inventoryOfPhones[7].brand, "Xiaomi");
    strcpy(inventoryOfPhones[7].name, "12 Lite");
    inventoryOfPhones[7].memory = 128;
    inventoryOfPhones[7].price = 13499;

    inventoryOfPhones[8].id = 9;
    strcpy(inventoryOfPhones[8].brand, "Xiaomi");
    strcpy(inventoryOfPhones[8].name, "Redmi 12C");
    inventoryOfPhones[8].memory = 128;
    inventoryOfPhones[8].price = 5599;

    inventoryOfPhones[9].id = 10;
    strcpy(inventoryOfPhones[9].brand, "Xiaomi");
    strcpy(inventoryOfPhones[9].name, "Redmi A2");
    inventoryOfPhones[9].memory = 32;
    inventoryOfPhones[9].price = 3499;

    inventoryOfPhones[10].id = 11;
    strcpy(inventoryOfPhones[10].brand, "Xiaomi");
    strcpy(inventoryOfPhones[10].name, "13 Lite");
    inventoryOfPhones[10].memory = 256;
    inventoryOfPhones[10].price = 17999;

    inventoryOfPhones[11].id = 12;
    strcpy(inventoryOfPhones[11].brand, "Xiaomi");
    strcpy(inventoryOfPhones[11].name, "Redmi 10");
    inventoryOfPhones[11].memory = 128;
    inventoryOfPhones[11].price = 5599;

    inventoryOfPhones[12].id = 13;
    strcpy(inventoryOfPhones[12].brand, "Samsung");
    strcpy(inventoryOfPhones[12].name, "Galaxy A24");
    inventoryOfPhones[12].memory = 128;
    inventoryOfPhones[12].price = 8999;

    inventoryOfPhones[13].id = 14;
    strcpy(inventoryOfPhones[13].brand, "Samsung");
    strcpy(inventoryOfPhones[13].name, "Galaxy S23");
    inventoryOfPhones[13].memory = 128;
    inventoryOfPhones[13].price = 33999;

    inventoryOfPhones[14].id = 15;
    strcpy(inventoryOfPhones[14].brand, "Samsung");
    strcpy(inventoryOfPhones[14].name, "Galaxy A54");
    inventoryOfPhones[14].memory = 128;
    inventoryOfPhones[14].price = 17699;

    inventoryOfPhones[15].id = 16;
    strcpy(inventoryOfPhones[15].brand, "Samsung");
    strcpy(inventoryOfPhones[15].name, "Galaxy Fold 4");
    inventoryOfPhones[15].memory = 512;
    inventoryOfPhones[15].price = 58499;

    inventoryOfPhones[16].id = 17;
    strcpy(inventoryOfPhones[16].brand, "Samsung");
    strcpy(inventoryOfPhones[16].name, "Galaxy S23 Ultra");
    inventoryOfPhones[16].memory = 256;
    inventoryOfPhones[16].price = 50999;

    inventoryOfPhones[17].id = 18;
    strcpy(inventoryOfPhones[17].brand, "Samsung");
    strcpy(inventoryOfPhones[17].name, "Galaxy M14");
    inventoryOfPhones[17].memory = 128;
    inventoryOfPhones[17].price = 8499;

    inventoryOfPhones[18].id = 19;
    strcpy(inventoryOfPhones[18].brand, "Realme");
    strcpy(inventoryOfPhones[18].name, "10");
    inventoryOfPhones[18].memory = 128;
    inventoryOfPhones[18].price = 9499;

    inventoryOfPhones[19].id = 20;
    strcpy(inventoryOfPhones[19].brand, "Realme");
    strcpy(inventoryOfPhones[19].name, "C55");
    inventoryOfPhones[19].memory = 256;
    inventoryOfPhones[19].price = 8299;

    inventoryOfPhones[20].id = 21;
    strcpy(inventoryOfPhones[20].brand, "Realme");
    strcpy(inventoryOfPhones[20].name, "10 Pro Plus 5G");
    inventoryOfPhones[20].memory = 256;
    inventoryOfPhones[20].price = 16999;

    inventoryOfPhones[21].id = 22;
    strcpy(inventoryOfPhones[21].brand, "Realme");
    strcpy(inventoryOfPhones[21].name, "9i");
    inventoryOfPhones[21].memory = 64;
    inventoryOfPhones[21].price = 5499;

    inventoryOfPhones[22].id = 23;
    strcpy(inventoryOfPhones[22].brand, "Realme");
    strcpy(inventoryOfPhones[22].name, "C30s");
    inventoryOfPhones[22].memory = 64;
    inventoryOfPhones[22].price = 3999;

    inventoryOfPhones[23].id = 24;
    strcpy(inventoryOfPhones[23].brand, "Realme");
    strcpy(inventoryOfPhones[23].name, "GT Neo 5 SE 5G");
    inventoryOfPhones[23].memory = 512;
    inventoryOfPhones[23].price = 19499;

    inventoryOfPhones[24].id = 25;
    strcpy(inventoryOfPhones[24].brand, "Oppo");
    strcpy(inventoryOfPhones[24].name, "A96");
    inventoryOfPhones[24].memory = 128;
    inventoryOfPhones[24].price = 9299;

    inventoryOfPhones[25].id = 26;
    strcpy(inventoryOfPhones[25].brand, "Oppo");
    strcpy(inventoryOfPhones[25].name, "A17");
    inventoryOfPhones[25].memory = 64;
    inventoryOfPhones[25].price = 5299;

    inventoryOfPhones[26].id = 27;
    strcpy(inventoryOfPhones[26].brand, "Oppo");
    strcpy(inventoryOfPhones[26].name, "A54s");
    inventoryOfPhones[26].memory = 128;
    inventoryOfPhones[26].price = 7299;

    inventoryOfPhones[27].id = 28;
    strcpy(inventoryOfPhones[27].brand, "Oppo");
    strcpy(inventoryOfPhones[27].name, "Reno8 T");
    inventoryOfPhones[27].memory = 128;
    inventoryOfPhones[27].price = 13999;

    inventoryOfPhones[28].id = 29;
    strcpy(inventoryOfPhones[28].brand, "Oppo");
    strcpy(inventoryOfPhones[28].name, "A98");
    inventoryOfPhones[28].memory = 256;
    inventoryOfPhones[28].price = 15799;

    inventoryOfPhones[29].id = 30;
    strcpy(inventoryOfPhones[29].brand, "Oppo");
    strcpy(inventoryOfPhones[29].name, "A74");
    inventoryOfPhones[29].memory = 128;
    inventoryOfPhones[29].price = 13499;


 
Product inventoryOfChargers[10];
int countChargers = 10;

inventoryOfChargers[0].id = 31;
strcpy(inventoryOfChargers[0].brand, "Duracell");
strcpy(inventoryOfChargers[0].name, "Швидкий шнур");
strcpy(inventoryOfChargers[0].connector, "USB-C");
inventoryOfChargers[0].leigth = 1;
inventoryOfChargers[0].price = 599;

inventoryOfChargers[1].id = 32;
strcpy(inventoryOfChargers[1].brand, "Baseus");
strcpy(inventoryOfChargers[1].name, "Cafule Cable");
strcpy(inventoryOfChargers[1].connector, "Type-C 3A");
inventoryOfChargers[1].leigth = 1;
inventoryOfChargers[1].price = 189;

inventoryOfChargers[2].id = 33;
strcpy(inventoryOfChargers[2].brand, "Baseus");
strcpy(inventoryOfChargers[2].name, "Cafule Cable");
strcpy(inventoryOfChargers[2].connector, "Lightning");
inventoryOfChargers[2].leigth = 1.5;
inventoryOfChargers[2].price = 219;

inventoryOfChargers[3].id = 34;
strcpy(inventoryOfChargers[3].brand, "Grand-X");
strcpy(inventoryOfChargers[3].name, "Cable");
strcpy(inventoryOfChargers[3].connector, "Type-C 3A");
inventoryOfChargers[3].leigth = 1;
inventoryOfChargers[3].price = 99;

inventoryOfChargers[4].id = 35;
strcpy(inventoryOfChargers[4].brand, "Baseus");
strcpy(inventoryOfChargers[4].name, "Cafuke Cable Type-C 3A");
strcpy(inventoryOfChargers[4].connector, "Type-C 3A");
inventoryOfChargers[4].leigth = 2;
inventoryOfChargers[4].price = 230;

inventoryOfChargers[5].id = 36;
strcpy(inventoryOfChargers[5].brand, "Apple");
strcpy(inventoryOfChargers[5].name, "Cable USB");
strcpy(inventoryOfChargers[5].connector, "Lightning");
inventoryOfChargers[5].leigth = 1;
inventoryOfChargers[5].price = 999;

inventoryOfChargers[6].id = 37;
strcpy(inventoryOfChargers[6].brand, "Apple");
strcpy(inventoryOfChargers[6].name, "Cable USB-C");
strcpy(inventoryOfChargers[6].connector, "Lightning");
inventoryOfChargers[6].leigth = 1;
inventoryOfChargers[6].price = 999;

inventoryOfChargers[7].id = 38;
strcpy(inventoryOfChargers[7].brand, "Apple");
strcpy(inventoryOfChargers[7].name, "Cable USB-C");
strcpy(inventoryOfChargers[7].connector, "USB-C");
inventoryOfChargers[7].leigth = 2;
inventoryOfChargers[7].price = 999;

inventoryOfChargers[8].id = 39;
strcpy(inventoryOfChargers[8].brand, "ArmorStandart");
strcpy(inventoryOfChargers[8].name, "AR88");
strcpy(inventoryOfChargers[8].connector, "Type-C 2.4 A");
inventoryOfChargers[8].leigth = 1;
inventoryOfChargers[8].price = 179;

inventoryOfChargers[9].id = 40;
strcpy(inventoryOfChargers[9].brand, "Intaleo");
strcpy(inventoryOfChargers[9].name, "CBFLEXL1");
strcpy(inventoryOfChargers[9].connector, "Lightning");
inventoryOfChargers[9].leigth = 1.2;
inventoryOfChargers[9].price = 179;

Product inventoryOfCase[30];
int countCase = 30;

inventoryOfCase[0].id = 41;
strcpy(inventoryOfCase[0].brand, "Apple");
strcpy(inventoryOfCase[0].name, "MagSafe Silicone Case");
strcpy(inventoryOfCase[0].compatibility, "Iphone 14"); 
inventoryOfCase[0].price = 2799;

inventoryOfCase[1].id = 42;
strcpy(inventoryOfCase[1].brand, "Apple");
strcpy(inventoryOfCase[1].name, "MagSafe Silicone Case");
strcpy(inventoryOfCase[1].compatibility, "Iphone 14 Pro"); 
inventoryOfCase[1].price = 2799;

inventoryOfCase[2].id = 43;
strcpy(inventoryOfCase[2].brand, "Apple");
strcpy(inventoryOfCase[2].name, "MagSafe Silicone Case");
strcpy(inventoryOfCase[2].compatibility, "Iphone 14 Pro Max"); 
inventoryOfCase[2].price = 3099;

inventoryOfCase[3].id = 44;
strcpy(inventoryOfCase[3].brand, "Apple");
strcpy(inventoryOfCase[3].name, "MagSafe Clear Case");
strcpy(inventoryOfCase[3].compatibility, "Iphone 14 Plus"); 
inventoryOfCase[3].price = 2799;

inventoryOfCase[4].id = 45;
strcpy(inventoryOfCase[4].brand, "Apple");
strcpy(inventoryOfCase[4].name, "MagSafe Clear Case");
strcpy(inventoryOfCase[4].compatibility, "Iphone 13"); 
inventoryOfCase[4].price = 2499;

inventoryOfCase[5].id = 46;
strcpy(inventoryOfCase[5].brand, "ArmorStandart");
strcpy(inventoryOfCase[5].name, "Icon2 Case");
strcpy(inventoryOfCase[5].compatibility, "Iphone 11"); 
inventoryOfCase[5].price = 499;

inventoryOfCase[6].id = 47;
strcpy(inventoryOfCase[6].brand, "ArmorStandart");
strcpy(inventoryOfCase[6].name, "Air Force");
strcpy(inventoryOfCase[6].compatibility, "Xiaomi Redmi Note 12 Pro 4G"); 
inventoryOfCase[6].price = 167;

inventoryOfCase[7].id = 48;
strcpy(inventoryOfCase[7].brand, "BeCover");
strcpy(inventoryOfCase[7].name, "Anti-Shock");
strcpy(inventoryOfCase[7].compatibility, "Xiaomi 12 Lite"); 
inventoryOfCase[7].price = 149;

inventoryOfCase[8].id = 49;
strcpy(inventoryOfCase[8].brand, "ArmorStandart");
strcpy(inventoryOfCase[8].name, "G-Case");
strcpy(inventoryOfCase[8].compatibility, "Xiaomi Redmi 12C"); 
inventoryOfCase[8].price = 269;

inventoryOfCase[9].id = 50;
strcpy(inventoryOfCase[9].brand, "BeCover");
strcpy(inventoryOfCase[9].name, "Sniver Case");
strcpy(inventoryOfCase[9].compatibility, "Xiaomi Redmi A2"); 
inventoryOfCase[9].price = 249;

inventoryOfCase[10].id = 51;
strcpy(inventoryOfCase[10].brand, "BeCover");
strcpy(inventoryOfCase[10].name, "Case");
strcpy(inventoryOfCase[10].compatibility, "Xiaomi 13 Lite"); 
inventoryOfCase[10].price = 149;

inventoryOfCase[11].id = 52;
strcpy(inventoryOfCase[11].brand, "ArmorStandart");
strcpy(inventoryOfCase[11].name, "G-Case");
strcpy(inventoryOfCase[11].compatibility, "Xiaomi Redmi 10"); 
inventoryOfCase[11].price = 269;

inventoryOfCase[12].id = 53;
strcpy(inventoryOfCase[12].brand, "ArmorStandart");
strcpy(inventoryOfCase[12].name, "Icon Case");
strcpy(inventoryOfCase[12].compatibility, "Samsung Galaxy A24"); 
inventoryOfCase[12].price = 349;

inventoryOfCase[13].id = 54;
strcpy(inventoryOfCase[13].brand, "Rugget");
strcpy(inventoryOfCase[13].name, "Gadget Cover");
strcpy(inventoryOfCase[13].compatibility, "Samsung Galaxy S23"); 
inventoryOfCase[13].price = 2599;

inventoryOfCase[14].id = 55;
strcpy(inventoryOfCase[14].brand, "ArmorStandart");
strcpy(inventoryOfCase[14].name, "Icon Case");
strcpy(inventoryOfCase[14].compatibility, "Samsung Galaxy A54"); 
inventoryOfCase[14].price = 349;

inventoryOfCase[15].id = 56;
strcpy(inventoryOfCase[15].brand, "Clear");
strcpy(inventoryOfCase[15].name, "Edge Cover");
strcpy(inventoryOfCase[15].compatibility, "Samsung Galaxy Fold 4"); 
inventoryOfCase[15].price = 1849;

inventoryOfCase[16].id = 57;
strcpy(inventoryOfCase[16].brand, "Samsung");
strcpy(inventoryOfCase[16].name, "Leather Cover");
strcpy(inventoryOfCase[16].compatibility, "Samsung Galaxy S23 Ultra"); 
inventoryOfCase[16].price = 2599;

inventoryOfCase[17].id = 58;
strcpy(inventoryOfCase[17].brand, "ArmorStandart");
strcpy(inventoryOfCase[17].name, "Icon Case");
strcpy(inventoryOfCase[17].compatibility, "Samsung Galaxy M14"); 
inventoryOfCase[17].price = 349;

inventoryOfCase[18].id = 59;
strcpy(inventoryOfCase[18].brand, "Dux Ducis");
strcpy(inventoryOfCase[18].name, "Skin Pro");
strcpy(inventoryOfCase[18].compatibility, "Realme 10"); 
inventoryOfCase[18].price = 329;

inventoryOfCase[19].id = 60;
strcpy(inventoryOfCase[19].brand, "UniCase");
strcpy(inventoryOfCase[19].name, "Carbon");
strcpy(inventoryOfCase[19].compatibility, "Realme C55"); 
inventoryOfCase[19].price = 199;

inventoryOfCase[20].id = 61;
strcpy(inventoryOfCase[20].brand, "Deexe");
strcpy(inventoryOfCase[20].name, "Leather Cover");
strcpy(inventoryOfCase[20].compatibility, "Realme 10 Pro Plus 5G"); 
inventoryOfCase[20].price = 219;

inventoryOfCase[21].id = 62;
strcpy(inventoryOfCase[21].brand, "Nillkin");
strcpy(inventoryOfCase[21].name, "Frosted Shield");
strcpy(inventoryOfCase[21].compatibility, "Realme 9i"); 
inventoryOfCase[21].price = 319;

inventoryOfCase[22].id = 63;
strcpy(inventoryOfCase[22].brand, "ArmorStandart");
strcpy(inventoryOfCase[22].name, "G-Case");
strcpy(inventoryOfCase[22].compatibility, "Realme C30s"); 
inventoryOfCase[22].price = 269;

inventoryOfCase[23].id = 64;
strcpy(inventoryOfCase[23].brand, "ArmorStandart");
strcpy(inventoryOfCase[23].name, "Icon Case");
strcpy(inventoryOfCase[23].compatibility, "Realme GT Neo 5 SE 5G"); 
inventoryOfCase[23].price = 349;

inventoryOfCase[24].id = 65;
strcpy(inventoryOfCase[24].brand, "ColorWay");
strcpy(inventoryOfCase[24].name, "TPU AntiShock");
strcpy(inventoryOfCase[24].compatibility, "Oppo A96"); 
inventoryOfCase[24].price = 129;

inventoryOfCase[25].id = 66;
strcpy(inventoryOfCase[25].brand, "ArmorStandart");
strcpy(inventoryOfCase[25].name, "Matte Slim Fit");
strcpy(inventoryOfCase[25].compatibility, "Oppo A17"); 
inventoryOfCase[25].price = 199;

inventoryOfCase[26].id = 67;
strcpy(inventoryOfCase[26].brand, "BeCover");
strcpy(inventoryOfCase[26].name, "Anti-Shock");
strcpy(inventoryOfCase[26].compatibility, "Oppo A54s"); 
inventoryOfCase[26].price = 149;

inventoryOfCase[27].id = 68;
strcpy(inventoryOfCase[27].brand, "ArmorStandart");
strcpy(inventoryOfCase[27].name, "Air Series");
strcpy(inventoryOfCase[27].compatibility, "Oppo Reno8 T"); 
inventoryOfCase[27].price = 199;

inventoryOfCase[28].id = 69;
strcpy(inventoryOfCase[28].brand, "ColorWay");
strcpy(inventoryOfCase[28].name, "Simple Book");
strcpy(inventoryOfCase[28].compatibility, "Oppo A98"); 
inventoryOfCase[28].price = 349;

inventoryOfCase[29].id = 70;
strcpy(inventoryOfCase[29].brand, "ArmorStandart");
strcpy(inventoryOfCase[29].name, "Icon Case");
strcpy(inventoryOfCase[29].compatibility, "Oppo A74"); 
inventoryOfCase[29].price = 239;


Product inventoryOfPowerBank[7];
int countPowerBank = 7;

inventoryOfPowerBank[0].id = 71;
strcpy(inventoryOfPowerBank[0].brand, "Apple");
strcpy(inventoryOfPowerBank[0].name, "MagSafe Battery Pack");
inventoryOfPowerBank[0].speed = 5;
inventoryOfPowerBank[0].price = 4299;

inventoryOfPowerBank[1].id = 72;
strcpy(inventoryOfPowerBank[1].brand, "Xiaomi");
strcpy(inventoryOfPowerBank[1].name, "Mi Power Bank 20000");
inventoryOfPowerBank[1].speed = 22.5;
inventoryOfPowerBank[1].price = 2499;

inventoryOfPowerBank[2].id = 73;
strcpy(inventoryOfPowerBank[2].brand, "Samsung");
strcpy(inventoryOfPowerBank[2].name, "EB-P5300 20000");
inventoryOfPowerBank[2].speed = 25;
inventoryOfPowerBank[2].price = 2499;

inventoryOfPowerBank[3].id = 74;
strcpy(inventoryOfPowerBank[3].brand, "Baseus");
strcpy(inventoryOfPowerBank[3].name, "Bipow 10000");
inventoryOfPowerBank[3].speed = 15;
inventoryOfPowerBank[3].price = 599;

inventoryOfPowerBank[4].id = 75;
strcpy(inventoryOfPowerBank[4].brand, "Xiaomi");
strcpy(inventoryOfPowerBank[4].name, "Mi Power Bank 3 20000");
inventoryOfPowerBank[4].speed = 18;
inventoryOfPowerBank[4].price = 799;

inventoryOfPowerBank[5].id = 76;
strcpy(inventoryOfPowerBank[5].brand, "Hama");
strcpy(inventoryOfPowerBank[5].name, "PD-10HD 10000");
inventoryOfPowerBank[5].speed = 15;
inventoryOfPowerBank[5].price = 899;

inventoryOfPowerBank[6].id = 77;
strcpy(inventoryOfPowerBank[6].brand, "Promate");
strcpy(inventoryOfPowerBank[6].name, "Bolt-20");
inventoryOfPowerBank[6].speed = 10;
inventoryOfPowerBank[6].price = 1399;



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

