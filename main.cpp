#include "recipe.h"
#include <iostream>

using namespace std;

map<string, double> ingredients;

int main() {
    // Read ingredients file
    parseRecipes("../ingredients.txt");

    // Read orders file
    ifstream file("../orders.txt");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        string recipeName;
        double quantity;

        ss >> recipeName >> quantity;

        Recipe* recipe = getRecipe(recipeName);

        // If recipe is not found, skip it
        if (recipe == nullptr) {
            cout << "Recipe \"" << recipeName << "\" not found!\nOmitting in calculation." << endl;
            continue;
        }

        // Add ingredients to the map
        for (auto& ingredient : recipe->getIngredients()) {
            ingredients[ingredient.first] += ingredient.second * quantity;
        }
    }

    // Print ingredients
    for (auto& ingredient : ingredients) {
        cout << ingredient.first << " " << ingredient.second << endl;
    }

    return 0;
}

