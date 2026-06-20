__int64 __fastcall ufs_qcom_phy_qrbtc_sdm845_start_serdes(__int64 a1)
{
  int v2; // w0
  __int64 result; // x0

  writel_relaxed(1, *(_QWORD *)(a1 + 24) + 3076LL);
  v2 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 3072LL));
  result = writel_relaxed(v2 | 1u, *(_QWORD *)(a1 + 24) + 3072LL);
  __dsb(0xFu);
  return result;
}
