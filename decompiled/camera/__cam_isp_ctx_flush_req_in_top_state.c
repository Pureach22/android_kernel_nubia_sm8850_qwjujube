__int64 __fastcall _cam_isp_ctx_flush_req_in_top_state(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  char v5; // w9
  _QWORD *v6; // x9
  __int64 v7; // x10
  __int64 *v8; // x24
  unsigned int v9; // w21
  char v10; // w8
  __int64 v11; // x9
  __int64 *v12; // x10
  char v13; // w8
  __int64 (__fastcall *v14)(__int64, __int64 *); // x8
  __int64 v15; // x0
  int v16; // w0
  __int64 v17; // x8
  void (__fastcall *v18)(_QWORD); // x8
  unsigned int v19; // w9
  unsigned int v20; // w10
  __int64 *v21; // x9
  __int64 (__fastcall *v22)(__int64, __int64 *); // x8
  __int64 v23; // x0
  unsigned __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  int v26; // [xsp+10h] [xbp-30h]
  __int64 v27; // [xsp+18h] [xbp-28h] BYREF
  __int64 v28; // [xsp+20h] [xbp-20h] BYREF
  _QWORD *v29; // [xsp+28h] [xbp-18h]
  _QWORD v30[2]; // [xsp+30h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 256);
  v5 = *(_BYTE *)(a2 + 24);
  v30[0] = 0;
  v28 = 0;
  v29 = nullptr;
  v27 = 0;
  v26 = 0;
  v25 = 0;
  *(_BYTE *)(v4 + 45753) = v5;
  v6 = *(_QWORD **)(*(_QWORD *)(a1 + 256) + 45720LL);
  v7 = *(_QWORD *)(a1 + 256) + 45720LL;
  for ( *(_QWORD *)(*(_QWORD *)(a1 + 256) + 45712LL) = 0; v6 != (_QWORD *)v7; v6 = (_QWORD *)*v6 )
    *((_DWORD *)v6 - 2) = 0;
  v8 = (__int64 *)(v4 + 37296);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_reset_fcg_tracker",
      6799,
      "Reset FCG skip info on ctx %u link: %x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    if ( *(_DWORD *)(a2 + 8) )
    {
LABEL_6:
      v9 = 0;
      v10 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
      {
LABEL_33:
        raw_spin_lock_bh(a1 + 120);
        _cam_isp_ctx_flush_req(a1, a1 + 144, a2);
        raw_spin_unlock_bh(a1 + 120);
        goto LABEL_34;
      }
LABEL_31:
      if ( !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v10 & 8,
          4,
          "__cam_isp_ctx_flush_req_in_top_state",
          6882,
          "Flush pending list, ctx_idx: %u, link: 0x%x",
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
      goto LABEL_33;
    }
  }
  else if ( *(_DWORD *)(a2 + 8) )
  {
    goto LABEL_6;
  }
  if ( *(_DWORD *)(a1 + 240) > 3u )
  {
    raw_spin_lock_bh(a1 + 120);
    *(_DWORD *)(a1 + 240) = 4;
    *(_DWORD *)(v4 + 20) = 6;
    raw_spin_unlock_bh(a1 + 120);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_ctx_flush_req_in_top_state",
      6831,
      "Last request id to flush is %lld, ctx_id:%u link: 0x%x",
      *(_QWORD *)(a2 + 16),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    *(_DWORD *)(a1 + 464) = *(_QWORD *)(a2 + 16);
    _cam_isp_ctx_trigger_reg_dump(2u, a1, 0);
    v11 = *v8;
    LODWORD(v30[0]) = 1;
    WORD2(v30[0]) = 256;
    v12 = *(__int64 **)(a1 + 208);
    v28 = v11;
    v13 = *(_BYTE *)(v4 + 45753);
    v29 = v30;
    BYTE6(v30[0]) = v13;
    v14 = (__int64 (__fastcall *)(__int64, __int64 *))v12[6];
    v15 = *v12;
    if ( *((_DWORD *)v14 - 1) != 1863972096 )
      __break(0x8228u);
    v16 = v14(v15, &v28);
    if ( v16 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_flush_req_in_top_state",
        6846,
        "Failed to stop HW in Flush rc: %d, ctx_id:%u link: 0x%x",
        v16,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_ctx_flush_req_in_top_state",
      6849,
      "Stop HW complete. Reset HW next.Ctx_id:%u link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_flush_req_in_top_state",
        6851,
        "Flush wait and active lists, ctx_id:%u link: 0x%x",
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      v17 = *(_QWORD *)(a1 + 216);
      if ( !v17 )
        goto LABEL_22;
    }
    else
    {
      v17 = *(_QWORD *)(a1 + 216);
      if ( !v17 )
        goto LABEL_22;
    }
    v18 = *(void (__fastcall **)(_QWORD))(v17 + 24);
    if ( v18 )
    {
      v20 = *(_DWORD *)(a1 + 60);
      v19 = *(_DWORD *)(a1 + 64);
      LOBYTE(v26) = 0;
      v25 = __PAIR64__(v20, v19);
      if ( *((_DWORD *)v18 - 1) != -1398328256 )
        __break(0x8228u);
      v18(&v25);
    }
LABEL_22:
    raw_spin_lock_bh(a1 + 120);
    if ( *(_QWORD *)(a1 + 160) != a1 + 160 )
      _cam_isp_ctx_flush_req(a1, a1 + 160, a2);
    if ( *(_QWORD *)(a1 + 128) != a1 + 128 )
      _cam_isp_ctx_flush_req(a1, a1 + 128, a2);
    *(_DWORD *)(v4 + 37320) = 0;
    raw_spin_unlock_bh(a1 + 120);
    v21 = *(__int64 **)(a1 + 208);
    v27 = *v8;
    v22 = (__int64 (__fastcall *)(__int64, __int64 *))v21[16];
    v23 = *v21;
    if ( *((_DWORD *)v22 - 1) != 1863972096 )
      __break(0x8228u);
    v9 = v22(v23, &v27);
    if ( v9 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_flush_req_in_top_state",
        6877,
        "Failed to reset HW rc: %d, ctx_id:%u link: 0x%x",
        v9,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
    *(_BYTE *)(v4 + 45741) = 0;
    v10 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_33;
    goto LABEL_31;
  }
  v9 = 0;
  *(_DWORD *)(a1 + 240) = 2;
LABEL_34:
  *(_DWORD *)(v4 + 37376) = 0;
  *(_DWORD *)(v4 + 37388) = 0;
  *(_BYTE *)(v4 + 45746) = 0;
  *(_DWORD *)(v4 + 45700) = 0;
  *(_DWORD *)(v4 + 24) = 0;
  *(_DWORD *)(v4 + 45584) = 0;
  _ReadStatusReg(SP_EL0);
  *(_DWORD *)(v4 + 45572) = 0;
  return v9;
}
