#pragma once
#include <functional>
using namespace std::placeholders;

namespace Engine {
	namespace Utilities {
		class genericFunction
		{
		public:
			virtual ~genericFunction() = 0;
			virtual void call() = 0;
		};

		template<class type>
		class FunctionPtr : public genericFunction
		{
		public:
			std::function<type> func;
			~FunctionPtr() {
				FunctionPtr(std::function<type> func)
					: func()
				{
				}
				void call()
				{
					func();
				}
			};
		};
	}
}