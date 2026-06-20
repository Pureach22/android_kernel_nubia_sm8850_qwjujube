__int64 __fastcall cam_cpas_get_custom_dt_info(__int64 a1, __int64 *a2, const char **a3)
{
  unsigned int *v5; // x21
  __int64 v6; // x20
  unsigned int string; // w0
  __int64 v8; // x6
  const char *v9; // x5
  unsigned int v10; // w19
  __int64 v11; // x4
  __int64 result; // x0
  unsigned int v13; // w0
  _QWORD *v14; // x23
  int u64; // w6
  int variable_u32_array; // w0
  char v17; // w8
  int v18; // w9
  _QWORD *v19; // x23
  int v20; // w0
  int v21; // w9
  char v22; // w8
  __int64 property; // x0
  __int64 v24; // x0
  unsigned int v25; // w0
  const char *v26; // x5
  __int64 v27; // x6
  __int64 v28; // x4
  unsigned int v29; // w20
  int v30; // w8
  char *v31; // x0
  __int64 v32; // x0
  int v33; // w6
  unsigned int v34; // w23
  unsigned int v35; // w24
  unsigned int *v36; // x28
  unsigned int v37; // w0
  unsigned int v38; // w0
  unsigned int v39; // w0
  const char *v40; // x5
  __int64 v41; // x1
  __int64 v42; // x4
  int *v43; // x23
  unsigned int v44; // w0
  unsigned int v45; // w0
  int string_helper; // w0
  unsigned __int64 v47; // x22
  const char **v48; // x23
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  unsigned int v52; // w22
  int v53; // w22
  __int64 v54; // x23
  unsigned int v55; // w8
  __int64 v56; // x28
  _QWORD *v57; // x25
  unsigned int v58; // w0
  __int64 v59; // x8
  const char *v60; // x5
  unsigned int v61; // w19
  __int64 v62; // x4
  __int64 v63; // x0
  int v64; // w0
  int v65; // w7
  unsigned int v66; // w0
  __int64 v67; // x28
  __int64 v68; // x22
  int *v69; // x26
  const char *v70; // x5
  __int64 v71; // x4
  const char *v72; // x5
  __int64 v73; // x1
  __int64 v74; // x4
  __int64 v75; // x6
  __int64 v76; // x0
  char v77; // w8
  __int64 v78; // x0
  __int64 v79; // x0
  unsigned int v80; // w0
  unsigned int v81; // w0
  unsigned int v82; // w0
  unsigned int v83; // w0
  char v84; // w8
  __int64 v85; // x0
  const char *v86; // x5
  unsigned int v87; // w6
  __int64 v88; // x4
  unsigned int v89; // w0
  const char *v90; // x5
  __int64 v91; // x4
  const char *v92; // x5
  __int64 v93; // x4
  unsigned int v94; // w0
  unsigned int v95; // w0
  unsigned int v96; // w0
  int v97; // w9
  unsigned __int64 v98; // x22
  unsigned __int8 *v99; // x25
  _DWORD *v100; // x21
  int v101; // w22
  unsigned int v102; // w0
  unsigned int v103; // w0
  char v104; // w8
  unsigned int v105; // w22
  const char *v106; // x6
  const char *v108; // [xsp+28h] [xbp-C8h] BYREF
  unsigned int v109; // [xsp+34h] [xbp-BCh] BYREF
  __int64 v110; // [xsp+38h] [xbp-B8h] BYREF
  __int64 v111; // [xsp+40h] [xbp-B0h] BYREF
  __int64 v112; // [xsp+48h] [xbp-A8h]
  __int64 v113; // [xsp+50h] [xbp-A0h]
  __int64 v114; // [xsp+58h] [xbp-98h]
  __int64 v115; // [xsp+60h] [xbp-90h]
  __int64 v116; // [xsp+68h] [xbp-88h]
  __int64 v117; // [xsp+70h] [xbp-80h]
  __int64 v118; // [xsp+78h] [xbp-78h]
  __int64 v119; // [xsp+80h] [xbp-70h]
  __int64 v120; // [xsp+88h] [xbp-68h]
  __int64 v121; // [xsp+90h] [xbp-60h] BYREF
  __int64 v122; // [xsp+98h] [xbp-58h]
  __int64 v123; // [xsp+A0h] [xbp-50h]
  __int64 v124; // [xsp+A8h] [xbp-48h]
  __int64 v125; // [xsp+B0h] [xbp-40h]
  __int64 v126; // [xsp+B8h] [xbp-38h]
  __int64 v127; // [xsp+C0h] [xbp-30h]
  __int64 v128; // [xsp+C8h] [xbp-28h]
  __int64 v129; // [xsp+D0h] [xbp-20h]
  __int64 v130; // [xsp+D8h] [xbp-18h]
  __int64 v131; // [xsp+E0h] [xbp-10h]

  v131 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned int **)(a1 + 3680);
  v129 = 0;
  v130 = 0;
  v127 = 0;
  v128 = 0;
  v125 = 0;
  v126 = 0;
  v123 = 0;
  v124 = 0;
  v121 = 0;
  v122 = 0;
  v119 = 0;
  v120 = 0;
  v117 = 0;
  v118 = 0;
  v115 = 0;
  v116 = 0;
  v113 = 0;
  v114 = 0;
  v111 = 0;
  v112 = 0;
  v110 = 0;
  v109 = 0;
  if ( !a2 || !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_custom_dt_info",
      1343,
      "invalid input arg %pK %pK",
      a3,
      a2);
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  v6 = a2[95];
  string = of_property_read_string(v6, "arch-compat", a3);
  if ( string )
  {
    v8 = *a2;
    v9 = "device %s failed to read arch-compat";
    v10 = string;
    v11 = 1353;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_custom_dt_info",
      v11,
      v9,
      v8);
    result = v10;
    goto LABEL_8;
  }
  cam_cpas_get_hw_features((__int64)a2, a3);
  *((_DWORD *)a3 + 410) = 0;
  *((_BYTE *)a3 + 1644) = 0;
  a3[204] = nullptr;
  v13 = of_property_count_elems_of_size(v6, "domain-id", 4);
  if ( (int)v13 <= 0 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_parse_domain_id_mapping",
        1192,
        "No domain-id mapping found, count: %d",
        v13);
      if ( *((_BYTE *)a3 + 1644) )
        goto LABEL_16;
    }
    else if ( *((_BYTE *)a3 + 1644) )
    {
LABEL_16:
      v14 = a3 + 131;
      a3[131] = nullptr;
      u64 = of_property_read_u64(v6, "camnoc-axi-min-ib-bw", a3 + 131);
      if ( u64 == -75 )
      {
        *v14 = 0;
        variable_u32_array = of_property_read_variable_u32_array(v6, "camnoc-axi-min-ib-bw", a3 + 131, 1, 0);
        u64 = variable_u32_array & (variable_u32_array >> 31);
      }
      v17 = debug_mdl;
      v18 = debug_priority;
      if ( u64 )
      {
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_get_custom_dt_info",
            1381,
            "failed to read camnoc-axi-min-ib-bw rc:%d",
            u64);
          v18 = debug_priority;
          v17 = debug_mdl;
        }
        *v14 = 3000000000LL;
      }
      if ( (v17 & 4) != 0 && !v18 )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v17 & 4,
          4,
          "cam_cpas_get_custom_dt_info",
          1385,
          "camnoc-axi-min-ib-bw = %llu",
          *v14);
      v19 = a3 + 132;
      v20 = of_property_read_u64(v6, "cam-max-rt-axi-bw", a3 + 132);
      v21 = debug_priority;
      v22 = debug_mdl;
      if ( v20 )
      {
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_get_custom_dt_info",
            1389,
            "failed to read cam-max-rt-axi-bw rc:%d",
            v20);
          v21 = debug_priority;
          v22 = debug_mdl;
        }
        *v19 = 0;
      }
      if ( (v22 & 4) != 0 && !v21 )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v22 & 4,
          4,
          "cam_cpas_get_custom_dt_info",
          1393,
          "cam-max-rt-axi-bw = %llu",
          *v19);
      *((_BYTE *)a3 + 8) = of_find_property(v6, "client-id-based", 0) != 0;
      property = of_find_property(v6, "interconnect-names", 0);
      *((_BYTE *)a3 + 9) = property != 0;
      if ( property )
      {
        v24 = of_find_property(v6, "cam-icc-path-names", 0);
        *((_BYTE *)a3 + 10) = v24 != 0;
        if ( v24 )
        {
          v25 = of_property_read_string(v6, "cam-icc-path-names", v5 + 730);
          if ( v25 )
          {
            v8 = *a2;
            v9 = "device %s failed to read ahb cam-icc-path-names";
            v10 = v25;
            v11 = 1406;
            goto LABEL_5;
          }
        }
        else
        {
          v37 = of_property_read_string(v6, "interconnect-names", v5 + 730);
          if ( v37 )
          {
            v8 = *a2;
            v9 = "device %s failed to read ahb interconnect-names";
            v10 = v37;
            v11 = 1417;
            goto LABEL_5;
          }
          v38 = _of_parse_phandle_with_args(v6, "interconnects", "#interconnect-cells", 0xFFFFFFFFLL, 0, &v121);
          if ( v38 )
          {
            v8 = *a2;
            v9 = "device %s failed to read ahb bus src info";
            v10 = v38;
            v11 = 1427;
            goto LABEL_5;
          }
          if ( (_DWORD)v122 != 1 )
          {
            v40 = "Invalid number of ahb src args: %d";
            v41 = 4;
            v42 = 1434;
LABEL_122:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              v41,
              1,
              "cam_cpas_get_custom_dt_info",
              v42,
              v40);
            goto LABEL_7;
          }
          v5[732] = HIDWORD(v122);
          v39 = _of_parse_phandle_with_args(v6, "interconnects", "#interconnect-cells", 0xFFFFFFFFLL, 1, &v111);
          if ( v39 )
          {
            v8 = *a2;
            v9 = "device %s failed to read ahb bus dst info";
            v10 = v39;
            v11 = 1444;
            goto LABEL_5;
          }
          if ( (_DWORD)v112 != 1 )
          {
            v40 = "Invalid number of ahb dst args: %d";
            v41 = 4;
            v42 = 1451;
            goto LABEL_122;
          }
          v5[733] = HIDWORD(v112);
        }
        v43 = (int *)(v5 + 735);
        v44 = of_property_read_variable_u32_array(v6, "cam-ahb-num-cases", v5 + 735, 1, 0);
        if ( (v44 & 0x80000000) != 0 )
        {
          v8 = *a2;
          v9 = "device %s failed to read ahb num usecases";
          v10 = v44;
          v11 = 1464;
          goto LABEL_5;
        }
        if ( *v43 >= 10 )
        {
          v40 = "Invalid number of usecases: %d";
          v41 = 0x20000;
          v42 = 1471;
          goto LABEL_122;
        }
        v45 = of_property_count_elems_of_size(v6, "cam-ahb-bw-KBps", 4);
        if ( (int)v45 <= 0 )
        {
          v40 = "Error counting ahb bw values";
          v41 = 0x20000;
          v42 = 1477;
          goto LABEL_122;
        }
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          v105 = v45;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_get_custom_dt_info",
            1481,
            "AHB: num bw values %d",
            v45);
          v45 = v105;
        }
        if ( v45 >> 1 != *v43 )
        {
          v40 = "Invalid number of levels: %d";
          v41 = 0x20000;
          v42 = 1486;
          goto LABEL_122;
        }
        if ( v45 != 1 )
        {
          v53 = 0;
          v54 = 0;
          if ( v45 >> 1 <= 1 )
            v55 = 1;
          else
            v55 = v45 >> 1;
          v56 = 2LL * v55;
          v57 = v5 + 736;
          while ( 1 )
          {
            LODWORD(v51) = of_property_read_u32_index(v6, "cam-ahb-bw-KBps", (unsigned int)v54, &v110);
            if ( (_DWORD)v51 )
            {
              v60 = "Error reading ab bw value, rc=%d";
              v61 = v51;
              v62 = 1494;
LABEL_119:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                0x20000,
                1,
                "cam_cpas_get_custom_dt_info",
                v62,
                v60,
                v61);
              result = v61;
              goto LABEL_8;
            }
            if ( v54 == 18 )
              break;
            *v57 = (unsigned int)v110;
            v58 = of_property_read_u32_index(v6, "cam-ahb-bw-KBps", (unsigned int)(v54 + 1), &v109);
            if ( v58 )
            {
              v60 = "Error reading ib bw value, rc=%d";
              v61 = v58;
              v62 = 1503;
              goto LABEL_119;
            }
            v59 = v109;
            v57[1] = v109;
            if ( (debug_mdl & 4) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 4,
                4,
                "cam_cpas_get_custom_dt_info",
                1511,
                "AHB: Level: %d, ab_value %llu, ib_value: %llu",
                v53,
                *v57,
                v59);
            v54 += 2;
            ++v53;
            v57 += 2;
            if ( v56 == v54 )
              goto LABEL_84;
          }
