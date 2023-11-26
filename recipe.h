#ifndef RECIPE_H
#define RECIPE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Recipe {
    std::string recipeName; // Name of the recipe
    std::unordered_map<std::string, double> ingredients; // Ingredients and their quantities

public:
    // Global hash map of recipes
    static std::unordered_map<std::string, Recipe> recipes;

    // Default constructor
    Recipe() = default;

    // Constructor with recipe name
    explicit Recipe(std::string  name) : recipeName(std::move(name)) {}

    // Add ingredient to the recipe
    void addIngredient(const std::string& ingredientName, const double& quantity);

    // Getters
    [[nodiscard]] const std::string& getRecipeName() const {
        return recipeName;
    }

    [[nodiscard]] const std::unordered_map<std::string, double>& getIngredients() const {
        return ingredients;
    }
};

// Parse the recipes file
void parseRecipes(std::ifstream& file);

// Get recipe by name
Recipe* getRecipe(const std::string& recipeName);

// Get recipe by name, if not found, create a new one
Recipe& getOrMakeRecipe(const std::string& recipeName);

#endif //RECIPE_H
