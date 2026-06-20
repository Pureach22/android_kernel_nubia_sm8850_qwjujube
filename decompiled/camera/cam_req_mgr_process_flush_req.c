__int64 __fastcall cam_req_mgr_process_flush_req(int *a1, __int64 a2)
{
  int v4; // w6
  __int64 v5; // x6
  int v6; // w7
  int v7; // w8
  unsigned int v8; // w21
  int v9; // w25
  __int64 v10; // x24
  __int64 v11; // x26
  __int64 v12; // x9
  int v13; // w13
  char v14; // w12
  int v15; // w10
  __int64 v16; // x9
  void (__fastcall *v17)(_QWORD); // x9
  __int64 v18; // x21
  __int64 v19; // x6
  __int64 v20; // x21
  unsigned int slot_for_req; // w0
  __int64 v22; // x27
  unsigned int v23; // w21
  int v24; // w8
  __int64 v25; // x26
  __int64 v26; // x8
  unsigned int *v27; // x9
  _DWORD *v28; // x8
  __int64 v29; // x6
  unsigned int v30; // w9
  __int64 v31; // x9
  int v32; // w8
  __int64 v33; // x1
  int v34; // w8
  int v35; // w24
  __int64 v36; // x21
  __int64 v37; // x25
  __int64 v38; // x9
  int v39; // w13
  char v40; // w12
  int v41; // w10
  __int64 v42; // x9
  void (__fastcall *v43)(_QWORD); // x9
  unsigned __int64 StatusReg; // x21
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // [xsp+8h] [xbp-28h] BYREF
  __int64 v49; // [xsp+10h] [xbp-20h]
  __int64 v50; // [xsp+18h] [xbp-18h]
  __int64 v51; // [xsp+20h] [xbp-10h]
  __int64 v52; // [xsp+28h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_process_flush_req",
      3208,
      "input args NULL %pK %pK",
      (const void *)a2,
      a1);
    LODWORD(v18) = -22;
    goto LABEL_75;
  }
  if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000010,
      4,
      "cam_req_mgr_process_flush_req",
      3218,
      "link_hdl %x req_id %lld type %d",
      *(_DWORD *)(a2 + 12),
      *(_QWORD *)(a2 + 24),
      *(_DWORD *)(a2 + 16));
  while ( 1 )
  {
    mutex_lock(a1 + 8264);
    v4 = *(_DWORD *)(a2 + 16);
    if ( v4 != 1 )
    {
      if ( v4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_process_flush_req",
          3245,
          "Invalid flush type %u",
          v4);
        LODWORD(v18) = -22;
      }
      else
      {
        v5 = *(_QWORD *)(a2 + 24);
        v6 = *a1;
        *((_QWORD *)a1 + 4158) = v5;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          3,
          "cam_req_mgr_process_flush_req",
          3227,
          "Last request id to flush is %lld on link 0x%x",
          v5,
          v6);
        ((void (__fastcall *)(int *))_cam_req_mgr_flush_req_slot)(a1);
        v50 = 0;
        v51 = 0;
        *((_QWORD *)a1 + 10) = -1;
        *((_QWORD *)a1 + 19) = -1;
        *((_QWORD *)a1 + 13) = -1;
        *((_QWORD *)a1 + 22) = -1;
        *((_QWORD *)a1 + 16) = -1;
        *((_QWORD *)a1 + 25) = -1;
        v7 = a1[1];
        v8 = a1[2];
        v48 = 0;
        v49 = 0;
        if ( v7 >= 1 )
        {
          v9 = *(_DWORD *)(a2 + 20);
          v10 = 0;
          v11 = 304;
          do
          {
            v12 = *((_QWORD *)a1 + 5);
            if ( *(_DWORD *)(v12 + v11 - 16) <= v8 )
            {
              v13 = *(_DWORD *)(a2 + 16);
              LODWORD(v48) = *(_DWORD *)(a2 + 12);
              v14 = *(_BYTE *)(g_crm_core_dev + 65);
              v15 = *(_DWORD *)(v12 + v11 - 304);
              v50 = *(_QWORD *)(a2 + 24);
              HIDWORD(v48) = v15;
              LODWORD(v49) = v13;
              LOBYTE(v51) = (v14 ^ 1) & v9;
              v16 = *(_QWORD *)(v12 + v11);
              if ( v16 )
              {
                v17 = *(void (__fastcall **)(_QWORD))(v16 + 32);
                if ( v17 )
                {
                  if ( *((_DWORD *)v17 - 1) != 598888819 )
                    __break(0x8229u);
                  v17(&v48);
                  v7 = a1[1];
                }
              }
            }
            ++v10;
            v11 += 320;
          }
          while ( v10 < v7 );
        }
        LODWORD(v18) = 0;
        a1[8314] = 0;
        a1[8344] = 0;
        a1[8348] = 0;
      }
      goto LABEL_74;
    }
    v19 = *(_QWORD *)(a2 + 24);
    *((_QWORD *)a1 + 4158) = v19;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "cam_req_mgr_process_flush_req",
        3238,
        "Canceling req %lld on link 0x%x",
        v19,
        *a1);
      v19 = *(_QWORD *)(a2 + 24);
    }
    v20 = *((_QWORD *)a1 + 6);
    slot_for_req = _cam_req_mgr_find_slot_for_req(v20, v19);
    if ( (slot_for_req & 0x80000000) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        1,
        "__cam_req_mgr_try_cancel_req",
        3141,
        "req_id %lld not found in input queue",
        *(_QWORD *)(a2 + 24));
      LODWORD(v18) = -2;
      goto LABEL_41;
    }
    if ( slot_for_req >= 0x31 )
      goto LABEL_78;
    v22 = v20 + 72LL * slot_for_req;
    if ( *(__int64 *)(v22 + 24) >= 1 && *(_DWORD *)(v22 + 44) )
    {
      v23 = slot_for_req;
      _cam_req_mgr_disconnect_req_on_sync_link(a1, v22 + 8);
      slot_for_req = v23;
    }
    v24 = *(_DWORD *)(v22 + 16);
    LODWORD(v25) = 3;
    if ( v24 > 2 )
    {
      if ( v24 == 3 )
        goto LABEL_58;
      if ( v24 != 4 )
      {
LABEL_30:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "__cam_req_mgr_try_cancel_req",
          3179,
          "invalid state for slot link:0x%x req:%lld",
          *(_DWORD *)(a2 + 12),
          *(_QWORD *)(a2 + 24));
        LODWORD(v18) = -22;
        goto LABEL_41;
      }
    }
    else
    {
      if ( v24 == 1 )
        goto LABEL_58;
      if ( v24 != 2 )
        goto LABEL_30;
    }
    v26 = (unsigned int)a1[1];
    if ( (int)v26 < 1 )
    {
LABEL_39:
      LODWORD(v18) = -19;
LABEL_40:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        1,
        "__cam_req_mgr_try_cancel_req",
        3155,
        "pd: %d link_hdl: 0x%x red_id: %d",
        v18,
        *a1,
        *(_QWORD *)(a2 + 24));
