__int64 __fastcall _cam_isp_ctx_handle_buf_done_for_request(
        __int64 buffers_from_packet,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v7; // x25
  int v8; // w8
  int i; // w10
  _BYTE *v10; // x22
  __int64 v11; // x9
  _DWORD *v12; // x21
  __int64 v13; // x9
  __int64 v14; // x12
  __int64 v15; // x13
  int v16; // w13
  int v17; // w14
  int v18; // w8
  __int64 v19; // x19
  const char *v20; // x6
  unsigned int v21; // w24
  unsigned int v22; // w27
  _DWORD *v23; // x19
  int v24; // w8
  int v25; // w9
  int v26; // w11
  int v27; // w26
  int v28; // w10
  int *v29; // x13
  int v30; // w14
  char v31; // w26
  const char *v32; // x0
  int *v33; // x9
  int v34; // w7
  const char *v35; // x12
  char v36; // w27
  __int64 v37; // x8
  __int64 v38; // x1
  __int64 v39; // x7
  int v40; // w9
  __int64 v41; // x4
  int v42; // w0
  int v43; // w8
  const char *v44; // x28
  char v45; // w27
  __int64 v46; // x8
  const char *v47; // x5
  char v48; // w8
  __int64 v49; // x8
  __int64 v50; // x9
  int v51; // w9
  int v52; // w10
  const char *v53; // x7
  unsigned int *v54; // x28
  const char *v55; // x0
  const char *v56; // x13
  unsigned int v57; // w9
  unsigned int v58; // w10
  unsigned int *v59; // x28
  const char *v60; // x0
  const char *v61; // x13
  unsigned int v62; // w9
  unsigned int v63; // w10
  unsigned int v64; // w7
  unsigned int v65; // w8
  __int64 v66; // x0
  int v67; // w0
  int v68; // w8
  const char *v69; // x6
  int v71; // w21
  __int64 v72; // x20
  __int64 v73; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v75; // x21
  int v76; // w22
  __int64 v77; // x20
  __int64 v78; // x8
  unsigned int v79; // [xsp+34h] [xbp-4Ch]
  unsigned int v80; // [xsp+34h] [xbp-4Ch]
  __int64 v81; // [xsp+38h] [xbp-48h]
  __int64 v82; // [xsp+38h] [xbp-48h]
  __int64 v83; // [xsp+48h] [xbp-38h]
  __int64 v84; // [xsp+50h] [xbp-30h]
  int v85; // [xsp+5Ch] [xbp-24h]
  __int64 *v86; // [xsp+60h] [xbp-20h]
  _DWORD *v87; // [xsp+68h] [xbp-18h]
  __int64 v88; // [xsp+70h] [xbp-10h]

  v87 = *(_DWORD **)buffers_from_packet;
  while ( 1 )
  {
    v7 = *(_QWORD *)(a2 + 32);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v71 = a4;
      v72 = buffers_from_packet;
      v73 = a5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_handle_buf_done_for_request",
        2117,
        "Enter with bubble_state %d, req_bubble_detected %d, ctx %u link: 0x%x",
        a4,
        *(unsigned __int8 *)(v7 + 4504),
        v87[8],
        v87[16]);
      LODWORD(a4) = v71;
      buffers_from_packet = v72;
      a5 = v73;
    }
    *(_DWORD *)(a5 + 4) = 0;
    v88 = buffers_from_packet + 45056;
    v85 = a4;
    *(_QWORD *)(a5 + 16) = *(_QWORD *)(a3 + 16);
    v8 = *(_DWORD *)(v7 + 32);
    if ( v8 )
    {
      for ( i = 0; i != v8; ++i )
      {
        if ( *(_DWORD *)(a3 + 4) == *(_DWORD *)(*(_QWORD *)(v7 + 24) + ((__int64)i << 6)) )
          goto LABEL_11;
      }
      v10 = (_BYTE *)(a3 + 24);
      i = *(_DWORD *)(v7 + 32);
      goto LABEL_14;
    }
    i = 0;
