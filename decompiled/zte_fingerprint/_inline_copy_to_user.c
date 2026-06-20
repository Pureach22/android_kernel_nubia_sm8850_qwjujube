__int64 __fastcall inline_copy_to_user(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x10
  __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v15; // x10

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v3 = a1, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v3 = a1 & ((__int64)(a1 << 8) >> 8);
  v4 = v3 >> 39;
  v5 = 1;
  if ( !v4 )
  {
    v6 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v12 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v12 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v12);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v6);
    v5 = _arch_copy_to_user(a1 & 0xFF7FFFFFFFFFFFFFLL, a2, 1);
    v13 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v15 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v15 - 4096);
    _WriteStatusReg(TTBR1_EL1, v15);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v13);
  }
  return v5;
}
