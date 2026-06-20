__int64 __fastcall dsi_phy_hw_v5_0_dyn_refresh_helper(__int64 result, int a2)
{
  __int64 v2; // x19
  char v3; // w20
  int v4; // w0
  int v5; // w0
  int v6; // w0
  int v7; // w0
  int v8; // w0

  v2 = result;
  if ( !a2 )
  {
    v4 = readl_relaxed_14(*(unsigned int **)(result + 16));
    result = writel_relaxed_11(v4 & 0xFFFCDEFE, *(unsigned int **)(v2 + 16));
    __dsb(0xEu);
    return result;
  }
  v3 = a2;
  if ( (a2 & 2) != 0 )
  {
    v5 = readl_relaxed_14(*(unsigned int **)(result + 16));
    result = writel_relaxed_11(v5 | 0x2000u, *(unsigned int **)(v2 + 16));
    if ( (v3 & 4) == 0 )
    {
LABEL_4:
      if ( (v3 & 0x10) == 0 )
        goto LABEL_5;
LABEL_10:
      v7 = readl_relaxed_14(*(unsigned int **)(v2 + 16));
      result = writel_relaxed_11(v7 | 1u, *(unsigned int **)(v2 + 16));
      if ( (v3 & 8) == 0 )
        return result;
      goto LABEL_11;
    }
  }
  else if ( (a2 & 4) == 0 )
  {
    goto LABEL_4;
  }
  v6 = readl_relaxed_14(*(unsigned int **)(v2 + 16));
  result = writel_relaxed_11(v6 | 0x10000u, *(unsigned int **)(v2 + 16));
  if ( (v3 & 0x10) != 0 )
    goto LABEL_10;
LABEL_5:
  if ( (v3 & 8) != 0 )
  {
LABEL_11:
    v8 = readl_relaxed_14(*(unsigned int **)(v2 + 16));
    result = writel_relaxed_11(v8 | 0x100u, *(unsigned int **)(v2 + 16));
    __dsb(0xEu);
  }
  return result;
}
