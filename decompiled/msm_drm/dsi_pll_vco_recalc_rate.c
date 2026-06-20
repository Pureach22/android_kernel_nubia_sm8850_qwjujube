__int64 __fastcall dsi_pll_vco_recalc_rate(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v4; // x23
  int v5; // w19
  int v6; // w19
  unsigned __int64 v7; // x19

  v1 = *(_QWORD *)(a1 + 144);
  if ( v1 )
  {
    v2 = *(_QWORD *)(a1 + 40);
    v4 = (unsigned __int8)readl_relaxed_16(*(_QWORD *)a1 + 224LL);
    v5 = readl_relaxed_16(*(_QWORD *)a1 + 228LL);
    v6 = ((unsigned __int8)readl_relaxed_16(*(_QWORD *)a1 + 232LL) << 8) | v5;
    v7 = ((2 * v2 * (unsigned __int64)(v6 | ((unsigned __int8)(readl_relaxed_16(*(_QWORD *)a1 + 236LL) & 3) << 16))) >> *(_DWORD *)(v1 + 28))
       + 2 * v2 * v4;
    return v7 >> readl_relaxed_16(*(_QWORD *)a1 + 340LL);
  }
  else
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll configuration not found\n",
      *(_DWORD *)(a1 + 100));
    return -22;
  }
}
