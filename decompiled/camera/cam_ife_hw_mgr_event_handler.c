__int64 __fastcall cam_ife_hw_mgr_event_handler(__int64 a1, unsigned int a2, _DWORD *a3)
{
  int v5; // w8
  char v7; // w23
  unsigned int v8; // w8
  void (__fastcall *v9)(__int64, __int64, __int64 *); // x22
  char v10; // w8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x1
  unsigned int affected_ctx; // w23
  char v15; // w25
  unsigned int v16; // w9
  void (__fastcall *v17)(__int64, __int64, __int64 *); // x8
  char v18; // w25
  _DWORD *v19; // x22
  _QWORD *i; // x25
  __int64 v21; // x8
  __int64 v22; // x9
  _DWORD *v23; // x8
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x9
  _DWORD *v27; // x8
  __int64 v28; // x0
  unsigned __int64 v29; // x25
  __int64 v30; // x8
  __int64 v31; // x9
  _DWORD *v32; // x8
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x9
  _DWORD *v36; // x8
  __int64 v37; // x0
  unsigned int v38; // w8
  void (__fastcall *v39)(__int64, __int64, __int64 *); // x8
  __int64 v40; // x0
  int v41; // w8
  _DWORD *v42; // x22
  __int64 v43; // x0
  int *v44; // x25
  int v45; // w24
  int v46; // w8
  __int64 v47; // x8
  unsigned int v48; // w22
  __int64 v49; // x23
  unsigned int ife_csid_rdi_res_type; // w0
  int *v51; // x9
  unsigned int v52; // w8
  void (__fastcall *v53)(__int64, __int64, __int64 *); // x22
  __int64 v54; // x8
  __int64 v55; // x0
  int v56; // w0
  __int64 v57; // x6
  __int64 v58; // x7
  __int64 v59; // x0
  const char *v60; // x5
  const char *v61; // x3
  __int64 v62; // x4
  char v63; // w9
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x1
  int v67; // w0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x6
  __int64 v71; // x7
  const char *v72; // x3
  const char *v73; // x5
  __int64 v74; // x4
  int v75; // w0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x1
  __int64 v79; // x4
  __int64 v80; // x6
  __int64 v81; // x7
  int v82; // w9
  const char *v83; // x3
  const char *v84; // x5
  __int64 v85; // x1
  __int64 v86; // x4
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x1
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x1
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x1
  __int64 v97; // x8
  __int64 v98; // x0
  __int64 v99; // x8
  __int64 v100; // x0
  _DWORD *v101; // x8
  __int64 v102; // x0
  _QWORD *j; // x23
  _QWORD *k; // x27
  __int64 v105; // x2
  __int64 v106; // x2
  __int64 v107; // x9
  void (__fastcall *v108)(__int64, __int64); // x8
  __int64 v109; // x0
  __int64 v110; // x9
  void (__fastcall *v111)(__int64, __int64); // x8
  __int64 v112; // x0
  __int64 v113; // x8
  __int64 v114; // x9
  _DWORD *v115; // x8
  __int64 v116; // x0
  __int64 v117; // x8
  __int64 v118; // x9
  _DWORD *v119; // x8
  __int64 v120; // x0
  __int64 v121; // x6
  __int64 v122; // x8
  __int64 v123; // x22
  __int64 v124; // x8
  __int64 v125; // x9
  _DWORD *v126; // x8
  __int64 v127; // x0
  __int64 v128; // x8
  __int64 v129; // x9
  _DWORD *v130; // x8
  __int64 v131; // x0
  const char *v132; // x3
  __int64 v133; // x4
  int v134; // w8
  __int64 v135; // x1
  int v136; // w8
  int v137; // w22
  const char *v138; // x0
  int v139; // w8
  int v140; // w9
  void (__fastcall *v141)(__int64, __int64, __int64 *); // x8
  __int64 v142; // x0
  void (__fastcall *v143)(__int64, __int64, __int64 *); // x8
  __int64 v144; // x0
  __int64 v145; // x0
  __int64 v146; // x0
  __int64 v147; // x2
  unsigned int v148; // w22
  const void *v149; // x0
  int v150; // w22
  const char *v151; // x0
  int v152; // w8
  unsigned int *v153; // x24
  unsigned int v154; // w22
  __int64 v155; // x27
  __int64 v156; // x0
  __int64 (__fastcall *v157)(__int64, __int64, int *); // x23
  __int64 v158; // x0
  __int64 v159; // x7
  const char *v160; // x3
  const char *v161; // x5
  __int64 v162; // x4
  __int64 v163; // x6
  __int64 v164; // x0
  __int64 v165; // x0
  __int64 v166; // x1
  __int64 v167; // x8
  int v168; // w8
  int v169; // w0
  const char *v170; // x6
  _DWORD *v172; // x22
  __int64 v173; // x0
  char v174; // w23
  unsigned __int64 v175; // x8
  char v176; // w28
  unsigned __int64 v177; // x23
  unsigned int *v178; // x24
  unsigned int v179; // w9
  __int64 v180; // x9
  unsigned __int64 v181; // x11
  __int64 **v182; // x10
  int v183; // w9
  __int64 v184; // x9
  __int64 v185; // x9
  _QWORD *v186; // x10
  __int64 v187; // x11
  _DWORD *v188; // x10
  __int64 v189; // x0
  __int64 v190; // x0
  __int64 v191; // x0
  __int64 v192; // x1
  __int64 v193; // x8
  __int64 v194; // x0
  __int64 v195; // x0
  __int64 v196; // x3
  int v197; // w8
  int v198; // [xsp+0h] [xbp-110h]
  int v199; // [xsp+28h] [xbp-E8h]
  int v200; // [xsp+2Ch] [xbp-E4h]
  _QWORD v201[2]; // [xsp+30h] [xbp-E0h] BYREF
  __int64 v202; // [xsp+40h] [xbp-D0h]
  int v203; // [xsp+4Ch] [xbp-C4h] BYREF
  _BYTE v204[30]; // [xsp+50h] [xbp-C0h] BYREF
  __int16 v205; // [xsp+6Eh] [xbp-A2h]
  __int64 v206; // [xsp+70h] [xbp-A0h] BYREF
  __int64 v207; // [xsp+78h] [xbp-98h] BYREF
  __int64 v208; // [xsp+80h] [xbp-90h] BYREF
  __int64 v209; // [xsp+88h] [xbp-88h]
  __int64 v210; // [xsp+90h] [xbp-80h]
  __int64 v211; // [xsp+98h] [xbp-78h]
  __int64 v212; // [xsp+A0h] [xbp-70h]
  __int64 v213; // [xsp+A8h] [xbp-68h]
  __int64 v214; // [xsp+B0h] [xbp-60h]
  __int64 v215; // [xsp+B8h] [xbp-58h]
  __int64 v216; // [xsp+C0h] [xbp-50h]
  __int64 v217; // [xsp+C8h] [xbp-48h]
  __int64 v218; // [xsp+D0h] [xbp-40h]
  __int64 v219; // [xsp+D8h] [xbp-38h]
  __int64 v220; // [xsp+E0h] [xbp-30h]
  __int64 v221; // [xsp+E8h] [xbp-28h]
  __int64 v222; // [xsp+F0h] [xbp-20h]
  __int64 v223; // [xsp+F8h] [xbp-18h]
  __int64 v224; // [xsp+100h] [xbp-10h]

  v224 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_event_handler",
      18445,
      "Invalid data evt_info: %pK priv: %pK",
      a3,
      (const void *)a1);
    affected_ctx = -22;
    goto LABEL_359;
  }
  v5 = a3[5];
  if ( v5 == 7 )
  {
    v18 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v148 = a3[3];
      v149 = (const void *)cam_isp_hw_evt_type_to_string(a2);
      ((void (*)(__int64, _QWORD, __int64, const char *, const char *, ...))cam_print_log)(
        3,
        v18 & 8,
        4,
        "cam_ife_hw_mgr_handle_sfe_event",
        &print_fmt_cam_flush_req[28],
        "Handle SFE[%u] %s event in ctx: %u",
        (const void *)v148,
        v149);
      if ( a2 != 5 )
        goto LABEL_32;
    }
    else if ( a2 != 5 )
    {
LABEL_32:
      if ( !a2 )
      {
        v19 = *((_DWORD **)a3 + 4);
        memset(v204, 0, 24);
        v222 = 0;
        v223 = 0;
        v220 = 0;
        v221 = 0;
        v218 = 0;
        v219 = 0;
        v216 = 0;
        v217 = 0;
        v214 = 0;
        v215 = 0;
        v212 = 0;
        v213 = 0;
        v210 = 0;
        v211 = 0;
        v208 = 0;
        v209 = 0;
        v206 = 0;
        v207 = 0;
        if ( v19 )
        {
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_handle_sfe_hw_err",
              17799,
              "SFE[%u] error [%u] on res_type %u ctx: %u",
              a3[3],
              *v19,
              *a3,
              *(_DWORD *)(a1 + 56));
          raw_spin_lock(&unk_3A8588);
          for ( i = *(_QWORD **)(a1 + 256); i != (_QWORD *)(a1 + 256); i = (_QWORD *)*i )
          {
            v21 = i[4];
            if ( v21 )
            {
              if ( *a3 == 11 && *(_DWORD *)v21 == 11 && a3[2] == *(_DWORD *)(v21 + 4) )
              {
                v22 = *(_QWORD *)(v21 + 16);
                if ( v22 )
                {
                  v23 = *(_DWORD **)(v22 + 88);
                  if ( v23 )
                  {
                    v24 = *(_QWORD *)(v22 + 112);
                    if ( *(v23 - 1) != -1055839300 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v23)(v24, 17, a3, 40);
                  }
                }
              }
            }
            v25 = i[5];
            if ( v25 )
            {
              if ( *a3 == 11 && *(_DWORD *)v25 == 11 && a3[2] == *(_DWORD *)(v25 + 4) )
              {
                v26 = *(_QWORD *)(v25 + 16);
                if ( v26 )
                {
                  v27 = *(_DWORD **)(v26 + 88);
                  if ( v27 )
                  {
                    v28 = *(_QWORD *)(v26 + 112);
                    if ( *(v27 - 1) != -1055839300 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v27)(v28, 17, a3, 40);
                  }
                }
              }
            }
          }
          if ( *a3 == 12 )
          {
            v29 = *(_QWORD *)(a1 + 280)
                + ((unsigned __int64)*(unsigned __int8 *)(*(_QWORD *)(a1 + 8504) + *((unsigned __int8 *)a3 + 8)) << 7);
            v30 = *(_QWORD *)(v29 + 32);
            if ( v30 )
            {
              v31 = *(_QWORD *)(v30 + 16);
              v32 = *(_DWORD **)(v31 + 88);
              if ( v32 )
              {
                v33 = *(_QWORD *)(v31 + 112);
                if ( *(v32 - 1) != -1055839300 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v32)(v33, 17, a3, 40);
              }
            }
            v34 = *(_QWORD *)(v29 + 40);
            if ( v34 )
            {
              v35 = *(_QWORD *)(v34 + 16);
              v36 = *(_DWORD **)(v35 + 88);
              if ( v36 )
              {
                v37 = *(_QWORD *)(v35 + 112);
                if ( *(v36 - 1) != -1055839300 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v36)(v37, 17, a3, 40);
              }
            }
          }
          if ( (*(_BYTE *)v19 & 3) != 0 )
          {
            *(_DWORD *)v204 = 8;
            if ( (debug_mdl & 8) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_hw_mgr_handle_sfe_hw_err",
                17808,
                "Notify context for SFE error, ctx_idx: %u",
                *(_DWORD *)(a1 + 56));
            cam_ife_hw_mgr_find_affected_ctx(v204, (unsigned int)a3[3], &v206, 0);
          }
          raw_spin_unlock(&unk_3A8588);
          affected_ctx = 0;
          goto LABEL_359;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_handle_sfe_hw_err",
          17791,
          "No additional error event data failed to process for SFE[%u] ctx: %u",
          a3[3],
          *(_DWORD *)(a1 + 56));
        affected_ctx = -22;
        goto LABEL_355;
      }
      ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_ife_hw_mgr_handle_sfe_event",
        &print_fmt_cam_flush_req[41],
        "Event: %u not handled for SFE, ctx_idx: %u");
