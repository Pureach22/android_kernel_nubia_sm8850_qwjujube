__int64 __fastcall wcd939x_populate_dt_data(__int64 a1)
{
  __int64 v2; // x19
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
  __int64 v14; // x0
  int v15; // w21
  int v16; // w8
  __int64 v17; // x0
  int v18; // w21
  int v19; // w8
  __int64 v20; // x0
  int v21; // w21
  int v22; // w9
  int v23; // w8
  __int64 v24; // x0
  int v25; // w21
  int v26; // w8
  __int64 v27; // x0
  int v28; // w21
  int v29; // w8
  __int64 v30; // x0
  int v31; // w21
  int v32; // w8
  __int64 v33; // x0
  int v34; // w21
  int v35; // w8
  __int64 v36; // x0
  int v37; // w21
  int v38; // w8
  __int64 v39; // x0
  int v40; // w21
  int v41; // w8
  int v42; // w9
  int v43; // w21
  int v44; // w8
  __int64 v45; // x0
  int v46; // w21
  int v47; // w8
  int v48; // w9
  int v49; // w10
  int v50; // w11
  int v51; // w8
  int v52; // w21
  int v53; // w8
  __int64 v54; // x0
  int v55; // w21
  int v56; // w8
  int v57; // w10
  int v58; // w21
  int v59; // w9
  int v60; // w11
  __int64 v61; // x0
  int v62; // w8
  __int64 v63; // x0
  int v64; // w21
  int v65; // w9
  int v66; // w12
  int v67; // w13
  int v68; // w10
  int v69; // w17
  int v70; // w8
  int v71; // w11
  int v72; // w12
  int v73; // w14
  int v74; // w11
  int v75; // w15
  int v76; // w12
  int v77; // w14
  unsigned int v78; // w16
  int v79; // w17
  __int64 v80; // x0
  int v81; // w9
  int v82; // w8
  unsigned int named_gpio; // w0
  int v84; // w0
  __int64 v85; // x0
  int v87; // [xsp+4h] [xbp-5Ch] BYREF
  __int64 v88; // [xsp+8h] [xbp-58h] BYREF
  __int64 v89; // [xsp+10h] [xbp-50h]
  __int64 v90; // [xsp+18h] [xbp-48h]
  __int64 v91; // [xsp+20h] [xbp-40h]
  __int64 v92; // [xsp+28h] [xbp-38h]
  __int64 v93; // [xsp+30h] [xbp-30h]
  __int64 v94; // [xsp+38h] [xbp-28h]
  __int64 v95; // [xsp+40h] [xbp-20h]
  __int64 v96; // [xsp+48h] [xbp-18h]
  __int64 v97; // [xsp+50h] [xbp-10h]
  __int64 v98; // [xsp+58h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = devm_kmalloc(a1, 296, 3520);
  if ( !v2 )
    goto LABEL_112;
  v3 = *(_QWORD *)(a1 + 744);
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v4 = _of_parse_phandle_with_args(v3, "qcom,wcd-rst-gpio-node", 0, 0, 0, &v88);
  v5 = v88;
  if ( v4 )
    v5 = 0;
  *(_QWORD *)v2 = v5;
  if ( !v5 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_populate_dt_data__rs, "wcd939x_populate_dt_data") )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_populate_dt_data",
        "qcom,wcd-rst-gpio-node",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
      v2 = 0;
      goto LABEL_112;
    }
    goto LABEL_85;
  }
  msm_cdc_get_power_supplies(a1, v2 + 280, v2 + 288);
  if ( !*(_QWORD *)(v2 + 280) || *(int *)(v2 + 288) <= 0 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_populate_dt_data__rs_36, "wcd939x_populate_dt_data") )
    {
      dev_err(a1, "%s: no power supplies defined for codec\n", "wcd939x_populate_dt_data");
      v2 = 0;
      goto LABEL_112;
    }
