void sub_646C()
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x9

  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v6 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v6 - 4096);
  _WriteStatusReg(TTBR1_EL1, v6);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  JUMPOUT(0x6424);
}
