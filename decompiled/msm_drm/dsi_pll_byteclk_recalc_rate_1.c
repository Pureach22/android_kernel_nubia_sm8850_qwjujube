unsigned __int64 __fastcall dsi_pll_byteclk_recalc_rate_1(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x5
  unsigned __int64 result; // x0
  unsigned __int64 v5; // x20
  double v6; // d0
  unsigned __int64 v7; // x8
  __int64 v8; // x9
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9

  v2 = *(_QWORD *)(a1 + 24);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 64);
    if ( v3 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: DSI_PLL_%d: returning byte clk rate = %lld %ld\n",
        *(_DWORD *)(v2 + 100),
        v3,
        a2);
      return *(_QWORD *)(v2 + 64);
    }
    else
    {
      v5 = dsi_pll_vco_recalc_rate_1(*(_QWORD *)(a1 + 24));
      v7 = v5 / (readl_relaxed_18(*(_QWORD *)(v2 + 8) + 16LL, v6) & 0xFuLL);
      v8 = (v7 * (unsigned __int128)0x2492492492492493uLL) >> 64;
      v9 = v7 - v8;
      v10 = v7 >> 3;
      v11 = (v8 + (v9 >> 1)) >> 2;
      if ( *(_DWORD *)(v2 + 176) )
        result = v11;
      else
        result = v10;
      *(_QWORD *)(v2 + 64) = result;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: DSI_PLL_%d: pll priv is null\n", -1);
    return 0;
  }
  return result;
}