LABEL_85:
    v2 = 0;
    goto LABEL_112;
  }
  v6 = *(_QWORD *)(a1 + 744);
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v7 = _of_parse_phandle_with_args(v6, "qcom,rx-slave", 0, 0, 0, &v88);
  v8 = v88;
  v9 = v7 == 0;
  v10 = *(_QWORD *)(a1 + 744);
  if ( !v9 )
    v8 = 0;
  v96 = 0;
  v97 = 0;
  *(_QWORD *)(v2 + 8) = v8;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v11 = _of_parse_phandle_with_args(v10, "qcom,tx-slave", 0, 0, 0, &v88);
  v12 = v88;
  v9 = v11 == 0;
  v13 = *(_QWORD *)(a1 + 744);
  if ( !v9 )
    v12 = 0;
  LODWORD(v88) = 0;
  *(_QWORD *)(v2 + 16) = v12;
  if ( of_find_property(v13, "qcom,cdc-micbias1-mv", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias1-mv", &v88, 1, 0) & 0x80000000) != 0 )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,cdc-micbias1-mv",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    else
      *(_DWORD *)(v2 + 32) = v88;
  }
  else
  {
    dev_info(a1, "%s: Micbias1 DT property not found\n", "wcd939x_dt_parse_micbias_info");
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias2-mv", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias2-mv", &v88, 1, 0) & 0x80000000) != 0 )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,cdc-micbias2-mv",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    else
      *(_DWORD *)(v2 + 36) = v88;
  }
  else
  {
    dev_info(a1, "%s: Micbias2 DT property not found\n", "wcd939x_dt_parse_micbias_info");
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias3-mv", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias3-mv", &v88, 1, 0) & 0x80000000) != 0 )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,cdc-micbias3-mv",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    else
      *(_DWORD *)(v2 + 40) = v88;
  }
  else
  {
    dev_info(a1, "%s: Micbias3 DT property not found\n", "wcd939x_dt_parse_micbias_info");
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias4-mv", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,cdc-micbias4-mv", &v88, 1, 0) & 0x80000000) != 0 )
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,cdc-micbias4-mv",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    else
      *(_DWORD *)(v2 + 44) = v88;
  }
  else
  {
    dev_info(a1, "%s: Micbias4 DT property not found\n", "wcd939x_dt_parse_micbias_info");
  }
  v14 = *(_QWORD *)(a1 + 744);
  *(_QWORD *)(v2 + 164) = 0x50000007FLL;
  v87 = 0;
  LODWORD(v88) = 0;
  *(_QWORD *)(v2 + 216) = 0;
  *(_QWORD *)(v2 + 224) = 0x221000001F4LL;
  *(_QWORD *)(v2 + 232) = 45;
  *(_QWORD *)(v2 + 240) = 0;
  *(_QWORD *)(v2 + 128) = 0x5000000B7LL;
  *(_QWORD *)(v2 + 136) = 330;
  *(_QWORD *)(v2 + 172) = 330;
  *(_QWORD *)(v2 + 56) = 290;
  *(_DWORD *)(v2 + 84) = 290;
  *(_DWORD *)(v2 + 112) = 229;
  *(_QWORD *)(v2 + 68) = 0x13600000000LL;
  *(_QWORD *)(v2 + 88) = 0;
  *(_QWORD *)(v2 + 96) = 0x13600000000LL;
  *(_QWORD *)(v2 + 264) = 0x26AA00000000LL;
  *(_DWORD *)(v2 + 272) = 9906;
  *(_QWORD *)(v2 + 76) = 1;
  *(_QWORD *)(v2 + 104) = 1;
  *(_DWORD *)(v2 + 144) = 0;
  *(_DWORD *)(v2 + 148) = 530;
  *(_DWORD *)(v2 + 180) = 0;
  *(_DWORD *)(v2 + 184) = 530;
  *(_QWORD *)(v2 + 200) = 0;
  *(_QWORD *)(v2 + 208) = 0;
  *(_QWORD *)(v2 + 152) = 0x100000005LL;
  *(_QWORD *)(v2 + 188) = 0x100000005LL;
  *(_DWORD *)(v2 + 160) = 5;
  *(_DWORD *)(v2 + 196) = 5;
  *(_QWORD *)(v2 + 116) = 13;
  *(_QWORD *)(v2 + 248) = 0x1F400000000LL;
  *(_QWORD *)(v2 + 256) = 2031647;
  *(_DWORD *)(v2 + 64) = 0;
  if ( of_find_property(v14, "qcom,usbcss-hs-xtalk-config", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-xtalk-config", &v88, 1, 0)
        & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-xtalk-config",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else if ( (unsigned int)v88 <= 2 )
    {
      *(_DWORD *)(v2 + 260) = v88;
    }
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-lin-k-aud", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-lin-k-aud", &v87, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_s32",
        "qcom,usbcss-hs-lin-k-aud",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else if ( (unsigned int)(v87 + 90) <= 0x276A )
    {
      *(_DWORD *)(v2 + 116) = v87;
    }
  }
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-diff-slope", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-diff-slope", &v88, 1, 0)
        & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-diff-slope",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else if ( (unsigned int)(v88 - 9800) <= 0xC8 )
    {
      *(_DWORD *)(v2 + 268) = v88;
    }
  }
  v15 = *(_DWORD *)(v2 + 224);
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-rdson-6v", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-rdson-6v", &v88, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-rdson-6v",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v16 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_39;
    }
  }
  v16 = v15;
  LODWORD(v88) = v15;