LABEL_59:
      affected_ctx = -22;
      goto LABEL_355;
    }
    affected_ctx = cam_ife_hw_mgr_handle_hw_buf_done(a1, a3);
    if ( !affected_ctx )
      goto LABEL_359;
LABEL_355:
    if ( a2 > 5 )
      v170 = "INVALID_EVT";
    else
      v170 = off_451420[a2];
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_event_handler",
      18472,
      "Failed to handle %s [%u] event from hw %u in ctx %u rc %d",
      v170,
      a2,
      a3[5],
      *(_DWORD *)(a1 + 56),
      affected_ctx);
    goto LABEL_359;
  }
  if ( v5 != 2 )
  {
    if ( !v5 )
    {
      v7 = debug_mdl;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v150 = a3[3];
        v151 = (const char *)cam_isp_hw_evt_type_to_string(a2);
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v7 & 8,
          4,
          "cam_ife_hw_mgr_handle_csid_event",
          18366,
          "Handle CSID[%u] %s event in ctx: %u",
          v150,
          v151,
          *(_DWORD *)(a1 + 56));
        if ( (int)a2 > 1 )
          goto LABEL_9;
      }
      else if ( (int)a2 > 1 )
      {
LABEL_9:
        if ( a2 == 4 )
        {
          v38 = a3[2];
          v206 = 0;
          if ( v38 <= 6 )
          {
            v39 = *(void (__fastcall **)(__int64, __int64, __int64 *))(a1 + 24);
            if ( !*(_DWORD *)(a1 + 8844) )
            {
              v40 = *(_QWORD *)(a1 + 32);
              if ( *((_DWORD *)v39 - 1) != 414296116 )
                __break(0x8228u);
              v39(v40, 4, &v206);
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_ife_hw_mgr_handle_csid_eof",
                  17471,
                  "Received CSID[%u] CAMIF EOF res: %d ctx_idx: %u",
                  (unsigned int)a3[3],
                  (unsigned int)a3[2],
                  *(_DWORD *)(a1 + 56));
            }
            goto LABEL_349;
          }
          v56 = __ratelimit(&cam_ife_hw_mgr_handle_csid_eof__rs, "cam_ife_hw_mgr_handle_csid_eof");
          v57 = (unsigned int)a3[2];
          v58 = *(unsigned int *)(a1 + 56);
          if ( v56 )
            v59 = 3;
          else
            v59 = 2;
          v60 = "Invalid res_id: %d ctx_idx: %u";
          v61 = "cam_ife_hw_mgr_handle_csid_eof";
          v62 = 17475;
          goto LABEL_348;
        }
        if ( a2 != 3 )
        {
          if ( a2 == 2 )
          {
            v8 = a3[2];
            v207 = 0;
            v208 = 0;
            v206 = 0;
            if ( v8 <= 6 )
            {
              v9 = *(void (__fastcall **)(__int64, __int64, __int64 *))(a1 + 24);
              if ( !*(_DWORD *)(a1 + 8844) )
              {
                v10 = *(_BYTE *)(a1 + 9316);
                LOBYTE(v208) = 1;
                if ( (v10 & 1) != 0 )
                {
                  v206 = 0;
                  v87 = ktime_get_with_offset(1);
                  v88 = ns_to_timespec64(v87);
                  v207 = v89 + 1000000000 * v88;
                  if ( (debug_mdl & 8) != 0 && !debug_priority )
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 8,
                      4,
                      "cam_ife_hw_mgr_handle_csid_rup",
                      17409,
                      "CSID RUP ACK, boot_time %llu, ctx_idx: %u",
                      v89 + 1000000000 * v88,
                      *(_DWORD *)(a1 + 56));
                  goto LABEL_169;
                }
                if ( *(_BYTE *)(a1 + 9380) == 1 )
                {
                  v11 = ktime_get_with_offset(1);
                  v12 = ns_to_timespec64(v11);
                  v206 = v13 + 1000000000 * v12;
                  v207 = v206;
LABEL_169:
                  cam_hw_mgr_reset_out_of_sync_cnt(a1);
                  v98 = *(_QWORD *)(a1 + 32);
                  if ( *((_DWORD *)v9 - 1) != 414296116 )
                    __break(0x8236u);
                  v9(v98, 2, &v206);
                  if ( (debug_mdl & 8) != 0 && !debug_priority )
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
                      3,
                      debug_mdl & 8,
                      4,
                      "cam_ife_hw_mgr_handle_csid_rup",
                      17436,
                      "RUP done for CSID:%d source %d ctx_idx: %u",
                      (unsigned int)a3[3],
                      (unsigned int)a3[2],
                      *(_DWORD *)(a1 + 56));
                  goto LABEL_349;
                }
                v97 = *((_QWORD *)a3 + 4);
                if ( v97 )
                {
                  v206 = *(_QWORD *)(v97 + 16);
                  cam_ife_mgr_cmd_get_sof_timestamp(a1, &v206, &v207, 0, 0);
                  goto LABEL_169;
                }
                v132 = "cam_ife_hw_mgr_handle_csid_rup";
                v133 = 17418;
                goto LABEL_431;
              }
LABEL_349:
              affected_ctx = 0;
              goto LABEL_350;
            }
            v67 = __ratelimit(&cam_ife_hw_mgr_handle_csid_rup__rs, "cam_ife_hw_mgr_handle_csid_rup");
            v57 = (unsigned int)a3[2];
            v58 = *(unsigned int *)(a1 + 56);
            if ( v67 )
              v59 = 3;
            else
              v59 = 2;
            v60 = "Invalid res_id: %d, ctx_idx: %u";
            v61 = "cam_ife_hw_mgr_handle_csid_rup";
            v62 = 17440;
