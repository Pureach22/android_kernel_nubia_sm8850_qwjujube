__int64 __fastcall backing_dev_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  _QWORD *v6; // x20
  const char *v7; // x21
  size_t v8; // x0
  unsigned __int64 v9; // x2
  size_t v10; // x0
  size_t v11; // x8
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x22
  __int64 v14; // x23
  __int64 v15; // x8
  __int64 v16; // x24
  __int64 v17; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v19; // x24
  __int64 v21; // x25

  v6 = *(_QWORD **)(*(_QWORD *)(a1 - 224) + 88LL);
  v7 = (const char *)_kmalloc_cache_noprof(raw_spin_unlock_irq, 3264, 4096);
  if ( !v7 )
    return -12;
  while ( 1 )
  {
    down_write(v6 + 4);
    if ( v6[27] )
    {
      printk(&unk_B6FF);
      a4 = -16;
LABEL_16:
      kvfree(0);
      goto LABEL_23;
    }
    v8 = strnlen(a3, 0x1000u);
    if ( v8 == -1 )
    {
      _fortify_panic(2, -1, 0);
LABEL_27:
      v10 = _fortify_panic(7, 4096, v9);
LABEL_28:
      _fortify_panic(2, 4096, v10 + 1);
      goto LABEL_29;
    }
    if ( v8 == 4096 )
      v9 = 4096;
    else
      v9 = v8 + 1;
    if ( v9 > 0x1000 )
      goto LABEL_27;
    sized_strscpy(v7, a3);
    v10 = strnlen(v7, 0x1000u);
    if ( v10 > 0x1000 )
      goto LABEL_28;
    if ( !v10 )
      goto LABEL_14;
    if ( v10 != 4096 )
      break;
LABEL_29:
    _fortify_panic(4, 4096, 4097);
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &backing_dev_store__alloc_tag;
    v7 = (const char *)_kmalloc_cache_noprof(raw_spin_unlock_irq, 3264, 4096);
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !v7 )
      return -12;
  }
  v11 = v10 - 1;
  if ( v7[v11] == 10 )
    v7[v11] = 0;
LABEL_14:
  v12 = filp_open_block(v7, 131202, 0);
  v13 = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    a4 = (int)v12;
    goto LABEL_16;
  }
  v14 = **(_QWORD **)(v12 + 24);
  if ( (*(_WORD *)v14 & 0xF000) != 0x6000 )
  {
    a4 = -15;
    goto LABEL_21;
  }
  v15 = atomic_load((unsigned __int64 *)(v14 + 80));
  v16 = v15 >> 12;
  v17 = _kvmalloc_node_noprof(((unsigned __int64)((v15 >> 12) + 63) >> 3) & 0xFFFFFFF8, 0, 3520, 0xFFFFFFFFLL);
  if ( !v17 )
  {
    a4 = -12;
LABEL_21:
    kvfree(0);
    if ( v13 )
      filp_close(v13, 0);
LABEL_23:
    up_write(v6 + 4);
    goto LABEL_24;
  }
  v21 = v17;
  reset_bdev(v6);
  v6[33] = I_BDEV(v14);
  v6[34] = v21;
  v6[30] = v13;
  v6[35] = v16;
  up_write(v6 + 4);
  printk(&unk_B518);
LABEL_24:
  kfree(v7);
  return a4;
}
