__int64 __fastcall cam_icp_mgr_config_hw(const char *a1, _QWORD *a2)
{
  unsigned __int64 v2; // x21
  const char *v4; // x20
  __int64 v5; // x24
  char *v6; // x23
  int v7; // w8
  __int64 v8; // x0
  unsigned __int64 *v9; // x19
  unsigned __int64 i; // x23
  const char *v11; // x25
  unsigned __int64 v12; // x27
  __int64 v13; // x26
  __int64 v14; // x22
  unsigned int *v15; // x28
  __int64 result; // x0
  const char *v17; // x5
  __int64 v18; // x6
  __int64 v19; // x4
  unsigned __int64 v20; // x14
  unsigned int *v21; // x0
  unsigned int *v22; // x0
  __int64 v23; // x7
  __int64 v24; // x1
  __int64 v25; // x10
  const char *v26; // x3
  const char *v27; // x6
  __int64 v28; // x4
  __int64 v29; // x19
  int v30; // w24
  __int64 v31; // x10
  __int64 v32; // x6
  __int64 v33; // x8
  unsigned int v34; // w7
  int v35; // w9
  unsigned __int64 v36; // x15
  __int64 v37; // x6
  unsigned __int64 v38; // x19
  __int64 v39; // x7
  __int64 v40; // x10
  __int64 v41; // x9
  unsigned int v42; // w8
  int v43; // w10
  __int64 v44; // x12
  __int64 v45; // x9
  unsigned int v46; // w8
  __int64 v47; // x11
  int v48; // w10
  __int64 v49; // x12
  unsigned int v50; // w9
  unsigned int v51; // w19
  unsigned __int64 v52; // x19
  _BOOL4 v53; // w13
  unsigned int v54; // w8
  unsigned int v55; // w9
  unsigned int v56; // w10
  __int64 v57; // x8
  __int64 v58; // x19
  __int64 v59; // x1
  __int64 v60; // x8
  unsigned int v61; // w15
  unsigned int *v62; // x11
  unsigned int v63; // w9
  unsigned int v64; // w10
  __int64 v65; // x9
  unsigned int v66; // w9
  _BOOL4 v67; // w19
  unsigned int v68; // w9
  __int64 v69; // x20
  unsigned int v70; // w24
  __int64 v71; // x19
  int v72; // w24
  _QWORD *v73; // x0
  __int64 v74; // x13
  __int64 v75; // x20
  __int64 v76; // x6
  int v77; // w7
  __int64 v78; // x1
  int v79; // w8
  unsigned __int64 v80; // x13
  unsigned __int64 v81; // x7
  unsigned __int64 v82; // x8
  __int64 v83; // x19
  __int64 v84; // x8
  unsigned int v85; // w7
  unsigned int v86; // w6
  __int64 v87; // x19
  int v88; // w10
  int v89; // w9
  __int64 v90; // x8
  __int64 v91; // x8
  __int64 v92; // x11
  __int64 v93; // x9
  __int64 v94; // x1
  __int64 v95; // x10
  int v96; // w8
  __int64 v97; // x11
  _QWORD *v98; // x13
  _QWORD *v99; // x10
  unsigned int *v100; // x28
  bool v101; // w19
  int v102; // w6
  unsigned int v103; // w8
  _QWORD *v104; // x8
  __int64 v105; // x11
  __int64 v106; // x10
  __int64 v107; // x8
  size_t v108; // x2
  unsigned __int64 v109; // x24
  unsigned __int64 v110; // x8
  int v111; // w6
  int v112; // w6
  unsigned __int64 v113; // x19
  __int64 v114; // x9
  __int64 v115; // x10
  int v116; // w0
  __int64 v117; // x8
  __int64 v118; // x9
  const char *v119; // x0
  unsigned __int64 v120; // x11
  unsigned __int64 v121; // x9
  int v122; // w9
  int v123; // w10
  _QWORD *v124; // x28
  const char *v125; // x0
  __int64 v126; // x8
  int v127; // w9
  unsigned __int64 v128; // x10
  unsigned __int64 v129; // x11
  unsigned __int64 v130; // x8
  int v131; // w10
  int v132; // w9
  size_t v133; // x2
  _QWORD *v134; // x8
  __int64 v135; // x10
  __int64 v136; // x11
  __int64 v137; // x8
  int v138; // w24
  __int64 v139; // x9
  _DWORD *v140; // x8
  __int64 v141; // x0
  int v142; // w0
  __int64 v143; // x24
  int *task; // x0
  __int64 v145; // x8
  _QWORD *v146; // x23
  int v147; // w1
  int v148; // w0
  unsigned int v149; // w21
  __int64 *v150; // x8
  __int64 v151; // x8
  _DWORD *v152; // x8
  __int64 v153; // x0
  __int64 *v155; // x8
  __int64 v156; // x19
  __int64 v157; // x24
  int *v158; // x0
  __int64 v159; // x8
  _BOOL4 v160; // w19
  __int64 v161; // x8
  unsigned int v162; // w19
  unsigned __int64 v168; // x10
  _QWORD *v169; // [xsp+28h] [xbp-2E8h]
  _QWORD *v170; // [xsp+28h] [xbp-2E8h]
  __int64 v171; // [xsp+30h] [xbp-2E0h]
  __int64 v172; // [xsp+30h] [xbp-2E0h]
  const char *v173; // [xsp+30h] [xbp-2E0h]
  const char *v174; // [xsp+30h] [xbp-2E0h]
  _BOOL4 v175; // [xsp+30h] [xbp-2E0h]
  unsigned __int64 v176; // [xsp+38h] [xbp-2D8h]
  const char *v177; // [xsp+40h] [xbp-2D0h]
  unsigned __int64 *v178; // [xsp+48h] [xbp-2C8h]
  unsigned __int64 v179; // [xsp+50h] [xbp-2C0h]
  _QWORD *v180; // [xsp+58h] [xbp-2B8h]
  char *v181; // [xsp+60h] [xbp-2B0h]
  __int64 v182; // [xsp+68h] [xbp-2A8h]
  __int64 v183; // [xsp+70h] [xbp-2A0h]
  _QWORD v184[2]; // [xsp+78h] [xbp-298h] BYREF
  _QWORD s[81]; // [xsp+88h] [xbp-288h] BYREF

  v4 = a1;
  s[79] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_config_hw",
      6207,
      "Invalid arguments %pK %pK",
      a1,
      a2);
    result = 4294967274LL;
    goto LABEL_438;
  }
  v5 = *a2;
  if ( !*((_DWORD *)a2 + 2) )
  {
    v17 = "%s: No hw update enteries are available";
    v18 = v5 + 29824;
    v19 = 6215;
LABEL_20:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_config_hw",
      v19,
      v17,
      v18);
    result = 4294967274LL;
    goto LABEL_438;
  }
  v6 = (char *)(a1 + 40960);
  if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
  {
    v2 = (unsigned __int64)v4;
    if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x8000000,
        4,
        "cam_icp_mgr_config_hw",
        6222,
        "%s: presil: locking frame_in_process %d req id %llu",
        (const char *)(v5 + 29824),
        *((_DWORD *)v6 + 802),
        a2[6]);
    down_write(&frame_in_process_sem);
    *((_DWORD *)v6 + 802) = 1;
    v7 = *(_DWORD *)(v5 + 29224);
    *((_DWORD *)v6 + 803) = v7;
    if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x8000000,
        4,
        "cam_icp_mgr_config_hw",
        6228,
        "%s: presil: locked frame_in_process req id %llu ctx_id %d",
        (const char *)(v5 + 29824),
        a2[6],
        v7);
    msleep(100);
  }
  mutex_lock(v4);
  v8 = mutex_lock(*((_QWORD *)v4 + 11) + 48LL * *(unsigned int *)(v5 + 29224));
  if ( *(_DWORD *)(v5 + 104) != 2 )
  {
    mutex_unlock(*((_QWORD *)v4 + 11) + 48LL * *(unsigned int *)(v5 + 29224));
    mutex_unlock(v4);
    v17 = "%s: is not in use";
    v18 = v5 + 29824;
    v19 = 6237;
    goto LABEL_20;
  }
  v9 = (unsigned __int64 *)a2[5];
  v181 = v6;
  v182 = v5 + 28672;
  i = 0;
  v11 = nullptr;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v180 = a2;
  v15 = (_DWORD *)&unk_1318;
  while ( *(_QWORD *)(v5 + v12 + 1784) != *v9 )
  {
    v11 += 63;
    ++v14;
    v13 += 504;
    v12 += 8LL;
    i += 126LL;
    v15 += 8;
    if ( v11 == byte_9D8 )
      goto LABEL_22;
  }
  if ( (int)v14 >= 40 )
  {
LABEL_22:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_config_hw",
      6246,
      "%s: frame process index not found for req_id: %llu",
      v5 + 29824);
    mutex_unlock(*((_QWORD *)v4 + 11) + 48LL * *(unsigned int *)(v5 + 29224));
    mutex_unlock(v4);
    result = 4294967274LL;
    goto LABEL_438;
  }
  v179 = *v9;
  if ( (cam_presil_mode_enabled(v8) & 1) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      3,
      "cam_icp_mgr_config_hw",
      6254,
      "%s: Sending relevant buffers for request: %llu to presil",
      (const char *)(v5 + 29824),
      v180[6]);
    cam_presil_send_buffers_from_packet((unsigned int *)v9[7], *((_DWORD *)v4 + 37), *((_DWORD *)v4 + 37));
  }
  v20 = *(_QWORD *)(v5 + 16);
  v176 = v20;
  if ( v5 )
  {
    v21 = *(unsigned int **)(v5 + 29800);
    if ( v21 )
    {
      ++*(_DWORD *)(v5 + 29808);
      if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          debug_mdl & 0x2000100,
          4,
          "cam_icp_ctx_timer_reset",
          427,
          "%s: reset timer : counter=%d",
          v5 + 29824);
        v21 = *(unsigned int **)(v5 + 29800);
      }
      crm_timer_reset(v21);
      v20 = v176;
    }
  }
  v22 = *(unsigned int **)(v20 + 552);
  if ( v22 )
  {
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      v2 = v176;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_device_timer_reset",
        441,
        "[%s] reset timer for device: %s",
        v4 + 112,
        *(const char **)v176);
      v22 = *(unsigned int **)(v176 + 552);
    }
    crm_timer_reset(v22);
    v20 = v176;
    ++*(_DWORD *)(v176 + 560);
  }
  v183 = v5;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_check_clk_update",
      1480,
      "Reset %s device timer",
      *(const char **)v20);
    v20 = v176;
  }
  v177 = v4;
  v178 = v9;
  v23 = *((_QWORD *)v181 + 392);
  if ( !v23 )
  {
    if ( (unsigned int)v14 >= 0x28 )
      goto LABEL_393;
    v29 = 0;
    v30 = 0;
    v31 = *(_QWORD *)(v183 + v12 + 1784);
    v2 = v183 + 4824;
    do
    {
      v32 = *(_QWORD *)(v2 + 8 * v29 - 3040);
      if ( v32 && *(_BYTE *)(v2 + v29) == 1 )
      {
        if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
        {
          v171 = v31;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x2000100,
            4,
            "cam_icp_busy_prev_reqs",
            1065,
            "r id = %lld busy = %d",
            v32,
            1);
          v31 = v171;
          v20 = v176;
        }
        ++v30;
      }
      ++v29;
    }
    while ( v29 != 40 );
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_check_clk_update",
        1492,
        "%s: busy = %d req_id = %lld",
        (const char *)(v183 + 29824),
        v30 > 1,
        v31);
      v20 = v176;
    }
    v33 = v183 + 4 * v12;
    v34 = *(_DWORD *)(v33 + 4872);
    if ( !v34 )
    {
      v39 = *((_QWORD *)v181 + 393);
      if ( v39 == *(_DWORD *)(v20 + 28) )
        goto LABEL_245;
      *(_DWORD *)(v20 + 24) = v39;
      v24 = debug_mdl & 0x2000100;
      *(_DWORD *)(v20 + 28) = *((_DWORD *)v181 + 786);
      v40 = *((_QWORD *)v181 + 393);
      *(_QWORD *)(v20 + 48) = v40;
      *(_QWORD *)(v20 + 56) = v40;
      if ( !v24 || debug_priority )
        goto LABEL_240;
      v26 = "cam_icp_default_clk_update";
      v27 = v4 + 112;
      v28 = 1270;
      goto LABEL_44;
    }
    v35 = *(_DWORD *)(v33 + 4876);
    v36 = v33 + 4824;
    *(_DWORD *)(v182 + 564) = v35;
    if ( v35 || *(_DWORD *)(v20 + 8) == 3 )
    {
      v37 = *(_QWORD *)((char *)v15 + v183 - 24);
      v2 = 1000000000 * (unsigned __int64)v34 / (unsigned int)v37;
      if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      {
        v38 = v33 + 4824;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000100,
          4,
          "cam_icp_mgr_calc_base_clk",
          1050,
          "budget = %lld fc = %d ib = %lld base_clk = %lld",
          v37,
          v34,
          1000000000LL * v34,
          v2);
        v20 = v176;
        v36 = v38;
      }
    }
    else
    {
      v2 = *(unsigned int *)(v182 + 628);
    }
    if ( v30 >= 2 )
    {
      *(_DWORD *)(v182 + 568) = v2;
      *(_DWORD *)(v20 + 40) = 0;
      if ( *(_DWORD *)(v36 + 48) > *(_DWORD *)(v182 + 560) )
      {
        v41 = 0;
        v42 = 0;
        v43 = *(_DWORD *)(*(_QWORD *)(v183 + 16) + 8LL);
        *(_DWORD *)(v20 + 24) = 0;
        do
        {
          v44 = *(_QWORD *)(*((_QWORD *)v4 + 12) + v41);
          if ( v44 && *(_DWORD *)(v44 + 104) == 2 && *(_DWORD *)(*(_QWORD *)(v44 + 16) + 8LL) == v43 )
          {
            v42 += *(_DWORD *)(v44 + 29240);
            *(_DWORD *)(v20 + 24) = v42;
          }
          v41 += 8;
        }
        while ( v41 != 432 );
        v55 = *(_DWORD *)(v182 + 592);
        v56 = v55;
        if ( v55 < (unsigned int)v2 )
        {
          v56 = *(_DWORD *)(v182 + 596);
          if ( v56 < (unsigned int)v2 )
          {
            v56 = *(_DWORD *)(v182 + 600);
            if ( v56 < (unsigned int)v2 )
            {
              v56 = *(_DWORD *)(v182 + 604);
              if ( v56 < (unsigned int)v2 )
              {
                v56 = *(_DWORD *)(v182 + 608);
                if ( v56 < (unsigned int)v2 )
                {
                  v56 = *(_DWORD *)(v182 + 612);
                  if ( v56 < (unsigned int)v2 )
                  {
                    v56 = *(_DWORD *)(v182 + 616);
                    if ( v56 < (unsigned int)v2 )
                    {
                      v56 = *(_DWORD *)(v182 + 620);
                      if ( v56 < (unsigned int)v2 )
                      {
                        v56 = *(_DWORD *)(v182 + 624);
                        if ( v56 < (unsigned int)v2 )
                        {
                          v56 = *(_DWORD *)(v182 + 628);
                          if ( v56 <= (unsigned int)v2 )
                            v56 = v2;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if ( v42 > v56 )
        {
          *(_DWORD *)(v20 + 28) = v42;
          goto LABEL_235;
        }
        LODWORD(v58) = *(_DWORD *)(v20 + 28);
        if ( v55 >= (unsigned int)v58 )
        {
          v60 = 1;
        }
        else if ( *(_DWORD *)(v182 + 596) >= (unsigned int)v58 )
        {
          v60 = 2;
        }
        else if ( *(_DWORD *)(v182 + 600) >= (unsigned int)v58 )
        {
          v60 = 3;
        }
        else if ( *(_DWORD *)(v182 + 604) >= (unsigned int)v58 )
        {
          v60 = 4;
        }
        else
        {
          v2 = v36;
          if ( *(_DWORD *)(v182 + 608) >= (unsigned int)v58 )
          {
            v60 = 5;
          }
          else if ( *(_DWORD *)(v182 + 612) >= (unsigned int)v58 )
          {
            v60 = 6;
          }
          else if ( *(_DWORD *)(v182 + 616) >= (unsigned int)v58 )
          {
            v60 = 7;
          }
          else if ( *(_DWORD *)(v182 + 620) >= (unsigned int)v58 )
          {
            v60 = 8;
          }
          else
          {
            if ( *(_DWORD *)(v182 + 624) < (unsigned int)v58 )
            {
              v59 = debug_mdl & 0x2000100;
              if ( (debug_mdl & 0x2000100) == 0 || debug_priority )
                goto LABEL_133;
              goto LABEL_531;
            }
            v60 = 9;
          }
          v20 = v176;
        }
        LODWORD(v58) = *(_DWORD *)(v182 + 592 + 4 * v60);
        goto LABEL_234;
      }
      v2 = *(unsigned int *)(v20 + 28);
      if ( *(_DWORD *)(v182 + 592) >= (unsigned int)v2 )
      {
        v57 = 1;
      }
      else if ( *(_DWORD *)(v182 + 596) >= (unsigned int)v2 )
      {
        v57 = 2;
      }
      else if ( *(_DWORD *)(v182 + 600) >= (unsigned int)v2 )
      {
        v57 = 3;
      }
      else if ( *(_DWORD *)(v182 + 604) >= (unsigned int)v2 )
      {
        v57 = 4;
      }
      else if ( *(_DWORD *)(v182 + 608) >= (unsigned int)v2 )
      {
        v57 = 5;
      }
      else
      {
        v52 = v36;
        if ( *(_DWORD *)(v182 + 612) >= (unsigned int)v2 )
        {
          v57 = 6;
        }
        else if ( *(_DWORD *)(v182 + 616) >= (unsigned int)v2 )
        {
          v57 = 7;
        }
        else if ( *(_DWORD *)(v182 + 620) >= (unsigned int)v2 )
        {
          v57 = 8;
        }
        else
        {
          if ( *(_DWORD *)(v182 + 624) < (unsigned int)v2 )
          {
            v53 = 0;
            if ( (debug_mdl & 0x2000100) == 0 )
            {
              v20 = v176;
              goto LABEL_236;
            }
            v20 = v176;
            if ( debug_priority )
              goto LABEL_236;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x2000100,
              4,
              "cam_icp_get_next_clk_rate",
              338,
              "%s: Already clk at higher level",
              (const char *)(v183 + 29824));
            v20 = v176;
            v36 = v52;
            v54 = *(_DWORD *)(v176 + 28);
            goto LABEL_226;
          }
          v57 = 9;
        }
        v20 = v176;
      }
      v68 = *(_DWORD *)(v182 + 592 + 4 * v57);
      v54 = v2;
      v2 = v68;
LABEL_226:
      if ( v54 >= (unsigned int)v2 )
      {
        v53 = 0;
        goto LABEL_236;
      }
      *(_DWORD *)(v20 + 28) = v2;
      goto LABEL_235;
    }
    v45 = 0;
    v46 = 0;
    v47 = *(_QWORD *)(v183 + 16);
    *(_DWORD *)(v182 + 560) = *(_DWORD *)(v36 + 48);
    *(_DWORD *)(v182 + 568) = v2;
    v48 = *(_DWORD *)(v47 + 8);
    *(_DWORD *)(v20 + 24) = 0;
    do
    {
      v49 = *(_QWORD *)(*((_QWORD *)v4 + 12) + v45);
      if ( v49 && *(_DWORD *)(v49 + 104) == 2 && *(_DWORD *)(*(_QWORD *)(v49 + 16) + 8LL) == v48 )
      {
        v46 += *(_DWORD *)(v49 + 29240);
        *(_DWORD *)(v20 + 24) = v46;
      }
      v45 += 8;
    }
    while ( v45 != 432 );
    v50 = *(_DWORD *)(v182 + 592);
    if ( v50 >= v46 )
    {
      v51 = 0;
    }
    else if ( *(_DWORD *)(v182 + 596) >= v46 )
    {
      v51 = 1;
    }
    else if ( *(_DWORD *)(v182 + 600) >= v46 )
    {
      v51 = 2;
    }
    else if ( *(_DWORD *)(v182 + 604) >= v46 )
    {
      v51 = 3;
    }
    else if ( *(_DWORD *)(v182 + 608) >= v46 )
    {
      v51 = 4;
    }
    else if ( *(_DWORD *)(v182 + 612) >= v46 )
    {
      v51 = 5;
    }
    else
    {
      if ( *(_DWORD *)(v182 + 616) >= v46 )
      {
        v51 = 6;
      }
      else if ( *(_DWORD *)(v182 + 620) >= v46 )
      {
        v51 = 7;
      }
      else if ( *(_DWORD *)(v182 + 624) >= v46 )
      {
        v51 = 8;
      }
      else if ( *(_DWORD *)(v182 + 628) >= v46 )
      {
        v51 = 9;
      }
      else
      {
        v51 = 10;
      }
      v20 = v176;
    }
    v61 = *(_DWORD *)(v20 + 28);
    if ( v50 >= v61 )
    {
      v2 = 0;
    }
    else if ( *(_DWORD *)(v182 + 596) >= v61 )
    {
      v2 = 1;
    }
    else if ( *(_DWORD *)(v182 + 600) >= v61 )
    {
      v2 = 2;
    }
    else if ( *(_DWORD *)(v182 + 604) >= v61 )
    {
      v2 = 3;
    }
    else if ( *(_DWORD *)(v182 + 608) >= v61 )
    {
      v2 = 4;
    }
    else
    {
      if ( *(_DWORD *)(v182 + 612) < v61 )
      {
        if ( *(_DWORD *)(v182 + 616) < v61 )
        {
          if ( *(_DWORD *)(v182 + 620) >= v61 )
          {
            v2 = 7;
          }
          else
          {
            if ( *(_DWORD *)(v182 + 624) < v61 )
            {
              if ( *(_DWORD *)(v182 + 628) >= v61 )
                v2 = 9;
              else
                v2 = 10;
              goto LABEL_173;
            }
            v2 = 8;
          }
          v20 = v176;
          goto LABEL_179;
        }
        v2 = 6;
LABEL_173:
        v20 = v176;
        goto LABEL_179;
      }
      v2 = 5;
    }
LABEL_179:
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_is_over_clk",
        306,
        "%s: bc_idx = %d cc_idx = %d %d %d",
        (const char *)(v183 + 29824),
        v51,
        v2,
        v46,
        v61);
      v20 = v176;
      v46 = *(_DWORD *)(v176 + 24);
      v61 = *(_DWORD *)(v176 + 28);
    }
    v62 = (unsigned int *)(v182 + 592);
    if ( v61 <= v46 || (unsigned int)v2 <= v51 )
    {
      if ( v61 > v46 )
      {
        v53 = 0;
        *(_DWORD *)(v20 + 40) = 0;
        goto LABEL_237;
      }
      if ( v61 >= v46 )
      {
        v53 = 0;
        goto LABEL_237;
      }
      v66 = *v62;
      if ( *v62 < v46 )
      {
        v66 = *(_DWORD *)(v182 + 596);
        if ( v66 < v46 )
        {
          v66 = *(_DWORD *)(v182 + 600);
          if ( v66 < v46 )
          {
            v66 = *(_DWORD *)(v182 + 604);
            if ( v66 < v46 )
            {
              v66 = *(_DWORD *)(v182 + 608);
              if ( v66 < v46 )
              {
                v66 = *(_DWORD *)(v182 + 612);
                if ( v66 < v46 )
                {
                  v66 = *(_DWORD *)(v182 + 616);
                  if ( v66 < v46 )
                  {
                    v66 = *(_DWORD *)(v182 + 620);
                    if ( v66 < v46 )
                    {
                      v66 = *(_DWORD *)(v182 + 624);
                      if ( v66 < v46 )
                      {
                        v66 = *(_DWORD *)(v182 + 628);
                        if ( v66 <= v46 )
                          v66 = v46;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      *(_DWORD *)(v20 + 28) = v66;
      goto LABEL_529;
    }
    v64 = *(_DWORD *)(v20 + 36);
    v63 = *(_DWORD *)(v20 + 40);
    v53 = v63 >= v64;
    if ( v63 < v64 )
    {
      *(_DWORD *)(v20 + 40) = v63 + 1;
      goto LABEL_237;
    }
    if ( *v62 >= v61 )
    {
      if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      {
        v67 = v63 >= v64;
        v2 = v61;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000100,
          4,
          "cam_icp_get_lower_clk_rate",
          324,
          "%s: Already clk at lower level",
          (const char *)(v183 + 29824));
        v62 = (unsigned int *)(v182 + 592);
        v20 = v176;
        v61 = v2;
        v53 = v67;
        v46 = *(_DWORD *)(v176 + 24);
      }
    }
    else if ( *(_DWORD *)(v182 + 596) >= v61 )
    {
      v61 = *v62;
    }
    else if ( *(_DWORD *)(v182 + 600) >= v61 )
    {
      v61 = *(_DWORD *)(v182 + 596);
    }
    else if ( *(_DWORD *)(v182 + 604) >= v61 )
    {
      v61 = *(_DWORD *)(v182 + 600);
    }
    else
    {
      if ( *(_DWORD *)(v182 + 608) >= v61 )
      {
        v65 = 3;
      }
      else if ( *(_DWORD *)(v182 + 612) >= v61 )
      {
        v65 = 4;
      }
      else if ( *(_DWORD *)(v182 + 616) >= v61 )
      {
        v65 = 5;
      }
      else if ( *(_DWORD *)(v182 + 620) >= v61 )
      {
        v65 = 6;
      }
      else if ( *(_DWORD *)(v182 + 624) >= v61 )
      {
        v65 = 7;
      }
      else
      {
        v65 = 8;
        if ( *(_DWORD *)(v182 + 628) < v61 )
          v65 = 9;
      }
      v20 = v176;
      v61 = v62[v65];
    }
    *(_DWORD *)(v20 + 28) = v61;
    if ( v61 > v46 )
    {
      if ( *v62 >= v46 )
      {
        v2 = 0;
      }
      else if ( *(_DWORD *)(v182 + 596) >= v46 )
      {
        v2 = 1;
      }
      else if ( *(_DWORD *)(v182 + 600) >= v46 )
      {
        v2 = 2;
      }
      else
      {
        if ( *(_DWORD *)(v182 + 604) >= v46 )
        {
          v2 = 3;
        }
        else if ( *(_DWORD *)(v182 + 608) >= v46 )
        {
          v2 = 4;
        }
        else if ( *(_DWORD *)(v182 + 612) >= v46 )
        {
          v2 = 5;
        }
        else if ( *(_DWORD *)(v182 + 616) >= v46 )
        {
          v2 = 6;
        }
        else if ( *(_DWORD *)(v182 + 620) >= v46 )
        {
          v2 = 7;
        }
        else if ( *(_DWORD *)(v182 + 624) >= v46 )
        {
          v2 = 8;
        }
        else if ( *(_DWORD *)(v182 + 628) >= v46 )
        {
          v2 = 9;
        }
        else
        {
          v2 = 10;
        }
        v20 = v176;
      }
      if ( *v62 >= v61 )
      {
        v162 = 0;
      }
      else if ( *(_DWORD *)(v182 + 596) >= v61 )
      {
        v162 = 1;
      }
      else
      {
        if ( *(_DWORD *)(v182 + 600) < v61 )
        {
          if ( *(_DWORD *)(v182 + 604) < v61 )
          {
            if ( *(_DWORD *)(v182 + 608) >= v61 )
            {
              v162 = 4;
            }
            else if ( *(_DWORD *)(v182 + 612) >= v61 )
            {
              v162 = 5;
            }
            else if ( *(_DWORD *)(v182 + 616) >= v61 )
            {
              v162 = 6;
            }
            else if ( *(_DWORD *)(v182 + 620) >= v61 )
            {
              v162 = 7;
            }
            else
            {
              if ( *(_DWORD *)(v182 + 624) < v61 )
              {
                if ( *(_DWORD *)(v182 + 628) >= v61 )
                  v162 = 9;
                else
                  v162 = 10;
                goto LABEL_512;
              }
              v162 = 8;
            }
            v20 = v176;
            goto LABEL_520;
          }
          v162 = 3;
LABEL_512:
          v20 = v176;
          goto LABEL_520;
        }
        v162 = 2;
      }
LABEL_520:
      if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      {
        v175 = v53;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000100,
          4,
          "cam_icp_is_over_clk",
          306,
          "%s: bc_idx = %d cc_idx = %d %d %d",
          (const char *)(v183 + 29824),
          v2,
          v162,
          v46,
          v61);
        v53 = v175;
        v20 = v176;
        if ( v162 > (unsigned int)v2 )
          goto LABEL_523;
      }
      else if ( v162 > (unsigned int)v2 )
      {
        goto LABEL_523;
      }
LABEL_529:
      v53 = 1;
      goto LABEL_237;
    }
    if ( v61 >= v46 )
    {
LABEL_523:
      *(_DWORD *)(v20 + 40) = 0;
      goto LABEL_237;
    }
    if ( *v62 >= v61 )
    {
      v2 = v62[1];
    }
    else
    {
      if ( *(_DWORD *)(v182 + 596) < v61 )
      {
        v160 = v53;
        if ( *(_DWORD *)(v182 + 600) >= v61 )
        {
          v161 = 3;
        }
        else
        {
          v2 = v61;
          if ( *(_DWORD *)(v182 + 604) >= v61 )
          {
            v161 = 4;
          }
          else if ( *(_DWORD *)(v182 + 608) >= v61 )
          {
            v161 = 5;
          }
          else if ( *(_DWORD *)(v182 + 612) >= v61 )
          {
            v161 = 6;
          }
          else if ( *(_DWORD *)(v182 + 616) >= v61 )
          {
            v161 = 7;
          }
          else if ( *(_DWORD *)(v182 + 620) >= v61 )
          {
            v161 = 8;
          }
          else
          {
            if ( *(_DWORD *)(v182 + 624) < v61 )
            {
              if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x2000100,
                  4,
                  "cam_icp_get_next_clk_rate",
                  338,
                  "%s: Already clk at higher level",
                  (const char *)(v183 + 29824));
              v20 = v176;
              goto LABEL_526;
            }
            v161 = 9;
          }
        }
        v20 = v176;
        v2 = v62[v161];
LABEL_526:
        v53 = v160;
        goto LABEL_527;
      }
      v2 = v62[2];
    }
LABEL_527:
    *(_DWORD *)(v20 + 28) = v2;
    *(_DWORD *)(v20 + 40) = 0;
    goto LABEL_237;
  }
  if ( v23 == *(_DWORD *)(v20 + 28) )
    goto LABEL_245;
  *(_DWORD *)(v20 + 24) = v23;
  v24 = debug_mdl & 0x2000100;
  *(_DWORD *)(v20 + 28) = *((_DWORD *)v181 + 784);
  v25 = *((_QWORD *)v181 + 392);
  *(_QWORD *)(v20 + 48) = v25;
  *(_QWORD *)(v20 + 56) = v25;
  if ( !v24 || debug_priority )
    goto LABEL_240;
  v26 = "cam_icp_debug_clk_update";
  v27 = v4 + 112;
  v28 = 1253;
LABEL_44:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
    3,
    v24,
    4,
    v26,
    v28,
    "[%s] bc = %d cc = %d",
    v27);
LABEL_240:
  while ( 2 )
  {
    v2 = 29824;
    v69 = *(_QWORD *)(v183 + 16);
    memset(s, 0, 64);
    scnprintf(s, 64, "%s Before clk update rate=%u", (const char *)(v183 + 29824), *(_DWORD *)(v69 + 32));
    cam_cpas_notify_event((__int64)s, *(_DWORD *)(v69 + 32));
    v70 = *(_DWORD *)(v69 + 28);
    *(_DWORD *)(v69 + 32) = v70;
    scnprintf(s, 64, "%s After clk update rate=%u", (const char *)(v183 + 29824), v70);
    cam_cpas_notify_event((__int64)s, v70);
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_update_clk_rate",
        1646,
        "%s: clk_rate %u",
        (const char *)(v183 + 29824),
        v70);
    v4 = v177;
    if ( !*((_DWORD *)v181 + 804) )
      cam_icp_update_clk_util(v70, v177, v183);
LABEL_245:
    if ( (unsigned int)v14 >= 0x28 )
      goto LABEL_393;
    v71 = 0;
    v72 = 0;
    v2 = v183 + v13 + 6184;
    v73 = (_QWORD *)(v183 + v13 + 6192);
    v74 = *(_QWORD *)(v183 + v12 + 1784);
    v75 = v183 + 4824;
    v176 = *(_QWORD *)(v183 + 16);
    do
    {
      v76 = *(_QWORD *)(v75 + 8 * v71 - 3040);
      if ( v76 && *(_BYTE *)(v75 + v71) == 1 )
      {
        if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
        {
          v169 = v73;
          v172 = v74;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x2000100,
            4,
            "cam_icp_busy_prev_reqs",
            1065,
            "r id = %lld busy = %d",
            v76,
            1);
          v73 = v169;
          v74 = v172;
        }
        ++v72;
      }
      ++v71;
    }
    while ( v71 != 40 );
    v77 = *(_DWORD *)(v182 + 556);
    if ( v77 != 2 )
    {
      v4 = v177;
      if ( v77 == 1 )
      {
        v78 = debug_mdl & 0x2000100;
        v79 = debug_priority;
        if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v78,
            4,
            "cam_icp_check_bw_update",
            1543,
            "%s: Req[%lld] Current camno=%lld, mnoc=%lld",
            (const char *)(v183 + 29824),
            v74,
            *(_QWORD *)(v176 + 48),
            *(_QWORD *)(v176 + 56));
          v79 = debug_priority;
          v80 = v176;
          v78 = debug_mdl & 0x2000100;
          if ( (debug_mdl & 0x2000100) == 0 )
            goto LABEL_261;
        }
        else
        {
          v80 = v176;
          if ( (debug_mdl & 0x2000100) == 0 )
            goto LABEL_261;
        }
        if ( !v79 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v78,
            4,
            "cam_icp_update_bw",
            1415,
            "%s: ubw ctx = %lld clk_info ubw = %lld busy = %d",
            (const char *)(v183 + 29824),
            *(_QWORD *)(v183 + 29248),
            *(_QWORD *)((char *)v15 + v183 - 8),
            v72 > 1);
          v80 = v176;
        }
LABEL_261:
        v81 = *(_QWORD *)(v183 + 29248);
        v82 = *(_QWORD *)((char *)v15 + v183 - 8);
        if ( v82 == v81 && v82 == *(_QWORD *)(v80 + 48) )
        {
          v15 = (unsigned int *)v182;
          v83 = v183;
          if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x2000100,
              4,
              "cam_icp_update_bw",
              1421,
              "%s: Update not required bw=%lld",
              (const char *)(v183 + 29824),
              v82);
        }
        else
        {
          if ( v72 < 2 || v81 <= v82 )
          {
            v2 = 0;
            i = 29824;
            v11 = "%s: Current context=[%lld %lld] Total=[%lld %lld]";
            *(_QWORD *)(v183 + 29248) = v82;
            v90 = *(_QWORD *)((char *)v15 + v183);
            v15 = (unsigned int *)v182;
            *(_QWORD *)(v183 + 29256) = v90;
            *(_QWORD *)(v80 + 48) = 0;
            *(_QWORD *)(v80 + 56) = 0;
            do
            {
              v91 = *(_QWORD *)(*((_QWORD *)v177 + 12) + v2);
              if ( v91 )
              {
                if ( *(_DWORD *)(v91 + 104) == 2
                  && *(_DWORD *)(*(_QWORD *)(v183 + 16) + 8LL) == *(_DWORD *)(*(_QWORD *)(v91 + 16) + 8LL) )
                {
                  v92 = *(_QWORD *)(v80 + 56);
                  v93 = *(_QWORD *)(v80 + 48) + *(_QWORD *)(v91 + 29248);
                  v94 = debug_mdl & 0x2000100;
                  *(_QWORD *)(v80 + 48) = v93;
                  v95 = v92 + *(_QWORD *)(v91 + 29256);
                  *(_QWORD *)(v80 + 56) = v95;
                  if ( v94 )
                  {
                    if ( !debug_priority )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        v94,
                        4,
                        "cam_icp_update_bw",
                        1458,
                        "%s: Current context=[%lld %lld] Total=[%lld %lld]",
                        (const char *)(v183 + 29824),
                        *(_QWORD *)(v91 + 29248),
                        *(_QWORD *)(v91 + 29256),
                        v93,
                        v95);
                      v80 = v176;
                    }
                  }
                }
              }
              v2 += 8LL;
            }
            while ( v2 != 432 );
            v83 = v183;
            *(_BYTE *)(v182 + 1120) = 1;
            goto LABEL_396;
          }
          v15 = (unsigned int *)v182;
          v83 = v183;
          if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              debug_mdl & 0x2000100,
              4,
              "cam_icp_update_bw",
              1432,
              "%s: Busy, Update not required existing=%lld, new=%lld",
              v183 + 29824);
        }
        goto LABEL_424;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_icp_check_bw_update",
        1577,
        "%s: Invalid bw config version: %d",
        v177 + 112);
LABEL_279:
      v15 = (unsigned int *)v182;
      v83 = v183;
      goto LABEL_424;
    }
    v4 = v177;
    v84 = v183 + 4 * i;
    v85 = *(_DWORD *)(v176 + 64);
    v86 = *(_DWORD *)(v84 + 6164);
    if ( v86 > 0xC || v85 >= 0xD )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_check_bw_update",
        1553,
        "Invalid num of clk path req num path:%d, dev num path:%d",
        v86,
        v85);
      goto LABEL_279;
    }
    v87 = v84 + 4824;
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      i = (unsigned __int64)v73;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_check_bw_update",
        1558,
        "%s: index=%d, num_paths=%d, ctx_data=%pK",
        (const char *)(v183 + 29824),
        v14,
        v86,
        (const void *)v183);
      v86 = *(_DWORD *)(v87 + 1340);
      v73 = (_QWORD *)i;
      v15 = (unsigned int *)v182;
      if ( v86 )
      {
LABEL_271:
        v88 = debug_mdl;
        v89 = debug_priority;
        for ( i = 0; i < v86; ++i )
        {
          if ( (v88 & 0x2000100) != 0 && !v89 )
          {
            if ( i >= 0xC )
              goto LABEL_393;
            v170 = v73;
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v88 & 0x2000100,
              4,
              "cam_icp_update_bw_v2",
              1294,
              "%s: clk_info camnoc = %lld busy = %d",
              (const char *)(v183 + 29824),
              *(_QWORD *)v2,
              v72 > 1);
            v89 = debug_priority;
            v73 = v170;
            v88 = debug_mdl;
            v86 = *(_DWORD *)(v87 + 1340);
          }
          v2 += 40LL;
        }
        v96 = *(_DWORD *)(v182 + 632);
        if ( v86 == v96 )
        {
          if ( v86 )
          {
            v97 = 0;
            v98 = (_QWORD *)(v183 + 29336);
            while ( v97 != 12 )
            {
              if ( *((_DWORD *)v73 - 5) != *((_DWORD *)v98 - 5)
                || *((_DWORD *)v73 - 4) != *((_DWORD *)v98 - 4)
                || *(v73 - 1) != *(v98 - 1)
                || *v73 != *v98 )
              {
                goto LABEL_305;
              }
              ++v97;
              v98 += 5;
              v73 += 5;
              if ( v86 == v97 )
                goto LABEL_304;
            }
LABEL_393:
            __break(0x5512u);
LABEL_394:
            v15 = (unsigned int *)v182;
            goto LABEL_395;
          }
LABEL_304:
          v15 = (unsigned int *)v182;
LABEL_382:
          v2 = 0;
          if ( (v88 & 0x2000100) != 0 && !v89 )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v88 & 0x2000100,
              4,
              "cam_icp_update_bw_v2",
              1318,
              "%s: Incoming BW hasn't changed, no update required, num_paths=%d",
              (const char *)(v183 + 29824),
              v86);
            v2 = 0;
          }
