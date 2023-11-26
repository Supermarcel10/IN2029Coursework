#include <chrono>
#include "recipe.h"

using namespace std;

// Global hash map of recipes
unordered_map<string, Recipe> Recipe::recipes;

// Print the ingredients to the output stream using string stream for efficiency
void Recipe::addIngredient(const string& ingredientName, const double& quantity) {
    ingredients.emplace(ingredientName, quantity);
}

// Parse the recipes file
void parseRecipes(ifstream& file) {
    // Iterate through the file line by line
    string line;
    stringstream ss;
    while (getline(file, line)) {
        ss.clear();
        ss.str(line);
        string recipeName, ingredient;
        double quantity;

        // Split the data
        ss >> recipeName >> ingredient >> quantity;

        getOrMakeRecipe(recipeName).addIngredient(ingredient, quantity);
    }
}

// Get recipe by name
Recipe* getRecipe(const std::string& recipeName) {
    auto it = Recipe::recipes.find(recipeName);
    if (it != Recipe::recipes.end()) return &it->second;

    return nullptr;
}

// Get recipe by name, if not found, create a new one
Recipe& getOrMakeRecipe(const std::string& recipeName) {
    // Search for the recipe
    Recipe* recipe = getRecipe(recipeName);

    // If recipe found, return it
    if (recipe != nullptr) return *recipe;

    // If recipe not found, create a new one
    Recipe::recipes.emplace(recipeName, Recipe(recipeName));
    return Recipe::recipes[recipeName];
}
