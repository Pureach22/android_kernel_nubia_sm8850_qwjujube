unsigned __int64 __fastcall ufs_qcom_parse_reg_info(__int64 a1, const char *a2, _QWORD *a3)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x22
  unsigned __int64 result; // x0
  _QWORD *v9; // x23
  int variable_u32_array; // w0
  _QWORD v11[6]; // [xsp+0h] [xbp-90h] BYREF
  __int16 v12; // [xsp+30h] [xbp-60h]
  _QWORD v13[11]; // [xsp+38h] [xbp-58h] BYREF

  v13[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 16);
  v12 = 0;
  v5 = *(_QWORD *)(v4 + 64);
  memset(v11, 0, sizeof(v11));
  v6 = *(_QWORD *)(v5 + 744);
  if ( !v6 )
  {
    result = dev_err(v5, "%s: non DT initialization\n", "ufs_qcom_parse_reg_info");
    v9 = nullptr;
LABEL_7:
    *a3 = v9;
    goto LABEL_8;
  }
  snprintf((char *)v11, 0x32u, "%s-supply", a2);
  memset(v13, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v6, v11, 0, 0, 0, v13) || !v13[0] )
  {
    result = dev_info(
               v5,
               "%s: Unable to find %s regulator, assuming enabled\n",
               "ufs_qcom_parse_reg_info",
               (const char *)v11);
    goto LABEL_8;
  }
  result = devm_kmalloc(v5, 24, 3520);
  if ( result )
  {
    v9 = (_QWORD *)result;
    *(_QWORD *)(result + 8) = a2;
    snprintf((char *)v11, 0x32u, "%s-max-microamp", a2);
    variable_u32_array = of_property_read_variable_u32_array(v6, v11, (char *)v9 + 20, 1, 0);
    if ( variable_u32_array < 0 )
    {
      result = dev_err(
                 v5,
                 "%s: unable to find %s err %d\n",
                 "ufs_qcom_parse_reg_info",
                 (const char *)v11,
                 variable_u32_array);
      goto LABEL_8;
    }
    result = devm_regulator_get(v5, v9[1]);
    *v9 = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
    {
      result = dev_err(v5, "%s: %s get failed, err=%d\n", "ufs_qcom_parse_reg_info", (const char *)v9[1], result);
      goto LABEL_8;
    }
    goto LABEL_7;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
