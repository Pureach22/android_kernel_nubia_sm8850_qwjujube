__int64 __fastcall ufs_qcom_phy_qmp_v4_ctrl_rx_linecfg(__int64 a1, char a2)
{
  int v4; // w10
  int v5; // w8
  __int64 result; // x0

  v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 1404LL)) & 0xFFFFFFFD;
  if ( (a2 & 1) != 0 )
    v5 = 0;
  else
    v5 = 2;
  result = writel_relaxed(v4 | (unsigned int)v5, (unsigned int *)(*(_QWORD *)(a1 + 24) + 1404LL));
  __dsb(0xFu);
  return result;
}
