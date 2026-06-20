__int64 __fastcall ufs_qcom_phy_init_vreg(__int64 a1, __int64 a2, const char *a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  int v8; // w8
  __int64 result; // x0
  unsigned __int64 v10; // x0
  int variable_u32_array; // w0
  int v12; // w8
  __int64 v13; // x19
  __int64 v14; // x8
  _DWORD *v15; // x19
  char s[8]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v17; // [xsp+10h] [xbp-70h]
  __int64 v18; // [xsp+18h] [xbp-68h]
  __int64 v19; // [xsp+20h] [xbp-60h]
  _QWORD v20[11]; // [xsp+28h] [xbp-58h] BYREF

  v20[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 744);
  v18 = 0;
  v19 = 0;
  *(_QWORD *)s = 0;
  v17 = 0;
  if ( !v6
    || (snprintf(s, 0x20u, "%s-supply", a3),
        v7 = *(_QWORD *)(a1 + 744),
        memset(v20, 0, 80),
        v8 = _of_parse_phandle_with_args(v7, s, 0, 0, 0, v20),
        result = 4294967235LL,
        !v8)
    && v20[0] )
  {
    *(_QWORD *)a2 = a3;
    v10 = devm_regulator_get(a1, a3);
    *(_QWORD *)(a2 + 8) = v10;
    if ( v10 >= 0xFFFFFFFFFFFFF001LL )
    {
      v13 = v10;
      dev_err(a1, "failed to get %s, %d\n", a3, v10);
      goto LABEL_25;
    }
    if ( *(_QWORD *)(a1 + 744) )
    {
      snprintf(s, 0x20u, "%s-max-microamp", a3);
      variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), s, a2 + 16, 1, 0);
      v12 = variable_u32_array & (variable_u32_array >> 31);
      if ( v12 == -22 )
      {
        if ( *(_DWORD *)(a2 + 16) && (int)regulator_count_voltages(*(_QWORD *)(a2 + 8)) >= 1 )
        {
          dev_err(a1, "%s: %s is mandatory\n", "ufs_qcom_phy_init_vreg", s);
          result = 4294967274LL;
          goto LABEL_23;
        }
      }
      else if ( v12 )
      {
        v13 = variable_u32_array & (unsigned int)(variable_u32_array >> 31);
        dev_err(a1, "%s: failed to read %s\n", "ufs_qcom_phy_init_vreg", s);
LABEL_25:
        result = v13;
        goto LABEL_23;
      }
    }
    result = strcmp(a3, "vdda-pll");
    if ( !(_DWORD)result )
    {
      v14 = 7730941134000000LL;
      goto LABEL_22;
    }
    if ( !strcmp(a3, "vdda-phy") )
    {
      *(_QWORD *)(a2 + 20) = 3972844749680000LL;
      v15 = (_DWORD *)(a2 + 20);
      snprintf(s, 0x20u, "%s-min-microvolt", a3);
      of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), s, v15, 1, 0);
      if ( (unsigned int)(*v15 - 925001) <= 0xFFFF5036 )
      {
        dev_err(a1, "%s: ufs vdda-phy invalid min_uV=%duV\n", "ufs_qcom_phy_init_vreg", *v15);
        result = 0;
        *v15 = 880000;
        goto LABEL_23;
      }
    }
    else
    {
      result = strcmp(a3, "vddp-ref-clk");
      if ( !(_DWORD)result )
      {
        v14 = 5153960756400000LL;
        goto LABEL_22;
      }
      result = strcmp(a3, "vdda-qref");
      if ( !(_DWORD)result )
      {
        v14 = 0xDEA80000D6D80LL;
        goto LABEL_22;
      }
      result = strcmp(a3, "vdda-refgen");
      if ( !(_DWORD)result )
      {
        v14 = 3951369913200000LL;
LABEL_22:
        *(_QWORD *)(a2 + 20) = v14;
        goto LABEL_23;
      }
    }
    result = 0;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
