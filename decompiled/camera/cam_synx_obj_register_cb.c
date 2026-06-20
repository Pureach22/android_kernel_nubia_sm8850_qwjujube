__int64 __fastcall cam_synx_obj_register_cb(_DWORD *a1, unsigned int a2, const void *a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x24
  int v9; // w7
  int v10; // w9
  unsigned int v11; // w20
  __int64 v12; // x8
  __int64 v13; // x10
  unsigned int v14; // w9
  __int64 v15; // x10
  __int64 v16; // x9
  int v17; // w10
  __int64 v18; // x10
  __int64 v19; // x8
  int v20; // w21
  int v21; // w10
  unsigned int v22; // w19
  __int64 v23; // [xsp+10h] [xbp-70h] BYREF
  __int64 (__fastcall *v24)(); // [xsp+18h] [xbp-68h]
  __int64 v25; // [xsp+20h] [xbp-60h]
  __int64 v26; // [xsp+28h] [xbp-58h]
  __int64 v27; // [xsp+30h] [xbp-50h]
  _DWORD *v28; // [xsp+38h] [xbp-48h] BYREF
  __int64 v29; // [xsp+40h] [xbp-40h]
  __int64 v30; // [xsp+48h] [xbp-38h]
  __int64 v31; // [xsp+50h] [xbp-30h]
  __int64 v32; // [xsp+58h] [xbp-28h]
  __int64 v33; // [xsp+60h] [xbp-20h]
  __int64 v34; // [xsp+68h] [xbp-18h]
  __int64 v35; // [xsp+70h] [xbp-10h]
  __int64 v36; // [xsp+78h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = nullptr;
  v25 = 0;
  v23 = 0;
  if ( !a1 || !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_register_cb",
      649,
      "Invalid args sync_obj: %p sync_cb: %p",
      a1,
      a3);
    result = 4294967274LL;
    goto LABEL_26;
  }
  if ( a2 >= 0x100 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_register_cb",
      655,
      "synx obj idx: %d is invalid",
      a2);
    result = 4294967274LL;
    goto LABEL_26;
  }
  raw_spin_lock_bh(g_cam_synx_obj_dev + 4LL * a2 + 22528);
  v7 = g_cam_synx_obj_dev;
  v8 = g_cam_synx_obj_dev + 88LL * a2;
  v9 = *(_DWORD *)(v8 + 64);
  v10 = *(_DWORD *)(v8 + 68);
  if ( v10 != 1 )
  {
    if ( (cam_sync_monitor_mask & 8) != 0 )
    {
      cam_generic_fence_update_monitor_array(a2, g_cam_synx_obj_dev + 23560, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 2);
      v9 = *(_DWORD *)(v8 + 64);
      v10 = *(_DWORD *)(v8 + 68);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_register_cb",
      671,
      "synx obj at idx: %d handle: %d is not active, current state: %d",
      a2,
      v9,
      v10);
    v11 = -22;
    goto LABEL_14;
  }
  if ( *(_BYTE *)(v8 + 80) == 1 )
  {
    if ( (cam_sync_monitor_mask & 8) != 0 )
    {
      cam_generic_fence_update_monitor_array(a2, g_cam_synx_obj_dev + 23560, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 3);
      v9 = *(_DWORD *)(v8 + 64);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      2,
      "cam_synx_obj_register_cb",
      687,
      "synx obj at idx: %d handle: %d has already registered a cb for sync: %d",
      a2,
      v9,
      *(_DWORD *)(v8 + 84));
    v11 = 0;
LABEL_14:
    v12 = g_cam_synx_obj_dev;
    v13 = *(_QWORD *)(g_cam_synx_obj_dev + 23640);
    if ( v13 && (cam_sync_monitor_mask & 8) != 0 )
    {
      v14 = a2 - 128;
      v31 = 0;
      v32 = 0;
      v29 = 0;
      v30 = 0;
      if ( a2 < 0x80 )
        v14 = a2;
      v15 = *(_QWORD *)(v13 + 8LL * (a2 > 0x7F));
      if ( *(_DWORD *)(v15 + 1616LL * v14 + 140) )
      {
        v16 = v15 + 1616LL * v14;
        v28 = (_DWORD *)(g_cam_synx_obj_dev + 88LL * a2);
        HIDWORD(v29) = v28[16];
        v17 = v28[17];
        v33 = v16;
        LODWORD(v32) = 3;
        HIDWORD(v30) = v17;
        v18 = 176;
        LODWORD(v30) = v28[21];
        if ( *(_BYTE *)(v16 + 168) )
          v19 = 896;
        else
          v19 = 176;
        if ( !*(_BYTE *)(v16 + 168) )
          v18 = 896;
        v34 = v16 + v19;
        v35 = v16 + v18;
        cam_generic_fence_dump_monitor_array((__int64)&v28);
        v12 = g_cam_synx_obj_dev;
      }
    }
    raw_spin_unlock_bh(v12 + 4LL * a2 + 22528);
    result = v11;
    goto LABEL_26;
  }
  *(_QWORD *)(v8 + 72) = a3;
  v20 = v9;
  v21 = *a1;
  *(_BYTE *)(v8 + 80) = 1;
  *(_DWORD *)(v8 + 84) = v21;
  v26 = 0;
  v27 = -1;
  LODWORD(v23) = v9;
  v24 = _cam_synx_obj_signal_cb;
  v25 = v7 + 88LL * a2;
  if ( (cam_sync_monitor_mask & 8) != 0 )
  {
    cam_generic_fence_update_monitor_array(a2, v7 + 23560, *(_QWORD *)(v7 + 23640), 1);
    v7 = g_cam_synx_obj_dev;
  }
  raw_spin_unlock_bh(v7 + 4LL * a2 + 22528);
  result = synx_async_wait(*(_QWORD *)(g_cam_synx_obj_dev + 23552), &v23);
  if ( (_DWORD)result )
  {
    v22 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_register_cb",
      711,
      "Failed to register cb for synx obj: %d rc: %d",
      v20,
      result);
    result = v22;
  }
  else if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000000000LL,
      4,
      "cam_synx_obj_register_cb",
      717,
      "CB successfully registered for synx obj: %d for sync_obj: %d",
      v20,
      *a1);
    result = 0;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
