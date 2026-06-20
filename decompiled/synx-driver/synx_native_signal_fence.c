__int64 __fastcall synx_native_signal_fence(
        unsigned __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  unsigned __int64 v8; // x9
  unsigned __int64 v10; // x21
  unsigned __int64 v11; // x8
  __int64 v12; // x19
  __int64 v13; // x9
  int v14; // w10
  int v15; // w10
  unsigned int v16; // w20
  void *v17; // x0
  __int64 v18; // x3

  result = 4294967274LL;
  if ( !a1 )
    return result;
  if ( a1 > 0xFFFFFFFFFFFFF000LL )
    return result;
  v8 = *(_QWORD *)(a1 + 64);
  if ( !v8 || v8 > 0xFFFFFFFFFFFFF000LL )
    return result;
  if ( a2 <= 1 )
  {
    if ( (synx_debug & 1) != 0 )
    {
      printk(&unk_25A89, &unk_29207, "synx_native_signal_fence", 538, a2, a6);
      return 4294967274LL;
    }
    return result;
  }
  if ( (*(_BYTE *)(a1 + 124) & 0x20) != 0 )
  {
    if ( (synx_debug & 1) == 0 )
      return result;
    v17 = &unk_268E5;
    v18 = 543;
    goto LABEL_29;
  }
  v10 = a1;
  if ( (unsigned int)synx_util_get_object_status(a1) != 1 )
    return 4294967182LL;
  v11 = *(_QWORD *)(v10 + 352);
  if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) == 0 )
      return 4294967274LL;
    v17 = &unk_28DEE;
    v18 = 552;
LABEL_29:
    printk(v17, &unk_29207, "synx_native_signal_fence", v18, a5, a6);
    return 4294967274LL;
  }
  if ( (dma_fence_remove_callback(*(_QWORD *)(v10 + 64), v11 + 32) & 1) == 0 )
  {
    if ( (synx_debug & 1) == 0 )
      return 4294967274LL;
    v17 = &unk_25F05;
    v18 = 562;
    goto LABEL_29;
  }
  if ( (synx_debug & 0x80) != 0 )
    printk(&unk_25714, &unk_25D36, "synx_native_signal_fence", 567, *(_QWORD *)(v10 + 352), a6);
  kfree(*(_QWORD *)(v10 + 352));
  *(_QWORD *)(v10 + 352) = 0;
  synx_util_put_object(v10);
  v12 = raw_spin_lock_irqsave(**(_QWORD **)(v10 + 64));
  if ( (unsigned int)synx_util_get_object_status_locked(v10) != 1 )
  {
    raw_spin_unlock_irqrestore(**(_QWORD **)(v10 + 64), v12);
    return 4294967182LL;
  }
  *(_DWORD *)(v10 + 128) = a2;
  if ( a2 != 2 )
  {
    v13 = *(_QWORD *)(v10 + 64);
    if ( a2 >= 0xFFF )
      v14 = 4095;
    else
      v14 = a2;
    v15 = -v14;
    if ( (*(_QWORD *)(v13 + 48) & 1) != 0 )
      __break(0x800u);
    *(_DWORD *)(v13 + 60) = v15;
  }
  v16 = dma_fence_signal_locked(*(_QWORD *)(v10 + 64));
  if ( v16 && (synx_debug & 1) != 0 )
    printk(&unk_2B795, &unk_29207, "synx_native_signal_fence", 595, *(_QWORD *)(v10 + 64), v16);
  raw_spin_unlock_irqrestore(**(_QWORD **)(v10 + 64), v12);
  return v16;
}
