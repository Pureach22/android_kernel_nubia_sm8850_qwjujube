__int64 __fastcall cam_soc_util_get_dt_clk_info(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x21
  int v4; // w8
  __int64 v5; // x0
  int v6; // w23
  const char *v7; // x5
  __int64 v8; // x1
  __int64 v9; // x4
  __int64 v10; // x6
  unsigned int v11; // w26
  unsigned __int64 v13; // x22
  int v14; // w28
  const char **v15; // x27
  unsigned int v16; // w0
  unsigned int v17; // w24
  unsigned int v18; // w23
  const char *v19; // x5
  __int64 v20; // x4
  __int64 v21; // x6
  __int64 v22; // x7
  unsigned int v23; // w24
  unsigned __int64 v24; // x27
  _DWORD *v25; // x26
  __int64 v26; // x23
  unsigned int v27; // w9
  unsigned int v28; // w23
  unsigned int v29; // w0
  unsigned int v30; // w9
  unsigned __int64 v31; // x8
  __int64 v32; // x24
  __int64 v33; // x25
  unsigned __int64 v34; // x9
  unsigned int v35; // w6
  int v36; // w8
  const char *v37; // x5
  __int64 v38; // x4
  __int64 i; // x8
  __int64 v40; // x23
  char *v41; // x24
  const char **v42; // x27
  int v43; // w8
  int v44; // w8
  const char *v45; // x5
  __int64 v46; // x1
  __int64 v47; // x4
  __int64 property; // x0
  int v49; // w8
  int v50; // w0
  unsigned int v51; // w22
  int string_helper; // w0
  __int64 v53; // x24
  __int64 v54; // x27
  size_t v55; // x0
  int v56; // [xsp+0h] [xbp-C0h]
  int v57; // [xsp+18h] [xbp-A8h]
  unsigned int v58; // [xsp+20h] [xbp-A0h]
  int v59; // [xsp+34h] [xbp-8Ch]
  unsigned int v60; // [xsp+38h] [xbp-88h] BYREF
  unsigned int v61; // [xsp+3Ch] [xbp-84h] BYREF
  const char *v62; // [xsp+40h] [xbp-80h] BYREF
  char *v63; // [xsp+48h] [xbp-78h] BYREF
  char *s; // [xsp+50h] [xbp-70h] BYREF
  char *s2; // [xsp+58h] [xbp-68h] BYREF
  __int64 v66; // [xsp+60h] [xbp-60h] BYREF
  __int64 v67; // [xsp+68h] [xbp-58h]
  __int64 v68; // [xsp+70h] [xbp-50h]
  __int64 v69; // [xsp+78h] [xbp-48h]
  __int64 v70; // [xsp+80h] [xbp-40h]
  __int64 v71; // [xsp+88h] [xbp-38h]
  __int64 v72; // [xsp+90h] [xbp-30h]
  __int64 v73; // [xsp+98h] [xbp-28h]
  __int64 v74; // [xsp+A0h] [xbp-20h]
  __int64 v75; // [xsp+A8h] [xbp-18h]
  __int64 v76; // [xsp+B0h] [xbp-10h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 8);
  s = nullptr;
  s2 = nullptr;
  v62 = nullptr;
  v63 = nullptr;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  if ( !v1 )
    goto LABEL_12;
  v2 = *(_QWORD *)(v1 + 744);
  v61 = 0;
  if ( of_find_property(v2, "use-shared-clk", 0) )
  {
    v4 = 1;
  }
  else
  {
    v4 = 0;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_dt_clk_info",
        2849,
        "No shared clk parameter defined");
      v4 = 0;
    }
  }
  *(_DWORD *)(a1 + 864) = v4;
  LODWORD(v5) = of_property_read_string_helper(v2, "clock-names", 0, 0, 0);
  v6 = v5;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    LODWORD(v5) = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x20000,
                    4,
                    "cam_soc_util_get_dt_clk_info",
                    2858,
                    "E: dev_name = %s count = %d",
                    *(const char **)(a1 + 24),
                    v5);
    if ( v6 >= 33 )
      goto LABEL_10;
  }
  else if ( (int)v5 >= 33 )
  {
LABEL_10:
    v7 = "invalid count of clocks, count=%d";
    v8 = 0x20000;
    v9 = 2860;
    v10 = (unsigned int)v6;
    goto LABEL_11;
  }
  if ( v6 <= 0 )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_dt_clk_info",
        2865,
        "No clock-names found");
    v11 = 0;
    *(_DWORD *)(a1 + 868) = 0;
    goto LABEL_13;
  }
  v13 = 0;
  v14 = v6;
  v59 = v6;
  *(_DWORD *)(a1 + 868) = v6;
  v15 = (const char **)(a1 + 872);
  do
  {
    if ( v13 == 33 )
      goto LABEL_44;
    LODWORD(v5) = of_property_read_string_helper(v2, "clock-names", v15, 1, (unsigned int)v13);
    v11 = v5;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      LODWORD(v5) = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 0x20000,
                      4,
                      "cam_soc_util_get_dt_clk_info",
                      2876,
                      "clock-names[%d] = %s",
                      v13,
                      *v15);
      if ( (v11 & 0x80000000) != 0 )
      {
LABEL_24:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_get_dt_clk_info",
          2880,
          "i= %d count= %d reading clock-names failed",
          v13,
          v6);
        goto LABEL_13;
      }
    }
    else if ( (v5 & 0x80000000) != 0 )
    {
      goto LABEL_24;
    }
    ++v13;
    ++v15;
  }
  while ( v6 != v13 );
  v16 = of_property_count_elems_of_size(v2, "clock-rates", 4);
  if ( (int)v16 <= 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_clk_info",
      2887,
      "reading clock-rates count failed");
    goto LABEL_12;
  }
  v17 = *(_DWORD *)(a1 + 868);
  v18 = v16;
  LODWORD(v13) = v16 / v17;
  if ( v16 % v17 )
  {
    v19 = "mismatch clk/rates, No of clocks=%d, No of rates=%d";
    v20 = 2894;
    v21 = v17;
    v22 = v16;
    goto LABEL_46;
  }
  LODWORD(v5) = of_property_read_string_helper(v2, "clock-cntl-level", 0, 0, 0);
  if ( (_DWORD)v5 != (_DWORD)v13 )
    goto LABEL_45;
  *(_QWORD *)(a1 + 2872) = 9;
  if ( v17 <= v18 )
  {
    v28 = 0;
    while ( 1 )
    {
      v29 = of_property_read_string_helper(v2, "clock-cntl-level", &v62, 1, v28);
      if ( (v29 & 0x80000000) != 0 )
        break;
      LODWORD(v5) = cam_soc_util_get_level_from_string(v62, (int *)&v61);
      if ( (_DWORD)v5 )
      {
        v11 = v5;
        goto LABEL_13;
      }
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        LODWORD(v5) = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        debug_mdl & 0x20000,
                        4,
                        "cam_soc_util_get_dt_clk_info",
                        2927,
                        "[%d] : %s %d",
                        v28,
                        v62,
                        v61);
      v30 = v61;
      if ( v61 > 9 )
        goto LABEL_44;
      LODWORD(v31) = *(_DWORD *)(a1 + 868);
      *(_BYTE *)(a1 + 2860 + v61) = 1;
      if ( (_DWORD)v31 )
      {
        v32 = a1 + 1384;
        v33 = -32;
        while ( 1 )
        {
          if ( v61 > 9 )
            goto LABEL_44;
          LODWORD(v5) = of_property_read_u32_index(
                          v2,
                          "clock-rates",
                          (unsigned int)v33 + v28 * (_DWORD)v31 + 32,
                          v32 + ((unsigned __int64)v61 << 7));
          if ( (_DWORD)v5 )
            break;
          if ( !v33 )
            goto LABEL_44;
          v35 = v61;
          if ( v61 > 9 )
            goto LABEL_44;
          v36 = *(_DWORD *)(v32 + ((unsigned __int64)v61 << 7));
          if ( !v36 )
            v36 = -1;
          *(_DWORD *)(v32 + ((unsigned __int64)v61 << 7)) = v36;
          if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
            LODWORD(v5) = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                            3,
                            debug_mdl & 0x20000,
                            4,
                            "cam_soc_util_get_dt_clk_info",
                            2947,
                            "soc_info->clk_rate[%d][%d] = %d",
                            v35,
                            (int)v33 + 32,
                            v36);
          v31 = *(unsigned int *)(a1 + 868);
          v34 = v33 + 33;
          ++v33;
          v32 += 4;
          if ( v34 >= v31 )
          {
            v30 = v61;
            goto LABEL_68;
          }
        }
        v11 = v5;
        v37 = "Error reading clock-rates, rc=%d";
        v38 = 2936;
LABEL_75:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_get_dt_clk_info",
          v38,
          v37,
          v11);
        goto LABEL_13;
      }
