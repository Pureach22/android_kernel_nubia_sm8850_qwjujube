__int64 __fastcall debugfs_line_count_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  _DWORD *v4; // x24
  unsigned __int64 v5; // x20
  unsigned __int64 v8; // x19
  unsigned int v9; // w21
  __int64 v10; // x21
  __int64 v11; // x21
  unsigned __int64 v12; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x0
  _QWORD *v17; // x9
  unsigned __int64 v18; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x10

  v4 = *(_DWORD **)(a1 + 32);
  if ( a3 >= 0x1000 )
    v5 = 4096;
  else
    v5 = a3;
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v8 = _kmalloc_noprof(v5, 3520);
  if ( v8 < 0x11 )
    return -12;
  mutex_lock(v4 + 8);
  v9 = scnprintf(v8, v5, "Command triggered at line: %04x\n", v4[725]);
  v10 = (unsigned int)scnprintf(v8 + v9, v5 - v9, "Command triggered at frame: %04x\n", v4[726]) + v9;
  v11 = (unsigned int)scnprintf(v8 + v10, v5 - v10, "Command successful at line: %04x\n", v4[727]) + (unsigned int)v10;
  v12 = (unsigned int)scnprintf(v8 + v11, v5 - v11, "Command successful at frame: %04x\n", v4[728]) + (unsigned int)v11;
  mutex_unlock(v4 + 8);
  if ( v5 >= v12 )
    v5 = (unsigned int)v12;
  else
    v5 = (unsigned int)v5;
  if ( (v5 & 0x80000000) != 0 )
  {
    __break(0x800u);
  }
  else
  {
    _check_object_size(v8, v5, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v14 = a2 & ((__int64)(a2 << 8) >> 8);
    v15 = v5;
    _CF = 0x8000000000LL - v5 >= v14;
    v17 = a4;
    if ( _CF )
    {
      v18 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v18);
      v15 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
      v17 = a4;
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v26 - 4096);
      _WriteStatusReg(TTBR1_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
    }
    if ( !v15 )
      *v17 += v5;
  }
  kfree(v8);
  return v5;
}
