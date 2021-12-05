//Includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defines

#define TAM 10

#define MAXSTR 128

typedef struct vDrinks {

    int dId, dStock;
    char dName[MAXSTR], dType[TAM];
    float dPrice;

} vDrink;

//Adicionar bebidas
int createDrink(vDrink *drinksList, int *drinksNumber, int *lastDrinkId) {
    //Vars    
    vDrink drink;
    int drinksToRead = 0;

    //MainCode
    printf("\n Quantas bebidas deseja inserir: \t");
    scanf("%d", &drinksToRead);
    fflush(stdin);
    for (int i = 0; i < drinksToRead; i++) {
        printf("\n Nome da bebida: \t");
        scanf("%s", &drink.dName);
        fflush(stdin);

        printf("\n Preco da bebida: \t");
        scanf("%f", &drink.dPrice);
        fflush(stdin);

        printf("\n Stock da bebida: \t");
        scanf("%d", &drink.dStock);
        fflush(stdin);

        printf("\n Tipo de bebida: (simples|alcool|refrigerante)\t");
        scanf("%s", &drink.dType);
        fflush(stdin);
        
        (*lastDrinkId)++;
        drink.dId = *lastDrinkId;
        drinksList[(*drinksNumber)++] = drink;
    }

    return drinksToRead;
}

//Listar inventario de bebidas
void listingInventory(vDrink *vDrinks, int drinksNumber) {

    //MainCode
    printf("\n Lista de bebidas: \t");
    for (int i = 0; i < drinksNumber; i++) {
        printf("\n Id: %d", vDrinks[i].dId);
        printf(" | Nome: %s", vDrinks[i].dName);
        printf(" | Preco: %.2f", vDrinks[i].dPrice);
        printf(" | Stock: %d", vDrinks[i].dStock);
        printf(" | Tipo: %s", vDrinks[i].dType);
    }

}

//Listar bebida individual
void listingIndividualDrink(vDrink *vDrinks, int drinksNumber, int *lastDrinkId) {

    //Vars
    int x = *lastDrinkId, requestedId;

    //MainCode
    printf("\n Ultimo id inserido: %d\t", x);
    printf("\n Insira o id da bebida: \t");
    scanf("%d", &requestedId);
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dId==requestedId) {
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
            break;
        }
    }
}

//Alterar preco de um certo id
void changeDrinkPrice(vDrink *vDrinks, int drinksNumber, int *lastDrinkId) {

    //Vars
    int x = *lastDrinkId, requestedId;
    float newPrice;

    //MainCode
    printf("\n Ultimo id inserido: %d\t", x);
    printf("\n Insira o id da bebida: \t");
    scanf("%d", &requestedId);
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dId==requestedId) {
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
            printf("\n Novo preco da bebida: \t");
            scanf("%f", &newPrice);
            vDrinks[i].dPrice = newPrice;
            printf("\n Novos dados da bebida: \t");
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
            break;
        }
    }
};

//Mostrar bebida com mais stock
void showMostStockedDrink(vDrink *vDrinks, int drinksNumber) {

    //Vars
    int mostStockedStock = 0, mostStockedI = 0;

    //MainCode
    printf("\n A bebida com mais stock: \t");
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dStock > mostStockedStock) {
            mostStockedStock = vDrinks[i].dStock;
            mostStockedI = i;
        }
    }
    printf("\n Id: %d", vDrinks[mostStockedI].dId);
    printf(" | Nome: %s", vDrinks[mostStockedI].dName);
    printf(" | Preco: %.2f", vDrinks[mostStockedI].dPrice);
    printf(" | Stock: %d", vDrinks[mostStockedI].dStock);
    printf(" | Tipo: %s", vDrinks[mostStockedI].dType);
}

