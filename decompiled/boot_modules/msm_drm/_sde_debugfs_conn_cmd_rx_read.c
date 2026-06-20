__int64 __fastcall sde_debugfs_conn_cmd_rx_read(__int64 a1, unsigned __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x20
  __int64 v5; // x25
  int v6; // w8
  unsigned int v9; // w26
  size_t v10; // x20
  const char *v11; // x19
  size_t v12; // x3
  __int64 v13; // x27
  const char *v14; // x22
  int v15; // w0
  size_t v16; // x0
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x9
  __int64 v19; // x0
  _QWORD *v21; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v30; // x10
  void *v31; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v33; // x22

  if ( *a4 )
    return 0;
  v5 = *(_QWORD *)(a1 + 32);
  if ( !v5 )
  {
    v31 = &unk_250682;
LABEL_24:
    printk(v31, "_sde_debugfs_conn_cmd_rx_read");
    return -22;
  }
  v6 = *(_DWORD *)(v5 + 5004);
  if ( (unsigned int)(v6 - 257) <= 0xFFFFFEFF )
  {
    v31 = &unk_216618;
    goto LABEL_24;
  }
  v9 = 5 * v6 + 1;
  v10 = v9;
  v11 = (const char *)_kmalloc_noprof(v9, 3520);
  if ( !v11 )
    return -12;
  while ( 1 )
  {
    mutex_lock(v5 + 2816);
    if ( *(int *)(v5 + 5004) >= 1 )
    {
      v13 = 0;
      v14 = v11;
      while ( v13 != 256 )
      {
        v15 = scnprintf(v14, (int)v9, "0x%.2x ", *(unsigned __int8 *)(v5 + 4747 + v13++));
        v14 += v15;
        v9 -= v15;
        if ( v13 >= *(int *)(v5 + 5004) )
          goto LABEL_10;
      }
      __break(0x5512u);
LABEL_28:
      _fortify_panic(2, v10, v12 + 1);
      goto LABEL_29;
    }
LABEL_10:
    mutex_unlock(v5 + 2816);
    v16 = strnlen(v11, v10);
    v12 = v16;
    if ( v16 > v10 )
      goto LABEL_28;
    if ( v16 < v10 )
      break;
LABEL_29:
    _fortify_panic(4, v10, v12 + 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    v33 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sde_debugfs_conn_cmd_rx_read__alloc_tag;
    v11 = (const char *)_kmalloc_noprof(v10, 3520);
    *(_QWORD *)(StatusReg + 80) = v33;
    if ( !v11 )
      return -12;
  }
  if ( (int)v16 <= 0 )
  {
    printk(&unk_23FAC0, "_sde_debugfs_conn_cmd_rx_read");
    v4 = -14;
  }
  else
  {
    v4 = v16 & 0x7FFFFFFF;
    _check_object_size(v11, v4, 1);
    v17 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v17 + 70) & 0x20) != 0 || (v18 = a2, (*(_QWORD *)v17 & 0x4000000) != 0) )
      v18 = a2 & ((__int64)(a2 << 8) >> 8);
    v19 = v4;
    _CF = 0x8000000000LL - v4 >= v18;
    v21 = a4;
    if ( _CF )
    {
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v27 = *(_QWORD *)(v17 + 8);
      _WriteStatusReg(TTBR1_EL1, v27 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v27);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
      v19 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
      v21 = a4;
      v28 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v30 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v30 - 4096);
      _WriteStatusReg(TTBR1_EL1, v30);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v28);
    }
    if ( v19 )
    {
      printk(&unk_2165E3, "_sde_debugfs_conn_cmd_rx_read");
      v4 = -14;
    }
    else
    {
      *v21 += v4;
    }
  }
  kfree(v11);
  return v4;
}
