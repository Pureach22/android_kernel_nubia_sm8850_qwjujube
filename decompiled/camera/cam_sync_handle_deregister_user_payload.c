__int64 __fastcall cam_sync_handle_deregister_user_payload(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x1
  __int64 result; // x0
  const char *v4; // x5
  __int64 v5; // x4
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x20
  _QWORD *v10; // x20
  _QWORD *v11; // x24
  _QWORD *v12; // t1
  _QWORD *v13; // x9
  _QWORD *v14; // x0
  __int64 v15; // x8
  _QWORD *v16; // x8
  _QWORD *v17; // x10
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  __int64 v19; // [xsp+8h] [xbp-18h]
  __int64 v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 4);
  v19 = 0;
  v20 = 0;
  v18 = 0;
  if ( v1 != 24 )
  {
    v4 = "Incorrect ioctl size";
    v5 = 933;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_handle_deregister_user_payload",
      v5,
      v4);
    goto LABEL_8;
  }
  v2 = *(_QWORD *)(a1 + 16);
  if ( !v2 )
  {
    v4 = "Invalid embedded ioctl ptr";
    v5 = 938;
    goto LABEL_7;
  }
  if ( inline_copy_from_user_2((int)&v18, v2, 0x18u) )
  {
    result = 4294967282LL;
    goto LABEL_9;
  }
  v6 = (unsigned int)v18;
  if ( (unsigned int)(v18 - 2048) < 0xFFFFF801 )
  {
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  raw_spin_lock_bh(sync_dev + 4LL * (unsigned int)v18 + 136);
  v7 = sync_dev;
  v8 = *(_QWORD *)(sync_dev + 128);
  v9 = v8 + 216LL * (unsigned int)v6;
  if ( !*(_DWORD *)(v9 + 104) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_handle_deregister_user_payload",
      957,
      "Error: accessing an uninitialized sync obj = %s[%d]",
      (const char *)(v8 + 216LL * (unsigned int)v6),
      v6);
    raw_spin_unlock_bh(sync_dev + 4 * v6 + 136);
    goto LABEL_8;
  }
  v12 = *(_QWORD **)(v9 + 160);
  v10 = (_QWORD *)(v9 + 160);
  v11 = v12;
  if ( v12 == v10 )
    goto LABEL_28;
  do
  {
    v13 = v11;
    v14 = v11 - 2;
    v15 = *(v11 - 2);
    v11 = (_QWORD *)*v11;
    if ( v15 == v19 && *(v13 - 1) == v20 )
    {
      v16 = (_QWORD *)v13[1];
      if ( (_QWORD *)*v16 == v13 && (_QWORD *)v11[1] == v13 )
      {
        v11[1] = v16;
        *v16 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v13);
        v14 = v17;
      }
      *v13 = v13;
      v13[1] = v13;
      if ( mem_trace_en == 1 )
      {
        cam_mem_trace_free(v14, 0);
        if ( (cam_sync_monitor_mask & 2) != 0 )
          goto LABEL_14;
      }
      else
      {
        kvfree(v14);
        if ( (cam_sync_monitor_mask & 2) != 0 )
LABEL_14:
          cam_generic_fence_update_monitor_array((unsigned int)v6, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 6);
      }
    }
  }
  while ( v11 != v10 );
  v7 = sync_dev;
LABEL_28:
  raw_spin_unlock_bh(v7 + 4 * v6 + 136);
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
