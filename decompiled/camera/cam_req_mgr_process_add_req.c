__int64 __fastcall cam_req_mgr_process_add_req(_DWORD *a1, __int64 a2)
{
  __int64 v2; // x24
  _DWORD *v3; // x27
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x23
  unsigned int slot_for_req; // w0
  unsigned int v10; // w21
  __int64 v11; // x25
  unsigned int v12; // w0
  __int64 v13; // x24
  __int64 v14; // x7
  __int64 v15; // x28
  unsigned int v16; // w0
  __int64 v17; // x7
  unsigned int v18; // w0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 result; // x0
  int v22; // w9
  __int64 v23; // x1
  unsigned int v24; // w0
  int v25; // w8
  __int64 v26; // x28
  __int64 v27; // x25
  __int64 v28; // x9
  unsigned int v29; // w11
  _QWORD *v30; // x9
  unsigned int v31; // w10
  __int64 v32; // x9
  _DWORD *v33; // x9
  unsigned int v34; // w6
  int v35; // w9
  __int64 v36; // x9
  __int64 v37; // x6
  unsigned int v38; // w20
  __int64 v39; // x6
  __int64 v40; // x6
  unsigned __int64 StatusReg; // x25
  __int64 v42; // x0
  __int64 v43; // x8
  _QWORD v44[2]; // [xsp+28h] [xbp-178h] BYREF
  __int64 v45; // [xsp+38h] [xbp-168h]
  __int64 v46; // [xsp+40h] [xbp-160h]
  __int64 v47; // [xsp+48h] [xbp-158h]
  __int64 v48; // [xsp+50h] [xbp-150h]
  __int64 v49; // [xsp+58h] [xbp-148h]
  _QWORD s[40]; // [xsp+60h] [xbp-140h] BYREF

  s[38] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x130u);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44[1] = 0;
  v45 = 0;
  v44[0] = 0;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_process_add_req",
      3458,
      "input args NULL %pK %pK",
      (const void *)a2,
      a1);
