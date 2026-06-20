__int64 __fastcall _cam_isp_ctx_handle_error(__int64 *a1, unsigned int *a2)
{
  __int64 v2; // x19
  unsigned int v3; // w23
  _QWORD *v4; // x26
  _QWORD *v5; // x27
  __int64 v6; // x20
  __int64 *v7; // x24
  unsigned int *v8; // x25
  unsigned int v9; // w0
  unsigned int v10; // w22
  __int64 v11; // x21
  __int64 v12; // x22
  unsigned int v13; // w0
  const char *v14; // x5
  unsigned int *v15; // x20
  __int64 v16; // x1
  __int64 v17; // x4
  unsigned __int64 v18; // x8
  unsigned int v19; // w23
  int v20; // w20
  __int64 *v21; // x8
  unsigned __int64 v22; // x8
  unsigned int v23; // w23
  int v24; // w20
  __int64 *v25; // x21
  __int64 v26; // x8
  const char *v27; // x9
  __int64 v28; // x16
  const char *v29; // x17
  unsigned int v30; // w8
  __int64 v31; // x1
  int v32; // w10
  unsigned int v33; // w24
  unsigned int **v34; // x20
  unsigned int **v35; // x27
  int v36; // w26
  int v37; // w11
  unsigned int *v38; // x28
  _QWORD *v39; // x23
  unsigned int *v40; // x21
  __int64 v41; // x20
  __int64 v42; // x27
  unsigned __int64 v43; // x23
  __int64 v44; // x25
  unsigned int v45; // w7
  signed int v46; // w0
  unsigned int **v47; // x8
  unsigned int *v48; // x9
  __int64 v49; // x20
  unsigned int *v50; // x1
  unsigned int *v51; // x27
  unsigned int *v52; // x21
  __int64 v53; // x20
  __int64 v54; // x23
  unsigned __int64 v55; // x28
  __int64 v56; // x25
  unsigned int v57; // w7
  signed int v58; // w0
  unsigned int **v59; // x8
  unsigned int *v60; // x9
  __int64 v61; // x20
  unsigned int *v62; // x1
  unsigned int **v63; // x10
  unsigned int ***v64; // x9
  unsigned int **v65; // x11
  unsigned int *v66; // x8
  unsigned int **v67; // x2
  _QWORD *v68; // x10
  _QWORD *v69; // x11
  _QWORD *v70; // x9
  _QWORD *v71; // x12
  __int64 v72; // x8
  _QWORD *v73; // x2
  __int64 v74; // x0
  _QWORD *v75; // x23
  unsigned int *v76; // x26
  __int64 v77; // x21
  __int64 v78; // x23
  __int64 v79; // x23
  unsigned __int64 v80; // x27
  __int64 v81; // x8
  unsigned int v82; // w0
  signed int v83; // w0
  unsigned int **v84; // x8
  __int64 v85; // x9
  __int64 v86; // x21
  unsigned int *v87; // x1
  char v88; // w20
  __int64 *v89; // x21
  __int64 v90; // x0
  char v91; // w8
  __int64 v92; // x8
  __int64 *v93; // x10
  _DWORD *v94; // x8
  __int64 v95; // x0
  __int64 v96; // x6
  __int64 v97; // x7
  const char *v98; // x3
  const char *v99; // x5
  __int64 v100; // x1
  __int64 v101; // x0
  __int64 v102; // x2
  __int64 v103; // x4
  unsigned int *v104; // x21
  __int64 *v105; // x20
  __int64 v106; // x20
  __int64 v107; // x22
  __int64 v108; // x21
  int v109; // w0
  __int64 v110; // x8
  __int64 v111; // x9
  __int64 v113; // [xsp+0h] [xbp-130h]
  __int64 v114; // [xsp+8h] [xbp-128h]
  int v115; // [xsp+10h] [xbp-120h]
  __int64 v116; // [xsp+18h] [xbp-118h]
  unsigned int v117; // [xsp+5Ch] [xbp-D4h]
  int v118; // [xsp+60h] [xbp-D0h]
  unsigned int v119; // [xsp+68h] [xbp-C8h]
  int v120; // [xsp+68h] [xbp-C8h]
  unsigned int v121; // [xsp+6Ch] [xbp-C4h]
  int v122; // [xsp+6Ch] [xbp-C4h]
  _QWORD *v123; // [xsp+70h] [xbp-C0h]
  unsigned int *v124; // [xsp+78h] [xbp-B8h]
  __int64 *v125; // [xsp+80h] [xbp-B0h]
  unsigned int *v126; // [xsp+88h] [xbp-A8h]
  __int64 v127; // [xsp+88h] [xbp-A8h]
  unsigned int *v128; // [xsp+90h] [xbp-A0h]
  unsigned int *v129; // [xsp+90h] [xbp-A0h]
  unsigned int **v130; // [xsp+98h] [xbp-98h]
  _QWORD *v131; // [xsp+A0h] [xbp-90h]
  __int64 v132; // [xsp+A8h] [xbp-88h] BYREF
  __int64 v133; // [xsp+B0h] [xbp-80h]
  __int64 v134; // [xsp+B8h] [xbp-78h]
  __int64 v135; // [xsp+C0h] [xbp-70h]
  __int64 v136; // [xsp+C8h] [xbp-68h]
  __int64 v137; // [xsp+D0h] [xbp-60h]
  __int64 v138; // [xsp+D8h] [xbp-58h]
  __int64 v139; // [xsp+E0h] [xbp-50h]
  __int64 v140; // [xsp+E8h] [xbp-48h]
  __int64 v141; // [xsp+F0h] [xbp-40h]
  __int64 v142; // [xsp+F8h] [xbp-38h]
  __int64 v143; // [xsp+100h] [xbp-30h]
  _QWORD v144[5]; // [xsp+108h] [xbp-28h] BYREF

  v144[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    v3 = *a2;
    if ( (*a2 & 0x400000) == 0 )
      goto LABEL_4;
LABEL_228:
    v106 = *(_QWORD *)(v2 + 256);
    if ( *(_QWORD *)(v2 + 160) == v2 + 160 )
      v107 = 0;
    else
      v107 = *(_QWORD *)(v2 + 160);
    if ( *(_QWORD *)(v2 + 128) == v2 + 128 )
      v108 = 0;
    else
      v108 = *(_QWORD *)(v2 + 128);
    if ( v107 | v108 )
    {
      *((_BYTE *)a2 + 19) = 1;
      v109 = __ratelimit(&cam_isp_ctx_rup_miss_handler__rs, "cam_isp_ctx_rup_miss_handler");
      v96 = *(unsigned int *)(v2 + 32);
      v97 = *(unsigned int *)(v2 + 64);
      if ( v107 )
      {
        v110 = *(_QWORD *)(v107 + 24);
        if ( !v108 )
          goto LABEL_239;
LABEL_241:
        v111 = *(_QWORD *)(v108 + 24);
        goto LABEL_242;
      }
      v110 = -1;
      if ( v108 )
        goto LABEL_241;
    }
    else
    {
      v109 = __ratelimit(&cam_isp_ctx_rup_miss_handler__rs, "cam_isp_ctx_rup_miss_handler");
      v96 = *(unsigned int *)(v2 + 32);
      v97 = *(unsigned int *)(v2 + 64);
      v110 = -1;
    }
LABEL_239:
    v111 = -1;
LABEL_242:
    if ( v109 )
      v101 = 3;
    else
      v101 = 2;
    v98 = "cam_isp_ctx_rup_miss_handler";
    v99 = "RUP miss recived for ctx:%u, link:0x%x, wait_req:%llu active_req:%llu substate:%u frame_id:%u";
    v100 = 8;
    v102 = 2;
    v103 = 4764;
    v116 = *(_QWORD *)(v106 + 8);
    v115 = *(_DWORD *)(v106 + 20);
    v113 = v110;
    v114 = v111;
LABEL_246:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, __int64, int, __int64))cam_print_log)(
      v101,
      v100,
      v102,
      v98,
      v103,
      v99,
      v96,
      v97,
      v113,
      v114,
      v115,
      v116);
    goto LABEL_247;
  }
  v104 = a2;
  v105 = a1;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "__cam_isp_ctx_handle_error",
    4792,
    "Enter HW error_type = %d, ctx:%u on link 0x%x",
    *a2,
    *(_DWORD *)(v2 + 32),
    *(_DWORD *)(v2 + 64));
  a2 = v104;
  a1 = v105;
  v3 = *v104;
  if ( (*v104 & 0x400000) != 0 )
    goto LABEL_228;
