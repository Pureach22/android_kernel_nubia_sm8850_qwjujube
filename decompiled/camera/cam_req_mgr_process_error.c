__int64 __fastcall cam_req_mgr_process_error(__int64 a1, __int64 a2)
{
  __int64 v4; // x9
  int *v5; // x21
  __int64 v6; // x28
  int v7; // w8
  unsigned int v8; // w0
  unsigned int slot_for_req; // w0
  int *v10; // x27
  __int64 v11; // x8
  int v12; // w7
  __int64 v13; // x24
  int v14; // w26
  char v15; // w8
  int v16; // w9
  int v17; // w7
  __int64 result; // x0
  __int64 v19; // x0
  __int64 v20; // x9
  int *v21; // x8
  unsigned int v22; // w8
  int v23; // w9
  int v24; // w23
  int v25; // w8
  int v26; // w9
  int v27; // w8
  unsigned int v28; // w20
  int v29; // w24
  int *v30; // x8
  _DWORD *v31; // x8
  int v32; // t1
  __int64 v33; // x8
  __int64 v34; // x9
  unsigned int v35; // [xsp+24h] [xbp-17Ch] BYREF
  _DWORD v36[2]; // [xsp+28h] [xbp-178h] BYREF
  __int64 v37; // [xsp+30h] [xbp-170h]
  __int64 v38; // [xsp+38h] [xbp-168h]
  __int64 v39; // [xsp+40h] [xbp-160h]
  __int64 v40; // [xsp+48h] [xbp-158h]
  __int64 v41; // [xsp+50h] [xbp-150h]
  __int64 v42; // [xsp+58h] [xbp-148h]
  _QWORD s[40]; // [xsp+60h] [xbp-140h] BYREF

  s[38] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = -1;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_process_error",
      3749,
      "input args NULL %pK %pK",
      (const void *)a2,
      (const void *)a1);
    result = 4294967274LL;
    goto LABEL_54;
  }
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_process_error",
      3760,
      "link_hdl %x req_id %lld error %d",
      *(_DWORD *)(a2 + 8),
      *(_QWORD *)(a2 + 16),
      *(_DWORD *)(a2 + 48));
  memset(s, 0, 0x130u);
  v4 = *(_QWORD *)(a2 + 16);
  v5 = *(int **)(a1 + 48);
  v6 = *(_QWORD *)(a1 + 56);
  LODWORD(s[0]) = 5;
  LODWORD(s[2]) = -1;
  s[1] = v4;
  s[3] = -1;
  ((void (__fastcall *)(__int64, _QWORD *))_cam_req_mgr_update_state_monitor_array)(a1, s);
  mutex_lock(a1 + 33056);
  v7 = *(_DWORD *)(a2 + 48);
  if ( v7 != 7 )
  {
    if ( v7 == 2 )
    {
      v8 = _cam_req_mgr_send_evt(*(_QWORD *)(a2 + 16), 0, 2, (_DWORD *)a1);
    }
    else
    {
      v8 = 0;
      if ( v7 == 1 )
        goto LABEL_9;
    }
LABEL_53:
    v28 = v8;
    mutex_unlock(a1 + 33056);
    result = v28;
    goto LABEL_54;
  }
LABEL_9:
  slot_for_req = _cam_req_mgr_find_slot_for_req(v5, *(_QWORD *)(a2 + 16));
  v35 = slot_for_req;
  if ( (slot_for_req & 0x80000000) != 0 )
  {
    if ( (unsigned int)__ratelimit(&cam_req_mgr_process_error__rs, "cam_req_mgr_process_error") )
      v19 = 3;
    else
      v19 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v19,
      16,
      1,
      "cam_req_mgr_process_error",
      3779,
      "req_id %lld not found in input queue",
      *(_QWORD *)(a2 + 16));
    v8 = 0;
    goto LABEL_53;
  }
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_process_error",
      3782,
      "req_id %lld found at idx %d last_applied %d",
      *(_QWORD *)(a2 + 16),
      slot_for_req,
      v5[868]);
    slot_for_req = v35;
    if ( v35 >= 0x31 )
      goto LABEL_70;
  }
  else if ( slot_for_req >= 0x31 )
  {
    goto LABEL_70;
  }
  v10 = v5 + 2;
  v11 = (__int64)&v5[18 * slot_for_req + 2];
  if ( *(_DWORD *)(v11 + 12) )
  {
    v12 = *(_DWORD *)(v11 + 8);
    if ( v12 != 2 && v12 != 4 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        16,
        2,
        "cam_req_mgr_process_error",
        3794,
        "req_id %lld can not be recovered %d",
        *(_QWORD *)(a2 + 16));
      mutex_unlock(a1 + 33056);
      result = 4294967274LL;
      goto LABEL_54;
    }
    v13 = *(_QWORD *)(a1 + 56);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 4);
      v15 = debug_mdl;
      v16 = debug_priority;
      do
      {
        v17 = *(_DWORD *)(v13 + 4);
        *(_DWORD *)(v13 + 16) = v14 - v17;
        if ( (v15 & 0x10) != 0 && !v16 )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v15 & 0x10,
            4,
            "__cam_req_mgr_tbl_set_all_skip_cnt",
            803,
            "%d: pd %d skip_traverse %d delta %d",
            *(_DWORD *)v13,
            v17,
            v14 - v17,
            *(_DWORD *)(v13 + 32));
          v15 = debug_mdl;
          v16 = debug_priority;
        }
        v13 = *(_QWORD *)(v13 + 24);
      }
      while ( v13 );
      slot_for_req = v35;
    }
    v5[866] = slot_for_req;
    if ( *(_DWORD *)(a2 + 48) == 1 )
    {
      if ( slot_for_req > 0x2F )
        goto LABEL_70;
      ++v10[18 * slot_for_req + 13];
      slot_for_req = v35;
    }
    if ( slot_for_req > 0x2F )
