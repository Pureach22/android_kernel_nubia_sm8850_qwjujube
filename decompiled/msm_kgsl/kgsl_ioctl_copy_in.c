__int64 __fastcall kgsl_ioctl_copy_in(unsigned int a1, unsigned int a2, unsigned __int64 a3, __int64 a4)
{
  unsigned int v4; // w8
  unsigned int v5; // w9
  size_t v6; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v11; // x10
  size_t v12; // x2
  unsigned __int64 v13; // x10
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9

  v4 = HIWORD(a2) & 0x3FFF;
  v5 = HIWORD(a1) & 0x3FFF;
  if ( v5 >= v4 )
    v6 = v4;
  else
    v6 = v5;
  if ( (a1 & 0x40000000) == 0 )
    return 0;
  result = 0;
  if ( (a2 & 0x40000000) != 0 && (_DWORD)v6 )
  {
    _check_object_size(a4, v6, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v11 = a3 & ((__int64)(a3 << 8) >> 8);
    v12 = v6;
    if ( 0x8000000000LL - v6 < v11 )
      goto LABEL_13;
    v13 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v19 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v19);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v13);
    v12 = _arch_copy_from_user(a4, a3 & 0xFF7FFFFFFFFFFFFFLL, v6);
    v20 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v22 - 4096);
    _WriteStatusReg(TTBR1_EL1, v22);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v20);
    if ( v12 )
    {
LABEL_13:
      memset((void *)(a4 + v6 - v12), 0, v12);
      return -14;
    }
    return 0;
  }
  return result;
}
