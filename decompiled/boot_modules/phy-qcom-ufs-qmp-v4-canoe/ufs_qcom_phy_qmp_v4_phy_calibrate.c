__int64 ufs_qcom_phy_qmp_v4_phy_calibrate()
{
  __int64 ufs_qcom_phy; // x19
  __int64 v1; // x20
  unsigned int v2; // w0
  int v3; // w22
  int v4; // w21
  __int64 v5; // x21
  unsigned int v6; // w8
  unsigned int i; // w22
  _DWORD *v8; // x9
  int v9; // w0
  const char *v11; // x1
  unsigned int v12; // w19

  ufs_qcom_phy = get_ufs_qcom_phy();
  v1 = *(_QWORD *)(ufs_qcom_phy + 16);
  v2 = reset_control_assert(*(_QWORD *)(ufs_qcom_phy + 464));
  if ( !v2 )
  {
    v3 = *(_DWORD *)(ufs_qcom_phy + 428);
    if ( (unsigned int)(v3 - 3) <= 0xFFFFFFFD )
    {
      dev_err(v1, "%s: unsupported submode.\n", "ufs_qcom_phy_qmp_v4_phy_calibrate");
      return 4294967201LL;
    }
    v4 = *(_DWORD *)(ufs_qcom_phy + 424);
    writel_relaxed(1, *(_QWORD *)(ufs_qcom_phy + 24) + 1032LL);
    __dsb(0xEu);
    ufs_qcom_phy_write_tbl(ufs_qcom_phy, &phy_cal_table_rate_A_g5, 106);
    if ( v3 == 1 )
      ufs_qcom_phy_write_tbl(ufs_qcom_phy, &phy_cal_table_rate_A_g4, 2);
    if ( *(_DWORD *)(ufs_qcom_phy + 352) == 2 )
    {
      ufs_qcom_phy_write_tbl(ufs_qcom_phy, &phy_cal_table_2nd_lane, 1);
      if ( v4 != 13 )
      {
LABEL_7:
        v5 = *(_QWORD *)(ufs_qcom_phy + 448);
        if ( !v5 )
          goto LABEL_18;
        goto LABEL_11;
      }
    }
    else if ( v4 != 13 )
    {
      goto LABEL_7;
    }
    ufs_qcom_phy_write_tbl(ufs_qcom_phy, &phy_cal_table_rate_B, 1);
    v5 = *(_QWORD *)(ufs_qcom_phy + 448);
    if ( !v5 )
    {
LABEL_18:
      writel_relaxed(0, *(_QWORD *)(ufs_qcom_phy + 24) + 1032LL);
      __dsb(0xEu);
      *(_BYTE *)(ufs_qcom_phy + 460) = 0;
      v2 = reset_control_deassert(*(_QWORD *)(ufs_qcom_phy + 464));
      if ( !v2 )
      {
        v9 = readl_relaxed(*(_QWORD *)(ufs_qcom_phy + 24) + 1024LL);
        writel_relaxed(v9 | 1u, *(_QWORD *)(ufs_qcom_phy + 24) + 1024LL);
        __dsb(0xFu);
        return ufs_qcom_phy_qmp_v4_is_pcs_ready(ufs_qcom_phy);
      }
      v11 = "Failed to deassert UFS PHY reset %d\n";
      goto LABEL_23;
    }
LABEL_11:
    v6 = *(_DWORD *)(ufs_qcom_phy + 440);
    if ( v6 )
    {
      for ( i = 0; i < v6; ++i )
      {
        v8 = (_DWORD *)(v5 + 12LL * (int)i);
        if ( !*v8 || *v8 == *(_DWORD *)(ufs_qcom_phy + 432) )
        {
          writel_relaxed((unsigned int)v8[2], *(_QWORD *)(ufs_qcom_phy + 24) + (unsigned int)v8[1]);
          v6 = *(_DWORD *)(ufs_qcom_phy + 440);
        }
      }
    }
    goto LABEL_18;
  }
  v11 = "Failed to assert UFS PHY reset %d\n";
LABEL_23:
  v12 = v2;
  dev_err(v1, v11, v2);
  return v12;
}
