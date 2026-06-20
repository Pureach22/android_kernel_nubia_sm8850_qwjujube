__int64 __fastcall cam_vfe_bus_process_cmd(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned __int64 v5; // x9
  _DWORD *v6; // x11
  int v7; // w0
  const char *v8; // x5
  __int64 v9; // x0
  const char *v10; // x3
  __int64 v11; // x4
  __int64 result; // x0
  __int64 v13; // x21
  __int64 v14; // x25
  __int64 v15; // x26
  _DWORD *v16; // x28
  __int64 v17; // x27
  __int64 v18; // x6
  __int64 v19; // x19
  unsigned int *v20; // x24
  unsigned int v21; // w8
  __int64 v22; // x9
  _DWORD *v23; // x9
  char v24; // w9
  _DWORD *v25; // x9
  char v26; // w9
  _DWORD *v27; // x9
  char v28; // w9
  _DWORD *v29; // x9
  char v30; // w9
  __int64 v31; // x13
  int v32; // w14
  int v33; // w14
  int v34; // w14
  int v35; // w14
  int v36; // w14
  int v37; // w14
  int v38; // w14
  int v39; // w14
  int v40; // w14
  int v41; // w14
  __int64 v42; // x10
  __int64 v43; // x8
  int v44; // w7
  int v45; // w6
  __int64 v46; // x9
  __int64 v47; // x20
  unsigned int v48; // w25
  __int64 v49; // x28
  __int64 v50; // x8
  __int64 v51; // x20
  unsigned int v52; // w8
  _DWORD *v53; // x9
  unsigned int v54; // w21
  _DWORD *v55; // x10
  _DWORD *v56; // x12
  int v57; // w8
  int v58; // w9
  int v59; // w11
  char v60; // w10
  _DWORD *v61; // x11
  _DWORD *v62; // x12
  char v63; // w10
  int v64; // w8
  int v65; // w9
  int v66; // w11
  int *v67; // x20
  __int64 v68; // x8
  __int64 v69; // x9
  _DWORD *v70; // x10
  int v71; // w6
  __int64 v72; // x8
  _DWORD *v73; // x10
  unsigned __int64 v74; // x9
  __int64 v75; // x14
  __int64 v76; // x15
  int v77; // w15
  int v78; // w15
  int v79; // w15
  int v80; // w15
  int v81; // w15
  int v82; // w15
  int v83; // w15
  int v84; // w15
  __int64 v85; // x19
  unsigned int v86; // w0
  int v88; // w0
  const char *v89; // x5
  __int64 v90; // x0
  const char *v91; // x3
  __int64 v92; // x4
  __int64 v93; // x6
  __int64 v94; // x24
  unsigned int *v95; // x21
  int v96; // w8
  __int64 v97; // x1
  _DWORD *v98; // x23
  int v99; // w25
  int v100; // w6
  unsigned int v101; // w27
  __int64 v102; // x22
  char v103; // w8
  __int64 v104; // x22
  __int64 v105; // x27
  unsigned int cpas_hw_version; // w0
  __int64 v107; // x6
  __int64 v108; // x4
  const char *v109; // x5
  int v110; // w24
  _QWORD *v111; // x8
  __int64 v112; // x27
  __int64 v113; // x24
  int v114; // w0
  int v115; // w8
  int v116; // w9
  int v117; // w11
  int v118; // w24
  int v119; // w8
  __int64 v120; // x8
  __int64 v121; // x9
  __int64 v122; // x22
  _DWORD *v123; // x13
  unsigned int v124; // w9
  unsigned int v125; // w8
  int v126; // w8
  __int64 v127; // x8
  __int64 v128; // x9
  _DWORD *v129; // x24
  __int64 v130; // x22
  unsigned int v131; // w9
  unsigned int v132; // w8
  __int64 v133; // x8
  char v134; // w9
  unsigned int v135; // w8
  unsigned int v136; // w22
  __int64 v137; // x6
  __int64 v138; // x1
  const char *v139; // x3
  __int64 v140; // x4
  __int64 v141; // x8
  char v142; // w9
  unsigned int v143; // w9
  int v144; // w7
  __int64 v145; // x22
  __int64 v146; // x22
  __int64 v147; // x22
  unsigned int v148; // w8
  int v149; // w27
  int v150; // w22
  _QWORD *v151; // x8
  unsigned int v152; // w9
  char v153; // w8
  unsigned int v154; // w8
  __int64 v155; // x4
  __int64 v156; // x23
  int v157; // w8
  char v158; // w8
  __int64 v159; // x22
  __int64 v160; // x22
  __int64 v161; // x22
  _DWORD *v162; // x22
  _DWORD *v163; // x22
  _DWORD *v164; // x22
  _DWORD *v165; // x22
  _DWORD *v166; // x22
  _DWORD *v167; // x22
  const char *v168; // x3
  __int64 v169; // x4
  __int64 v170; // x6
  const char *v171; // x3
  __int64 v172; // x1
  __int64 v173; // x4
  unsigned int v174; // w20
  __int64 (__fastcall *v175)(_QWORD); // x8
  __int64 v176; // x21
  int v177; // w0
  __int64 v178; // x8
  unsigned int v179; // w6
  int v180; // w21
  const char *v181; // x3
  __int64 v182; // x4
  __int64 v183; // x21
  __int64 (__fastcall *v184)(_QWORD); // x8
  int v185; // w0
  unsigned int v186; // w6
  void (__fastcall *v187)(__int64, __int64, __int64); // x9
  __int64 v188; // x0
  __int64 v189; // x1
  __int64 v190; // x20
  __int64 v191; // x20
  __int64 v192; // x23
  __int64 v193; // [xsp+18h] [xbp-A8h]
  __int64 v194; // [xsp+18h] [xbp-A8h]
  __int64 v195; // [xsp+18h] [xbp-A8h]
  __int64 v196; // [xsp+18h] [xbp-A8h]
  __int64 v197; // [xsp+18h] [xbp-A8h]
  __int64 v198; // [xsp+18h] [xbp-A8h]
  _DWORD *v199; // [xsp+18h] [xbp-A8h]
  _DWORD *v200; // [xsp+18h] [xbp-A8h]
  __int64 v201; // [xsp+20h] [xbp-A0h]
  __int64 v202; // [xsp+28h] [xbp-98h]
  __int64 v203; // [xsp+30h] [xbp-90h]
  __int64 v204; // [xsp+38h] [xbp-88h]
  __int64 v205; // [xsp+40h] [xbp-80h]
  __int64 v206; // [xsp+48h] [xbp-78h]
  __int64 v207; // [xsp+50h] [xbp-70h]
  __int64 v208; // [xsp+58h] [xbp-68h]
  __int64 v209; // [xsp+60h] [xbp-60h]
  __int64 v210; // [xsp+68h] [xbp-58h]
  __int64 v211; // [xsp+70h] [xbp-50h]
  __int64 v212; // [xsp+78h] [xbp-48h]
  __int64 v213; // [xsp+80h] [xbp-40h]
  __int64 v214; // [xsp+88h] [xbp-38h]
  __int64 v215; // [xsp+90h] [xbp-30h]
  __int64 v216; // [xsp+98h] [xbp-28h]
  unsigned int v217; // [xsp+A0h] [xbp-20h]
  unsigned int v218; // [xsp+A0h] [xbp-20h]
  unsigned int v219; // [xsp+A0h] [xbp-20h]
  unsigned int v220; // [xsp+A0h] [xbp-20h]
  __int64 v221; // [xsp+A0h] [xbp-20h]
  int v222; // [xsp+ACh] [xbp-14h] BYREF
  __int64 v223; // [xsp+B0h] [xbp-10h]

  v223 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v7 = __ratelimit(&cam_vfe_bus_process_cmd__rs, "cam_vfe_bus_process_cmd");
    v8 = "Invalid input arguments";
    if ( v7 )
      v9 = 3;
    else
      v9 = 2;
    v10 = "cam_vfe_bus_process_cmd";
    v11 = 3758;
    goto LABEL_16;
  }
  v3 = a1 + 39108;
  if ( a2 > 15 )
  {
    if ( a2 <= 34 )
    {
      if ( a2 != 16 )
      {
        if ( a2 == 17 )
        {
          result = cam_vfe_bus_dump_wm_data(a1, a3);
          goto LABEL_18;
        }
        if ( a2 == 24 )
        {
          v4 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
          if ( v4 && *(_QWORD *)(v4 + 88) )
          {
            if ( *(_DWORD *)(v4 + 16) )
            {
              v5 = 0;
              v6 = (_DWORD *)(*(_QWORD *)(a3 + 40) + 36LL);
              while ( v5 != 2 )
              {
                v31 = *(_QWORD *)(*(_QWORD *)(v4 + 24 + 8 * v5) + 24LL);
                if ( !*(_QWORD *)(*(_QWORD *)(v31 + 16) + 72LL) )
                {
                  v10 = "cam_vfe_bus_update_ubwc_config_v2";
                  v8 = "No UBWC register to configure.";
                  v9 = 3;
                  v11 = 3380;
                  goto LABEL_16;
                }
                if ( !*(_DWORD *)(v31 + 56) )
                {
                  v10 = "cam_vfe_bus_update_ubwc_config_v2";
                  v8 = "UBWC Disabled";
                  v9 = 3;
                  v11 = 3386;
                  goto LABEL_16;
                }
                v32 = *(v6 - 4);
                if ( *(_DWORD *)(v31 + 64) != v32 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 64) = v32;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                if ( !*(_DWORD *)(v31 + 116) )
                {
                  v33 = *(v6 - 1);
                  if ( *(_DWORD *)(v31 + 68) != v33 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                  {
                    *(_DWORD *)(v31 + 68) = v33;
                    *(_BYTE *)(v31 + 60) = 1;
                  }
                  if ( *(_DWORD *)(v31 + 72) != *v6 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                  {
                    *(_DWORD *)(v31 + 72) = *v6;
                    *(_BYTE *)(v31 + 60) = 1;
                  }
                }
                v34 = v6[1];
                if ( *(_DWORD *)(v31 + 76) != v34 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 76) = v34;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                v35 = *(v6 - 7);
                if ( *(_DWORD *)(v31 + 80) != v35 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 80) = v35;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                v36 = *(v6 - 3);
                if ( *(_DWORD *)(v31 + 84) != v36 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 84) = v36;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                v37 = *(v6 - 2);
                if ( *(_DWORD *)(v31 + 88) != v37 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 88) = v37;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                v38 = *(v6 - 5);
                if ( *(_DWORD *)(v31 + 92) != v38 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 92) = v38;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                v39 = v6[5];
                if ( *(_DWORD *)(v31 + 120) != v39 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 120) = v39;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                v40 = v6[6];
                if ( *(_DWORD *)(v31 + 124) != v40 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 124) = v40;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                v41 = v6[8];
                if ( *(_DWORD *)(v31 + 128) != v41 || (*(_BYTE *)(v31 + 24) & 1) == 0 )
                {
                  *(_DWORD *)(v31 + 128) = v41;
                  *(_BYTE *)(v31 + 60) = 1;
                }
                ++v5;
                result = 0;
                v6 += 18;
                if ( v5 >= *(unsigned int *)(v4 + 16) )
                  goto LABEL_18;
              }
              goto LABEL_386;
            }
            goto LABEL_180;
          }
          v10 = "cam_vfe_bus_update_ubwc_config_v2";
          v8 = "Invalid data";
          v9 = 3;
          v11 = 3365;
          goto LABEL_16;
        }
LABEL_175:
        v88 = __ratelimit(&cam_vfe_bus_process_cmd__rs_74, "cam_vfe_bus_process_cmd");
        v89 = "Invalid camif process command:%d";
        if ( v88 )
          v90 = 3;
        else
          v90 = 2;
        v91 = "cam_vfe_bus_process_cmd";
        v92 = 3816;
        v93 = (unsigned int)a2;
LABEL_179:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          v90,
          8,
          1,
          v91,
          v92,
          v89,
          v93);
        goto LABEL_17;
      }
      v72 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( v72 && *(_QWORD *)(v72 + 88) )
      {
        if ( *(_DWORD *)(v72 + 16) )
        {
          v73 = *(_DWORD **)(a3 + 40);
          v74 = 0;
          while ( v74 != 2 )
          {
            v75 = *(_QWORD *)(*(_QWORD *)(v72 + 24 + 8 * v74) + 24LL);
            if ( v74 == 1 )
              v76 = 40;
            else
              v76 = 0;
            if ( !*(_QWORD *)(*(_QWORD *)(v75 + 16) + 72LL) )
            {
              v10 = "cam_vfe_bus_update_ubwc_config";
              v8 = "No UBWC register to configure.";
              v9 = 3;
              v11 = 3270;
              goto LABEL_16;
            }
            if ( !*(_DWORD *)(v75 + 56) )
            {
              v10 = "cam_vfe_bus_update_ubwc_config";
              v8 = "UBWC Disabled";
              v9 = 3;
              v11 = 3276;
              goto LABEL_16;
            }
            v73 = (_DWORD *)((char *)v73 + v76);
            v77 = v73[4];
            if ( *(_DWORD *)(v75 + 64) != v77 || (*(_BYTE *)(v75 + 24) & 1) == 0 )
            {
              *(_DWORD *)(v75 + 64) = v77;
              *(_BYTE *)(v75 + 60) = 1;
            }
            if ( !*(_DWORD *)(v75 + 116) )
            {
              v78 = v73[7];
              if ( *(_DWORD *)(v75 + 68) != v78 || (*(_BYTE *)(v75 + 24) & 1) == 0 )
              {
                *(_DWORD *)(v75 + 68) = v78;
                *(_BYTE *)(v75 + 60) = 1;
              }
              v79 = v73[8];
              if ( *(_DWORD *)(v75 + 72) != v79 || (*(_BYTE *)(v75 + 24) & 1) == 0 )
              {
                *(_DWORD *)(v75 + 72) = v79;
                *(_BYTE *)(v75 + 60) = 1;
              }
            }
            v80 = v73[9];
            if ( *(_DWORD *)(v75 + 76) != v80 || (*(_BYTE *)(v75 + 24) & 1) == 0 )
            {
              *(_DWORD *)(v75 + 76) = v80;
              *(_BYTE *)(v75 + 60) = 1;
            }
            v81 = v73[1];
            if ( *(_DWORD *)(v75 + 80) != v81 || (*(_BYTE *)(v75 + 24) & 1) == 0 )
            {
              *(_DWORD *)(v75 + 80) = v81;
              *(_BYTE *)(v75 + 60) = 1;
            }
            v82 = v73[5];
            if ( *(_DWORD *)(v75 + 84) != v82 || (*(_BYTE *)(v75 + 24) & 1) == 0 )
            {
              *(_DWORD *)(v75 + 84) = v82;
              *(_BYTE *)(v75 + 60) = 1;
            }
            v83 = v73[6];
            if ( *(_DWORD *)(v75 + 88) != v83 || (*(_BYTE *)(v75 + 24) & 1) == 0 )
            {
              *(_DWORD *)(v75 + 88) = v83;
              *(_BYTE *)(v75 + 60) = 1;
            }
            v84 = v73[3];
            if ( *(_DWORD *)(v75 + 92) != v84 || (*(_BYTE *)(v75 + 24) & 1) == 0 )
            {
              *(_DWORD *)(v75 + 92) = v84;
              *(_BYTE *)(v75 + 60) = 1;
            }
            ++v74;
            result = 0;
            if ( v74 >= *(unsigned int *)(v72 + 16) )
              goto LABEL_18;
          }
          goto LABEL_386;
        }
        goto LABEL_180;
      }
      v10 = "cam_vfe_bus_update_ubwc_config";
      v8 = "Invalid data";
      v9 = 3;
      v11 = 3255;
LABEL_16:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        v9,
        8,
        1,
        v10,
        v11,
        v8);
      goto LABEL_17;
    }
    v13 = a1 + 33609;
    if ( a2 == 35 )
    {
      v85 = a1;
      v86 = cam_io_r_mb(*(_QWORD *)(a1 + 8) + *(unsigned int *)(*(_QWORD *)(a1 + 40) + 92LL));
      cam_io_w_mb(
        (1 << *(_DWORD *)(v13 + 15)) | v86,
        *(_QWORD *)(v85 + 8) + *(unsigned int *)(*(_QWORD *)(v85 + 40) + 92LL));
      goto LABEL_17;
    }
    if ( a2 != 38 )
    {
      if ( a2 == 44 )
      {
        *(_DWORD *)a3 = *(_DWORD *)(a1 + 42664);
        *(_BYTE *)(a3 + 29) = *(_BYTE *)v13;
        goto LABEL_17;
      }
      goto LABEL_175;
    }
    v67 = *(int **)(a3 + 40);
    if ( !v67 )
    {
      v10 = "cam_vfe_bus_get_res_for_mid";
      v8 = "invalid get resource for mid paramas";
      v9 = 3;
      v11 = 3715;
      goto LABEL_16;
    }
    v68 = *(unsigned int *)(a1 + 33620);
    if ( (_DWORD)v68 )
    {
      v69 = 0;
      while ( v69 != 23 )
      {
        v70 = *(_DWORD **)(v3 + 20);
        if ( v70 )
        {
          v71 = *v67;
          if ( v70[28] == *v67 || v70[29] == v71 || v70[30] == v71 || v70[31] == v71 )
          {
            if ( (unsigned int)v69 > 0x16 )
              goto LABEL_386;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              3,
              "cam_vfe_bus_get_res_for_mid",
              3742,
              "match mid :%d  out resource:0x%x found",
              v71,
              *(_DWORD *)v3);
            result = 0;
            v67[1] = *(_DWORD *)v3;
            goto LABEL_18;
          }
        }
        ++v69;
        v3 += 152;
        if ( v68 == v69 )
          goto LABEL_353;
      }
      goto LABEL_386;
    }
