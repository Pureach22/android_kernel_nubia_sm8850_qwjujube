__int64 __fastcall _cam_dma_fence_signal_cb(__int64 result, __int64 a2)
{
  __int64 (*v2)(void); // x8
  __int64 v3; // x20
  __int64 v4; // x19
  _DWORD *v5; // x9
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x8
  __int64 v9; // x21
  __int64 v10; // x19
  int v11; // w22
  __int64 v12; // x23
  __int64 v13; // x19
  __int64 v14; // x20
  _DWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(a2 - 4) )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x400000000LL,
               1,
               "__cam_dma_fence_signal_cb",
               198,
               "dma fence seqno: %llu is in invalid state: %d",
               *(_QWORD *)(result + 40),
               0);
    goto LABEL_25;
  }
  if ( (*(_BYTE *)(a2 + 42) & 1) == 0 )
  {
    if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    {
      v13 = a2;
      v14 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x400000000LL,
        4,
        "__cam_dma_fence_signal_cb",
        207,
        "dma fence seqno: %llu fd: %d signaled, signal sync obj: %d",
        *(_QWORD *)(result + 40),
        *(_DWORD *)(a2 - 8),
        *(_DWORD *)(a2 + 24));
      result = v14;
      a2 = v13;
    }
    if ( *(_BYTE *)(a2 + 40) == 1 && *(_QWORD *)(a2 + 32) )
    {
      v15[1] = *(_DWORD *)(a2 - 8);
      if ( (*(_QWORD *)(result + 48) & 1) == 0 )
      {
        v2 = *(__int64 (**)(void))(*(_QWORD *)(result + 8) + 32LL);
        if ( !v2 )
          goto LABEL_16;
        v3 = a2;
        v4 = result;
        if ( *((_DWORD *)v2 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v2() & 1) == 0 )
        {
          LODWORD(v2) = 0;
          a2 = v3;
          goto LABEL_16;
        }
        dma_fence_signal_locked(v4);
        result = v4;
        a2 = v3;
      }
      LODWORD(v2) = *(_DWORD *)(result + 60);
      if ( (unsigned int)v2 <= 1 )
        LODWORD(v2) = 1;
LABEL_16:
      v15[0] = (_DWORD)v2;
      v5 = *(_DWORD **)(a2 + 32);
      v6 = *(unsigned int *)(a2 + 24);
      *(_DWORD *)(a2 - 4) = 2;
      v7 = a2;
      if ( *(v5 - 1) != 927450924 )
        __break(0x8229u);
      result = ((__int64 (__fastcall *)(__int64, _DWORD *))v5)(v6, v15);
      if ( (cam_sync_monitor_mask & 4) != 0 )
      {
        v8 = v7;
        v9 = 0;
        v10 = 0;
        v11 = *(_DWORD *)(v8 - 8);
        v12 = 24584;
        do
        {
          raw_spin_lock_bh(g_cam_dma_fence_dev + v12);
          if ( *(_DWORD *)(g_cam_dma_fence_dev + v9 + 148) && *(_DWORD *)(g_cam_dma_fence_dev + v9 + 144) == v11 )
          {
            raw_spin_unlock_bh(g_cam_dma_fence_dev + v12);
            goto LABEL_27;
          }
          raw_spin_unlock_bh(g_cam_dma_fence_dev + v12);
          ++v10;
          v12 += 4;
          v9 += 192;
        }
        while ( v10 != 128 );
        LODWORD(v10) = 0;
LABEL_27:
        result = cam_generic_fence_update_monitor_array(
                   (unsigned int)v10,
                   g_cam_dma_fence_dev + 25096,
                   *(_QWORD *)(g_cam_dma_fence_dev + 25160),
                   5);
      }
    }
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
