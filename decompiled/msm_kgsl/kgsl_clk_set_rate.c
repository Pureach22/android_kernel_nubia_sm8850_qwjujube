__int64 __fastcall kgsl_clk_set_rate(__int64 a1, int a2, char *s2, __int64 a4)
{
  __int64 result; // x0
  __int64 v8; // x21
  _QWORD *i; // x22

  result = 4294967277LL;
  if ( a1 && a2 >= 1 )
  {
    v8 = (unsigned int)a2;
    for ( i = (_QWORD *)(a1 + 8); strcmp((const char *)*(i - 1), s2); i += 2 )
    {
      if ( !--v8 )
        return 4294967277LL;
    }
    if ( *i )
      return clk_set_rate(*i, a4);
    return 4294967277LL;
  }
  return result;
}
