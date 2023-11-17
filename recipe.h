#ifndef RECIPE_H
#define RECIPE_H

#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Recipe {
    std::string recipeName;
    std::map<std::string, double> ingredients;

public:
    static std::vector<Recipe> recipes;

    explicit Recipe(std::string name) : recipeName(std::move(name)) {};

    void addIngredient(const std::string& ingredientName, const double& quantity);

    [[nodiscard]] const std::string& getRecipeName() const {
        return recipeName;
    }

    [[nodiscard]] const std::map<std::string, double>& getIngredients() const {
        return ingredients;
    }
};

void parseRecipes(const std::string& fileName);

Recipe* getRecipe(const std::string& recipeName);

Recipe& getOrMakeRecipe(const std::string& recipeName);

#endif //RECIPE_H
