class MenuItem{

	constructor(name, ingrediance, smallCalorries, regularCalories, category, subcategory, nonDairy) {
	  this.itemName = name;
	  this.ingrediance = ingrediance;
	  this.regularCalories = regularCalories;
	  this.smallCalorries = smallCalorries;
	  this.category = category;
	  this.subcategory = subcategory;
	  this.nonDairy = nonDairy;
  }
}

class Menu{
	constructor() {
	  let itemList = [];
  }

  addMenuItem(item) {
	  itemList.push(item);
	  return
  }

  findIngrediance() {
	  	
  }

  filter(fn){
	let filteredItemList = [];
	
  }
}

myBananaberry = new MenuItem("Bananaberry", ["bananas","strawberries"],230,405,"Smoothie", "Classic Favorites", true);
console.log(myBananaberry.itemName, myBananaberry.ingrediance, myBananaberry.nonDairy, myBananaberry.smallCalorries);

myMangoMagic = new MenuItem("Mango Magic", ["mango", "stawberries", "pineapples", "coconut", "creme"], 250, 310, "Smoothie", "Classic Favorites", false);

myGreenSmoothie = new MenuItem("Green Smoothie", ["bananas", "spinach"], 295, 530, "Smoothie", "Healthy & Smart", false);

myPurplePopeye = new MenuItem("Purple Popeye", ["spinach", "apple", "beet", "cucumber"], 130, 130, "Juice", "Healthy & Smart", false);

myBrazilianSunrise = new MenuItem("BrazilianSunrise", ["bananas", "acai", "blueberries", "granola"], 515, 780, "Smoothie", "Healthy & Smart", false);

myBeetBooster = new MenuItem("Beet Booster", ["beet", "orange", "apple"], 225, 225, "Juice", "Healthy & Smart", false);