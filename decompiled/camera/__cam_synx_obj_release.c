__int64 __fastcall _cam_synx_obj_release(unsigned int a1)
{
  __int64 v1; // x24
  __int64 v3; // x21
  unsigned int v4; // w19
  int v5; // w22
  __int64 v6; // x0
  int v7; // w22
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x9
  int v11; // w10
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x9
  int v17; // w10
  __int64 v18; // x10
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x22
  __int64 v22; // x27
  size_t v23; // x0
  unsigned __int64 v24; // x2
  __int64 v25; // x25
  char v26; // w9
  __int64 v27; // x10
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x10
  __int64 result; // x0
  unsigned __int64 v38; // x10
  __int64 v39; // [xsp+8h] [xbp-48h] BYREF
  __int64 (__fastcall *v40)(__int64, int, __int64); // [xsp+10h] [xbp-40h]
  __int64 v41; // [xsp+18h] [xbp-38h]
  __int64 v42; // [xsp+20h] [xbp-30h]
  __int64 v43; // [xsp+28h] [xbp-28h]
  __int64 v44; // [xsp+30h] [xbp-20h]
  __int64 v45; // [xsp+38h] [xbp-18h]
  __int64 v46; // [xsp+40h] [xbp-10h]
  __int64 v47; // [xsp+48h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 0x101 )
    __break(0x5512u);
  v1 = (int)a1;
  raw_spin_lock_bh(g_cam_synx_obj_dev + 4LL * (int)a1 + 22528);
  v3 = g_cam_synx_obj_dev + 88LL * (int)v1;
  v4 = *(_DWORD *)(v3 + 64);
  if ( *(_DWORD *)(v3 + 68) == 1 )
  {
    if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000000000LL,
        4,
        "__cam_synx_obj_release",
        260,
        "Unsignaled synx obj being released name: %s synx_obj:%d",
        (const char *)(g_cam_synx_obj_dev + 88LL * (int)v1),
        v4);
    v5 = *(unsigned __int8 *)(v3 + 80);
    if ( v5 == 1 && (cam_sync_monitor_mask & 8) != 0 )
      cam_generic_fence_update_monitor_array(a1, g_cam_synx_obj_dev + 23560, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 5);
    if ( (cam_sync_monitor_mask & 8) != 0 )
      cam_generic_fence_update_monitor_array(a1, g_cam_synx_obj_dev + 23560, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 4);
    if ( v5 )
    {
      raw_spin_unlock_bh(g_cam_synx_obj_dev + 22528 + 4 * v1);
      v42 = 0;
      v43 = 0;
      v6 = *(_QWORD *)(g_cam_synx_obj_dev + 23552);
      v39 = v4;
      v40 = _cam_synx_obj_signal_cb;
      v41 = v3;
      v7 = synx_cancel_async_wait(v6, &v39);
      raw_spin_lock_bh(g_cam_synx_obj_dev + 22528 + 4 * v1);
      if ( v7 )
      {
        if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000000000LL,
            4,
            "__cam_synx_obj_release",
            283,
            "Failed to deregister cb for synx hdl: %u rc: %d",
            v4,
            v7);
        v8 = *(_QWORD *)(g_cam_synx_obj_dev + 23640);
        if ( v8 )
        {
          if ( (cam_sync_monitor_mask & 8) != 0 )
          {
            v42 = 0;
            v43 = 0;
            v40 = nullptr;
            v41 = 0;
            v9 = *(_QWORD *)(v8 + 8LL * (a1 >> 7));
            if ( *(_DWORD *)(v9 + 1616LL * (a1 & 0x7F) + 140) )
            {
              v10 = v9 + 1616LL * (a1 & 0x7F);
              v39 = g_cam_synx_obj_dev + 88LL * a1;
              HIDWORD(v40) = *(_DWORD *)(v39 + 64);
              v11 = *(_DWORD *)(v39 + 68);
              v44 = v10;
              LODWORD(v43) = 3;
              HIDWORD(v41) = v11;
              v12 = 176;
              LODWORD(v41) = *(_DWORD *)(v39 + 84);
              if ( *(_BYTE *)(v10 + 168) )
                v13 = 896;
              else
                v13 = 176;
              if ( !*(_BYTE *)(v10 + 168) )
                v12 = 896;
              v45 = v10 + v13;
              v46 = v10 + v12;
              cam_generic_fence_dump_monitor_array((__int64)&v39);
            }
          }
        }
      }
    }
  }
  if ( (cam_sync_monitor_mask & 8) == 0 )
    goto LABEL_43;
  cam_generic_fence_update_monitor_array(a1, g_cam_synx_obj_dev + 23560, *(_QWORD *)(g_cam_synx_obj_dev + 23640), 7);
  if ( (cam_sync_monitor_mask & 0x80000) != 0 )
  {
    v14 = *(_QWORD *)(g_cam_synx_obj_dev + 23640);
    if ( v14 )
    {
      if ( (cam_sync_monitor_mask & 8) != 0 )
      {
        v42 = 0;
        v43 = 0;
        v40 = nullptr;
        v41 = 0;
        v15 = *(_QWORD *)(v14 + 8LL * (a1 >> 7));
        if ( *(_DWORD *)(v15 + 1616LL * (a1 & 0x7F) + 140) )
        {
          v16 = v15 + 1616LL * (a1 & 0x7F);
          v39 = g_cam_synx_obj_dev + 88LL * a1;
          HIDWORD(v40) = *(_DWORD *)(v39 + 64);
          v17 = *(_DWORD *)(v39 + 68);
          v44 = v16;
          LODWORD(v43) = 3;
          HIDWORD(v41) = v17;
          v18 = 176;
          LODWORD(v41) = *(_DWORD *)(v39 + 84);
          if ( *(_BYTE *)(v16 + 168) )
            v19 = 896;
          else
            v19 = 176;
          if ( !*(_BYTE *)(v16 + 168) )
            v18 = 896;
          v45 = v16 + v19;
          v46 = v16 + v18;
          cam_generic_fence_dump_monitor_array((__int64)&v39);
        }
      }
    }
  }
  v20 = *(_QWORD *)(g_cam_synx_obj_dev + 23640);
  if ( !v20 )
    goto LABEL_43;
  v21 = g_cam_synx_obj_dev + 88LL * a1;
  v22 = *(_QWORD *)(v20 + 8LL * (a1 >> 7));
  v23 = strnlen((const char *)v21, 0x40u);
  if ( v23 >= 0x41 )
  {
    _fortify_panic(2, 64, v23 + 1);
LABEL_49:
    _fortify_panic(7, 128, v24);
    goto LABEL_50;
  }
  if ( v23 == 64 )
    v24 = 64;
  else
    v24 = v23 + 1;
  if ( v24 >= 0x81 )
    goto LABEL_49;
  v25 = v22 + 1616LL * (a1 & 0x7F);
  sized_strscpy(v25 + 8, v21);
  *(_DWORD *)(v25 + 140) = *(_DWORD *)(v21 + 64);
  *(_DWORD *)(v25 + 144) = *(_DWORD *)(v21 + 84);
  *(_DWORD *)(v25 + 152) = *(_DWORD *)(v21 + 68);
  v26 = *(_BYTE *)(v25 + 168);
  *(_QWORD *)(v25 + 160) = *(_QWORD *)v25;
  *(_BYTE *)(v25 + 168) = v26 ^ 1;
