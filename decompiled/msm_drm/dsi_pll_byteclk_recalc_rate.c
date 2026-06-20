unsigned __int64 __fastcall dsi_pll_byteclk_recalc_rate(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x5
  unsigned __int64 v5; // x20
  unsigned __int64 v6; // x8

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
      v5 = dsi_pll_vco_recalc_rate(*(_QWORD *)(a1 + 24));
      v6 = v5 / (readl_relaxed_16(*(_QWORD *)(v2 + 8) + 16LL) & 0xFuLL);
      if ( *(_DWORD *)(v2 + 176) )
        return v6 / 7;
      else
        return v6 >> 3;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: DSI_PLL_%d: pll priv is null\n", -1);
    return 0;
  }
}
