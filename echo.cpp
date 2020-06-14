#include <napi.h>

using namespace std;

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  string arg0 = info[0].As<Napi::String>().Utf8Value();

  return Napi::String::New(env, arg0);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "echo"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(echo, Init)
