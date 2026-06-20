__int64 __fastcall ufs_qcom_phy_qmp_v4_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x8

  v2 = devm_kmalloc(a1 + 16, 488, 3520);
  if ( !v2 )
    return 4294967284LL;
  v3 = v2;
  v4 = ufs_qcom_phy_generic_probe(a1, v2, ufs_qcom_phy_qmp_v4_phy_ops, &phy_v4_ops);
  if ( v4 )
  {
    v5 = v4;
    *(_QWORD *)(v5 + 152) = v3;
    strcpy((char *)(v3 + 366), "ufs_phy_qmp_v4_canoe");
    return 0;
  }
  else
  {
    dev_err(a1 + 16, "%s: ufs_qcom_phy_generic_probe() failed\n", "ufs_qcom_phy_qmp_v4_probe");
    return 4294967291LL;
  }
}
