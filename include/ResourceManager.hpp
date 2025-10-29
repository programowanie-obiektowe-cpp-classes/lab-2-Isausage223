
#pragma once

#include "Resource.hpp"

class ResourceManager
{
    Resource* resource;

public:
    // konstruktor domyślny
    ResourceManager() : resource{new Resource()} {}

    // destruktor
    ~ResourceManager() { delete resource; }

    // konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource{new Resource(*other.resource)} {}

    // operator przypisania kopiującego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            // silna gwarancja wyjątków: alokuj najpierw nowy zasób
            Resource* tmp = new Resource(*other.resource);
            delete resource;
            resource = tmp;
        }
        return *this;
    }

    // metoda udostępniająca wartość zasobu
    double get() const { return resource->get(); }
};
