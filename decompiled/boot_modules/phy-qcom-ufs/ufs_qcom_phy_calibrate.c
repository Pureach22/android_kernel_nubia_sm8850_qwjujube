__int64 __fastcall ufs_qcom_phy_calibrate(_QWORD *a1, __int64 a2, int a3, __int64 a4, int a5, char a6)
{
  __int64 v7; // x20
  __int64 v9; // x22
  __int64 v11; // x24
  int v13; // w0
  unsigned int *v14; // x25
  unsigned int *v15; // x21
  int v16; // w0
  void (__fastcall *v17)(_QWORD); // x8
  __int64 (__fastcall *v18)(_QWORD); // x8
  unsigned int v20; // w19

  v7 = a1[2];
  LODWORD(v9) = a5;
  LODWORD(v11) = a3;
  v13 = reset_control_assert(a1[58]);
  if ( v13 )
  {
    v20 = v13;
    dev_err(v7, "Failed to assert UFS PHY reset %d\n", v13);
    return v20;
  }
  if ( !a2 )
  {
    dev_err(v7, "%s: tbl_A is NULL\n", "ufs_qcom_phy_calibrate");
    return 22;
  }
  if ( (int)v11 >= 1 )
  {
    v11 = (unsigned int)v11;
    v14 = (unsigned int *)(a2 + 4);
    do
    {
      writel_relaxed(*v14, (unsigned int *)(a1[3] + *(v14 - 1)));
      --v11;
      v14 += 2;
    }
    while ( v11 );
  }
  if ( (a6 & 1) != 0 )
  {
    if ( a4 )
    {
      if ( (int)v9 >= 1 )
      {
        v9 = (unsigned int)v9;
        v15 = (unsigned int *)(a4 + 4);
        do
        {
          writel_relaxed(*v15, (unsigned int *)(a1[3] + *(v15 - 1)));
          --v9;
          v15 += 2;
        }
        while ( v9 );
      }
      goto LABEL_11;
    }
    dev_err(v7, "%s: tbl_B is NULL\n", "ufs_qcom_phy_calibrate");
    return 22;
  }
LABEL_11:
  __dsb(0xFu);
  v16 = reset_control_deassert(a1[58]);
  if ( v16 )
    dev_err(v7, "Failed to deassert UFS PHY reset %d\n", v16);
  v17 = *(void (__fastcall **)(_QWORD))(a1[52] + 8LL);
  if ( !v17 )
  {
    dev_err(a1[2], "%s: start_serdes() callback is not supported\n", "ufs_qcom_phy_start_serdes");
    return 4294967201LL;
  }
  if ( *((_DWORD *)v17 - 1) != -36396358 )
    __break(0x8228u);
  v17(a1);
  v18 = *(__int64 (__fastcall **)(_QWORD))(a1[52] + 16LL);
  if ( !v18 )
  {
    dev_err(a1[2], "%s: is_physical_coding_sublayer_ready() callback is not supported\n", "ufs_qcom_phy_is_pcs_ready");
    return 4294967201LL;
  }
  if ( *((_DWORD *)v18 - 1) != 834462215 )
    __break(0x8228u);
  return v18(a1);
}
