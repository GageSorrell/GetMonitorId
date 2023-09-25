#include <napi.h>
#include <windows.h>

Napi::Object GetWindowPos(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);

    HWND hwnd = GetForegroundWindow();
    RECT rect;
    GetWindowRect(hwnd, &rect);

    obj.Set("x", Napi::Number::New(env, rect.left));
    obj.Set("y", Napi::Number::New(env, rect.top));

    return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("getWindowPos", Napi::Function::New(env, GetWindowPos));
    return exports;
}

NODE_API_MODULE(activeWindowPosition, Init)
