__int64 __fastcall dsi_pll_vco_recalc_rate_1(__int64 a1, double a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v5; // x23
  double v6; // d0
  int v7; // w19
  double v8; // d0
  int v9; // w19
  double v10; // d0
  unsigned __int64 v11; // x19
  double v12; // d0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 144);
  if ( v2 )
  {
    v3 = *(_QWORD *)(a1 + 40);
    v5 = (unsigned __int8)readl_relaxed_18(*(_QWORD *)a1 + 224LL, a2);
    v7 = readl_relaxed_18(*(_QWORD *)a1 + 228LL, v6);
    v9 = ((unsigned __int8)readl_relaxed_18(*(_QWORD *)a1 + 232LL, v8) << 8) | v7;
    v11 = ((2 * v3 * (unsigned __int64)(v9 | ((unsigned __int8)(readl_relaxed_18(*(_QWORD *)a1 + 236LL, v10) & 3) << 16))) >> *(_DWORD *)(v2 + 28))
        + 2 * v3 * v5;
    result = v11 >> readl_relaxed_18(*(_QWORD *)a1 + 340LL, v12);
    *(_QWORD *)(a1 + 56) = result;
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
  return result;
}