LABEL_39:
  v17 = *(_QWORD *)(a1 + 744);
  v18 = *(_DWORD *)(v2 + 228);
  *(_DWORD *)(v2 + 224) = v16;
  if ( of_find_property(v17, "qcom,usbcss-hs-rdson-3p6v", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-rdson-3p6v", &v88, 1, 0)
        & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-rdson-3p6v",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v19 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_43;
    }
  }
  v19 = v18;
  LODWORD(v88) = v18;
LABEL_43:
  v20 = *(_QWORD *)(a1 + 744);
  v21 = *(_DWORD *)(v2 + 252);
  v22 = v19 - *(_DWORD *)(v2 + 224);
  *(_DWORD *)(v2 + 228) = v19;
  *(_DWORD *)(v2 + 232) = v22;
  if ( of_find_property(v20, "qcom,usbcss-hs-rcom-margin", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-rcom-margin", &v88, 1, 0)
        & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-rcom-margin",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v23 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_47;
    }
  }
  v23 = v21;
  LODWORD(v88) = v21;
LABEL_47:
  v24 = *(_QWORD *)(a1 + 744);
  v25 = *(_DWORD *)(v2 + 72);
  *(_DWORD *)(v2 + 252) = v23;
  if ( of_find_property(v24, "qcom,usbcss-hs-r1-l", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r1-l", &v88, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-r1-l",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v26 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_51;
    }
  }
  v26 = v25;
  LODWORD(v88) = v25;
LABEL_51:
  v27 = *(_QWORD *)(a1 + 744);
  v28 = *(_DWORD *)(v2 + 100);
  *(_DWORD *)(v2 + 72) = v26;
  if ( of_find_property(v27, "qcom,usbcss-hs-r1-r", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r1-r", &v88, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-r1-r",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v29 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_55;
    }
  }
  v29 = v28;
  LODWORD(v88) = v28;
LABEL_55:
  v30 = *(_QWORD *)(a1 + 744);
  v31 = *(_DWORD *)(v2 + 76);
  *(_DWORD *)(v2 + 100) = v29;
  if ( of_find_property(v30, "qcom,usbcss-hs-r3-l", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r3-l", &v88, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-r3-l",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v32 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_59;
    }
  }
  v32 = v31;
  LODWORD(v88) = v31;
LABEL_59:
  v33 = *(_QWORD *)(a1 + 744);
  v34 = *(_DWORD *)(v2 + 104);
  *(_DWORD *)(v2 + 76) = v32;
  if ( of_find_property(v33, "qcom,usbcss-hs-r3-r", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r3-r", &v88, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-r3-r",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v35 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_63;
    }
  }
  v35 = v34;
  LODWORD(v88) = v34;
LABEL_63:
  v36 = *(_QWORD *)(a1 + 744);
  v37 = *(_DWORD *)(v2 + 148);
  *(_DWORD *)(v2 + 104) = v35;
  if ( of_find_property(v36, "qcom,usbcss-hs-r4-sbu1", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r4-sbu1", &v88, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-r4-sbu1",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v38 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_67;
    }
  }
  v38 = v37;
  LODWORD(v88) = v37;
LABEL_67:
  v39 = *(_QWORD *)(a1 + 744);
  v40 = *(_DWORD *)(v2 + 184);
  *(_DWORD *)(v2 + 148) = v38;
  if ( of_find_property(v39, "qcom,usbcss-hs-r4-sbu2", 0) )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r4-sbu2", &v88, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(
        a1,
        "%s: Looking up %s property in node %s failed\n",
        "wcd939x_read_of_property_u32",
        "qcom,usbcss-hs-r4-sbu2",
        *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    }
    else
    {
      v41 = v88;
      if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        goto LABEL_71;
    }
  }
  v41 = v40;
  LODWORD(v88) = v40;