LABEL_68:
      if ( v30 < 2 )
        goto LABEL_72;
      if ( v30 < *(_DWORD *)(a1 + 2872) )
        *(_DWORD *)(a1 + 2872) = v30;
      if ( v30 <= 9 )
      {
LABEL_72:
        if ( v30 > *(_DWORD *)(a1 + 2876) )
          *(_DWORD *)(a1 + 2876) = v30;
      }
      if ( (int)++v28 >= (int)v13 )
        goto LABEL_35;
    }
    v11 = v29;
    v37 = "Error reading clock-cntl-level, rc=%d";
    v38 = 2917;
    goto LABEL_75;
  }
LABEL_35:
  LODWORD(v5) = of_property_count_elems_of_size(v2, "agg-clks", 4);
  if ( (int)v5 >= 1 )
  {
    LODWORD(v13) = *(_DWORD *)(a1 + 868);
    v23 = v5;
    v24 = 0;
    v25 = (_DWORD *)(a1 + 3312);
    v26 = a1 + 3320;
    v27 = v13;
    v58 = (unsigned int)v5 / (unsigned int)v13;
    do
    {
      if ( (unsigned int)v13 <= v23 )
      {
        if ( v24 > 0x1F )
          goto LABEL_44;
        v57 = v58 * v24;
        LODWORD(v5) = of_property_read_u32_index(v2, "agg-clks", v58 * (unsigned int)v24, v26 - 8);
        if ( v58 != 1 )
        {
          LODWORD(v5) = of_property_read_u32_index(v2, "agg-clks", (unsigned int)(v57 + 1), v26 - 4);
          if ( v58 >= 3 )
          {
            LODWORD(v5) = of_property_read_u32_index(v2, "agg-clks", (unsigned int)(v57 + 2), v26);
            if ( v58 != 3 )
              goto LABEL_44;
          }
        }
        v27 = *(_DWORD *)(a1 + 868);
      }
      ++v24;
      v26 += 8;
    }
    while ( v24 < v27 );
    if ( v27 )
    {
      for ( i = 0; i != v27; ++i )
      {
        if ( i == 32 )
          goto LABEL_44;
        if ( *v25 )
          *(_DWORD *)(a1 + 3568) |= 1 << i;
        v25 += 2;
      }
    }
  }
  *(_DWORD *)(a1 + 2796) = -1;
  LODWORD(v5) = of_property_read_string_helper(v2, "src-clock-name", &s2, 1, 0);
  if ( (v5 & 0x80000000) != 0 || !s2 )
  {
    v11 = 0;
    if ( (debug_mdl & 0x20000) == 0 || debug_priority )
      goto LABEL_13;
    v45 = "No src_clk_str found";
    v46 = debug_mdl & 0x20000;
    v47 = 2980;
    goto LABEL_99;
  }
  if ( *(_DWORD *)(a1 + 868) )
  {
    v13 = 0;
    v40 = a1 + 2664;
    while ( 1 )
    {
      if ( v13 == 32 )
        goto LABEL_44;
      v41 = s2;
      v42 = (const char **)(v40 + 8 * v13 - 1792);
      if ( !strcmp(*v42, s2) )
      {
        v43 = debug_mdl;
        *(_DWORD *)(a1 + 2796) = v13;
        if ( (v43 & 0x20000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            *(_QWORD *)&v43 & 0x20000LL,
            4,
            "cam_soc_util_get_dt_clk_info",
            2989,
            "src clock = %s, index = %d",
            v41,
            v13);
      }
      LODWORD(v5) = _of_parse_phandle_with_args(v2, "clocks", "#clock-cells", 0xFFFFFFFFLL, (unsigned int)v13, &v66);
      if ( (_DWORD)v5 )
        break;
      v44 = HIDWORD(v67);
      *(_DWORD *)(v40 + 4 * v13) = HIDWORD(v67);
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        LODWORD(v5) = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        debug_mdl & 0x20000,
                        4,
                        "cam_soc_util_get_dt_clk_info",
                        3006,
                        "Dev %s clk %s id %d",
                        *(const char **)(a1 + 24),
                        *v42,
                        v44);
      if ( ++v13 >= *(unsigned int *)(a1 + 868) )
        goto LABEL_101;
    }
    v10 = (unsigned int)v5;
    v7 = "failed to clock info rc=%d";
    v8 = 4;
    v9 = 2996;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v8,
      1,
      "cam_soc_util_get_dt_clk_info",
      v9,
      v7,
      v10);
    goto LABEL_12;
  }
