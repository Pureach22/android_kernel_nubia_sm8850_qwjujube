__int64 __fastcall dsi_ctrl_hw_22_phy_reset_config(__int64 a1, char a2)
{
  int v4; // w0
  __int64 v5; // x8
  int v6; // w9
  unsigned int v7; // w8
  unsigned int v8; // w0

  v4 = readl_relaxed_20(*(_QWORD *)(a1 + 32));
  v5 = 1LL << *(_DWORD *)(a1 + 56);
  v6 = v4 & ~(_DWORD)v5;
  v7 = v4 | v5;
  if ( (a2 & 1) != 0 )
    v8 = v6;
  else
    v8 = v7;
  return writel_relaxed_17(v8, *(unsigned int **)(a1 + 32));
}
