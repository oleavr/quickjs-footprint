#include <quickjs.h>
#include <string.h>

int
main (int argc,
      char * argv[])
{
  JSRuntime * rt;
  JSContext * ctx;
  const uint8_t code[] = {
    0x02, 0x01, 0x10, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x2e, 0x6a, 0x73, 0x0e,
    0x00, 0x06, 0x01, 0xa2, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x05,
    0x01, 0xa4, 0x01, 0x00, 0x00, 0x00, 0xb7, 0xb7, 0x9d, 0xcd, 0x28, 0xbe,
    0x03, 0x01, 0x00,
  };
  JSValue func, result;
  const char * str;

  rt = JS_NewRuntime ();
  ctx = JS_NewContextRaw (rt);
  //JS_AddIntrinsicBaseObjects (ctx);
  //JS_AddIntrinsicDate (ctx);
  ////JS_AddIntrinsicEval (ctx);
  //JS_AddIntrinsicStringNormalize (ctx);
  //JS_AddIntrinsicRegExp (ctx);
  //JS_AddIntrinsicJSON (ctx);
  //JS_AddIntrinsicProxy (ctx);
  //JS_AddIntrinsicMapSet (ctx);
  //JS_AddIntrinsicTypedArrays (ctx);
  //JS_AddIntrinsicPromise (ctx);
  //JS_AddIntrinsicBigInt (ctx);

  func = JS_ReadObject (ctx, code, sizeof (code), JS_READ_OBJ_BYTECODE);

  result = JS_EvalFunction (ctx, func);

  str = JS_ToCString (ctx, result);
  printf ("%s\n", str);
  JS_FreeCString (ctx, str);

  JS_FreeValue (ctx, result);

  JS_FreeContext (ctx);
  JS_FreeRuntime (rt);

  return 0;
}