LABEL_348:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
              v59,
              8,
              1,
              v61,
              v62,
              v60,
              v57,
              v58,
              v198);
            goto LABEL_349;
          }
          goto LABEL_332;
        }
        v41 = *((unsigned __int8 *)a3 + 4);
        v42 = *(_DWORD **)(a1 + 24);
        v208 = 0;
        v209 = 0;
        v206 = 0;
        v207 = 0;
        if ( v41 == 1 )
        {
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_handle_csid_camif_epoch",
              17576,
              "Received CSID[%u] CAMIF EPOCH res: %d as secondary evt, ctx_idx: %u",
              a3[3],
              a3[2],
              *(_DWORD *)(a1 + 56));
          v43 = *(_QWORD *)(a1 + 32);
          *(_DWORD *)v204 = 1;
LABEL_315:
          if ( *(v42 - 1) != 414296116 )
            __break(0x8236u);
          affected_ctx = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *))v42)(v43, 6, v204);
          goto LABEL_350;
        }
        if ( a3[2] > 6u )
        {
          v75 = __ratelimit(&cam_ife_hw_mgr_handle_csid_camif_epoch__rs, "cam_ife_hw_mgr_handle_csid_camif_epoch");
          v57 = (unsigned int)a3[2];
          v58 = *(unsigned int *)(a1 + 56);
          if ( v75 )
            v59 = 3;
          else
            v59 = 2;
          v60 = "Invalid res_id: %d ctx_idx: %u";
          v61 = "cam_ife_hw_mgr_handle_csid_camif_epoch";
          v62 = 17636;
          goto LABEL_348;
        }
        if ( *(_DWORD *)(a1 + 8844) )
          goto LABEL_349;
        v63 = *(_BYTE *)(a1 + 9316);
        LODWORD(v207) = a3[4];
        LOBYTE(v209) = 1;
        if ( (v63 & 1) != 0 )
        {
          v206 = 0;
          v94 = ktime_get_with_offset(1);
          v95 = ns_to_timespec64(v94);
          v208 = v96 + 1000000000 * v95;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_handle_csid_camif_epoch",
              17603,
              "boot_time 0x%llx, ctx_idx: %u",
              v96 + 1000000000 * v95,
              *(_DWORD *)(a1 + 56));