LABEL_4:
  v4 = a1 + 5654;
  v5 = a1 + 4662;
  v125 = a1;
  if ( *((_BYTE *)a2 + 18) != 1 )
  {
    v10 = 0;
    goto LABEL_21;
  }
  v6 = *a1;
  v144[1] = 0;
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  if ( (v3 & 0x80) != 0 && (byte_3A8B8C & 2) != 0 )
  {
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_19;
    v14 = "Internal recovery for bus overflow is disabled, err_type: 0x%x";
    v15 = a2;
    v16 = debug_mdl & 8;
    v17 = 4689;
    goto LABEL_250;
  }
  if ( (v3 & 0x15000) != 0 && (byte_3A8B8C & 8) != 0 )
  {
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_19;
    v14 = "Internal recovery for CSID recoverable error is disabled, err_type: 0x%x";
    v15 = a2;
    v16 = debug_mdl & 8;
    v17 = 4699;
LABEL_250:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      v16,
      4,
      "__cam_isp_ctx_trigger_error_req_reapply",
      v17,
      v14,
      v3);
    a2 = v15;
LABEL_19:
    *((_BYTE *)a2 + 18) = 0;
    goto LABEL_20;
  }
  v7 = a1;
  v8 = a2;
  v9 = _cam_isp_ctx_validate_for_req_reapply_util();
  a2 = v8;
  v10 = v9;
  if ( !v9 )
  {
    v11 = *v7;
    v12 = *(_QWORD *)(*v7 + 144);
    if ( v12 != *v7 + 144 )
    {
      *((_DWORD *)v7 + 5) = 2;
      v5[8] = *(_QWORD *)(v12 + 24);
      *((_DWORD *)v4 + 85) = 1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "__cam_isp_ctx_handle_recovery_req_util",
        4653,
        "Notify CRM to reapply req:%llu for ctx:%u link:0x%x",
        *(_QWORD *)(v12 + 24),
        *(_DWORD *)(v11 + 32),
        *(_DWORD *)(v11 + 64));
      v13 = _cam_isp_ctx_notify_error_util(7, *(_QWORD *)(v12 + 24), v7);
      if ( v13 )
      {
        v10 = v13;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "__cam_isp_ctx_handle_recovery_req_util",
          4662,
          "ctx:%u link:0x%x unable to notify CRM for req %llu",
          *(_DWORD *)(v11 + 32),
          *(_DWORD *)(v11 + 64),
          v5[8]);
        v5[8] = 0;
        a2 = v8;
        *((_DWORD *)v4 + 85) = 0;
        goto LABEL_21;
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_handle_recovery_req_util",
          4669,
          "Triggered internal recovery for req:%llu ctx:%u on link 0x%x",
          v5[8],
          *(_DWORD *)(v11 + 32),
          *(_DWORD *)(v11 + 64));
