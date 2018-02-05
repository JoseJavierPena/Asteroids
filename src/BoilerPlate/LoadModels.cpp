#include "LoadModels.hpp"

namespace Utilities
{
	LoadModels::LoadModels()
	{}
	
	LoadModels::~LoadModels()
	{}

	// LOAD MODELS
	std::vector<Asteroids::Entities::Ship*> LoadModels::Load(const int width, const int height)
	{
		Engine::FileSystem::Utilities util;
		auto modelsList = util.ListFile(fileName);
		std::vector<Asteroids::Entities::Ship*> ships;

		//std::cout << " * LOADED MODELS* " << std::endl;
		for (int i = 2; i < static_cast<int>(modelsList.size()); i++)
		{
			std::string model = modelsList[i];
			std::ifstream inFile(util.buildPath(fileName, model));
			std::string current("");
			std::vector<Engine::Math::Vector2> points;

			if (inFile.good())
			{
				std::string getFloat;
				while (inFile >> current)
				{
					std::vector<float> pointsRead;
					getFloat = current.substr(0, current.find_last_of(","));
					pointsRead.push_back(std::stof(getFloat));	
					getFloat = current.substr(current.find_last_of(",") + 1, current.length());
					pointsRead.push_back(std::stof(getFloat));

					// Adding points to vector
					points.push_back(Engine::Math::Vector2(pointsRead[0], pointsRead[1]));
				}
			}
			//std::cout << model << " has " << points.size() << " points " << std::endl;

			// Adding points to temp
			Asteroids::Entities::Ship* temp = new Asteroids::Entities::Ship(points, width, height);

			// Adding temp to ships vector, who storages the ships in a vector
			ships.push_back(temp);
		}
		//std::cout << std::endl;

		return ships;
	}
}