LABEL_41:
    result = 4294967274LL;
    goto LABEL_42;
  }
  v6 = (unsigned int)a1[1];
  if ( (int)v6 < 1 )
    goto LABEL_37;
  v7 = *((_QWORD *)a1 + 5);
  while ( *(_DWORD *)v7 != *(_DWORD *)(a2 + 12) )
  {
    --v6;
    v7 += 320;
    if ( !v6 )
      goto LABEL_37;
  }
  v8 = *(_QWORD *)(v7 + 16);
  if ( !v8 )
  {
LABEL_37:
    if ( (unsigned int)__ratelimit(&cam_req_mgr_process_add_req__rs, "cam_req_mgr_process_add_req") )
      v20 = 3;
    else
      v20 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v20,
      16,
      1,
      "cam_req_mgr_process_add_req",
      3478,
      "dev_hdl not found %x, %x %x",
      *(_DWORD *)(a2 + 12),
      **((_DWORD **)a1 + 5),
      *(_DWORD *)(*((_QWORD *)a1 + 5) + 320LL));
    goto LABEL_41;
  }
  mutex_lock(a1 + 8264);
  slot_for_req = _cam_req_mgr_find_slot_for_req(*((int **)a1 + 6), *(_QWORD *)(a2 + 16));
  if ( (slot_for_req & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_process_add_req",
      3495,
      "Req_id %lld not found in in_q for dev %s on link 0x%x",
      *(_QWORD *)(a2 + 16),
      (const char *)(v7 + 28),
      *a1);
    mutex_unlock(a1 + 8264);
    result = 4294967239LL;
    goto LABEL_42;
  }
  v10 = slot_for_req;
  if ( slot_for_req >= 0x31 )
    goto LABEL_77;
  v11 = *((_QWORD *)a1 + 6);
  if ( *(_BYTE *)(a2 + 33) == 1 )
  {
    v12 = _cam_req_mgr_find_slot_for_req(*((int **)a1 + 6), *(_QWORD *)(a2 + 16) + 1LL);
    if ( (v12 & 0x80000000) == 0 )
    {
      if ( v12 > 0x30 )
        goto LABEL_77;
      v13 = *((_QWORD *)a1 + 6) + 72LL * v12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        2,
        "cam_req_mgr_process_add_req",
        3508,
        "Skip requested on req: %u skipping for req: %u idx: %u",
        *(_QWORD *)(a2 + 16),
        *(_QWORD *)(a2 + 16) + 1,
        v12);
      *(_BYTE *)(v13 + 77) = 1;
    }
  }
  v14 = *(unsigned __int8 *)(a2 + 24);
  v3 = &unk_393000;
  v2 = v8 + 48LL * v10 + 40;
  v15 = v11 + 72LL * v10;
  if ( (unsigned int)v14 > *(_DWORD *)(v8 + 48LL * v10 + 56) )
  {
    *(_DWORD *)(v8 + 48LL * v10 + 56) = v14;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "cam_req_mgr_process_add_req",
        3520,
        "Req_id %llu injecting delay %llu frame at SOF by %s on link 0x%x",
        *(_QWORD *)(a2 + 16),
        v14,
        (const char *)(v7 + 28),
        *a1);
    if ( *(_DWORD *)(v15 + 32) == 1 )
    {
      v16 = cam_req_mgr_sync_info_for_sync_mode((__int64)a1, a2 + 8, v8 + 48LL * v10 + 40, 0);
      if ( (v16 & 0x80000000) != 0 )
      {
        v37 = *(_QWORD *)(a2 + 16);
        v38 = v16;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, __int64, _DWORD))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_process_add_req",
          3531,
          "Req_id %llu injecting delay %llu failed frame at SOF by %s for sync link 0x%x",
          v37,
          *(unsigned int *)(v8 + 48LL * v10 + 56),
          v7 + 28,
          *a1);
        goto LABEL_76;
      }
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "cam_req_mgr_process_add_req",
          3540,
          "Req_id %llu injecting delay %llu frame at SOF by %s for sync link 0x%x",
          *(_QWORD *)(a2 + 16),
          *(unsigned int *)(v8 + 48LL * v10 + 56),
          (const char *)(v7 + 28),
          *a1);
    }
  }
  v17 = *(unsigned __int8 *)(a2 + 28);
  if ( (unsigned int)v17 > *(_DWORD *)(v8 + 48LL * v10 + 60) )
  {
    *(_DWORD *)(v8 + 48LL * v10 + 60) = v17;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "cam_req_mgr_process_add_req",
        3552,
        "Req_id %llu injecting delay %llu frame at EOF by %s on link 0x%x",
        *(_QWORD *)(a2 + 16),
        v17,
        (const char *)(v7 + 28),
        *a1);
    if ( *(_DWORD *)(v15 + 32) == 1 )
    {
      v18 = cam_req_mgr_sync_info_for_sync_mode((__int64)a1, a2 + 8, v8 + 48LL * v10 + 40, 1);
      if ( (v18 & 0x80000000) != 0 )
      {
        v39 = *(_QWORD *)(a2 + 16);
        v38 = v18;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, __int64, _DWORD))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_process_add_req",
          3563,
          "Req_id %llu injecting delay %llu failed frame at EOF by %s for sync link 0x%x",
          v39,
          *(unsigned int *)(v8 + 48LL * v10 + 60),
          v7 + 28,
          *a1);
        goto LABEL_76;
      }
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "cam_req_mgr_process_add_req",
          3572,
          "Req_id %llu injecting delay %llu frame at EOF by %s for sync link 0x%x",
          *(_QWORD *)(a2 + 16),
          *(unsigned int *)(v8 + 48LL * v10 + 60),
          (const char *)(v7 + 28),
          *a1);
    }
  }
  if ( *(_BYTE *)(a2 + 32) == 1 )
  {
    v19 = *(unsigned int *)(v8 + 48LL * v10 + 64);
    *(_BYTE *)(v8 + 48LL * v10 + 84) = 1;
    if ( (_DWORD)v19 == 4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16777232,
        1,
        "cam_req_mgr_process_add_req",
        3582,
        "Req_id %llu slot:%d already has %d devices, can't add more",
        *(_QWORD *)(a2 + 16),
        v10,
        4);
      mutex_unlock(a1 + 8264);
      goto LABEL_41;
    }
    v22 = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v8 + 48LL * v10 + 64) = v19 + 1;
    if ( (unsigned int)v19 <= 3 )
    {
      *(_DWORD *)(v2 + 4 * v19 + 28) = v22;
      v23 = debug_mdl & 0x1000010;
      if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v23,
          4,
          "cam_req_mgr_process_add_req",
          3591,
          "Req_id %llu slot:%d added for EOF trigger for Device: %s on link 0x%x, property_mask: 0x%x",
          *(_QWORD *)(a2 + 16),
          v10,
          (const char *)(v7 + 28),
          *a1,
          a1[8341]);
      if ( *(_DWORD *)(v15 + 32) != 1 )
        goto LABEL_53;
      v24 = cam_req_mgr_sync_info_for_sync_mode((__int64)a1, a2 + 8, v8 + 48LL * v10 + 40, 2);
      if ( (v24 & 0x80000000) == 0 )
      {
        v23 = debug_mdl & 0x1000010;
        if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v23,
            4,
            "cam_req_mgr_process_add_req",
            3611,
            "Req_id %llu slot:%d added for EOF tigger for Device: %s for sync link 0x%x",
            *(_QWORD *)(a2 + 16),
            v10,
            (const char *)(v7 + 28),
            *a1);
