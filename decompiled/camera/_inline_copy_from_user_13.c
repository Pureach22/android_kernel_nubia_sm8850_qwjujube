size_t __fastcall inline_copy_from_user_13(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x9
  unsigned __int64 v11; // x8
  size_t v12; // x20
  unsigned __int64 v13; // x8
  unsigned __int64 v15; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v4 > 0x7FFFFFFFE8LL )
  {
    v12 = 24;
LABEL_8:
    memset((void *)(a1 - v12 + 24), 0, v12);
    return v12;
  }
  v5 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v11 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v11 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v11);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v5);
  v12 = _arch_copy_from_user(a1, a2 & 0xFF7FFFFFFFFFFFFFLL, 24);
  v13 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v15 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v15 - 4096);
  _WriteStatusReg(TTBR1_EL1, v15);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v13);
  if ( v12 )
    goto LABEL_8;
  return v12;
}
