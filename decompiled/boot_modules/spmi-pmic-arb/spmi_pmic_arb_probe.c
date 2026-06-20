__int64 __fastcall spmi_pmic_arb_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 resource_byname; // x0
  __int64 *v5; // x21
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x22
  unsigned int v10; // w21
  char **v11; // x8
  __int64 result; // x0
  unsigned int v13; // w8
  char *v14; // x8
  unsigned int variable_u32_array; // w0
  __int64 v16; // x0
  const char *v17; // x1
  const char *v18; // x1
  unsigned int v19; // w20
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v2 = devm_kmalloc(a1 + 16, 112, 3520);
  if ( !v2 )
    goto LABEL_6;
  v3 = v2;
  resource_byname = platform_get_resource_byname(a1, 512, "core");
  if ( !resource_byname )
  {
    result = 4294967274LL;
    goto LABEL_20;
  }
  v5 = (__int64 *)resource_byname;
  v6 = devm_ioremap(a1 + 16);
  if ( !v6 )
  {
LABEL_6:
    result = 4294967284LL;
    goto LABEL_20;
  }
  v8 = *v5;
  v7 = v5[1];
  v9 = v6;
  *(_QWORD *)(a1 + 168) = v3;
  *(_QWORD *)(v3 + 32) = v7 - v8 + 1;
  v10 = readl_relaxed();
  if ( v10 > 0x2000FFFF )
  {
    v13 = v10 >> 28;
    if ( v10 >> 28 > 2 )
    {
      if ( v13 > 4 )
      {
        if ( v13 > 6 )
        {
          if ( (v10 & 0x80000000) != 0 )
            v11 = &pmic_arb_v8;
          else
            v11 = &pmic_arb_v7;
        }
        else
        {
          v11 = &pmic_arb_v5;
        }
      }
      else
      {
        v11 = &pmic_arb_v3;
      }
    }
    else
    {
      v11 = &pmic_arb_v2;
    }
  }
  else
  {
    v11 = &pmic_arb_v1;
  }
  *(_QWORD *)(v3 + 56) = v11;
  v14 = v11[1];
  if ( *((_DWORD *)v14 - 1) != -1647921489 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64))v14)(a1, v9);
  if ( !(_DWORD)result )
  {
    dev_info(a1 + 16, "PMIC arbiter version %s (0x%x)\n", **(const char ***)(v3 + 56), v10);
    variable_u32_array = of_property_read_variable_u32_array(
                           *(_QWORD *)(a1 + 760),
                           "qcom,channel",
                           (char *)v20 + 4,
                           1,
                           0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v17 = "channel unspecified.\n";
    }
    else
    {
      if ( HIDWORD(v20[0]) >= 6 )
      {
        v18 = "invalid channel (%u) specified.\n";
        goto LABEL_31;
      }
      v16 = *(_QWORD *)(a1 + 760);
      *(_BYTE *)(v3 + 48) = BYTE4(v20[0]);
      variable_u32_array = of_property_read_variable_u32_array(v16, "qcom,ee", v20, 1, 0);
      if ( (variable_u32_array & 0x80000000) == 0 )
      {
        if ( LODWORD(v20[0]) < 6 )
        {
          *(_BYTE *)(v3 + 49) = v20[0];
          result = spmi_pmic_arb_register_buses(v3, a1);
          goto LABEL_20;
        }
        v18 = "invalid EE (%u) specified\n";
LABEL_31:
        dev_err(a1 + 16, v18);
        result = 4294967274LL;
        goto LABEL_20;
      }
      v17 = "EE unspecified.\n";
    }
    v19 = variable_u32_array;
    dev_err(a1 + 16, v17);
    result = v19;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
