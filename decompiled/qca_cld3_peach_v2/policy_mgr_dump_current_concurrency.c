__int64 __fastcall policy_mgr_dump_current_concurrency(__int64 a1)
{
  size_t v1; // x21
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *v11; // x23
  __int64 result; // x0
  int v13; // w22
  const char *v14; // x25
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x24
  __int64 v25; // x19
  unsigned __int64 v26; // x23
  unsigned __int8 v27; // w26
  unsigned __int64 v28; // x20
  __int64 v29; // x1
  unsigned int ml_links_info; // w0
  size_t v31; // x28
  size_t v32; // x0
  __int64 v33; // x19
  size_t v34; // x2
  unsigned __int64 v35; // x27
  __int64 v36; // x19
  int v37; // w28
  __int64 v38; // x25
  size_t v39; // x2
  const char *v40; // x8
  bool v41; // w8
  unsigned __int64 v42; // x8
  bool v43; // zf
  const char *v44; // x5
  size_t v45; // x0
  size_t v46; // x2
  __int64 v47; // x25
  size_t v48; // x0
  size_t v49; // x2
  __int64 v50; // x19
  char *v51; // x0
  size_t v52; // x2
  size_t v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x19
  size_t v63; // x2
  const char *v64; // x1
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  const char *v73; // x2
  unsigned int v74; // w19
  __int64 v75; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x19
  char is_mlo_vdev; // w25
  unsigned int *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int v95; // w21
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x19
  size_t v105; // x2
  const char *v106; // x1
  __int64 v107; // x19
  size_t v108; // x2
  const char *v109; // x1
  char v110; // w22
  __int64 v111; // x19
  size_t v112; // x2
  const char *v113; // x1
  unsigned int v114; // w21
  __int64 v115; // x0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x21
  char v125; // w22
  unsigned int *v126; // x8
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  size_t v135; // x0
  size_t v136; // x2
  __int64 v137; // x19
  char is_current_hwmode_dbs; // w8
  __int64 v139; // x0
  __int64 v140; // x0
  __int64 v141; // x1
  __int64 v142; // [xsp+0h] [xbp-F0h]
  _QWORD *v143; // [xsp+10h] [xbp-E0h]
  size_t v144; // [xsp+20h] [xbp-D0h]
  __int64 v145; // [xsp+28h] [xbp-C8h]
  __int64 v146; // [xsp+38h] [xbp-B8h]
  unsigned __int64 v147; // [xsp+40h] [xbp-B0h]
  __int64 v148; // [xsp+48h] [xbp-A8h]
  unsigned __int64 v149; // [xsp+50h] [xbp-A0h]
  __int64 v150; // [xsp+58h] [xbp-98h]
  unsigned __int64 v151; // [xsp+60h] [xbp-90h]
  unsigned __int64 v152; // [xsp+70h] [xbp-80h]
  char v153[4]; // [xsp+78h] [xbp-78h] BYREF
  char v154[4]; // [xsp+7Ch] [xbp-74h] BYREF
  int v155; // [xsp+80h] [xbp-70h] BYREF
  char v156; // [xsp+84h] [xbp-6Ch]
  _QWORD v157[2]; // [xsp+88h] [xbp-68h] BYREF
  int v158; // [xsp+98h] [xbp-58h]
  char string[8]; // [xsp+A0h] [xbp-50h] BYREF
  __int64 v160; // [xsp+A8h] [xbp-48h]
  _WORD v161[7]; // [xsp+B0h] [xbp-40h] BYREF
  char src[8]; // [xsp+C0h] [xbp-30h] BYREF
  __int64 v163; // [xsp+C8h] [xbp-28h]
  __int64 v164; // [xsp+D0h] [xbp-20h]
  __int64 v165; // [xsp+D8h] [xbp-18h]
  __int64 v166; // [xsp+E0h] [xbp-10h]

  v1 = a1;
  v166 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "policy_mgr_dump_current_concurrency");
