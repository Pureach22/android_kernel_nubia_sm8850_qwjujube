unsigned __int64 __fastcall dsi_pll_pclk_recalc_rate_1(__int64 a1, __int64 a2, double a3)
{
  __int64 v3; // x19
  __int64 v4; // x5
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x20
  char v7; // w21
  int v8; // w8
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x20
  __int64 v11; // x9

  v3 = *(_QWORD *)(a1 + 24);
  if ( !v3 )
  {
    drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: DSI_PLL_%d: pll priv is null\n", -1);
    return 0;
  }
  v4 = *(_QWORD *)(v3 + 72);
  if ( v4 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_PLL_%d: returning pclk rate = %lld %ld\n",
      *(_DWORD *)(v3 + 100),
      v4,
      a2);
    return *(_QWORD *)(v3 + 72);
  }
  v6 = dsi_pll_vco_recalc_rate_1(*(_QWORD *)(a1 + 24), a3);
  v7 = readl_relaxed_18((unsigned int *)(*(_QWORD *)(v3 + 8) + 16LL));
  v8 = readl_relaxed_18((unsigned int *)(*(_QWORD *)(v3 + 8) + 20LL)) & 3;
  if ( v8 == 3 )
  {
    if ( *(_DWORD *)(v3 + 176) == 1 )
    {
      v11 = (2 * v6 * (unsigned __int128)0x2492492492492493uLL) >> 64;
      v10 = (v11 + ((2 * v6 - v11) >> 1)) >> 2;
      goto LABEL_13;
    }
    goto LABEL_12;
  }
  v9 = v7 & 0xF;
  if ( v8 == 1 )
  {
    v10 = (v6 / v9) >> 1;
    goto LABEL_13;
  }
  if ( v8 )
  {
LABEL_12:
    v10 = 0;
    goto LABEL_13;
  }
  v10 = v6 / v9;
LABEL_13:
  result = v10 / ((unsigned __int8)readl_relaxed_18((unsigned int *)(*(_QWORD *)(v3 + 8) + 16LL)) >> 4);
  *(_QWORD *)(v3 + 72) = result;
  return result;
}
