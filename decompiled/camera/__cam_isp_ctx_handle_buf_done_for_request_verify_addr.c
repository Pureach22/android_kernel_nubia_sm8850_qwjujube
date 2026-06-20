__int64 __fastcall _cam_isp_ctx_handle_buf_done_for_request_verify_addr(
        __int64 matched,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        char a5,
        char a6)
{
  __int64 v6; // x23
  _DWORD *v8; // x8
  __int64 v9; // x24
  unsigned int v10; // w8
  int v11; // w9
  bool v12; // w12
  _DWORD *v13; // x13
  unsigned int v14; // w28
  unsigned int v15; // w20
  __int64 v16; // x22
  char v17; // w8
  unsigned int v18; // w10
  __int64 v19; // x9
  __int64 v20; // x9
  _DWORD *v21; // x25
  int v22; // w0
  int v23; // w8
  const char *v24; // x6
  unsigned int v25; // w26
  _DWORD *v26; // x21
  int v27; // w8
  int v28; // w9
  int v29; // w10
  int v30; // w20
  int *v31; // x12
  int v32; // w13
  char v33; // w20
  const char *v34; // x0
  __int64 v35; // x27
  int *v36; // x9
  __int64 v37; // x7
  int v38; // w9
  char v39; // w9
  int v40; // w8
  __int64 v41; // x1
  _DWORD *v42; // x8
  int v43; // w0
  int v44; // w8
  const char *v45; // x27
  char v46; // w8
  char v47; // w20
  _DWORD *v48; // x8
  char v49; // w20
  __int64 v50; // x8
  unsigned int *v51; // x9
  int v52; // w20
  char v53; // w28
  __int64 v54; // x8
  __int64 v55; // x4
  unsigned int *v56; // x9
  int v57; // w20
  char v58; // w28
  unsigned int *v59; // x28
  const char *v60; // x0
  const char *v61; // x0
  unsigned int *v62; // x28
  const char *v63; // x0
  const char *v64; // x0
  const char *v65; // x5
  __int64 v66; // x6
  __int64 v67; // x7
  int v68; // w9
  int v69; // w8
  __int64 v70; // x4
  __int64 v71; // x9
  int v72; // w10
  unsigned int v73; // w7
  unsigned int v74; // w8
  unsigned int v76; // w0
  unsigned int v77; // w22
  __int64 v78; // x25
  char v79; // w20
  __int64 v80; // [xsp+0h] [xbp-90h]
  unsigned int v81; // [xsp+24h] [xbp-6Ch]
  unsigned int v82; // [xsp+24h] [xbp-6Ch]
  unsigned int v83; // [xsp+24h] [xbp-6Ch]
  unsigned int v84; // [xsp+24h] [xbp-6Ch]
  unsigned int v85; // [xsp+34h] [xbp-5Ch]
  _QWORD *v86; // [xsp+38h] [xbp-58h]
  __int64 v87; // [xsp+40h] [xbp-50h]
  __int64 v88; // [xsp+40h] [xbp-50h]
  __int64 v89; // [xsp+40h] [xbp-50h]
  __int64 v90; // [xsp+40h] [xbp-50h]
  __int64 v92; // [xsp+58h] [xbp-38h]
  _DWORD *v93; // [xsp+60h] [xbp-30h]
  __int128 v94; // [xsp+68h] [xbp-28h] BYREF
  __int64 v95; // [xsp+78h] [xbp-18h]
  __int64 v96; // [xsp+80h] [xbp-10h]
  __int64 v97; // [xsp+88h] [xbp-8h]

  v6 = matched;
  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD **)matched;
  v95 = 0;
  v96 = 0;
  v93 = v8;
  v94 = 0u;
  v9 = *(_QWORD *)(a2 + 32);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v77 = a4;
    v78 = a2;
    v79 = a5;
    matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                2690,
                "Enter with bubble_state %d, req_bubble_detected %d, ctx %u, link[0x%x]",
                a4,
                *(unsigned __int8 *)(v9 + 4504),
                v8[8],
                v8[16]);
    a2 = v78;
    a4 = v77;
    a5 = v79;
  }
  v10 = *(_DWORD *)(v9 + 32);
  v95 = *(_QWORD *)(a3 + 16);
  if ( v10 )
  {
    v11 = 0;
    v12 = 1;
    do
    {
      v13 = (_DWORD *)(*(_QWORD *)(v9 + 24) + ((__int64)v11 << 6));
      if ( *(_DWORD *)(a3 + 4) == *v13 && v13[4] == -1 )
        break;
      v12 = ++v11 < v10;
    }
    while ( v10 != v11 );
    if ( v12 )
    {
      v14 = 0;
      goto LABEL_129;
    }
  }
  if ( (a5 & 1) != 0 )
  {
    v15 = a4;
    v16 = a2;
    matched = _cam_isp_ctx_check_buf_done_match_for_request(v6, v9, a3, *(unsigned __int8 *)(v6 + 45754));
    a2 = v16;
    a4 = v15;
    v17 = matched ^ 1;
  }
  else
  {
    v17 = 0;
  }
  v18 = *(_DWORD *)(a3 + 8);
  v19 = 45672;
  if ( *(_DWORD *)a3 == 7 )
    v19 = 45680;
  v20 = *(_QWORD *)(v6 + v19);
  v21 = (_DWORD *)(v20 + 292LL * v18);
  if ( !v21 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
      2710,
      "comp_grp is NULL");
    v14 = -22;
    goto LABEL_129;
  }
  v92 = a2;
  v85 = a4;
  if ( (v17 & 1) != 0 )
  {
    matched = _cam_isp_context_try_match_buf_done_with_other_ports(
                v6,
                v20 + 292LL * v18,
                a3,
                v9,
                *(unsigned __int8 *)(v6 + 45754));
    v14 = matched;
    if ( (matched & 0x80000000) != 0 )
      goto LABEL_129;
    if ( !(_DWORD)matched )
    {
      v22 = *(_DWORD *)(a3 + 4);
      v86 = (_QWORD *)v6;
      v23 = *(_DWORD *)(v6 + 45580);
      switch ( v23 )
      {
        case 65555:
          goto LABEL_23;
        case 65552:
          if ( (unsigned int)(v22 - 1) > 0xE )
            v24 = "Invalid_Resource_Type";
          else
            v24 = off_4517A8[v22 - 1];
          break;
        case 65538:
LABEL_23:
          v24 = _cam_isp_ife_sfe_resource_handle_id_to_type(v22);
          break;
        default:
          v24 = "INVALID_DEV_TYPE";
          break;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
        2735,
        "BUF_DONE for res %s last_consumed_addr:0x%x not found in Req %lld ",
        v24,
        *(_DWORD *)(a3 + 12),
        *(_QWORD *)(v92 + 24));
      v71 = *(_QWORD *)(a3 + 4);
      v14 = 0;
      v72 = *(_DWORD *)(a3 + 12);
      LODWORD(v94) = *(_DWORD *)a3;
      *(_QWORD *)((char *)&v94 + 4) = v71;
      HIDWORD(v94) = v72;
LABEL_122:
      if ( DWORD1(v94) && (a6 & 1) == 0 )
        _cam_isp_ctx_check_deferred_buf_done(v86, (__int64)&v94, v85);
      v73 = *(_DWORD *)(v9 + 52);
      v74 = *(_DWORD *)(v9 + 32);
      if ( v73 > v74 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
          3018,
          "WARNING: req_id %lld num_acked %d > map_out %d, ctx_idx:%u link[0x%x]",
          *(_QWORD *)(v92 + 24),
          v73,
          *(_DWORD *)(v9 + 32),
          v93[8],
          v93[16]);
        v73 = *(_DWORD *)(v9 + 52);
        v74 = *(_DWORD *)(v9 + 32);
      }
      if ( v73 == v74 )
        v14 = _cam_isp_ctx_handle_buf_done_for_req_list(v86, v92);
      goto LABEL_129;
    }
  }
  else
  {
    v14 = 0;
  }
  v86 = (_QWORD *)v6;
  if ( !*v21 )
    goto LABEL_122;
  v25 = 0;
  v26 = v21 + 1;
  _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    v27 = *(_DWORD *)(v9 + 32);
    if ( !v27 )
      goto LABEL_39;
    if ( v25 > 0x23 )
      goto LABEL_132;
    v28 = v21[v25 + 37];
    v29 = v26[v25];
    v30 = 0;
    while ( 1 )
    {
      v31 = (int *)(*(_QWORD *)(v9 + 24) + ((__int64)v30 << 6));
      v32 = *v31;
      if ( !v28 )
      {
        if ( v29 == v32 )
          break;
        goto LABEL_34;
      }
      if ( v29 == v32 && v28 == v31[1] )
        break;
LABEL_34:
      if ( v27 == ++v30 )
        goto LABEL_39;
    }
    if ( v30 == v27 )
    {
LABEL_39:
      v33 = debug_mdl;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        if ( v25 <= 0x23 )
        {
          v34 = _cam_isp_resource_handle_id_to_type(*(_DWORD *)(v6 + 45580), v26[v25]);
          matched = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      v33 & 8,
                      4,
                      "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                      2769,
                      "BUF_DONE for res %s not active in Req %lld ctx %u, link[0x%x]",
                      v34,
                      *(_QWORD *)(v92 + 24),
                      v93[8],
                      v93[16]);
          goto LABEL_29;
        }
