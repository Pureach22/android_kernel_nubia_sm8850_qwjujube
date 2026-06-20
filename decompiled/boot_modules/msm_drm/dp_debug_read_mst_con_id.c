__int64 __fastcall dp_debug_read_mst_con_id(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x23
  unsigned __int64 v6; // x21
  char *v9; // x0
  char *v10; // x20
  unsigned int v11; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x0
  unsigned __int64 v15; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  __int64 ipc_log_context; // x0

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_245274, "dp_debug_read_mst_con_id");
    return -19;
  }
  if ( *a4 )
    return 0;
  v6 = a3;
  v9 = (char *)_kmalloc_cache_noprof(kthread_park, 3520, 4096);
  v10 = v9;
  if ( !v9 )
    return -12;
  v11 = snprintf(v9, 0x1000u, "%u\n", *(_DWORD *)(v4 + 16));
  if ( v11 < v6 )
    v6 = v11;
  if ( v6 > 0x1000 )
  {
    _copy_overflow(4096, v6);
  }
  else
  {
    _check_object_size(v10, v6, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v13 = a2 & ((__int64)(a2 << 8) >> 8);
    v14 = v6;
    if ( 0x8000000000LL - v6 >= v13 )
    {
      v15 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v21 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v21);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v15);
      v14 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v24 - 4096);
      _WriteStatusReg(TTBR1_EL1, v24);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
    }
    if ( !v14 )
    {
      *a4 += v6;
      kfree(v10);
      return v6;
    }
  }
  kfree(v10);
  return -14;
}
