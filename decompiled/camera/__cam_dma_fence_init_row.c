__int64 __fastcall _cam_dma_fence_init_row(size_t a1, __int64 a2, int a3, unsigned int a4, char a5)
{
  __int64 v5; // x24
  const char *v6; // x20
  char v10; // w26
  __int64 v11; // x25
  unsigned __int64 v12; // x2
  __int64 v14; // x0

  if ( a4 >= 0x81 )
  {
    __break(0x5512u);
    goto LABEL_11;
  }
  v5 = a4;
  v6 = (const char *)a1;
  v10 = a5 & 1;
  raw_spin_lock_bh(g_cam_dma_fence_dev + 4LL * a4 + 24584);
  v11 = g_cam_dma_fence_dev + 192LL * (unsigned int)v5;
  *(_QWORD *)(v11 + 136) = a2;
  *(_DWORD *)(v11 + 144) = a3;
  *(_DWORD *)(v11 + 148) = 1;
  *(_BYTE *)(v11 + 193) = v10;
  a1 = strnlen(v6, 0x80u);
  if ( a1 == -1 )
  {
LABEL_11:
    _fortify_panic(2, -1, a1 + 1);
LABEL_12:
    v14 = _fortify_panic(7, 128, v12);
    return _cam_dma_fence_release(v14);
  }
  if ( a1 == 128 )
    v12 = 128;
  else
    v12 = a1 + 1;
  if ( v12 >= 0x81 )
    goto LABEL_12;
  sized_strscpy(v11 + 8, v6);
  if ( (cam_sync_monitor_mask & 4) != 0 )
    cam_generic_fence_update_monitor_array(a4, g_cam_dma_fence_dev + 25096, *(_QWORD *)(g_cam_dma_fence_dev + 25160), 0);
  return raw_spin_unlock_bh(g_cam_dma_fence_dev + 4 * v5 + 24584);
}
