__int64 __fastcall cam_dma_fence_release(__int64 a1)
{
  unsigned int v1; // w19
  const char *v2; // x3
  const char *v3; // x5
  __int64 v4; // x4
  __int64 v5; // x21
  __int64 v6; // x20
  __int64 v7; // x22
  unsigned __int64 v8; // x21
  __int64 v9; // x0

  v1 = *(_DWORD *)a1;
  if ( (*(_BYTE *)(a1 + 4) & 1) == 0 )
  {
    v5 = 0;
    v6 = 0;
    v7 = 24584;
    while ( 1 )
    {
      raw_spin_lock_bh(g_cam_dma_fence_dev + v7);
      if ( *(_DWORD *)(g_cam_dma_fence_dev + v5 + 148) )
      {
        if ( *(_DWORD *)(g_cam_dma_fence_dev + v5 + 144) == v1 )
          break;
      }
      raw_spin_unlock_bh(g_cam_dma_fence_dev + v7);
      ++v6;
      v7 += 4;
      v5 += 192;
      if ( v6 == 128 )
        goto LABEL_11;
    }
    v8 = *(_QWORD *)(g_cam_dma_fence_dev + v5 + 136);
    raw_spin_unlock_bh(g_cam_dma_fence_dev + v7);
    if ( v8 && v8 < 0xFFFFFFFFFFFFF001LL )
    {
      v9 = (unsigned int)v6;
      return _cam_dma_fence_release(v9);
    }
LABEL_11:
    v2 = "__cam_dma_fence_release_fd";
    v3 = "Failed to find dma fence for fd: %d";
    v4 = 756;
    goto LABEL_12;
  }
  if ( v1 >= 0x80 )
  {
    v2 = "__cam_dma_fence_release_row";
    v3 = "dma fence idx: %d is invalid";
    v4 = 769;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x400000000LL,
      1,
      v2,
      v4,
      v3,
      v1);
    return 4294967274LL;
  }
  v9 = v1;
  return _cam_dma_fence_release(v9);
}
