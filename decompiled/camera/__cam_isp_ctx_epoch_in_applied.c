__int64 __fastcall _cam_isp_ctx_epoch_in_applied(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x22
  __int64 v5; // x26
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v8; // x8
  int v9; // w10
  _QWORD *v10; // x11
  _QWORD *v11; // x20
  __int64 v12; // x27
  __int64 v13; // x0
  unsigned __int64 v14; // x20
  __int64 v15; // x0
  _QWORD *v16; // x8
  __int64 v17; // x20
  unsigned int v18; // w0
  void (__fastcall *v19)(__int64, __int64); // x8
  _QWORD *v20; // x8
  __int64 v21; // x9
  _QWORD *v22; // x21
  _QWORD *v23; // x1
  int v24; // w7
  unsigned __int64 v25; // x25
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x9
  _QWORD *i; // x25
  __int64 v30; // x8
  unsigned __int64 v31; // x20
  __int64 v32; // x2
  char v33; // w20
  const char *v34; // x0
  char v35; // w19
  __int64 v36; // x21
  const char *v37; // x0
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x8

  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_epoch_in_applied",
      4011,
      "invalid event data");
    return 4294967274LL;
  }
  v2 = *(_QWORD *)a1;
  _X25 = a1 + 42128;
  v5 = a1 + 37304;
  if ( *(_BYTE *)(a2 + 24) == 1 )
  {
    if ( *(_QWORD *)a2 != *(_QWORD *)v5 )
    {
      v6 = a2;
      _cam_isp_ctx_update_sof_ts(a1, *(_QWORD *)a2, *(_QWORD *)(a2 + 16));
      goto LABEL_9;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v6 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_epoch_in_applied",
        4025,
        "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
        *(_QWORD *)a2 / 0x3B9ACA00uLL,
        *(_QWORD *)a2 % 0x3B9ACA00uLL,
        *(_QWORD *)(a1 + 37312) / 0x3B9ACA00uLL,
        *(_QWORD *)(a1 + 37312) % 0x3B9ACA00uLL);
LABEL_9:
      a2 = v6;
    }
  }
  if ( *(_BYTE *)(_X25 + 3621) != 1 || (*(_BYTE *)(_X25 + 3624) & 1) != 0 )
  {
    *(_DWORD *)(a1 + 16) = *(_DWORD *)(a2 + 8);
    v8 = *(_QWORD *)(v2 + 160);
    if ( v8 == v2 + 160 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_epoch_in_applied",
        4059,
        "Ctx:%u link: 0x%x No wait request",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      *(_DWORD *)(a1 + 20) = 0;
      _cam_isp_ctx_send_sof_timestamp(a1, 0, 0);
      if ( a1 )
      {
        __asm { PRFM            #0x11, [X25] }
        do
        {
          v46 = __ldxr((unsigned __int64 *)_X25);
          v47 = v46 + 1;
        }
        while ( __stlxr(v47, (unsigned __int64 *)_X25) );
        __dmb(0xBu);
        v14 = v47 & 7;
        v15 = ktime_get_with_offset(1);
        v16 = (_QWORD *)(a1 + (v14 << 6) + 43184);
        *v16 = 0;
        v16[1] = v15;
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
    }
    else
    {
      if ( *(_QWORD *)(_X25 + 3536) < *(_QWORD *)(_X25 + 3528) )
        goto LABEL_17;
      v9 = 2;
      v10 = (_QWORD *)(v2 + 160);
      do
      {
        v10 = (_QWORD *)*v10;
        --v9;
      }
      while ( v10 != (_QWORD *)(v2 + 160) );
      if ( v9 )
      {
LABEL_17:
        *(_DWORD *)(a1 + 20) = 3;
        v11 = *(_QWORD **)(v2 + 160);
        v12 = v11[4];
        *(_WORD *)(v12 + 4504) = 1;
        *(_DWORD *)(v12 + 4448) = 2;
        *(_DWORD *)(a1 + 24) = 1;
        if ( (unsigned int)__ratelimit(&_cam_isp_ctx_epoch_in_applied__rs, "__cam_isp_ctx_epoch_in_applied") )
          v13 = 3;
        else
          v13 = 2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          v13,
          8,
          3,
          "__cam_isp_ctx_epoch_in_applied",
          4102,
          "ctx:%u link: 0x%x Report Bubble flag %d req id:%lld",
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64),
          *(_DWORD *)(v12 + 72),
          v11[3]);
        if ( *(_DWORD *)(v12 + 72) )
        {
          _cam_isp_ctx_notify_error_util(1, v11[3], a1);
        }
        else
        {
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "__cam_isp_ctx_epoch_in_applied",
              4112,
              "Skip bubble recovery for req %lld ctx %u, link: 0x%x",
              v11[3],
              *(_DWORD *)(v2 + 32),
              *(_DWORD *)(v2 + 64));
          if ( *(int *)(v5 + 16) <= 1 )
            _cam_isp_ctx_notify_trigger_util(1, a1);
        }
        v20 = (_QWORD *)v11[1];
        if ( (_QWORD *)*v20 == v11 && (v21 = *v11, *(_QWORD **)(*v11 + 8LL) == v11) )
        {
          *(_QWORD *)(v21 + 8) = v20;
          *v20 = v21;
        }
        else
        {
          _list_del_entry_valid_or_report(v11);
        }
        *v11 = v11;
        v22 = (_QWORD *)(v2 + 128);
        v11[1] = v11;
        v23 = *(_QWORD **)(v2 + 136);
        if ( v11 == (_QWORD *)(v2 + 128) || v11 == v23 || (_QWORD *)*v23 != v22 )
        {
          _list_add_valid_or_report(v11);
        }
        else
        {
          *(_QWORD *)(v2 + 136) = v11;
          *v11 = v22;
          v11[1] = v23;
          *v23 = v11;
        }
        v24 = *(_DWORD *)(v5 + 16) + 1;
        *(_DWORD *)(v5 + 16) = v24;
        if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000008,
            4,
            "__cam_isp_ctx_epoch_in_applied",
            4126,
            "move request %lld to active list(cnt = %d), ctx %u, link: 0x%x",
            v11[3],
            v24,
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64));
        _cam_isp_ctx_handle_deferred_buf_done_in_bubble(a1, v11);
        if ( a1 )
        {
          __asm { PRFM            #0x11, [X25] }
          do
          {
            v39 = __ldxr((unsigned __int64 *)_X25);
            v40 = v39 + 1;
          }
          while ( __stlxr(v40, (unsigned __int64 *)_X25) );
          __dmb(0xBu);
          v25 = v40 & 7;
          v26 = ktime_get_with_offset(1);
          v27 = a1 + (v25 << 6);
          if ( v11 )
          {
            v28 = v11[4];
            *(_QWORD *)(v27 + 43184) = v11[3];
            *(_QWORD *)(v28 + 4472) = v26;
          }
          else
          {
            *(_QWORD *)(v27 + 43184) = 0;
          }
          *(_QWORD *)(v27 + 43192) = v26;
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
        for ( i = (_QWORD *)*v22; ; i = (_QWORD *)*i )
        {
          if ( i == v22 )
          {
            v31 = 0;
            v32 = 0;
            goto LABEL_64;
          }
          v30 = i[4];
          if ( !*(_DWORD *)(v30 + 72) )
          {
            v31 = i[3];
            if ( v31 > *(_QWORD *)(v5 + 24) )
              break;
          }
        }
        *(_QWORD *)(v5 + 24) = v31;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v36 = v30;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_epoch_in_applied",
            4154,
            "ctx %u link: 0x%x reported_req_id update to %lld",
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64),
            v31);
          v30 = v36;
        }
        v32 = *(unsigned __int8 *)(v30 + 4504);