LABEL_256:
          __break(0x5512u);
          goto LABEL_257;
        }
      }
LABEL_84:
      string_helper = of_property_read_string_helper(v6, "client-names", 0, 0, 0);
      if ( string_helper <= 0 )
      {
        v40 = "no client-names found";
        v41 = 4;
        v42 = 1517;
        goto LABEL_122;
      }
      if ( (unsigned int)string_helper >= 0x2C )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_get_custom_dt_info",
          1521,
          "Number of clients %d greater than max %d",
          string_helper,
          43);
        goto LABEL_7;
      }
      *((_DWORD *)a3 + 3) = string_helper;
      if ( (debug_mdl & 4) == 0
        || debug_priority
        || (((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 4,
              4,
              "cam_cpas_get_custom_dt_info",
              1529,
              "arch-compat=%s, client_id_based = %d, num_clients=%d",
              *a3,
              *((unsigned __int8 *)a3 + 8),
              string_helper),
            *((_DWORD *)a3 + 3)) )
      {
        v47 = 0;
        v48 = a3 + 2;
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          if ( (of_property_read_string_helper(v6, "client-names", v48, 1, (unsigned int)v47) & 0x80000000) != 0 )
          {
            v40 = "no client-name at cnt=%d";
            v41 = 4;
            v42 = 1535;
            goto LABEL_122;
          }
          if ( mem_trace_en == 1 )
            v49 = cam_mem_trace_alloc(1712, 0xCC0u, 0, "cam_cpas_get_custom_dt_info", 0x604u);
          else
            v49 = _kvmalloc_node_noprof(1712, 0, 3520, 0xFFFFFFFFLL);
          v50 = v49;
          v51 = a1;
          if ( v47 == 43 )
            goto LABEL_256;
          *(_QWORD *)&v5[2 * v47 + 80] = v50;
          if ( !v50 )
            break;
          if ( (debug_mdl & 4) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 4,
              4,
              "cam_cpas_get_custom_dt_info",
              1547,
              "Client[%d] : %s",
              v47,
              *v48);
          ++v47;
          ++v48;
          if ( v47 >= *((unsigned int *)a3 + 3) )
            goto LABEL_124;
        }
        v52 = -12;
        goto LABEL_252;
      }
