__int64 __fastcall _cam_isp_ctx_apply_req_in_activated_state(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x21
  __int64 v6; // x26
  int v7; // w0
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v10; // x9
  __int64 v11; // x0
  const char *v12; // x5
  __int64 v13; // x2
  __int64 v14; // x4
  int v15; // w0
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  _QWORD *v19; // x22
  __int64 v20; // x28
  __int64 v21; // x25
  __int64 v22; // x23
  __int64 v23; // x25
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x28
  int v27; // w8
  int v28; // w10
  __int64 v29; // x9
  __int64 v30; // x8
  __int64 v31; // x8
  unsigned int v32; // w9
  int v33; // w10
  __int64 *v34; // x8
  __int64 (__fastcall *v35)(__int64, __int64 *); // x9
  __int64 v36; // x0
  unsigned int v37; // w0
  unsigned int v38; // w25
  __int64 v39; // x0
  char v40; // w23
  unsigned __int64 v41; // x9
  __int64 v42; // x26
  const char *v43; // x0
  __int64 v44; // x1
  const char *v45; // x0
  unsigned int *v46; // [xsp+18h] [xbp-58h]
  __int64 v48; // [xsp+28h] [xbp-48h] BYREF
  __int64 v49; // [xsp+30h] [xbp-40h]
  __int64 v50; // [xsp+38h] [xbp-38h]
  __int64 v51; // [xsp+40h] [xbp-30h]
  __int64 v52; // [xsp+48h] [xbp-28h]
  __int64 v53; // [xsp+50h] [xbp-20h]
  __int64 v54; // [xsp+58h] [xbp-18h]
  __int64 v55; // [xsp+60h] [xbp-10h]
  __int64 v56; // [xsp+68h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 256);
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v6 = v5 + 45560;
  v48 = 0;
  v49 = 0;
  *(_DWORD *)(v5 + 45692) = *(_DWORD *)(v5 + 45688);
  if ( *(_BYTE *)(a2 + 40) == 1 && *(_QWORD *)(a2 + 8) <= *(_QWORD *)(v5 + 37352) )
  {
    if ( (unsigned int)__ratelimit(
                         &_cam_isp_ctx_apply_req_in_activated_state__rs,
                         "__cam_isp_ctx_apply_req_in_activated_state") )
      v17 = 3;
    else
      v17 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v17,
      8,
      3,
      "__cam_isp_ctx_apply_req_in_activated_state",
      5811,
      "ctx_id:%u link: 0x%x Trying to reapply the same request %llu again",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_QWORD *)(a2 + 8));
    result = 0;
  }
  else
  {
    if ( *(_QWORD *)(a1 + 144) == a1 + 144 )
    {
      v15 = __ratelimit(&_cam_isp_ctx_apply_req_in_activated_state__rs_26, "__cam_isp_ctx_apply_req_in_activated_state");
      v8 = *(unsigned int *)(a1 + 32);
      v9 = *(unsigned int *)(a1 + 64);
      v10 = *(_QWORD *)(a2 + 8);
      if ( v15 )
        v11 = 3;
      else
        v11 = 2;
      v12 = "ctx_id:%u link: 0x%x No available request for Apply id %lld";
      v13 = 1;
      v14 = 5819;
      goto LABEL_13;
    }
    if ( *(_DWORD *)(v5 + 24) )
    {
      v7 = __ratelimit(&_cam_isp_ctx_apply_req_in_activated_state__rs_28, "__cam_isp_ctx_apply_req_in_activated_state");
      v8 = *(unsigned int *)(a1 + 32);
      v9 = *(unsigned int *)(a1 + 64);
      v10 = *(_QWORD *)(a2 + 8);
      if ( v7 )
        v11 = 3;
      else
        v11 = 2;
      v12 = "ctx_id:%u link: 0x%x Processing bubble cannot apply Request Id %llu";
      v13 = 3;
      v14 = 5834;
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64))cam_print_log)(
        v11,
        8,
        v13,
        "__cam_isp_ctx_apply_req_in_activated_state",
        v14,
        v12,
        v8,
        v9,
        v10);
