__int64 __fastcall ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x20

  if ( *(_DWORD *)(a1 + 456) == -1342177279 )
    return 0;
  v4 = ktime_get(a1, a2);
  v5 = readl(*(_QWORD *)(a1 + 24) + 188LL);
  if ( (_DWORD)v5 == 61 )
    return 0;
  v7 = v4 + 1000000000;
  while ( ktime_get(v5, v6) <= v7 )
  {
    usleep_range_state(3, 10, 2);
    __yield();
    v5 = readl(*(_QWORD *)(a1 + 24) + 188LL);
    if ( (_DWORD)v5 == 61 )
      return 0;
  }
  if ( (unsigned int)readl(*(_QWORD *)(a1 + 24) + 188LL) == 61 )
    return 0;
  dev_err(*(_QWORD *)(a1 + 16), "%s: poll for pcs failed err = %d\n", "ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready", -110);
  return 4294967186LL;
}
