void uaccess_ttbr0_enable_0()
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x9

  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 8);
  _WriteStatusReg(TTBR1_EL1, v6 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v6);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
}