LABEL_124:
      v63 = of_find_property(v6, "control-camnoc-axi-clk", 0);
      *((_BYTE *)a3 + 1036) = v63 != 0;
      if ( v63 )
      {
        v64 = of_property_read_variable_u32_array(v6, "camnoc-bus-width", a3 + 130, 1, 0);
        v65 = *((_DWORD *)a3 + 260);
        if ( v64 < 0 || !v65 )
        {
          v52 = v64 & (v64 >> 31);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_get_custom_dt_info",
            1558,
            "Bus width not found rc=%d, %d",
            v52,
            v65);
LABEL_251:
          v51 = a1;
LABEL_252:
          cam_cpas_util_client_cleanup(v51);
          result = v52;
          goto LABEL_8;
        }
        if ( (of_property_read_variable_u32_array(v6, "camnoc-axi-clk-bw-margin-perc", (char *)a3 + 1044, 1, 0)
            & 0x80000000) != 0 )
          *((_DWORD *)a3 + 261) = 0;
      }
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_get_custom_dt_info",
          1575,
          "control_camnoc_axi_clk=%d, width=%d, margin=%d",
          *((unsigned __int8 *)a3 + 1036),
          *((_DWORD *)a3 + 260),
          *((_DWORD *)a3 + 261));
      v66 = of_property_count_elems_of_size(v6, "vdd-corners", 4);
      if ( v66 - 1 <= 0xF )
      {
        v67 = v66;
        if ( (unsigned int)of_property_read_string_helper(v6, "vdd-corner-ahb-mapping", 0, 0, 0) == v66 )
        {
          v68 = 0;
          v69 = (int *)(a3 + 114);
          v108 = nullptr;
          while ( !(unsigned int)of_property_read_u32_index(v6, "vdd-corners", (unsigned int)v68, v69 - 1) )
          {
            if ( (of_property_read_string_helper(v6, "vdd-corner-ahb-mapping", &v108, 1, (unsigned int)v68) & 0x80000000) != 0 )
            {
              v70 = "no ahb-mapping at index=%d";
              v71 = 1597;
              goto LABEL_145;
            }
            if ( (unsigned int)cam_soc_util_get_level_from_string(v108, v69) )
            {
              v72 = "invalid ahb-string at index=%d";
              v73 = 4;
              v74 = 1606;
              v75 = (unsigned int)v68;
              goto LABEL_159;
            }
            if ( (debug_mdl & 4) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 4,
                4,
                "cam_cpas_get_custom_dt_info",
                1614,
                "Vdd-AHB mapping [%d] : [%d] [%s] [%d]",
                v68,
                *(v69 - 1),
                v108,
                *v69);
            ++v68;
            v69 += 2;
            if ( v67 == v68 )
            {
              *((_DWORD *)a3 + 226) = v67;
              goto LABEL_148;
            }
          }
          v70 = "vdd-corners failed at index=%d";
          v71 = 1588;
LABEL_145:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_get_custom_dt_info",
            v71,
            v70,
            (unsigned int)v68);
          v52 = -19;
          goto LABEL_251;
        }
      }
