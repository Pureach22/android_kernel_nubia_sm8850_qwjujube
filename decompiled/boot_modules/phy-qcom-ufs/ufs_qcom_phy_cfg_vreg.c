__int64 __fastcall ufs_qcom_phy_cfg_vreg(__int64 a1, __int64 a2, char a3)
{
  const char *v3; // x19
  __int64 v4; // x21
  int v8; // w0
  unsigned int v9; // w22
  int v10; // w0
  const char *v12; // x3
  unsigned int v13; // w19
  unsigned int v14; // w21

  v3 = *(const char **)a2;
  v4 = *(_QWORD *)(a2 + 8);
  if ( (int)regulator_count_voltages(v4) < 1 )
    return 0;
  if ( (a3 & 1) != 0 )
  {
    v8 = regulator_set_voltage(v4, *(unsigned int *)(a2 + 20), *(unsigned int *)(a2 + 24));
    if ( !v8 )
    {
      v9 = *(_DWORD *)(a2 + 16);
      goto LABEL_6;
    }
LABEL_9:
    v12 = v3;
    v13 = v8;
    dev_err(a1, "%s: %s set voltage failed, err=%d\n", "ufs_qcom_phy_cfg_vreg", v12, v8);
    return v13;
  }
  v8 = regulator_set_voltage(v4, 0, *(unsigned int *)(a2 + 24));
  v9 = 0;
  if ( v8 )
    goto LABEL_9;
LABEL_6:
  v10 = regulator_set_load(v4, v9);
  if ( v10 < 0 )
  {
    v14 = v10;
    dev_err(a1, "%s: %s set optimum mode(uA_load=%d) failed, err=%d\n", "ufs_qcom_phy_cfg_vreg", v3, v9, v10);
    return v14;
  }
  return 0;
}