LABEL_71:
  v42 = *(_DWORD *)(v2 + 260);
  *(_DWORD *)(v2 + 184) = v41;
  if ( v42 == 1 )
  {
    v52 = *(_DWORD *)(v2 + 156);
    if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r6-sbu1", 0) )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r6-sbu1", &v88, 1, 0) & 0x80000000) != 0 )
      {
        dev_err(
          a1,
          "%s: Looking up %s property in node %s failed\n",
          "wcd939x_read_of_property_u32",
          "qcom,usbcss-hs-r6-sbu1",
          *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
      }
      else
      {
        v53 = v88;
        if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
          goto LABEL_90;
      }
    }
    v53 = v52;
    LODWORD(v88) = v52;
LABEL_90:
    v54 = *(_QWORD *)(a1 + 744);
    v55 = *(_DWORD *)(v2 + 192);
    *(_DWORD *)(v2 + 156) = v53;
    if ( of_find_property(v54, "qcom,usbcss-hs-r6-sbu2", 0) )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r6-sbu2", &v88, 1, 0) & 0x80000000) != 0 )
      {
        dev_err(
          a1,
          "%s: Looking up %s property in node %s failed\n",
          "wcd939x_read_of_property_u32",
          "qcom,usbcss-hs-r6-sbu2",
          *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
      }
      else
      {
        v56 = v88;
        if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
          goto LABEL_94;
      }
    }
    v56 = v55;
    LODWORD(v88) = v55;
LABEL_94:
    v57 = *(_DWORD *)(v2 + 156);
    v58 = *(_DWORD *)(v2 + 160);
    v59 = *(_DWORD *)(v2 + 148);
    v60 = *(_DWORD *)(v2 + 184);
    v61 = *(_QWORD *)(a1 + 744);
    *(_DWORD *)(v2 + 192) = v56;
    *(_DWORD *)(v2 + 136) = v59 + v57;
    *(_DWORD *)(v2 + 172) = v60 + v56;
    if ( of_find_property(v61, "qcom,usbcss-hs-r7-sbu1", 0) )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r7-sbu1", &v88, 1, 0) & 0x80000000) != 0 )
      {
        dev_err(
          a1,
          "%s: Looking up %s property in node %s failed\n",
          "wcd939x_read_of_property_u32",
          "qcom,usbcss-hs-r7-sbu1",
          *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
      }
      else
      {
        v62 = v88;
        if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
          goto LABEL_98;
      }
    }
    v62 = v58;
    LODWORD(v88) = v58;
LABEL_98:
    v63 = *(_QWORD *)(a1 + 744);
    v64 = *(_DWORD *)(v2 + 196);
    *(_DWORD *)(v2 + 160) = v62;
    *(_DWORD *)(v2 + 132) = v62;
    if ( of_find_property(v63, "qcom,usbcss-hs-r7-sbu2", 0) )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r7-sbu2", &v88, 1, 0) & 0x80000000) != 0 )
      {
        dev_err(
          a1,
          "%s: Looking up %s property in node %s failed\n",
          "wcd939x_read_of_property_u32",
          "qcom,usbcss-hs-r7-sbu2",
          *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
      }
      else
      {
        v51 = v88;
        if ( (unsigned int)(v88 - 20001) > 0xFFFFB1DF )
        {
LABEL_102:
          *(_DWORD *)(v2 + 196) = v51;
          *(_DWORD *)(v2 + 168) = v51;
          goto LABEL_104;
        }
      }
    }
    v51 = v64;
    goto LABEL_102;
  }
  if ( v42 != 2 )
  {
    v51 = *(_DWORD *)(v2 + 168);
    goto LABEL_104;
  }
  v43 = *(_DWORD *)(v2 + 152);
  if ( !of_find_property(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r5-sbu1", 0) )
    goto LABEL_76;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r5-sbu1", &v88, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(
      a1,
      "%s: Looking up %s property in node %s failed\n",
      "wcd939x_read_of_property_u32",
      "qcom,usbcss-hs-r5-sbu1",
      *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    goto LABEL_76;
  }
  v44 = v88;
  if ( (unsigned int)(v88 - 20001) <= 0xFFFFB1DF )
  {
LABEL_76:
    v44 = v43;
    LODWORD(v88) = v43;
  }
  v45 = *(_QWORD *)(a1 + 744);
  v46 = *(_DWORD *)(v2 + 188);
  *(_DWORD *)(v2 + 152) = v44;
  if ( !of_find_property(v45, "qcom,usbcss-hs-r5-sbu2", 0) )
    goto LABEL_80;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,usbcss-hs-r5-sbu2", &v88, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(
      a1,
      "%s: Looking up %s property in node %s failed\n",
      "wcd939x_read_of_property_u32",
      "qcom,usbcss-hs-r5-sbu2",
      *(const char **)(*(_QWORD *)(a1 + 744) + 16LL));
    goto LABEL_80;
  }
  v47 = v88;
  if ( (unsigned int)(v88 - 20001) <= 0xFFFFB1DF )