LABEL_11:
    v10 = (_BYTE *)(a3 + 24);
    if ( i != v8 && (*(_BYTE *)(a3 + 24) & 1) != 0 && *(int *)(*(_QWORD *)(v7 + 24) + ((__int64)i << 6) + 20) <= 0 )
    {
      v67 = *(_DWORD *)(a3 + 4);
      v68 = *(_DWORD *)(v88 + 524);
      switch ( v68 )
      {
        case 65555:
          goto LABEL_132;
        case 65552:
          if ( (unsigned int)(v67 - 1) > 0xE )
            v69 = "Invalid_Resource_Type";
          else
            v69 = off_4517A8[v67 - 1];
          break;
        case 65538:
LABEL_132:
          v69 = _cam_isp_ife_sfe_resource_handle_id_to_type(v67);
          break;
        default:
          v69 = "INVALID_DEV_TYPE";
          break;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_handle_buf_done_for_request",
        2133,
        "Early done already handled for res:%s Req %lld, ignoring",
        v69,
        *(_QWORD *)(a2 + 24));
      return 0;
    }
LABEL_14:
    v86 = (__int64 *)buffers_from_packet;
    v11 = 45672;
    if ( *(_DWORD *)a3 == 7 )
      v11 = 45680;
    v12 = (_DWORD *)(*(_QWORD *)(buffers_from_packet + v11) + 292LL * *(unsigned int *)(a3 + 8));
    if ( !v12 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_handle_buf_done_for_request",
        2143,
        "comp_grp is NULL");
      return (unsigned int)-22;
    }
    v13 = (unsigned int)*v12;
    if ( i != v8 )
      goto LABEL_36;
    if ( !(_DWORD)v13 )
    {
LABEL_122:
      v22 = 0;
      goto LABEL_123;
    }
    buffers_from_packet = *(unsigned int *)(a3 + 4);
    v14 = 0;
    while ( 1 )
    {
      v16 = v12[v14 + 1];
      if ( v16 == (_DWORD)buffers_from_packet )
      {
        v15 = v14 + 1;
        if ( v14 + 1 == v13 )
          goto LABEL_36;
        goto LABEL_21;
      }
      if ( v8 )
      {
        v17 = 0;
        while ( v16 != *(_DWORD *)(*(_QWORD *)(v7 + 24) + ((__int64)v17 << 6)) )
        {
          if ( v8 == ++v17 )
            goto LABEL_30;
        }
      }
      else
      {
        v17 = 0;
      }
      if ( v17 != v8 )
        goto LABEL_36;
LABEL_30:
      v15 = v14 + 1;
      if ( v14 + 1 == v13 )
        break;
LABEL_21:
      v14 = v15;
      if ( v15 == 36 )
        goto LABEL_145;
    }
    if ( v14 == (_DWORD)v13 - 1 )
    {
      v18 = *(_DWORD *)(v88 + 524);
      switch ( v18 )
      {
        case 65555:
          goto LABEL_35;
        case 65552:
          v19 = a5;
          if ( (unsigned int)(buffers_from_packet - 1) > 0xE )
            v20 = "Invalid_Resource_Type";
          else
            v20 = off_4517A8[(unsigned int)(buffers_from_packet - 1)];
          break;
        case 65538:
LABEL_35:
          v19 = a5;
          v20 = _cam_isp_ife_sfe_resource_handle_id_to_type(buffers_from_packet);
          break;
        default:
          v19 = a5;
          v20 = "INVALID_DEV_TYPE";
          break;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_handle_buf_done_for_request",
        2186,
        "BUF_DONE for res %s not found in Req %lld ",
        v20,
        *(_QWORD *)(a2 + 24));
      v22 = 0;
      *(_DWORD *)v19 = *(_DWORD *)a3;
      *(_DWORD *)(v19 + 4) = *(_DWORD *)(a3 + 4);
      *(_DWORD *)(v19 + 8) = *(_DWORD *)(a3 + 8);
      *(_BYTE *)(v19 + 24) = *(_BYTE *)(a3 + 24);
LABEL_123:
      v64 = *(_DWORD *)(v7 + 52);
      v65 = *(_DWORD *)(v7 + 32);
      if ( v64 <= v65 )
      {
        v66 = (__int64)v86;
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "__cam_isp_ctx_handle_buf_done_for_request",
          2371,
          "WARNING: req_id %lld num_acked %d > map_out %d, ctx %u link: 0x%x",
          *(_QWORD *)(a2 + 24));
        v64 = *(_DWORD *)(v7 + 52);
        v65 = *(_DWORD *)(v7 + 32);
        v66 = (__int64)v86;
        if ( v64 > v65 )
        {
          __break(0x800u);
          v64 = *(_DWORD *)(v7 + 52);
          v65 = *(_DWORD *)(v7 + 32);
        }
      }
      if ( v64 == v65 )
        return (unsigned int)_cam_isp_ctx_handle_buf_done_for_req_list(v66, (unsigned int *)a2);
      return v22;
    }