LABEL_64:
        _cam_isp_ctx_send_sof_timestamp(a1, 0, v32);
        cam_req_mgr_debug_delay_detect();
      }
      else
      {
        v31 = *(_QWORD *)(v8 + 24);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "__cam_isp_ctx_epoch_in_applied",
          4085,
          "ctx:%d Don't report the bubble for req:%lld",
          *(_DWORD *)(v2 + 32),
          v31);
      }
      if ( v31 )
      {
LABEL_67:
        _cam_isp_ctx_update_state_monitor_array(a1, 4, v31);
        v33 = debug_mdl;
        result = 0;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v34 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(a1 + 20));
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v33 & 8,
            4,
            "__cam_isp_ctx_epoch_in_applied",
            4183,
            "next Substate[%s], ctx_idx: %u link: 0x%x",
            v34,
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64));
          return 0;
        }
        return result;
      }
    }
    v31 = *(_QWORD *)(*(_QWORD *)(v2 + 136) + 24LL);
    goto LABEL_67;
  }
  if ( !*(_DWORD *)(_X25 + 3436) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_ctx_epoch_in_applied",
      4045,
      "Bubble Recovery Disabled");
    _cam_isp_ctx_send_sof_timestamp(a1, 0, 0);
    return 0;
  }
  v17 = a2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "__cam_isp_ctx_epoch_in_applied",
    4031,
    "Processed a unserved rup, ctx:%u link: 0x%x",
    *(_DWORD *)(v2 + 32),
    *(_DWORD *)(v2 + 64));
  _cam_isp_ctx_reg_upd_in_applied_state((unsigned __int64 *)a1, nullptr);
  v18 = *(_DWORD *)(a1 + 20);
  v19 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 40) + 56LL * v18 + 24);
  if ( v19 )
  {
    if ( *((_DWORD *)v19 - 1) != -1019304031 )
      __break(0x8228u);
    v19(a1, v17);
  }
  else
  {
    v35 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v37 = _cam_isp_ctx_substate_val_to_type(v18);
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v35 & 8,
        4,
        "__cam_isp_ctx_epoch_in_applied",
        4042,
        "No handle function for Substate[%s], evt id %d, ctx:%u link: 0x%x",
        v37,
        3,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    }
  }
  result = 0;
  *(_DWORD *)(_X25 + 3436) = 0;
  return result;
}