LABEL_41:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        2,
        "cam_req_mgr_process_flush_req",
        3242,
        "cannot cancel req_id %lld on link 0x%x",
        *(_QWORD *)(a2 + 24),
        *(_DWORD *)(a2 + 12));
      goto LABEL_74;
    }
    v27 = (unsigned int *)(*((_QWORD *)a1 + 5) + 288LL);
    while ( *(v27 - 1) != 4 )
    {
      --v26;
      v27 += 80;
      if ( !v26 )
        goto LABEL_39;
    }
    v18 = *v27;
    if ( (unsigned int)v18 >= 3 )
      goto LABEL_40;
    v28 = a1 + 36;
    v29 = *(_QWORD *)(a2 + 24);
    if ( v29 <= *(_QWORD *)&a1[6 * (unsigned int)v18 + 38] )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        2,
        "__cam_req_mgr_try_cancel_req",
        3161,
        "req %lld already applied to IFE on link 0x%x",
        v29,
        *(_DWORD *)(a2 + 12));
      LODWORD(v18) = -1;
      goto LABEL_41;
    }
    v30 = a1[2];
    if ( (unsigned int)v18 <= v30 )
      v25 = v30;
    else
      v25 = (unsigned int)v18;
    if ( (unsigned int)v18 >= v30 )
      goto LABEL_58;
    if ( (_DWORD)v18 == 2 )
      goto LABEL_78;
    v31 = v18 + 1;
    if ( v29 <= *(_QWORD *)&v28[6 * v18 + 8] )
      break;
    if ( v31 == v25 )
      goto LABEL_58;
    if ( v18 == 1 )
      goto LABEL_78;
    if ( v29 <= *(_QWORD *)&v28[6 * v18 + 14] )
      goto LABEL_57;
    if ( v18 + 2 == v25 )
      goto LABEL_58;
