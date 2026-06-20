__int64 __fastcall wcd938x_slave_unbind(__int64 result)
{
  __int64 v1; // x19

  if ( result )
    v1 = result - 72;
  else
    v1 = 0;
  if ( !v1 || !*(_QWORD *)(v1 + 224) )
  {
    result = __ratelimit(&wcd938x_slave_unbind__rs, "wcd938x_slave_unbind");
    if ( (_DWORD)result )
      return dev_err(v1 + 72, "%s: wcd938x_slave is NULL\n", "wcd938x_slave_unbind");
  }
  return result;
}