LABEL_385:
          v120 = v176;
          v121 = *(unsigned int *)(v176 + 64);
          goto LABEL_386;
        }
LABEL_305:
        if ( v72 >= 2 && v86 )
        {
          v99 = (_QWORD *)(v183 + 8LL * (_QWORD)v11);
          if ( *(_QWORD *)(v183 + 29328) > v99[773] )
            goto LABEL_308;
          if ( v86 != 1 )
          {
            if ( *(_QWORD *)(v183 + 29368) > v99[778] )
              goto LABEL_308;
            if ( v86 != 2 )
            {
              if ( *(_QWORD *)(v183 + 29408) > v99[783] )
              {
LABEL_308:
                v15 = (unsigned int *)v182;
                v2 = 0;
                goto LABEL_385;
              }
              if ( v86 != 3 )
              {
                if ( *(_QWORD *)(v183 + 29448) > v99[788] )
                  goto LABEL_317;
                if ( v86 != 4 )
                {
                  if ( *(_QWORD *)(v183 + 29488) > v99[793] )
                    goto LABEL_317;
                  if ( v86 != 5 )
                  {
                    if ( *(_QWORD *)(v183 + 29528) > *(_QWORD *)(v183 + v13 + 6384) )
                      goto LABEL_317;
                    if ( v86 != 6 )
                    {
                      if ( *(_QWORD *)(v183 + 29568) > *(_QWORD *)(v183 + v13 + 6424) )
                        goto LABEL_317;
                      if ( v86 != 7 )
                      {
                        if ( *(_QWORD *)(v183 + 29608) > *(_QWORD *)(v183 + v13 + 6464) )
                          goto LABEL_317;
                        if ( v86 != 8 )
                        {
                          if ( *(_QWORD *)(v183 + 29648) > *(_QWORD *)(v183 + v13 + 6504) )
                            goto LABEL_317;
                          if ( v86 != 9 )
                          {
                            if ( *(_QWORD *)(v183 + 29688) > *(_QWORD *)(v183 + v13 + 6544) )
                              goto LABEL_317;
                            if ( v86 != 10 )
                            {
                              if ( *(_QWORD *)(v183 + 29728) > *(_QWORD *)(v183 + v13 + 6584) )
                                goto LABEL_317;
                              if ( v86 != 11 )
                              {
                                if ( *(_QWORD *)(v183 + 29768) > *(_QWORD *)(v183 + v13 + 6624) )
                                {
LABEL_317:
                                  v4 = v177;
                                  v15 = (unsigned int *)v182;
                                  v2 = 0;
                                  goto LABEL_385;
                                }
                                if ( v86 != 12 )
                                  goto LABEL_393;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v100 = (unsigned int *)(v182 + 632);
        if ( !v96 )
          goto LABEL_358;
        goto LABEL_343;
      }
    }
    else
    {
      v15 = (unsigned int *)v182;
      if ( v86 )
        goto LABEL_271;
    }
    if ( !v15[158] )
    {
      v88 = debug_mdl;
      v89 = debug_priority;
      v86 = 0;
      goto LABEL_382;
    }
    v100 = v15 + 158;
LABEL_343:
    v2 = 0;
    v4 = "cam_icp_validate_bw_path_idx";
    i = v176 + 72;
    v13 = v182 + 644;
    do
    {
      v102 = *(_DWORD *)(*(_QWORD *)(v183 + 16) + 8LL);
      switch ( v102 )
      {
        case 2:
          v103 = *(_DWORD *)(v13 + 4) - 32;
          break;
        case 4:
          v103 = *(_DWORD *)(v13 + 4) - 160;
          break;
        case 3:
          v103 = *(_DWORD *)v13;
          break;
        default:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_get_axi_path_index",
            551,
            "Invalid hw dev type not supported: %u",
            v102);
          if ( v2 == 12 )
            goto LABEL_393;
          goto LABEL_345;
      }
      if ( v2 == 12 )
        goto LABEL_393;
      if ( (v103 & 0x80000000) == 0 )
      {
        if ( v103 < 0xC )
        {
          v104 = (_QWORD *)(i + 40LL * v103);
          v105 = v104[3];
          v106 = v104[4];
          v104[2] -= *(_QWORD *)(v13 + 12);
          v104[3] = v105 - *(_QWORD *)(v13 + 20);
          v104[4] = v106 - *(_QWORD *)(v13 + 28);
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            2,
            "cam_icp_validate_bw_path_idx",
            531,
            "Invalid path: %u IPE start offset: %d, OFE start offset: %d max: %d",
            *(_DWORD *)(v13 + 4),
            32,
            160,
            12);
        }
      }
LABEL_345:
      ++v2;
      v13 += 40;
    }
    while ( v2 < *v100 );
    v86 = *(_DWORD *)(v87 + 1340);
LABEL_358:
    *v100 = v86;
    v107 = *(unsigned int *)(v87 + 1340);
    v108 = 40 * v107;
    if ( (unsigned int)v107 >= 0xD && (cam_icp_update_bw_v2___already_done & 1) == 0 )
    {
      cam_icp_update_bw_v2___already_done = 1;
      i = 40 * v107;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v108,
        "field \"&ctx_data->clk_info.axi_path[0]\" at ../vendor/qcom/opensource/camera-kernel/drivers/cam_icp/icp_hw/icp_"
        "hw_mgr/cam_icp_hw_mgr.c:1355",
        0x1E0u);
      v108 = i;
      __break(0x800u);
    }
    memcpy((void *)(v183 + 29312), (const void *)(v183 + 8LL * (_QWORD)v11 + 6168), v108);
    if ( !*v100 )
    {
      v15 = (unsigned int *)v182;
      v2 = 1;
      v4 = v177;
      *(_BYTE *)(v182 + 1120) = 1;
      goto LABEL_385;
    }
    v4 = v177;
    v109 = 0;
    v2 = v176 + 72;
    i = v182 + 644;
    while ( 2 )
    {
      v111 = *(_DWORD *)(*(_QWORD *)(v183 + 16) + 8LL);
      switch ( v111 )
      {
        case 2:
          v13 = (unsigned int)(*(_DWORD *)(i + 4) - 32);
          goto LABEL_371;
        case 4:
          v13 = (unsigned int)(*(_DWORD *)(i + 4) - 160);
LABEL_371:
          if ( v109 == 12 )
            goto LABEL_393;
          if ( (v13 & 0x80000000) == 0 )
          {
            v112 = *(_DWORD *)(i + 4);
            if ( (unsigned int)v13 < 0xC )
            {
              v113 = v2 + 40LL * (unsigned int)v13;
              *(_DWORD *)(v113 + 8) = v112;
              v114 = *(_QWORD *)(v113 + 16);
              v115 = *(_QWORD *)(v113 + 24);
              v116 = *(_DWORD *)i;
              *(_DWORD *)(v113 + 4) = *(_DWORD *)i;
              v117 = v114 + *(_QWORD *)(i + 12);
              v118 = *(_QWORD *)(v113 + 32);
              *(_QWORD *)(v113 + 16) = v117;
              *(_QWORD *)(v113 + 24) = v115 + *(_QWORD *)(i + 20);
              *(_QWORD *)(v113 + 32) = v118 + *(_QWORD *)(i + 28);
              v11 = (const char *)(debug_mdl & 0x2000100);
              if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
              {
                v173 = cam_cpas_axi_util_trans_type_to_string(v116);
                v119 = cam_cpas_axi_util_path_type_to_string(*(_DWORD *)(v113 + 8));
                ((void (*)(__int64, const char *, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v11,
                  4,
                  "cam_icp_update_bw_v2",
                  1388,
                  "%s: Consolidate Path Vote: i[%d] path_idx[%d] : [%s %s] [%lld %lld]",
                  (const char *)(v183 + 29824),
                  v109,
                  v13,
                  v173,
                  v119,
                  *(_QWORD *)(v113 + 16),
                  *(_QWORD *)(v113 + 24));
              }
            }
            else
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x2000000,
                2,
                "cam_icp_validate_bw_path_idx",
                531,
                "Invalid path: %u IPE start offset: %d, OFE start offset: %d max: %d",
                v112,
                32,
                160,
                12);
            }
          }
          goto LABEL_364;
        case 3:
          v13 = *(unsigned int *)i;
          goto LABEL_371;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_get_axi_path_index",
        551,
        "Invalid hw dev type not supported: %u",
        v111);
      if ( v109 == 12 )
        goto LABEL_393;
LABEL_364:
      v110 = *v100;
      ++v109;
      i += 40LL;
      if ( v109 < v110 )
        continue;
      break;
    }
    v15 = (unsigned int *)v182;
    v2 = 1;
    v120 = v176;
    *(_BYTE *)(v182 + 1120) = 1;
    v121 = *(unsigned int *)(v176 + 64);
    if ( v121 < v110 )
    {
      *(_DWORD *)(v176 + 64) = v110;
LABEL_387:
      v122 = debug_mdl;
      v123 = debug_priority;
      i = 0;
      v124 = (_QWORD *)(v120 + 104);
      v11 = "%s: Final path_type: %s, transac_type: %s, camnoc_bw = %lld mnoc_ab_bw = %lld, mnoc_ib_bw = %lld";
      while ( 1 )
      {
        v13 = v122 & 0x2000100;
        if ( (v122 & 0x2000100) != 0 && !v123 )
        {
          if ( i > 0xB )
            goto LABEL_393;
          v174 = cam_cpas_axi_util_path_type_to_string(*((_DWORD *)v124 - 6));
          v125 = cam_cpas_axi_util_trans_type_to_string(*((_DWORD *)v124 - 7));
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v13,
            4,
            "cam_icp_check_bw_update",
            1573,
            "%s: Final path_type: %s, transac_type: %s, camnoc_bw = %lld mnoc_ab_bw = %lld, mnoc_ib_bw = %lld",
            (const char *)(v183 + 29824),
            v174,
            v125,
            *(v124 - 2),
            *(v124 - 1),
            *v124);
          v122 = debug_mdl;
          v123 = debug_priority;
          v110 = *(unsigned int *)(v176 + 64);
        }
        ++i;
        v124 += 5;
        if ( i >= v110 )
          goto LABEL_394;
      }
    }
LABEL_386:
    v110 = v121;
    if ( v121 )
      goto LABEL_387;
LABEL_395:
    v83 = v183;
    if ( !(_DWORD)v2 )
      goto LABEL_424;
LABEL_396:
    memset(s, 0, 0x278u);
    v126 = *(_QWORD *)(v83 + 16);
    v30 = *(_DWORD *)(v126 + 580);
    v127 = *(_DWORD *)(v126 + 8);
    if ( (unsigned int)v30 < 2 )
    {
      v128 = 1;
      goto LABEL_401;
    }
    if ( v30 != 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_get_bw_device_share_ratio",
        573,
        "[%s] Number of devices %u not supported for geting bw device share ratio",
        v4 + 112,
        v30);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_update_cpas_vote",
        1671,
        "%s: Fail to get device share ratio",
        (const char *)(v183 + 29824));
      goto LABEL_423;
    }
    v128 = 2;
LABEL_401:
    LODWORD(s[0]) = 1;
    if ( v15[139] == 1 )
    {
      v129 = *(_QWORD *)(v126 + 48) / v128;
      v130 = *(_QWORD *)(v126 + 56) / v128;
      if ( v127 == 2 )
        v131 = 34;
      else
        v131 = 163;
      if ( v127 == 3 )
        v132 = 256;
      else
        v132 = v131;
      HIDWORD(s[3]) = 1;
      LODWORD(s[4]) = v132;
      LODWORD(s[2]) = 1;
      s[5] = v129;
      s[6] = v130;
      s[7] = v130;
      goto LABEL_414;
    }
    LODWORD(s[2]) = *(_DWORD *)(v126 + 64);
    v58 = LODWORD(s[2]);
    v133 = 40LL * LODWORD(s[2]);
    if ( LODWORD(s[2]) >= 0x10 )
    {
      _fortify_panic(17, 608, v133);
LABEL_531:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v59,
        4,
        "cam_icp_get_next_clk_rate",
        338,
        "%s: Already clk at higher level",
        (const char *)(v183 + 29824));
LABEL_133:
      v20 = v176;
      v36 = v2;
LABEL_234:
      *(_DWORD *)(v20 + 28) = v58;
LABEL_235:
      v53 = 1;
LABEL_236:
      *(_DWORD *)(v182 + 560) = *(_DWORD *)(v36 + 48);
LABEL_237:
      if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      {
        v101 = v53;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000100,
          4,
          "cam_icp_check_clk_update",
          1517,
          "%s: bc = %d cc = %d busy = %d overclk = %d uc = %d",
          (const char *)(v183 + 29824),
          *(_DWORD *)(v20 + 24),
          *(_DWORD *)(v20 + 28),
          v30 > 1,
          *(_DWORD *)(v20 + 40),
          v53);
        if ( v101 )
          continue;
      }
      else if ( v53 )
      {
        continue;
      }
      goto LABEL_245;
    }
    break;
  }
  memcpy(&s[3], (const void *)(v126 + 72), v133);
  if ( (unsigned int)v30 >= 2 && (_DWORD)v58 )
  {
    v134 = &s[7];
    do
    {
      --v58;
      v135 = *(v134 - 1) >> 1;
      v136 = *v134 >> 1;
      *(v134 - 2) >>= 1;
      *(v134 - 1) = v135;
      *v134 = v136;
      v134 += 5;
    }
    while ( v58 );
  }
LABEL_414:
  HIDWORD(s[78]) = 1;
  v137 = *(_QWORD *)(v183 + 16);
  if ( *(_DWORD *)(v137 + 580) )
  {
    v138 = 0;
    while ( 1 )
    {
      v139 = *(_QWORD *)(*(_QWORD *)(v137 + 16) + 8LL * v138);
      if ( !v139 )
        break;
      v140 = *(_DWORD **)(v139 + 88);
      v141 = *(_QWORD *)(v139 + 112);
      if ( *(v140 - 1) != -1055839300 )
        __break(0x8228u);
      v142 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v140)(v141, 3, s, 632);
      if ( v142 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          1,
          "cam_icp_update_cpas_vote",
          1748,
          "%s: Failed in updating cpas vote for %s cell idx: %u, rc=%d",
          (const char *)(v183 + 29824),
          **(const char ***)(v183 + 16),
          v138,
          v142);
      v137 = *(_QWORD *)(v183 + 16);
      if ( (unsigned int)++v138 >= *(_DWORD *)(v137 + 580) )
        goto LABEL_423;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_update_cpas_vote",
      1740,
      "Device intf for %s[%u] is NULL",
      *(const char **)v137,
      v138);
  }
