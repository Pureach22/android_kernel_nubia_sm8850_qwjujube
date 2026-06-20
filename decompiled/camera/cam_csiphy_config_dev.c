__int64 __fastcall cam_csiphy_config_dev(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 v5; // x20
  __int64 v6; // x26
  int v7; // w27
  int v8; // w24
  const char *v9; // x9
  unsigned __int16 v10; // w23
  const char *v11; // x8
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x12
  __int64 v15; // x12
  unsigned int v16; // w9
  unsigned int v17; // w21
  _QWORD *v18; // x8
  __int64 v19; // x20
  unsigned int v20; // w10
  unsigned int v21; // w9
  __int64 v22; // x8
  unsigned int v23; // w0
  __int64 v24; // x8
  __int64 *v25; // x23
  unsigned __int64 v26; // x21
  __int64 v27; // x24
  unsigned int v28; // w20
  unsigned __int64 v29; // x25
  unsigned __int64 v30; // x8
  unsigned int v31; // w26
  __int64 *v32; // x27
  __int64 v33; // x22
  __int64 v35; // x8
  int v36; // w24
  int v37; // w20
  _DWORD *v38; // x9
  unsigned int v39; // w23
  int v40; // w22
  __int64 v41; // x25
  unsigned int v42; // w27
  __int64 v43; // x0
  _BOOL4 v45; // w8
  unsigned int v46; // w28
  int v47; // w9
  int v48; // w8
  unsigned int v49; // w6
  int v50; // w10
  unsigned int *v51; // x8
  const char *v52; // x9
  __int64 v53; // x9
  __int64 v54; // x10
  __int64 v55; // x8
  __int64 v56; // x10
  __int64 v57; // x21
  int *v58; // x22
  __int64 v59; // x20
  __int64 v60; // x0
  const char *v61; // x5
  __int64 v62; // x4
  __int64 *v63; // x10
  __int64 v64; // x2
  __int64 v65; // x23
  int v66; // w21
  __int64 v67; // x8
  int v68; // w13
  __int64 v69; // x8
  int v70; // w22
  unsigned int v71; // w0
  unsigned int v72; // w19
  __int64 result; // x0
  __int16 v74; // w8
  int v75; // w6
  unsigned int v76; // w19
  __int64 v77; // x10
  __int64 v78; // x24
  __int64 v79; // x25
  __int64 v80; // x8
  int v81; // w28
  __int64 v82; // x27
  unsigned int *v83; // x9
  unsigned int v84; // w8
  unsigned int v85; // w22
  __int64 v86; // x23
  unsigned int v87; // w8
  _QWORD *v88; // x8
  __int64 v89; // x24
  int v90; // w25
  int v91; // w26
  _DWORD *v92; // x27
  int v93; // w9
  unsigned int v94; // w8
  __int64 v95; // x0
  __int64 v96; // x1
  __int64 v97; // x0
  const char *v98; // x6
  const char *v99; // x6
  unsigned int v100; // w20
  __int64 v101; // [xsp+0h] [xbp-F0h]
  const char *v102; // [xsp+10h] [xbp-E0h]
  const char *v103; // [xsp+18h] [xbp-D8h]
  int v104; // [xsp+34h] [xbp-BCh]
  __int64 v105; // [xsp+38h] [xbp-B8h]
  unsigned int v107; // [xsp+4Ch] [xbp-A4h]
  __int64 v108; // [xsp+50h] [xbp-A0h]
  int v109; // [xsp+58h] [xbp-98h]
  unsigned int v110; // [xsp+5Ch] [xbp-94h]
  __int64 v111; // [xsp+60h] [xbp-90h]
  __int64 v112; // [xsp+68h] [xbp-88h]
  __int64 v113; // [xsp+70h] [xbp-80h]
  unsigned __int16 v114; // [xsp+78h] [xbp-78h]
  int v115; // [xsp+7Ch] [xbp-74h]
  __int64 v116; // [xsp+88h] [xbp-68h]
  unsigned int v117; // [xsp+90h] [xbp-60h]
  int v118; // [xsp+94h] [xbp-5Ch]
  __int64 v119; // [xsp+98h] [xbp-58h]
  __int64 v120; // [xsp+A0h] [xbp-50h]
  __int64 v121; // [xsp+A8h] [xbp-48h]
  int v122; // [xsp+B4h] [xbp-3Ch]
  unsigned __int64 v123; // [xsp+B8h] [xbp-38h] BYREF
  __int64 v124; // [xsp+C0h] [xbp-30h]
  unsigned __int16 v125[2]; // [xsp+C8h] [xbp-28h] BYREF
  unsigned int v126; // [xsp+CCh] [xbp-24h] BYREF
  _DWORD v127[2]; // [xsp+D0h] [xbp-20h] BYREF
  __int64 v128; // [xsp+D8h] [xbp-18h]
  __int64 v129; // [xsp+E0h] [xbp-10h]

  v129 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 1200);
  v125[0] = 0;
  if ( (debug_mdl & 0x8000) == 0 || debug_priority )
  {
    if ( v5 )
      goto LABEL_4;
LABEL_181:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_config_dev",
      2059,
      "csiphybase NULL");
    goto LABEL_182;
  }
  ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    (unsigned __int16)debug_mdl & 0x8000,
    4,
    "cam_csiphy_config_dev",
    2057,
    "ENTER");
  if ( !v5 )
    goto LABEL_181;
