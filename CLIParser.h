#pragma once
#include <string>
#include <vector>
namespace CLIParser {
	struct InputArgument {
		std::string name;
		std::string value;
	};
	struct InputData {
		std::vector<InputArgument> listArguments;
	};

	//Parses arguments given at the start of the program and returns a InputData object
	InputData* ParseArguments(int argc, char** argv, char prefix = '-') {
		InputData* outArguments = new InputData();
		outArguments->listArguments = std::vector<InputArgument>();
		// Per each argument save with new instance of InputArgument on
		// InputData.rawArguments
		for (size_t i = 1; i < argc; i += 2)
		{
			if (argv[i][0] == prefix)
			{
				InputArgument inputArguments = {};
				inputArguments.name = std::string(argv[i]).substr(1);
				inputArguments.value = std::string(argv[i + 1]);
				outArguments->listArguments.push_back(inputArguments);	//Adding Argument to argument parsed list		
			}
		}
		return outArguments;
	}

	const char* GetArgumentValue(const char* parameterName, InputData* data)
	{
		for (size_t i = 0; i < data->listArguments.size(); i++)
		{
			if (data->listArguments[i].name == parameterName)
			{
				return data->listArguments[i].value.c_str();
			}
		}
	}
}