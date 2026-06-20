// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall _cam_isp_ctx_rdi_only_reg_upd_in_bubble_applied_state(__int64 a1)
{
  __int64 v1; // x23
  unsigned int *v4; // x20
  unsigned int **v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x24
  __int64 v9; // x8
  __int64 v10; // x21
  unsigned __int64 v11; // x20
  __int64 v12; // x0
  _QWORD *v13; // x8
  __int64 v14; // x2
  unsigned int *v15; // x1
  int v16; // w7
  __int64 v17; // x8
  __int64 v18; // x2
  unsigned int *v19; // x1
  char v20; // w8
  char v21; // w21
  unsigned __int64 v22; // x21
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x9
  const char *v26; // x0
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  __int64 v38; // [xsp+18h] [xbp-8h]

  v1 = *(_QWORD *)a1;
  *(_DWORD *)(a1 + 20) = 2;
  _X22 = (unsigned __int64 *)(a1 + 42136);
  v4 = *(unsigned int **)(v1 + 160);
  if ( v4 != (unsigned int *)(v1 + 160) )
  {
    v5 = *((unsigned int ***)v4 + 1);
    v6 = 37320;
    if ( *v5 == v4 && (v7 = *(_QWORD *)v4, *(unsigned int **)(*(_QWORD *)v4 + 8LL) == v4) )
    {
      *(_QWORD *)(v7 + 8) = v5;
      *v5 = (unsigned int *)v7;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(v1 + 160));
    }
    *(_QWORD *)v4 = v4;
    v8 = a1 + v6;
    *((_QWORD *)v4 + 1) = v4;
    v9 = *((_QWORD *)v4 + 4);
    if ( *(_DWORD *)(v9 + 88) == 1 )
      v10 = 0;
    else
      v10 = *((_QWORD *)v4 + 3);
    if ( *(_DWORD *)(v9 + 32) )
    {
      v14 = v1 + 128;
      v15 = *(unsigned int **)(v1 + 136);
      if ( v4 == (unsigned int *)(v1 + 128) || v4 == v15 || *(_QWORD *)v15 != v14 )
      {
        _list_add_valid_or_report(v4);
      }
      else
      {
        *(_QWORD *)(v1 + 136) = v4;
        *(_QWORD *)v4 = v14;
        *((_QWORD *)v4 + 1) = v15;
        *(_QWORD *)v15 = v4;
      }
      v16 = *(_DWORD *)v8 + 1;
      *(_DWORD *)v8 = v16;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_rdi_only_reg_upd_in_bubble_applied_state",
          7437,
          "move request %lld to active list(cnt = %d), ctx %u link: 0x%x",
          *((_QWORD *)v4 + 3),
          v16,
          *(_DWORD *)(v1 + 32),
          *(_DWORD *)(v1 + 64));
      v10 = *((_QWORD *)v4 + 3);
      goto LABEL_29;
    }
    cam_smmu_buffer_tracker_putref(v4 + 28);
    v17 = *((_QWORD *)v4 + 4);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v38 = *((_QWORD *)v4 + 4);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_move_req_to_free_list",
        1404,
        "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
        *((_QWORD *)v4 + 3),
        *((_QWORD *)v4 + 17),
        *(_DWORD *)(v1 + 32),
        *(_DWORD *)(v1 + 64));
      v17 = v38;
      if ( !*((_QWORD *)v4 + 17) )
      {
LABEL_23:
        v18 = v1 + 176;
        v19 = *(unsigned int **)(v1 + 184);
        if ( (unsigned int *)(v1 + 176) == v4 || v19 == v4 || *(_QWORD *)v19 != v18 )
        {
          _list_add_valid_or_report(v4);
          v20 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_29;
        }
        else
        {
          *(_QWORD *)(v1 + 184) = v4;
          *(_QWORD *)v4 = v18;
          *((_QWORD *)v4 + 1) = v19;
          *(_QWORD *)v19 = v4;
          v20 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_29;
        }
        if ( !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v20 & 8,
            4,
            "__cam_isp_ctx_rdi_only_reg_upd_in_bubble_applied_state",
            7446,
            "move active req %lld to free list(cnt=%d), ctx %u link: 0x%x",
            *((_QWORD *)v4 + 3),
            *(_DWORD *)v8,
            *(_DWORD *)(v1 + 32),
            *(_DWORD *)(v1 + 64));
LABEL_29:
        _cam_isp_ctx_notify_trigger_util(1, (__int64 *)a1);
        if ( v10 )
          *(_QWORD *)(v8 + 8) = v10;
        _cam_isp_ctx_send_sof_timestamp(a1, v10, 0);
        v21 = debug_mdl;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v26 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(a1 + 20));
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v21 & 8,
            4,
            "__cam_isp_ctx_rdi_only_reg_upd_in_bubble_applied_state",
            7458,
            "next Substate[%s], ctx %u link: 0x%x",
            v26,
            *(_DWORD *)(v1 + 32),
            *(_DWORD *)(v1 + 64));
          if ( a1 )
          {
LABEL_34:
            __asm { PRFM            #0x11, [X22] }
            do
            {
              v29 = __ldxr(_X22);
              v30 = v29 + 1;
            }
            while ( __stlxr(v30, _X22) );
            __dmb(0xBu);
            v22 = v30 & 7;
            v23 = ktime_get_with_offset(1);
            v24 = a1 + (v22 << 6);
            if ( v4 )
            {
              v25 = *((_QWORD *)v4 + 4);
              *(_QWORD *)(v24 + 43696) = *((_QWORD *)v4 + 3);
              *(_QWORD *)(v25 + 4480) = v23;
            }
            else
            {
              *(_QWORD *)(v24 + 43696) = 0;
            }
            *(_QWORD *)(v24 + 43704) = v23;
            return 0;
          }
        }
        else if ( a1 )
        {
          goto LABEL_34;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "__cam_isp_ctx_update_event_record",
          98,
          "Invalid Args");
        return 0;
      }
    }
    else if ( !*((_QWORD *)v4 + 17) )
    {
      goto LABEL_23;
    }
    cam_mem_put_kref(*(_DWORD *)(v17 + 4328));
    cam_common_mem_free(*((_QWORD *)v4 + 17));
    *((_QWORD *)v4 + 17) = 0;
    goto LABEL_23;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "__cam_isp_ctx_rdi_only_reg_upd_in_bubble_applied_state",
    7419,
    "Reg upd ack with no waiting request, ctx %u link: 0x%x",
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 64));
  _cam_isp_ctx_send_sof_timestamp(a1, 0, 0);
  if ( a1 )
  {
    __asm { PRFM            #0x11, [X22] }
    do
    {
      v36 = __ldxr(_X22);
      v37 = v36 + 1;
    }
    while ( __stlxr(v37, _X22) );
    __dmb(0xBu);
    v11 = v37 & 7;
    v12 = ktime_get_with_offset(1);
    *(_DWORD *)(a1 + 20) = 0;
    v13 = (_QWORD *)(a1 + (v11 << 6) + 43696);
    *v13 = 0;
    v13[1] = v12;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_update_event_record",
      98,
      "Invalid Args");
    HIDWORD(qword_10) = 0;
  }
  return 0;
}
