unsigned __int64 __fastcall fastrpc_register_wakeup_source(const char **a1, const char *a2, unsigned __int64 *a3)
{
  unsigned __int64 result; // x0
  const char *v7; // x2

  result = wakeup_source_register(0);
  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    *a3 = result;
  }
  else
  {
    v7 = a1[14];
    if ( !v7 )
      v7 = *a1;
    return dev_err(a1, "wakeup_source_register failed for dev %s, client %s with err %ld\n", v7, a2, result);
  }
  return result;
}
