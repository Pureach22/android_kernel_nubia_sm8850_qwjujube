__int64 __fastcall cam_csiphy_core_cfg(__int64 a1, int *a2)
{
  __int64 v2; // x19
  size_t v3; // x20
  _BYTE *v4; // x23
  _DWORD *v5; // x24
  unsigned __int8 *v6; // x25
  _QWORD *v7; // x26
  __int64 v8; // x8
  unsigned int v9; // w6
  unsigned int *v10; // x28
  __int64 v11; // x22
  int v13; // w6
  int *v14; // x8
  __int64 v15; // x9
  unsigned int v16; // w10
  const char *v17; // x5
  __int64 v18; // x4
  const char *v19; // x5
  __int64 v20; // x4
  int v21; // w9
  __int64 v22; // x1
  __int64 v23; // x7
  __int64 v24; // x3
  __int64 v25; // x4
  size_t v26; // x0
  __int64 v27; // x0
  int v28; // w9
  __int64 v29; // x6
  __int64 v30; // x7
  const char *v31; // x5
  __int64 v32; // x4
  __int64 v33; // x1
  const char *v34; // x5
  __int64 v35; // x4
  __int64 v36; // x0
  unsigned int v37; // w9
  int v38; // w11
  const char *v39; // x5
  __int64 v40; // x4
  unsigned int v41; // w6
  unsigned int v42; // w7
  __int64 v43; // x0
  const char *v44; // x5
  __int64 v45; // x4
  _QWORD *v46; // x21
  __int64 v47; // x22
  const char *v48; // x5
  __int64 v49; // x4
  unsigned int v50; // w21
  int drv_enable; // w0
  __int64 v52; // x3
  __int64 v53; // x4
  const char *v54; // x5
  __int64 v55; // x4
  unsigned int v56; // w21
  __int64 v57; // x8
  __int64 v58; // x9
  __int64 v59; // x22
  __int64 v60; // x0
  __int64 v61; // x2
  __int64 v62; // x22
  int v63; // w10
  int v64; // w9
  unsigned int v65; // w1
  int v66; // w0
  int v67; // w0
  const char *v68; // x5
  __int64 v69; // x4
  __int64 v70; // x6
  __int64 v71; // x0
  const char *v72; // x5
  __int64 v73; // x4
  __int64 v74; // x6
  int v75; // w9
  __int64 v76; // x22
  __int64 v77; // x8
  int v78; // w9
  _DWORD *v79; // x9
  unsigned int v80; // w22
  int v81; // w0
  int v82; // w23
  char *string_from_level; // x20
  char *v84; // x0
  int v85; // w8
  __int64 v86; // x22
  char *v87; // x0
  unsigned int v88; // w9
  int v89; // w0
  __int64 v90; // x21
  long double v91; // q0
  long double v92; // q1
  int16x8_t v93; // q2
  unsigned int v94; // w9
  int v95; // w0
  unsigned int v96; // w6
  int v97; // w0
  __int16 v98; // w9
  unsigned int v99; // w21
  int device_hdl; // w0
  int v101; // w11
  __int64 v102; // x9
  int *v103; // x8
  unsigned int v104; // w6
  int v105; // w7
  __int16 v106; // w9
  int v107; // w0
  unsigned int v108; // w0
  __int64 v109; // x6
  const char *v110; // x10
  int v111; // w0
  int v112; // w0
  unsigned int v113; // w6
  int v114; // w10
  __int64 v115; // x1
  __int64 v116; // x8
  char v117; // w0
  int v118; // w8
  __int64 v119; // x6
  const char *v120; // x5
  __int64 v121; // x1
  __int64 v122; // x2
  __int64 v123; // x4
  long double v124; // q0
  long double v125; // q1
  int16x8_t v126; // q2
  unsigned __int16 v127; // w9
  __int64 v128; // x8
  char v129; // w0
  __int64 v130; // x6
  const char *v131; // x5
  __int64 v132; // x1
  __int64 v133; // x2
  __int64 v134; // x4
  __int64 v135; // x8
  char v136; // w0
  __int64 v137; // x6
  const char *v138; // x5
  __int64 v139; // x1
  __int64 v140; // x2
  __int64 v141; // x4
  int v142; // w8
  unsigned int v143; // w6
  unsigned __int64 StatusReg; // x20
  __int64 v145; // x22
  __int64 v146; // x8
  __int128 v148; // [xsp+48h] [xbp-58h] BYREF
  __int64 v149; // [xsp+58h] [xbp-48h]
  __int64 v150; // [xsp+60h] [xbp-40h]
  __int64 v151; // [xsp+68h] [xbp-38h]
  __int64 v152; // [xsp+70h] [xbp-30h] BYREF
  _QWORD v153[2]; // [xsp+78h] [xbp-28h] BYREF
  __int64 v154; // [xsp+88h] [xbp-18h]
  int v155; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v156; // [xsp+98h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v156 = v8;
  v155 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_core_cfg",
      2691,
      "Invalid input args");
    LODWORD(v3) = -22;
    goto LABEL_315;
  }
  if ( a2[2] != 1 )
  {
    v19 = "Invalid handle type: %d";
    v20 = 2697;
LABEL_27:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_core_cfg",
      v20,
      v19);
    LODWORD(v3) = -22;
    goto LABEL_315;
  }
  v9 = *(_DWORD *)(a1 + 932);
  if ( v9 >= 8 )
    goto LABEL_303;
  v5 = &g_phy_data;
  if ( !*((_QWORD *)&g_phy_data + 7 * v9) )
  {
    v19 = "CSIPHY hw is not avaialble at index: %d";
    v20 = 2709;
    goto LABEL_27;
  }
  v10 = *(unsigned int **)(**(_QWORD **)(a1 + 112) + 16LL);
  if ( v10 )
  {
    v7 = &unk_393000;
    v11 = *(_QWORD *)(a1 + 1200);
    v6 = (unsigned __int8 *)(a1 + 4096);
    v4 = &unk_393000;
    v2 = a1;
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_core_cfg",
        2723,
        "Opcode received: %d",
        *a2);
      a1 = v2;
    }
    mutex_lock(a1 + 24);
    v13 = *a2;
    v14 = a2;
    if ( *a2 > 260 )
    {
      if ( v13 <= 344 )
      {
        if ( v13 == 261 )
        {
          v149 = 0;
          v148 = 0u;
          if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
          {
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              (unsigned __int16)debug_mdl & 0x8000,
              4,
              "cam_csiphy_core_cfg",
              3094,
              "CONFIG_DEV Called");
            v14 = a2;
          }
          if ( inline_copy_from_user_8((int)&v148, *((_QWORD *)v14 + 2), 0x18u) )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x8000,
              1,
              "cam_csiphy_core_cfg",
              3097,
              "Couldn't copy the Entire Config From User");
            LODWORD(v3) = -14;
          }
          else
          {
            LODWORD(v3) = cam_cmd_buf_parser(v2, (__int64)&v148);
            if ( (v3 & 0x80000000) != 0 )
            {
              v17 = "Fail in cmd buf parser";
              v18 = 3102;
              goto LABEL_121;
            }
          }
          goto LABEL_312;
        }
        if ( v13 != 262 )
          goto LABEL_73;
        v21 = *(_DWORD *)(v2 + 80);
        *(_QWORD *)&v148 = 0;
        if ( !v21 )
        {
          v39 = "No valid devices to release";
          v40 = 3012;
          goto LABEL_92;
        }
        if ( inline_copy_from_user_8((int)&v148, *((_QWORD *)a2 + 2), 8u) )
        {
          LODWORD(v3) = -14;
LABEL_128:
          v71 = v2 + 24;
LABEL_314:
          mutex_unlock(v71);
          goto LABEL_315;
        }
        v56 = ((__int64 (__fastcall *)(__int64, _QWORD))cam_csiphy_get_instance_offset)(v2, DWORD1(v148));
        if ( (v56 & 0x80000000) == 0 )
        {
          LODWORD(v8) = *(unsigned __int8 *)(v2 + 96);
          if ( v56 < (unsigned int)v8 )
          {
            if ( v56 <= 2 )
            {
              v57 = v2;
              v58 = v2 + 104LL * v56;
              v59 = v58 + 600;
              if ( *(_BYTE *)(v58 + 603) )
              {
                cam_csiphy_program_secure_mode(v2, 0, v56);
                v57 = v2;
              }
              v60 = DWORD1(v148);
              *(_BYTE *)(v59 + 3) = 0;
              *(_QWORD *)(v57 + 8LL * v56 + 4504) = 0;
              *(_WORD *)(v57 + 4734) = 0;
              LODWORD(v3) = cam_destroy_device_hdl(v60);
              if ( (v3 & 0x80000000) != 0 )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x8000,
                  1,
                  "cam_csiphy_core_cfg",
                  3045,
                  "destroying the device hdl");
              *(_QWORD *)(v59 + 48) = -1;
              v62 = v2;
              cam_csiphy_reset_phyconfig_param(v2, v56, v61);
              v63 = *(_DWORD *)(v2 + 80);
              LOWORD(v8) = debug_mdl;
              v64 = debug_priority;
              if ( v63 )
              {
                *(_DWORD *)(v2 + 80) = v63 - 1;
                if ( (v8 & 0x8000) != 0 && !v64 )
                {
                  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    (unsigned __int16)v8 & 0x8000,
                    4,
                    "cam_csiphy_core_cfg",
                    3054,
                    "Acquire_cnt: %d",
                    v63 - 1);
                  v62 = v2;
                  if ( *(_DWORD *)(v2 + 80) )
                    goto LABEL_225;
                }
                else if ( v63 != 1 )
                {
                  goto LABEL_225;
                }
                LOWORD(v8) = debug_mdl;
                v64 = debug_priority;
              }
              if ( (v8 & 0x8000) != 0 && !v64 )
                goto LABEL_304;
              goto LABEL_114;
            }
            goto LABEL_303;
          }
        }
        v72 = "index is invalid: %d";
        v73 = 3028;
        v74 = v56;
        goto LABEL_131;
      }
      if ( v13 == 345 )
      {
        v4 = &unk_2FD000;
        if ( mem_trace_en == 1 )
          v43 = cam_mem_trace_alloc((unsigned int)a2[1], 0xCC0u, 0, "cam_csiphy_core_cfg", 0xD44u);
        else
          v43 = _kvmalloc_node_noprof((unsigned int)a2[1], 0, 3520, 0xFFFFFFFFLL);
        v46 = (_QWORD *)v43;
        if ( !v43 )
        {
LABEL_310:
          v68 = "memory allocation is failed rc = %d";
          v69 = 3423;
          v70 = 4294967284LL;
          LODWORD(v3) = -12;
LABEL_311:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            0x8000,
            1,
            "cam_csiphy_core_cfg",
            v69,
            v68,
            v70);
          goto LABEL_312;
        }
