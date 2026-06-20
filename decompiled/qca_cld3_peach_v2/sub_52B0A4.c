__int64 __fastcall sub_52B0A4(int a1, int a2, int a3)
{
  int v3; // w12

  if ( (v3 & 0x10000) != 0 )
    JUMPOUT(0x5237B4);
  return dp_get_cfr_dbg_stats(a1, a2, a3);
}
