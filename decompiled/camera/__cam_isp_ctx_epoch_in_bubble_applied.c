__int64 __fastcall _cam_isp_ctx_epoch_in_bubble_applied(__int64 a1, __int64 *a2)
{
  __int64 v2; // x22
  __int64 v5; // x26
  unsigned __int64 v7; // x1
  _QWORD *v9; // x20
  __int64 v10; // x27
  __int64 v11; // x0
  int v12; // w8
  unsigned __int64 v13; // x20
  __int64 v14; // x0
  _QWORD *v15; // x8
  _QWORD *v16; // x8
  __int64 v17; // x9
  _QWORD *v18; // x21
  _QWORD *v19; // x1
  int v20; // w7
  _QWORD *v21; // x8
  __int64 v22; // x9
  _QWORD *v23; // x1
  unsigned __int64 v24; // x1
  unsigned __int64 v25; // x21
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x9
  unsigned __int64 v29; // x21
  __int64 v30; // x0
  _QWORD *v31; // x8
  char v32; // w8
  __int64 v33; // x8
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v42; // x8
  unsigned __int64 v43; // x8
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v48; // x8

  v2 = *(_QWORD *)a1;
  if ( !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_epoch_in_bubble_applied",
      4294,
      "invalid event data, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    return 4294967274LL;
  }
  _X23 = (unsigned __int64 *)(a1 + 42128);
  v5 = a1 + 37304;
  *(_DWORD *)(a1 + 16) = *((_DWORD *)a2 + 2);
  if ( *((_BYTE *)a2 + 24) == 1 )
  {
    v7 = *a2;
    if ( v7 == *(_QWORD *)v5 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_epoch_in_bubble_applied",
          4310,
          "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
          v7 / 0x3B9ACA00,
          v7 % 0x3B9ACA00,
          *(_QWORD *)(a1 + 37312) / 0x3B9ACA00uLL,
          *(_QWORD *)(a1 + 37312) % 0x3B9ACA00uLL);
    }
    else
    {
      _cam_isp_ctx_update_sof_ts(a1, v7, a2[2]);
    }
  }
  v9 = *(_QWORD **)(v2 + 160);
  if ( v9 != (_QWORD *)(v2 + 160) )
  {
    v10 = v9[4];
    *(_BYTE *)(v10 + 4504) = 1;
    if ( (unsigned int)__ratelimit(&_cam_isp_ctx_epoch_in_bubble_applied__rs, "__cam_isp_ctx_epoch_in_bubble_applied") )
      v11 = 3;
    else
      v11 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v11,
      8,
      3,
      "__cam_isp_ctx_epoch_in_bubble_applied",
      4337,
      "Ctx:%u link: 0x%x Report Bubble flag %d req id:%lld",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64),
      *(_DWORD *)(v10 + 72),
      v9[3]);
    v12 = *(_DWORD *)(v10 + 72);
    *(_DWORD *)(v10 + 4448) = 2;
    *(_BYTE *)(v10 + 4505) = 0;
    if ( v12 )
    {
      _cam_isp_ctx_notify_error_util(1, v9[3], a1);
    }
    else
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_epoch_in_bubble_applied",
          4348,
          "Skip bubble recovery for req %lld ctx %u link: 0x%x",
          v9[3],
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
      if ( *(int *)(v5 + 16) <= 1 )
        _cam_isp_ctx_notify_trigger_util(1, a1);
    }
    *(_DWORD *)(a1 + 24) = 1;
    v16 = (_QWORD *)v9[1];
    if ( (_QWORD *)*v16 == v9 && (v17 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
    {
      *(_QWORD *)(v17 + 8) = v16;
      *v16 = v17;
    }
    else
    {
      _list_del_entry_valid_or_report(v9);
    }
    *v9 = v9;
    v18 = (_QWORD *)(v2 + 128);
    v9[1] = v9;
    v19 = *(_QWORD **)(v2 + 136);
    if ( v9 == (_QWORD *)(v2 + 128) || v9 == v19 || (_QWORD *)*v19 != v18 )
    {
      _list_add_valid_or_report(v9);
    }
    else
    {
      *(_QWORD *)(v2 + 136) = v9;
      *v9 = v18;
      v9[1] = v19;
      *v19 = v9;
    }
    v20 = *(_DWORD *)(v5 + 16) + 1;
    *(_DWORD *)(v5 + 16) = v20;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_epoch_in_bubble_applied",
        4363,
        "move request %lld to active list(cnt = %d) ctx %u, link: 0x%x",
        v9[3],
        v20,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    _cam_isp_ctx_handle_deferred_buf_done_in_bubble(a1, v9);
    if ( (*(_BYTE *)(v10 + 4504) & 1) == 0 )
    {
      v9 = *(_QWORD **)(v2 + 144);
      *(_WORD *)(v10 + 4504) = 1;
      *(_DWORD *)(v10 + 4448) = 2;
      *(_DWORD *)(a1 + 24) = 1;
      v21 = (_QWORD *)v9[1];
      if ( (_QWORD *)*v21 == v9 && (v22 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
      {
        *(_QWORD *)(v22 + 8) = v21;
        *v21 = v22;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      *v9 = v9;
      v9[1] = v9;
      v23 = *(_QWORD **)(v2 + 136);
      if ( v9 == v18 || v9 == v23 || (_QWORD *)*v23 != v18 )
      {
        _list_add_valid_or_report(v9);
      }
      else
      {
        *(_QWORD *)(v2 + 136) = v9;
        *v9 = v18;
        v9[1] = v23;
        *v23 = v9;
      }
      ++*(_DWORD *)(v5 + 16);
    }
    if ( *(_DWORD *)(v10 + 72) )
    {
      _cam_isp_ctx_send_sof_timestamp(a1, 0, 0);
      if ( a1 )
      {
        __asm { PRFM            #0x11, [X23] }
        do
        {
          v35 = __ldxr(_X23);
          v36 = v35 + 1;
        }
        while ( __stlxr(v36, _X23) );
LABEL_68:
        __dmb(0xBu);
        v29 = v36 & 7;
        v30 = ktime_get_with_offset(1);
        v31 = (_QWORD *)(a1 + (v29 << 6) + 43184);
        *v31 = 0;
        v31[1] = v30;
LABEL_57:
        v32 = debug_mdl;
        *(_DWORD *)(a1 + 20) = 3;
        if ( (v32 & 8) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v32 & 8,
            4,
            "__cam_isp_ctx_epoch_in_bubble_applied",
            4407,
            "next Substate[%s], ctx_idx: %u, link: 0x%x",
            "BUBBLE",
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64));
        cam_req_mgr_debug_delay_detect();
        goto LABEL_61;
      }
    }
    else
    {
      v24 = v9[3];
      if ( v24 <= *(_QWORD *)(v5 + 24) )
      {
        _cam_isp_ctx_send_sof_timestamp(a1, 0, 0);
        if ( a1 )
        {
          __asm { PRFM            #0x11, [X23] }
          do
          {
            v48 = __ldxr(_X23);
            v36 = v48 + 1;
          }
          while ( __stlxr(v36, _X23) );
          goto LABEL_68;
        }
      }
      else
      {
        *(_QWORD *)(v5 + 24) = v24;
        _cam_isp_ctx_send_sof_timestamp(a1, v24, 1);
        if ( a1 )
        {
          __asm { PRFM            #0x11, [X23] }
          do
          {
            v45 = __ldxr(_X23);
            v46 = v45 + 1;
          }
          while ( __stlxr(v46, _X23) );
          __dmb(0xBu);
          v25 = v46 & 7;
          v26 = ktime_get_with_offset(1);
          v27 = a1 + (v25 << 6);
          if ( v9 )
          {
            v28 = v9[4];
            *(_QWORD *)(v27 + 43184) = v9[3];
            *(_QWORD *)(v28 + 4472) = v26;
          }
          else
          {
            *(_QWORD *)(v27 + 43184) = 0;
          }
          *(_QWORD *)(v27 + 43192) = v26;
          goto LABEL_57;
        }
      }
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_update_event_record",
      98,
      "Invalid Args");
    goto LABEL_57;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "__cam_isp_ctx_epoch_in_bubble_applied",
    4323,
    "ctx:%u link: 0x%x No pending request.",
    *(_DWORD *)(v2 + 32),
    *(_DWORD *)(v2 + 64));
  _cam_isp_ctx_send_sof_timestamp(a1, 0, 0);
  if ( a1 )
  {
    __asm { PRFM            #0x11, [X23] }
    do
    {
      v42 = __ldxr(_X23);
      v43 = v42 + 1;
    }
    while ( __stlxr(v43, _X23) );
    __dmb(0xBu);
    v13 = v43 & 7;
    v14 = ktime_get_with_offset(1);
    v15 = (_QWORD *)(a1 + (v13 << 6) + 43184);
    *v15 = 0;
    v15[1] = v14;
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
  }
  *(_DWORD *)(a1 + 20) = 3;
LABEL_61:
  v33 = *(_QWORD *)(v2 + 136);
  if ( v33 )
    _cam_isp_ctx_update_state_monitor_array(a1, 4, *(_QWORD *)(v33 + 24));
  return 0;
}