LABEL_36:
    if ( !(_DWORD)v13 )
      goto LABEL_122;
    v21 = 0;
    v22 = 0;
    v23 = v12 + 1;
    v83 = a3;
    v84 = a2;
    _ReadStatusReg(SP_EL0);
LABEL_39:
    v24 = (unsigned __int8)*v10;
    if ( v24 == 1 )
    {
      if ( v21 > 0x23 )
        goto LABEL_145;
      if ( *(_DWORD *)(a3 + 4) != v23[v21] )
        goto LABEL_38;
    }
    v25 = *(_DWORD *)(v7 + 32);
    if ( !v25 )
      goto LABEL_51;
    if ( v21 <= 0x23 )
      break;
LABEL_145:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v75 = buffers_from_packet;
      v76 = a4;
      v77 = a5;
      ++*(_DWORD *)(StatusReg + 16);
      buffers_from_packet = _traceiter_cam_buf_done(0, (__int64)"ISP", (__int64)v87, a2);
      v78 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v78;
      if ( !v78 || (LODWORD(a4) = v76, buffers_from_packet = v75, a5 = v77, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(buffers_from_packet);
        LODWORD(a4) = v76;
        buffers_from_packet = v75;
        a5 = v77;
      }
    }
  }
  v26 = v23[v21];
  v27 = 0;
  v28 = v12[v21 + 37];
  while ( 1 )
  {
    v29 = (int *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6));
    v30 = *v29;
    if ( v28 )
      break;
    if ( v26 == v30 )
      goto LABEL_50;
LABEL_46:
    if ( v25 == ++v27 )
      goto LABEL_51;
  }
  if ( v26 != v30 || v28 != v29[1] )
    goto LABEL_46;
LABEL_50:
  if ( v27 == v25 )
  {
LABEL_51:
    v31 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      if ( v21 <= 0x23 )
      {
        v32 = _cam_isp_resource_handle_id_to_type(*(_DWORD *)(v88 + 524), v23[v21]);
        buffers_from_packet = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                3,
                                v31 & 8,
                                4,
                                "__cam_isp_ctx_handle_buf_done_for_request",
                                2228,
                                "BUF_DONE for res %s not active in Req %lld ctx %u link: 0x%x",
                                v32,
                                *(_QWORD *)(a2 + 24),
                                v87[8],
                                v87[16]);
        goto LABEL_38;
      }
      goto LABEL_145;
    }
