__int64 __fastcall cam_soc_util_clk_disable_default(__int64 result, unsigned int a2)
{
  int v2; // w20
  __int64 v3; // x19

  v2 = *(_DWORD *)(result + 868) - 1;
  if ( v2 >= 0 )
  {
    v3 = result;
    do
      result = cam_soc_util_clk_disable(v3, a2, 0, (unsigned int)v2--);
    while ( v2 != -1 );
  }
  return result;
}