LABEL_76:
        v3 = (unsigned int)a2[1];
        if ( (v3 & 0x80000000) != 0 )
        {
          __break(0x800u);
          goto LABEL_78;
        }
        v47 = *((_QWORD *)a2 + 2);
        _check_object_size(v46, (unsigned int)a2[1], 0);
        LODWORD(v3) = inline_copy_from_user_8((int)v46, v47, v3);
        if ( (_DWORD)v3 )
        {
LABEL_78:
          if ( v4[2904] == 1 )
            cam_mem_trace_free(v46, 0);
          else
            kvfree(v46);
          v68 = "Failed in copy from user, rc=%d";
          v69 = 3404;
          v70 = (unsigned int)v3;
          goto LABEL_311;
        }
        v67 = cam_packet_util_process_generic_blob(a2[1], v46, &cam_csiphy_generic_data_update, v2);
        if ( v67 )
        {
          LODWORD(v3) = v67;
          goto LABEL_138;
        }
        v3 = (unsigned int)a2[1];
        if ( (v3 & 0x80000000) != 0 )
        {
          __break(0x800u);
        }
        else
        {
          v76 = *((_QWORD *)a2 + 2);
          _check_object_size(v46, (unsigned int)a2[1], 1);
          LODWORD(v3) = inline_copy_to_user_7(v76, v46, v3);
          if ( !(_DWORD)v3 )
            goto LABEL_138;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_core_cfg",
          3418,
          "Failed in copy to user, rc=%d",
          v3);
