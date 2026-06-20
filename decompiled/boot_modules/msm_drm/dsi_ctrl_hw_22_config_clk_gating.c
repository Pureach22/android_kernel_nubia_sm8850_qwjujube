__int64 __fastcall dsi_ctrl_hw_22_config_clk_gating(__int64 a1, char a2, char a3)
{
  int v6; // w0
  int v7; // w8
  int v8; // w9
  int v9; // w9
  int v10; // w9
  int v11; // w8
  unsigned int v12; // w0

  v6 = readl_relaxed_20(*(unsigned int **)(a1 + 32));
  if ( (a3 & 1) == 0 )
  {
    v7 = 0;
    if ( (a3 & 2) == 0 )
      goto LABEL_12;
    goto LABEL_8;
  }
  if ( *(_DWORD *)(a1 + 56) )
    v7 = 64;
  else
    v7 = 32;
  if ( (a3 & 2) != 0 )
  {
LABEL_8:
    if ( *(_DWORD *)(a1 + 56) )
      v8 = 256;
    else
      v8 = 128;
    v7 |= v8;
  }
LABEL_12:
  if ( (a3 & 4) != 0 )
  {
    if ( *(_DWORD *)(a1 + 56) )
      v9 = 1024;
    else
      v9 = 512;
    v7 |= v9;
  }
  v10 = v7 | v6;
  v11 = v6 & ~v7;
  if ( (a2 & 1) != 0 )
    v12 = v10;
  else
    v12 = v11;
  return writel_relaxed_17(v12, *(unsigned int **)(a1 + 32));
}
