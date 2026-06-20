__int64 __fastcall cam_context_apply_req_to_hw(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x2
  _QWORD *v7; // x1
  int v8; // w9
  __int64 v9; // x10
  __int64 v10; // x8
  int v11; // w9
  __int64 *v12; // x10
  __int64 v13; // x8
  __int64 (__fastcall *v14)(__int64, __int64 *); // x8
  __int64 v15; // x0
  __int64 result; // x0
  unsigned int v17; // w22
  _QWORD *v18; // x8
  __int64 v19; // x9
  __int64 v20; // x0
  __int64 v21; // x2
  _QWORD *v22; // x1
  __int64 v23; // [xsp+8h] [xbp-48h] BYREF
  __int64 v24; // [xsp+10h] [xbp-40h]
  __int64 v25; // [xsp+18h] [xbp-38h]
  __int64 v26; // [xsp+20h] [xbp-30h]
  __int64 v27; // [xsp+28h] [xbp-28h]
  __int64 v28; // [xsp+30h] [xbp-20h]
  __int64 v29; // [xsp+38h] [xbp-18h]
  __int64 v30; // [xsp+40h] [xbp-10h]
  __int64 v31; // [xsp+48h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[13];
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v2 = *(_QWORD *)(v1 + 208);
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  if ( v2 )
  {
    raw_spin_lock(v1 + 120);
    v4 = (_QWORD *)a1[1];
    if ( (_QWORD *)*v4 == a1 && (v5 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
    {
      *(_QWORD *)(v5 + 8) = v4;
      *v4 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(a1);
    }
    *a1 = a1;
    v6 = v1 + 128;
    a1[1] = a1;
    v7 = *(_QWORD **)(v1 + 136);
    if ( (_QWORD *)(v1 + 128) == a1 || v7 == a1 || *v7 != v6 )
    {
      _list_add_valid_or_report(a1);
    }
    else
    {
      *(_QWORD *)(v1 + 136) = a1;
      *a1 = v6;
      a1[1] = v7;
      *v7 = a1;
    }
    raw_spin_unlock(v1 + 120);
    if ( (*(_QWORD *)(v1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        3,
        "cam_context_apply_req_to_hw",
        307,
        "[%s][%d] : Moving req[%llu] from pending_list to active_list",
        (const char *)v1,
        *(_DWORD *)(v1 + 32),
        a1[3]);
    v8 = *((_DWORD *)a1 + 12);
    v9 = a1[5];
    v23 = *(_QWORD *)(v1 + 264);
    v10 = a1[9];
    LODWORD(v24) = v8;
    v11 = *((_DWORD *)a1 + 20);
    v25 = v9;
    v26 = v10;
    v12 = *(__int64 **)(v1 + 208);
    LODWORD(v27) = v11;
    v13 = a1[3];
    v28 = a1[4];
    v29 = v13;
    v14 = (__int64 (__fastcall *)(__int64, __int64 *))v12[9];
    v15 = *v12;
    if ( *((_DWORD *)v14 - 1) != 1863972096 )
      __break(0x8228u);
    result = v14(v15, &v23);
    if ( (_DWORD)result )
    {
      v17 = result;
      cam_smmu_buffer_tracker_putref(a1 + 14);
      raw_spin_lock(v1 + 120);
      v18 = (_QWORD *)a1[1];
      if ( (_QWORD *)*v18 == a1 && (v19 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
      {
        *(_QWORD *)(v19 + 8) = v18;
        *v18 = v19;
      }
      else
      {
        _list_del_entry_valid_or_report(a1);
      }
      *a1 = a1;
      a1[1] = a1;
      raw_spin_unlock(v1 + 120);
      v20 = a1[17];
      if ( v20 )
      {
        cam_common_mem_free(v20);
        a1[17] = 0;
      }
      raw_spin_lock(v1 + 120);
      v21 = v1 + 176;
      v22 = *(_QWORD **)(v1 + 184);
      if ( (_QWORD *)(v1 + 176) == a1 || v22 == a1 || *v22 != v21 )
      {
        _list_add_valid_or_report(a1);
      }
      else
      {
        *(_QWORD *)(v1 + 184) = a1;
        *a1 = v21;
        a1[1] = v22;
        *v22 = a1;
      }
      raw_spin_unlock(v1 + 120);
      if ( (*(_QWORD *)(v1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x80000,
          3,
          "cam_context_apply_req_to_hw",
          337,
          "[%s][%d] : Moving req[%llu] from active_list to free_list",
          (const char *)v1,
          *(_DWORD *)(v1 + 32),
          a1[3]);
      result = v17;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_apply_req_to_hw",
      294,
      "[%s][%d] HW interface is not ready",
      (const char *)v1,
      *(_DWORD *)(v1 + 32));
    result = 4294967282LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