LABEL_138:
        if ( v4[2904] == 1 )
          cam_mem_trace_free(v46, 0);
        else
          kvfree(v46);
        goto LABEL_312;
      }
      if ( v13 != 513 )
        goto LABEL_73;
      v33 = *((_QWORD *)a2 + 2);
      v149 = 0;
      v148 = 0u;
      if ( inline_copy_from_user_8((int)&v148, v33, 0x18u) )
      {
        v34 = "failed copy config ext\n";
        v35 = 3381;
LABEL_56:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_core_cfg",
          v35,
          v34);
        LODWORD(v3) = -14;
        goto LABEL_128;
      }
      LODWORD(v3) = ((__int64 (__fastcall *)(__int64, __int128 *))cam_csiphy_external_cmd)(v2, &v148);
      if ( !(_DWORD)v3 )
        goto LABEL_312;
      v54 = "exteranal command configuration failed rc: %d";
      v55 = 3389;
      goto LABEL_95;
    }
    if ( v13 <= 258 )
    {
      v15 = v2;
      if ( v13 != 257 )
      {
        if ( v13 == 258 )
        {
          v153[1] = 0;
          v154 = 0;
          v152 = 0;
          v153[0] = 0;
          v150 = 0;
          v151 = 0;
          *((_QWORD *)&v148 + 1) = 0;
          v149 = 0;
          if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              (unsigned __int16)debug_mdl & 0x8000,
              4,
              "cam_csiphy_core_cfg",
              2734,
              "ACQUIRE_CNT: %d COMBO_MODE: %d",
              *(_DWORD *)(v2 + 80),
              *(unsigned __int8 *)(v2 + 97));
            v14 = a2;
            v15 = v2;
          }
          if ( *(_DWORD *)(v15 + 104) == 2 && !*(_BYTE *)(v15 + 97) && *(_DWORD *)(v15 + 80) )
          {
            v44 = "NonComboMode does not support multiple acquire: Acquire_count: %d";
            v45 = 2740;
            goto LABEL_126;
          }
          v16 = *(_DWORD *)(v15 + 80);
          if ( !v16 || v16 < *(unsigned __int8 *)(v15 + 96) )
          {
            LODWORD(v3) = inline_copy_from_user_8((int)v153, *((_QWORD *)v14 + 2), 0x18u);
            if ( (v3 & 0x80000000) != 0 )
            {
              v17 = "Failed copying from User";
              v18 = 2759;
              goto LABEL_121;
            }
            LODWORD(v152) = 0;
            if ( inline_copy_from_user_8((int)&v152, v154, 8u) )
            {
              v17 = "Failed copying from User";
              v18 = 2769;
LABEL_121:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x8000,
                1,
                "cam_csiphy_core_cfg",
                v18,
                v17);
              goto LABEL_128;
            }
            v75 = WORD2(v152);
            if ( (_DWORD)v152 && WORD2(v152) )
            {
              v39 = "Cannot support both Combo_mode and cphy_dphy_combo_mode";
              v40 = 2776;
              goto LABEL_92;
            }
            v77 = v2;
            if ( (_DWORD)v152 == 1 )
            {
              if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
              {
                ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  (unsigned __int16)debug_mdl & 0x8000,
                  4,
                  "cam_csiphy_core_cfg",
                  2782,
                  "combo mode stream detected");
                v77 = v2;
              }
              v78 = BYTE6(v152);
              *(_BYTE *)(v77 + 97) = 1;
              if ( v78 )
              {
                if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
                {
                  ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    (unsigned __int16)debug_mdl & 0x8000,
                    4,
                    "cam_csiphy_core_cfg",
                    2785,
                    "3Phase ComboMode");
                  v77 = v2;
                }
                *(_BYTE *)(v77 + 96) = 3;
              }
              else
              {
                v98 = debug_mdl;
                *(_BYTE *)(v77 + 96) = 2;
                if ( v98 < 0 && !debug_priority )
                {
                  ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    v98 & 0x8000,
                    4,
                    "cam_csiphy_core_cfg",
                    2791,
                    "2Phase ComboMode");
                  v77 = v2;
                }
              }
              v75 = WORD2(v152);
            }
            if ( v75 == 1 )
            {
              if ( (debug_mdl & 0x8000) != 0 )
              {
                v75 = 1;
                if ( !debug_priority )
                {
                  ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    (unsigned __int16)debug_mdl & 0x8000,
                    4,
                    "cam_csiphy_core_cfg",
                    2796,
                    "cphy_dphy_combo_mode stream detected");
                  v75 = WORD2(v152);
                  v77 = v2;
                }
              }
              else
              {
                v75 = 1;
              }
              *(_BYTE *)(v77 + 98) = 1;
              *(_BYTE *)(v77 + 96) = 2;
            }
            if ( !((unsigned int)v152 | v75) )
            {
              if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
              {
                ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  (unsigned __int16)debug_mdl & 0x8000,
                  4,
                  "cam_csiphy_core_cfg",
                  2804,
                  "Non Combo Mode stream");
                v77 = v2;
              }
              *(_BYTE *)(v77 + 96) = 1;
            }
            v99 = *(_DWORD *)(v77 + 80);
            *(_QWORD *)((char *)&v148 + 4) = 0;
            LODWORD(v148) = v153[0];
            v150 = 0;
            v151 = v77;
            v149 = 0x8000;
            device_hdl = cam_create_device_hdl((__int64)&v148);
            HIDWORD(v153[0]) = device_hdl;
            if ( device_hdl )
            {
              if ( v99 > 2 )
                goto LABEL_303;
              v101 = BYTE6(v152);
              v102 = v2 + 104LL * v99;
              v103 = a2;
              *(_DWORD *)(v102 + 652) = v153[0];
              *(_DWORD *)(v102 + 648) = device_hdl;
              *(_DWORD *)(v102 + 624) = v101;
              *(_DWORD *)(v102 + 684) = -1;
              *(_WORD *)(v102 + 688) = 0;
              *(_BYTE *)(v102 + 690) = 0;
              if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
              {
                ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  (unsigned __int16)debug_mdl & 0x8000,
                  4,
                  "cam_csiphy_core_cfg",
                  2836,
                  "Add dev_handle:0x%x at index: %d ",
                  device_hdl,
                  v99);
                v103 = a2;
              }
              if ( inline_copy_to_user_7(*((_QWORD *)v103 + 2), v153, 24) )
              {
                v39 = "Failed copying from User";
                v40 = 2840;
                goto LABEL_92;
              }
              v104 = *(_DWORD *)(v2 + 932);
              v8 = v2;
              if ( !*(_DWORD *)(v2 + 80) )
              {
                if ( v104 > 7 )
                  goto LABEL_303;
                v105 = BYTE6(v152);
                v106 = debug_mdl;
                *((_BYTE *)&g_phy_data + 56 * v104 + 8) = BYTE6(v152);
                if ( v106 < 0 && !debug_priority )
                {
                  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    v106 & 0x8000,
                    4,
                    "cam_csiphy_core_cfg",
                    2850,
                    "g_csiphy data is updated for index: %d is_3phase: %u",
                    v104,
                    v105);
                  v8 = v2;
                }
                v104 = *(_DWORD *)(v8 + 932);
                *(_QWORD *)(v8 + 4720) = 0;
                *(_QWORD *)(v8 + 4712) = 0;
                *(_QWORD *)(v8 + 4704) = 0;
                *(_QWORD *)(v8 + 4696) = 0;
                *(_QWORD *)(v8 + 4688) = 0;
                *(_QWORD *)(v8 + 4680) = 0;
                *(_QWORD *)(v8 + 4672) = 0;
                *(_QWORD *)(v8 + 4664) = 0;
                *(_QWORD *)(v8 + 4656) = 0;
                *(_QWORD *)(v8 + 4648) = 0;
                *(_QWORD *)(v8 + 4640) = 0;
                *(_QWORD *)(v8 + 4632) = 0;
                *(_QWORD *)(v8 + 4624) = 0;
                *(_QWORD *)(v8 + 4616) = 0;
                *(_QWORD *)(v8 + 4608) = 0;
              }
              if ( v104 > 7 )
              {
                while ( 1 )
                {
                  do
                  {
LABEL_303:
                    __break(0x5512u);
LABEL_304:
                    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      (unsigned __int16)v8 & 0x8000,
                      4,
                      "cam_csiphy_core_cfg",
                      3058,
                      "All PHY devices released");
                    v62 = v2;
LABEL_114:
                    v65 = *(_DWORD *)(v62 + 932);
                  }
                  while ( v65 > 7 );
                  if ( v5[14 * v65 + 9] != 255 )
                  {
                    v66 = ((__int64 (__fastcall *)(_QWORD))cam_csiphy_util_update_aon_ops)(0);
                    if ( v66 )
                    {
                      v62 = v2;
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x8000,
                        2,
                        "cam_csiphy_core_cfg",
                        3064,
                        "Error in releasing AON operation for phy_idx: %d, rc: %d",
                        *(_DWORD *)(v2 + 932),
                        v66);
                      LODWORD(v3) = 0;
                    }
                    else
                    {
                      LODWORD(v3) = 0;
                      v62 = v2;
                    }
                  }
                  *(_BYTE *)(v62 + 97) = 0;
                  *(_DWORD *)(v62 + 92) = 0;
                  *(_DWORD *)(v62 + 104) = 0;
