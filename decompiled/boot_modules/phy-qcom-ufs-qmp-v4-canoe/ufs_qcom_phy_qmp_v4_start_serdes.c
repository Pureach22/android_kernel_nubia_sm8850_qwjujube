__int64 __fastcall ufs_qcom_phy_qmp_v4_start_serdes(__int64 a1)
{
  int v2; // w0
  __int64 result; // x0

  v2 = readl_relaxed(*(_QWORD *)(a1 + 24) + 1024LL);
  result = writel_relaxed(v2 | 1u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 1024LL));
  __dsb(0xFu);
  return result;
}