LABEL_353:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_get_res_for_mid",
      3735,
      "mid:%d does not match with any out resource",
      *v67);
    v67[1] = 0;
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  if ( a2 > 5 )
  {
    if ( a2 == 6 )
    {
      result = 0;
      **(_DWORD **)(a3 + 40) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)a3 + 24LL) + 96LL) == 1;
      goto LABEL_18;
    }
    if ( a2 == 8 )
    {
      v50 = *(_QWORD *)(a3 + 8);
      v51 = *(_QWORD *)(v50 + 24);
      if ( v51 )
      {
        v52 = *(_DWORD *)(v50 + 4);
        if ( v52 >= 0x3000 && v52 < *(_DWORD *)(a1 + 42664) && *(_DWORD *)(v51 + 16) )
        {
          v53 = *(_DWORD **)(a3 + 16);
          v54 = 3 * ((unsigned __int8)v52 + *(_DWORD *)a3 * *v53);
          v55 = &v53[4 * v54];
          v56 = *(_DWORD **)(*(_QWORD *)(v51 + 24) + 24LL);
          v57 = v55[7];
          v56[8] = v57;
          v58 = v55[6];
          v56[7] = v58;
          v59 = v55[8];
          v60 = debug_mdl;
          v56[17] = v59;
          if ( (v60 & 8) != 0 && !debug_priority )
          {
            v192 = a3;
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v60 & 8,
              4,
              "cam_vfe_bus_update_stripe_cfg",
              3519,
              "id:%x wm:%d width:0x%x offset:%x tilecfg:%x",
              *(_DWORD *)(*(_QWORD *)(a3 + 8) + 4LL),
              0,
              v57,
              v58,
              v59);
            a3 = v192;
          }
          if ( *(_DWORD *)(v51 + 16) >= 2u )
          {
            v61 = (_DWORD *)(*(_QWORD *)(a3 + 16) + 16LL * (v54 + 1));
            v62 = *(_DWORD **)(*(_QWORD *)(v51 + 32) + 24LL);
            v63 = debug_mdl;
            v64 = v61[7];
            v62[8] = v64;
            v65 = v61[6];
            v62[7] = v65;
            v66 = v61[8];
            v62[17] = v66;
            if ( (v63 & 8) != 0 && !debug_priority )
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v63 & 8,
                4,
                "cam_vfe_bus_update_stripe_cfg",
                3519,
                "id:%x wm:%d width:0x%x offset:%x tilecfg:%x",
                *(_DWORD *)(*(_QWORD *)(a3 + 8) + 4LL),
                1,
                v64,
                v65,
                v66);
            if ( *(_DWORD *)(v51 + 16) > 2u )
            {
LABEL_386:
              __break(0x5512u);
              return cam_vfe_bus_get_evt_payload();
            }
          }
        }
