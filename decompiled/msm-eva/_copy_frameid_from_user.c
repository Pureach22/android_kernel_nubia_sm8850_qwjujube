__int64 __fastcall copy_frameid_from_user(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x9
  __int64 v3; // x8
  unsigned __int64 v4; // x10
  unsigned __int64 v6; // x10
  unsigned __int64 v12; // x11
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x9
  unsigned int v17; // w8

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a2 + 16;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a2 + 16, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = v3 & (v3 << 8 >> 8);
  if ( v4 > 0x7FFFFFFFF8LL )
  {
    *(_QWORD *)(a1 + 16) = 0;
    v17 = -14;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_9362C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return (unsigned int)-14;
    }
  }
  else
  {
    _X8 = v3 & 0xFF7FFFFFFFFFFFFFLL;
    v6 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v12 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v12 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v12);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v6);
    __asm { LDTR            X10, [X8] }
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v16 - 4096);
    _WriteStatusReg(TTBR1_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    v17 = 0;
    *(_QWORD *)(a1 + 16) = _X10;
  }
  return v17;
}