LABEL_247:
      v10 = 0;
      goto LABEL_248;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_handle_recovery_req_util",
      4640,
      "No pending request to recover from on ctx: %u",
      *(_DWORD *)(v11 + 32));
    if ( v3 != 4096 )
    {
      v10 = -22;
      a2 = v8;
      goto LABEL_21;
    }
    if ( byte_3A8B91 == 1 )
    {
      v92 = *v5;
      v93 = *(__int64 **)(v6 + 208);
      LODWORD(v132) = 14;
      v144[0] = v92;
      v94 = (_DWORD *)v93[12];
      v144[2] = &v132;
      v95 = *v93;
      if ( *(v94 - 1) != 1863972096 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v94)(v95, v144);
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_247;
      v96 = *(unsigned int *)(v6 + 32);
      v97 = *(unsigned int *)(v6 + 64);
      v98 = "__cam_isp_ctx_trigger_error_req_reapply";
      v99 = "Skipping error reporting for out of sync on ctx: %u link: 0x%x";
      v100 = debug_mdl & 8;
      v101 = 3;
      v102 = 4;
      v103 = 4734;
      goto LABEL_246;
    }
    a2 = v8;
LABEL_20:
    v10 = -22;
  }
LABEL_21:
  v124 = a2;
  if ( (*((_BYTE *)v4 + 505) & 1) == 0 )
    _cam_isp_ctx_pause_crm_timer(v2);
  v123 = v4;
  v18 = *v4;
  if ( (*v4 & 0x8000000000000000LL) == 0 )
  {
    if ( v18 > 4 )
    {
      v20 = 5;
      v19 = (v18 + 1) % 5;
    }
    else
    {
      v19 = 0;
      v20 = v18 + 1;
    }
    do
    {
      v21 = &v125[8 * (unsigned __int64)v19 + 5655];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "__cam_isp_ctx_dump_frame_timing_record",
        614,
        "Index: %u SOF_TS: %llu.%llu EPOCH_TS: %llu.%llu EOF_TS: %llu.%llu SEC_SOF: %llu.%llu",
        v19,
        *v21,
        v21[1] / 1000,
        v21[4],
        v21[5] / 1000,
        v21[2],
        v21[3] / 1000,
        v21[6],
        v21[7] / 1000);
      if ( v19 + 1 < 5 )
        ++v19;
      else
        v19 -= 4;
      --v20;
    }
    while ( v20 );
  }
  _cam_isp_ctx_print_event_record(v125);
  v131 = v5;
  v22 = v5[13];
  if ( (v22 & 0x8000000000000000LL) == 0 )
  {
    if ( v22 > 0x53 )
    {
      v24 = 84;
      v23 = (v22 + 1) % 0x54;
    }
    else
    {
      v23 = 0;
      v24 = v22 + 1;
    }
    v135 = 0;
    v136 = 0;
    v133 = 0;
    v134 = 0;
    v132 = 0;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_dump_state_monitor_array",
      700,
      "Dumping state information for preceding requests");
    do
    {
      v25 = &v125[7 * v23 + 4676];
      time64_to_tm(v25[3], 0, &v132);
      v26 = *(unsigned int *)v25;
      v27 = "INVALID";
      if ( (unsigned int)v26 <= 6 )
        v27 = off_451850[v26];
      v28 = *((unsigned int *)v25 + 1);
      v29 = "CAM_ISP_EVENT_INVALID";
      if ( (unsigned int)v28 <= 0xB )
        v29 = off_451888[v28];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_dump_state_monitor_array",
        715,
        "Idx[%d] time[%d-%d %d:%d:%d.%lld]:Substate[%s] Frame[%lld] Req[%lld] evt[%s] at boot time[%llu:%llu]",
        v23,
        v134 + 1,
        HIDWORD(v133),
        v133,
        HIDWORD(v132),
        v132,
        v25[4] / 1000000,
        v27,
        v25[2],
        v25[1],
        v29,
        v25[5],
        v25[6]);
      if ( v23 + 1 < 0x54 )
        ++v23;
      else
        v23 -= 83;
      --v24;
    }
    while ( v24 );
  }
  v30 = *v124;
  v31 = 62;
  if ( (*v124 & 2) != 0 )
    v32 = 53;
  else
    v32 = 51;
  if ( (v30 & 0x40) != 0 )
    v32 = 60;
  if ( (v30 & 0x80) != 0 )
    v32 = 59;
  if ( (v30 & 4) != 0 )
    v32 = 54;
  if ( (v30 & 0x40008) != 0 )
    v32 = 55;
  if ( (v30 & 0x10) != 0 )
    v32 = 56;
  if ( (v30 & 0x1000) != 0 )
    v32 = 62;
  if ( (v30 & 0x1AF00) != 0 )
    v32 = 61;
  if ( (v30 & 0x100000) != 0 )
    v32 = 62;
  if ( (v30 & 0x200000) != 0 )
    v33 = 53;
  else
    v33 = v32;
  v35 = (unsigned int **)(v2 + 128);
  v34 = *(unsigned int ***)(v2 + 128);
  v36 = ((unsigned __int16)(v30 & 0x1000) >> 4)
      | ((v30 & 0x10) << 16)
      | (v30 >> 5) & 0x10
      | (v30 >> 4) & 0x2C0
      | (v30 >> 3) & 0x3020
      | (4 * (v30 & 0x100000));
  if ( (v30 & 0x11BE00) != 0 )
    v37 = 5;
  else
    v37 = 3;
  v117 = v37;
  v118 = (v30 << 16) & 0x80000 | (v30 >> 2) & 0x10000;
  v119 = v30 & 0x200000;
  v121 = ((*v124 & 6) << 16) | ((*v124 & 0xC0) >> 4);
  if ( v34 == v35 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_handle_error",
        4824,
        "handling error with no active request, ctx:%u on link 0x%x",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    v34 = *(unsigned int ***)(v2 + 160);
    if ( v34 == (unsigned int **)(v2 + 160) )
    {
      if ( (unsigned int)__ratelimit(&_cam_isp_ctx_handle_error__rs, "__cam_isp_ctx_handle_error") )
        v74 = 3;
      else
        v74 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v74,
        8,
        1,
        "__cam_isp_ctx_handle_error",
        4828,
        "Error with no active/wait request, ctx:%u on link 0x%x",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      goto LABEL_171;
    }
  }
  if ( *((_BYTE *)v124 + 17) == 1 )
    v10 = cam_isp_ctx_dump_req(v34[4], v31);
  _cam_isp_ctx_update_state_monitor_array((__int64)v125, 0, (__int64)v34[3]);
  v38 = *v35;
  v39 = v131;
  if ( *v35 != (unsigned int *)v35 )
  {
    v128 = (unsigned int *)(v2 + 176);
    while ( 1 )
    {
      v40 = *(unsigned int **)v38;
      cam_smmu_buffer_tracker_putref(v38 + 28);
      v41 = *((_QWORD *)v38 + 4);
      if ( *(_DWORD *)(v41 + 72) )
        goto LABEL_141;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_handle_error",
        4853,
        "signalled error for req %llu, ctx:%u on link 0x%x",
        *((_QWORD *)v38 + 3),
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      if ( *(_DWORD *)(v41 + 32) )
      {
        v42 = 0;
        v43 = 0;
        do
        {
          v44 = *(_QWORD *)(v41 + 24) + v42;
          v45 = *(_DWORD *)(v44 + 16);
          if ( v45 != -1 )
          {
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "__cam_isp_ctx_handle_error",
                4861,
                "req %llu, Sync fd 0x%x ctx %u, link 0x%x",
                *((_QWORD *)v38 + 3));
              v45 = *(_DWORD *)(v44 + 16);
            }
            v10 = cam_sync_signal(v45, 3u, v33);
            *(_DWORD *)(v44 + 16) = -1;
          }
          v46 = *(_DWORD *)(v44 + 20);
          if ( v46 >= 1 )
          {
            v10 = cam_sync_signal(v46, 3u, v33);
            if ( v10 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "__cam_isp_ctx_handle_error",
                4879,
                "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
                *(_DWORD *)(v44 + 20),
                *((_QWORD *)v38 + 3),
                v10,
                *(_DWORD *)(v2 + 32),
                *(_DWORD *)(v2 + 64));
            *(_DWORD *)(v44 + 20) = -1;
          }
          ++v43;
          v42 += 64;
        }
        while ( v43 < *(unsigned int *)(v41 + 32) );
      }
      v47 = *((unsigned int ***)v38 + 1);
      if ( *v47 == v38 && (v48 = *(unsigned int **)v38, *(unsigned int **)(*(_QWORD *)v38 + 8LL) == v38) )
      {
        *((_QWORD *)v48 + 1) = v47;
        *v47 = v48;
      }
      else
      {
        _list_del_entry_valid_or_report(v38);
      }
      v39 = v131;
      v35 = (unsigned int **)(v2 + 128);
      *(_QWORD *)v38 = v38;
      *((_QWORD *)v38 + 1) = v38;
      v49 = *((_QWORD *)v38 + 4);
      if ( (debug_mdl & 8) == 0 || debug_priority )
        break;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_move_req_to_free_list",
        1404,
        "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
        *((_QWORD *)v38 + 3),
        *((_QWORD *)v38 + 17),
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      if ( *((_QWORD *)v38 + 17) )
        goto LABEL_97;
