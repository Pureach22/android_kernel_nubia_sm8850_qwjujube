__int64 __fastcall cam_dma_fence_signal_fd(__int64 a1)
{
  int v1; // w23
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x22
  unsigned __int64 v6; // x21

  v1 = *(_DWORD *)(a1 + 4);
  v3 = 0;
  v4 = 0;
  v5 = 24584;
  while ( 1 )
  {
    raw_spin_lock_bh(g_cam_dma_fence_dev + v5);
    if ( *(_DWORD *)(g_cam_dma_fence_dev + v3 + 148) )
    {
      if ( *(_DWORD *)(g_cam_dma_fence_dev + v3 + 144) == v1 )
        break;
    }
    raw_spin_unlock_bh(g_cam_dma_fence_dev + v5);
    ++v4;
    v5 += 4;
    v3 += 192;
    if ( v4 == 128 )
      goto LABEL_8;
  }
  v6 = *(_QWORD *)(g_cam_dma_fence_dev + v3 + 136);
  raw_spin_unlock_bh(g_cam_dma_fence_dev + v5);
  if ( v6 && v6 < 0xFFFFFFFFFFFFF001LL )
    return cam_dma_fence_internal_signal(v4, a1);
LABEL_8:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000000LL,
    1,
    "cam_dma_fence_signal_fd",
    573,
    "Failed to find dma fence for fd: %d",
    *(_DWORD *)(a1 + 4));
  return 4294967274LL;
}
