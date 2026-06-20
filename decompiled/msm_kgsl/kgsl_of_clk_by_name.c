__int64 __fastcall kgsl_of_clk_by_name(__int64 a1, int a2, char *s2)
{
  __int64 result; // x0
  __int64 v6; // x20
  unsigned __int64 v7; // x21
  __int64 i; // x22

  result = 0;
  if ( a1 && a2 >= 1 )
  {
    v6 = 0;
    v7 = (unsigned int)a2;
    for ( i = a1 + 8; strcmp(*(const char **)(i - 8), s2); i += 16 )
    {
      if ( ++v6 >= v7 )
        return 0;
    }
    return *(_QWORD *)i;
  }
  return result;
}