LABEL_148:
      v76 = of_find_property(v6, "enable-secure-qos-update", 0);
      v77 = debug_mdl;
      *((_BYTE *)a3 + 1611) = v76 != 0;
      if ( (v77 & 4) != 0 && !debug_priority )
      {
        if ( v76 )
          v106 = "Y";
        else
          v106 = "N";
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v77 & 4,
          4,
          "cam_cpas_get_custom_dt_info",
          1623,
          "Enable secure qos update: %s",
          v106);
      }
      v78 = of_find_property(v6, "enable-smart-qos", 0);
      *((_BYTE *)a3 + 1608) = v78 != 0;
      if ( !v78 )
      {
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_get_custom_dt_info",
            1753,
            "SmartQoS not enabled, use static settings");
        a3[202] = nullptr;
        goto LABEL_164;
      }
      LODWORD(v108) = 0;
      if ( mem_trace_en == 1 )
      {
        v79 = cam_mem_trace_alloc(96, 0xCC0u, 0, "cam_cpas_get_custom_dt_info", 0x660u);
        a3[202] = (const char *)v79;
        if ( v79 )
          goto LABEL_153;
      }
      else
      {
        v85 = _kvmalloc_node_noprof(96, 0, 3520, 0xFFFFFFFFLL);
        a3[202] = (const char *)v85;
        if ( v85 )
        {
LABEL_153:
          v80 = of_property_read_variable_u32_array(v6, "rt-wr-priority-min", &v108, 1, 0);
          if ( (v80 & 0x80000000) != 0 )
          {
            v86 = "Invalid min Qos priority rc %d";
            v87 = v80;
            v88 = 1648;
          }
          else
          {
            *a3[202] = (char)v108;
            v81 = of_property_read_variable_u32_array(v6, "rt-wr-priority-max", &v108, 1, 0);
            if ( (v81 & 0x80000000) == 0 )
            {
              *((_BYTE *)a3[202] + 1) = (_BYTE)v108;
              v82 = of_property_read_variable_u32_array(v6, "rt-wr-priority-clamp", &v108, 1, 0);
              if ( (v82 & 0x80000000) != 0 )
              {
                v52 = v82;
                v90 = "Invalid clamp Qos priority rc %d";
                v91 = 1664;
                goto LABEL_250;
              }
              *((_BYTE *)a3[202] + 2) = (_BYTE)v108;
              v83 = of_property_read_variable_u32_array(v6, "rt-wr-slope-factor", &v108, 1, 0);
              if ( (v83 & 0x80000000) != 0 )
              {
                v52 = v83;
                v90 = "Invalid slope factor rc %d";
                v91 = 1672;
                goto LABEL_250;
              }
              v75 = (unsigned int)v108;
              if ( (unsigned int)v108 >= 0x65 )
              {
                v72 = "Invalid slope factor value %d";
                v73 = 0x20000;
                v74 = 1677;
LABEL_159:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                  3,
                  v73,
                  1,
                  "cam_cpas_get_custom_dt_info",
                  v74,
                  v72,
                  v75);
                v52 = -22;
                goto LABEL_251;
              }
              *((_BYTE *)a3[202] + 3) = (_BYTE)v108;
              if ( (debug_mdl & 4) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 4,
                  4,
                  "cam_cpas_get_custom_dt_info",
                  1688,
                  "SmartQoS enabled, priority min=%u, max=%u, clamp=%u, slope factor=%u",
                  *(unsigned __int8 *)a3[202],
                  *((unsigned __int8 *)a3[202] + 1),
                  *((unsigned __int8 *)a3[202] + 2),
                  *((unsigned __int8 *)a3[202] + 3));
              v94 = of_property_read_variable_u32_array(v6, "rt-wr-leaststressed-clamp-threshold", &v108, 1, 0);
              if ( (v94 & 0x80000000) != 0 )
              {
                v52 = v94;
                v90 = "Invalid leaststressed clamp threshold rc %d";
                v91 = 1693;
                goto LABEL_250;
              }
              *((_BYTE *)a3[202] + 4) = (_BYTE)v108;
              v95 = of_property_read_variable_u32_array(v6, "rt-wr-moststressed-clamp-threshold", &v108, 1, 0);
              if ( (v95 & 0x80000000) != 0 )
              {
                v52 = v95;
                v90 = "Invalid moststressed clamp threshold rc %d";
                v91 = 1701;
                goto LABEL_250;
              }
              *((_BYTE *)a3[202] + 5) = (_BYTE)v108;
              if ( (debug_mdl & 4) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 4,
                  4,
                  "cam_cpas_get_custom_dt_info",
                  1709,
                  "leaststressed_clamp_th=%u, moststressed_clamp_th=%u",
                  *((unsigned __int8 *)a3[202] + 4),
                  *((unsigned __int8 *)a3[202] + 5));
              v96 = of_property_read_variable_u32_array(v6, "rt-wr-highstress-indicator-threshold", &v108, 1, 0);
              if ( (v96 & 0x80000000) != 0 )
              {
                v52 = v96;
                v90 = "Invalid highstress indicator threshold rc %d";
                v91 = 1714;
                goto LABEL_250;
              }
              v75 = (unsigned int)v108;
              if ( (unsigned int)v108 >= 0x65 )
              {
                v72 = "Invalid highstress indicator threshold value %d";
                v73 = 0x20000;
                v74 = 1719;
                goto LABEL_159;
              }
              *((_BYTE *)a3[202] + 6) = (_BYTE)v108;
              v102 = of_property_read_variable_u32_array(v6, "rt-wr-lowstress-indicator-threshold", &v108, 1, 0);
              if ( (v102 & 0x80000000) != 0 )
              {
                v52 = v102;
                v90 = "Invalid lowstress indicator threshold rc %d";
                v91 = 1728;
                goto LABEL_250;
              }
              v75 = (unsigned int)v108;
              if ( (unsigned int)v108 >= 0x65 )
              {
                v72 = "Invalid lowstress indicator threshold value %d";
                v73 = 0x20000;
                v74 = 1733;
                goto LABEL_159;
              }
              *((_BYTE *)a3[202] + 7) = (_BYTE)v108;
              v103 = of_property_read_variable_u32_array(v6, "rt-wr-bw-ratio-scale-factor", &v108, 1, 0);
              if ( (v103 & 0x80000000) != 0 )
              {
                v52 = v103;
                v90 = "Invalid bw ratio scale factor rc %d";
                v91 = 1742;
                goto LABEL_250;
              }
              v104 = debug_mdl;
              *((_BYTE *)a3[202] + 8) = (_BYTE)v108;
              if ( (v104 & 4) != 0 && !debug_priority )
                ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v104 & 4,
                  4,
                  "cam_cpas_get_custom_dt_info",
                  1751,
                  "highstress_indicator_th=%u, lowstress_indicator_th=%u, scale factor=%u",
                  *((unsigned __int8 *)a3[202] + 6),
                  *((unsigned __int8 *)a3[202] + 7),
                  *((unsigned __int8 *)a3[202] + 8));
LABEL_164:
              if ( (of_property_read_variable_u32_array(v6, "enable-cam-drv", (char *)&v110 + 4, 1, 0) & 0x80000000) == 0 )
              {
                v84 = BYTE4(v110);
                if ( (v110 & 0x100000000LL) != 0 )
                  *((_BYTE *)a3 + 1609) = 1;
                if ( (v84 & 2) != 0 )
                {
                  if ( (*((_BYTE *)a3 + 1609) & 1) == 0 )
                  {
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      4,
                      1,
                      "cam_cpas_get_custom_dt_info",
                      1768,
                      "DDR DRV needs to be enabled for Clock DRV");
                    v52 = -1;
                    goto LABEL_251;
                  }
                  *((_BYTE *)a3 + 1610) = 1;
                  v89 = cam_soc_util_cesta_populate_crm_device();
                  if ( v89 )
                  {
                    v52 = v89;
                    v90 = "Failed to populate cam cesta crm device rc %d";
                    v91 = 1777;
LABEL_250:
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                      3,
                      4,
                      1,
                      "cam_cpas_get_custom_dt_info",
                      v91,
                      v90,
                      v52);
                    goto LABEL_251;
                  }
                }
              }
              if ( (debug_mdl & 4) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 4,
                  4,
                  "cam_cpas_get_custom_dt_info",
                  1785,
                  "enable_cam_ddr_drv %d enable_cam_clk_drv %d cam_drv_en_mask_val %d",
                  *((unsigned __int8 *)a3 + 1609),
                  *((unsigned __int8 *)a3 + 1610),
                  HIDWORD(v110));
              LODWORD(v51) = cam_cpas_parse_node_tree(v5, v6, a3);
              if ( (_DWORD)v51 )
              {
                v52 = v51;
                result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           4,
                           1,
                           "cam_cpas_get_custom_dt_info",
                           1789,
                           "Node tree parsing failed rc: %d",
                           v51);