LABEL_180:
        result = 0;
        goto LABEL_18;
      }
      v10 = "cam_vfe_bus_update_stripe_cfg";
      v8 = "Failed! Invalid data";
      v9 = 3;
      v11 = 3498;
      goto LABEL_16;
    }
    if ( a2 != 14 )
      goto LABEL_175;
    if ( *(_DWORD *)(a1 + 42652) )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v191 = a1;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_process_cmd",
          3778,
          "Mask off bus error irq handler");
        a1 = v191;
      }
      result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a1 + 24));
      *(_DWORD *)(v3 + 3544) = 0;
      goto LABEL_18;
    }
    goto LABEL_17;
  }
  if ( a2 != 1 )
  {
    if ( a2 != 4 )
      goto LABEL_175;
    v14 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
    if ( !v14 || (v15 = *(_QWORD *)(v14 + 88)) == 0 )
    {
      v10 = "cam_vfe_bus_update_hfr";
      v8 = "Failed! Invalid data";
      v9 = 3;
      v11 = 3126;
      goto LABEL_16;
    }
    if ( *(_DWORD *)(v14 + 16) )
    {
      v16 = *(_DWORD **)(a3 + 40);
      v17 = 0;
      v18 = 0;
      v19 = *(_QWORD *)(v14 + 8) + 48LL;
      while ( 1 )
      {
        if ( (unsigned int)v18 >= 0x74 )
        {
          v168 = "cam_vfe_bus_update_hfr";
          v169 = 3139;
          goto LABEL_370;
        }
        if ( v17 == 2 )
          goto LABEL_386;
        v20 = *(unsigned int **)(*(_QWORD *)(v14 + 24 + 8 * v17) + 24LL);
        if ( *v20 <= 2 )
        {
          v21 = v16[2];
          if ( v21 >= 4 )
          {
            v91 = "cam_vfe_bus_update_hfr";
            v89 = "RDI doesn't support irq subsample period %d";
            v90 = 3;
            v92 = 3148;
            v93 = v21;
            goto LABEL_179;
          }
        }
        if ( v20[27] != v16[3] || (*((_BYTE *)v20 + 25) & 1) == 0 )
        {
          v22 = (unsigned int)v18;
          v18 = (unsigned int)(v18 + 2);
          v23 = (_DWORD *)(v19 + 4 * v22);
          *v23 = *(_DWORD *)(*((_QWORD *)v20 + 2) + 56LL);
          v23[1] = v16[3];
          v24 = debug_mdl;
          v20[27] = v16[3];
          if ( (v24 & 8) != 0 && !debug_priority )
          {
            v193 = a3;
            v217 = v18;
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              v24 & 8,
              4,
              "cam_vfe_bus_update_hfr",
              3161,
              "WM %d framedrop pattern 0x%x",
              *v20);
            v18 = v217;
            a3 = v193;
          }
        }
        if ( v20[26] != v16[4] || (*((_BYTE *)v20 + 25) & 1) == 0 )
        {
          v25 = (_DWORD *)(v19 + 4LL * (unsigned int)v18);
          v18 = (unsigned int)(v18 + 2);
          *v25 = *(_DWORD *)(*((_QWORD *)v20 + 2) + 52LL);
          v25[1] = v16[4];
          v26 = debug_mdl;
          v20[26] = v16[4];
          if ( (v26 & 8) != 0 && !debug_priority )
          {
            v194 = a3;
            v218 = v18;
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              v26 & 8,
              4,
              "cam_vfe_bus_update_hfr",
              3172,
              "WM %d framedrop period 0x%x",
              *v20);
            v18 = v218;
            a3 = v194;
          }
        }
        if ( v20[24] != v16[2] || (*((_BYTE *)v20 + 25) & 1) == 0 )
        {
          v27 = (_DWORD *)(v19 + 4LL * (unsigned int)v18);
          v18 = (unsigned int)(v18 + 2);
          *v27 = *(_DWORD *)(*((_QWORD *)v20 + 2) + 44LL);
          v27[1] = v16[2];
          v28 = debug_mdl;
          v20[24] = v16[2];
          if ( (v28 & 8) != 0 && !debug_priority )
          {
            v195 = a3;
            v219 = v18;
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              v28 & 8,
              4,
              "cam_vfe_bus_update_hfr",
              3184,
              "WM %d irq subsample period 0x%x",
              *v20);
            v18 = v219;
            a3 = v195;
          }
        }
        if ( v20[25] != v16[1] || (*((_BYTE *)v20 + 25) & 1) == 0 )
        {
          v29 = (_DWORD *)(v19 + 4LL * (unsigned int)v18);
          v18 = (unsigned int)(v18 + 2);
          *v29 = *(_DWORD *)(*((_QWORD *)v20 + 2) + 48LL);
          v29[1] = v16[1];
          v30 = debug_mdl;
          v20[25] = v16[1];
          if ( (v30 & 8) != 0 && !debug_priority )
            break;
        }
        if ( (*((_BYTE *)v20 + 25) & 1) == 0 )
          goto LABEL_63;
