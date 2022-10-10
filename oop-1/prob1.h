#include <string>
using namespace std;

class IIKH {
private:
	Recipe* recipeList = new Recipe[30]; // Recipe List variable
public:
	IIKH(); // Constructor
	void InitProgram(); // Starting Program or Being called when Return button pushed
	void NewWindow(); // Creating new window for showing Recipe searched
	void SearchRecipe(); // Searching Recipe 
	void ShowRecipe(); // Showing Recipes that meet user's search criteria
};

class Recipe {
private:
	string dishName = "unNamed"; // default dish name
	string* ingredients = new string[30]; // ingredients list
	string* items = new string[30]; // items list
	int preparationTime; // expected preparation time
	int currentStep = 1; // current step
	string* cookingStep = new string[30]; // how to cook on steps
	string imageLink; // image link for dish

public:
	Recipe(); // Constructor
	Recipe(char dishName); // Constructor that can change dishName member variable

	void SetDishName(); // set method for dishName variable
	void GetDishName(); // get method for dishName variable

	void SetIngredients(); // set method for ingredients variable
	void GetIngredients(); // get method for ingredients variable

	void SetItems(); // set method for items variable
	void GetItems(); // get method for items variable

	void SetPreparationTime(); // set method for preparationTime variable
	void GetPreparationTime(); // get method for preparationTime variable
	
	void PrintRecipe(); // print recipe that user want

	void SetCookingStep(int currentStep); // set method for cookingStep variable
	void GetCookingStep(int currentStep); // get method & showing recipe for currentStep

	void CreateRecipe(char dishName); // creating custom recipe
};
