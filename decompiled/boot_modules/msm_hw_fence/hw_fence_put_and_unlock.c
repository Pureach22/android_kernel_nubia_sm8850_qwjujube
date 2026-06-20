__int64 __fastcall hw_fence_put_and_unlock(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  int v5; // w8
  __int64 v6; // x20
  unsigned __int64 v9; // x9
  int v10; // w8
  int v11; // w21
  int v12; // w24
  char v13; // w23
  __int64 result; // x0
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x21
  __int64 v17; // x0
  _QWORD *v18; // x8
  __int64 v19; // x9
  unsigned int v20; // w25
  __int64 v21; // x22
  __int64 (__fastcall *v22)(_QWORD); // x8
  int v23; // w8
  unsigned int v24; // w8
  __int64 v26; // t1
  int v33; // w8

  v5 = *(_DWORD *)(a3 + 112);
  v6 = v4;
  if ( (v5 & 0x3FFFFFFF) == 0 )
  {
    global_atomic_store(a1, a3 + 40, 0);
    printk(&unk_20C04, "hw_fence_put_and_unlock", 1778, v6, a2);
    return 4294967274LL;
  }
  v9 = *(_QWORD *)(a3 + 48);
  v10 = v5 - 1;
  *(_DWORD *)(a3 + 112) = v10;
  if ( (v10 & 0x3FFFFFFF) != 0 )
    v11 = 0;
  else
    v11 = (v9 >> 2) & 1;
  if ( v11 == 1 )
  {
    v12 = *(_DWORD *)(a3 + 4);
    v13 = v9 & 0xFB;
    *(_QWORD *)(a3 + 48) = v9 & 0xFFFFFFFFFFFFFFFBLL;
    if ( v10 )
      goto LABEL_10;
  }
  else
  {
    v13 = 0;
    v12 = 0;
    if ( v10 )
      goto LABEL_10;
  }
  *(_DWORD *)(a3 + 4) = 0;
  __dsb(0xEu);
  *(_QWORD *)(a3 + 8) = 0;
  *(_QWORD *)(a3 + 16) = 0;
  *(_QWORD *)(a3 + 24) = 0;
  *(_QWORD *)(a3 + 32) = 0;
  *(_QWORD *)(a3 + 80) = 0;
  *(_QWORD *)(a3 + 88) = 0;
  *(_QWORD *)(a3 + 96) = 0;
  *(_QWORD *)(a3 + 104) = 0;
  *(_QWORD *)(a3 + 48) = 0;
  *(_QWORD *)(a3 + 56) = -1;
  *(_QWORD *)(a3 + 64) = -1;
  *(_QWORD *)(a3 + 72) = -1;
  *(_QWORD *)(a3 + 112) = 0;
  *(_QWORD *)(a3 + 120) = 0;
  *(_DWORD *)a3 = 0;
LABEL_10:
  global_atomic_store(a1, a3 + 40, 0);
  result = 0;
  if ( !v11 )
    return result;
  v15 = hw_fence_dma_fence_find(a1, a4, 0);
  v16 = v15;
  if ( !v15 || v15 >= 0xFFFFFFFFFFFFF001LL )
  {
    v20 = v15;
    if ( (_DWORD)v15 )
      goto LABEL_49;
    return 0;
  }
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    printk(&unk_24A38, "hw_fence_dma_fence_table_del", 1655, *(_QWORD *)(v15 + 32), *(_QWORD *)(v15 + 40));
  v17 = raw_spin_lock_irqsave(a1 + 748);
  v18 = *(_QWORD **)(v16 + 192);
  if ( v18 )
  {
    v19 = *(_QWORD *)(v16 + 184);
    *v18 = v19;
    if ( v19 )
      *(_QWORD *)(v19 + 8) = v18;
    *(_QWORD *)(v16 + 184) = 0;
    *(_QWORD *)(v16 + 192) = 0;
    raw_spin_unlock_irqrestore(a1 + 748, v17);
    v20 = 0;
  }
  else
  {
    raw_spin_unlock_irqrestore(a1 + 748, v17);
    printk(&unk_28C87, "hw_fence_dma_fence_table_del", 1667, v6, *(_QWORD *)(v16 + 32));
    v20 = -22;
  }
  dma_fence_remove_callback(v16, v16 + 144);
  v21 = raw_spin_lock_irqsave(*(_QWORD *)v16);
  if ( (*(_QWORD *)(v16 + 48) & 1) == 0 )
  {
    v22 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v16 + 8) + 32LL);
    if ( v22 )
    {
      if ( *((_DWORD *)v22 - 1) != 1879296680 )
        __break(0x8228u);
      if ( (v22(v16) & 1) != 0 )
      {
        dma_fence_signal(v16);
        goto LABEL_35;
      }
    }
    if ( (v13 & 1) != 0 )
      v23 = v12;
    else
      v23 = 4;
    if ( !v23 )
      goto LABEL_34;
    v24 = -v23;
    if ( (*(_QWORD *)(v16 + 48) & 1) != 0 )
    {
      __break(0x800u);
      if ( v24 > 0xFFFFF000 )
        goto LABEL_33;
    }
    else if ( v24 > 0xFFFFF000 )
    {
LABEL_33:
      *(_DWORD *)(v16 + 60) = v24;
LABEL_34:
      dma_fence_signal_locked(v16);
      goto LABEL_35;
    }
    __break(0x800u);
    goto LABEL_33;
  }
LABEL_35:
  v26 = *(_QWORD *)v16;
  _X21 = (unsigned int *)(v16 + 56);
  raw_spin_unlock_irqrestore(v26, v21);
  __asm { PRFM            #0x11, [X21] }
  do
    v33 = __ldxr(_X21);
  while ( __stlxr(v33 - 1, _X21) );
  if ( v33 != 1 )
  {
    if ( v33 <= 0 )
    {
      refcount_warn_saturate(_X21, 3);
      if ( !v20 )
        return 0;
    }
    else if ( !v20 )
    {
      return 0;
    }
LABEL_49:
    printk(&unk_29E1E, "hw_fence_put_and_unlock", 1786, v6, a4);
    return v20;
  }
  __dmb(9u);
  dma_fence_release(_X21);
  if ( v20 )
    goto LABEL_49;
  return 0;
}
