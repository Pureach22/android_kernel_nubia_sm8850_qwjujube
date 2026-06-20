__int64 __fastcall _cam_isp_ctx_apply_pending_req(__int64 a1)
{
  __int64 v1; // x23
  _QWORD *v2; // x19
  __int64 v3; // x24
  __int64 *v4; // x25
  __int64 result; // x0
  _QWORD *v7; // x20
  __int64 v8; // x8
  __int64 v9; // x9
  int v10; // w11
  __int64 v11; // x27
  _QWORD *v12; // x8
  __int64 v13; // x9
  __int64 v14; // x2
  _QWORD *v15; // x1
  __int64 *v16; // x8
  __int64 (__fastcall *v17)(__int64, __int64 *); // x9
  __int64 v18; // x0
  unsigned int v19; // w0
  unsigned int v20; // w26
  __int64 v21; // x0
  __int64 v22; // [xsp+18h] [xbp-48h] BYREF
  __int64 v23; // [xsp+20h] [xbp-40h]
  __int64 v24; // [xsp+28h] [xbp-38h]
  __int64 v25; // [xsp+30h] [xbp-30h]
  __int64 v26; // [xsp+38h] [xbp-28h]
  __int64 v27; // [xsp+40h] [xbp-20h]
  __int64 v28; // [xsp+48h] [xbp-18h]
  __int64 v29; // [xsp+50h] [xbp-10h]
  __int64 v30; // [xsp+58h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  if ( !a1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_apply_pending_req",
      3390,
      "Invalid ctx_isp:%pK",
      nullptr);
    result = 4294967274LL;
    goto LABEL_39;
  }
  v1 = *(_QWORD *)a1;
  v2 = (_QWORD *)(*(_QWORD *)a1 + 144LL);
  if ( (_QWORD *)*v2 != v2 )
  {
    v3 = a1 + 45560;
    v4 = (__int64 *)(a1 + 37296);
    if ( *(_BYTE *)(a1 + 45738) == 1 )
    {
      if ( *(_DWORD *)(a1 + 20) == 1 || *(int *)(a1 + 37320) > 0 )
        goto LABEL_38;
    }
    else if ( *(_DWORD *)(v1 + 240) != 5
           || !*(_DWORD *)(a1 + 45584)
           || *(_DWORD *)(a1 + 20) == 1
           || *(int *)(a1 + 37320) > 1 )
    {
      goto LABEL_38;
    }
    raw_spin_lock_bh(v1 + 120);
    v7 = *(_QWORD **)(v1 + 144);
    raw_spin_unlock_bh(v1 + 120);
    if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000008,
        4,
        "__cam_isp_ctx_apply_pending_req",
        3427,
        "Apply request %lld in substate %d ctx_idx: %u, link: 0x%x",
        v7[3],
        *(_DWORD *)(a1 + 20),
        *(_DWORD *)(v1 + 32),
        *(_DWORD *)(v1 + 64));
    v8 = v7[3];
    v9 = v7[4];
    v22 = *v4;
    v28 = v8;
    v24 = *(_QWORD *)(v9 + 8);
    LODWORD(v8) = *(unsigned __int8 *)(v3 + 178);
    v10 = *(_DWORD *)(v9 + 16);
    v27 = v9 + 80;
    LODWORD(v23) = v10;
    if ( (_DWORD)v8 == 1 )
      BYTE4(v29) = 1;
    raw_spin_lock_bh(v1 + 120);
    *(_DWORD *)(v3 + 24) = 0;
    *(_DWORD *)(a1 + 20) = 1;
    v11 = v4[7];
    v4[7] = v7[3];
    *(_DWORD *)v3 = 1;
    v12 = (_QWORD *)v7[1];
    if ( (_QWORD *)*v12 == v7 && (v13 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
    {
      *(_QWORD *)(v13 + 8) = v12;
      *v12 = v13;
    }
    else
    {
      _list_del_entry_valid_or_report(v7);
    }
    *v7 = v7;
    v14 = v1 + 160;
    v7[1] = v7;
    v15 = *(_QWORD **)(v1 + 168);
    if ( v7 == (_QWORD *)(v1 + 160) || v7 == v15 || *v15 != v14 )
    {
      _list_add_valid_or_report(v7);
    }
    else
    {
      *(_QWORD *)(v1 + 168) = v7;
      *v7 = v14;
      v7[1] = v15;
      *v15 = v7;
    }
    raw_spin_unlock_bh(v1 + 120);
    v16 = *(__int64 **)(v1 + 208);
    v17 = (__int64 (__fastcall *)(__int64, __int64 *))v16[9];
    v18 = *v16;
    if ( *((_DWORD *)v17 - 1) != 1863972096 )
      __break(0x8229u);
    v19 = v17(v18, &v22);
    if ( v19 )
    {
      v20 = v19;
      if ( (unsigned int)__ratelimit(&_cam_isp_ctx_apply_pending_req__rs, "__cam_isp_ctx_apply_pending_req") )
        v21 = 3;
      else
        v21 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v21,
        8,
        1,
        "__cam_isp_ctx_apply_pending_req",
        3461,
        "Can not apply the configuration,ctx: %u,link: 0x%x",
        *(_DWORD *)(v1 + 32),
        *(_DWORD *)(v1 + 64));
      raw_spin_lock_bh(v1 + 120);
      *(_DWORD *)(a1 + 20) = 0;
      v4[7] = v11;
      *(_DWORD *)v3 = 0;
      _list_del_entry(v7);
      *v7 = v7;
      v7[1] = v7;
      _list_add(v7, v2, *(_QWORD *)(v1 + 144));
      raw_spin_unlock_bh(v1 + 120);
      result = v20;
      goto LABEL_39;
    }
    *(_DWORD *)(v3 + 8) = 0;
    *(_DWORD *)v3 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_apply_pending_req",
        3477,
        "New substate state %d, applied req %lld, ctx: %u, link: 0x%x",
        1,
        v4[7],
        *(_DWORD *)(v1 + 32),
        *(_DWORD *)(v1 + 64));
    _cam_isp_ctx_update_state_monitor_array(a1, 1, v7[3]);
LABEL_38:
    result = 0;
    goto LABEL_39;
  }
  result = 4294967282LL;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_apply_pending_req",
      3399,
      "No pending requests to apply, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 64));
    result = 4294967282LL;
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
