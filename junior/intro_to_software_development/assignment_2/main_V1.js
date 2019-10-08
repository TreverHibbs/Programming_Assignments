class MenuItem{

	constructor(name, ingrediance, smallCalorries, regularCalories, category, subcategory, nonDairy) {

	  this.ingrediance = [];

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
	  this.itemList = new Array(20);
  }



  
  addMenuItem(item) {
	  this.itemList.push(item);
	  return
  }

  findMenuItem(ingrediant){
	let filteredItemList = [];
	for (let item of this.itemList){
		try{
			var arrayLength = item.ingrediance.length;

			for(var i = 0; i < arrayLength; i++){	
				try{
				}catch(e){

				}
				if (item.ingrediance[i] === ingrediant){
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

myBananaberry = new MenuItem("Bananaberry", ["banana","strawberrie"],230,405,"Smoothie", "Classic Favorites", true);

myMangoMagic = new MenuItem("Mango Magic", ["mango", "stawberrie", "pineapple", "coconut", "creme"], 250, 310, "Smoothie", "Classic Favorites", false);

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

console.log(myMenu.findMenuItem("banana"));
