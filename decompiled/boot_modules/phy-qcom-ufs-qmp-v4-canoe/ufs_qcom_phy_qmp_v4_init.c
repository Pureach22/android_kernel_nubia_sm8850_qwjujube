__int64 __fastcall ufs_qcom_phy_qmp_v4_init(__int64 a1)
{
  __int64 v1; // x19
  unsigned int inited; // w0
  __int64 v4; // x8
  const char *v5; // x1
  unsigned int v6; // w19

  v1 = *(_QWORD *)(a1 + 152);
  inited = ufs_qcom_phy_init_clks(v1);
  if ( inited )
  {
    v4 = *(_QWORD *)(v1 + 16);
    v5 = "%s: ufs_qcom_phy_init_clks() failed %d\n";
LABEL_9:
    v6 = inited;
    dev_err(v4, v5, "ufs_qcom_phy_qmp_v4_init", inited);
    return v6;
  }
  inited = ufs_qcom_phy_init_vregulators(v1);
  if ( inited )
  {
    v4 = *(_QWORD *)(v1 + 16);
    v5 = "%s: ufs_qcom_phy_init_vregulators() failed %d\n";
    goto LABEL_9;
  }
  ufs_qcom_phy_get_reset(v1);
  if ( !*(_QWORD *)(v1 + 264) )
    pm_runtime_enable(*(_QWORD *)(v1 + 16));
  return 0;
}
