__int64 __fastcall cam_sync_dma_fence_cb(unsigned int a1, int *a2)
{
  __int64 v4; // x7
  __int64 result; // x0
  int v6; // w9
  __int64 v7; // x21
  int v8; // w9
  unsigned int v9; // w20
  unsigned int v10; // w0
  unsigned int v11; // w24
  unsigned int v18; // w10
  unsigned int v21; // w9
  unsigned int v22; // w9
  _QWORD *v23; // x9
  _QWORD *v24; // x10
  _QWORD *v25; // [xsp+18h] [xbp-18h] BYREF
  _QWORD **v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 - 1 >= 0x7FF )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_sync_dma_fence_cb",
        998,
        "Invalid sync obj: %d",
        a1);
      result = 4294967274LL;
    }
    else
    {
      raw_spin_lock_bh(sync_dev + 4LL * a1 + 136);
      v4 = *(_QWORD *)(sync_dev + 128) + 216LL * a1;
      if ( (*(_QWORD *)(v4 + 184) & 4) == 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _QWORD))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_dma_fence_cb",
          1009,
          "sync obj = %d[%s] has no associated dma fence ext_fence_mask = 0x%x",
          a1,
          v4,
          *(_QWORD *)(v4 + 184));
LABEL_17:
        v11 = -22;
        goto LABEL_18;
      }
      v6 = a2[1];
      if ( *(_DWORD *)(v4 + 192) != v6 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _DWORD, int))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_dma_fence_cb",
          1018,
          "sync obj: %d[%s] is associated with a different fd: %d, signaling for fd: %d",
          a1,
          v4,
          *(_DWORD *)(v4 + 192),
          v6);
        goto LABEL_17;
      }
      v7 = *(_QWORD *)(sync_dev + 128) + 216LL * a1;
      if ( *a2 == -125 )
        v8 = 4;
      else
        v8 = 3;
      if ( *a2 >= 0 )
        v9 = 2;
      else
        v9 = v8;
      v10 = cam_sync_signal_validate_util(a1, v9);
      if ( v10 )
      {
        v11 = v10;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_dma_fence_cb",
          1035,
          "Error: Failed to validate signal info for sync_obj = %d[%s] with status = %d rc = %d",
          a1,
          (const char *)v7,
          v9,
          v10);
LABEL_18:
        raw_spin_unlock_bh(sync_dev + 4LL * a1 + 136);
        result = v11;
        goto LABEL_19;
      }
      _X9 = (unsigned int *)(v7 + 176);
      __asm { PRFM            #0x11, [X9] }
      do
        v18 = __ldxr(_X9);
      while ( __stxr(v18 + 1, _X9) );
      _X10 = (unsigned int *)(v7 + 176);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v21 = __ldxr(_X10);
        v22 = v21 - 1;
      }
      while ( __stlxr(v22, _X10) );
      __dmb(0xBu);
      if ( v22 )
      {
        v11 = 0;
        goto LABEL_18;
      }
      *(_DWORD *)(v7 + 104) = v9;
      cam_sync_util_dispatch_signaled_cb(a1, v9, 0);
      v25 = &v25;
      v26 = &v25;
      v23 = *(_QWORD **)(v7 + 72);
      if ( v23 != (_QWORD *)(v7 + 72) )
      {
        v24 = *(_QWORD **)(v7 + 80);
        v23[1] = &v25;
        v25 = v23;
        *v24 = &v25;
        v26 = (_QWORD **)v24;
        *(_QWORD *)(v7 + 72) = v7 + 72;
        *(_QWORD *)(v7 + 80) = v7 + 72;
      }
      raw_spin_unlock_bh(sync_dev + 4LL * a1 + 136);
      if ( v25 != &v25 )
        cam_sync_signal_parent_util((_QWORD *)v9, 0, &v25);
      result = 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_dma_fence_cb",
      992,
      "Invalid signal info args");
    result = 4294967274LL;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