LABEL_234:
                cam_cpas_node_tree_cleanup(result, a3);
                goto LABEL_251;
              }
              if ( *((_BYTE *)a3 + 1608) == 1 )
              {
                if ( (unsigned int)*((unsigned __int8 *)a3[202] + 9) - 11 >= 0xFFFFFFF6 )
                {
                  if ( v5[695] )
                  {
                    v97 = debug_priority;
                    v98 = 0;
                    LOBYTE(v50) = debug_mdl;
                    v99 = (unsigned __int8 *)v5 + 3345;
                    do
                    {
                      if ( (v50 & 4) != 0 && !v97 )
                      {
                        if ( v98 > 5 )
                          goto LABEL_256;
                        LODWORD(v51) = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                         3,
                                         v50 & 4,
                                         4,
                                         "cam_cpas_get_custom_dt_info",
                                         1811,
                                         "[%d] : Port[%s] is_rt=%d",
                                         v98,
                                         *(const char **)(v99 - 249),
                                         *v99);
                        v97 = debug_priority;
                        LOBYTE(v50) = debug_mdl;
                        if ( (*v99 & 1) != 0 )
                          goto LABEL_208;
                      }
                      else
                      {
                        if ( v98 > 5 )
                          goto LABEL_256;
                        if ( (*v99 & 1) != 0 )
                          goto LABEL_208;
                      }
                      ++v98;
                      v99 += 408;
                    }
                    while ( v98 < v5[695] );
                  }
                  v92 = "RT AXI port not tagged, num ports %d";
                  v93 = 1821;
                }
                else
                {
                  v92 = "Invalid number of level1 nodes %d";
                  v93 = 1802;
                }
                result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                           3,
                           4,
                           1,
                           "cam_cpas_get_custom_dt_info",
                           v93,
                           v92);
                v52 = -22;
                goto LABEL_234;
              }