LABEL_178:
          cam_hw_mgr_reset_out_of_sync_cnt(a1);
          v100 = *(_QWORD *)(a1 + 32);
          if ( *(v42 - 1) != 414296116 )
            __break(0x8236u);
          ((void (__fastcall *)(__int64, __int64, __int64 *))v42)(v100, 3, &v206);
          affected_ctx = 0;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_handle_csid_camif_epoch",
              17632,
              "Received CSID[%u] CAMIF Epoch res: %d, ctx_idx: %u",
              (unsigned int)a3[3],
              (unsigned int)a3[2],
              *(_DWORD *)(a1 + 56));
            goto LABEL_349;
          }
LABEL_350:
          if ( !dword_3A88C8 )
            goto LABEL_354;
          if ( a2 > 5 )
            goto LABEL_352;
          goto LABEL_303;
        }
        if ( *(_BYTE *)(a1 + 9380) == 1 )
        {
          v64 = ktime_get_with_offset(1);
          v65 = ns_to_timespec64(v64);
          v206 = v66 + 1000000000 * v65;
          v208 = v206;
          goto LABEL_178;
        }
        v99 = *((_QWORD *)a3 + 4);
        if ( v99 )
        {
          v206 = *(_QWORD *)(v99 + 16);
          cam_ife_mgr_cmd_get_sof_timestamp(a1, &v206, &v208, 0, 0);
          goto LABEL_178;
        }
        goto LABEL_264;
      }
      if ( a2 )
      {
        if ( a2 != 1 )
        {
LABEL_332:
          v159 = *(unsigned int *)(a1 + 56);
          v160 = "cam_ife_hw_mgr_handle_csid_event";
          v161 = "Event: %u not handled for CSID, ctx_idx: %u";
          v162 = 18389;
          v163 = a2;
LABEL_339:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
            3,
            8,
            1,
            v160,
            v162,
            v161,
            v163,
            v159);
          affected_ctx = -22;
          goto LABEL_350;
        }
        v152 = *((unsigned __int8 *)a3 + 4);
        v42 = *(_DWORD **)(a1 + 24);
        v206 = 0;
        v207 = 0;
        if ( v152 == 1 )
        {
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_handle_csid_camif_sof",
              17496,
              "Received CSID[%u] CAMIF SOF res: %d as secondary evt, ctx_idx: %u",
              a3[3],
              a3[2],
              *(_DWORD *)(a1 + 56));
          v43 = *(_QWORD *)(a1 + 32);
          *(_DWORD *)v204 = 0;
          goto LABEL_315;
        }
        if ( a3[2] > 6u )
        {
          v169 = __ratelimit(&cam_ife_hw_mgr_handle_csid_camif_sof__rs, "cam_ife_hw_mgr_handle_csid_camif_sof");
          v57 = (unsigned int)a3[2];
          v58 = *(unsigned int *)(a1 + 56);
          if ( v169 )
            v59 = 3;
          else
            v59 = 2;
          v60 = "Invalid res_id: %d, ctx_idx: %u";
          v61 = "cam_ife_hw_mgr_handle_csid_camif_sof";
          v62 = 17554;
          goto LABEL_348;
        }
        if ( *(_DWORD *)(a1 + 8844) )
          goto LABEL_349;
        if ( (*(_BYTE *)(a1 + 9316) & 1) != 0 )
        {
          v206 = 0;
          v190 = ktime_get_with_offset(1);
          v191 = ns_to_timespec64(v190);
          v207 = v192 + 1000000000 * v191;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_handle_csid_camif_sof",
              17520,
              "boot_time 0x%llx, ctx_idx: %u",
              v192 + 1000000000 * v191,
              *(_DWORD *)(a1 + 56));
        }
        else if ( *(_BYTE *)(a1 + 9380) == 1 )
        {
          v164 = ktime_get_with_offset(1);
          v165 = ns_to_timespec64(v164);
          v206 = v166 + 1000000000 * v165;
          v207 = v206;
        }
        else
        {
          v193 = *((_QWORD *)a3 + 4);
          if ( !v193 )
          {
            v132 = "cam_ife_hw_mgr_handle_csid_camif_sof";
            v133 = 17529;
            goto LABEL_431;
          }
          v206 = *(_QWORD *)(v193 + 16);
          cam_ife_mgr_cmd_get_sof_timestamp(a1, &v206, &v207, 0, 0);
        }
        cam_hw_mgr_reset_out_of_sync_cnt(a1);
        v194 = *(_QWORD *)(a1 + 32);
        if ( *(v42 - 1) != 414296116 )
          __break(0x8236u);
        ((void (__fastcall *)(__int64, __int64, __int64 *))v42)(v194, 1, &v206);
        affected_ctx = 0;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_handle_csid_camif_sof",
            17549,
            "Received CSID[%u] CAMIF SOF res: %d, ctx_idx: %u",
            (unsigned int)a3[3],
            (unsigned int)a3[2],
            *(_DWORD *)(a1 + 56));
          goto LABEL_349;
        }
        goto LABEL_350;
      }
      v153 = *((unsigned int **)a3 + 4);
      v201[1] = 0;
      v202 = 0;
      v201[0] = 0;
      v222 = 0;
      v223 = 0;
      v220 = 0;
      v221 = 0;
      v218 = 0;
      v219 = 0;
      v216 = 0;
      v217 = 0;
      v214 = 0;
      v215 = 0;
      v212 = 0;
      v213 = 0;
      v210 = 0;
      v211 = 0;
      v208 = 0;
      v209 = 0;
      v206 = 0;
      v207 = 0;
      if ( !v153 )
      {
        v163 = (unsigned int)a3[3];
        v159 = *(unsigned int *)(a1 + 56);
        v160 = "cam_ife_hw_mgr_handle_csid_error";
        v161 = "No additional error event data failed to process for CSID[%u] ctx: %u";
        v162 = 17281;
        goto LABEL_339;
      }
      v154 = *v153;
      v155 = *(_QWORD *)(a1 + 72);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_handle_csid_error",
          17289,
          "Entry CSID[%u] error %d ctx_idx: %u",
          a3[3],
          v154,
          *(_DWORD *)(a1 + 56));
      v156 = raw_spin_lock(&unk_3A8588);
      if ( *((_BYTE *)a3 + 4) == 1 )
      {
        v157 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 24);
        v205 = 0;
        v203 = 0;
        strcpy(v204, "error");
        memset(&v204[6], 0, 24);
        if ( (v154 & 0x4000) != 0 )
        {
          v203 = 2;
          strcpy(v204, "sync frame drop");
        }
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_handle_csid_secondary_err_evts",
            17231,
            "Received CSID[%d] %s err_type:%d res: %d as secondary evt on ctx: %u",
            a3[3],
            v204,
            v154,
            a3[2],
            *(_DWORD *)(a1 + 56));
        v158 = *(_QWORD *)(a1 + 32);
        if ( *((_DWORD *)v157 - 1) != 414296116 )
          __break(0x8237u);
        affected_ctx = v157(v158, 6, &v203);
        if ( affected_ctx )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_handle_csid_secondary_err_evts",
            17238,
            "Handling cb for CSID[%d] %s err_type:%d res: %d as secondary evt on ctx: %u failed rc:%d",
            a3[3],
            v204,
            v154,
            a3[2],
            *(_DWORD *)(a1 + 56),
            affected_ctx);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_handle_csid_error",
            17299,
            "Failed to handle CSID[%u] sec event for res: %d err: 0x%x on ctx: %u",
            a3[3],
            a3[2],
            v154,
            *(_DWORD *)(a1 + 56));
        }
