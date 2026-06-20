__int64 __fastcall _cam_isp_ctx_validate_for_req_reapply_util(__int64 a1)
{
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x19
  _QWORD *v4; // x26
  _QWORD *v5; // x8
  _QWORD *v6; // x27
  _QWORD *v7; // x23
  __int64 v8; // x8
  char v9; // w8
  __int64 v10; // x11
  _QWORD *v11; // x9
  unsigned int v12; // w10
  __int64 v13; // x11
  int v14; // w13
  int v15; // w12
  _QWORD *v16; // x23
  _QWORD *v17; // x26
  _QWORD *v18; // x22
  __int64 v19; // x8
  __int64 result; // x0
  unsigned int v21; // w20

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)a1;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFF0100) == 0 )
    raw_spin_lock_bh(v2 + 120);
  v4 = (_QWORD *)(v2 + 128);
  if ( *(_QWORD *)(v2 + 128) == v2 + 128 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_validate_for_req_reapply_util",
        4571,
        "Active request list empty for ctx: %u on link: 0x%x",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    if ( *(_QWORD *)(v2 + 160) == v2 + 160 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_validate_for_req_reapply_util",
        4576,
        "No active/wait req for ctx: %u on link: 0x%x start from pending",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
LABEL_42:
      result = 0;
      goto LABEL_43;
    }
  }
  if ( (_QWORD *)*v4 == v4 || (v5 = *(_QWORD **)(v2 + 136), v5 == v4) )
  {
LABEL_10:
    if ( (_QWORD *)*v4 != v4 )
    {
      v6 = *(_QWORD **)(v2 + 136);
      while ( v6 != v4 )
      {
        v7 = v6;
        v6 = (_QWORD *)v6[1];
        if ( (_QWORD *)*v6 == v7 && (v8 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
        {
          *(_QWORD *)(v8 + 8) = v6;
          *v6 = v8;
        }
        else
        {
          _list_del_entry_valid_or_report(v7);
        }
        *v7 = v7;
        v7[1] = v7;
        _cam_isp_ctx_enqueue_request_in_order(v2, v7, 0);
        v9 = debug_mdl;
        --*(_DWORD *)(a1 + 37320);
        if ( (v9 & 8) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v9 & 8,
            4,
            "__cam_isp_ctx_validate_for_req_reapply_util",
            4610,
            "ctx:%u link:0x%x move active req %llu to pending",
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64),
            v7[3]);
      }
    }
    v16 = (_QWORD *)(v2 + 160);
    if ( *(_QWORD *)(v2 + 160) != v2 + 160 )
    {
      v17 = *(_QWORD **)(v2 + 168);
      while ( v17 != v16 )
      {
        v18 = v17;
        v17 = (_QWORD *)v17[1];
        if ( (_QWORD *)*v17 == v18 && (v19 = *v18, *(_QWORD **)(*v18 + 8LL) == v18) )
        {
          *(_QWORD *)(v19 + 8) = v17;
          *v17 = v19;
        }
        else
        {
          _list_del_entry_valid_or_report(v18);
        }
        *v18 = v18;
        v18[1] = v18;
        _cam_isp_ctx_enqueue_request_in_order(v2, v18, 0);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_validate_for_req_reapply_util",
            4620,
            "ctx:%u link:0x%x move wait req %llu to pending",
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64),
            v18[3]);
      }
    }
    goto LABEL_42;
  }
  while ( 1 )
  {
    v10 = v5[4];
    v11 = (_QWORD *)v5[1];
    v12 = *(_DWORD *)(v10 + 32);
    if ( v12 )
    {
      v13 = *(_QWORD *)(v10 + 24);
      if ( *(_DWORD *)(v13 + 16) == -1 )
        break;
      v14 = 1;
      do
      {
        v15 = v14;
        if ( v12 == v14 )
          break;
        ++v14;
      }
      while ( *(_DWORD *)(v13 + ((__int64)v15 << 6) + 16) != -1 );
      if ( v15 < v12 )
        break;
    }
    v5 = (_QWORD *)v5[1];
    if ( v11 == v4 )
      goto LABEL_10;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    2,
    "__cam_isp_ctx_validate_for_req_reapply_util",
    4595,
    "Req: %llu in ctx:%u on link: 0x%x fence has partially signaled, cannot do recovery",
    v5[3],
    *(_DWORD *)(v2 + 32),
    *(_DWORD *)(v2 + 64));
  result = 4294967274LL;
LABEL_43:
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFF0100) == 0 )
  {
    v21 = result;
    raw_spin_unlock_bh(v2 + 120);
    return v21;
  }
  return result;
}
