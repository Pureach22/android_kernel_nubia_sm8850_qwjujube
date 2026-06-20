__int64 __fastcall dsi_pll_program_slave(__int64 a1, char a2)
{
  int v2; // w8
  unsigned int v4; // w19
  int v5; // w3

  v2 = *(_DWORD *)(a1 + 80);
  if ( v2 == 2 )
  {
    v4 = dsi_pll_4nm_program_slave(a1, a2 & 1);
    if ( !v4 )
      return v4;
    goto LABEL_4;
  }
  if ( v2 != 3 )
  {
    v4 = -22;
    if ( a1 )
      goto LABEL_5;
    goto LABEL_9;
  }
  v4 = dsi_pll_5nm_program_slave(a1, a2 & 1);
  if ( v4 )
  {
LABEL_4:
    if ( a1 )
    {
LABEL_5:
      v5 = *(_DWORD *)(a1 + 100);
LABEL_10:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_PLL_%d: %s failed rc=%d\n",
        v5,
        "dsi_pll_program_slave",
        v4);
      return v4;
    }
LABEL_9:
    v5 = -1;
    goto LABEL_10;
  }
  return v4;
}
