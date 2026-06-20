__int64 __fastcall st54spi_get_ioc_message(unsigned int a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x19
  __int64 v6; // x0
  __int64 v7; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9

  if ( (a1 & 0xC000FFFF) != 0x40006B00 )
    return -25;
  v3 = HIWORD(a1) & 0x3FFF;
  if ( (a1 & 0x1F0000) != 0 )
    return -22;
  *a3 = (unsigned int)v3 >> 5;
  if ( (unsigned int)v3 < 0x20 )
    return 0;
  v6 = _kmalloc_noprof(HIWORD(a1) & 0x3FFF, 3264);
  if ( !v6 )
    return -12;
  v7 = v6;
  _check_object_size(v6, v3, 0);
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 8);
  _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v14);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  v15 = _arch_copy_from_user(v7, a2 & 0xFF7FFFFFFFFFFFFFLL, v3);
  v16 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v18 - 4096);
  _WriteStatusReg(TTBR1_EL1, v18);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v16);
  if ( !v15 )
    return v7;
  kfree(v7);
  return -14;
}