LABEL_225:
                  if ( v6[504] == 1 )
                  {
                    *(_DWORD *)(v62 + 4600) = 0;
                    *(_QWORD *)(v62 + 4592) = 0;
                  }
                  v8 = v7[458];
                  if ( (v8 & 0x8000) == 0 || *((_DWORD *)v4 + 919) )
                    break;
                  if ( *(_DWORD *)(v62 + 932) <= 7u )
                  {
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      v7[458] & 0x8000LL,
                      4,
                      "cam_csiphy_core_cfg",
                      3079,
                      "CAM_RELEASE_PHYDEV: %u Type: %s");
                    v62 = v2;
                    break;
                  }
                }
                if ( *(_DWORD *)(v62 + 80) < *(_DWORD *)(v62 + 84) )
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                    3,
                    0x8000,
                    1,
                    "cam_csiphy_core_cfg",
                    3086,
                    "PHYDEV %u streamon count:%u bigger than acquire count:%u, missing stream offs",
                    *(unsigned int *)(v62 + 932));
                  LODWORD(v3) = -22;
                  v71 = v2 + 24;
                  goto LABEL_314;
                }
LABEL_313:
                v71 = v62 + 24;
                goto LABEL_314;
              }
              if ( *((_DWORD *)&g_phy_data + 14 * v104 + 9) != 255 )
              {
                LODWORD(v3) = ((__int64 (__fastcall *)(__int64, _QWORD))cam_csiphy_util_update_aon_ops)(1, v104);
                if ( (_DWORD)v3 )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x8000,
                    1,
                    "cam_csiphy_core_cfg",
                    2860,
                    "Error in setting up AON operation for phy_idx: %d, rc: %d",
                    *(_DWORD *)(v2 + 932),
                    v3);
                  goto LABEL_128;
                }
                v8 = v2;
              }
              v114 = *(_DWORD *)(v8 + 104);
              ++*(_DWORD *)(v8 + 80);
              if ( !v114 )
                *(_DWORD *)(v8 + 104) = 1;
              if ( *(_DWORD *)(v8 + 932) >= 8u )
                goto LABEL_303;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x8000,
                3,
                "cam_csiphy_core_cfg",
                2876,
                "CAM_ACQUIRE_DEV: %u Type: %s acquire_count: %d combo: %u cphy+dphy combo: %u");
LABEL_312:
              v62 = v2;
              goto LABEL_313;
            }
            v34 = "Can not create device handle";
            v35 = 2819;
            goto LABEL_56;
          }
          v44 = "Max acquires are allowed in combo mode: %d";
          v45 = 2750;
