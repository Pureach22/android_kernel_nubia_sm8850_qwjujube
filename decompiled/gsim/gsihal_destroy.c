__int64 __fastcall gsihal_destroy(long double a1)
{
  __int64 result; // x0

  result = kfree(gsihal_ctx, a1);
  gsihal_ctx = 0;
  return result;
}