LABEL_4:
  cam_csiphy_update_lane_selection(a1, a2, 1);
  if ( a2 > 2 )
    goto LABEL_188;
  v6 = a1 + 600 + 104LL * a2;
  v104 = *(_DWORD *)(v6 + 24);
  cam_csiphy_get_settle_count(a1, a2, v125);
  v7 = *(unsigned __int8 *)(v6 + 2);
  v8 = *(unsigned __int8 *)(v6 + 28);
  if ( !*(_BYTE *)(v6 + 2) )
  {
LABEL_122:
    if ( v104 )
    {
      if ( !a1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_program_cphy_common_ctrl_settings",
          1573,
          "Device is NULL");
LABEL_138:
        result = 0;
        v74 = debug_mdl;
        if ( (debug_mdl & 0x8000) == 0 )
          goto LABEL_183;
LABEL_175:
        if ( debug_priority )
          goto LABEL_183;
        v76 = result;
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v74 & 0x8000,
          4,
          "cam_csiphy_config_dev",
          2124,
          "EXIT");
        goto LABEL_136;
      }
      if ( a3 >= 3u )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_program_cphy_common_ctrl_settings",
          1579,
          "Datarate variant Idx: %u can not exceed %u",
          a3,
          2);
        goto LABEL_138;
      }
      if ( *(unsigned __int8 *)(a1 + 932) < 8u )
      {
        v77 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 120LL) + 8LL) + 408LL * *(unsigned __int8 *)(a1 + 102);
        v78 = *(_QWORD *)(v77 + 16);
        if ( v78 >= 1 )
        {
          v79 = *(_QWORD *)(a1 + 1200);
          v80 = 0;
          v81 = 1;
          v82 = *(_QWORD *)(v77 + 24LL * *(unsigned __int8 *)(a1 + 932) + 8LL * a3 + 24);
          do
          {
            v83 = (unsigned int *)(v82 + 16 * v80);
            v84 = v83[3];
            v86 = *v83;
            v85 = v83[1];
            if ( v84 == 1024 )
            {
              v87 = *(_DWORD *)(a1 + 932);
              if ( v87 > 7 )
                goto LABEL_188;
              if ( ((*((_QWORD *)&g_phy_data + 7 * v87 + 3) >> *(_BYTE *)(a1 + 102)) & 1) != 0 )
              {
                cam_io_w_mb(v85, v79 + v86);
                if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
                  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    (unsigned __int16)debug_mdl & 0x8000,
                    4,
                    "cam_csiphy_program_cphy_common_ctrl_settings",
                    1613,
                    "CSIPHY: %u configuring new aux setting reg_addr: 0x%x reg_val: 0x%x",
                    *(_DWORD *)(a1 + 932),
                    v86,
                    v85);
              }
            }
            else if ( v84 == 1 )
            {
              cam_io_w_mb(v85, v79 + v86);
            }
            v80 = v81++;
          }
          while ( v78 > v80 );
        }
        result = 0;
        v74 = debug_mdl;
        if ( (debug_mdl & 0x8000) == 0 )
          goto LABEL_183;
        goto LABEL_175;
      }