LABEL_70:
      __break(0x5512u);
    v10[18 * slot_for_req + 2] = 1;
    if ( v6 )
    {
      while ( v35 <= 0x2F )
      {
        v20 = v6 + 48LL * v35;
        v6 = *(_QWORD *)(v6 + 24);
        *(_DWORD *)(v20 + 48) = 0;
        if ( !v6 )
          goto LABEL_37;
      }
      goto LABEL_70;
    }
LABEL_37:
    if ( *(_QWORD *)(a1 + 33224) )
    {
      if ( v35 > 0x2F )
        goto LABEL_70;
      v10[18 * v35 + 6] = 0;
      cam_common_inc_idx(&v35, 1, *(unsigned int *)(*(_QWORD *)(a1 + 56) + 36LL));
      if ( v35 > 0x2F )
        goto LABEL_70;
      v10[18 * v35 + 6] = 0;
    }
    if ( v35 > 0x2F )
      goto LABEL_70;
    v21 = &v10[18 * v35];
    if ( (unsigned int)v21[13] >= 2 && (v21[17] & 1) == 0 )
    {
      *(_BYTE *)(a1 + 33361) = 1;
      raw_spin_lock_bh(a1 + 33216);
      crm_timer_reset(*(_QWORD *)(a1 + 33112));
      *(_BYTE *)(*(_QWORD *)(a1 + 33112) + 64LL) = 1;
      raw_spin_unlock_bh(a1 + 33216);
      _cam_req_mgr_send_evt(*(_QWORD *)(a2 + 16), 5, 2, (_DWORD *)a1);
      raw_spin_lock_bh(a1 + 33216);
      crm_timer_reset(*(_QWORD *)(a1 + 33112));
      *(_BYTE *)(*(_QWORD *)(a1 + 33112) + 64LL) = 0;
      raw_spin_unlock_bh(a1 + 33216);
      if ( v35 > 0x2F )
        goto LABEL_70;
      LOBYTE(v10[18 * v35 + 17]) = 1;
      *(_BYTE *)(a1 + 33361) = 0;
    }
    v22 = v5[866];
    v23 = v5[868];
    v35 = v22;
    if ( v23 < 0 )
    {
      v24 = 1;
    }
    else
    {
      v24 = v23 - v22;
      if ( (int)(v23 - v22) < 0 )
        v24 += *(_DWORD *)(*(_QWORD *)(a1 + 56) + 36LL);
      if ( v24 < 1 )
      {
LABEL_50:
        raw_spin_lock_bh(a1 + 33216);
        *(_DWORD *)(a1 + 33152) = 3;
        raw_spin_unlock_bh(a1 + 33216);
        v25 = *(_DWORD *)(a1 + 33256);
        v41 = 0;
        v42 = 0;
        *(_DWORD *)(a1 + 33256) = v25 + 1;
        v37 = *(_QWORD *)(a2 + 24);
        v38 = 0;
        v26 = *(_DWORD *)(a2 + 12);
        v36[0] = *(_DWORD *)(a2 + 8);
        v36[1] = v26;
        v27 = *(_DWORD *)(a2 + 32);
        v39 = *(_QWORD *)(a2 + 40);
        v40 = 0;
        LODWORD(v38) = v27;
        if ( (unsigned int)_cam_req_mgr_process_req((unsigned int *)a1, (__int64)v36) )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            16,
            1,
            "__cam_req_mgr_apply_on_bubble",
            3694,
            "Failed to apply request on bubbled frame");
        v8 = 0;
        goto LABEL_53;
      }
    }
    v29 = 0;
    while ( 1 )
    {
      cam_common_inc_idx(&v35, 1, *(unsigned int *)(*(_QWORD *)(a1 + 56) + 36LL));
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      {
        if ( v35 > 0x2F )
          goto LABEL_70;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "cam_req_mgr_process_error",
          3871,
          "Recovery on idx: %d reset slot [idx: %d status: %d]",
          (unsigned int)v5[866]);
      }
      if ( v35 > 0x2F )
        goto LABEL_70;
      v30 = &v10[18 * v35];
      v32 = v30[2];
      v31 = v30 + 2;
      if ( v32 == 4 )
      {
        *v31 = 1;
        v33 = *(_QWORD *)(a1 + 56);
        if ( v33 )
          break;
      }
LABEL_58:
      if ( ++v29 == v24 )
        goto LABEL_50;
    }
    while ( v35 <= 0x2F )
    {
      v34 = v33 + 48LL * v35;
      v33 = *(_QWORD *)(v33 + 24);
      *(_DWORD *)(v34 + 48) = 0;
      if ( !v33 )
        goto LABEL_58;
    }
    goto LABEL_70;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    16,
    2,
    "cam_req_mgr_process_error",
    3787,
    "err recovery disabled req_id %lld",
    *(_QWORD *)(a2 + 16));
  mutex_unlock(a1 + 33056);
  result = 0;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