LABEL_80:
    v47 = v46;
  v49 = *(_DWORD *)(v2 + 148);
  v48 = *(_DWORD *)(v2 + 152);
  v50 = *(_DWORD *)(v2 + 184);
  *(_DWORD *)(v2 + 188) = v47;
  v51 = v50 + v47;
  *(_DWORD *)(v2 + 132) = v49 + v48;
  *(_DWORD *)(v2 + 136) = 125;
  *(_DWORD *)(v2 + 168) = v51;
  *(_DWORD *)(v2 + 172) = 125;
LABEL_104:
  v65 = *(_DWORD *)(v2 + 136);
  v66 = *(_DWORD *)(v2 + 240);
  v67 = *(_DWORD *)(v2 + 172);
  v68 = v65 + *(_DWORD *)(v2 + 132);
  v69 = *(_DWORD *)(v2 + 76);
  v70 = v67 + v51;
  v71 = *(_DWORD *)(v2 + 128) + v66 + v68;
  v72 = v66 + *(_DWORD *)(v2 + 164);
  v73 = *(_DWORD *)(v2 + 60) + *(_DWORD *)(v2 + 56);
  *(_DWORD *)(v2 + 140) = v68;
  *(_DWORD *)(v2 + 144) = v71;
  v74 = v73 + v69;
  v75 = *(_DWORD *)(v2 + 104);
  *(_DWORD *)(v2 + 176) = v70;
  *(_DWORD *)(v2 + 180) = v72 + v70;
  v76 = *(_DWORD *)(v2 + 84);
  v77 = *(_DWORD *)(v2 + 88);
  v79 = *(_DWORD *)(v2 + 224);
  v78 = *(_DWORD *)(v2 + 228);
  v80 = *(_QWORD *)(a1 + 744);
  *(_DWORD *)(v2 + 64) = v74;
  v81 = v79 + ((unsigned int)(v67 + v65) >> 1);
  *(_DWORD *)(v2 + 92) = v77 + v76 + v75;
  v82 = v78 - 200;
  *(_DWORD *)(v2 + 200) = v81;
  *(_DWORD *)(v2 + 204) = v81;
  if ( v78 - 200 >= 0xC8 )
    v82 = 200;
  *(_DWORD *)(v2 + 208) = v81;
  *(_DWORD *)(v2 + 212) = v81;
  if ( v78 < 0xC8 )
    v82 = 0;
  *(_DWORD *)(v2 + 236) = v82;
  named_gpio = of_get_named_gpio(v80, "qcom,bmic-sw-gpio", 0);
  *(_DWORD *)(v2 + 292) = named_gpio;
  if ( (named_gpio & 0x80000000) != 0 )
  {
    dev_err(a1, "%s: %s property not found %d\n", "wcd939x_populate_dt_data", "qcom,bmic-sw-gpio", named_gpio);
  }
  else
  {
    v84 = gpio_request(named_gpio, "bmic_sw_gpio");
    if ( v84 )
      dev_err(a1, "%s: bmic_sw_gpio request failed, ret:%d\n", "wcd939x_populate_dt_data", v84);
    v85 = gpio_to_desc(*(unsigned int *)(v2 + 292));
    gpiod_direction_output_raw(v85, 0);
    bmic_sw_control = 0;
  }
LABEL_112:
  _ReadStatusReg(SP_EL0);
  return v2;
}
