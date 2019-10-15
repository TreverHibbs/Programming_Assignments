class MenuItem{

	constructor(name, ingrediantList, smallCalorries, regularCalories, category, subcategory, nonDairy) {

	  this.ingrediantList = [];

	  this.itemName = name;
	  this.ingrediantList = ingrediantList;
	  this.regularCalories = regularCalories;
	  this.smallCalorries = smallCalorries;
	  this.category = category;
	  this.subcategory = subcategory;
	  this.nonDairy = nonDairy;
  }
}

class Menu{

  constructor() {
	  this.itemList = new Array();
  }



  
  addMenuItem(item) {
	  this.itemList.push(item);
	  return
  }

  findMenuItem(ingrediant){
	let filteredItemList = [];
	for (let item of this.itemList){
		try{
			var arrayLength = item.ingrediantList.length;

			for(var i = 0; i < arrayLength; i++){	
				try{
				}catch(e){

				}
				if (item.ingrediantList[i] === ingrediant){
					filteredItemList.push(item);
				}
			}
		}catch(e){

		}
	}

	let filteredItemNames = [];
	var arrayLength = filteredItemList.length;

	try{
		for(var i = 0; i < arrayLength; i++){
			try{	
			filteredItemNames[i] = filteredItemList[i].itemName;
			}catch(e){

			}
		}
	}catch(e){

	}

	return(filteredItemNames);
  }
}

class Drink{
	constructor(MenuItem, size){
		this.drink = MenuItem;
		this.drinkSize = size;
	}
}

class Order{
	constructor(){
		this.drinkList = [];

		this.smallClassicSmoothiePrice = 3.99;
		this.regularClassicSmoothiePrice = 4.99;
		this.smallHealthySmoothiePrice = 4.99;
		this.regularHealthySmoothiePrice = 5.99;
		this.juecePrice = 3.00;
	}

	addDrink(drink) {
		this.drinkList.push(drink);
		return
	}

	calculateCost() {
		var total = 0.00;

		for (let currentDrink of this.drinkList){
			try{
				if(currentDrink.drink.category === "Smoothie" && currentDrink.drink.subcategory === "Healthy & Smart"){
					if(currentDrink.drinkSize === "small"){
						total += 4.99;
					}else{
						total += 5.99;
					}
				}else if(currentDrink.drink.category === "Smoothie" && currentDrink.drink.subcategory === "Classic Favorites"){
					if(currentDrink.drinkSize === "small"){
						total += 3.99;
					}else{
						total += 4.99;
					}
				}else{
					total += 3.00;
				}
			}catch(e){
				console.log(e);
			}
		}
		return(total);
	}

	calculateCallories() {
		var total = 0.00;

		for (let currentDrink of this.drinkList){
			try{
				if(currentDrink.drinkSize === "small"){
					total += currentDrink.drink.smallCalorries;
				}else{
					total += currentDrink.drink.regularCalories
				}
			}catch(e){
				console.log(e);
			}
		}
		return(total);
	}
}

class Inventory{
	constructor(){
		//each quantity in the quantity array will correspond with the ingrediant at the same index of the ingredient array.
		this.ingredients = ["banana", "strawberries", "mango", "pineapple", "coconut", "creme", "spinach", "apple", "beet", "cucumber", "acai", "blueberrie", "granola", "orange"];
		this.quantity = [];
	}
}

class Store{
	constructor(inventory){
		this.myInventory = inventory;
	}

	//This function will take in an Order object and check if it can make the order with current inventory.
	placeOrder(myOrder){

		let insufficientFlag = false;
		var canMakeArray = [];

		for(let item of myOrder.drinkList){
			try{
				//iterate through all ingrediants needed for current drink.
				for(let drinkIngrediant of item.drink.ingrediantList){
					//iterate through every ingrediant in inventory to check if that ingrediant is need for the drink.
					//If ingredient is needed then decrement inventory counter accordingly.
					//finally check if there is not enough of ingrediant and set flag if true.
					for(var i = 0; i < this.myInventory.ingredients.length; i++){
						if(drinkIngrediant ===  this.myInventory.ingredients[i] && item.drink.drinkSize === "small" && this.myInventory.quantity[i] >= 1){
							this.myInventory.quantity[i]--; 
						}else if(drinkIngrediant ===  this.myInventory.ingredients[i] && this.myInventory.quantity[i] >= 2){
							this.myInventory.quantity[i]--;
							this.myInventory.quantity[i]--;
						}else if(drinkIngrediant ===  this.myInventory.ingredients[i]){
							insufficientFlag = true;
							break;
						}
					}
					if(insufficientFlag){
						break;
					}
				}
			}catch(e){
				console.log(e);
			}
			if(insufficientFlag == false){
				canMakeArray.push(item);
			}

			insufficientFlag = false;
		}

		return(canMakeArray);
	}
}

myBananaberry = new MenuItem("Bananaberry", ["banana","strawberrie"],230,405,"Smoothie", "Classic Favorites", true);

myMangoMagic = new MenuItem("Mango Magic", ["mango", "strawberrie", "pineapple", "coconut", "creme"], 250, 310, "Smoothie", "Classic Favorites", false);

myGreenSmoothie = new MenuItem("Green Smoothie", ["banana", "spinach"], 295, 530, "Smoothie", "Healthy & Smart", false);

myPurplePopeye = new MenuItem("Purple Popeye", ["spinach", "apple", "beet", "cucumber"], 130, 130, "Juice", "Healthy & Smart", false);

myBrazilianSunrise = new MenuItem("BrazilianSunrise", ["banana", "acai", "blueberrie", "granola"], 515, 780, "Smoothie", "Healthy & Smart", false);

myBeetBooster = new MenuItem("Beet Booster", ["beet", "orange", "apple"], 225, 225, "Juice", "Healthy & Smart", false);

myMenu = new Menu();

myMenu.addMenuItem(myBananaberry);
myMenu.addMenuItem(myMangoMagic);
myMenu.addMenuItem(myGreenSmoothie);
myMenu.addMenuItem(myPurplePopeye);
myMenu.addMenuItem(myBrazilianSunrise);
myMenu.addMenuItem(myBeetBooster);

myDrink = new Drink(myBananaberry, "small");

myOrder = new Order();

myOrder.addDrink(myDrink);

myDrink = new Drink(myGreenSmoothie, "small");

myOrder.addDrink(myDrink);

myInventory = new Inventory();

myInventory.quantity[0] = 5;
myInventory.quantity[1] = 7;
myInventory.quantity[2] = 23;
myInventory.quantity[3] = 2;
myInventory.quantity[4] = 9;
myInventory.quantity[5] = 3;
myInventory.quantity[6] = 0;
myInventory.quantity[7] = 5;
myInventory.quantity[8] = 3;
myInventory.quantity[9] = 7;
myInventory.quantity[10] = 8;
myInventory.quantity[11] = 2;
myInventory.quantity[12] = 12;
myInventory.quantity[13] = 6;

myStore = new Store(myInventory);

console.log(myStore.placeOrder(myOrder));