LABEL_126:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x8000,
            1,
            "cam_csiphy_core_cfg",
            v45,
            v44);
          goto LABEL_127;
        }
LABEL_73:
        v44 = "Invalid Opcode: %d";
        v45 = 3428;
        goto LABEL_126;
      }
      v36 = *((_QWORD *)a2 + 2);
      v38 = *(_DWORD *)(v2 + 72);
      v37 = *(_DWORD *)(v2 + 76);
      LODWORD(v148) = *(_DWORD *)(v2 + 932);
      DWORD1(v148) = v38;
      *((_QWORD *)&v148 + 1) = v37;
      if ( !inline_copy_to_user_7(v36, &v148, 16) )
      {
        LODWORD(v3) = 0;
        goto LABEL_312;
      }
      v39 = "Failed copying from User";
      v40 = 2885;
LABEL_92:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_core_cfg",
        v40,
        v39);
      goto LABEL_127;
    }
    if ( v13 != 259 )
    {
      v22 = *((_QWORD *)a2 + 2);
      *(_QWORD *)&v148 = 0;
      LOWORD(v153[0]) = 0;
      if ( (inline_copy_from_user_8((int)&v148, v22, 8u) & 0x80000000) == 0 )
      {
        v23 = *(unsigned int *)(v2 + 104);
        if ( (_DWORD)v23 != 2 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64))cam_print_log)(
            3,
            0x8000,
            1,
            "cam_csiphy_core_cfg",
            2906,
            "Csiphy:%d Not in right state to stop : %d",
            *(unsigned int *)(v2 + 932),
            v23);
LABEL_99:
          LODWORD(v3) = 0;
          goto LABEL_128;
        }
        LODWORD(v3) = ((__int64 (__fastcall *)(__int64, _QWORD))cam_csiphy_get_instance_offset)(v2, DWORD1(v148));
        if ( (v3 & 0x80000000) == 0 )
        {
          LODWORD(v8) = *(unsigned __int8 *)(v2 + 96);
          if ( (unsigned int)v3 < (unsigned int)v8 )
          {
            if ( (unsigned int)v3 > 3 )
              goto LABEL_303;
            cam_csiphy_get_settle_count(v2, (unsigned int)v3, (unsigned __int16 *)v153, v24, v25);
            v26 = strnlen(&csiphy_qmargin, 0x14u);
            if ( v26 < 0x15 )
            {
              if ( !v26 )
                goto LABEL_45;
              if ( v26 != 20 )
              {
                cam_csiphy_common_status_reg_dump(v2, 0);
LABEL_45:
                v27 = v2;
                v28 = *(_DWORD *)(v2 + 84) - 1;
                *(_DWORD *)(v2 + 84) = v28;
                v4 = (_BYTE *)(v2 + 104LL * (unsigned int)v3 + 600);
                if ( !v28 )
                {
                  if ( *(_BYTE *)(v2 + 104LL * (unsigned int)v3 + 603) )
                  {
                    cam_csiphy_program_secure_mode(v2, 0, v3);
                    v27 = v2;
                  }
                  *(_QWORD *)(v2 + 104LL * (unsigned int)v3 + 632) = 0;
                  v85 = v6[632];
                  *(_BYTE *)(v2 + 104LL * (unsigned int)v3 + 603) = 0;
                  if ( v85 == 1 )
                  {
                    v86 = v27;
                    mutex_lock(&active_csiphy_cnt_mutex);
                    --active_csiphy_hw_cnt;
                    mutex_unlock(&active_csiphy_cnt_mutex);
                    cam_csiphy_program_common_registers(v86, 1, 0);
                  }
                  else
                  {
                    _csiphy_prgm_common_data(*(unsigned int *)(v27 + 932), *(_QWORD *)(*(_QWORD *)(v27 + 112) + 8LL));
                  }
                  v90 = v2;
                  if ( *(_WORD *)(v2 + 4734) )
                  {
                    _cam_csiphy_get_preamble_status(v2, (unsigned int)v3);
                    v90 = v2;
                  }
                  cam_csiphy_update_lane_selection(v90, v3, 0);
                  if ( (cam_csiphy_disable_hw(v90, v3, v91, v92, v93) & 0x80000000) != 0 )
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      0x8000,
                      1,
                      "cam_csiphy_core_cfg",
                      2989,
                      "Failed in csiphy release");
                  v94 = *(_DWORD *)(v2 + 932);
                  if ( v94 > 7 )
                    goto LABEL_303;
                  v8 = v2;
                  if ( (*((_BYTE *)&g_phy_data + 56 * v94 + 16) & 1) == 0 )
                  {
                    v95 = cam_csiphy_cpas_ops(*(unsigned int *)(v2 + 88), 0);
                    v8 = v2;
                    if ( v95 )
                    {
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                        3,
                        0x8000,
                        1,
                        "cam_csiphy_core_cfg",
                        2993,
                        "Failed in de-voting CPAS");
                      v8 = v2;
                    }
                  }
                  v96 = *(_DWORD *)(v8 + 932);
                  *(_DWORD *)(v8 + 104) = 1;
                  if ( v96 >= 8 )
                    goto LABEL_303;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x8000,
                    3,
                    "cam_csiphy_core_cfg",
                    3004,
                    "CAM_STOP_PHYDEV: %u, CSID:%d, Type: %s, slot: %d, Datarate: %llu, Settlecount: %u");
                  LODWORD(v3) = 0;
                  v71 = v2 + 24;
                  goto LABEL_314;
                }
                if ( *(_BYTE *)(v2 + 104LL * (unsigned int)v3 + 603) )
                {
                  cam_csiphy_program_secure_mode(v2, 0, v3);
                  v27 = v2;
                }
                *(_BYTE *)(v2 + 104LL * (unsigned int)v3 + 603) = 0;
                *(_QWORD *)(v2 + 104LL * (unsigned int)v3 + 632) = 0;
                cam_csiphy_update_lane_selection(v27, v3, 0);
                LODWORD(v8) = v6[16];
                if ( (_DWORD)v8 != 1 )
                  goto LABEL_234;
                LODWORD(v8) = *(unsigned __int8 *)(v2 + 104LL * (unsigned int)v3 + 688);
                if ( (_DWORD)v8 != 1 )
                  goto LABEL_234;
                if ( (unsigned int)cam_soc_util_set_src_clk_rate(
                                     v2 + 912,
                                     *(_DWORD *)(v2 + 104LL * (unsigned int)v3 + 684),
                                     0,
                                     0) )
                {
                  v29 = *(unsigned int *)(v2 + 932);
                  v30 = *(unsigned int *)(v2 + 104LL * (unsigned int)v3 + 684);
                  v31 = "[%d] Failed in setting clk rate for %d";
                  v32 = 2941;
                }
                else
                {
                  v108 = cam_soc_util_cesta_channel_switch(
                           *(_DWORD *)(v2 + 104LL * (unsigned int)v3 + 684),
                           "csiphy_stop_dev");
                  if ( !v108 )
                  {
LABEL_234:
                    v109 = *(unsigned int *)(v2 + 932);
                    if ( (unsigned int)v109 > 7 )
                      goto LABEL_303;
                    v110 = "CPHY";
                    if ( !*((_BYTE *)&g_phy_data + 56 * (unsigned int)v109 + 8) )
                      v110 = "DPHY";
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, const char *, _DWORD, _DWORD, _QWORD, _DWORD))cam_print_log)(
                      3,
                      0x8000,
                      3,
                      "cam_csiphy_core_cfg",
                      2958,
                      "CAM_STOP_PHYDEV: %d, CSID:%d, Type: %s, dev_cnt: %u, slot: %d, Datarate: %llu, Settlecount: %u",
                      v109,
                      *(unsigned int *)(v2 + 104LL * (unsigned int)v3 + 684),
                      v110,
                      *(_DWORD *)(v2 + 84),
                      v3,
                      *(_QWORD *)(v2 + 104LL * (unsigned int)v3 + 616),
                      LOWORD(v153[0]));
                    goto LABEL_99;
                  }
                  v29 = *(unsigned int *)(v2 + 104LL * (unsigned int)v3 + 684);
                  v30 = v108;
                  v31 = "Failed to apply power states for cesta client:%d rc:%d";
                  v32 = 2948;
                }
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                  3,
                  0x8000,
                  1,
                  "cam_csiphy_core_cfg",
                  v32,
                  v31,
                  v29,
                  v30);
                goto LABEL_234;
              }
              _fortify_panic(4, 20, 21);
              StatusReg = _ReadStatusReg(SP_EL0);
              v145 = *(_QWORD *)(StatusReg + 80);
              *(_QWORD *)(StatusReg + 80) = &cam_csiphy_core_cfg__alloc_tag;
              v46 = (_QWORD *)_kvmalloc_node_noprof(*(unsigned int *)(v146 + 4), 0, 3520, 0xFFFFFFFFLL);
              *(_QWORD *)(StatusReg + 80) = v145;
              if ( !v46 )
                goto LABEL_310;
              goto LABEL_76;
            }
            _fortify_panic(2, 20, v26 + 1);
            goto LABEL_306;
          }
        }
        v72 = "Index is invalid: %d";
        v73 = 2914;
        v74 = (unsigned int)v3;