LABEL_98:
      v50 = *(unsigned int **)(v2 + 184);
      if ( v128 == v38 || v50 == v38 || *(unsigned int **)v50 != v128 )
      {
        _list_add_valid_or_report(v38);
      }
      else
      {
        *(_QWORD *)(v2 + 184) = v38;
        *(_QWORD *)v38 = v128;
        *((_QWORD *)v38 + 1) = v50;
        *(_QWORD *)v50 = v38;
      }
      v38 = v40;
      --*((_DWORD *)v131 + 6);
      if ( v40 == (unsigned int *)(v2 + 128) )
        goto LABEL_108;
    }
    if ( !*((_QWORD *)v38 + 17) )
      goto LABEL_98;
LABEL_97:
    cam_mem_put_kref(*(_DWORD *)(v49 + 4328));
    cam_common_mem_free(*((_QWORD *)v38 + 17));
    *((_QWORD *)v38 + 17) = 0;
    goto LABEL_98;
  }
LABEL_108:
  v51 = *(unsigned int **)(v2 + 160);
  if ( v51 == (unsigned int *)(v2 + 160) )
    goto LABEL_171;
  v126 = (unsigned int *)(v2 + 176);
  while ( 1 )
  {
    v52 = *(unsigned int **)v51;
    cam_smmu_buffer_tracker_putref(v51 + 28);
    v53 = *((_QWORD *)v51 + 4);
    if ( *(_DWORD *)(v53 + 72) )
      break;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_handle_error",
      4904,
      "signalled error for req %llu, ctx %u, link 0x%x",
      *((_QWORD *)v51 + 3),
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    if ( *(_DWORD *)(v53 + 32) )
    {
      v54 = 0;
      v55 = 0;
      do
      {
        v56 = *(_QWORD *)(v53 + 24) + v54;
        v57 = *(_DWORD *)(v56 + 16);
        if ( v57 != -1 )
        {
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "__cam_isp_ctx_handle_error",
              4912,
              "req %llu, Sync fd 0x%x ctx %u link 0x%x",
              *((_QWORD *)v51 + 3));
            v57 = *(_DWORD *)(v56 + 16);
          }
          v10 = cam_sync_signal(v57, 3u, v33);
          *(_DWORD *)(v56 + 16) = -1;
        }
        v58 = *(_DWORD *)(v56 + 20);
        if ( v58 >= 1 )
        {
          v10 = cam_sync_signal(v58, 3u, v33);
          if ( v10 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "__cam_isp_ctx_handle_error",
              4929,
              "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
              *(_DWORD *)(v56 + 20),
              *((_QWORD *)v51 + 3),
              v10,
              *(_DWORD *)(v2 + 32),
              *(_DWORD *)(v2 + 64));
          *(_DWORD *)(v56 + 20) = -1;
        }
        ++v55;
        v54 += 64;
      }
      while ( v55 < *(unsigned int *)(v53 + 32) );
    }
    v59 = *((unsigned int ***)v51 + 1);
    if ( *v59 == v51 && (v60 = *(unsigned int **)v51, *(unsigned int **)(*(_QWORD *)v51 + 8LL) == v51) )
    {
      *((_QWORD *)v60 + 1) = v59;
      *v59 = v60;
    }
    else
    {
      _list_del_entry_valid_or_report(v51);
    }
    *(_QWORD *)v51 = v51;
    *((_QWORD *)v51 + 1) = v51;
    v61 = *((_QWORD *)v51 + 4);
    if ( (debug_mdl & 8) == 0 || debug_priority )
    {
      if ( !*((_QWORD *)v51 + 17) )
        goto LABEL_130;
LABEL_129:
      cam_mem_put_kref(*(_DWORD *)(v61 + 4328));
      cam_common_mem_free(*((_QWORD *)v51 + 17));
      *((_QWORD *)v51 + 17) = 0;
      goto LABEL_130;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_move_req_to_free_list",
      1404,
      "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
      *((_QWORD *)v51 + 3),
      *((_QWORD *)v51 + 17),
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    if ( *((_QWORD *)v51 + 17) )
      goto LABEL_129;
LABEL_130:
    v62 = *(unsigned int **)(v2 + 184);
    if ( v126 == v51 || v62 == v51 || *(unsigned int **)v62 != v126 )
    {
      _list_add_valid_or_report(v51);
    }
    else
    {
      *(_QWORD *)(v2 + 184) = v51;
      *(_QWORD *)v51 = v126;
      *((_QWORD *)v51 + 1) = v62;
      *(_QWORD *)v62 = v51;
    }
    v51 = v52;
    if ( v52 == (unsigned int *)(v2 + 160) )
      goto LABEL_171;
  }
  v39 = v131;
  v35 = (unsigned int **)(v2 + 128);