LABEL_14:
      result = 4294967282LL;
      goto LABEL_24;
    }
    if ( *(_DWORD *)(v5 + 45572) )
    {
      if ( (unsigned int)__ratelimit(
                           &_cam_isp_ctx_apply_req_in_activated_state__rs_30,
                           "__cam_isp_ctx_apply_req_in_activated_state") )
        v18 = 3;
      else
        v18 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v18,
        8,
        3,
        "__cam_isp_ctx_apply_req_in_activated_state",
        5847,
        "ctx_id:%u link: 0x%x Processing recovery cannot apply Request Id %lld",
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64),
        *(_QWORD *)(a2 + 8));
      result = 4294967285LL;
      goto LABEL_24;
    }
    raw_spin_lock_bh(a1 + 120);
    v19 = *(_QWORD **)(a1 + 144);
    if ( *(_QWORD *)(a1 + 128) == a1 + 128 )
      v20 = 0;
    else
      v20 = *(_QWORD *)(a1 + 128);
    raw_spin_unlock_bh(a1 + 120);
    v21 = v19[3];
    if ( v21 != *(_QWORD *)(a2 + 8) )
    {
      if ( (unsigned int)__ratelimit(
                           &_cam_isp_ctx_apply_req_in_activated_state__rs_32,
                           "__cam_isp_ctx_apply_req_in_activated_state") )
        v24 = 3;
      else
        v24 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
        v24,
        8,
        1,
        "__cam_isp_ctx_apply_req_in_activated_state",
        5869,
        "ctx_id:%u link: 0x%x Invalid Request Id asking %llu existing %llu",
        *(unsigned int *)(a1 + 32),
        *(unsigned int *)(a1 + 64),
        *(_QWORD *)(a2 + 8),
        v19[3]);
      goto LABEL_14;
    }
    if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
    {
      v42 = debug_mdl & 0x1000008;
      v43 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v5 + 20));
      v44 = v42;
      v6 = v5 + 45560;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v44,
        4,
        "__cam_isp_ctx_apply_req_in_activated_state",
        5877,
        "Apply request %lld in Substate[%s] ctx %u, link: 0x%x",
        v21,
        v43,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
    }
    v22 = v19[4];
    if ( v20 )
    {
      v23 = *(_QWORD *)(v20 + 32);
      v46 = (unsigned int *)(v5 + 37320);
      if ( *(int *)(v5 + 37320) < 2 )
      {
        _cam_isp_ctx_trigger_reg_dump(4, a1, v23 + 80);
        *(_BYTE *)(v23 + 4506) = 1;
LABEL_47:
        *(_DWORD *)(v5 + 37388) = 0;
        v26 = v22 + 4096;
        v27 = *(_DWORD *)(a2 + 24);
        *(_QWORD *)(v22 + 52) = 0;
        v28 = *(_DWORD *)(v22 + 4448);
        *(_WORD *)(v22 + 4504) = 0;
        *(_DWORD *)(v22 + 72) = v27;
        v29 = *(_QWORD *)(v5 + 37296);
        v54 = v19[3];
        v30 = *(_QWORD *)(v22 + 8);
        v48 = v29;
        v50 = v30;
        LODWORD(v30) = *(_DWORD *)(v22 + 16);
        v53 = v22 + 80;
        LODWORD(v55) = v28;
        LODWORD(v49) = v30;
        LOBYTE(v30) = *(_BYTE *)(a2 + 43);
        WORD2(v55) = 0;
        *(_BYTE *)(v22 + 4370) = v30;
        if ( *(_BYTE *)(v6 + 92) == 1 && v19[3] == *(_QWORD *)(v6 + 72) )
        {
          result = cam_isp_context_apply_evt_injection(*(_QWORD *)v5);
          if ( !(_DWORD)result )
            goto LABEL_24;
        }
        if ( *(_QWORD *)(v6 + 160) != v6 + 160 )
        {
          _cam_isp_ctx_print_fcg_tracker(v5 + 45704);
          v31 = *(_QWORD *)(v6 + 160);
          v32 = *(_DWORD *)(v6 + 152);
          v33 = *(_DWORD *)(v6 + 156) - *(_DWORD *)(v31 - 8);
          if ( v32 > ~v33 )
            v32 = ~v33;
          *(_DWORD *)(v6 + 156) = v33 + v32;
          *(_DWORD *)(v31 - 8) = v32;
          *(_DWORD *)(v6 + 152) = 0;
          list_rotate_left(v6 + 160);
          _cam_isp_ctx_print_fcg_tracker(v5 + 45704);
          _cam_isp_ctx_update_fcg_prediction_idx(a1, *(_QWORD *)(a2 + 8), v5 + 45704, v22 + 4376);
          v26 = v22 + 4096;
        }
        *(_DWORD *)v6 = 1;
        v34 = *(__int64 **)(a1 + 208);
        v35 = (__int64 (__fastcall *)(__int64, __int64 *))v34[9];
        v36 = *v34;
        if ( *((_DWORD *)v35 - 1) != 1863972096 )
          __break(0x8229u);
        v37 = v35(v36, &v48);
        if ( v37 == -114 )
        {
          v38 = -114;
          raw_spin_lock_bh(a1 + 120);
          *(_WORD *)(v26 + 408) = 1;
          *(_DWORD *)(v5 + 24) = 1;
          _list_del_entry(v19);
          *v19 = v19;
          v19[1] = v19;
          _list_add(v19, a1 + 128, *(_QWORD *)(a1 + 128));
          ++*v46;
          raw_spin_unlock_bh(a1 + 120);
          if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x1000008,
              4,
              "__cam_isp_ctx_apply_req_in_activated_state",
              6007,
              "move request %lld to active list(cnt = %d), ctx %u, link: 0x%x",
              v19[3],
              *v46,
              *(_DWORD *)(a1 + 32),
              *(_DWORD *)(a1 + 64));
          goto LABEL_75;
        }
        v38 = v37;
        if ( v37 )
        {
          if ( (unsigned int)__ratelimit(
                               &_cam_isp_ctx_apply_req_in_activated_state__rs_40,
                               "__cam_isp_ctx_apply_req_in_activated_state") )
            v39 = 3;
          else
            v39 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v39,
            8,
            1,
            "__cam_isp_ctx_apply_req_in_activated_state",
            6011,
            "ctx_id:%u link: 0x%x,Can not apply (req %lld) the configuration, rc %d",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64),
            *(_QWORD *)(a2 + 8),
            v38);
          goto LABEL_75;
        }
        raw_spin_lock_bh(a1 + 120);
        *(_DWORD *)(v6 + 8) = 0;
        *(_DWORD *)(v5 + 20) = a3;
        *(_QWORD *)(v5 + 37352) = *(_QWORD *)(a2 + 8);
        *(_QWORD *)(v6 + 104) = jiffies;
        _list_del_entry(v19);
        *v19 = v19;
        v19[1] = v19;
        if ( *(_DWORD *)(v6 + 12) )
          _cam_isp_ctx_enqueue_request_in_order(a1, v19, 0);
        else
          _list_add(v19, *(_QWORD *)(a1 + 168), a1 + 160);
        v40 = debug_mdl;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v45 = _cam_isp_ctx_substate_val_to_type(a3);
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v40 & 8,
            4,
            "__cam_isp_ctx_apply_req_in_activated_state",
            5976,
            "new Substate[%s], applied req %lld, ctx_idx: %u, link: 0x%x",
            v45,
            *(_QWORD *)(v5 + 37352),
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
          v41 = *(_QWORD *)(a2 + 32);
          if ( v41 )
          {
LABEL_72:
            if ( *(_QWORD *)(v5 + 37312) - 100000LL < v41 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                2,
                "__cam_isp_ctx_apply_req_in_activated_state",
                5984,
                "Apply delayed req:%llu, link:0x%x, timestamp sof:0x%llx applied:0x%llx",
                *(_QWORD *)(a2 + 8),
                *(_DWORD *)(a1 + 64),
                *(_QWORD *)(v5 + 37312),
                v41);
              _cam_isp_ctx_notify_v4l2_error_event(1, 0x200000, *(_QWORD *)(a2 + 8), a1);
            }
          }
        }
        else
        {
          v41 = *(_QWORD *)(a2 + 32);
          if ( v41 )
            goto LABEL_72;
        }
        raw_spin_unlock_bh(a1 + 120);
        _cam_isp_ctx_update_state_monitor_array(v5, 1, v19[3]);
        _cam_isp_ctx_update_event_record(v5, 1, v19, 0);
LABEL_75:
        result = v38;
        *(_DWORD *)v6 = 0;
        goto LABEL_24;
      }
    }
    else
    {
      v46 = (unsigned int *)(v5 + 37320);
      if ( *(int *)(v5 + 37320) <= 1 )
        goto LABEL_47;
      v23 = 0;
    }
    if ( (unsigned int)__ratelimit(
                         &_cam_isp_ctx_apply_req_in_activated_state__rs_35,
                         "__cam_isp_ctx_apply_req_in_activated_state") )
      v25 = 3;
    else
      v25 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD))cam_print_log)(
      v25,
      8,
      2,
      "__cam_isp_ctx_apply_req_in_activated_state",
      5888,
      "Reject apply request (id %lld) due to congestion(cnt = %d) ctx %u, link: 0x%x",
      v19[3],
      *v46,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    if ( v20 )
      _cam_isp_ctx_handle_buf_done_fail_log(v5, *(_QWORD *)(v20 + 24), v23);
    result = 4294967282LL;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
