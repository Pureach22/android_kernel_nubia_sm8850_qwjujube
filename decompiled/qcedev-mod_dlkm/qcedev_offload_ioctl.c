__int64 __fastcall qcedev_offload_ioctl(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 StatusReg; // x22
  __int64 result; // x0
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v19; // x9
  __int64 v20; // x0
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  _QWORD v24[76]; // [xsp+0h] [xbp-260h] BYREF

  v24[75] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 0x258u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_QWORD *)StatusReg & 0x400000) != 0 )
  {
    memmove(v24, (const void *)a4, 0x258u);
LABEL_5:
    qcedev_offload_translate_to_areq(a3, (__int64)v24);
    *(_DWORD *)(a3 + 48) = 2;
    if ( (unsigned int)qcedev_check_extended_cipher_params(a3 + 56) )
    {
      result = -22;
      goto LABEL_18;
    }
    *(_DWORD *)(a3 + 812) = 0;
    LODWORD(result) = qcedev_smmu_ablk_offload_cipher(a3, a1);
    if ( (_DWORD)result )
    {
      result = (int)result;
      goto LABEL_18;
    }
    v9 = *(_QWORD *)(a3 + 608);
    v10 = *(_QWORD *)(a3 + 616);
    v24[66] = *(_QWORD *)(a3 + 600);
    v11 = *(_QWORD *)(a3 + 624);
    v24[67] = v9;
    LODWORD(v9) = *(_DWORD *)(a3 + 812);
    v24[68] = v10;
    v24[69] = v11;
    LODWORD(v24[74]) = v9;
    if ( (*(_QWORD *)StatusReg & 0x400000) != 0 )
    {
      memmove((void *)a4, v24, 0x258u);
    }
    else
    {
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v12 = a4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v12 = a4 & ((__int64)(a4 << 8) >> 8);
      if ( v12 > 0x7FFFFFFDA8LL )
        goto LABEL_3;
      v13 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v19 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v19);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v13);
      v20 = _arch_copy_to_user(a4 & 0xFF7FFFFFFFFFFFFFLL, v24, 600);
      v21 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v23 - 4096);
      _WriteStatusReg(TTBR1_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v21);
      if ( v20 )
        goto LABEL_3;
    }
    result = 0;
    goto LABEL_18;
  }
  if ( !inline_copy_from_user((int)v24, a4, 0x258u) )
    goto LABEL_5;
LABEL_3:
  result = -14;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
