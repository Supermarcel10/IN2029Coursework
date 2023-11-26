#include "recipe.h"
#include <iostream>

using namespace std;

// Global hash map of ingredients
// Unordered since I don't care about the order
unordered_map<string, double> ingredients;

// Print the ingredients to the output stream using string stream for efficiency
void printIngredients(ostream& out) {
    ostringstream oss;
    for (auto& ingredient : ingredients) {
        oss << ingredient.first << " " << ingredient.second << "\n";
    }
    out << oss.str();
}

// Iterate through the file line by line and parse the recipes into a global map ingredients
void parseOrders(ifstream& file) {
    string line;
    stringstream ss;
    while (getline(file, line)) {
        ss.clear();
        ss.str(line);
        string recipeName;
        double quantity;

        ss >> recipeName >> quantity;

        Recipe* recipe = getRecipe(recipeName);

        // If recipe is not found, skip it
        if (recipe == nullptr) {
            cerr << "Recipe \"" << recipeName << "\" not found!\nOmitting in calculation.\n";
            continue;
        }

        // Add ingredients to the map
        for (auto& ingredient : recipe->getIngredients()) {
            ingredients[ingredient.first] += ingredient.second * quantity;
        }
    }
}

int main() {
    // Read ingredients file
    ifstream fIngredients("../ingredients.txt");
    parseRecipes(fIngredients);

    // Read orders file
    ifstream fOrders("../orders.txt");
    parseOrders(fOrders);

    // Print ingredients
    printIngredients(cout);

    return 0;
}
