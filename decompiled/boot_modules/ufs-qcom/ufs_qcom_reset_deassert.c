__int64 __fastcall ufs_qcom_reset_deassert(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w0

  v1 = *(_QWORD *)(a1 - 184);
  v2 = readl((unsigned int *)(*(_QWORD *)v1 + 220LL));
  writel(v2 & 0xFFFFFFFD, (unsigned int *)(*(_QWORD *)v1 + 220LL));
  readl((unsigned int *)(*(_QWORD *)v1 + 220LL));
  usleep_range_state(1000, 1100, 2);
  return 0;
}
