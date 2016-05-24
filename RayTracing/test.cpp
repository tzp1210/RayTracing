#include <iostream>
#include <vector>
#include "Model.h"
#include "SpherePrimitive.h"

int main()
{
	Model model(/*std::vector<Primitive*>*/{ new SpherePrimitive(1.0, Color(1.0, 0.0, 0.0)) });
	model.output();
	return 0;
}