LABEL_38:
        if ( ++v17 >= (unsigned __int64)*(unsigned int *)(v14 + 16) )
        {
          if ( (unsigned int)v18 < 2 )
            goto LABEL_357;
          v174 = (unsigned int)v18 >> 1;
          v175 = *(__int64 (__fastcall **)(_QWORD))(v15 + 24);
          v176 = a3;
          if ( *((_DWORD *)v175 - 1) != 2010610996 )
            __break(0x8228u);
          v177 = v175((unsigned int)v18 >> 1);
          v178 = v176;
          v179 = *(_DWORD *)(v176 + 24);
          v180 = 4 * v177;
          if ( 4 * v177 > v179 )
          {
            v181 = "cam_vfe_bus_update_hfr";
            v182 = 3214;
            goto LABEL_379;
          }
          v187 = *(void (__fastcall **)(__int64, __int64, __int64))(v15 + 120);
LABEL_383:
          v188 = *(_QWORD *)(v178 + 16);
          v189 = v174;
          v190 = v178;
          if ( *((_DWORD *)v187 - 1) != -1401492769 )
            __break(0x8229u);
          v187(v188, v189, v19);
          result = 0;
          *(_DWORD *)(v190 + 28) = v180;
          goto LABEL_18;
        }
      }
      v196 = a3;
      v220 = v18;
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v30 & 8,
        4,
        "cam_vfe_bus_update_hfr",
        3196,
        "WM %d irq subsample pattern 0x%x",
        *v20);
      v18 = v220;
      a3 = v196;
      if ( (*((_BYTE *)v20 + 25) & 1) != 0 )
        goto LABEL_38;
