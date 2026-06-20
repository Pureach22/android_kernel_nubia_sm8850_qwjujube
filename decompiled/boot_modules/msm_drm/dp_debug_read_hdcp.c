__int64 __fastcall dp_debug_read_hdcp(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 v5; // x19
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v9; // x10
  __int64 v10; // x0
  _QWORD *v12; // x10
  unsigned __int64 v13; // x10
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  if ( a3 >= 0x80 )
    v5 = 128;
  else
    v5 = a3;
  _check_object_size(v4 + 174, v5, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v9 = a2 & ((__int64)(a2 << 8) >> 8);
  v10 = v5;
  _CF = 0x8000000000LL - v5 >= v9;
  v12 = a4;
  if ( _CF )
  {
    v13 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v13);
    v10 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
    v12 = a4;
    v19 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v21 - 4096);
    _WriteStatusReg(TTBR1_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v19);
  }
  if ( v10 )
    return -14;
  *v12 += v5;
  return v5;
}
