__int64 __fastcall _cam_dma_fence_find_free_idx(_DWORD *a1)
{
  unsigned __int64 first_zero_bit; // x0
  __int64 v3; // x8
  unsigned __int64 v10; // x9
  __int64 v12; // x23
  __int64 v13; // x22
  __int64 i; // x24
  int v15; // w9

  while ( 1 )
  {
    first_zero_bit = find_first_zero_bit(g_cam_dma_fence_dev + 25144, 128);
    *a1 = first_zero_bit;
    if ( (unsigned int)first_zero_bit > 0x7F )
      break;
    v3 = 1LL << first_zero_bit;
    _X10 = (unsigned __int64 *)(g_cam_dma_fence_dev + 25144 + 8 * ((first_zero_bit >> 6) & 1));
    __asm { PRFM            #0x11, [X10] }
    do
      v10 = __ldxr(_X10);
    while ( __stlxr(v10 | v3, _X10) );
    __dmb(0xBu);
    if ( (v10 & v3) == 0 )
      return 0;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x400000000LL,
    1,
    "__cam_dma_fence_find_free_idx",
    136,
    "No free idx, printing dma fence table......");
  v12 = -127;
  v13 = 24588;
  for ( i = 340; ; i += 192 )
  {
    raw_spin_lock_bh(g_cam_dma_fence_dev + v13);
    v15 = *(_DWORD *)(g_cam_dma_fence_dev + i);
    if ( !v15 )
      break;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      3,
      "__cam_dma_fence_print_table",
      115,
      "Idx: %d seqno: %llu name: %s state: %d",
      v12 + 128,
      *(_QWORD *)(*(_QWORD *)(g_cam_dma_fence_dev + i - 12) + 40LL),
      (const char *)(g_cam_dma_fence_dev + i - 140),
      v15);
    raw_spin_unlock_bh(g_cam_dma_fence_dev + v13);
    _CF = __CFADD__(v12++, 1);
    v13 += 4;
    if ( _CF )
      return 4294967284LL;
  }
  raw_spin_unlock_bh(g_cam_dma_fence_dev + v13);
  return 4294967284LL;
}
