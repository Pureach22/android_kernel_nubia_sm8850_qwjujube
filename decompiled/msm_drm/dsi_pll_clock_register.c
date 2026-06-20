__int64 __fastcall dsi_pll_clock_register(__int64 a1, __int64 a2)
{
  int v2; // w8
  unsigned int v4; // w20

  v2 = *(_DWORD *)(a2 + 80);
  if ( v2 )
  {
    if ( v2 == 2 )
    {
      v4 = dsi_pll_clock_register_4nm(a1, a2);
      if ( !v4 )
        return v4;
    }
    else if ( v2 == 3 )
    {
      v4 = ((__int64 (__fastcall *)(__int64, __int64))dsi_pll_clock_register_5nm)(a1, a2);
      if ( !v4 )
        return v4;
    }
    else
    {
      v4 = -22;
    }
  }
  else
  {
    v4 = dsi_pll_clock_register_3nm(a1, a2);
    if ( !v4 )
      return v4;
  }
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: DSI_PLL_%d: clock register failed rc=%d\n",
    *(_DWORD *)(a2 + 100),
    v4);
  return v4;
}
