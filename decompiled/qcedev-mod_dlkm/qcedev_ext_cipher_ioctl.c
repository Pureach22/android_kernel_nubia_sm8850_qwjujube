__int64 __fastcall qcedev_ext_cipher_ioctl(__int64 a1, int a2, _DWORD *a3, unsigned __int64 a4)
{
  unsigned __int64 StatusReg; // x22
  void *v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  unsigned __int64 v11; // x3
  __int64 result; // x0
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x0
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  v8 = a3 + 14;
  if ( (*(_QWORD *)StatusReg & 0x400000) != 0 )
  {
    memmove(v8, (const void *)a4, 0x2F8u);
  }
  else if ( inline_copy_from_user((int)v8, a4, 0x2F8u) )
  {
    return -14;
  }
  a3[12] = 2;
  if ( (unsigned int)qcedev_check_extended_cipher_params((__int64)(a3 + 14), v9, v10, v11) )
    return -22;
  a3[203] = 0;
  LODWORD(result) = qcedev_smmu_ablk_offload_cipher((__int64)a3, a1);
  if ( (_DWORD)result )
    return (int)result;
  if ( (*(_QWORD *)StatusReg & 0x400000) != 0 )
  {
    memmove((void *)a4, a3 + 14, 0x2F8u);
  }
  else
  {
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = a4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v13 = a4 & ((__int64)(a4 << 8) >> 8);
    if ( v13 > 0x7FFFFFFD08LL )
      return -14;
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    v21 = _arch_copy_to_user(a4 & 0xFF7FFFFFFFFFFFFFLL, a3 + 14, 760);
    v22 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v24 - 4096);
    _WriteStatusReg(TTBR1_EL1, v24);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v22);
    if ( v21 )
      return -14;
  }
  return 0;
}