LABEL_101:
  property = of_find_property(v2, "operating-points-v2", 0);
  v49 = debug_mdl;
  *(_BYTE *)(a1 + 3309) = property != 0;
  if ( (v49 & 0x20000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      *(_QWORD *)&v49 & 0x20000LL,
      4,
      "cam_soc_util_get_dt_clk_info",
      3024,
      "Dev %s src_clk_idx %d, lowest_clk_level %d highest_clk_level: %d",
      *(const char **)(a1 + 24),
      *(_DWORD *)(a1 + 2796),
      *(_DWORD *)(a1 + 2872),
      *(_DWORD *)(a1 + 2876));
  *(_DWORD *)(a1 + 2792) = 0;
  v50 = of_property_count_elems_of_size(v2, "shared-clks", 4);
  if ( v50 <= 0 )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_dt_clk_info",
        3029,
        "Dev %s, no shared clks",
        *(const char **)(a1 + 24));
  }
  else
  {
    if ( v50 != v59 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_get_dt_clk_info",
        3032,
        "Dev %s, incorrect shared clock count %d %d",
        *(const char **)(a1 + 24),
        v50,
        v59);
      goto LABEL_12;
    }
    v51 = 0;
    v60 = 0;
    do
    {
      if ( (unsigned int)of_property_read_u32_index(v2, "shared-clks", v51, &v60) || v60 > 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_get_dt_clk_info",
          3044,
          "Incorrect shared clk info at %d, val=%d, count=%d",
          v51,
          v60,
          v59);
        goto LABEL_12;
      }
      if ( v60 )
        *(_DWORD *)(a1 + 2792) |= 1 << v51;
      ++v51;
    }
    while ( v14 != v51 );
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_dt_clk_info",
        3054,
        "Dev %s shared clk mask 0x%x",
        *(const char **)(a1 + 24),
        *(_DWORD *)(a1 + 2792));
  }
  *(_DWORD *)(a1 + 2880) = 0;
  string_helper = of_property_read_string_helper(v2, "scl-clk-names", 0, 0, 0);
  v10 = (unsigned int)string_helper;
  *(_DWORD *)(a1 + 2880) = string_helper;
  if ( (unsigned int)(string_helper - 33) <= 0xFFFFFFDF )
  {
    if ( string_helper != -61 )
    {
      if ( string_helper == -22 )
      {
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "cam_soc_util_get_dt_clk_info",
            3064,
            "scl_clk_name prop not avialable");
        goto LABEL_149;
      }
      if ( string_helper < 33 )
      {
LABEL_149:
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "cam_soc_util_get_dt_clk_info",
            3072,
            "Invalid scl_clk count: %d",
            *(_DWORD *)(a1 + 2880));
        *(_DWORD *)(a1 + 2880) = -1;
        goto LABEL_153;
      }
    }
    v7 = "Invalid scl_clk_count: %d";
    v8 = 0x20000;
    v9 = 3068;
    goto LABEL_11;
  }
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_get_dt_clk_info",
      3076,
      "No of scalable clocks: %d",
      string_helper);
    if ( *(int *)(a1 + 2880) < 1 )
    {
LABEL_153:
      if ( (of_property_read_string_helper(v2, "clock-control-debugfs", &v63, 1, 0) & 0x80000000) == 0 && v63 )
      {
        if ( !strcmp("true", v63) )
          *(_BYTE *)(a1 + 3288) = 1;
        v11 = 0;
        if ( (debug_mdl & 0x20000) == 0 || debug_priority )
          goto LABEL_13;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_get_dt_clk_info",
          3111,
          "X: dev_name = %s count = %d",
          *(const char **)(a1 + 24),
          v59);
LABEL_100:
        v11 = 0;
        goto LABEL_13;
      }
      v11 = 0;
      if ( (debug_mdl & 0x20000) == 0 || debug_priority )
        goto LABEL_13;
      v45 = "No clock_control_debugfs property found";
      v46 = debug_mdl & 0x20000;
      v47 = 3102;