LABEL_78:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v46 = _traceiter_cam_flush_req(0, a1, a2 + 8);
      v47 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v47;
      if ( !v47 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v46);
    }
  }
  LODWORD(v31) = v18;
LABEL_57:
  LODWORD(v25) = v31;
LABEL_58:
  *(_DWORD *)(v22 + 36) = 0;
  if ( slot_for_req == 48 )
    goto LABEL_78;
  *(_QWORD *)(v22 + 24) = -1;
  *(_DWORD *)(v22 + 12) = 1;
  v32 = debug_priority;
  v33 = debug_mdl & 0x10;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v33,
      4,
      "__cam_req_mgr_in_q_skip_idx",
      754,
      "SET IDX SKIP on slot= %d",
      slot_for_req);
    v32 = debug_priority;
    v33 = debug_mdl & 0x10;
    if ( (debug_mdl & 0x10) != 0 )
      goto LABEL_62;
  }
  else if ( (debug_mdl & 0x10) != 0 )
  {
LABEL_62:
    if ( !v32 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v33,
        4,
        "__cam_req_mgr_try_cancel_req",
        3184,
        "cancelling request %lld on link 0x%x for devices with pd less than %d",
        *(_QWORD *)(a2 + 24),
        *(_DWORD *)(a2 + 12),
        v25);
  }
  v34 = a1[1];
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  if ( v34 >= 1 )
  {
    v35 = *(_DWORD *)(a2 + 20);
    v36 = 0;
    v37 = 304;
    do
    {
      v38 = *((_QWORD *)a1 + 5);
      if ( *(_DWORD *)(v38 + v37 - 16) <= (unsigned int)v25 )
      {
        v39 = *(_DWORD *)(a2 + 16);
        LODWORD(v48) = *(_DWORD *)(a2 + 12);
        v40 = *(_BYTE *)(g_crm_core_dev + 65);
        v41 = *(_DWORD *)(v38 + v37 - 304);
        v50 = *(_QWORD *)(a2 + 24);
        HIDWORD(v48) = v41;
        LODWORD(v49) = v39;
        LOBYTE(v51) = (v40 ^ 1) & v35;
        v42 = *(_QWORD *)(v38 + v37);
        if ( v42 )
        {
          v43 = *(void (__fastcall **)(_QWORD))(v42 + 32);
          if ( v43 )
          {
            if ( *((_DWORD *)v43 - 1) != 598888819 )
              __break(0x8229u);
            v43(&v48);
            v34 = a1[1];
          }
        }
      }
      ++v36;
      v37 += 320;
    }
    while ( v36 < v34 );
  }
  LODWORD(v18) = 0;
  --a1[8314];
LABEL_74:
  complete(a1 + 8280);
  mutex_unlock(a1 + 8264);
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v18;
}
