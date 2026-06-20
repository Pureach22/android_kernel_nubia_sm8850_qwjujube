__int64 __fastcall dp_debug_read_hdr(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  __int64 v5; // x20
  unsigned __int64 v10; // x19
  __int64 ipc_log_context; // x0
  __int64 v12; // x0
  unsigned int v13; // w0
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v17; // x10
  unsigned __int64 v18; // x9
  __int64 v19; // x0
  _QWORD *v21; // x10
  unsigned __int64 v22; // x9
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v30; // x11

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_245274, "dp_debug_read_hdr");
    return -19;
  }
  v5 = **(_QWORD **)(v4 + 144);
  if ( !v5 )
  {
    v12 = get_ipc_log_context(a1);
    ipc_log_string(v12, "[e][%-4d]connector is NULL\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_272998, "dp_debug_read_hdr");
    return -22;
  }
  if ( *a4 )
    return 0;
  v10 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  if ( v10 < 0x11 )
    return -12;
  v13 = ((__int64 (__fastcall *)(__int64, unsigned __int64))dp_debug_print_hdr_params_to_buf)(v5, v10);
  if ( v13 == -75 )
  {
    kfree(v10);
    return 4294967221LL;
  }
  v14 = v13;
  if ( v13 >= a3 )
    v14 = a3;
  v15 = v14;
  if ( v14 > 0x1000 )
  {
    _copy_overflow(4096, v14);
LABEL_21:
    kfree(v10);
    return -14;
  }
  _check_object_size(v10, v14, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v17 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v17 = a2 & ((__int64)(a2 << 8) >> 8);
  v18 = v15;
  v19 = v15;
  _CF = 0x8000000000LL - v15 >= v17;
  v21 = a4;
  if ( _CF )
  {
    v22 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v27 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v27 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v27);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v22);
    v19 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
    v18 = v15;
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
    goto LABEL_21;
  *v21 += v18;
  kfree(v10);
  return v15;
}
