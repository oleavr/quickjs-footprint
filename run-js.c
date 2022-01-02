#include <quickjs.h>
#include <stdio.h>
#include <string.h>

int
main (int argc,
      char * argv[])
{
  JSRuntime * rt;
  JSContext * ctx;
  const char * code = "2 + 2";
  JSValue result;
  const char * str;

  rt = JS_NewRuntime ();
  ctx = JS_NewContextRaw (rt);
  //JS_AddIntrinsicBaseObjects (ctx);
  //JS_AddIntrinsicDate (ctx);
  JS_AddIntrinsicEval (ctx); // Required here since we're not using bytecode.
  //JS_AddIntrinsicStringNormalize (ctx);
  //JS_AddIntrinsicRegExp (ctx);
  //JS_AddIntrinsicJSON (ctx);
  //JS_AddIntrinsicProxy (ctx);
  //JS_AddIntrinsicMapSet (ctx);
  //JS_AddIntrinsicTypedArrays (ctx);
  //JS_AddIntrinsicPromise (ctx);
  //JS_AddIntrinsicBigInt (ctx);

  result = JS_Eval (ctx, code, strlen (code), "hello.js", JS_EVAL_TYPE_GLOBAL | JS_EVAL_FLAG_STRICT);

  str = JS_ToCString (ctx, result);
  printf ("%s\n", str);
  JS_FreeCString (ctx, str);

  JS_FreeValue (ctx, result);

  JS_FreeContext (ctx);
  JS_FreeRuntime (rt);

  return 0;
}