LABEL_141:
  v63 = *(unsigned int ***)(v2 + 136);
  if ( v63 != v35 )
  {
    v64 = (unsigned int ***)(v2 + 144);
    do
    {
      v65 = (unsigned int **)v63[1];
      if ( *v65 == (unsigned int *)v63 && (v66 = *v63, *((unsigned int ***)*v63 + 1) == v63) )
      {
        *((_QWORD *)v66 + 1) = v65;
        *v65 = v66;
      }
      else
      {
        _list_del_entry_valid_or_report(v63);
      }
      *v63 = (unsigned int *)v63;
      v63[1] = (unsigned int *)v63;
      v67 = *v64;
      if ( (*v64)[1] != (unsigned int *)v64 || v63 == (unsigned int **)v64 || v63 == v67 )
      {
        _list_add_valid_or_report(v63);
      }
      else
      {
        v67[1] = (unsigned int *)v63;
        *v63 = (unsigned int *)v67;
        v63[1] = (unsigned int *)v64;
        *v64 = v63;
      }
      v63 = v65;
      --*((_DWORD *)v39 + 6);
    }
    while ( v65 != v35 );
  }
  v68 = *(_QWORD **)(v2 + 168);
  v69 = (_QWORD *)(v2 + 160);
  if ( v68 != (_QWORD *)(v2 + 160) )
  {
    v70 = (_QWORD *)(v2 + 144);
    do
    {
      v71 = (_QWORD *)v68[1];
      if ( (_QWORD *)*v71 == v68 && (v72 = *v68, *(_QWORD **)(*v68 + 8LL) == v68) )
      {
        *(_QWORD *)(v72 + 8) = v71;
        *v71 = v72;
      }
      else
      {
        _list_del_entry_valid_or_report(v68);
      }
      *v68 = v68;
      v68[1] = v68;
      v73 = (_QWORD *)*v70;
      if ( *(_QWORD **)(*v70 + 8LL) != v70 || v68 == v70 || v68 == v73 )
      {
        _list_add_valid_or_report(v68);
      }
      else
      {
        v73[1] = v68;
        *v68 = v73;
        v68[1] = v70;
        *v70 = v68;
      }
      v68 = v71;
    }
    while ( v71 != v69 );
  }
