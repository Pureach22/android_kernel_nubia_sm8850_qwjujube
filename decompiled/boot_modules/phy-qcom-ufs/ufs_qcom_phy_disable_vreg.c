__int64 __fastcall ufs_qcom_phy_disable_vreg(__int64 a1, __int64 a2)
{
  int v4; // w0
  const char *v6; // x3
  unsigned int v7; // w19

  if ( !a2 )
    return 0;
  if ( *(_BYTE *)(a2 + 28) != 1 )
    return 0;
  v4 = regulator_disable(*(_QWORD *)(a2 + 8));
  if ( v4 )
  {
    v6 = *(const char **)a2;
    v7 = v4;
    dev_err(a1, "%s: %s disable failed, err=%d\n", "ufs_qcom_phy_disable_vreg", v6, v4);
    return v7;
  }
  else
  {
    ufs_qcom_phy_cfg_vreg(a1, a2, 0);
    *(_BYTE *)(a2 + 28) = 0;
    return 0;
  }
}
