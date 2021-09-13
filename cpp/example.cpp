#include <jni.h>
#include <jsi/jsi.h>
#include <iostream>
#include <string>
#include "example.h"

using namespace std;
using namespace facebook;

namespace example {
	int multiply(float a, float b) {
		return a * b;
	}
	int multiplyJsi(float a, float b) {
		return a * b;
	}
	int add(float a, float b) {
		return a + b;
	}
	void installJsi(jsi::Runtime& jsiRuntime){
		auto multiplyJsi = jsi::Function::createFromHostFunction(
			jsiRuntime,
			jsi::PropNameID::forAscii(jsiRuntime, "multiplyJsi"),
			2,
			[](jsi::Runtime& runtime, const jsi::Value& thisValue, const jsi::Value* arguments, size_t count) -> jsi::Value {
			if(count == 0) {
          		jsi::detail::throwJSError(runtime, "[react-native-quick-sqlite] database name is required");
          		return {};
        	}
			std::cout <<"hello";
			// return example::multiplyJsi(arguments[0].asNumber(),arguments[1].asNumber());
			return jsi::Value(arguments[0].asNumber()*arguments[1].asNumber());
			}
		);
		jsiRuntime.global().setProperty(jsiRuntime, "multiplyJsi", std::move(multiplyJsi));

		auto multiplyWithCallback = jsi::Function::createFromHostFunction(
			jsiRuntime,
			jsi::PropNameID::forAscii(jsiRuntime, "multiplyWithCallback"),
			3,
			[](jsi::Runtime& runtime, const jsi::Value& thisValue, const jsi::Value* arguments, size_t count) -> jsi::Value {
			std::cout <<"hello";
			int x = arguments[0].asNumber();
			int y = arguments[1].asNumber();

			arguments[2].getObject(runtime).getFunction(runtime).call(runtime, x*y);
			return jsi::Value();
			}
		);
		jsiRuntime.global().setProperty(jsiRuntime, "multiplyWithCallback", std::move(multiplyWithCallback));

		auto helloWorld = jsi::Function::createFromHostFunction(
			jsiRuntime,
			jsi::PropNameID::forAscii(jsiRuntime, "helloWorld"),
			0,
			[](jsi::Runtime& runtime, const jsi::Value& thisValue, const jsi::Value* arguments, size_t count) -> jsi::Value {
				string data = "message from jsi";
				return jsi::Value(runtime, jsi::String::createFromUtf8(runtime, data));
			}
		);

		jsiRuntime.global().setProperty(jsiRuntime, "helloWorld", std::move(helloWorld));
	}
}