LABEL_346:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = (_QWORD *)comp_private_obj;
  result = policy_mgr_get_connection_count(v1);
  if ( !(_DWORD)result )
    goto LABEL_346;
  v13 = result;
  result = _qdf_mem_malloc(0x12Cu, "policy_mgr_dump_current_concurrency", 1761);
  if ( !result )
    goto LABEL_346;
  v14 = (const char *)result;
  policy_mgr_dump_connection_status_info(v1);
  v154[0] = 0;
  v156 = 0;
  v155 = 0;
  v153[0] = 0;
  v158 = 0;
  v157[0] = 0;
  v157[1] = 0;
  v15 = wlan_objmgr_psoc_get_comp_private_obj(v1, 6u);
  v24 = v14;
  if ( !v15 )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v16, v17, v18, v19, v20, v21, v22, v23, "policy_mgr_get_ml_info");
    v27 = 0;
    if ( v13 > 2 )
      goto LABEL_136;
LABEL_120:
    if ( v13 == 1 )
    {
      policy_mgr_dump_current_concurrency_one_connection(v1, v24);
      v73 = "%s: %s Standalone";
LABEL_344:
      qdf_trace_msg(0x4Fu, 8u, v73, v65, v66, v67, v68, v69, v70, v71, v72, "policy_mgr_dump_current_concurrency", v24);
      goto LABEL_345;
    }
    if ( v13 != 2 )
      goto LABEL_164;
    policy_mgr_dump_current_concurrency_two_connection(v1, v24);
    qdf_mutex_acquire((__int64)(v11 + 7));
    if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F0C) )
    {
      v32 = strnlen(v24, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_360;
      if ( v32 <= 0x12B )
      {
        if ( v32 >= 0x128 )
          v62 = 299;
        else
          v62 = v32 + 4;
        if ( v32 >= 0x128 )
          v63 = 299 - v32;
        else
          v63 = 4;
        v64 = " SCC";
LABEL_186:
        memcpy((void *)&v24[v32], v64, v63);
        v24[v62] = 0;
      }
    }
    else
    {
      if ( (policy_mgr_2_freq_always_on_same_mac(v1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) == 0 )
      {
        if ( (policy_mgr_is_current_hwmode_dbs(v1) & 1) != 0 )
        {
          v32 = strnlen(v24, 0x12Cu);
          if ( v32 == -1 )
            goto LABEL_360;
          if ( v32 > 0x12B )
            goto LABEL_342;
          if ( v32 >= 0x128 )
            v111 = 299;
          else
            v111 = v32 + 4;
          if ( v32 >= 0x128 )
            v112 = 299 - v32;
          else
            v112 = 4;
          v113 = " DBS";
          goto LABEL_341;
        }
        if ( (policy_mgr_is_current_hwmode_sbs(v1) & 1) != 0 )
        {
          v32 = strnlen(v24, 0x12Cu);
          if ( v32 == -1 )
            goto LABEL_360;
          if ( v32 > 0x12B )
            goto LABEL_342;
          if ( v32 >= 0x128 )
            v111 = 299;
          else
            v111 = v32 + 4;
          if ( v32 >= 0x128 )
            v112 = 299 - v32;
          else
            v112 = 4;
          v113 = " SBS";
          goto LABEL_341;
        }
        v32 = strnlen(v24, 0x12Cu);
        if ( v27 > 1u )
        {
          if ( v32 == -1 )
            goto LABEL_360;
          if ( v32 > 0x12B )
            goto LABEL_342;
          if ( v32 >= 0x128 )
            v111 = 299;
          else
            v111 = v32 + 4;
          if ( v32 >= 0x128 )
            v112 = 299 - v32;
          else
            v112 = 4;
          v113 = " SMM";
          goto LABEL_341;
        }
LABEL_332:
        if ( v32 == -1 )
          goto LABEL_360;
        if ( v32 > 0x12B )
          goto LABEL_342;
        if ( v32 >= 0x128 )
          v111 = 299;
        else
          v111 = v32 + 4;
        if ( v32 >= 0x128 )
          v112 = 299 - v32;
        else
          v112 = 4;
        v113 = " MCC";
LABEL_341:
        memcpy((void *)&v24[v32], v113, v112);
        v24[v111] = 0;
        goto LABEL_342;
      }
      v32 = strnlen(v24, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_360;
      if ( v32 <= 0x12B )
      {
        if ( v32 >= 0x128 )
          v62 = 299;
        else
          v62 = v32 + 4;
        if ( v32 >= 0x128 )
          v63 = 299 - v32;
        else
          v63 = 4;
        v64 = " MCC";
        goto LABEL_186;
      }
    }
    if ( (policy_mgr_is_current_hwmode_dbs(v1) & 1) == 0 )
      goto LABEL_342;
    v32 = strnlen(v24, 0x12Cu);
    if ( v32 == -1 )
      goto LABEL_360;
    if ( v32 > 0x12B )
      goto LABEL_342;
    if ( v32 >= 0x126 )
      v111 = 299;
    else
      v111 = v32 + 6;
    if ( v32 >= 0x126 )
      v112 = 299 - v32;
    else
      v112 = 6;
    v113 = " (DBS)";
    goto LABEL_341;
  }
  v25 = v15;
  v143 = v11;
  qdf_mutex_acquire(v15 + 56);
  v142 = v25;
  policy_mgr_get_ml_sta_info(v25, v154, v153, &v155, v157, 0, 0, 0);
  v26 = (unsigned __int8)v154[0];
  v160 = 0;
  memset(v161, 0, sizeof(v161));
  v27 = v154[0] - v153[0];
  *(_QWORD *)string = 0;
  if ( v154[0] )
  {
    v28 = 0;
    v164 = 0;
    v165 = 0;
    v148 = (unsigned __int8)(v154[0] - v153[0]) + 2LL;
    v150 = (unsigned __int8)(v154[0] - v153[0]) + 1LL;
    v151 = v150 + (unsigned __int8)(v153[0] - 1);
    v146 = (unsigned __int8)(v154[0] - v153[0]) + 3LL;
    v144 = v1;
    v145 = (unsigned __int8)(v154[0] - v153[0]) | 4LL;
    *(_QWORD *)src = 0;
    v163 = 0;
    while ( v28 != 5 )
    {
      v29 = *((unsigned __int8 *)&v155 + v28);
      if ( (_DWORD)v29 != 255 )
      {
        ml_links_info = mlo_get_ml_links_info(v1, v29, src);
        if ( !(_BYTE)ml_links_info )
          goto LABEL_110;
        v31 = ml_links_info;
        v32 = strnlen(v14, 0x12Cu);
        if ( v32 == -1 )
          goto LABEL_360;
        if ( v32 <= 0x12B )
        {
          if ( v32 >= 0x125 )
            v33 = 299;
          else
            v33 = v32 + 7;
          if ( v32 >= 0x125 )
            v34 = 299 - v32;
          else
            v34 = 7;
          memcpy((void *)&v14[v32], "ML STA(", v34);
          v14[v33] = 0;
        }
        v1 = 0;
        v35 = v28 + 1;
        v36 = 8LL * (unsigned __int8)v31;
        v149 = v28 + 3;
        v147 = v28 | 4;
        v152 = v28 + 2;
        do
        {
          if ( v1 == 32 )
          {
            __break(0x5512u);
LABEL_357:
            v49 = v31 + 1;
            goto LABEL_361;
          }
          v37 = (unsigned __int8)src[v1];
          if ( v1 )
          {
            v32 = strnlen(v14, 0x12Cu);
            if ( v32 == -1 )
              goto LABEL_360;
            if ( v32 <= 0x12B )
            {
              if ( v32 >= 0x129 )
                v38 = 299;
              else
                v38 = v32 + 3;
              if ( v32 >= 0x129 )
                v39 = 299 - v32;
              else
                v39 = 3;
              memcpy((void *)&v24[v32], " + ", v39);
              v24[v38] = 0;
              v14 = v24;
            }
          }
          if ( (unsigned int)v26 <= v27 )
          {
            v40 = "A";
          }
          else
          {
            v40 = "A";
            if ( v37 != 255 )
            {
              if ( v27 > 4u )
                goto LABEL_363;
              if ( *((unsigned __int8 *)&v155 + v27) == v37 )
              {
                v41 = 1;
              }
              else
              {
                v42 = v151;
                if ( (_DWORD)v26 != (unsigned __int8)v150 )
                {
                  if ( v27 == 4 )
                    goto LABEL_363;
                  v42 = v151;
                  if ( *((unsigned __int8 *)&v155 + v150) == v37 )
                  {
                    v42 = v27 + 1LL;
                  }
                  else if ( (_DWORD)v26 != (unsigned __int8)v148 )
                  {
                    if ( v27 == 3 )
                      goto LABEL_363;
                    v42 = v151;
                    if ( *((unsigned __int8 *)&v155 + v148) == v37 )
                    {
                      v42 = v27 + 2LL;
                    }
                    else if ( (_DWORD)v26 != (unsigned __int8)v146 )
                    {
                      if ( v27 == 2 || v27 > 2u )
                        goto LABEL_363;
                      v42 = v151;
                      if ( *((unsigned __int8 *)&v155 + v146) == v37 )
                      {
                        v42 = v27 + 3LL;
                      }
                      else if ( (_DWORD)v26 != (_DWORD)v145 )
                      {
                        if ( v27 == 1 || v27 == 2 )
                          goto LABEL_363;
                        v42 = v151;
                        if ( *((unsigned __int8 *)&v155 + v145) == v37 )
                        {
                          v42 = v27 | 4LL;
                        }
                        else if ( (_DWORD)v26 != (unsigned __int8)(v27 + 5) )
                        {
                          goto LABEL_363;
                        }
                      }
                    }
                  }
                }
                v41 = v42 < v26;
              }
              v43 = !v41;
              v40 = "A";
              if ( !v43 )
                v40 = (const char *)&unk_A088AB;
            }
          }
          if ( v1 + 4 > 0x20 )
            goto LABEL_363;
          v44 = v37 == 255 ? "S" : v40;
          scnprintf(string, 30, "vdev %d freq %d(%s)", v37, *(_DWORD *)&src[v1 + 4], v44);
          if ( v37 != 255 )
          {
            if ( v28 > 5 )
              goto LABEL_363;
            if ( *((unsigned __int8 *)&v155 + v28) == v37 )
              *((_BYTE *)&v155 + v28) = -1;
            if ( v35 < v26 )
            {
              if ( v28 == 4 )
                goto LABEL_363;
              if ( *((unsigned __int8 *)&v155 + v35) == v37 )
                *((_BYTE *)&v155 + v35) = -1;
              if ( v152 < v26 )
              {
                if ( v28 == 3 )
                  goto LABEL_363;
                if ( *((unsigned __int8 *)&v155 + v152) == v37 )
                  *((_BYTE *)&v155 + v152) = -1;
                if ( v149 < v26 )
                {
                  if ( v28 == 2 )
                    goto LABEL_363;
                  if ( *((unsigned __int8 *)&v155 + v149) == v37 )
                    *((_BYTE *)&v155 + v149) = -1;
                  if ( v147 < v26 )
                  {
                    if ( v28 == 1 || v147 > 5 )
                      goto LABEL_363;
                    if ( *((unsigned __int8 *)&v155 + v147) == v37 )
                      *((_BYTE *)&v155 + v147) = -1;
                    if ( v28 + 5 < v26 )
                      goto LABEL_363;
                  }
                }
              }
            }
          }
          v31 = strnlen(v14, 0x12Cu);
          if ( v31 == -1 )
            goto LABEL_357;
          v45 = strnlen(string, 0x1Eu);
          if ( v45 >= 0x1F )
            goto LABEL_359;
          if ( v45 == 30 )
          {
            v45 = _fortify_panic(4, 30, 31);
LABEL_359:
            v32 = _fortify_panic(2, 30, v45 + 1);
LABEL_360:
            v49 = v32 + 1;
LABEL_361:
            _fortify_panic(2, -1, v49);
          }
          if ( v31 <= 0x12B )
          {
            if ( v45 + v31 >= 0x12C )
              v46 = 299 - v31;
            else
              v46 = v45;
            if ( v45 + v31 >= 0x12C )
              v47 = 299;
            else
              v47 = v45 + v31;
            memcpy((void *)&v24[v31], string, v46);
            v24[v47] = 0;
            v14 = v24;
          }
          v1 += 8LL;
        }
        while ( v36 != v1 );
        v48 = strnlen(v14, 0x12Cu);
        v49 = v48 + 1;
        if ( v48 == -1 )
          goto LABEL_361;
        v1 = v144;
        if ( v48 <= 0x12B )
        {
          if ( v48 == 299 )
            v50 = 299;
          else
            v50 = v48 + 1;
          if ( v50 == -1 )
            goto LABEL_362;
          v43 = v48 == 299;
          v51 = (char *)&v14[v48];
          v52 = !v43;
          memcpy(v51, ")", v52);
          v14[v50] = 0;
        }
      }
      if ( ++v28 == v26 )
        goto LABEL_110;
    }
    goto LABEL_363;
  }
LABEL_110:
  v11 = v143;
  if ( v27 )
  {
    if ( !(_DWORD)pm_conc_connection_list )
    {
      v74 = qword_8D4F00;
      v75 = ((__int64 (__fastcall *)(size_t, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              v1,
              (unsigned int)qword_8D4F00,
              24);
      if ( v75 )
      {
        v84 = v75;
        is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v75, v76, v77, v78, v79, v80, v81, v82, v83);
        wlan_objmgr_vdev_release_ref(v84, 0x18u, v86, v87, v88, v89, v90, v91, v92, v93, v94);
        if ( (is_mlo_vdev & 1) != 0 )
          goto LABEL_135;
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: invalid vdev for id %d",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "policy_mgr_is_ml_vdev",
          v74);
      }
    }
    v53 = strnlen(v24, 0x12Cu);
    v49 = v53 + 1;
    if ( v53 == -1 )
      goto LABEL_361;
    if ( v53 <= 0x12B )
    {
      if ( v53 == 299 )
        v50 = 299;
      else
        v50 = v53 + 1;
      if ( v50 == -1 )
      {
LABEL_362:
        _fortify_panic(9, -1, v50 + 1);
LABEL_363:
        __break(1u);
        goto LABEL_364;
      }
      memcpy((void *)&v24[v53], "+", v53 != 299);
      v24[v50] = 0;
    }
  }
LABEL_135:
  qdf_mutex_release(v142 + 56);
  if ( v13 <= 2 )
    goto LABEL_120;
LABEL_136:
  if ( v13 == 3 )
  {
    policy_mgr_dump_current_concurrency_three_connection(v1, v24);
    qdf_mutex_acquire((__int64)(v11 + 7));
    if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F0C)
      && HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F30) )
    {
      qdf_mutex_release((__int64)(v11 + 7));
      v32 = strnlen(v24, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_360;
      if ( v32 > 0x12B )
        goto LABEL_343;
      if ( v32 >= 0x128 )
        v107 = 299;
      else
        v107 = v32 + 4;
      if ( v32 >= 0x128 )
        v108 = 299 - v32;
      else
        v108 = 4;
      v109 = " SCC";
    }
    else
    {
      v110 = policy_mgr_are_3_freq_on_same_mac(v1);
      qdf_mutex_release((__int64)(v11 + 7));
      if ( (v110 & 1) != 0 )
      {
        v32 = strnlen(v24, 0x12Cu);
        if ( v27 > 1u )
        {
          if ( v32 == -1 )
            goto LABEL_360;
          if ( v32 > 0x12B )
            goto LABEL_343;
          if ( v32 >= 0x11E )
            v107 = 299;
          else
            v107 = v32 + 14;
          if ( v32 >= 0x11E )
            v108 = 299 - v32;
          else
            v108 = 14;
          v109 = " on single MAC";
        }
        else
        {
          if ( v32 == -1 )
            goto LABEL_360;
          if ( v32 > 0x12B )
            goto LABEL_343;
          if ( v32 >= 0x11A )
            v107 = 299;
          else
            v107 = v32 + 18;
          if ( v32 >= 0x11A )
            v108 = 299 - v32;
          else
            v108 = 18;
          v109 = " MCC on single MAC";
        }
      }
      else
      {
        if ( (policy_mgr_is_current_hwmode_dbs(v1) & 1) != 0 )
        {
          policy_mgr_dump_dbs_concurrency(v1, v24);
          goto LABEL_343;
        }
        if ( (policy_mgr_is_current_hwmode_sbs(v1) & 1) != 0 )
        {
          policy_mgr_dump_sbs_concurrency(v1, v24);
          goto LABEL_343;
        }
        v32 = strnlen(v24, 0x12Cu);
        if ( v27 > 1u )
        {
          if ( v32 == -1 )
            goto LABEL_360;
          if ( v32 > 0x12B )
            goto LABEL_343;
          if ( v32 >= 0x128 )
            v107 = 299;
          else
            v107 = v32 + 4;
          if ( v32 >= 0x128 )
            v108 = 299 - v32;
          else
            v108 = 4;
          v109 = " SMM";
        }
        else
        {
          if ( v32 == -1 )
            goto LABEL_360;
          if ( v32 > 0x12B )
            goto LABEL_343;
          if ( v32 >= 0x128 )
            v107 = 299;
          else
            v107 = v32 + 4;
          if ( v32 >= 0x128 )
            v108 = 299 - v32;
          else
            v108 = 4;
          v109 = " MCC";
        }
      }
    }
    memcpy((void *)&v24[v32], v109, v108);
    v24[v107] = 0;
LABEL_343:
    v73 = "%s: %s";
    goto LABEL_344;
  }
  if ( v13 == 4 )
  {
    qdf_mutex_acquire((__int64)(v11 + 7));
    ((void (__fastcall *)(_QWORD, const char *))policy_mgr_dump_current_concurrency_4_connection)(*v11, v24);
LABEL_327:
    is_current_hwmode_dbs = policy_mgr_is_current_hwmode_dbs(*v11);
    v139 = *v11;
    if ( (is_current_hwmode_dbs & 1) != 0 )
    {
      policy_mgr_dump_dbs_concurrency(v139, v24);
LABEL_342:
      qdf_mutex_release((__int64)(v11 + 7));
      goto LABEL_343;
    }
    if ( (policy_mgr_is_current_hwmode_sbs(v139) & 1) != 0 )
    {
      policy_mgr_dump_sbs_concurrency(*v11, v24);
      goto LABEL_342;
    }
    v32 = strnlen(v24, 0x12Cu);
    goto LABEL_332;
  }
  if ( v13 != 5 )
  {
LABEL_164:
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: unexpected num_connections value %d",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "policy_mgr_dump_current_concurrency",
      (unsigned int)v13);