LABEL_63:
      *((_BYTE *)v20 + 25) = 1;
      goto LABEL_38;
    }
LABEL_357:
    result = 0;
    *(_DWORD *)(a3 + 28) = 0;
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_18;
    v170 = *(unsigned int *)(v14 + 16);
    v171 = "cam_vfe_bus_update_hfr";
    v172 = debug_mdl & 8;
    v173 = 3228;
LABEL_367:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v172,
      4,
      v171,
      v173,
      "No reg val pairs. num_wms: %u",
      v170);
    result = 0;
    goto LABEL_18;
  }
  v42 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
  if ( !v42 || !*(_QWORD *)(v42 + 88) )
  {
    v10 = "cam_vfe_bus_update_wm";
    v8 = "Failed! Invalid data";
    v9 = 3;
    v11 = 2944;
    goto LABEL_16;
  }
  v43 = *(_QWORD *)(a3 + 40);
  v44 = *(_DWORD *)(v42 + 16);
  v45 = *(_DWORD *)(v43 + 20);
  if ( v45 != v44 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_update_wm",
      2953,
      "Failed! Invalid number buffers:%d required:%d",
      v45,
      v44);
    goto LABEL_17;
  }
  if ( !v45 )
  {
    result = 0;
    *(_DWORD *)(a3 + 28) = 0;
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_18;
    v170 = *(unsigned int *)(v42 + 16);
    v171 = "cam_vfe_bus_update_wm";
    v172 = debug_mdl & 8;
    v173 = 3102;
    goto LABEL_367;
  }
  v213 = *(_QWORD *)(v42 + 88);
  v46 = *(_QWORD *)(v42 + 8);
  v47 = 0;
  v48 = 0;
  v19 = v46 + 48;
  v49 = v46 + 52;
  v214 = v46 + 60;
  v204 = v46 + 68;
  v212 = v46 + 72;
  v211 = v46 + 76;
  v210 = v46 + 80;
  v209 = v46 + 84;
  v208 = v46 + 88;
  v207 = v46 + 92;
  v206 = v46 + 96;
  v205 = v46 + 100;
  v202 = v46 + 104;
  v201 = v46 + 116;
  v203 = v46 + 108;
  v216 = *(_QWORD *)(v43 + 56) + 24LL;
  v221 = v42 + 24;
  v215 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
  while ( 2 )
  {
    v94 = v48;
    if ( v48 >= 0x74 )
    {
      v168 = "cam_vfe_bus_update_wm";
      v169 = 2964;
      v18 = v48;
LABEL_370:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        v168,
        v169,
        "reg_val_pair %d exceeds the array limit %zu",
        v18,
        174);
      result = 4294967284LL;
      goto LABEL_18;
    }
    if ( v47 == 2 )
      goto LABEL_386;
    v95 = *(unsigned int **)(*(_QWORD *)(v221 + 8 * v47) + 24LL);
    *(_DWORD *)(v19 + 4LL * v48) = *(_DWORD *)(*((_QWORD *)v95 + 2) + 28LL);
    *(_DWORD *)(v49 + 4LL * v48) = v95[8];
    v96 = debug_priority;
    v97 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v145 = a3;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v97,
        4,
        "cam_vfe_bus_update_wm",
        2975,
        "WM %d image width 0x%x",
        *v95);
      a3 = v145;
      v96 = debug_priority;
      v97 = debug_mdl & 8;
    }
    v98 = (_DWORD *)(v216 + 48 * v47);
    v99 = v98[2];
    if ( v97 && !v96 )
    {
      v146 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v97,
        4,
        "cam_vfe_bus_update_wm",
        2979,
        "before stride %d",
        v99);
      v100 = v98[2];
      a3 = v146;
    }
    else
    {
      v100 = v98[2];
    }
    v101 = (v99 + 15) & 0xFFFFFFF0;
    if ( v101 != v100 && v101 != v95[10] )
    {
      v102 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_vfe_bus_update_wm",
        2986,
        "Warning stride %u expected %u",
        v100,
        v101);
      a3 = v102;
    }
    v48 = v94 + 2;
    if ( v95[10] == v101 && (v95[6] & 1) != 0
      || *v95 < 3
      || (*(_DWORD *)(v19 + 4LL * v48) = *(_DWORD *)(*((_QWORD *)v95 + 2) + 40LL),
          v48 = v94 + 4,
          *(_DWORD *)(v214 + 4 * v94) = v98[2],
          v103 = debug_mdl,
          v95[10] = v101,
          (v103 & 8) == 0)
      || debug_priority )
    {
      if ( v95[14] )
        goto LABEL_200;
LABEL_314:
      v115 = v98[2];
      goto LABEL_315;
    }
    v147 = a3;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v103 & 8,
      4,
      "cam_vfe_bus_update_wm",
      2996,
      "WM %d image stride 0x%x",
      *v95,
      *(_DWORD *)(v214 + 4 * v94));
    a3 = v147;
    if ( !v95[14] )
      goto LABEL_314;