LABEL_368:
        raw_spin_unlock(&unk_3A8588);
        goto LABEL_350;
      }
      LODWORD(v206) = 2;
      LODWORD(v201[0]) |= v154;
      if ( (v154 & 0x400000) != 0 )
      {
        v172 = *(_DWORD **)(a1 + 24);
        LODWORD(v201[0]) = 0x400000;
        BYTE2(v202) = 1;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_handle_rup_miss_evt",
            17253,
            "Received CSID[%u] rup miss res: %d on ctx: %u",
            a3[3],
            a3[2],
            *(_DWORD *)(a1 + 56));
        v173 = *(_QWORD *)(a1 + 32);
        if ( *(v172 - 1) != 414296116 )
          __break(0x8236u);
        affected_ctx = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *))v172)(v173, 0, v201);
        if ( affected_ctx )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_handle_rup_miss_evt",
            17260,
            "CSID[%u] RUP miss cb failed for res:%d on ctx:%u",
            a3[3],
            a3[2],
            *(_DWORD *)(a1 + 56));
        *((_BYTE *)v153 + 8) = BYTE3(v202);
        goto LABEL_368;
      }
      if ( (v154 & 0x2201C0) != 0 )
      {
        v167 = (unsigned int)a3[2];
        if ( (unsigned int)v167 > 0xB )
        {
          v168 = -1;
          v200 = -1;
        }
        else
        {
          v200 = dword_4513A8[v167];
          v168 = dword_4513D8[v167];
        }
        v199 = v168;
        v175 = *(unsigned int *)(a1 + 8716);
        if ( (_DWORD)v175 )
        {
          v176 = 0;
          v177 = 0;
          v178 = (unsigned int *)(a1 + 8584);
          *(_QWORD *)v204 = 0;
          while ( 1 )
          {
            if ( v177 == 11 )
              goto LABEL_263;
            v179 = v178[2];
            if ( v179 == 7 )
            {
              v184 = *v178;
              if ( (_DWORD)v184 != a3[6] )
                goto LABEL_375;
              if ( (unsigned int)v184 > 2 )
                goto LABEL_263;
              v185 = v184;
              v186 = &g_ife_hw_mgr[v185];
              v181 = (v185 * 8) | 0xE0;
              v183 = v199;
              v182 = (__int64 **)(v186 + 28);
            }
            else
            {
              if ( v179 != 2 )
                goto LABEL_375;
              v180 = *v178;
              if ( (_DWORD)v180 != a3[3] )
                goto LABEL_375;
              if ( (unsigned int)v180 > 7 )
                goto LABEL_263;
              v181 = 8 * v180 + 160;
              v182 = (__int64 **)((char *)g_ife_hw_mgr + v181);
              v183 = v200;
            }
            if ( v181 > 0x13FD8 )
            {
              __break(1u);
              return cam_isp_hw_evt_type_to_string(v156);
            }
            v187 = **v182;
            if ( !v187 )
            {
              if ( (unsigned int)__ratelimit(
                                   &cam_ife_hw_mgr_check_and_notify_overflow__rs,
                                   "cam_ife_hw_mgr_check_and_notify_overflow") )
                v195 = 3;
              else
                v195 = 2;
              v156 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       v195,
                       8,
                       1,
                       "cam_ife_hw_mgr_check_and_notify_overflow",
                       1559,
                       "hw_intf is null, ctx_idx: %u",
                       *(_DWORD *)(a1 + 56));
              goto LABEL_408;
            }
            v188 = *(_DWORD **)(v187 + 88);
            if ( v188 )
            {
              v189 = *(_QWORD *)(v187 + 112);
              *(_DWORD *)v204 = v183;
              if ( *(v188 - 1) != -1055839300 )
                __break(0x822Au);
              v156 = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64))v188)(v189, 58, v204, 8);
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                v156 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         debug_mdl & 8,
                         4,
                         "cam_ife_hw_mgr_check_and_notify_overflow",
                         1574,
                         "check and notify hw idx %d type %d bus overflow happened %d ctx_idx: %u",
                         *v178,
                         v178[2],
                         v204[4],
                         *(_DWORD *)(a1 + 56));
              v175 = *(unsigned int *)(a1 + 8716);
              if ( v204[4] )
                v176 = 1;
            }
LABEL_375:
            ++v177;
            v178 += 3;
            if ( v177 >= v175 )
              goto LABEL_408;
          }
        }
        v176 = 0;
LABEL_408:
        v174 = v176 ^ 1;
      }
      else
      {
        v174 = 1;
      }
      if ( (v154 & 0x200000) != 0 )
        cam_ife_hw_mgr_drv_info_dump(v156, a1);
      if ( (v154 & 0x10AE20) == 0 )
      {
        if ( *(_BYTE *)(v155 + 81031) == 1 && (v154 & 0x10000) != 0
          || ((unsigned __int8)v174 & ((v154 & 0x15000) == 0)) != 0 )
        {
          goto LABEL_413;
        }
        v197 = *(_DWORD *)(a1 + 9448);
        if ( !v197 )
        {
          v197 = 1;
          BYTE2(v202) = 1;
          if ( *(_DWORD *)(a1 + 8844) )
            v197 = 0;
          else
            *(_DWORD *)(a1 + 9448) = 1;
          if ( !*(_QWORD *)(a1 + 9456) )
            *(_QWORD *)(a1 + 9456) = *(_QWORD *)(a1 + 9304);
        }
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_handle_csid_error",
            17355,
            "CSID[%u] error: %u current_recovery_cnt: %u  recovery_req: %llu on ctx: %u",
            a3[3],
            v154,
            v197,
            *(_QWORD *)(a1 + 9456),
            *(_DWORD *)(a1 + 56));
      }
      LODWORD(v206) = v154;
