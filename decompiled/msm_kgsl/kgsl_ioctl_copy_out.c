__int64 __fastcall kgsl_ioctl_copy_out(unsigned int a1, unsigned int a2, unsigned __int64 a3, __int64 a4)
{
  unsigned int v4; // w8
  unsigned int v5; // w9
  __int64 v6; // x19
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v11; // x10
  unsigned __int64 v12; // x10
  unsigned __int64 v18; // x9
  __int64 v19; // x0
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9

  v4 = HIWORD(a2) & 0x3FFF;
  v5 = HIWORD(a1) & 0x3FFF;
  if ( v5 >= v4 )
    v6 = v4;
  else
    v6 = v5;
  if ( (a1 & 0x80000000) == 0 || (a2 & 0x80000000) == 0 || !(_DWORD)v6 )
    return 0;
  _check_object_size(a4, v6, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v11 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( 0x8000000000LL - v6 < v11 )
    return -14;
  v12 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v18 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v18);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v12);
  v19 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, a4, v6);
  v20 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v22 - 4096);
  _WriteStatusReg(TTBR1_EL1, v22);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v20);
  if ( v19 )
    return -14;
  else
    return 0;
}
