#include <quickjs.h>
#include <string.h>

int
main (int argc,
      char * argv[])
{
  JSRuntime * rt;
  JSContext * ctx;
  const char * code = "2 + 2";
  JSValue result;

  rt = JS_NewRuntime ();
  ctx = JS_NewContext (rt);

  result = JS_Eval (ctx, code, strlen (code), "hello.js", JS_EVAL_TYPE_GLOBAL | JS_EVAL_FLAG_STRICT);
  JS_FreeValue (ctx, result);

  JS_FreeContext (ctx);
  JS_FreeRuntime (rt);

  return 0;
}