LABEL_188:
      __break(0x5512u);
    }
    v63 = *(__int64 **)(a1 + 112);
    v64 = v125[0];
    v65 = *(_QWORD *)(a1 + 1200);
    v66 = *(unsigned __int8 *)(a1 + 600 + 104LL * a2 + 90);
    v67 = *v63;
    v128 = v63[7];
    v68 = *(_DWORD *)(v67 + 48);
    if ( v66 )
      v69 = 104;
    else
      v69 = 108;
    v70 = *(_DWORD *)((char *)v63 + v69);
    v127[0] = v68;
    v127[1] = v70;
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    {
      if ( v66 )
        v99 = "N";
      else
        v99 = "Y";
      v100 = v125[0];
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_program_dphy_clk_lane",
        1894,
        "Prgm dphy clk lane, primary : %s",
        v99);
      v64 = v100;
    }
    v71 = cam_csiphy_program_lane_settings(a1, a2, v64, v8 != 0, v127);
    if ( v71 )
    {
      v72 = v71;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_program_dphy_clk_lane",
        1899,
        "Error while programming DPHY clk lane");
      result = v72;
      v74 = debug_mdl;
      if ( (debug_mdl & 0x8000) == 0 )
        goto LABEL_183;
      goto LABEL_175;
    }
    v88 = *(_QWORD **)(a1 + 112);
    v89 = v88[9];
    v90 = *(_DWORD *)(*v88 + 52LL);
    if ( !v90 || !v89 )
    {
      if ( v89 )
        v98 = "Y";
      else
        v98 = "N";
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_program_dphy_clk_lane",
        1909,
        "Invalid clk reg params, num offsets: %u, reg_array: %s",
        v98);
      result = 4294967274LL;
      v74 = debug_mdl;
      if ( (debug_mdl & 0x8000) == 0 )
        goto LABEL_183;
      goto LABEL_175;
    }
    v91 = 0;
    while ( 1 )
    {
      v92 = (_DWORD *)(v89 + 16LL * v91);
      v93 = v92[3];
      v94 = *v92 + v70;
      if ( v93 == 0x8000 )
      {
        v96 = v65 + v94;
        if ( v66 )
          v95 = 14;
        else
          v95 = 4;
      }
      else
      {
        if ( v93 != 1 )
        {
          if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              (unsigned __int16)debug_mdl & 0x8000,
              4,
              "cam_csiphy_program_dphy_clk_lane",
              1928,
              "Do Nothing");
          goto LABEL_168;
        }
        v95 = (unsigned int)v92[1];
        v96 = v65 + v94;
      }
      cam_io_w_mb(v95, v96);
LABEL_168:
      v97 = (unsigned int)v92[2];
      if ( (int)v97 >= 1 )
        usleep_range_state(v97, (int)v97 + 5, 2);
      if ( v90 == ++v91 )
        goto LABEL_138;
    }
  }
  v9 = "Y";
  v10 = *(_WORD *)v6;
  v11 = "CPHY";
  if ( !v104 )
    v9 = "N";
  v12 = 48;
  if ( v104 )
    v13 = 56;
  else
    v13 = 48;
  v103 = v9;
  v113 = v13;
  if ( v104 )
    v14 = 64;
  else
    v14 = 56;
  if ( !v104 )
  {
    v12 = 64;
    v11 = "DPHY";
  }
  v112 = v14;
  v126 = 0;
  v123 = 0;
  v124 = 0;
  v105 = v12;
  v15 = 72;
  if ( v104 )
    v15 = 56;
  v102 = v11;
  v111 = v15;
  v109 = v8;
  v110 = a2;
  v108 = a1 + 600 + 104LL * a2;
  while ( 1 )
  {
    cam_csiphy_get_lane_enable(a1, a2, v10 & 0xF, &v126, 0);
    v16 = __clz(__rbit32(v126));
    if ( v126 )
      v17 = v16;
    else
      v17 = -1;
    v126 = v17;
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_config_dev",
        2087,
        "Program  CSIPHY[%u] lane settings for ln%u, is_3phase: %s",
        *(_DWORD *)(a1 + 932),
        v17,
        v103);
      if ( (v17 & 0xFFF8) != 0 )
        goto LABEL_188;
    }
    else if ( (v17 & 0xFFF8) != 0 )
    {
      goto LABEL_188;
    }
    v18 = *(_QWORD **)(a1 + 112);
    v19 = v17 & 7;
    v20 = *(_DWORD *)(*v18 + v113);
    v21 = *((_DWORD *)v18 + v19 + 20);
    v22 = *(_QWORD *)((char *)v18 + v112);
    v123 = __PAIR64__(v21, v20);
    v124 = v22;
    v23 = cam_csiphy_program_lane_settings(a1, a2, v125[0], v8 != 0, &v123);
    if ( v23 )
    {
      v75 = *(_DWORD *)(a1 + 932);
      v76 = v23;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_config_dev",
        2097,
        "Error in programming CSIPHY[%u] settings for ln%u, is_3phase : %s",
        v75,
        v17,
        v103);