LABEL_413:
      if ( BYTE2(v202) == 1 && *(_DWORD *)(a1 + 8844) )
        v196 = (v154 >> 12) & 1;
      else
        v196 = 0;
      affected_ctx = cam_ife_hw_mgr_find_affected_ctx(v201, (unsigned int)a3[3], &v206, v196);
      if ( !affected_ctx && (_DWORD)v219 )
      {
        if ( (v202 & 0x10000) == 0 )
          cam_ife_hw_mgr_do_error_recovery(&v206);
        affected_ctx = 0;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_handle_csid_error",
            &print_fmt_cam_icp_fw_dbg[5],
            "Exit CSID[%u] error %d ctx_idx: %u",
            (const char *)(unsigned int)a3[3]);
          affected_ctx = 0;
        }
      }
      goto LABEL_368;
    }
    goto LABEL_59;
  }
  v15 = debug_mdl;
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( (int)a2 <= 2 )
      goto LABEL_21;
LABEL_266:
    if ( a2 == 3 )
    {
      v139 = a3[2];
      v208 = 0;
      v209 = 0;
      v206 = 0;
      v207 = 0;
      if ( (unsigned int)(v139 - 3) >= 7 )
      {
        if ( v139 )
        {
          if ( (unsigned int)__ratelimit(&cam_ife_hw_mgr_handle_hw_epoch__rs, "cam_ife_hw_mgr_handle_hw_epoch") )
            v145 = 3;
          else
            v145 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v145,
            8,
            1,
            "cam_ife_hw_mgr_handle_hw_epoch",
            17968,
            "Invalid res_id: %d, ctx_idx: %u",
            a3[2],
            *(_DWORD *)(a1 + 56));
        }
        else
        {
          v143 = *(void (__fastcall **)(__int64, __int64, __int64 *))(a1 + 24);
          if ( !*(_DWORD *)(a1 + 8844) )
          {
            v144 = *(_QWORD *)(a1 + 32);
            LODWORD(v207) = a3[4];
            if ( *((_DWORD *)v143 - 1) != 414296116 )
              __break(0x8228u);
            v143(v144, 3, &v206);
          }
        }
      }
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_300;
      v81 = (unsigned int)a3[2];
      v80 = (unsigned int)a3[3];
      v82 = *(_DWORD *)(a1 + 56);
      v83 = "cam_ife_hw_mgr_handle_hw_epoch";
      v84 = "Epoch for VFE:%d source %d ctx_idx: %u";
      v85 = debug_mdl & 8;
      v86 = 17973;
      goto LABEL_439;
    }
    if ( a2 != 4 )
    {
      if ( a2 == 5 )
      {
        affected_ctx = cam_ife_hw_mgr_handle_hw_buf_done(a1, a3);
        goto LABEL_301;
      }
LABEL_274:
      v71 = *(unsigned int *)(a1 + 56);
      v72 = "cam_ife_hw_mgr_handle_ife_event";
      v73 = "Event: %u not handled for IFE, ctx_idx: %u";
      v74 = 18342;
      v70 = a2;
      goto LABEL_275;
    }
    v140 = a3[2];
    v141 = *(void (__fastcall **)(__int64, __int64, __int64 *))(a1 + 24);
    v206 = 0;
    if ( (unsigned int)(v140 - 3) >= 5 )
    {
      if ( (unsigned int)(v140 - 8) < 2 )
        goto LABEL_298;
      if ( v140 )
      {
        if ( (unsigned int)__ratelimit(&cam_ife_hw_mgr_handle_hw_eof__rs, "cam_ife_hw_mgr_handle_hw_eof") )
          v146 = 3;
        else
          v146 = 2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          v146,
          8,
          1,
          "cam_ife_hw_mgr_handle_hw_eof",
          18118,
          "Invalid res_id: %d, ctx_idx: %u",
          a3[2],
          *(_DWORD *)(a1 + 56));
        goto LABEL_298;
      }
    }
    else if ( *(_BYTE *)(a1 + 9385) != 1 )
    {
LABEL_298:
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_300;
      v81 = (unsigned int)a3[2];
      v80 = (unsigned int)a3[3];
      v82 = *(_DWORD *)(a1 + 56);
      v83 = "cam_ife_hw_mgr_handle_hw_eof";
      v84 = "EOF for VFE:%d source %d ctx_idx: %u";
      v85 = debug_mdl & 8;
      v86 = 18123;
      goto LABEL_439;
    }
    if ( !*(_DWORD *)(a1 + 8844) )
    {
      v142 = *(_QWORD *)(a1 + 32);
      if ( *((_DWORD *)v141 - 1) != 414296116 )
        __break(0x8228u);
      v141(v142, 4, &v206);
    }
    goto LABEL_298;
  }
  v137 = a3[3];
  v138 = (const char *)cam_isp_hw_evt_type_to_string(a2);
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v15 & 8,
    4,
    "cam_ife_hw_mgr_handle_ife_event",
    18313,
    "Handle IFE[%u] %s event in ctx: %u",
    v137,
    v138,
    *(_DWORD *)(a1 + 56));
  if ( (int)a2 > 2 )
    goto LABEL_266;