//Mostrar todo o stock em quantidade e preco
void showAllStock(vDrink *vDrinks, int drinksNumber) {

    //Vars
    int stockCount = 0;
    float stockPriceCount = 0, calcVar;

    //MainCode
    printf("\n O stock total: \t");
    for (int i = 0; i < drinksNumber; i++) {
        stockCount = stockCount + vDrinks[i].dStock;
        calcVar = calcVar + vDrinks[i].dPrice; //Calcula preco individual
    }
    stockPriceCount = stockCount * calcVar;
    printf("\n Quantidade: %d", stockCount);
    printf("\n Preco: %.2f", stockPriceCount);
}

//Mostrar media de preco das bebidas
void averagePriceOfDrinks(vDrink *vDrinks, int drinksNumber) {

    //Vars
    float averagePrice = 0, sumPrice = 0;

    //MainCode
    printf("\n A media de preco das bebidas: \t");
    for (int i = 0; i < drinksNumber; i++) {
        sumPrice = sumPrice + vDrinks[i].dPrice;
    }
    averagePrice = sumPrice / drinksNumber;
    printf("%.2f", averagePrice);
}

//Mostrar bebida por tipo inserido
void drinksByType(vDrink *vDrinks, int drinksNumber) {

    //Vars
    char requestedType[TAM] = "none";

    //MainCode
    printf("\n Insira o tipo de bebida: (simples|alcool|refrigerante|outro)\t");
    scanf("%s", requestedType);
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dType == requestedType) {
            printf("\n APAGAR - requestedType encontrado \t");
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
        }
    }
}

//Mostrar bebidas com o preco acima da media
void overpricedDrinks(vDrink *vDrinks, int drinksNumber) {

    //Vars
    float averagePrice = 0, sumPrice = 0;

    //MainCode
    for (int i = 0; i < drinksNumber; i++) {
        sumPrice = sumPrice + vDrinks[i].dPrice;
    }
    averagePrice = sumPrice / drinksNumber;         //Media de preco das bebidas todas
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dPrice > averagePrice) {
            printf("\n Id: %d", vDrinks[i].dId);
            printf(" | Nome: %s", vDrinks[i].dName);
            printf(" | Preco: %.2f", vDrinks[i].dPrice);
            printf(" | Stock: %d", vDrinks[i].dStock);
            printf(" | Tipo: %s", vDrinks[i].dType);
        }  
    }
    printf("\n Media de precos: %.2f\t", averagePrice);
}

//Mostrar valor do iva de todo o stock de alccol
void calculateIvaAlcool(vDrink *vDrinks, int drinksNumber) {

    //Vars
    float priceAndIva = 0, ivaAlcool = 0, justPrice = 0;

    //MainCode
    for (int i = 0; i < drinksNumber; i++) {
        if (vDrinks[i].dType == "alcool") {
            printf("\n vDrinks[i].dType: %.2f \t", vDrinks[i].dType);     //apagar
            priceAndIva = priceAndIva + vDrinks[i].dPrice;
        }
    }
    justPrice = priceAndIva / 1.13;
    ivaAlcool = priceAndIva - justPrice;
    printf("\n priceAndIva: %.2f \t", priceAndIva); //apagar
    printf("\n justPrice: %.2f \t", justPrice);     //apagar
    printf("\n O preco do iva do alcool em stock: %.2f \t", ivaAlcool);
}

