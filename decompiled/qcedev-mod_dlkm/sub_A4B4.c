void sub_A4B4()
{
  unsigned __int64 StatusReg; // x13
  unsigned __int64 v6; // x14

  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v6 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v6 - 4096);
  _WriteStatusReg(TTBR1_EL1, v6);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  JUMPOUT(0x9C40);
}
