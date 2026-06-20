__int64 __fastcall _cam_isp_ctx_apply_default_settings(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  int v3; // w6
  int v4; // w7
  __int64 result; // x0
  __int64 v7; // x19
  int v8; // w25
  __int64 v9; // x25
  __int64 v10; // x6
  char v11; // w8
  __int64 v12; // x1
  __int64 v13; // x26
  __int64 v14; // x25
  __int64 v15; // x1
  __int64 v16; // x8
  __int64 (__fastcall *v17)(__int64, __int64); // x9
  unsigned int v18; // w20
  __int64 v19; // x21
  __int64 v20; // x0
  __int64 v21; // x0

  v2 = *(_QWORD *)(a1 + 256);
  v3 = *(_DWORD *)(a2 + 28);
  v4 = *(_DWORD *)(v2 + 37344);
  if ( (v4 & v3) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_apply_default_settings",
      10227,
      "Trigger: %u not subscribed for: %u, ctx: %u link: 0x%x",
      v3,
      v4,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    return 0;
  }
  if ( v3 != 1 )
    return 0;
  if ( *(_DWORD *)(v2 + 45572) )
    return _cam_isp_ctx_reset_and_recover();
  if ( *(_QWORD *)(v2 + 8) != 1 )
    ++*(_DWORD *)(v2 + 45712);
  v7 = a1;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_apply_default_settings",
      10244,
      "Apply default settings, number of previous continuous skipped frames: %d, ctx_id: %d",
      *(_DWORD *)(v2 + 45712),
      *(_DWORD *)(a1 + 32));
    a1 = v7;
  }
  v8 = *(_DWORD *)(v2 + 45756);
  raw_spin_lock_bh(a1 + 120);
  if ( !v8 )
  {
    v13 = *(_QWORD *)(v7 + 128);
    raw_spin_unlock_bh(v7 + 120);
    if ( v13 == v7 + 128 || !v13 )
    {
      v15 = a2;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_handle_reg_dump",
          6218,
          "No active req, hence not doing reg_dump for ctx id %d",
          *(_DWORD *)(v7 + 32));
        v15 = a2;
      }
    }
    else
    {
      v14 = *(_QWORD *)(v13 + 32);
      v15 = a2;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_handle_reg_dump",
          6210,
          "Handling reg dump for active req %llu, ctx %d",
          *(_QWORD *)(v13 + 24),
          *(_DWORD *)(v7 + 32));
        v15 = a2;
      }
      if ( (*(_BYTE *)(v14 + 4506) & 1) == 0 )
      {
        _cam_isp_ctx_trigger_reg_dump(4u, v7, v14 + 80);
        v15 = a2;
        *(_BYTE *)(v14 + 4506) = 1;
      }
    }
    v16 = v7;
    if ( (*(_BYTE *)(v2 + 45747) & 1) != 0 || *(_BYTE *)(v2 + 45751) == 1 && *(_BYTE *)(v2 + 45750) == 1 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_apply_default_settings",
          10277,
          "Enter: apply req in Substate:%d request _id:%lld ctx:%u on link:0x%x",
          *(_DWORD *)(v2 + 20),
          *(_QWORD *)(v15 + 8),
          *(_DWORD *)(v7 + 32),
          *(_DWORD *)(v7 + 64));
        v15 = a2;
        v16 = v7;
      }
      v17 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v2 + 32) + 192LL * *(unsigned int *)(v2 + 20) + 104);
      if ( v17 )
      {
        if ( *((_DWORD *)v17 - 1) != -289573293 )
          __break(0x8229u);
        result = v17(v16, v15);
        v18 = result;
        if ( !(_DWORD)result )
          goto LABEL_47;
      }
      else
      {
        v19 = v16;
        if ( (unsigned int)__ratelimit(&_cam_isp_ctx_apply_default_settings__rs, "__cam_isp_ctx_apply_default_settings") )
          v20 = 3;
        else
          v20 = 2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          v20,
          8,
          2,
          "__cam_isp_ctx_apply_default_settings",
          10286,
          "No handle function in activated substate %d, ctx:%u on link:0x%x",
          *(_DWORD *)(v2 + 20),
          *(_DWORD *)(v19 + 32),
          *(_DWORD *)(v19 + 64));
        v18 = -14;
      }
      if ( (unsigned int)__ratelimit(
                           &_cam_isp_ctx_apply_default_settings__rs_704,
                           "__cam_isp_ctx_apply_default_settings") )
        v21 = 3;
      else
        v21 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v21,
        8,
        2,
        "__cam_isp_ctx_apply_default_settings",
        10293,
        "Apply default failed in active substate %d rc %d ctx: %u link: 0x%x",
        *(_DWORD *)(v2 + 20),
        v18,
        *(_DWORD *)(v7 + 32),
        *(_DWORD *)(v7 + 64));
      result = v18;
LABEL_47:
      *(_DWORD *)(v2 + 45568) = 1;
      return result;
    }
    return 0;
  }
  v9 = *(_QWORD *)(v7 + 144);
  raw_spin_unlock_bh(v7 + 120);
  v10 = *(_QWORD *)(v9 + 24);
  v11 = debug_mdl;
  v12 = a2;
  *(_QWORD *)(a2 + 8) = v10;
  if ( (v11 & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v11 & 8,
      4,
      "__cam_isp_ctx_apply_default_settings",
      10255,
      "Apply request:%lld in Substate:%d on link:0x%x",
      v10,
      *(_DWORD *)(v2 + 20),
      *(_DWORD *)(v7 + 32));
    v12 = a2;
  }
  --*(_DWORD *)(v2 + 45756);
  return _cam_isp_ctx_apply_req_in_epoch(v7, v12);
}
