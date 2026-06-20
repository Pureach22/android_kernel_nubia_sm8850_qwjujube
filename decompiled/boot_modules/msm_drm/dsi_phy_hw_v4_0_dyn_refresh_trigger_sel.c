__int64 __fastcall dsi_phy_hw_v4_0_dyn_refresh_trigger_sel(__int64 result, char a2)
{
  __int64 v2; // x19
  int v3; // w0

  if ( (a2 & 1) != 0 )
  {
    v2 = result;
    v3 = readl_relaxed_13(*(unsigned int **)(result + 16));
    return writel_relaxed_10(v3 | 0x20000u, *(unsigned int **)(v2 + 16));
  }
  return result;
}
