__int64 __fastcall msm_cdc_parse_supplies(__int64 a1, __int64 a2, const char *a3, int a4, char a5)
{
  __int64 v7; // x21
  char v8; // w24
  __int64 v9; // x27
  _BYTE *v10; // x28
  unsigned int v11; // w0
  const char *v12; // x25
  __int64 v13; // x0
  unsigned int *property; // x0
  unsigned int v15; // w0
  bool v17; // w8
  bool v18; // nf
  const char *v19; // x3
  int v20; // w4
  int v21; // w5
  bool v22; // zf
  int v23; // w6
  int v24; // w7
  int v25; // w9
  int v26; // w8
  unsigned int v27; // w26
  const char *v29; // x3
  const char *v30; // [xsp+10h] [xbp-90h] BYREF
  __int64 v31; // [xsp+18h] [xbp-88h] BYREF
  _QWORD s[5]; // [xsp+20h] [xbp-80h] BYREF
  _QWORD v33[11]; // [xsp+48h] [xbp-58h] BYREF

  v33[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = nullptr;
  if ( a4 < 1 )
  {
LABEL_22:
    v27 = 0;
  }
  else
  {
    v7 = 0;
    v8 = a5 & 1;
    v9 = (unsigned int)a4;
    v10 = (_BYTE *)(a2 + 22);
    while ( 1 )
    {
      v11 = of_property_read_string_helper(*(_QWORD *)(a1 + 744), a3, &v30, 1, (unsigned int)v7);
      if ( (v11 & 0x80000000) != 0 )
      {
        v27 = v11;
        dev_err(a1, "%s: read string %s[%d] error (%d)\n", "msm_cdc_parse_supplies", a3, v7, v11);
        goto LABEL_23;
      }
      v12 = v30;
      v31 = 0;
      memset(s, 0, sizeof(s));
      snprintf((char *)s, 0x28u, "%s-supply", v30);
      v13 = *(_QWORD *)(a1 + 744);
      memset(v33, 0, 80);
      if ( (unsigned int)_of_parse_phandle_with_args(v13, s, 0, 0, 0, v33) || !v33[0] )
      {
        dev_err(
          a1,
          "%s: Looking up %s property in node %s failed",
          "msm_cdc_dt_parse_vreg_info",
          s,
          *(_QWORD *)(*(_QWORD *)(a1 + 744) + 16LL));
LABEL_30:
        v27 = -22;
        goto LABEL_32;
      }
      *(_QWORD *)(v10 - 22) = v12;
      *(v10 - 2) = v8;
      snprintf((char *)s, 0x28u, "qcom,%s-voltage", v12);
      property = (unsigned int *)of_get_property(*(_QWORD *)(a1 + 744), s, (char *)&v31 + 4);
      if ( !property || HIDWORD(v31) != 8 )
      {
        if ( property )
          v29 = "invalid format";
        else
          v29 = "no";
        dev_err(a1, "%s: %s %s property\n", "msm_cdc_dt_parse_vreg_info", v29, s);
        goto LABEL_30;
      }
      *(_DWORD *)(v10 - 14) = bswap32(*property);
      *(_DWORD *)(v10 - 10) = bswap32(property[1]);
      snprintf((char *)s, 0x28u, "qcom,%s-current", v12);
      v15 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), s, &v31, 1, 0);
      if ( (v15 & 0x80000000) != 0 )
        break;
      *(_DWORD *)(v10 - 6) = v31;
      snprintf((char *)s, 0x28u, "qcom,%s-lpm-supported", v12);
      v17 = (int)of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), s, &v31, 1, 0) >= 0 && (_DWORD)v31 != 0;
      *(v10 - 1) = v17;
      snprintf((char *)s, 0x28u, "qcom,%s-rem-supported", v12);
      v18 = (int)of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), s, &v31, 1, 0) < 0;
      v19 = *(const char **)(v10 - 22);
      v20 = *(_DWORD *)(v10 - 14);
      v21 = *(_DWORD *)(v10 - 10);
      v22 = v18 || (_DWORD)v31 == 0;
      v23 = *(_DWORD *)(v10 - 6);
      v24 = (unsigned __int8)*(v10 - 2);
      v25 = (unsigned __int8)*(v10 - 1);
      v26 = !v22;
      *v10 = v26;
      v10 += 32;
      dev_info(
        a1,
        "%s: %s: vol=[%d %d]uV, curr=[%d]uA, ond %d lpm %d rem %d\n",
        "msm_cdc_dt_parse_vreg_info",
        v19,
        v20,
        v21,
        v23,
        v24,
        v25,
        v26);
      if ( v9 == ++v7 )
        goto LABEL_22;
    }
    v27 = v15;
    dev_err(
      a1,
      "%s: Looking up %s property in node %s failed",
      "msm_cdc_dt_parse_vreg_info",
      (const char *)s,
      *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
LABEL_32:
    dev_err(a1, "%s: parse %s vreg info failed (%d)\n", "msm_cdc_parse_supplies", v30, v27);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v27;
}