LABEL_38:
    if ( ++v21 >= *v12 )
      goto LABEL_123;
    goto LABEL_39;
  }
  if ( (v24 & 1) == 0 )
  {
    v33 = (int *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6));
    if ( v33[4] == -1 )
    {
      v42 = *v33;
      v43 = *(_DWORD *)(v88 + 524);
      if ( v43 == 65555 )
        goto LABEL_83;
      if ( v43 == 65552 )
      {
        v44 = "Invalid_Resource_Type";
        if ( (unsigned int)(v42 - 1) <= 0xE )
          v44 = off_4517A8[v42 - 1];
        goto LABEL_84;
      }
      v44 = "INVALID_DEV_TYPE";
      if ( v43 == 65538 )
LABEL_83:
        v44 = _cam_isp_ife_sfe_resource_handle_id_to_type(v42);
LABEL_84:
      buffers_from_packet = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                              3,
                              8,
                              2,
                              "__cam_isp_ctx_handle_buf_done_for_request",
                              2240,
                              "Duplicate BUF_DONE for req %lld : i=%d, j=%d, res=%s, ctx %u link: 0x%x",
                              *(_QWORD *)(v84 + 24),
                              v21,
                              v27,
                              v44,
                              v87[8],
                              v87[16]);
      a4 = *(_QWORD *)(v84 + 24);
      a5 = (unsigned int)v87[8];
      a3 = v83;
      a2 = v84;
      goto LABEL_38;
    }
  }
  buffers_from_packet = cam_presil_mode_enabled(buffers_from_packet);
  if ( (buffers_from_packet & 1) == 0
    || (buffers_from_packet = cam_presil_retrieve_buffers_from_packet(
                                *(unsigned int **)(v7 + 4320),
                                v87[128],
                                *(_DWORD *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6))),
        (v22 = buffers_from_packet) == 0) )
  {
    if ( (*(_BYTE *)(v7 + 4504) & 1) != 0 )
    {
      v34 = *(_DWORD *)(v7 + 72);
      if ( v34 )
      {
        if ( (*v10 & 1) == 0 )
          ++*(_DWORD *)(v7 + 52);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v35 = "N";
          if ( *v10 )
            v35 = "Y";
          buffers_from_packet = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                  3,
                                  debug_mdl & 8,
                                  4,
                                  "__cam_isp_ctx_handle_buf_done_for_request",
                                  2339,
                                  "buf done with bubble state %d recovery %d for req %lld is_early:%s, ctx %u link: 0x%x",
                                  v85,
                                  v34,
                                  *(_QWORD *)(a2 + 24),
                                  v35,
                                  v87[8],
                                  v87[16]);
        }
        goto LABEL_38;
      }
      v45 = debug_mdl;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v59 = (unsigned int *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6));
        v82 = *(_QWORD *)(v84 + 24);
        v80 = *v59;
        v60 = _cam_isp_resource_handle_id_to_type(*(_DWORD *)(v88 + 524), *v59);
        v61 = "N";
        v62 = v59[4];
        v63 = v59[5];
        a2 = v84;
        if ( *v10 )
          v61 = "Y";
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v45 & 8,
          4,
          "__cam_isp_ctx_handle_buf_done_for_request",
          2302,
          "Sync with failure: req %lld res 0x%x %s is_early:%s fd 0x%x early_fd %d, ctx %u link: 0x%x",
          v82,
          v80,
          v60,
          v61,
          v62,
          v63,
          v87[8],
          v87[16]);
      }
      v46 = *(_QWORD *)(v7 + 24);
      if ( *v10 == 1 )
      {
        buffers_from_packet = cam_sync_signal(*(_DWORD *)(v46 + ((__int64)v27 << 6) + 20), 3u, 0x34u);
        v22 = buffers_from_packet;
        if ( (_DWORD)buffers_from_packet && (debug_mdl & 8) != 0 && !debug_priority )
        {
          v38 = debug_mdl & 8;
          v39 = (unsigned int)v87[8];
          v40 = v87[16];
          v41 = 2311;
LABEL_92:
          v47 = "Early Sync failed with rc = %d, ctx %u link: 0x%x";
LABEL_119:
          buffers_from_packet = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int))cam_print_log)(
                                  3,
                                  v38,
                                  4,
                                  "__cam_isp_ctx_handle_buf_done_for_request",
                                  v41,
                                  v47,
                                  v22,
                                  v39,
                                  v40);
          v48 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
          {
LABEL_98:
            if ( !v22 )
            {
              if ( *v10 == 1 )
              {
                *(_DWORD *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6) + 20) = -1;
              }
              else
              {
                v49 = *(_QWORD *)(v7 + 24) + ((__int64)v27 << 6);
                ++*(_DWORD *)(v7 + 52);
                *(_DWORD *)(v49 + 16) = -1;
              }
            }
            if ( *(_BYTE *)(v88 + 688) == 1
              && *(_DWORD *)(v7 + 112) == *(_DWORD *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6)) )
            {
              buffers_from_packet = _cam_isp_ctx_send_sof_timestamp_frame_header(
                                      v86,
                                      *(unsigned int **)(v7 + 96),
                                      *(_QWORD *)(a2 + 24));
            }
            goto LABEL_38;
          }
