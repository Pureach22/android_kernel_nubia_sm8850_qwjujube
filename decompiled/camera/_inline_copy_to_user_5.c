__int64 __fastcall inline_copy_to_user_5(unsigned __int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x9
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v14; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a1, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = a1 & ((__int64)(a1 << 8) >> 8);
  if ( 0x8000000000LL - a3 >= v4 )
  {
    v5 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v11 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v11 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v11);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v5);
    a3 = _arch_copy_to_user(a1 & 0xFF7FFFFFFFFFFFFFLL);
    v12 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v14 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v14 - 4096);
    _WriteStatusReg(TTBR1_EL1, v14);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v12);
  }
  return a3;
}
