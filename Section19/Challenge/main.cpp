// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void write(std::string country, std::string city, std::string population, std::string price)
{
    std::cout << std::setw(19) << std:: left << country << std::setw(25) << std::left << city << std::setw(10) << std::right <<population << std::setw(16) << std::right << price << std::endl;
}

void write(std::string country, std::string city, int population, double price)
{
    std::cout << std::setw(19) << std:: left << country << std::setw(25) << std::left << city << std::setw(10) << std::right <<population << std::setw(16) << std::right << std::setprecision(2) << std::fixed << price << std::endl;
}

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };
    for (int i = 0; i < 7; i++)
        std::cout << "1234567890";
    std::cout << std::endl << std::endl;
    
    // Unformatted display so you can see how to access the vector elements

    std::cout << std::setw(70/2 + size(tours.title)/2) << std::right <<tours.title << std::endl << std::endl;

    write("Country", "City", "Population", "Price");
    std::cout << std::setfill('-') << std::setw(70) <<""<< std::endl;
    std::cout << std::setfill(' ');
    for(auto country : tours.countries) {   // loop through the countries
        //std::cout << country.name << std::endl;
        bool first = true;
        for(auto city : country.cities) {       // loop through the cities for each country
            std::string aux = "";
            first? aux = country.name : aux ="";
            write(aux, city.name, city.population, city.cost);
            first = false;

        }
    }

    n_file.close();
    std::cout << std::endl << std::endl;
    return 0;
}