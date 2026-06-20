__int64 __fastcall compat_ipa3_nat_ipv6ct_alloc_table(unsigned __int64 a1, __int64 (__fastcall *a2)(_QWORD))
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  char v6; // w10
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x9
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  __int64 v19; // [xsp+8h] [xbp-18h]
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  result = inline_copy_from_user((int)v20, a1, 8u);
  if ( !result )
  {
    v18 = LODWORD(v20[0]);
    v19 = SHIDWORD(v20[0]);
    if ( *((_DWORD *)a2 - 1) != 1016474549 )
      __break(0x8234u);
    LODWORD(result) = a2(&v18);
    if ( (_DWORD)result )
    {
      result = (int)result;
    }
    else
    {
      result = 0;
      if ( v19 )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v6 = *(_BYTE *)(StatusReg + 70);
        HIDWORD(v20[0]) = v19;
        if ( (v6 & 0x20) != 0 || (v7 = a1, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v7 = a1 & ((__int64)(a1 << 8) >> 8);
        result = 8;
        if ( v7 <= 0x7FFFFFFFF8LL )
        {
          v8 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v14 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v14);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v8);
          result = _arch_copy_to_user(a1 & 0xFF7FFFFFFFFFFFFFLL, v20, 8);
          v15 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v17 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v17 - 4096);
          _WriteStatusReg(TTBR1_EL1, v17);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v15);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