LABEL_345:
    result = _qdf_mem_free((__int64)v24);
    goto LABEL_346;
  }
  qdf_mutex_acquire((__int64)(v11 + 7));
  v95 = qword_8D4F78;
  LOBYTE(v163) = 0;
  *(_QWORD *)src = 0;
  v96 = scnprintf(src, 9, "(vdev %d)", qword_8D4F90);
  if ( v95 <= 2 )
  {
    if ( v95 )
    {
      if ( v95 == 1 )
      {
        ((void (__fastcall *)(_QWORD, const char *, double))policy_mgr_dump_current_concurrency_4_connection)(
          *v11,
          v24,
          v96);
        v32 = strnlen(v24, 0x12Cu);
        if ( v32 == -1 )
          goto LABEL_360;
        if ( v32 <= 0x12B )
        {
          if ( v32 >= 0x128 )
            v104 = 299;
          else
            v104 = v32 + 4;
          if ( v32 >= 0x128 )
            v105 = 299 - v32;
          else
            v105 = 4;
          v106 = "+SAP";
          goto LABEL_315;
        }
        goto LABEL_316;
      }
      if ( v95 == 2 )
      {
        ((void (__fastcall *)(_QWORD, const char *, double))policy_mgr_dump_current_concurrency_4_connection)(
          *v11,
          v24,
          v96);
        v32 = strnlen(v24, 0x12Cu);
        if ( v32 == -1 )
          goto LABEL_360;
        if ( v32 <= 0x12B )
        {
          if ( v32 >= 0x124 )
            v104 = 299;
          else
            v104 = v32 + 8;
          if ( v32 >= 0x124 )
            v105 = 299 - v32;
          else
            v105 = 8;
          v106 = "+P2P CLI";
          goto LABEL_315;
        }
        goto LABEL_316;
      }
      goto LABEL_247;
    }
    ((void (__fastcall *)(_QWORD, const char *, double))policy_mgr_dump_current_concurrency_4_connection)(
      *v11,
      v24,
      v96);
    v114 = qword_8D4F90;
    v115 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             *v11,
             (unsigned int)qword_8D4F90,
             24);
    if ( v115 )
    {
      v124 = v115;
      v125 = wlan_vdev_mlme_is_mlo_vdev(v115, v116, v117, v118, v119, v120, v121, v122, v123);
      wlan_objmgr_vdev_release_ref(v124, 0x18u, v126, v127, v128, v129, v130, v131, v132, v133, v134);
      if ( (v125 & 1) != 0 )
        goto LABEL_327;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: invalid vdev for id %d",
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        "policy_mgr_is_ml_vdev",
        v114);
    }
    v32 = strnlen(v24, 0x12Cu);
    if ( v32 == -1 )
      goto LABEL_360;
    if ( v32 <= 0x12B )
    {
      if ( v32 >= 0x128 )
        v104 = 299;
      else
        v104 = v32 + 4;
      if ( v32 >= 0x128 )
        v105 = 299 - v32;
      else
        v105 = 4;
      v106 = "+STA";
      goto LABEL_315;
    }
    goto LABEL_316;
  }
  if ( v95 > 4 )
  {
    if ( v95 == 5 )
    {
      ((void (__fastcall *)(_QWORD, const char *, double))policy_mgr_dump_current_concurrency_4_connection)(
        *v11,
        v24,
        v96);
      v32 = strnlen(v24, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_360;
      if ( v32 <= 0x12B )
      {
        if ( v32 >= 0x123 )
          v104 = 299;
        else
          v104 = v32 + 9;
        if ( v32 >= 0x123 )
          v105 = 299 - v32;
        else
          v105 = 9;
        v106 = "+NAN Disc";
        goto LABEL_315;
      }
      goto LABEL_316;
    }
    if ( v95 == 6 )
    {
      ((void (__fastcall *)(_QWORD, const char *, double))policy_mgr_dump_current_concurrency_4_connection)(
        *v11,
        v24,
        v96);
      v32 = strnlen(v24, 0x12Cu);
      if ( v32 == -1 )
        goto LABEL_360;
      if ( v32 <= 0x12B )
      {
        if ( v32 >= 0x125 )
          v104 = 299;
        else
          v104 = v32 + 7;
        if ( v32 >= 0x125 )
          v105 = 299 - v32;
        else
          v105 = 7;
        v106 = "+LT_SAP";
        goto LABEL_315;
      }
      goto LABEL_316;
    }
LABEL_247:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: unexpected mode %d",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "policy_mgr_dump_current_concurrency_5_connection",
      (unsigned int)v95);
    goto LABEL_316;
  }
  if ( v95 == 3 )
  {
    ((void (__fastcall *)(_QWORD, const char *, double))policy_mgr_dump_current_concurrency_4_connection)(
      *v11,
      v24,
      v96);
    v32 = strnlen(v24, 0x12Cu);
    if ( v32 == -1 )
      goto LABEL_360;
    if ( v32 <= 0x12B )
    {
      if ( v32 >= 0x125 )
        v104 = 299;
      else
        v104 = v32 + 7;
      if ( v32 >= 0x125 )
        v105 = 299 - v32;
      else
        v105 = 7;
      v106 = "+P2P GO";
      goto LABEL_315;
    }
  }
  else
  {
    ((void (__fastcall *)(_QWORD, const char *, double))policy_mgr_dump_current_concurrency_4_connection)(
      *v11,
      v24,
      v96);
    v32 = strnlen(v24, 0x12Cu);
    if ( v32 == -1 )
      goto LABEL_360;
    if ( v32 <= 0x12B )
    {
      if ( v32 >= 0x128 )
        v104 = 299;
      else
        v104 = v32 + 4;
      if ( v32 >= 0x128 )
        v105 = 299 - v32;
      else
        v105 = 4;
      v106 = "+NDI";
LABEL_315:
      memcpy((void *)&v24[v32], v106, v105);
      v24[v104] = 0;
    }
  }
LABEL_316:
  v1 = strnlen(v24, 0x12Cu);
  if ( v1 == -1 )
  {
LABEL_364:
    v49 = v1 + 1;
    goto LABEL_361;
  }
  v135 = strnlen(src, 9u);
  if ( v135 >= 0xA )
  {
    v135 = _fortify_panic(2, 9, v135 + 1);
  }
  else if ( v135 != 9 )
  {
    if ( v1 <= 0x12B )
    {
      if ( v135 + v1 >= 0x12C )
        v136 = 299 - v1;
      else
        v136 = v135;
      if ( v135 + v1 >= 0x12C )
        v137 = 299;
      else
        v137 = v135 + v1;
      memcpy((void *)&v24[v1], src, v136);
      v24[v137] = 0;
    }
    goto LABEL_327;
  }
  v140 = _fortify_panic(4, 9, v135 + 1);
  return policy_mgr_dump_current_concurrency_one_connection(v140, v141);
}