LABEL_131:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_core_cfg",
          v73,
          v72,
          v74);
        LODWORD(v3) = 0;
        goto LABEL_128;
      }
      v48 = "Failed copying from User";
      v49 = 2900;
LABEL_81:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_core_cfg",
        v49,
        v48);
      LODWORD(v3) = 0;
      goto LABEL_128;
    }
    *(_QWORD *)&v148 = 0;
    LOWORD(v153[0]) = 0;
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_core_cfg",
        3117,
        "START_DEV Called");
      v14 = a2;
    }
    LODWORD(v3) = inline_copy_from_user_8((int)&v148, *((_QWORD *)v14 + 2), 8u);
    if ( (v3 & 0x80000000) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_core_cfg",
        3121,
        "Failed copying from User");
      goto LABEL_128;
    }
    if ( *(_DWORD *)(v2 + 104) == 2 )
    {
      v41 = *(_DWORD *)(v2 + 84);
      v42 = *(unsigned __int8 *)(v2 + 96);
      if ( v41 > v42 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_core_cfg",
          3131,
          "Invalid start count: %d, Max supported devices: %u",
          v41,
          v42);
LABEL_127:
        LODWORD(v3) = -22;
        goto LABEL_128;
      }
    }
    v50 = ((__int64 (__fastcall *)(__int64, _QWORD))cam_csiphy_get_instance_offset)(v2, DWORD1(v148));
    if ( (v50 & 0x80000000) != 0 || (LODWORD(v8) = *(unsigned __int8 *)(v2 + 96), v50 >= (unsigned int)v8) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_core_cfg",
        3140,
        "index is invalid: %d",
        v50);
      goto LABEL_128;
    }
    if ( v50 > 3 )
      goto LABEL_303;
    drv_enable = cam_cpas_query_drv_enable(0, (unsigned __int64)(v6 + 16));
    if ( drv_enable )
    {
      LODWORD(v3) = drv_enable;
      v54 = "Failed to query DRV enable rc: %d";
      v55 = 3148;
      goto LABEL_95;
    }
    cam_csiphy_get_settle_count(v2, v50, (unsigned __int16 *)v153, v52, v53);
    v8 = v2;
    if ( *(_DWORD *)(v2 + 84) )
    {
      v79 = *(_DWORD **)(*(_QWORD *)(v2 + 112) + 112LL);
      if ( *(v79 - 1) != -1852174336 )
        __break(0x8229u);
      LODWORD(v3) = ((__int64 (__fastcall *)(__int64, _QWORD))v79)(v2, v50);
      if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          (unsigned __int16)debug_mdl & 0x8000,
          4,
          "cam_csiphy_core_cfg",
          3163,
          "CSIPHY[%d] is_clk_drv_en[%d] conn_csid_idx[%d] use_hw_client_voting[%d] is_drv_config_en[%d]",
          *(_DWORD *)(v2 + 932),
          v6[16],
          *(_DWORD *)(v2 + 104LL * v50 + 684),
          *(unsigned __int8 *)(v2 + 104LL * v50 + 688),
          *(unsigned __int8 *)(v2 + 104LL * v50 + 689));
      if ( v6[16] == 1 && *(_BYTE *)(v2 + 104LL * v50 + 688) == 1 )
      {
        v80 = v3;
        if ( *(_BYTE *)(v2 + 104LL * v50 + 689) == 1 )
          v80 = *(_DWORD *)(v2 + 3784);
        v81 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))cam_soc_util_set_clk_rate_level)(
                v2 + 912,
                *(unsigned int *)(v2 + 104LL * v50 + 684),
                (unsigned int)v3,
                v80,
                0);
        if ( v81 )
        {
          v82 = v81;
          string_from_level = cam_soc_util_get_string_from_level(v3);
          v84 = cam_soc_util_get_string_from_level(v80);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x8000,
            1,
            "cam_csiphy_core_cfg",
            3178,
            "Failed to set the req clk_rate level[high low]: [%s %s] cesta_client_idx: %d rc: %d",
            string_from_level,
            v84,
            *(_DWORD *)(v2 + 104LL * v50 + 684),
            v82);
          goto LABEL_127;
        }
        v111 = cam_soc_util_cesta_channel_switch(*(_DWORD *)(v2 + 104LL * v50 + 684), "csiphy_combo");
        if ( v111 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x8000,
            1,
            "cam_csiphy_core_cfg",
            3188,
            "Failed to apply power states for crm client:%d rc:%d",
            *(_DWORD *)(v2 + 104LL * v50 + 684),
            v111);
      }
      else if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD))cam_soc_util_set_clk_rate_level)(
                                v2 + 912,
                                0xFFFFFFFFLL,
                                (unsigned int)v3,
                                0,
                                0) )
      {
        v87 = cam_soc_util_get_string_from_level(v3);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          2,
          "cam_csiphy_core_cfg",
          3198,
          "Failed to set the req clk_rate level: %s",
          v87);
        goto LABEL_127;
      }
      if ( v50 == 3 )
        goto LABEL_303;
      if ( *(_BYTE *)(v2 + 104LL * v50 + 603) != 1 )
        goto LABEL_246;
      if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cam_cpas_is_feature_supported)(1, 0, 0) & 1) == 0 )
      {
        v48 = "sec_cam: camera fuse bit not set";
        v49 = 3211;
        goto LABEL_81;
      }
      v112 = cam_csiphy_program_secure_mode(v2, 1, v50);
      if ( !v112 )
      {
LABEL_246:
        LODWORD(v3) = cam_csiphy_config_dev(v2, v50, 0);
        if ( (v3 & 0x80000000) == 0 )
        {
          if ( v6[635] == 1 )
            cam_csiphy_reg_dump(v2 + 912);
          v113 = *(_DWORD *)(v2 + 932);
          LODWORD(v8) = *(_DWORD *)(v2 + 84) + 1;
          *(_DWORD *)(v2 + 84) = v8;
          if ( v113 > 7 )
            goto LABEL_303;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x8000,
            3,
            "cam_csiphy_core_cfg",
            3251,
            "CAM_START_PHYDEV: %d, CSID:%d, Type: %s, dev_cnt: %u, slot: %d, combo: %u, cphy+dphy: %u, skew_en: %d, sec_m"
            "ode: %d, Datarate: %llu, Settlecount: %u");
          goto LABEL_128;
        }
        v17 = "cam_csiphy_config_dev failed";
        v18 = 3230;
        goto LABEL_121;
      }
      LODWORD(v3) = v112;
      *(_BYTE *)(v2 + 104LL * v50 + 603) = 0;
      v54 = "sec_cam: notify failed: rc: %d";
      v55 = 3223;