LABEL_97:
          if ( !debug_priority )
          {
            v50 = *(_QWORD *)(v7 + 24) + ((__int64)v27 << 6);
            v52 = *(_DWORD *)(v50 + 16);
            v51 = *(_DWORD *)(v50 + 20);
            if ( *v10 )
              v53 = "Y";
            else
              v53 = "N";
            buffers_from_packet = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                    3,
                                    v48 & 8,
                                    4,
                                    "__cam_isp_ctx_handle_buf_done_for_request",
                                    2347,
                                    "req %lld, is_early:%s reset sync id 0x%x early_fd %d ctx %u link: 0x%x",
                                    *(_QWORD *)(a2 + 24),
                                    v53,
                                    v52,
                                    v51,
                                    v87[8],
                                    v87[16]);
          }
          goto LABEL_98;
        }
LABEL_96:
        v48 = debug_mdl;
        if ( (debug_mdl & 8) == 0 )
          goto LABEL_98;
        goto LABEL_97;
      }
      cam_smmu_buffer_tracker_buffer_putref(*(__int64 **)(v46 + ((__int64)v27 << 6) + 56));
      buffers_from_packet = cam_sync_signal(*(_DWORD *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6) + 16), 3u, 0x34u);
      v22 = buffers_from_packet;
      if ( !(_DWORD)buffers_from_packet || (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_96;
      v38 = debug_mdl & 8;
      v39 = (unsigned int)v87[8];
      v40 = v87[16];
      v41 = 2321;
    }
    else
    {
      v36 = debug_mdl;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v54 = (unsigned int *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6));
        v81 = *(_QWORD *)(v84 + 24);
        v79 = *v54;
        v55 = _cam_isp_resource_handle_id_to_type(*(_DWORD *)(v88 + 524), *v54);
        v56 = "N";
        v57 = v54[4];
        v58 = v54[5];
        a2 = v84;
        if ( *v10 )
          v56 = "Y";
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v36 & 8,
          4,
          "__cam_isp_ctx_handle_buf_done_for_request",
          2270,
          "Sync with success: req %lld res 0x%x %s is_early:%s fd 0x%x early_fd %d, ctx %u link: 0x%x",
          v81,
          v79,
          v55,
          v56,
          v57,
          v58,
          v87[8],
          v87[16]);
      }
      v37 = *(_QWORD *)(v7 + 24);
      if ( *v10 == 1 )
      {
        buffers_from_packet = cam_sync_signal(*(_DWORD *)(v37 + ((__int64)v27 << 6) + 20), 2u, 1u);
        v22 = buffers_from_packet;
        if ( (_DWORD)buffers_from_packet && (debug_mdl & 8) != 0 && !debug_priority )
        {
          v38 = debug_mdl & 8;
          v39 = (unsigned int)v87[8];
          v40 = v87[16];
          v41 = 2279;
          goto LABEL_92;
        }
        goto LABEL_96;
      }
      cam_smmu_buffer_tracker_buffer_putref(*(__int64 **)(v37 + ((__int64)v27 << 6) + 56));
      buffers_from_packet = cam_sync_signal(*(_DWORD *)(*(_QWORD *)(v7 + 24) + ((__int64)v27 << 6) + 16), 2u, 1u);
      v22 = buffers_from_packet;
      if ( !(_DWORD)buffers_from_packet || (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_96;
      v38 = debug_mdl & 8;
      v39 = (unsigned int)v87[8];
      v40 = v87[16];
      v41 = 2290;
    }
    v47 = "Sync failed with rc = %d, ctx %u link: 0x%x";
    goto LABEL_119;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "__cam_isp_ctx_handle_buf_done_for_request",
    2255,
    "Failed to retrieve image buffers req_id:%d ctx_id:%u link: 0x%x bubble detected:%d rc:%d",
    *(_QWORD *)(a2 + 24),
    v87[8],
    v87[16],
    *(unsigned __int8 *)(v7 + 4504),
    buffers_from_packet);
  return v22;
}