LABEL_21:
  if ( a2 )
  {
    if ( a2 != 1 )
    {
      if ( a2 == 2 )
      {
        v16 = a3[2];
        v207 = 0;
        v208 = 0;
        v206 = 0;
        if ( v16 <= 9 )
        {
          v17 = *(void (__fastcall **)(__int64, __int64, __int64 *))(a1 + 24);
          if ( ((1 << v16) & 0xF8) != 0 )
          {
            if ( (*(_BYTE *)(a1 + 9385) & 1) == 0 && *(_BYTE *)(a1 + 9399) != 1 )
              goto LABEL_161;
LABEL_127:
            if ( !*(_DWORD *)(a1 + 8844) )
            {
              v68 = *(_QWORD *)(a1 + 32);
              if ( *((_DWORD *)v17 - 1) != 414296116 )
                __break(0x8228u);
              v17(v68, 2, &v206);
            }
            goto LABEL_161;
          }
          if ( ((1 << v16) & 0x304) != 0 )
          {
LABEL_161:
            if ( (debug_mdl & 8) == 0 || debug_priority )
              goto LABEL_300;
            v81 = (unsigned int)a3[2];
            v80 = (unsigned int)a3[3];
            v82 = *(_DWORD *)(a1 + 56);
            v83 = "cam_ife_hw_mgr_handle_hw_rup";
            v84 = "RUP done for VFE:%d source %d, ctx_idx: %u";
            v85 = debug_mdl & 8;
            v86 = 17932;
LABEL_439:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
              3,
              v85,
              4,
              v83,
              v86,
              v84,
              v80,
              v81,
              v82);
LABEL_300:
            affected_ctx = 0;
            goto LABEL_301;
          }
          if ( !v16 )
          {
            if ( *(_BYTE *)(a1 + 9379) == 1 && a3[3] != *(_DWORD *)(a1 + 60) )
              goto LABEL_161;
            goto LABEL_127;
          }
        }
        if ( (unsigned int)__ratelimit(&cam_ife_hw_mgr_handle_hw_rup__rs, "cam_ife_hw_mgr_handle_hw_rup") )
          v93 = 3;
        else
          v93 = 2;
        ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
          v93,
          8,
          1,
          "cam_ife_hw_mgr_handle_hw_rup",
          &print_fmt_cam_apply_req[47],
          (unsigned int)"Invalid res_id: %d, ctx_idx: %u");
        goto LABEL_161;
      }
      goto LABEL_274;
    }
    v52 = a3[2];
    v206 = 0;
    v207 = 0;
    if ( v52 <= 9 )
    {
      v53 = *(void (__fastcall **)(__int64, __int64, __int64 *))(a1 + 24);
      if ( ((1 << v52) & 0xF8) != 0 )
      {
        if ( (*(_BYTE *)(a1 + 9385) & 1) == 0 && *(_BYTE *)(a1 + 9399) != 1 )
          goto LABEL_148;
        v54 = *((_QWORD *)a3 + 4);
        if ( v54 )
          goto LABEL_104;
        v79 = 18044;
        goto LABEL_147;
      }
      if ( ((1 << v52) & 5) != 0 )
      {
        if ( (*(_BYTE *)(a1 + 9316) & 1) != 0 )
        {
          v90 = ktime_get_with_offset(1);
          v91 = ns_to_timespec64(v90);
          v207 = v92 + 1000000000 * v91;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_handle_hw_sof",
              18003,
              "boot_time 0x%llx, ctx_idx: %u",
              v92 + 1000000000 * v91,
              *(_DWORD *)(a1 + 56));
          goto LABEL_105;
        }
        if ( *(_BYTE *)(a1 + 9380) == 1 )
        {
          v76 = ktime_get_with_offset(1);
          v77 = ns_to_timespec64(v76);
          v206 = v78 + 1000000000 * v77;
          v207 = v206;
LABEL_105:
          cam_hw_mgr_reset_out_of_sync_cnt(a1);
          if ( !*(_DWORD *)(a1 + 8844) )
          {
            v55 = *(_QWORD *)(a1 + 32);
            if ( *((_DWORD *)v53 - 1) != 414296116 )
              __break(0x8236u);
            v53(v55, 1, &v206);
          }
          goto LABEL_148;
        }
        v54 = *((_QWORD *)a3 + 4);
        if ( v54 )
        {
LABEL_104:
          v206 = *(_QWORD *)(v54 + 16);
          cam_ife_mgr_cmd_get_sof_timestamp(a1, &v206, &v207, 0, 0);
          goto LABEL_105;
        }
        v79 = 18012;
LABEL_147:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_handle_hw_sof",
          v79,
          "SOF timestamp data is null: %s",
          "NULL");
LABEL_148:
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_300;
        v81 = (unsigned int)a3[2];
        v80 = (unsigned int)a3[3];
        v82 = *(_DWORD *)(a1 + 56);
        v83 = "cam_ife_hw_mgr_handle_hw_sof";
        v84 = "SOF for VFE:%d source %d ctx_idx: %u";
        v85 = debug_mdl & 8;
        v86 = 18074;
        goto LABEL_439;
      }
      if ( ((1 << v52) & 0x300) != 0 )
        goto LABEL_148;
    }
    if ( (unsigned int)__ratelimit(&cam_ife_hw_mgr_handle_hw_sof__rs, "cam_ife_hw_mgr_handle_hw_sof") )
      v69 = 3;
    else
      v69 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v69,
      8,
      1,
      "cam_ife_hw_mgr_handle_hw_sof",
      18069,
      "Invalid res_id: %d, ctx_idx: %u",
      a3[2],
      *(_DWORD *)(a1 + 56));
    goto LABEL_148;
  }
  v44 = *((int **)a3 + 4);
  memset(v204, 0, 24);
  v222 = 0;
  v223 = 0;
  v220 = 0;
  v221 = 0;
  v218 = 0;
  v219 = 0;
  v216 = 0;
  v217 = 0;
  v214 = 0;
  v215 = 0;
  v212 = 0;
  v213 = 0;
  v210 = 0;
  v211 = 0;
  v208 = 0;
  v209 = 0;
  v206 = 0;
  v207 = 0;
  if ( !v44 )
  {
    v70 = (unsigned int)a3[3];
    v71 = *(unsigned int *)(a1 + 56);
    v72 = "cam_ife_hw_mgr_handle_hw_err";
    v73 = "No additional error event data failed to process for IFE[%u] ctx: %u";
    v74 = 17831;
LABEL_275:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      8,
      1,
      v72,
      v74,
      v73,
      v70,
      v71);
    affected_ctx = -22;
    goto LABEL_301;
  }
  v45 = *v44;
  raw_spin_lock(&unk_3A8588);
  v46 = *a3;
  if ( *a3 == 6 )
  {
    v47 = (unsigned int)a3[3];
    if ( (unsigned int)v47 >= 8 )
    {
LABEL_263:
      __break(0x5512u);
LABEL_264:
      v132 = "cam_ife_hw_mgr_handle_csid_camif_epoch";
      v133 = 17612;
LABEL_431:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
        3,
        8,
        1,
        v132,
        v133,
        "SOF timestamp data is null: %s",
        "NULL");
      affected_ctx = 0;
      goto LABEL_350;
    }
    v48 = a3[2];
    v49 = g_ife_hw_mgr[v47 + 12];
    if ( max_ife_out_res + 12288 <= v48 )
    {
      ife_csid_rdi_res_type = 12;
    }
    else
    {
      ife_csid_rdi_res_type = cam_ife_hw_mgr_get_ife_csid_rdi_res_type(v48);
      if ( ife_csid_rdi_res_type >= 5 )
      {
        if ( !dword_3A85F0 )
          goto LABEL_184;
        v51 = &dword_3A85F4;
        if ( dword_3A85F8 == v48 )
          goto LABEL_96;
        if ( dword_3A85F0 == 1 )
          goto LABEL_184;
        v51 = &dword_3A85FC;
        if ( dword_3A8600 != v48 )
        {
          if ( dword_3A85F0 == 2 )
            goto LABEL_184;
          v51 = &dword_3A8604;
          if ( dword_3A8608 != v48 )
          {
            if ( dword_3A85F0 != 3 )
              goto LABEL_263;
LABEL_184:
            ife_csid_rdi_res_type = 5;
            goto LABEL_185;
          }
        }
LABEL_96:
        if ( *v51 == 8 )
          ife_csid_rdi_res_type = 6;
        else
          ife_csid_rdi_res_type = 5;
      }
    }