LABEL_132:
        __break(0x5512u);
      }
      goto LABEL_29;
    }
    v35 = v30;
    v36 = (int *)(*(_QWORD *)(v9 + 24) + ((__int64)v30 << 6));
    if ( v36[4] == -1 )
    {
      v43 = *v36;
      v44 = *(_DWORD *)(v6 + 45580);
      if ( v44 == 65555 )
        goto LABEL_61;
      if ( v44 == 65552 )
      {
        v45 = "Invalid_Resource_Type";
        if ( (unsigned int)(v43 - 1) <= 0xE )
          v45 = off_4517A8[v43 - 1];
        goto LABEL_62;
      }
      v45 = "INVALID_DEV_TYPE";
      if ( v44 == 65538 )
LABEL_61:
        v45 = _cam_isp_ife_sfe_resource_handle_id_to_type(v43);
LABEL_62:
      matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  2,
                  "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                  2780,
                  "Duplicate BUF_DONE for req %lld : i=%d, j=%d, res=%s, ctx %u, link[0x%x]",
                  *(_QWORD *)(v92 + 24),
                  v25,
                  v30,
                  v45,
                  v93[8],
                  v93[16]);
      goto LABEL_29;
    }
    matched = cam_presil_mode_enabled(matched);
    if ( (matched & 1) != 0 )
    {
      matched = cam_presil_retrieve_buffers_from_packet(
                  *(unsigned int **)(v9 + 4320),
                  v93[128],
                  *(_DWORD *)(*(_QWORD *)(v9 + 24) + ((__int64)v30 << 6)));
      v14 = matched;
      if ( (_DWORD)matched )
      {
        v65 = "Failed to retrieve image buffers req_id:%d ctx_id:%u link[0x%x] bubble detected:%d rc:%d";
        v66 = *(_QWORD *)(v92 + 24);
        v67 = (unsigned int)v93[8];
        v68 = *(unsigned __int8 *)(v9 + 4504);
        v69 = v93[16];
        v70 = 2795;
        goto LABEL_116;
      }
    }
    if ( (a6 & 1) != 0 )
    {
      v37 = *(unsigned int *)(v9 + 56);
      if ( (_DWORD)v37 )
      {
        v38 = 0;
        while ( *(_DWORD *)(*(_QWORD *)(v9 + 64) + 4LL * v38) != v30 )
        {
          if ( (_DWORD)v37 == ++v38 )
            goto LABEL_52;
        }
        v48 = (_DWORD *)(*(_QWORD *)(v9 + 24) + ((__int64)v30 << 6));
        matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    8,
                    2,
                    "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                    2812,
                    "duplicate deferred ack for ctx[%u] link[0x%x] req %lld res 0x%x sync_id 0x%x",
                    v93[8],
                    v93[16],
                    *(_QWORD *)(v92 + 24),
                    *v48,
                    v48[4]);
      }
      else
      {
LABEL_52:
        if ( (_DWORD)v37 == *(_DWORD *)(v9 + 32) )
        {
          matched = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                      3,
                      8,
                      2,
                      "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                      2825,
                      "WARNING: req_id %lld num_deferred_acks %d > map_out %d, ctx_idx:%u link[0x%x]",
                      *(_QWORD *)(v92 + 24));
          goto LABEL_29;
        }
        *(_DWORD *)(*(_QWORD *)(v9 + 64) + 4 * v37) = v30;
        v39 = debug_mdl;
        v40 = debug_priority;
        v41 = debug_mdl & 8;
        ++*(_DWORD *)(v9 + 56);
        if ( (v39 & 8) != 0 && !v40 )
        {
          matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      v41,
                      4,
                      "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                      2844,
                      "ctx[%u] link[0x%x]:Deferred buf done for %llu with bubble state %d recovery %d",
                      v93[8],
                      v93[16],
                      *(_QWORD *)(v92 + 24),
                      v85,
                      *(_DWORD *)(v9 + 72));
          v40 = debug_priority;
          v41 = debug_mdl & 8;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_29;
        }
        else if ( !v41 )
        {
          goto LABEL_29;
        }
        if ( !v40 )
        {
          v42 = (_DWORD *)(*(_QWORD *)(v9 + 24) + ((__int64)v30 << 6));
          matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      v41,
                      4,
                      "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                      2849,
                      "ctx[%u] link[0x%x]:Deferred info:num_acks=%d,fence_map_index=%d,resource_handle=0x%x,sync_id=%d",
                      v93[8],
                      v93[16],
                      *(_DWORD *)(v9 + 56),
                      v30,
                      *v42,
                      v42[4]);
        }
      }
