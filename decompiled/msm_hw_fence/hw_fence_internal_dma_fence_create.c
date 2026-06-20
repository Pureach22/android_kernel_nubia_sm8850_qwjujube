__int64 __fastcall hw_fence_internal_dma_fence_create(__int64 a1, unsigned int *a2, __int64 *a3)
{
  __int64 v3; // x30
  __int64 v4; // x19
  __int64 v7; // x20
  __int64 v8; // x24
  __int64 v10; // x22
  unsigned __int64 v11; // x0
  __int64 v12; // x4
  __int64 v13; // x26
  int v14; // w9
  int v15; // w0
  int v16; // w23
  __int64 v17; // x20
  __int64 v18; // x20
  unsigned int v26; // w8
  signed int v27; // w8
  unsigned __int64 v30; // x9
  int v32; // w8

  v4 = -22;
  if ( !a1 || !a2 || !a3 )
    return v4;
  v7 = *((_QWORD *)a2 + 23);
  v8 = v3;
  _X9 = a2 + 48;
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v26 = __ldxr(_X9);
    v27 = v26 + 1;
  }
  while ( __stlxr(v27, _X9) );
  __dmb(0xBu);
  v10 = v27;
  v11 = hw_dma_fence_init(a2, v7, v27);
  if ( !v11 || (v4 = v11, v11 >= 0xFFFFFFFFFFFFF001LL) )
  {
    printk(&unk_271D5, "hw_fence_internal_dma_fence_create", 1558, v8, *a2);
    return -22;
  }
  if ( (unsigned int)hw_fence_create(a1, a2, v11, v7, v10, a3) )
  {
    printk(&unk_249D2, "hw_fence_internal_dma_fence_create", 1565, v8, *a2);
    goto LABEL_20;
  }
  v12 = *a3;
  if ( *a3 >= (unsigned __int64)*(unsigned int *)(a1 + 16) )
  {
    v18 = v8;
    printk(&unk_23ADB, "_get_hw_fence", 1135, v8, v12);
    v12 = *a3;
LABEL_18:
    printk(&unk_226E9, "hw_fence_internal_dma_fence_create", 1572, v18, v12);
    goto LABEL_20;
  }
  v13 = *(_QWORD *)(a1 + 64) + (v12 << 7);
  if ( !v13 )
  {
    v18 = v8;
    goto LABEL_18;
  }
  global_atomic_store(a1, v13 + 40, 1);
  v14 = *(_DWORD *)(v13 + 112) | 0x40000000;
  *(_QWORD *)(v13 + 48) |= 4uLL;
  *(_DWORD *)(v13 + 112) = v14;
  global_atomic_store(a1, v13 + 40, 0);
  _X8 = (unsigned __int64 *)(v4 + 48);
  __asm { PRFM            #0x11, [X8] }
  do
    v30 = __ldxr(_X8);
  while ( __stxr(v30 | 0x80000000, _X8) );
  if ( !(unsigned int)hw_fence_dma_fence_table_add(a1, a2, v4, *a3) )
  {
    v15 = hw_fence_interop_add_cb(v4, v4 + 144, msm_hw_fence_internal_signal_callback);
    if ( !v15 )
      return v4;
    v16 = v15;
    printk(&unk_210A8, "hw_fence_internal_dma_fence_create", 1599, v8, v7);
    v17 = v16;
    goto LABEL_21;
  }
  printk(&unk_23669, "hw_fence_internal_dma_fence_create", 1588, v8, v7);
LABEL_20:
  v17 = -22;
LABEL_21:
  _X0 = (unsigned int *)(v4 + 56);
  __asm { PRFM            #0x11, [X0] }
  do
    v32 = __ldxr(_X0);
  while ( __stlxr(v32 - 1, _X0) );
  if ( v32 == 1 )
  {
    __dmb(9u);
    dma_fence_release();
  }
  else if ( v32 <= 0 )
  {
    refcount_warn_saturate();
  }
  return v17;
}
