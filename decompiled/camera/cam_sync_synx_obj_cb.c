__int64 __fastcall cam_sync_synx_obj_cb(unsigned int a1, _DWORD *a2)
{
  __int64 v4; // x7
  __int64 result; // x0
  __int64 v6; // x20
  unsigned int v7; // w0
  int v8; // w8
  unsigned int v9; // w23
  unsigned int v16; // w9
  unsigned int v19; // w9
  unsigned int v20; // w9
  __int64 v21; // x1
  _QWORD *v22; // x10
  _QWORD *v23; // x11
  _QWORD *v24; // [xsp+18h] [xbp-18h] BYREF
  _QWORD **v25; // [xsp+20h] [xbp-10h]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 - 1 >= 0x7FF )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_sync_synx_obj_cb",
        1079,
        "Invalid sync obj: %d",
        a1);
      result = 4294967274LL;
    }
    else
    {
      raw_spin_lock_bh(sync_dev + 4LL * a1 + 136);
      v4 = *(_QWORD *)(sync_dev + 128) + 216LL * a1;
      if ( (*(_QWORD *)(v4 + 184) & 8) == 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _QWORD))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_synx_obj_cb",
          1090,
          "sync obj = %d[%s] has no associated synx obj ext_fence_mask = 0x%x",
          a1,
          v4,
          *(_QWORD *)(v4 + 184));
LABEL_11:
        v9 = -22;
        goto LABEL_12;
      }
      if ( *(_DWORD *)(v4 + 204) != *a2 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _DWORD, _DWORD))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_synx_obj_cb",
          1100,
          "sync obj: %d[%s] is associated with a different synx obj: %d, signaling for synx obj: %d",
          a1,
          v4,
          *(_DWORD *)(v4 + 204),
          *a2);
        goto LABEL_11;
      }
      v6 = *(_QWORD *)(sync_dev + 128) + 216LL * a1;
      v7 = cam_sync_signal_validate_util(a1, a2[1]);
      if ( v7 )
      {
        v8 = a2[1];
        v9 = v7;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_synx_obj_cb",
          1109,
          "Error: Failed to validate signal info for sync_obj = %d[%s] with status = %d rc = %d",
          a1,
          (const char *)v6,
          v8,
          v7);
LABEL_12:
        raw_spin_unlock_bh(sync_dev + 4LL * a1 + 136);
        result = v9;
        goto LABEL_13;
      }
      _X8 = (unsigned int *)(v6 + 176);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 + 1, _X8) );
      _X10 = (unsigned int *)(v6 + 176);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v19 = __ldxr(_X10);
        v20 = v19 - 1;
      }
      while ( __stlxr(v20, _X10) );
      __dmb(0xBu);
      if ( v20 )
      {
        v9 = 0;
        if ( (debug_mdl & 0x80) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            (unsigned __int8)debug_mdl & 0x80,
            4,
            "cam_sync_synx_obj_cb",
            1117,
            "Sync = %d[%s] fence still has references, synx_hdl = %d",
            a1);
          v9 = 0;
        }
        goto LABEL_12;
      }
      v21 = (unsigned int)a2[1];
      *(_DWORD *)(v6 + 104) = v21;
      cam_sync_util_dispatch_signaled_cb(a1, v21, 0);
      v24 = &v24;
      v25 = &v24;
      v22 = *(_QWORD **)(v6 + 72);
      if ( v22 != (_QWORD *)(v6 + 72) )
      {
        v23 = *(_QWORD **)(v6 + 80);
        v22[1] = &v24;
        v24 = v22;
        *v23 = &v24;
        v25 = (_QWORD **)v23;
        *(_QWORD *)(v6 + 72) = v6 + 72;
        *(_QWORD *)(v6 + 80) = v6 + 72;
      }
      raw_spin_unlock_bh(sync_dev + 4LL * a1 + 136);
      if ( v24 == &v24 )
      {
LABEL_28:
        result = 0;
        goto LABEL_13;
      }
      cam_sync_signal_parent_util((_QWORD *)(unsigned int)a2[1], 0, &v24);
      result = 0;
      if ( (debug_mdl & 0x80) != 0 && !debug_priority )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          (unsigned __int8)debug_mdl & 0x80,
          4,
          "cam_sync_synx_obj_cb",
          1135,
          "Successfully signaled sync obj = %d with status = %d via synx obj = %d signal callback",
          a1,
          a2[1],
          *a2);
        goto LABEL_28;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_synx_obj_cb",
      1073,
      "Invalid signal info args");
    result = 4294967274LL;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