LABEL_29:
      if ( ++v25 >= *v21 )
        goto LABEL_122;
      continue;
    }
    break;
  }
  if ( (*(_BYTE *)(v9 + 4504) & 1) == 0 )
  {
    v47 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v59 = (unsigned int *)(*(_QWORD *)(v9 + 24) + (v35 << 6));
      v87 = *(_QWORD *)(v92 + 24);
      v81 = *v59;
      v60 = _cam_isp_resource_handle_id_to_type(*(_DWORD *)(v6 + 45580), *v59);
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v47 & 8,
        4,
        "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
        2859,
        "Sync with success: req %lld res 0x%x %s fd 0x%x, ctx:%u link[0x%x]",
        v87,
        v81,
        v60,
        v59[4],
        v93[8],
        v93[16]);
    }
    cam_smmu_buffer_tracker_buffer_putref(*(__int64 **)(*(_QWORD *)(v9 + 24) + (v35 << 6) + 56));
    matched = cam_sync_signal(*(_DWORD *)(*(_QWORD *)(v9 + 24) + (v35 << 6) + 16), 2u, 1u);
    v14 = matched;
    if ( (_DWORD)matched )
    {
      matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                  2871,
                  "Sync=%u for req=%llu failed with rc=%d ctx:%u link[0x%x]",
                  *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v35 << 6) + 16),
                  *(_QWORD *)(v92 + 24),
                  matched,
                  v93[8],
                  v93[16]);
    }
    else if ( *(_DWORD *)(v9 + 56) )
    {
      matched = _cam_isp_handle_deferred_buf_done(v6, v92, 0, 2, 1);
    }
    v50 = *(_QWORD *)(v9 + 24);
    v51 = (unsigned int *)(v50 + (v35 << 6));
    v52 = v51[5];
    if ( v52 >= 1 )
    {
      v53 = debug_mdl;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v82 = *v51;
        v88 = *(_QWORD *)(v92 + 24);
        v61 = _cam_isp_resource_handle_id_to_type(*(_DWORD *)(v6 + 45580), *v51);
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v53 & 8,
          4,
          "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
          2888,
          "Sync with success: req %lld res 0x%x %s early_fd 0x%x, ctx:%u link[0x%x]",
          v88,
          v82,
          v61,
          v52,
          v93[8],
          v93[16]);
        v50 = *(_QWORD *)(v9 + 24);
      }
      matched = cam_sync_signal(*(_DWORD *)(v50 + (v35 << 6) + 20), 2u, 1u);
      v14 = matched;
      if ( !(_DWORD)matched )
        goto LABEL_101;
      v54 = *(_QWORD *)(v9 + 24) + (v35 << 6);
      v55 = 2896;
      goto LABEL_100;
    }