int main() {

	//vars
    int menu = 0,
        drinksNumber = 0,
        drinksAdded = 0,
        lastDrinkAddedId = 0;
    vDrink drinks[TAM];

	//Preencher com variaveis restantes

	//main code
	puts("\n Gestao de bebidas:");              
	puts("\n 01|Adicionar bebidas");                                                                    //Funciona: sim
    puts("\n 02|Listar inventario de bebidas");                                                         //Funciona: sim
    puts("\n 03|Listar bebida individual");                                                             //Funciona: sim
    puts("\n 04|Alterar preco de uma bebida por id");                                                   //Funciona: sim
    puts("\n 05|Mostrar bebida com mais stock");                                                        //Funciona: sim
    puts("\n 06|Mostrar todo o stock (quantidade e preco)");                                            //Funciona: sim
    puts("\n 07|Media de preco das bebidas");                                                           //Funciona: sim
    puts("\n 08|Listar todas as bebidas por tipo (simples|alcool|refrigerante|outros)");                //Funciona: falha
    puts("\n 09|Mostrar a bebida mais barata de um certo tipo");                                        //Funciona: nao
    puts("\n 10|Listar bebidas que o preco esta acima da media");                                       //Funciona: sim
    puts("\n 11|Contabilizar, para cada tipo de bebida, a media da quantidade de garrafas em stock");   //Funciona: nao
    puts("\n 12|Vender bebidas por id");                                                                //Funciona: nao
    puts("\n 13|Calcular o IVA de todo o stock de alcool");                                             //Funciona: falha
    puts("\n 00|Sair");                                                                                 //Funciona: sim

    printf("\n Escolha a opcao que deseja: \t");
    scanf("%d", &menu);
    fflush(stdin);

    while (menu > 0)
    {
        switch (menu)
        {
        case 1: //Adicionar bebidas
            drinksAdded = createDrink(drinks, &drinksNumber, &lastDrinkAddedId);
            break;

        case 2: //Listar inventario de bebidas
            listingInventory(drinks, drinksNumber);
            break;

        case 3: //Listar info sobre bebida individual
            listingIndividualDrink(drinks, drinksNumber, &lastDrinkAddedId);
            break;

        case 4: //Alterar preco da bebida
            changeDrinkPrice(drinks, drinksNumber, &lastDrinkAddedId);
            break;

        case 5: //Mostrar bebida com mais stock
            showMostStockedDrink(drinks, drinksNumber);
            break;

        case 6: //Mostrar total de stock (quantidade e preco)
            showAllStock(drinks, drinksNumber);
            break;

        case 7: //Media de preco das bebidas
            averagePriceOfDrinks(drinks, drinksNumber);
            break;

        case 8: //Listar bebida por tipo inserido
            drinksByType(drinks, drinksNumber);
            break;

        case 9: //Mostrar a bebida mais barata de um certo tipo
            //Coming Soon
            break;

        case 10: //Mostrar bebidas com preco acima da media
            overpricedDrinks(drinks, drinksNumber);
            break;

        case 11: //
            //Coming Soon
            break;

        case 12: //
            //Coming Soon
            break;

        case 13: //Calcular iva do alcool em stock
            calculateIvaAlcool(drinks, drinksNumber);
            break;

        case 0:
            menu = 0;
            break;
        }

        if (menu == 0) {
            break;
        }

	    //main code
	    puts("\n Gestao de bebidas:");              
	    puts("\n 01|Adicionar bebidas");                                                                 
        puts("\n 02|Listar inventario de bebidas");                                                        
        puts("\n 03|Listar bebida individual");                                                             
        puts("\n 04|Alterar preco de uma bebida por id");                                                   
        puts("\n 05|Mostrar bebida com mais stock");                                                      
        puts("\n 06|Mostrar todo o stock (quantidade e preco)");                                         
        puts("\n 07|Media de preco das bebidas");                                                        
        puts("\n 08|Listar todas as bebidas por tipo (simples|alcool|refrigerante|outros)");            
        puts("\n 09|Mostrar a bebida mais barata de um certo tipo");                                       
        puts("\n 10|Listar bebidas que o preco esta acima da media");                                      
        puts("\n 11|Contabilizar, para cada tipo de bebida, a media da quantidade de garrafas em stock");   
        puts("\n 12|Vender bebidas por id");
        puts("\n 13|Calcular o IVA de todo oo stock de alcool");
        puts("\n 00|Sair");

        printf("\n Escolha a opcao que deseja: \t");
        scanf("%d", &menu);
        fflush(stdin);
    }

    return 0;

}