LABEL_99:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v46,
        4,
        "cam_soc_util_get_dt_clk_info",
        v47,
        v45);
      goto LABEL_100;
    }
  }
  v13 = 0;
  v53 = a1 + 2884;
  while ( 1 )
  {
    LODWORD(v5) = of_property_read_string_helper(v2, "scl-clk-names", &s, 1, (unsigned int)v13);
    if ( (v5 & 0x80000000) == 0 )
    {
      if ( s )
        break;
    }
    LODWORD(v5) = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x20000,
                    2,
                    "cam_soc_util_get_dt_clk_info",
                    3082,
                    "scl_clk_str is NULL");
    if ( v13 > 0x1F )
      goto LABEL_44;
    *(_DWORD *)(v53 + 4 * v13) = -1;
LABEL_132:
    if ( (__int64)++v13 >= *(int *)(a1 + 2880) )
      goto LABEL_153;
  }
  if ( !*(_DWORD *)(a1 + 868) )
    goto LABEL_132;
  v54 = 0;
  while ( v54 != 32 )
  {
    v55 = strlen(s);
    v5 = strnstr(s, *(_QWORD *)(a1 + 872 + 8 * v54), v55);
    if ( v5 )
    {
      if ( v13 > 0x1F )
        break;
      *(_DWORD *)(v53 + 4 * v13) = v54;
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_get_dt_clk_info",
          3092,
          "scl clock = %s, index = %d",
          s,
          v54);
      goto LABEL_132;
    }
    if ( ++v54 >= (unsigned __int64)*(unsigned int *)(a1 + 868) )
      goto LABEL_132;
  }
LABEL_44:
  __break(0x5512u);
LABEL_45:
  v22 = (unsigned int)v5;
  v19 = "Mismatch No of levels=%d, No of level string=%d";
  v20 = 2905;
  v21 = (unsigned int)v13;
LABEL_46:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_get_dt_clk_info",
    v20,
    v19,
    v21,
    v22,
    v56);
LABEL_12:
  v11 = -22;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v11;
}