LABEL_102:
    *(_DWORD *)(v50 + (v35 << 6) + 16) = -1;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                  2994,
                  "req %lld, reset sync id 0x%x ctx_idx:%u link[0x%x]",
                  *(_QWORD *)(v92 + 24),
                  *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v35 << 6) + 16),
                  v93[8],
                  v93[16]);
      if ( v14 )
        goto LABEL_106;
    }
    else if ( v14 )
    {
LABEL_106:
      if ( *(_BYTE *)(v6 + 45744) == 1 && *(_DWORD *)(v9 + 112) == *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v35 << 6)) )
        matched = _cam_isp_ctx_send_sof_timestamp_frame_header(v6, *(_QWORD *)(v9 + 96), *(_QWORD *)(v92 + 24));
      goto LABEL_29;
    }
    ++*(_DWORD *)(v9 + 52);
    goto LABEL_106;
  }
  if ( !*(_DWORD *)(v9 + 72) )
  {
    v49 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v62 = (unsigned int *)(*(_QWORD *)(v9 + 24) + (v35 << 6));
      v89 = *(_QWORD *)(v92 + 24);
      v83 = *v62;
      v63 = _cam_isp_resource_handle_id_to_type(*(_DWORD *)(v6 + 45580), *v62);
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v49 & 8,
        4,
        "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
        2913,
        "Sync with failure: req %lld res 0x%x %s fd 0x%x, ctx:%u link[0x%x]",
        v89,
        v83,
        v63,
        v62[4],
        v93[8],
        v93[16]);
    }
    cam_smmu_buffer_tracker_buffer_putref(*(__int64 **)(*(_QWORD *)(v9 + 24) + (v35 << 6) + 56));
    matched = cam_sync_signal(*(_DWORD *)(*(_QWORD *)(v9 + 24) + (v35 << 6) + 16), 3u, 0x34u);
    v14 = matched;
    if ( (_DWORD)matched )
    {
      matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                  2925,
                  "Sync:%u for req:%llu failed with rc:%d,ctx:%u,link[0x%x]",
                  *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v35 << 6) + 16),
                  *(_QWORD *)(v92 + 24),
                  matched,
                  v93[8],
                  v93[16]);
    }
    else if ( *(_DWORD *)(v9 + 56) )
    {
      matched = _cam_isp_handle_deferred_buf_done(v6, v92, 0, 3, 52);
    }
    v50 = *(_QWORD *)(v9 + 24);
    v56 = (unsigned int *)(v50 + (v35 << 6));
    v57 = v56[5];
    if ( v57 >= 1 )
    {
      v58 = debug_mdl;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v84 = *v56;
        v90 = *(_QWORD *)(v92 + 24);
        v64 = _cam_isp_resource_handle_id_to_type(*(_DWORD *)(v6 + 45580), *v56);
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v58 & 8,
          4,
          "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
          2942,
          "Sync with failure: req %lld res 0x%x %s early_fd 0x%x, ctx:%u link[0x%x]",
          v90,
          v84,
          v64,
          v57,
          v93[8],
          v93[16]);
        v50 = *(_QWORD *)(v9 + 24);
      }
      matched = cam_sync_signal(*(_DWORD *)(v50 + (v35 << 6) + 20), 3u, 0x34u);
      v14 = matched;
      if ( !(_DWORD)matched )
        goto LABEL_101;
      v54 = *(_QWORD *)(v9 + 24) + (v35 << 6);
      v55 = 2950;