LABEL_136:
      result = v76;
      goto LABEL_183;
    }
    if ( *(_DWORD *)(v6 + 24) )
      break;
LABEL_108:
    if ( *(_WORD *)(a1 + 4734) )
    {
      v53 = *(_QWORD *)(a1 + 112);
      v54 = *(_QWORD *)(v53 + 48);
      v55 = *(_QWORD *)(v54 + v111);
      if ( v55 )
      {
        v56 = *(_QWORD *)(v54 + v105);
        if ( (int)v56 >= 1 )
        {
          v57 = v56 & 0x7FFFFFFF;
          v58 = (int *)(v55 + 8);
          v59 = *(_QWORD *)(a1 + 1200) + *(unsigned int *)(v53 + 4 * v19 + 80);
          do
          {
            cam_io_w_mb((unsigned int)*(v58 - 1), v59 + *(v58 - 2));
            v60 = *v58;
            if ( (_DWORD)v60 )
              usleep_range_state(v60, (int)v60 + 5, 2);
            --v57;
            v58 += 4;
          }
          while ( v57 );
        }
      }
      else if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          (unsigned __int16)debug_mdl & 0x8000,
          4,
          "__cam_csiphy_prgm_bist_reg",
          1960,
          "No Bist Settings available for %s",
          v102);
      }
    }
    --v7;
    v10 >>= 4;
    if ( !(_BYTE)v7 )
      goto LABEL_122;
  }
  LOWORD(v127[0]) = 0;
  if ( !a1 || (v24 = *(_QWORD *)(a1 + 112)) == 0 )
  {
    v61 = "Device is NULL";
    v62 = 1639;
    goto LABEL_178;
  }
  v114 = v10;
  v25 = *(__int64 **)(v24 + 120);
  v115 = v7;
  v116 = v17 & 7;
  if ( !v25 )
  {
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_cphy_data_rate_config",
        1645,
        "Data rate specific register table not available");
    goto LABEL_107;
  }
  if ( *(_DWORD *)(a1 + 932) >= 8u )
  {
    v61 = "soc_info.index:%d >= MAX_CSIPHY:%d ";
    v62 = 1651;
    goto LABEL_178;
  }
  v26 = *(_QWORD *)(v6 + 16);
  v27 = *v25;
  v121 = *(_QWORD *)(a1 + 1200);
  cam_csiphy_get_settle_count(a1, a2, v127);
  v28 = *(unsigned __int8 *)(a1 + 932);
  v122 = *(_DWORD *)(v6 + 92);
  if ( (debug_mdl & 0x8000) == 0 || debug_priority )
  {
    v29 = v27 - 1;
    if ( v27 >= 1 )
      goto LABEL_35;
LABEL_107:
    v8 = v109;
    a2 = v110;
    v6 = v108;
    v7 = v115;
    v10 = v114;
    v19 = v116;
    goto LABEL_108;
  }
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    (unsigned __int16)debug_mdl & 0x8000,
    4,
    "cam_csiphy_cphy_data_rate_config",
    1668,
    "required data rate : %llu",
    v26);
  v29 = v27 - 1;
  if ( v27 < 1 )
    goto LABEL_107;