LABEL_423:
  v83 = v183;
LABEL_424:
  *(_BYTE *)(v83 + v14 + 4824) = 1;
  *(_QWORD *)(v83 + v12 + 28864) = ktime_get_with_offset(1);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_config_hw",
      6264,
      "%s: req_id %llu, io config %llu",
      (const char *)(v183 + 29824),
      v179,
      v178[1]);
  if ( v178[1] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      3,
      "cam_icp_mgr_config_hw",
      6267,
      "%s: Send recfg io",
      (const char *)(v183 + 29824));
    v143 = *(_QWORD *)(v183 + 8);
    task = cam_req_mgr_workq_get_task(*(_QWORD *)(v143 + 992));
    if ( !task
      || (v145 = *((_QWORD *)task + 1),
          *(_QWORD *)(v145 + 8) = v178 + 2,
          *(_DWORD *)(v145 + 16) = v179,
          *(_DWORD *)v145 = 1,
          *((_QWORD *)task + 2) = cam_icp_mgr_process_cmd,
          (unsigned int)cam_req_mgr_workq_enqueue_task((unsigned int *)task, v143, 0)) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_config_hw",
        6272,
        "%s: Fail to send reconfig io cmd",
        (const char *)(v183 + 29824));
    }
  }
  v146 = (_QWORD *)v183;
  v147 = v179;
  if ( v179 <= *(_QWORD *)(v183 + 29816) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      2,
      "cam_icp_mgr_config_hw",
      6278,
      "%s: Anomaly submitting flushed req %llu [last_flush %llu]",
      (const char *)(v183 + 29824),
      v179,
      *(_QWORD *)(v183 + 29816));
    v147 = v179;
  }
  cam_cpas_notify_event(v183 + 29824, v147);
  if ( *((_DWORD *)v181 + 797) )
  {
    v148 = -11;
    goto LABEL_435;
  }
  v155 = (__int64 *)v180[5];
  v156 = v180[2];
  v157 = *v155;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_enqueue_config",
      6067,
      "[%s] req_id = %lld %pK",
      v4 + 112,
      v157,
      v155);
  v158 = cam_req_mgr_workq_get_task(*((_QWORD *)v4 + 124));
  if ( !v158 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_enqueue_config",
      6071,
      "[%s] no empty task",
      v4 + 112);
    v146 = (_QWORD *)v183;
    v148 = -12;
    goto LABEL_435;
  }
  v159 = *((_QWORD *)v158 + 1);
  *(_QWORD *)(v159 + 8) = *(_QWORD *)(v156 + 16);
  *(_DWORD *)(v159 + 16) = v157;
  *(_DWORD *)v159 = 1;
  *((_QWORD *)v158 + 2) = cam_icp_mgr_process_cmd;
  v148 = cam_req_mgr_workq_enqueue_task((unsigned int *)v158, (__int64)v4, 0);
  v146 = (_QWORD *)v183;
  if ( v148 )
  {
LABEL_435:
    s[21] = 0;
    s[22] = 0;
    v184[1] = 1;
    v149 = v148;
    v150 = (__int64 *)v180[5];
    memset(s, 0, 168);
    v151 = *v150;
    LODWORD(s[22]) = 104;
    s[21] = v151;
    v184[0] = s;
    v152 = (_DWORD *)v146[12];
    v153 = *v146;
    if ( *(v152 - 1) != 414296116 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *))v152)(v153, 0, v184);
    _X8 = (unsigned __int64 *)v146[215];
    v146[v12 / 8 + 223] = 0;
    *((_BYTE *)v146 + v14 + 4824) = 0;
    __asm { PRFM            #0x11, [X8] }
    do
      v168 = __ldxr(_X8);
    while ( __stxr(v168 & ~(1LL << v14), _X8) );
    mutex_unlock(*((_QWORD *)v4 + 11) + 48LL * v15[138]);
    mutex_unlock(v4);
    result = v149;
    goto LABEL_438;
  }
  if ( (debug_mdl & 0x1000100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000100,
      4,
      "cam_icp_mgr_config_hw",
      6287,
      "%s: req_id = %lld queued to FW",
      (const char *)(v183 + 29824),
      v179);
  mutex_unlock(*((_QWORD *)v4 + 11) + 48LL * v15[138]);
  mutex_unlock(v4);
  result = 0;
LABEL_438:
  _ReadStatusReg(SP_EL0);
  return result;
}