LABEL_200:
    v104 = *(_QWORD *)(*((_QWORD *)v95 + 2) + 72LL);
    if ( !v104 )
    {
      v10 = "cam_vfe_bus_update_wm";
      v8 = "No UBWC register to configure.";
      v9 = 3;
      v11 = 3002;
      goto LABEL_16;
    }
    if ( *((_BYTE *)v95 + 60) == 1 )
    {
      v105 = a3;
      *((_BYTE *)v95 + 60) = 0;
      v222 = 0;
      if ( !v19 || !v95 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_update_ubwc_regs",
          2881,
          "Invalid args");
LABEL_210:
        a3 = v105;
LABEL_211:
        v104 = *(_QWORD *)(*((_QWORD *)v95 + 2) + 72LL);
        goto LABEL_212;
      }
      cpas_hw_version = cam_cpas_get_cpas_hw_version(&v222);
      if ( cpas_hw_version )
      {
        v107 = cpas_hw_version;
        v108 = 2888;
        v109 = "Failed to get HW version rc: %d";
LABEL_209:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_update_ubwc_regs",
          v108,
          v109,
          v107);
        goto LABEL_210;
      }
      v110 = v222;
      if ( (unsigned int)(v222 - 17264897) < 0xFEF88F00 )
      {
        v108 = 2893;
        v109 = "Invalid HW version: %d";
        v107 = (unsigned int)v222;
        goto LABEL_209;
      }
      if ( v222 > 1528063 )
      {
        if ( (unsigned int)(v222 - 1528064) > 0x30 )
          goto LABEL_210;
        a3 = v105;
        if ( ((1LL << v222) & 0x1000100000003LL) == 0 )
          goto LABEL_211;
      }
      else
      {
        a3 = v105;
        if ( (unsigned int)(v222 - 1507584) <= 0x20 && ((1LL << v222) & 0x100010001LL) != 0 )
          goto LABEL_236;
        if ( v222 != 1462528 )
        {
          if ( v222 != 1507840 )
            goto LABEL_211;
LABEL_236:
          v120 = *((_QWORD *)v95 + 2);
          v121 = 4LL * v48;
          v122 = v19 + v121;
          v123 = *(_DWORD **)(v120 + 72);
          *(_DWORD *)(v19 + v121) = *(_DWORD *)(v120 + 36);
          *(_DWORD *)(v49 + v121) = v95[16];
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v199 = v123;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_update_ubwc_legacy_regs",
              2791,
              "WM %d packer cfg 0x%x",
              *v95);
            v123 = v199;
            a3 = v105;
          }
          v124 = v95[29];
          *(_DWORD *)(v122 + 8) = *v123;
          *(_DWORD *)(v214 + 4LL * v48) = v95[17];
          if ( !v124 && (debug_mdl & 8) != 0 && !debug_priority )
          {
            v200 = v123;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_update_ubwc_legacy_regs",
              2802,
              "WM %d tile cfg 0x%x",
              *v95);
            v123 = v200;
            a3 = v105;
          }
          v125 = v95[29];
          *(_DWORD *)(v122 + 16) = v123[1];
          if ( v125 )
          {
            *(_DWORD *)(v204 + 4LL * v48) = v95[7];
          }
          else
          {
            *(_DWORD *)(v204 + 4LL * v48) = v95[18];
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              v167 = v123;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_vfe_bus_update_ubwc_legacy_regs",
                2814,
                "WM %d h_init 0x%x",
                *v95);
              v123 = v167;
              a3 = v105;
            }
          }
          *(_DWORD *)(v212 + 4LL * v48) = v123[2];
          *(_DWORD *)(v211 + 4LL * v48) = v95[19];
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v162 = v123;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_update_ubwc_legacy_regs",
              2821,
              "WM %d v_init 0x%x",
              *v95);
            v123 = v162;
            a3 = v105;
          }
          *(_DWORD *)(v210 + 4LL * v48) = v123[5];
          *(_DWORD *)(v209 + 4LL * v48) = v95[20];
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v163 = v123;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_update_ubwc_legacy_regs",
              2827,
              "WM %d meta stride 0x%x",
              *v95);
            v123 = v163;
            a3 = v105;
          }
          v141 = *((_QWORD *)v95 + 1);
          if ( *(_BYTE *)(v141 + 33610) == 1 )
          {
            v142 = debug_mdl;
            v95[21] &= ~v123[8];
            if ( (v142 & 8) != 0 && !debug_priority )
            {
              v166 = v123;
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v142 & 8,
                4,
                "cam_vfe_bus_update_ubwc_legacy_regs",
                2833,
                "Force disable UBWC compression on VFE:%d WM:%d",
                *(_DWORD *)v141,
                *v95);
              v123 = v166;
              a3 = v105;
            }
          }
          *(_DWORD *)(v208 + 4LL * v48) = v123[6];
          *(_DWORD *)(v207 + 4LL * v48) = v95[21];
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v164 = v123;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_update_ubwc_legacy_regs",
              2839,
              "WM %d ubwc_mode_cfg_0 0x%x",
              *v95);
            v123 = v164;
            a3 = v105;
          }
          *(_DWORD *)(v206 + 4LL * v48) = v123[4];
          *(_DWORD *)(v205 + 4LL * v48) = v95[23];
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v165 = v123;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_update_ubwc_legacy_regs",
              2845,
              "WM %d ubwc meta offset 0x%x",
              *v95);
            v123 = v165;
            a3 = v105;
          }
          v135 = v48 + 14;
          if ( v110 == 1507600 )
          {
            v143 = v95[11];
            if ( v143 == 39 )
            {
              v144 = 9;
LABEL_309:
              v136 = v48 + 16;
              *(_DWORD *)(v19 + 4LL * v135) = v123[7];
              *(_DWORD *)(v203 + 4LL * v48) = v144;
              if ( (debug_mdl & 8) == 0 || debug_priority )
                goto LABEL_311;
              v137 = *v95;
              v138 = debug_mdl & 8;
              v139 = "cam_vfe_bus_update_ubwc_legacy_regs";
              v140 = 2866;
LABEL_346:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                3,
                v138,
                4,
                v139,
                v140,
                "WM %d ubwc bw limit 0x%x",
                v137);
              a3 = v105;
LABEL_311:
              v48 = v136;
              goto LABEL_211;
            }
            if ( v143 == 38 )
            {
              v144 = 11;
              goto LABEL_309;
            }
          }
