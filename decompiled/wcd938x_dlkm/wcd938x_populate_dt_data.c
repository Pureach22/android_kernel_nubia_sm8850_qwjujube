__int64 __fastcall wcd938x_populate_dt_data(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  int v4; // w0
  __int64 v5; // x8
  __int64 v6; // x0
  int v7; // w0
  __int64 v8; // x8
  bool v9; // zf
  __int64 v10; // x0
  int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v15; // [xsp+8h] [xbp-58h] BYREF
  __int64 v16; // [xsp+10h] [xbp-50h]
  __int64 v17; // [xsp+18h] [xbp-48h]
  __int64 v18; // [xsp+20h] [xbp-40h]
  __int64 v19; // [xsp+28h] [xbp-38h]
  __int64 v20; // [xsp+30h] [xbp-30h]
  __int64 v21; // [xsp+38h] [xbp-28h]
  __int64 v22; // [xsp+40h] [xbp-20h]
  __int64 v23; // [xsp+48h] [xbp-18h]
  __int64 v24; // [xsp+50h] [xbp-10h]
  __int64 v25; // [xsp+58h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = devm_kmalloc(a1, 72, 3520);
  if ( !v2 )
    goto LABEL_28;
  v3 = *(_QWORD *)(a1 + 744);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v4 = _of_parse_phandle_with_args(v3, "qcom,wcd-rst-gpio-node", 0, 0, 0, &v15);
  v5 = v15;
  if ( v4 )
    v5 = 0;
  *(_QWORD *)v2 = v5;
  if ( !v5 )
  {
    if ( (unsigned int)__ratelimit(&wcd938x_populate_dt_data__rs, "wcd938x_populate_dt_data") )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd938x_populate_dt_data",
        "qcom,wcd-rst-gpio-node",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    goto LABEL_27;
  }
  msm_cdc_get_power_supplies(a1, v2 + 56, v2 + 64);
  if ( !*(_QWORD *)(v2 + 56) || *(int *)(v2 + 64) <= 0 )
  {
    if ( (unsigned int)__ratelimit(&wcd938x_populate_dt_data__rs_36, "wcd938x_populate_dt_data") )
      dev_err(a1, "%s: no power supplies defined for codec\n", "wcd938x_populate_dt_data");
LABEL_27:
    v2 = 0;
    goto LABEL_28;
  }
  v6 = *(_QWORD *)(a1 + 744);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v7 = _of_parse_phandle_with_args(v6, "qcom,rx-slave", 0, 0, 0, &v15);
  v8 = v15;
  v9 = v7 == 0;
  v10 = *(_QWORD *)(a1 + 744);
  if ( !v9 )
    v8 = 0;
  v23 = 0;
  v24 = 0;
  *(_QWORD *)(v2 + 8) = v8;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v11 = _of_parse_phandle_with_args(v10, "qcom,tx-slave", 0, 0, 0, &v15);
  v12 = v15;
  v9 = v11 == 0;
  v13 = *(_QWORD *)(a1 + 744);
  if ( !v9 )
    v12 = 0;
  LODWORD(v15) = 0;
  *(_QWORD *)(v2 + 16) = v12;
  if ( of_find_property(v13, "qcom,cdc-micbias1-mv", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias1-mv", &v15, 1, 0) & 0x80000000) != 0 )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd938x_read_of_property_u32",
        "qcom,cdc-micbias1-mv",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    else
      *(_DWORD *)(v2 + 32) = v15;
  }
  else
  {
    dev_info(a1, "%s: Micbias1 DT property not found\n", "wcd938x_dt_parse_micbias_info");
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias2-mv", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias2-mv", &v15, 1, 0) & 0x80000000) != 0 )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd938x_read_of_property_u32",
        "qcom,cdc-micbias2-mv",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    else
      *(_DWORD *)(v2 + 36) = v15;
  }
  else
  {
    dev_info(a1, "%s: Micbias2 DT property not found\n", "wcd938x_dt_parse_micbias_info");
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias3-mv", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias3-mv", &v15, 1, 0) & 0x80000000) != 0 )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd938x_read_of_property_u32",
        "qcom,cdc-micbias3-mv",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    else
      *(_DWORD *)(v2 + 40) = v15;
  }
  else
  {
    dev_info(a1, "%s: Micbias3 DT property not found\n", "wcd938x_dt_parse_micbias_info");
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias4-mv", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias4-mv", &v15, 1, 0) & 0x80000000) != 0 )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd938x_read_of_property_u32",
        "qcom,cdc-micbias4-mv",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    else
      *(_DWORD *)(v2 + 44) = v15;
  }
  else
  {
    dev_info(a1, "%s: Micbias4 DT property not found\n", "wcd938x_dt_parse_micbias_info");
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v2;
}
