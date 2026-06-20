unsigned __int64 __fastcall dsi_pll_pclk_recalc_rate(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x5
  unsigned __int64 v5; // x0
  __int64 v6; // x9
  unsigned __int64 v7; // x9

  v2 = *(_QWORD *)(a1 + 24);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 72);
    if ( v3 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: DSI_PLL_%d: returning pclk rate = %lld %ld\n",
        *(_DWORD *)(v2 + 100),
        v3,
        a2);
      return *(_QWORD *)(v2 + 72);
    }
    else
    {
      v5 = dsi_pll_vco_recalc_rate(*(_QWORD *)(a1 + 24));
      if ( *(_DWORD *)(v2 + 176) )
      {
        v6 = (2 * v5 * (unsigned __int128)0x2492492492492493uLL) >> 64;
        return ((v6 + ((2 * v5 - v6) >> 1)) >> 2)
             / ((unsigned __int8)readl_relaxed_16((unsigned int *)(*(_QWORD *)(v2 + 8) + 16LL)) >> 4);
      }
      else
      {
        v7 = v5 / (readl_relaxed_16((unsigned int *)(*(_QWORD *)(v2 + 8) + 16LL)) & 0xFuLL);
        return (v7 >> 1) / ((unsigned __int8)readl_relaxed_16((unsigned int *)(*(_QWORD *)(v2 + 8) + 16LL)) >> 4);
      }
    }
  }
  else
  {
    drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: DSI_PLL_%d: pll priv is null\n", -1);
    return 0;
  }
}
