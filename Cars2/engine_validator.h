#pragma once

#include "validator.h"
#include "engine.h"

class EngineValidator : public Validator<Engine>
{
private:
	static bool is_engine_type_value(const std::string& value);
	static bool is_power_valid(const Engine& engine);
public:

	std::unordered_map<std::string, std::string> validator(const Engine& engine) override;
	

	EngineValidator() = default;
	~EngineValidator() = default;
};

