class MenuItem{

	constructor(name, ingrediance, caloryLowBound, caloryHighBound, category, subcategory, nonDairy) {
	  this.itemName = name;
	  this.ingrediance = ingrediance;
	  this.caloryHighBound = caloryHighBound;
	  this.caloryLowBound = caloryLowBound;
	  this.category = category;
	  this.subcategory = subcategory;
	  this.dairy = dairy;
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
console.log(myBananaberry.itemName, myBananaberry.ingrediance, myBananaberry.dairy, myBananaberry.caloryLowBound);

myMangoMagic = new MenuItem("Mango Magic", ["mango", "stawberries", "pineapples", "coconut", "creme"], 250, 310, "Smoothie", "Classic Favorites", false);

myGreenSmoothie = new MenuItem("Green Smoothie", ["bananas", "spinach"], 295, 530, "Smoothie", "Healthy & Smart", false);

myPurplePopeye = new MenuItem("Purple Popeye");

myBrazilianSunrise = new MenuItem("BrazilianSunrise");

myBeetBooster = new MenuItem("Beet Booster");

myBrazilianSunrise = new MenuItem("BrazilianSunrise");

myBeetBooster = new MenuItem("Beet Booster");