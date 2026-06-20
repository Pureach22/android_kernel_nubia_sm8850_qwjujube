size_t __fastcall inline_copy_from_user(__int64 a1, unsigned __int64 a2, size_t n)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x9
  size_t v7; // x21
  unsigned __int64 v8; // x9
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v6 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v6 = a2 & ((__int64)(a2 << 8) >> 8);
  v7 = n;
  if ( n > 0x8000000000LL )
    goto LABEL_7;
  v7 = n;
  if ( 0x8000000000LL - n < v6 )
    goto LABEL_7;
  v8 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v14 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v14);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v8);
  v7 = _arch_copy_from_user(a1, a2 & 0xFF7FFFFFFFFFFFFFLL, n);
  v15 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v17 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v17 - 4096);
  _WriteStatusReg(TTBR1_EL1, v17);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v15);
  if ( v7 )
LABEL_7:
    memset((void *)(a1 + n - v7), 0, v7);
  return v7;
}
