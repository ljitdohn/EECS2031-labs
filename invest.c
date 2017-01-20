#include <stdio.h>
#include <stdlib.h>

/*Lab 2*/
/*This code has been tested. Unsolved problems with the RNG.*/

double stockPrice, balance;
double changeRate0, changeRate1, changeRate2; /*changeRateN means the change rate of N days before today.*/
int stockOwned;
int dayCount;
int pass = 1;/*Input param. When equal to 0, finish the program.*/
int r, b;/*Init var for rand and buy.*/

main(){
	
	onInit();
	
	while(scanf("%d", &pass) != 0){
		Day();
	}
	
	onFinish();

}

Day(){
	++ dayCount;/*Good morning!*/
	changeRate2 = changeRate1;
	changeRate1 = changeRate0;
	changeRate0 = 0.0;
	
	printf("%.2f --> %.2f      ", stockPrice, changeRate1);
	/*In the morning, buy or sell stocks.*/
	if(changeRate2 == 1.1 && changeRate1 == 1.1){
		Sell(stockOwned);
		printf("Sold all. %-6d shares remaining, and %2f dollars remaining.\n", stockOwned, balance);
	}else if(changeRate2 >= 1.05 && changeRate1 >= 1.05){
		b = (balance/stockPrice)/2;
		Buy(b);
		printf("Bought 1/2. %-6d shares remaining, and %2f dollars remaining.\n", stockOwned, balance);
	}else if(changeRate2 < 1 && changeRate1 < 1){
		b = (balance/stockPrice);
		Buy(b);
		printf("Bought all. %-6d shares remaining, and %2f dollars remaining.\n", stockOwned, balance);
	}else{
		printf("No action.");
	}
	
	/*In the night, stock price changes by random.*/
	r = (double)rand()/(double)RAND_MAX;
	changeRate0 = 0.3 * r + 0.85;
	
	stockPrice = stockPrice * changeRate0;
	printf("Day %d: The price now is %.2f.\n", dayCount, stockPrice);
}

onInit(){
	changeRate0 = changeRate1 = changeRate2 = 1;
	stockPrice = 12.0;
	balance = 10000.0;
	stockOwned = 0;
	dayCount = 0; /*Program starts at the night time.*/
}

onFinish(){
	balance = balance + stockOwned * stockPrice;
	stockOwned = 0;
	double settlement = balance - 10000.0;
	if(settlement >= 0){
		printf("Earn: $%.2f\n", settlement);
	}else{
		settlement = 0 - settlement;
		printf("Loss: $%.2f\n", settlement);
	}
}

Buy(int s){
	if(s * stockPrice > balance){
		b = stockPrice/balance;
		Buy(b);
	}else{
		balance = balance - s * stockPrice;
		stockOwned = stockOwned + s;
	}
}

Sell(int s){
	if(s > stockOwned){
		Sell(stockOwned);
	}else{
		stockOwned = stockOwned - s;
		balance = balance + s * stockPrice;
	}
}
