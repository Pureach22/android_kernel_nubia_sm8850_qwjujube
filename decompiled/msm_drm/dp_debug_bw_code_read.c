__int64 __fastcall dp_debug_bw_code_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x23
  unsigned __int64 v5; // x20
  char *v8; // x0
  char *v9; // x19
  unsigned int v10; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v12; // x9
  __int64 v13; // x0
  _QWORD *v15; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x10

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v5 = a3;
  v8 = (char *)_kmalloc_cache_noprof(kthread_park, 3520, 4096);
  v9 = v8;
  if ( (unsigned __int64)v8 < 0x11 )
    return -12;
  v10 = snprintf(v8, 0x1000u, "max_bw_code = %d\n", *(_DWORD *)(*(_QWORD *)(v4 + 120) + 896LL));
  if ( v10 < v5 )
    v5 = v10;
  if ( v5 > 0x1000 )
  {
    _copy_overflow(4096, v5);
    v5 = -14;
  }
  else
  {
    _check_object_size(v9, v5, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v12 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v12 = a2 & ((__int64)(a2 << 8) >> 8);
    v13 = v5;
    _CF = 0x8000000000LL - v5 >= v12;
    v15 = a4;
    if ( _CF )
    {
      v16 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v21 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v21);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v16);
      v13 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
      v15 = a4;
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v24 - 4096);
      _WriteStatusReg(TTBR1_EL1, v24);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
    }
    if ( v13 )
      v5 = -14;
    else
      *v15 += v5;
  }
  kfree(v9);
  return v5;
}