LABEL_43:
  if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000000000LL,
      4,
      "__cam_synx_obj_release",
      301,
      "Releasing synx_obj: %d[%s] row_idx: %u",
      *(_DWORD *)(v3 + 64),
      (const char *)v3,
      a1);
  *(_QWORD *)v3 = 0;
  *(_QWORD *)(v3 + 8) = 0;
  v27 = g_cam_synx_obj_dev;
  v28 = 1LL << a1;
  v29 = a1 >> 6;
  *(_QWORD *)(v3 + 72) = 0;
  *(_QWORD *)(v3 + 80) = 0;
  v30 = v27 + 23608;
  *(_QWORD *)(v3 + 56) = 0;
  *(_QWORD *)(v3 + 64) = 0;
  *(_QWORD *)(v3 + 40) = 0;
  *(_QWORD *)(v3 + 48) = 0;
  *(_QWORD *)(v3 + 24) = 0;
  *(_QWORD *)(v3 + 32) = 0;
  *(_QWORD *)(v3 + 16) = 0;
LABEL_50:
  _X9 = (unsigned __int64 *)(v30 + 8 * v29);
  __asm { PRFM            #0x11, [X9] }
  do
    v38 = __ldxr(_X9);
  while ( __stxr(v38 & ~v28, _X9) );
  raw_spin_unlock_bh(g_cam_synx_obj_dev + 4 * v1 + 22528);
  result = synx_release(*(_QWORD *)(g_cam_synx_obj_dev + 23552), v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