LABEL_307:
          v48 = v135;
          goto LABEL_211;
        }
      }
      v127 = *((_QWORD *)v95 + 2);
      v128 = 4LL * v48;
      v129 = *(_DWORD **)(v127 + 72);
      v130 = v19 + v128;
      *(_DWORD *)(v19 + v128) = *(_DWORD *)(v127 + 36);
      *(_DWORD *)(v49 + v128) = v95[16];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_update_ubwc_3_regs",
          2694,
          "WM %d packer cfg 0x%x",
          *v95);
        a3 = v105;
      }
      v131 = v95[29];
      *(_DWORD *)(v130 + 8) = *v129;
      *(_DWORD *)(v214 + 4LL * v48) = v95[17];
      if ( !v131 && (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_update_ubwc_3_regs",
          2705,
          "WM %d tile cfg 0x%x",
          *v95);
        a3 = v105;
      }
      v132 = v95[29];
      *(_DWORD *)(v130 + 16) = v129[1];
      if ( v132 )
      {
        *(_DWORD *)(v204 + 4LL * v48) = v95[7];
      }
      else
      {
        *(_DWORD *)(v204 + 4LL * v48) = v95[18];
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_update_ubwc_3_regs",
            2717,
            "WM %d h_init 0x%x",
            *v95);
          a3 = v105;
        }
      }
      *(_DWORD *)(v212 + 4LL * v48) = v129[2];
      *(_DWORD *)(v211 + 4LL * v48) = v95[19];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_update_ubwc_3_regs",
          2724,
          "WM %d v_init 0x%x",
          *v95);
        a3 = v105;
      }
      *(_DWORD *)(v210 + 4LL * v48) = v129[5];
      *(_DWORD *)(v209 + 4LL * v48) = v95[20];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_update_ubwc_3_regs",
          2730,
          "WM %d meta stride 0x%x",
          *v95);
        a3 = v105;
      }
      v133 = *((_QWORD *)v95 + 1);
      if ( *(_BYTE *)(v133 + 33610) == 1 )
      {
        v134 = debug_mdl;
        v95[21] &= ~v129[9];
        if ( (v134 & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v134 & 8,
            4,
            "cam_vfe_bus_update_ubwc_3_regs",
            2736,
            "Force disable UBWC compression on VFE:%d WM:%d",
            *(_DWORD *)v133,
            *v95);
          a3 = v105;
        }
      }
      *(_DWORD *)(v208 + 4LL * v48) = v129[6];
      *(_DWORD *)(v207 + 4LL * v48) = v95[21];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_update_ubwc_3_regs",
          2743,
          "WM %d ubwc_mode_cfg_0 0x%x",
          *v95);
        a3 = v105;
      }
      *(_DWORD *)(v206 + 4LL * v48) = v129[7];
      *(_DWORD *)(v205 + 4LL * v48) = v95[22];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_update_ubwc_3_regs",
          2749,
          "WM %d ubwc_mode_cfg_1 0x%x",
          *v95);
        a3 = v105;
      }
      *(_DWORD *)(v202 + 4LL * v48) = v129[4];
      *(_DWORD *)(v203 + 4LL * v48) = v95[23];
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_update_ubwc_3_regs",
          2755,
          "WM %d ubwc meta offset 0x%x",
          *v95);
        a3 = v105;
      }
      v135 = v48 + 16;
      if ( v95[32] )
      {
        v136 = v48 + 18;
        *(_DWORD *)(v19 + 4LL * v135) = v129[8];
        *(_DWORD *)(v201 + 4LL * v48) = v95[32];
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_311;
        v137 = *v95;
        v138 = debug_mdl & 8;
        v139 = "cam_vfe_bus_update_ubwc_3_regs";
        v140 = 2762;
        goto LABEL_346;
      }
      goto LABEL_307;
    }
