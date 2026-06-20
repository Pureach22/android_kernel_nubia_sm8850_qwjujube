__int64 __fastcall adreno_query_property_list(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 result; // x0
  int *v4; // x8
  __int64 v5; // x9
  int v6; // t1

  result = 21;
  if ( a2 )
  {
    if ( a3 >= 0x15 )
      result = 21;
    else
      result = a3;
    if ( a3 )
    {
      v4 = (int *)&adreno_property_funcs;
      v5 = result;
      do
      {
        v6 = *v4;
        v4 += 4;
        --v5;
        *a2++ = v6;
      }
      while ( v5 );
    }
    else
    {
      return 0;
    }
  }
  return result;
}
