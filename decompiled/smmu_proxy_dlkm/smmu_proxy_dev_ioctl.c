__int64 __fastcall smmu_proxy_dev_ioctl(__int64 a1, unsigned int a2, unsigned __int64 a3)
{
  size_t v3; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  size_t v9; // x22
  unsigned __int64 v10; // x1
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x0
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v3 = HIWORD(a2) & 0x3FFF;
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)v3 > 0x10 )
  {
    result = -22;
LABEL_23:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v22 = 0;
  v23 = 0;
  _check_object_size(&v22, HIWORD(a2) & 0x3FFF, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a3 & ((__int64)(a3 << 8) >> 8);
  v9 = v3;
  if ( 0x8000000000LL - v3 >= v8 )
  {
    v11 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v11);
    v9 = _arch_copy_from_user(&v22, a3 & 0xFF7FFFFFFFFFFFFFLL, v3);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    if ( !v9 )
    {
LABEL_14:
      if ( (a2 & 0x40000000) == 0 )
      {
        v22 = 0;
        v23 = 0;
      }
      if ( a2 == -2146413312 )
      {
        LODWORD(result) = smmu_proxy_get_csf_version(&v22);
        if ( (_DWORD)result )
        {
          result = (int)result;
        }
        else
        {
          _check_object_size(&v22, v3, 1);
          if ( inline_copy_to_user(a3) )
            result = -14;
          else
            result = 0;
        }
      }
      else
      {
        result = -25;
      }
      goto LABEL_23;
    }
  }
  if ( v3 - v9 <= 0x10 )
    v10 = 16 - (v3 - v9);
  else
    v10 = 0;
  if ( v10 >= v9 )
  {
    memset((char *)&v22 + v3 - v9, 0, v9);
    if ( v9 )
    {
      result = -14;
      goto LABEL_23;
    }
    goto LABEL_14;
  }
  v21 = _fortify_panic(15);
  return inline_copy_to_user(v21);
}
