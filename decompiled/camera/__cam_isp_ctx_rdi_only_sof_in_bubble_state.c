__int64 __fastcall _cam_isp_ctx_rdi_only_sof_in_bubble_state(__int64 a1, __int64 *a2)
{
  __int64 v2; // x28
  __int64 v3; // x25
  __int64 v4; // x7
  _QWORD *v5; // x27
  __int64 v6; // x20
  __int64 v7; // x7
  __int64 result; // x0
  __int64 v9; // x19
  __int64 v10; // x22
  __int64 v11; // x8
  __int64 *v12; // x10
  __int64 v13; // x23
  __int64 (__fastcall *v14)(__int64, __int64 *); // x8
  __int64 v15; // x0
  unsigned int v16; // w0
  unsigned int v17; // w19
  unsigned __int64 v18; // x21
  unsigned __int64 v19; // x6
  int v20; // w7
  __int64 v21; // x19
  unsigned int *v22; // x22
  unsigned int *v23; // x24
  unsigned int **v24; // x8
  __int64 v25; // x9
  __int64 v26; // x19
  _QWORD *v27; // x21
  unsigned __int64 v28; // x25
  __int64 v29; // x27
  __int64 v30; // x8
  unsigned int v31; // w0
  signed int v32; // w0
  int v33; // w0
  __int64 v34; // x19
  unsigned int *v35; // x1
  __int64 v36; // x19
  const char *v37; // x0
  __int64 v38; // [xsp+20h] [xbp-A0h]
  __int64 v39; // [xsp+28h] [xbp-98h]
  unsigned int **v40; // [xsp+30h] [xbp-90h]
  _QWORD v41[2]; // [xsp+38h] [xbp-88h] BYREF
  __int64 v42; // [xsp+48h] [xbp-78h]
  __int64 v43; // [xsp+50h] [xbp-70h]
  __int64 v44; // [xsp+58h] [xbp-68h]
  __int64 v45; // [xsp+60h] [xbp-60h]
  __int64 v46; // [xsp+68h] [xbp-58h]
  __int64 v47; // [xsp+70h] [xbp-50h]
  __int64 v48; // [xsp+78h] [xbp-48h]
  __int64 v49; // [xsp+80h] [xbp-40h]
  __int64 v50; // [xsp+88h] [xbp-38h]
  __int64 v51; // [xsp+90h] [xbp-30h]
  __int64 v52; // [xsp+98h] [xbp-28h] BYREF
  __int64 v53; // [xsp+A0h] [xbp-20h]
  _QWORD *v54; // [xsp+A8h] [xbp-18h]
  __int64 v55; // [xsp+B0h] [xbp-10h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v53 = 0;
  v54 = nullptr;
  v52 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v41[0] = 0;
  v41[1] = 0;
  if ( !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
      7237,
      "in valid sof event data, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    result = 4294967274LL;
    goto LABEL_69;
  }
  v3 = a1 + 36864;
  v4 = *(_QWORD *)(a1 + 37304);
  if ( v4 != *a2 )
  {
    ++*(_QWORD *)(a1 + 8);
    v4 = *a2;
    *(_QWORD *)(a1 + 37304) = *a2;
    *(_QWORD *)(a1 + 37312) = a2[1];
  }
  v5 = &unk_393000;
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( *(_DWORD *)(a1 + 24) )
      goto LABEL_7;
LABEL_32:
    v38 = a1;
    v22 = *(unsigned int **)(v2 + 128);
    v40 = (unsigned int **)(v2 + 128);
    if ( v22 == (unsigned int *)(v2 + 128) )
      goto LABEL_62;
    v23 = (unsigned int *)(v2 + 176);
    v39 = v3;
    while ( 1 )
    {
      v24 = *((unsigned int ***)v22 + 1);
      if ( *v24 == v22 && (v25 = *(_QWORD *)v22, *(unsigned int **)(*(_QWORD *)v22 + 8LL) == v22) )
      {
        *(_QWORD *)(v25 + 8) = v24;
        *v24 = (unsigned int *)v25;
      }
      else
      {
        _list_del_entry_valid_or_report(v22);
      }
      *(_QWORD *)v22 = v22;
      *((_QWORD *)v22 + 1) = v22;
      cam_smmu_buffer_tracker_putref(v22 + 28);
      v26 = *((_QWORD *)v22 + 4);
      v27 = v5;
      if ( (v5[458] & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v5[458] & 8LL,
          4,
          "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
          7334,
          "signal fence in active list. fence num %d, ctx %u link: 0x%x",
          *(_DWORD *)(v26 + 32),
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
        if ( *(_DWORD *)(v26 + 32) )
        {
LABEL_40:
          v28 = 0;
          v29 = 20;
          do
          {
            v30 = *(_QWORD *)(v26 + 24);
            v31 = *(_DWORD *)(v30 + v29 - 4);
            if ( v31 != -1 )
            {
              cam_sync_signal(v31, 3u, 0x34u);
              v30 = *(_QWORD *)(v26 + 24);
            }
            v32 = *(_DWORD *)(v30 + v29);
            if ( v32 >= 1 )
            {
              v33 = cam_sync_signal(v32, 3u, 0x34u);
              if ( v33 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
                  7353,
                  "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
                  *(_DWORD *)(*(_QWORD *)(v26 + 24) + v29),
                  *((_QWORD *)v22 + 3),
                  v33,
                  *(_DWORD *)(v2 + 32),
                  *(_DWORD *)(v2 + 64));
              *(_DWORD *)(*(_QWORD *)(v26 + 24) + v29) = -1;
            }
            ++v28;
            v29 += 64;
          }
          while ( v28 < *(unsigned int *)(v26 + 32) );
        }
      }
      else if ( *(_DWORD *)(v26 + 32) )
      {
        goto LABEL_40;
      }
      v34 = *((_QWORD *)v22 + 4);
      v5 = v27;
      if ( (v27[458] & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v27[458] & 8LL,
          4,
          "__cam_isp_ctx_move_req_to_free_list",
          1404,
          "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
          *((_QWORD *)v22 + 3),
          *((_QWORD *)v22 + 17),
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
      v3 = v39;
      if ( *((_QWORD *)v22 + 17) )
      {
        cam_mem_put_kref(*(_DWORD *)(v34 + 4328));
        cam_common_mem_free(*((_QWORD *)v22 + 17));
        *((_QWORD *)v22 + 17) = 0;
      }
      v35 = *(unsigned int **)(v2 + 184);
      if ( v23 == v22 || v35 == v22 || *(unsigned int **)v35 != v23 )
      {
        _list_add_valid_or_report(v22);
      }
      else
      {
        *(_QWORD *)(v2 + 184) = v22;
        *(_QWORD *)v22 = v23;
        *((_QWORD *)v22 + 1) = v35;
        *(_QWORD *)v35 = v22;
      }
      --*(_DWORD *)(v39 + 456);
      v22 = *v40;
      if ( *v40 == (unsigned int *)v40 )
        goto LABEL_62;
    }
  }
  v21 = a1;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
    7243,
    "frame id: %lld time stamp:0x%llx, ctx_idx: %u, link: 0x%x",
    *(_QWORD *)(a1 + 8),
    v4,
    *(_DWORD *)(v2 + 32),
    *(_DWORD *)(v2 + 64));
  a1 = v21;
  if ( !*(_DWORD *)(v21 + 24) )
    goto LABEL_32;
LABEL_7:
  v6 = *(_QWORD *)(v2 + 128);
  if ( v6 == v2 + 128 )
  {
    v9 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
      7249,
      "No available active req in bubble, ctx: %u, link: 0x%x",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    *(_DWORD *)(v9 + 24) = 0;
    result = 4294967274LL;
    goto LABEL_69;
  }
  v7 = *(_QWORD *)(v3 + 504);
  if ( v7 == *(_QWORD *)(v3 + 440) )
  {
    v38 = a1;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
        7260,
        "Tasklet delay detected! Bubble frame: %lld check skipped, sof_timestamp: %lld, ctx_id: %u, link: 0x%x",
        *(_QWORD *)(a1 + 8),
        v7,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    goto LABEL_62;
  }
  v10 = *(_QWORD *)(v6 + 32);
  if ( *(_BYTE *)(v10 + 4504) != 1 )
    goto LABEL_32;
  v11 = *(_QWORD *)(v3 + 432);
  v12 = *(__int64 **)(v2 + 208);
  LODWORD(v41[0]) = 6;
  v13 = a1;
  LODWORD(v53) = 0;
  v52 = v11;
  v14 = (__int64 (__fastcall *)(__int64, __int64 *))v12[12];
  v54 = v41;
  v15 = *v12;
  if ( *((_DWORD *)v14 - 1) != 1863972096 )
    __break(0x8228u);
  v16 = v14(v15, &v52);
  if ( !v16 )
  {
    v18 = v42;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
        7285,
        "last_cdm_done req: %d ctx_id: %u, link: 0x%x",
        v42,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    v19 = *(_QWORD *)(v6 + 24);
    v38 = v13;
    if ( v18 >= v19 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
          7290,
          "CDM callback detected for req: %lld, possible buf_done delay, waiting for buf_done, ctx_id: %u, link: 0x%x",
          v19,
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
      if ( *(_DWORD *)(v10 + 32) == *(_DWORD *)(v10 + 56) )
      {
        _cam_isp_handle_deferred_buf_done((__int64 *)v13, v6, 1, 3u, 0x34u);
        _cam_isp_ctx_handle_buf_done_for_req_list(v13, (unsigned int *)v6);
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
        7305,
        "CDM callback not happened for req: %lld, possible CDM stuck or workqueue delay, ctx_id: %u, link: 0x%x",
        v19,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      *(_QWORD *)(v10 + 52) = 0;
      *(_WORD *)(v10 + 4504) = 256;
      _list_del_entry((_QWORD *)v6);
      *(_QWORD *)v6 = v6;
      *(_QWORD *)(v6 + 8) = v6;
      _list_add((_QWORD *)v6, (_QWORD *)(v2 + 144), *(_QWORD *)(v2 + 144));
      *(_DWORD *)(v13 + 24) = 0;
      v20 = *(_DWORD *)(v3 + 456) - 1;
      *(_DWORD *)(v3 + 456) = v20;
      if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000008,
          4,
          "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
          7317,
          "Move active req: %lld to pending list(cnt = %d) [bubble re-apply],ctx %u link: 0x%x",
          *(_QWORD *)(v6 + 24),
          v20,
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
    }
LABEL_62:
    _cam_isp_ctx_notify_trigger_util(1, (__int64 *)v38);
    _cam_isp_ctx_send_sof_timestamp(v38, 0, 0);
    if ( *(_DWORD *)(v38 + 24) )
    {
      v36 = v5[458];
      if ( (v36 & 8) == 0 )
        goto LABEL_68;
    }
    else
    {
      *(_DWORD *)(v38 + 20) = 0;
      v36 = v5[458];
      if ( (v36 & 8) == 0 )
      {
LABEL_68:
        result = 0;
        *(_QWORD *)(v3 + 504) = *(_QWORD *)(v3 + 440);
        goto LABEL_69;
      }
    }
    if ( !debug_priority )
    {
      v37 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v38 + 20));
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v36 & 8,
        4,
        "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
        7385,
        "next Substate[%s], ctx %u link: 0x%x",
        v37,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    }
    goto LABEL_68;
  }
  v17 = v16;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "__cam_isp_ctx_rdi_only_sof_in_bubble_state",
    7279,
    "HW command failed, ctx_id: %u, link: 0x%x",
    *(_DWORD *)(v2 + 32),
    *(_DWORD *)(v2 + 64));
  result = v17;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
