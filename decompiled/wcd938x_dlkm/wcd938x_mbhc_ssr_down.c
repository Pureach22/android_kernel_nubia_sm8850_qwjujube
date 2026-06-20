__int64 __fastcall wcd938x_mbhc_ssr_down(__int64 result, __int64 a2)
{
  __int64 v2; // x19

  if ( result )
  {
    if ( a2 )
    {
      v2 = result;
      wcd938x_mbhc_hs_detect_exit(a2);
      return wcd_mbhc_deinit(v2);
    }
  }
  return result;
}
