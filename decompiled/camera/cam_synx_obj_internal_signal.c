__int64 __fastcall cam_synx_obj_internal_signal(unsigned int a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v5; // x8
  __int64 v6; // x20
  int v7; // w7
  int v8; // w9
  int v9; // w6
  int v10; // w25
  unsigned int v11; // w22
  unsigned int v12; // w8
  __int64 v13; // x0
  unsigned int v14; // w0
  __int64 v15; // x8
  __int64 v16; // x10
  unsigned int v17; // w9
  __int64 v18; // x10
  __int64 v19; // x9
  int v20; // w10
  __int64 v21; // x10
  __int64 v22; // x8
  __int64 v24; // [xsp+8h] [xbp-48h] BYREF
  __int64 (__fastcall *v25)(); // [xsp+10h] [xbp-40h]
  __int64 v26; // [xsp+18h] [xbp-38h]
  __int64 v27; // [xsp+20h] [xbp-30h]
  __int64 v28; // [xsp+28h] [xbp-28h]
  __int64 v29; // [xsp+30h] [xbp-20h]
  __int64 v30; // [xsp+38h] [xbp-18h]
  __int64 v31; // [xsp+40h] [xbp-10h]
  __int64 v32; // [xsp+48h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 0x100 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_internal_signal",
      531,
      "synx obj row idx: %d is invalid",
      a1);
    v3 = -22;
    goto LABEL_30;
  }
  raw_spin_lock_bh(g_cam_synx_obj_dev + 4LL * a1 + 22528);
  v5 = g_cam_synx_obj_dev;
  v6 = g_cam_synx_obj_dev + 88LL * a1;
  v7 = *(_DWORD *)(v6 + 68);
  *(_BYTE *)(v6 + 81) = 1;
  if ( v7 != 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_internal_signal",
      543,
      "synx obj: %u not in right state: %d to signal",
      *(unsigned int *)(a2 + 4));
    v3 = -22;
    goto LABEL_18;
  }
  v8 = *(_DWORD *)(v6 + 64);
  v9 = *(_DWORD *)(a2 + 4);
  if ( v8 != v9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      2,
      "cam_synx_obj_internal_signal",
      551,
      "Trying to signal synx obj: %u in row: %u having a different synx obj: %u",
      v9,
      a1,
      v8);
    v3 = 0;
LABEL_18:
    v15 = g_cam_synx_obj_dev;
    v16 = *(_QWORD *)(g_cam_synx_obj_dev + 23640);
    if ( v16 && (cam_sync_monitor_mask & 8) != 0 )
    {
      v17 = a1 - 128;
      v27 = 0;
      v28 = 0;
      v25 = nullptr;
      v26 = 0;
      if ( a1 < 0x80 )
        v17 = a1;
      v18 = *(_QWORD *)(v16 + 8LL * (a1 > 0x7F));
      if ( *(_DWORD *)(v18 + 1616LL * v17 + 140) )
      {
        v19 = v18 + 1616LL * v17;
        v24 = g_cam_synx_obj_dev + 88LL * a1;
        HIDWORD(v25) = *(_DWORD *)(v24 + 64);
        v20 = *(_DWORD *)(v24 + 68);
        v29 = v19;
        LODWORD(v28) = 3;
        HIDWORD(v26) = v20;
        v21 = 176;
        LODWORD(v26) = *(_DWORD *)(v24 + 84);
        if ( *(_BYTE *)(v19 + 168) )
          v22 = 896;
        else
          v22 = 176;
        if ( !*(_BYTE *)(v19 + 168) )
          v21 = 896;
        v30 = v19 + v22;
        v31 = v19 + v21;
        cam_generic_fence_dump_monitor_array((__int64)&v24);
        v15 = g_cam_synx_obj_dev;
      }
    }
    raw_spin_unlock_bh(v15 + 4LL * a1 + 22528);
    goto LABEL_30;
  }
  v10 = *(unsigned __int8 *)(v6 + 80);
  if ( *(_DWORD *)(a2 + 8) == 2 )
    v11 = 2;
  else
    v11 = 4;
  if ( v10 == 1 && (cam_sync_monitor_mask & 8) != 0 )
    cam_generic_fence_update_monitor_array(a1, v5 + 23560, *(_QWORD *)(v5 + 23640), 5);
  if ( (cam_sync_monitor_mask & 8) != 0 )
    cam_generic_fence_update_monitor_array(a1, g_cam_synx_obj_dev + 23560, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 4);
  *(_DWORD *)(v6 + 68) = 2;
  raw_spin_unlock_bh(g_cam_synx_obj_dev + 4LL * a1 + 22528);
  if ( v10 )
  {
    v12 = *(_DWORD *)(a2 + 4);
    v27 = 0;
    v28 = 0;
    v13 = *(_QWORD *)(g_cam_synx_obj_dev + 23552);
    v24 = v12;
    v25 = _cam_synx_obj_signal_cb;
    v26 = v6;
    v14 = synx_cancel_async_wait(v13, &v24);
    if ( v14 )
    {
      v3 = v14;
      raw_spin_lock_bh(g_cam_synx_obj_dev + 4LL * a1 + 22528);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x1000000000LL,
        1,
        "cam_synx_obj_internal_signal",
        584,
        "Failed to deregister cb for synx: %u rc: %d",
        *(_DWORD *)(a2 + 4),
        v3);
      goto LABEL_18;
    }
  }
  v3 = synx_signal(*(_QWORD *)(g_cam_synx_obj_dev + 23552), *(unsigned int *)(a2 + 4), v11);
  if ( v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_synx_obj_internal_signal",
      592,
      "Failed to signal synx hdl: %u with status: %u rc: %d",
      *(_DWORD *)(a2 + 4),
      v11,
      v3);
  }
  else if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000000000LL,
      4,
      "cam_synx_obj_internal_signal",
      597,
      "synx obj: %d signaled with status: %d rc: %d",
      *(_DWORD *)(a2 + 4),
      v11,
      0);
    v3 = 0;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v3;
}