LABEL_212:
    v111 = *(_QWORD **)(a3 + 40);
    v112 = a3;
    v222 = 0;
    v113 = *(_QWORD *)(*v111 + 8 * v47);
    if ( v19 && v104 )
    {
      v114 = cam_cpas_get_cpas_hw_version(&v222);
      if ( v114 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_update_ubwc_meta_addr",
          2633,
          "Failed to get HW version rc: %d",
          v114);
      }
      else if ( (unsigned int)(v222 - 1528113) > 0xFFFFAFCE )
      {
        if ( (unsigned int)(v222 - 1528064) <= 0x30 && ((1LL << v222) & 0x1000100000003LL) != 0 )
        {
          v126 = *(_DWORD *)(v104 + 12);
          *(_DWORD *)(v49 + 4LL * v48) = v113;
          *(_DWORD *)(v19 + 4LL * v48) = v126;
          v48 += 2;
        }
        else if ( (unsigned int)(v222 - 1507584) <= 0x20 && ((1LL << v222) & 0x100010001LL) != 0 || v222 == 1507840 )
        {
          v119 = *(_DWORD *)(v104 + 12);
          *(_DWORD *)(v49 + 4LL * v48) = v113;
          *(_DWORD *)(v19 + 4LL * v48) = v119;
          v48 += 2;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_update_ubwc_meta_addr",
          2638,
          "Invalid HW version: %d",
          v222);
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_update_ubwc_meta_addr",
        2627,
        "Invalid args");
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_update_wm",
        3018,
        "WM %d ubwc meta addr 0x%llx",
        *v95,
        *(_QWORD *)(**(_QWORD **)(v112 + 40) + 8 * v47));
    v115 = v98[2];
    a3 = v112;
    if ( v95[14] )
    {
      v116 = v98[3];
      v117 = v98[5];
      v118 = ((v116 * v115 + 4095) & 0xFFFFF000) + v117;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_update_wm",
          3030,
          "WM %d frm %d: ht: %d stride %d meta: %d",
          *v95,
          v118,
          v116,
          v115,
          v117);
        a3 = v112;
      }
      goto LABEL_316;
    }
LABEL_315:
    v118 = v98[3] * v115;
LABEL_316:
    if ( *v95 > 2 )
    {
      v149 = 1;
    }
    else
    {
      v148 = v95[24];
      v149 = v148 + 1;
      if ( v148 == -1 )
      {
LABEL_335:
        v156 = v215;
        v157 = *(_DWORD *)(*((_QWORD *)v95 + 2) + 60LL);
        *(_DWORD *)(v49 + 4LL * v48) = v118;
        *(_DWORD *)(v19 + 4LL * v48) = v157;
        v48 += 2;
        v158 = debug_mdl;
        if ( (debug_mdl & 8) == 0 )
          goto LABEL_338;
LABEL_336:
        if ( !debug_priority )
        {
          v159 = a3;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v158 & 8,
            4,
            "cam_vfe_bus_update_wm",
            3064,
            "WM %d frame_inc %d",
            *v95,
            *(_DWORD *)(v19 + 4LL * (v48 - 1)));
          a3 = v159;
        }
        goto LABEL_338;
      }
    }
    v150 = 0;
    do
    {
      if ( v95[14] )
      {
        if ( v48 < 0xAD )
        {
          *(_DWORD *)(v19 + 4LL * v48) = *(_DWORD *)(*((_QWORD *)v95 + 2) + 20LL);
          v151 = *(_QWORD **)(a3 + 40);
          v152 = v98[5];
          goto LABEL_327;
        }
        v154 = v48 + 1;
        v198 = a3;
        v155 = 3049;
LABEL_332:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_update_wm",
          v155,
          "Exceed buf size %u when adding reg/val at index %u and %u",
          174,
          v48,
          v154);
        a3 = v198;
        v153 = debug_mdl;
        if ( (debug_mdl & 8) == 0 )
          goto LABEL_321;
        goto LABEL_328;
      }
      if ( v48 >= 0xAD )
      {
        v154 = v48 + 1;
        v198 = a3;
        v155 = 3055;
        goto LABEL_332;
      }
      *(_DWORD *)(v19 + 4LL * v48) = *(_DWORD *)(*((_QWORD *)v95 + 2) + 20LL);
      v151 = *(_QWORD **)(a3 + 40);
      v152 = v95[7];
LABEL_327:
      *(_DWORD *)(v49 + 4LL * v48) = v150 + v152 + *(_QWORD *)(*v151 + 8 * v47);
      v48 += 2;
      v153 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_321;
LABEL_328:
      if ( !debug_priority )
      {
        v197 = a3;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v153 & 8,
          4,
          "cam_vfe_bus_update_wm",
          3057,
          "WM %d image address 0x%x",
          *v95,
          *(_DWORD *)(v19 + 4LL * (v48 - 1)));
        a3 = v197;
      }
LABEL_321:
      --v149;
      v150 += v118;
    }
    while ( v149 );
    if ( v48 < 0xAD )
      goto LABEL_335;
    v161 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_update_wm",
      3062,
      "Exceed buf size %u when adding reg/val at index %u and %u",
      174,
      v48,
      v48 + 1);
    v156 = v215;
    a3 = v161;
    v158 = debug_mdl;
    if ( (debug_mdl & 8) != 0 )
      goto LABEL_336;
LABEL_338:
    if ( v48 >= 0xAD )
    {
      v160 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_update_wm",
        3071,
        "Exceed buf size %u when adding reg/val at index %u and %u",
        174,
        v48,
        v48 + 1);
      a3 = v160;
      if ( (v95[6] & 1) == 0 )
        goto LABEL_181;
    }
    else
    {
      *(_DWORD *)(v19 + 4LL * v48) = *(_DWORD *)(*((_QWORD *)v95 + 2) + 8LL);
      *(_DWORD *)(v49 + 4LL * v48) = v95[28];
      v48 += 2;
      if ( (v95[6] & 1) == 0 )
LABEL_181:
        *((_BYTE *)v95 + 24) = 1;
    }
    if ( ++v47 < (unsigned __int64)*(unsigned int *)(v156 + 16) )
      continue;
    break;
  }
  v174 = v48 >> 1;
  v183 = a3;
  v184 = *(__int64 (__fastcall **)(_QWORD))(v213 + 24);
  if ( *((_DWORD *)v184 - 1) != 2010610996 )
    __break(0x8228u);
  v185 = v184(v48 >> 1);
  v178 = v183;
  v186 = *(_DWORD *)(v183 + 24);
  v180 = 4 * v185;
  if ( 4 * v185 <= v186 )
  {
    v187 = *(void (__fastcall **)(__int64, __int64, __int64))(v213 + 120);
    goto LABEL_383;
  }
  v181 = "cam_vfe_bus_update_wm";
  v182 = 3088;
LABEL_379:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    v181,
    v182,
    "Failed! Buf size:%d insufficient, expected size:%d");
  result = 4294967284LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