LABEL_35:
  if ( v28 > 8 )
    goto LABEL_188;
  v30 = 0;
  v31 = 0;
  while ( 1 )
  {
    v32 = (__int64 *)(v25[1] + 408 * v30);
    v33 = *v32;
    if ( v26 <= *v32 || v29 <= v30 )
      break;
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_cphy_data_rate_config",
        1680,
        "Skipping table [%d] with BW: %llu, Required data_rate: %llu",
        v31,
        v33,
        v26);
    v30 = ++v31;
    if ( v27 <= (unsigned __int64)v31 )
      goto LABEL_107;
  }
  v120 = v32[1];
  if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      (unsigned __int16)debug_mdl & 0x8000,
      4,
      "cam_csiphy_cphy_data_rate_config",
      1685,
      "table[%d] BW : %llu Selected",
      v31,
      v33);
  if ( strstr(&csiphy_qmargin, "default") )
    *(_QWORD *)(a1 + 4720) = v33;
  if ( a3 >= 3u )
  {
    v61 = "Datarate variant Idx: %u can not exceed %u";
    v62 = 1692;
    goto LABEL_178;
  }
  v119 = v32[3 * v28 + 27 + a3];
  if ( v119 )
  {
    if ( v120 >= 1 )
    {
      v35 = 0;
      v36 = 0;
      v37 = 1;
      v117 = HIBYTE(LOWORD(v127[0]));
      v118 = *(_DWORD *)(*(_QWORD *)(a1 + 112) + 4 * v116 + 80);
      v107 = LOBYTE(v127[0]);
      do
      {
        v38 = (_DWORD *)(v119 + 16 * v35);
        v39 = v38[1];
        v41 = (unsigned int)v38[2];
        v40 = v38[3];
        v42 = *v38 + v118;
        if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            (unsigned __int16)debug_mdl & 0x8000,
            4,
            "cam_csiphy_cphy_data_rate_config",
            1711,
            "param_type: %d writing reg : %x val : %x delay: %dus",
            v40,
            v42,
            v39,
            v41);
        if ( v40 <= 7 )
        {
          v43 = v39;
          if ( v40 == 1 )
            goto LABEL_77;
          v43 = v107;
          if ( v40 == 4 )
            goto LABEL_77;
        }
        else
        {
          v43 = v117;
          switch ( v40 )
          {
            case 8:
              goto LABEL_77;
            case 0x2000:
              v43 = v39;
              if ( v122 == 1 )
                goto LABEL_77;
              goto LABEL_78;
            case 0x1000:
              v43 = v39;
              if ( !v122 )
LABEL_77:
                cam_io_w_mb(v43, v121 + v42);
LABEL_78:
              v45 = v40 == 10240 && v122 == 1;
              if ( v40 != 2048 && !v45 )
                goto LABEL_96;
              goto LABEL_86;
          }
        }
        if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            (unsigned __int16)debug_mdl & 0x8000,
            4,
            "cam_csiphy_cphy_data_rate_config",
            1736,
            "Do Nothing");
        if ( v40 != 6144 || v122 )
          goto LABEL_78;
LABEL_86:
        v46 = v39;
        if ( *(_BYTE *)(a1 + 4600) == 1 )
        {
          v47 = *(_DWORD *)(a1 + 4596);
          v48 = *(_DWORD *)(a1 + 4592);
          v49 = *(_DWORD *)(a1 + 932);
          if ( v47 == 1 )
            v50 = *(_DWORD *)(a1 + 4592);
          else
            v50 = -v48;
          v46 = v50 + v39;
          if ( (int)(v50 + v39) <= 0 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x8000,
              2,
              "__cam_csiphy_compute_cdr_value",
              1553,
              "CSIPHY%u invalid cdr: %u tolerance: %u op_type: %u",
              v49,
              v39,
              v48,
              v47);
            v49 = *(_DWORD *)(a1 + 932);
            v46 = 0;
          }
          if ( v49 > 7 )
            goto LABEL_188;
          *((_DWORD *)&g_phy_data + 14 * v49 + 8) = v46;
        }
        cam_io_w_mb(v46, v121 + v42);
        if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
        {
          v52 = "Y";
          if ( !*(_BYTE *)(a1 + 4600) )
            v52 = "N";
          LODWORD(v101) = v46;
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64, const char *))cam_print_log)(
            3,
            (unsigned __int16)debug_mdl & 0x8000,
            4,
            "cam_csiphy_cphy_data_rate_config",
            1770,
            "CSIPHY: %u CDR reg_addr: 0x%x reg_val: 0x%x sweep test: %s",
            *(unsigned int *)(a1 + 932),
            v42,
            v101,
            v52);
        }
LABEL_96:
        if ( strstr(&csiphy_qmargin, "default") )
        {
          if ( v40 == 2048 )
          {
            v51 = (unsigned int *)(a1 + 4624 + 16LL * v36++);
            *v51 = v42;
            v51[1] = v39;
            v51[2] = v41;
          }
          if ( (int)v41 < 1 )
            goto LABEL_58;
        }
        else if ( (int)v41 < 1 )
        {
          goto LABEL_58;
        }
        usleep_range_state(v41, (int)v41 + 5, 2);
LABEL_58:
        v35 = v37++;
      }
      while ( v120 > v35 );
    }
    *(_BYTE *)(a1 + 102) = v31;
    goto LABEL_107;
  }
  v61 = "Datarate settings are null.";
  v62 = 1699;
LABEL_178:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_csiphy_cphy_data_rate_config",
    v62,
    v61);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_csiphy_config_dev",
    2107,
    "Date rate specific configuration failed rc: %d",
    -22);
LABEL_182:
  result = 4294967274LL;
LABEL_183:
  _ReadStatusReg(SP_EL0);
  return result;
}
