#include "engine_validator.h"

bool EngineValidator::is_engine_type_value(const std::string& value)
{
	
	return std::find(EngineTypeValues.begin(), EngineTypeValues.end(), value) != EngineTypeValues.end();
}

bool EngineValidator::is_power_valid(const Engine& engine)
{
	return engine.power >=0;
}

std::unordered_map<std::string, std::string> EngineValidator::validator(const Engine& engine)
{
	if (!is_engine_type_value(engine_type_to_string(engine.type)))
	{
		errors.insert(std::make_pair("engine", "is not valid"+engine_type_to_string(engine.type)));
	}
	if(!is_power_valid(engine))
	{
		errors.insert(std::make_pair("power", "is not valid" + std::to_string(engine.power)));
	}
	return errors;
}