LABEL_171:
  v75 = v131;
  v122 = v121 | v118;
  v129 = (unsigned int *)(v2 + 176);
  v120 = v36 | (v119 >> 4);
  v130 = (unsigned int **)(v2 + 144);
  while ( 2 )
  {
    v76 = *v130;
    if ( *v130 != (unsigned int *)v130 )
    {
      cam_smmu_buffer_tracker_putref(v76 + 28);
      v77 = *((_QWORD *)v76 + 4);
      v78 = v75[7];
      if ( *(_DWORD *)(v77 + 72) )
        goto LABEL_202;
      v127 = v78;
      if ( *(_DWORD *)(v77 + 32) )
      {
        v79 = 0;
        v80 = 0;
        do
        {
          v81 = *(_QWORD *)(v77 + 24);
          v82 = *(_DWORD *)(v81 + v79 + 16);
          if ( v82 != -1 )
          {
            v10 = cam_sync_signal(v82, 3u, v33);
            *(_DWORD *)(*(_QWORD *)(v77 + 24) + v79 + 16) = -1;
            v81 = *(_QWORD *)(v77 + 24);
          }
          v83 = *(_DWORD *)(v81 + v79 + 20);
          if ( v83 >= 1 )
          {
            v10 = cam_sync_signal(v83, 3u, v33);
            if ( v10 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "__cam_isp_ctx_handle_error",
                5005,
                "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
                *(_DWORD *)(*(_QWORD *)(v77 + 24) + v79 + 20),
                *((_QWORD *)v76 + 3),
                v10,
                *(_DWORD *)(v2 + 32),
                *(_DWORD *)(v2 + 64));
            *(_DWORD *)(*(_QWORD *)(v77 + 24) + v79 + 20) = -1;
          }
          ++v80;
          v79 += 64;
        }
        while ( v80 < *(unsigned int *)(v77 + 32) );
      }
      v84 = *((unsigned int ***)v76 + 1);
      if ( *v84 == v76 && (v85 = *(_QWORD *)v76, *(unsigned int **)(*(_QWORD *)v76 + 8LL) == v76) )
      {
        *(_QWORD *)(v85 + 8) = v84;
        *v84 = (unsigned int *)v85;
      }
      else
      {
        _list_del_entry_valid_or_report(v76);
      }
      v75 = v131;
      *(_QWORD *)v76 = v76;
      *((_QWORD *)v76 + 1) = v76;
      v86 = *((_QWORD *)v76 + 4);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_move_req_to_free_list",
          1404,
          "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
          *((_QWORD *)v76 + 3),
          *((_QWORD *)v76 + 17),
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
        if ( *((_QWORD *)v76 + 17) )
        {
LABEL_189:
          cam_mem_put_kref(*(_DWORD *)(v86 + 4328));
          cam_common_mem_free(*((_QWORD *)v76 + 17));
          *((_QWORD *)v76 + 17) = 0;
        }
      }
      else if ( *((_QWORD *)v76 + 17) )
      {
        goto LABEL_189;
      }
      v87 = *(unsigned int **)(v2 + 184);
      if ( v129 == v76 || v87 == v76 || *(unsigned int **)v87 != v129 )
      {
        _list_add_valid_or_report(v76);
      }
      else
      {
        *(_QWORD *)(v2 + 184) = v76;
        *(_QWORD *)v76 = v129;
        *((_QWORD *)v76 + 1) = v87;
        *(_QWORD *)v87 = v76;
      }
      if ( *((_QWORD *)v76 + 3) >= v131[7] )
      {
        v78 = v127;
        goto LABEL_201;
      }
      continue;
    }
    break;
  }
  v78 = v75[7];
LABEL_201:
  v77 = 0;
LABEL_202:
  if ( (*((_BYTE *)v123 + 505) & 1) == 0 )
  {
    if ( v77 && *(_DWORD *)(v77 + 72) )
    {
      v88 = *((_BYTE *)v124 + 16);
      v89 = v125;
      if ( v88 )
        v90 = 1;
      else
        v90 = 2;
      _cam_isp_ctx_notify_error_util(v90, v78, v125);
      if ( (v88 & 1) != 0 )
      {
LABEL_212:
        v91 = debug_mdl;
        *((_DWORD *)v89 + 5) = 5;
        if ( (v91 & 8) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v91 & 8,
            4,
            "__cam_isp_ctx_handle_error",
            5037,
            "Handling error done on ctx: %u, link: 0x%x",
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64));
        goto LABEL_248;
      }
    }
    else
    {
      v89 = v125;
      _cam_isp_ctx_notify_error_util(2, v78, v125);
    }
    _cam_isp_ctx_notify_v4l2_error_event(v117, v120 | v122, v78, (_DWORD *)v2);
    goto LABEL_212;
  }
LABEL_248:
  _ReadStatusReg(SP_EL0);
  return v10;
}
