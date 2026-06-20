__int64 __fastcall ufs_qcom_phy_qmp_v4_tx_hs_equalizer_config(__int64 a1)
{
  __int64 result; // x0

  writel_relaxed(0x48u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 1656LL));
  result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 1656LL));
  *(_BYTE *)(a1 + 460) = 1;
  return result;
}