LABEL_185:
    v101 = *(_DWORD **)(v49 + 88);
    LODWORD(v201[0]) = ife_csid_rdi_res_type;
    if ( v101 )
    {
      v102 = *(_QWORD *)(v49 + 112);
      if ( *(v101 - 1) != -1055839300 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD *, __int64))v101)(v102, 74, v201, 4) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_trigger_crop_reg_dump",
          17044,
          "CSID:%d Reg Dump failed for path=%u",
          a3[3],
          LODWORD(v201[0]));
    }
    v46 = *a3;
  }
  if ( v46 == 4 && (*(_BYTE *)(a1 + 9385) & 1) == 0 && a3[2] )
  {
    v201[0] = 0;
    for ( j = *(_QWORD **)(a1 + 224); j != (_QWORD *)(a1 + 224); j = (_QWORD *)*j )
    {
      v105 = j[4];
      if ( v105 )
      {
        if ( !*(_DWORD *)(v105 + 4) )
        {
          v110 = *(_QWORD *)(v105 + 16);
          if ( v110 )
          {
            v111 = *(void (__fastcall **)(__int64, __int64))(v110 + 88);
            if ( v111 )
            {
              v112 = *(_QWORD *)(v110 + 112);
              if ( *((_DWORD *)v111 - 1) != -1055839300 )
                __break(0x8228u);
              v111(v112, 20);
            }
          }
        }
      }
      v106 = j[5];
      if ( v106 )
      {
        if ( !*(_DWORD *)(v106 + 4) )
        {
          v107 = *(_QWORD *)(v106 + 16);
          if ( v107 )
          {
            v108 = *(void (__fastcall **)(__int64, __int64))(v107 + 88);
            if ( v108 )
            {
              v109 = *(_QWORD *)(v107 + 112);
              if ( *((_DWORD *)v108 - 1) != -1055839300 )
                __break(0x8228u);
              v108(v109, 20);
            }
          }
        }
      }
    }
    for ( k = *(_QWORD **)(a1 + 208); k != (_QWORD *)(a1 + 208); k = (_QWORD *)*k )
    {
      v113 = k[4];
      if ( v113 )
      {
        v114 = *(_QWORD *)(v113 + 16);
        v115 = *(_DWORD **)(v114 + 88);
        if ( v115 )
        {
          v116 = *(_QWORD *)(v114 + 112);
          if ( *(v115 - 1) != -1055839300 )
            __break(0x8228u);
          if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD *, __int64))v115)(v116, 40, v201, 8) )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_hw_mgr_handle_hw_dump_info",
              17749,
              "CSID Clock Dump failed, ctx_idx: %u",
              *(_DWORD *)(a1 + 56));
        }
      }
      v117 = k[5];
      if ( v117 )
      {
        v118 = *(_QWORD *)(v117 + 16);
        v119 = *(_DWORD **)(v118 + 88);
        if ( v119 )
        {
          v120 = *(_QWORD *)(v118 + 112);
          if ( *(v119 - 1) != -1055839300 )
            __break(0x8228u);
          if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD *, __int64))v119)(v120, 40, v201, 8) )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_hw_mgr_handle_hw_dump_info",
              17749,
              "CSID Clock Dump failed, ctx_idx: %u",
              *(_DWORD *)(a1 + 56));
        }
      }
    }
    if ( *a3 == 6 )
    {
      v121 = *((unsigned __int8 *)a3 + 8);
      v122 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8496) + v121);
      if ( v122 == 255 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_handle_hw_dump_info",
          17757,
          "Invalid index:%d for out_map",
          v121);
      }
      else
      {
        v123 = *(_QWORD *)(a1 + 272) + (v122 << 7);
        v124 = *(_QWORD *)(v123 + 32);
        if ( v124 )
        {
          v125 = *(_QWORD *)(v124 + 16);
          v126 = *(_DWORD **)(v125 + 88);
          if ( v126 )
          {
            v127 = *(_QWORD *)(v125 + 112);
            if ( *(v126 - 1) != -1055839300 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v126)(v127, 17, a3, 40);
          }
        }
        v128 = *(_QWORD *)(v123 + 40);
        if ( v128 )
        {
          v129 = *(_QWORD *)(v128 + 16);
          v130 = *(_DWORD **)(v129 + 88);
          if ( v130 )
          {
            v131 = *(_QWORD *)(v129 + 112);
            if ( *(v130 - 1) != -1055839300 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v130)(v131, 17, a3, 40);
          }
        }
      }
    }
  }
  if ( v45 == 3 )
  {
    if ( (v44[1] & 1) != 0 )
      v134 = 262152;
    else
      v134 = 8;
    goto LABEL_247;
  }
  if ( *a3 == 6 )
  {
    v134 = 16;
    goto LABEL_247;
  }
  if ( *a3 == 4 )
  {
    v134 = 2;
LABEL_247:
    *(_DWORD *)v204 = v134;
  }
  v135 = (unsigned int)a3[3];
  if ( dword_3A8504 )
    v204[16] = 1;
  if ( byte_3A8574 == 1 )
    v204[17] = byte_3A8574;
  affected_ctx = cam_ife_hw_mgr_find_affected_ctx(v204, v135, &v206, 0);
  if ( !affected_ctx && (_DWORD)v219 )
  {
    if ( v45 == 3 )
      v136 = 8;
    else
      v136 = 2;
    LODWORD(v206) = v136;
    cam_ife_hw_mgr_do_error_recovery(&v206);
  }
  raw_spin_unlock(&unk_3A8588);
LABEL_301:
  if ( !dword_3A88C8 )
    goto LABEL_354;
  if ( a2 > 5 )
  {
LABEL_352:
    v147 = 0xFFFFFFFFLL;
    goto LABEL_353;
  }
LABEL_303:
  v147 = dword_451408[a2];
LABEL_353:
  cam_ife_hw_mgr_print_debug_reg(a1, a3, v147);
LABEL_354:
  if ( affected_ctx )
    goto LABEL_355;
LABEL_359:
  _ReadStatusReg(SP_EL0);
  return affected_ctx;
}
