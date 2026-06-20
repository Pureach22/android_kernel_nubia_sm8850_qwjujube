__int64 __fastcall debug_read_helper(__int64 a1, unsigned __int64 a2, __int64 a3, _QWORD *a4, int a5)
{
  __int64 v5; // x19
  __int64 result; // x0
  __int64 v12; // x25
  unsigned int v13; // w8
  unsigned int v15; // w23
  unsigned int v21; // w9
  __int64 v22; // x23
  int v23; // w27
  unsigned int v24; // w26
  unsigned int v25; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x9
  unsigned __int64 v30; // x8
  __int64 v31; // x0
  unsigned __int64 v32; // x8
  unsigned __int64 v34; // x9
  __int64 v35; // x8
  __int64 v36; // x21
  int v38; // w9

  v5 = *(_QWORD *)(a1 + 72);
  LODWORD(result) = debugfs_file_get(v5);
  if ( (_DWORD)result )
    return (int)result;
  v12 = *(_QWORD *)(a1 + 32);
  _X20 = (unsigned int *)(v12 + 200);
  v13 = *(_DWORD *)(v12 + 200);
  if ( v13 )
  {
    do
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v21 = __ldxr(_X20);
      while ( v21 == v13 && __stxr(v13 + 1, _X20) );
      v15 = v13;
      if ( v21 == v13 )
        break;
      v15 = 0;
      v13 = v21;
    }
    while ( v21 );
  }
  else
  {
    v15 = 0;
  }
  if ( (((v15 + 1) | v15) & 0x80000000) == 0 )
  {
    if ( v15 )
      goto LABEL_14;
LABEL_32:
    debugfs_file_put(v5);
    return -5;
  }
  refcount_warn_saturate(_X20, 0);
  if ( !v15 )
    goto LABEL_32;
LABEL_14:
  v22 = _kmalloc_noprof(a3, 3264);
  if ( v22 )
  {
    if ( (int)a3 < 1020 )
    {
      printk(&unk_831E, "debug_log");
      v24 = -12;
    }
    else
    {
      v23 = a3 - 1;
      while ( 1 )
      {
        v24 = ipc_log_extract(v12, v22, v23);
        if ( !a5 || v24 )
          break;
        v25 = wait_for_completion_interruptible(v12 + 168);
        if ( (v25 & 0x80000000) != 0 )
        {
          v24 = v25;
          goto LABEL_30;
        }
      }
      if ( (int)v24 >= 1 )
      {
        _check_object_size(v22, v24, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v27 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v27 = a2 & ((__int64)(a2 << 8) >> 8);
        if ( 0x8000000000LL - (unsigned __int64)v24 < v27 )
          goto LABEL_27;
        v28 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v30 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v30 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v30);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v28);
        v31 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v22, v24);
        v32 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v34 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v34 - 4096);
        _WriteStatusReg(TTBR1_EL1, v34);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v32);
        if ( v31 )
        {
LABEL_27:
          kfree(v22);
          v35 = -14;
          goto LABEL_39;
        }
        *a4 += v24;
      }
    }
LABEL_30:
    kfree(v22);
    v35 = (int)v24;
  }
  else
  {
    v35 = -12;
  }
LABEL_39:
  __asm { PRFM            #0x11, [X20] }
  do
    v38 = __ldxr(_X20);
  while ( __stlxr(v38 - 1, _X20) );
  v36 = v35;
  if ( v38 == 1 )
  {
    __dmb(9u);
    ipc_log_context_free((__int64)_X20);
  }
  else if ( v38 <= 0 )
  {
    refcount_warn_saturate(_X20, 3);
  }
  debugfs_file_put(v5);
  return v36;
}
