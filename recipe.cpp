#include "recipe.h"

using namespace std;

vector<Recipe> Recipe::recipes;

void Recipe::addIngredient(const string& ingredientName, const double& quantity) {
    ingredients.insert(pair<string, double>(ingredientName, quantity));
}

Recipe* getRecipe(const std::string& recipeName) {
    for (auto& r : Recipe::recipes) {
        if (r.getRecipeName() == recipeName) return &r;
    }

    return nullptr;
}

Recipe& getOrMakeRecipe(const std::string& recipeName) {
    // Search for the recipe
    Recipe* recipe = getRecipe(recipeName);

    // If recipe found, return it
    if (recipe != nullptr) return *recipe;

    // If recipe not found, create a new one
    Recipe::recipes.emplace_back(recipeName);
    return Recipe::recipes.back();
}

void parseRecipes(const string& filePath) {
    ifstream file(filePath);

    // Iterate through the file line by line
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string recipeName, ingredient;
        double quantity;

        // Split the data
        ss >> recipeName >> ingredient >> quantity;

        getOrMakeRecipe(recipeName).addIngredient(ingredient, quantity);
    }
}