LABEL_208:
              LODWORD(v51) = of_property_count_elems_of_size(v6, "rpmh-bcm-info", 4);
              if ( (_DWORD)v51 == 5 )
              {
                v100 = a3 + 171;
                v101 = 0;
                if ( (unsigned int)of_property_read_u32_index(v6, "rpmh-bcm-info", 0, a3 + 171) )
                  goto LABEL_226;
                if ( (debug_mdl & 4) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 4,
                    4,
                    "cam_cpas_get_custom_dt_info",
                    1851,
                    "RPMH BCM Info [%d]=0x%x",
                    0,
                    *v100);
                v101 = 1;
                if ( (unsigned int)of_property_read_u32_index(v6, "rpmh-bcm-info", 1, (char *)a3 + 1372) )
                  goto LABEL_226;
                if ( (debug_mdl & 4) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 4,
                    4,
                    "cam_cpas_get_custom_dt_info",
                    1851,
                    "RPMH BCM Info [%d]=0x%x",
                    1,
                    *((_DWORD *)a3 + 343));
                v101 = 2;
                if ( (unsigned int)of_property_read_u32_index(v6, "rpmh-bcm-info", 2, a3 + 172) )
                  goto LABEL_226;
                if ( (debug_mdl & 4) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 4,
                    4,
                    "cam_cpas_get_custom_dt_info",
                    1851,
                    "RPMH BCM Info [%d]=0x%x",
                    2,
                    *((_DWORD *)a3 + 344));
                v101 = 3;
                if ( (unsigned int)of_property_read_u32_index(v6, "rpmh-bcm-info", 3, (char *)a3 + 1380) )
                  goto LABEL_226;
                if ( (debug_mdl & 4) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 4,
                    4,
                    "cam_cpas_get_custom_dt_info",
                    1851,
                    "RPMH BCM Info [%d]=0x%x",
                    3,
                    *((_DWORD *)a3 + 345));
                v101 = 4;
                if ( (unsigned int)of_property_read_u32_index(v6, "rpmh-bcm-info", 4, a3 + 173) )
                {
LABEL_226:
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    4,
                    1,
                    "cam_cpas_get_custom_dt_info",
                    1847,
                    "Incorrect rpmh info at %d, count=%d",
                    v101,
                    5);
                  *v100 = 0;
                }
                else if ( (debug_mdl & 4) != 0 && !debug_priority )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 4,
                    4,
                    "cam_cpas_get_custom_dt_info",
                    1851,
                    "RPMH BCM Info [%d]=0x%x",
                    4,
                    *((_DWORD *)a3 + 346));
                }
                goto LABEL_229;
              }
              LOBYTE(v50) = debug_mdl;
              if ( (debug_mdl & 4) == 0 || debug_priority )
              {
LABEL_229:
                result = cam_cpas_parse_sys_cache_uids(v6, a3);
                if ( !(_DWORD)result )
                  goto LABEL_8;
                v52 = result;
                *((_DWORD *)a3 + 342) = 0;
                goto LABEL_234;
              }