LABEL_53:
        if ( (a1[8341] & 1) == 0 )
        {
          v25 = a1[1];
          if ( v25 >= 1 )
          {
            v26 = 0;
            v27 = 304;
            do
            {
              v28 = *((_QWORD *)a1 + 5);
              HIDWORD(v45) = 10;
              v29 = *a1;
              v30 = (_QWORD *)(v28 + v27);
              v31 = *((_DWORD *)v30 - 76);
              LOBYTE(v46) = 1;
              v44[0] = __PAIR64__(v31, v29);
              v32 = *v30;
              if ( v32 )
              {
                v33 = *(_DWORD **)(v32 + 40);
                if ( v33 )
                {
                  if ( *(v33 - 1) != -662406558 )
                    __break(0x8229u);
                  ((void (__fastcall *)(_QWORD *, __int64))v33)(v44, v23);
                  v25 = a1[1];
                }
              }
              ++v26;
              v27 += 320;
            }
            while ( v26 < v25 );
          }
        }
        goto LABEL_62;
      }
      v40 = *(_QWORD *)(a2 + 16);
      v38 = v24;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, __int64, _DWORD))cam_print_log)(
        3,
        0x1000000,
        1,
        "cam_req_mgr_process_add_req",
        3602,
        "Req_id %llu slot:%d added failed for EOF tigger for Device: %s for sync link 0x%x",
        v40,
        v10,
        v7 + 28,
        *a1);
LABEL_76:
      mutex_unlock(a1 + 8264);
      result = v38;
      goto LABEL_42;
    }
LABEL_77:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v42 = _traceiter_cam_req_mgr_add_req(0, a1, v10, a2 + 8, v8, v7);
      v43 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v43;
      if ( !v43 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v42);
    }
    goto LABEL_67;
  }
LABEL_62:
  v34 = *(_DWORD *)(v8 + 48LL * v10 + 52);
  if ( v34 >= 2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      2,
      "cam_req_mgr_process_add_req",
      3638,
      "Unexpected state %d for slot %d map %x for dev %s on link 0x%x",
      v34,
      v10,
      *(_DWORD *)(v8 + 48LL * v10 + 44),
      (const char *)(v7 + 28),
      *a1);
  v3 = &unk_393000;
  *(_DWORD *)(v8 + 48LL * v10 + 52) = 1;
  v35 = *(_DWORD *)(v8 + 48LL * v10 + 44) | (1LL << *(_QWORD *)(v7 + 8));
  *(_DWORD *)(v8 + 48LL * v10 + 44) = v35;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_process_add_req",
      3646,
      "idx %d dev_hdl %x req_id %lld pd %d ready_map %x on link 0x%x",
      v10,
      *(_DWORD *)(a2 + 12),
      *(_QWORD *)(a2 + 16),
      *(_DWORD *)(v8 + 4),
      v35,
      *a1);
LABEL_67:
  if ( *(_DWORD *)(v2 + 4) == *(_DWORD *)(v8 + 12) )
  {
    if ( (debug_mdl & 0x1000010) != 0 && !v3[919] )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000010,
        4,
        "cam_req_mgr_process_add_req",
        3653,
        "link 0x%x idx %d req_id %lld pd %d SLOT READY",
        *a1,
        v10,
        *(_QWORD *)(a2 + 16),
        *(_DWORD *)(v8 + 4));
    *(_DWORD *)(v2 + 12) = 2;
    v36 = *(_QWORD *)(a2 + 16);
    LODWORD(s[2]) = -1;
    LODWORD(s[0]) = 0;
    s[1] = v36;
    s[3] = -1;
    ((void (__fastcall *)(_DWORD *, _QWORD *))_cam_req_mgr_update_state_monitor_array)(a1, s);
  }
  mutex_unlock(a1 + 8264);
  result = 0;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
