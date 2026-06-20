__int64 __fastcall msm_dss_put_clk(__int64 result, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 *v4; // x19
  bool v5; // cc

  v2 = (unsigned int)(a2 - 1);
  if ( a2 - 1 >= 0 )
  {
    v3 = v2 + 1;
    v4 = (__int64 *)(result + 120LL * (unsigned int)v2);
    do
    {
      result = *v4;
      if ( *v4 )
        result = clk_put(result);
      v5 = v3-- <= 1;
      *v4 = 0;
      v4 -= 15;
    }
    while ( !v5 );
  }
  return result;
}