LABEL_257:
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v50 & 4,
                4,
                "cam_cpas_get_custom_dt_info",
                1858,
                "RPMH BCM info not available in DT, count=%d",
                v51);
              goto LABEL_229;
            }
            v86 = "Invalid max Qos priority rc %d";
            v87 = v81;
            v88 = 1656;
          }
          v52 = v87;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_get_custom_dt_info",
            v88,
            v86);
          goto LABEL_251;
        }
      }
      v52 = -12;
      goto LABEL_251;
    }
    v40 = "Domain ID configuration is expected for this target";
    v41 = 4;
    v42 = 1366;
    goto LABEL_122;
  }
  if ( (v13 & 1) != 0 )
  {
    v26 = "Mismatch in domain-id mapping, found %d number of entries";
    v27 = v13;
    v28 = 1199;
LABEL_39:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_parse_domain_id_mapping",
      v28,
      v26,
      v27);
    goto LABEL_40;
  }
  *((_DWORD *)a3 + 410) = v13 >> 1;
  if ( v13 < 0xB )
  {
    if ( mem_trace_en == 1 )
      v32 = cam_mem_trace_alloc(4 * v13, 0xCC0u, 0, "cam_cpas_parse_domain_id_mapping", 0x4C0u);
    else
      v32 = _kvmalloc_node_noprof(8LL * *((unsigned int *)a3 + 410), 0, 3520, 0xFFFFFFFFLL);
    v33 = *((_DWORD *)a3 + 410);
    a3[204] = (const char *)v32;
    if ( !v32 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_parse_domain_id_mapping",
        1220,
        "Error allocating memory for %u domain-id mapping(s)",
        v33);
      v29 = -12;
      goto LABEL_41;
    }
    if ( v33 )
    {
      v34 = 0;
      v35 = 1;
      while ( 1 )
      {
        v36 = (unsigned int *)&a3[204][8 * v34];
        if ( (unsigned int)of_property_read_u32_index(v6, "domain-id", v35 - 1, v36) )
        {
          v26 = "Error reading domain-id type entry at pos %d";
          v28 = 1232;
          goto LABEL_67;
        }
        v27 = *v36;
        if ( (unsigned int)v27 >= 2 )
        {
          v26 = "Unexpected domain id type: %u";
          v28 = 1239;
          goto LABEL_39;
        }
        if ( (unsigned int)of_property_read_u32_index(v6, "domain-id", v35, v36 + 1) )
          break;
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_parse_domain_id_mapping",
            1253,
            "Domain-id type: %u, mapping: %u at pos: %d",
            *v36,
            v36[1],
            v34);
        ++v34;
        v35 += 2;
        if ( v34 >= *((_DWORD *)a3 + 410) )
          goto LABEL_61;
      }
      v26 = "Error reading domain-id mapping id at pos %d";
      v28 = 1247;
LABEL_67:
      v27 = v34;
      goto LABEL_39;
    }
LABEL_61:
    *((_BYTE *)a3 + 1644) = 1;
    goto LABEL_16;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_parse_domain_id_mapping",
    1209,
    "Number of domain id types: %u more than supported: %d",
    v13 >> 1,
    5);
LABEL_40:
  v29 = -22;
LABEL_41:
  v30 = (unsigned __int8)mem_trace_en;
  v31 = (char *)a3[204];
  *((_DWORD *)a3 + 410) = 0;
  if ( v30 == 1 )
    cam_mem_trace_free(v31, 0);
  else
    kvfree(v31);
  a3[204] = nullptr;
  result = v29;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
