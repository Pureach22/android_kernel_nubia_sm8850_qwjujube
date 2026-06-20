__int64 __fastcall zte_ir_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x20
  unsigned __int64 v6; // x9
  unsigned __int64 v8; // x10
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9

  if ( (a2 & 0x40000000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = *(_QWORD *)(a1 + 32);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v6 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v6 = a3 & ((__int64)(a3 << 8) >> 8);
    result = -14;
    if ( v6 <= 0x7FFFFFFFFCLL )
    {
      _X9 = a3 & 0xFF7FFFFFFFFFFFFFLL;
      v8 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v14 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v14);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v8);
      __asm { LDTR            W19, [X9] }
      v16 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v18 - 4096);
      _WriteStatusReg(TTBR1_EL1, v18);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v16);
      result = -25;
      if ( a2 == 1074030897 )
      {
        printk(&unk_6F42, "zte_ir_ioctl");
        result = -22;
        if ( (_DWORD)_X19 )
        {
          *(_DWORD *)(v5 + 80008) = 16 * _X19;
          return 0;
        }
      }
    }
  }
  else
  {
    result = -25;
    if ( a2 == 1074030897 )
    {
      printk(&unk_6F42, "zte_ir_ioctl");
      return -22;
    }
  }
  return result;
}