LABEL_95:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_core_cfg",
        v55,
        v54,
        (unsigned int)v3);
      goto LABEL_128;
    }
    v88 = *(_DWORD *)(v2 + 932);
    if ( v88 > 7 )
      goto LABEL_303;
    if ( (*((_BYTE *)&g_phy_data + 56 * v88 + 16) & 1) == 0 )
    {
      v89 = cam_csiphy_cpas_ops(*(unsigned int *)(v2 + 88), 1);
      v8 = v2;
      if ( v89 )
      {
        LODWORD(v3) = -14;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_core_cfg",
          3259,
          "voting CPAS: %d",
          -14);
        goto LABEL_128;
      }
    }
    if ( v50 == 3 )
      goto LABEL_303;
    if ( *(_BYTE *)(v2 + 104LL * v50 + 603) != 1 )
      goto LABEL_221;
    if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cam_cpas_is_feature_supported)(1, 0, 0) & 1) == 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_core_cfg",
        3270,
        "sec_cam: camera fuse bit not set");
      LODWORD(v3) = -22;
      goto LABEL_254;
    }
    v97 = cam_csiphy_program_secure_mode(v2, 1, v50);
    v8 = v2;
    if ( v97 )
    {
      LODWORD(v3) = v97;
      *(_BYTE *)(v2 + 104LL * v50 + 603) = 0;
    }
    else
    {
LABEL_221:
      v107 = cam_csiphy_enable_hw(v8, v50);
      if ( v107 )
      {
        LODWORD(v3) = v107;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_core_cfg",
          3288,
          "cam_csiphy_enable_hw failed");
      }
      else if ( (unsigned int)cam_common_read_poll_timeout(
                                (const void *)(v11 + v10[2]),
                                0x1F4u,
                                10000,
                                0x80u,
                                128,
                                &v155) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_core_cfg",
          3297,
          "Response poll timed out: status=0x%08x",
          v155);
        LODWORD(v3) = -110;
      }
      else
      {
        if ( v6[632] == 1 )
        {
          cam_csiphy_program_common_registers(v2, 0, 0);
          mutex_lock(&active_csiphy_cnt_mutex);
          ++active_csiphy_hw_cnt;
          mutex_unlock(&active_csiphy_cnt_mutex);
        }
        else
        {
          _csiphy_prgm_common_data(*(unsigned int *)(v2 + 932), *(_QWORD *)(*(_QWORD *)(v2 + 112) + 8LL));
        }
        LODWORD(v3) = cam_csiphy_config_dev(v2, v50, 0);
        if ( (v3 & 0x80000000) == 0 )
        {
          cam_csiphy_cphy_irq_config(v2);
          v115 = *(unsigned int *)(v2 + 932);
          if ( (unsigned int)v115 > 7 )
            goto LABEL_303;
          if ( csiphy_onthego_reg_count[v115] )
            cam_csiphy_apply_onthego_reg_values(v11);
          ((void (__fastcall *)(__int64, __int64, _QWORD))cam_csiphy_release_from_reset_state)(v2, v11, v50);
          LODWORD(v8) = *(_DWORD *)(v2 + 932);
          if ( (unsigned int)v8 > 7 )
            goto LABEL_303;
          if ( !*((_BYTE *)&g_phy_data + 56 * (unsigned int)v8 + 8) )
            goto LABEL_292;
          v116 = v10[3];
          if ( !(_DWORD)v116 )
            goto LABEL_280;
          v117 = cam_io_r_mb(v11 + v116);
          v118 = v117 & 0x1F;
          if ( (v117 & 0x17) != 0 )
          {
            v119 = v10[3];
            v120 = "Reg_offset: 0x%x, Cphy_trio%d_status = 0x%x";
            v121 = 0x8000;
            v122 = 2;
            v123 = 3342;
LABEL_274:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
              3,
              v121,
              v122,
              "cam_csiphy_core_cfg",
              v123,
              v120,
              v119,
              0,
              v118);
            goto LABEL_280;
          }
          v127 = debug_mdl;
          if ( (debug_mdl & 0x8000) == 0 || debug_priority )
          {
LABEL_280:
            v128 = v10[4];
            if ( !(_DWORD)v128 )
              goto LABEL_286;
            v129 = cam_io_r_mb(v11 + v128);
            if ( (v129 & 0x17) != 0 )
            {
              v130 = v10[4];
              v131 = "Reg_offset: 0x%x, Cphy_trio%d_status = 0x%x";
              v132 = 0x8000;
              v133 = 2;
              v134 = 3342;
            }
            else
            {
              if ( (debug_mdl & 0x8000) == 0 || debug_priority )
              {
LABEL_286:
                v135 = v10[5];
                if ( (_DWORD)v135 )
                {
                  v136 = cam_io_r_mb(v11 + v135);
                  if ( (v136 & 0x17) != 0 )
                  {
                    v137 = v10[5];
                    v138 = "Reg_offset: 0x%x, Cphy_trio%d_status = 0x%x";
                    v139 = 0x8000;
                    v140 = 2;
                    v141 = 3342;
                  }
                  else
                  {
                    if ( (debug_mdl & 0x8000) == 0 || debug_priority )
                      goto LABEL_292;
                    v137 = v10[5];
                    v138 = "Reg_offset: 0x%x, cphy_trio%d_status = 0x%x";
                    v139 = (unsigned __int16)debug_mdl & 0x8000;
                    v140 = 4;
                    v141 = 3337;
                  }
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
                    3,
                    v139,
                    v140,
                    "cam_csiphy_core_cfg",
                    v141,
                    v138,
                    v137,
                    2,
                    v136 & 0x1F);
                }
LABEL_292:
                if ( v6[635] == 1 )
                  cam_csiphy_reg_dump(v2 + 912);
                if ( v6[634] == 1 )
                {
                  usleep_range_state(50000, 50005, 2);
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x8000,
                    3,
                    "cam_csiphy_core_cfg",
                    3353,
                    "Status Reg Dump after config");
                  cam_csiphy_dump_status_reg(v2);
                }
                v142 = *(_DWORD *)(v2 + 84);
                v143 = *(_DWORD *)(v2 + 932);
                *(_DWORD *)(v2 + 104) = 2;
                LODWORD(v8) = v142 + 1;
                *(_DWORD *)(v2 + 84) = v8;
                if ( v143 > 7 )
                  goto LABEL_303;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x8000,
                  3,
                  "cam_csiphy_core_cfg",
                  3372,
                  "CAM_START_PHYDEV: %d, CSID:%d, Type: %s, dev_cnt: %u, slot: %d, combo: %u, cphy+dphy: %u, skew_en: %d,"
                  " sec_mode: %d, Datarate: %llu, Settlecount: %u");
                goto LABEL_312;
              }
              v130 = v10[4];
              v131 = "Reg_offset: 0x%x, cphy_trio%d_status = 0x%x";
              v132 = (unsigned __int16)debug_mdl & 0x8000;
              v133 = 4;
              v134 = 3337;
            }
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
              3,
              v132,
              v133,
              "cam_csiphy_core_cfg",
              v134,
              v131,
              v130,
              1,
              v129 & 0x1F);
            goto LABEL_286;
          }
LABEL_306:
          v119 = v10[3];
          v120 = "Reg_offset: 0x%x, cphy_trio%d_status = 0x%x";
          v121 = v127 & 0x8000;
          v122 = 4;
          v123 = 3337;
          goto LABEL_274;
        }
        v124 = ((long double (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 0x8000,
                 1,
                 "cam_csiphy_core_cfg",
                 3314,
                 "cam_csiphy_config_dev failed");
        cam_csiphy_disable_hw(v2, v50, v124, v125, v126);
        if ( v6[632] == 1 )
        {
          mutex_lock(&active_csiphy_cnt_mutex);
          --active_csiphy_hw_cnt;
          mutex_unlock(&active_csiphy_cnt_mutex);
        }
      }
    }
LABEL_254:
    if ( !(unsigned int)cam_csiphy_cpas_ops(*(unsigned int *)(v2 + 88), 0) )
      goto LABEL_128;
    v17 = "cpas stop failed";
    v18 = 3445;
    goto LABEL_121;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_csiphy_core_cfg",
    2719,
    "CSIPHY %d status reg is NULL: %s",
    v9,
    "NULL");
  LODWORD(v3) = -22;
LABEL_315:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v3;
}
