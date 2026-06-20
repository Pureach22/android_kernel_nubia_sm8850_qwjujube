__int64 __fastcall ufs_qcom_phy_qmp_v4_is_pcs_ready(__int64 a1)
{
  __int64 v2; // x20
  char v3; // w0
  __int64 v4; // x20

  v2 = ktime_get();
  v3 = readl(*(_QWORD *)(a1 + 24) + 1448LL);
  if ( (v3 & 1) != 0 )
  {
LABEL_5:
    if ( (v3 & 1) == 0 )
    {
LABEL_9:
      dev_err(*(_QWORD *)(a1 + 16), "%s: poll for pcs failed err = %d\n", "ufs_qcom_phy_qmp_v4_is_pcs_ready", -110);
      return 4294967186LL;
    }
  }
  else
  {
    v4 = v2 + 1000000000;
    while ( ktime_get() <= v4 )
    {
      usleep_range_state(3, 10, 2);
      __yield();
      v3 = readl(*(_QWORD *)(a1 + 24) + 1448LL);
      if ( (v3 & 1) != 0 )
        goto LABEL_5;
    }
    if ( (readl(*(_QWORD *)(a1 + 24) + 1448LL) & 1) == 0 )
      goto LABEL_9;
  }
  return 0;
}