LABEL_100:
      matched = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                  v55,
                  "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
                  *(_DWORD *)(v54 + 20),
                  *(_QWORD *)(v92 + 24),
                  v14,
                  v93[8],
                  v93[16]);
LABEL_101:
      *(_DWORD *)(*(_QWORD *)(v9 + 24) + (v35 << 6) + 20) = -1;
      v50 = *(_QWORD *)(v9 + 24);
      goto LABEL_102;
    }
    goto LABEL_102;
  }
  v46 = debug_mdl;
  ++*(_DWORD *)(v9 + 52);
  if ( (v46 & 8) != 0 && !debug_priority )
  {
    v80 = *(_QWORD *)(v92 + 24);
    matched = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                v46 & 8,
                4,
                "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
                2971,
                "buf done with bubble state %d recovery %d for req %lld, ctx_idx:%u link[0x%x]",
                v85);
    if ( *(_DWORD *)(v9 + 56) )
LABEL_68:
      matched = _cam_isp_handle_deferred_buf_done(v6, v92, 1, 3, 52);
  }
  else if ( *(_DWORD *)(v9 + 56) )
  {
    goto LABEL_68;
  }
  if ( *(_DWORD *)(v9 + 52) != *(_DWORD *)(v9 + 32) )
    goto LABEL_29;
  v76 = _cam_isp_ctx_handle_buf_done_for_req_list(v6, v92);
  v14 = v76;
  if ( v76 )
  {
    v66 = *(_QWORD *)(v92 + 24);
    v65 = "Error in buf done for req = %llu with rc = %d, ctx_idx:%u link[0x%x]";
    v69 = v93[8];
    v68 = v93[16];
    v70 = 2985;
    v67 = v76;
LABEL_116:
    LODWORD(v80) = v69;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, int))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_handle_buf_done_for_request_verify_addr",
      v70,
      v65,
      v66,
      v67,
      v80,
      v68);
  }
LABEL_129:
  _ReadStatusReg(SP_EL0);
  return v14;
}
