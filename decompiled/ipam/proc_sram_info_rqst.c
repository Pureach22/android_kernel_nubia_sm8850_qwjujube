__int64 __fastcall proc_sram_info_rqst(unsigned __int64 a1)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x9
  __int64 result; // x0
  unsigned __int64 v5; // x9
  unsigned __int64 v11; // x8
  __int64 v12; // x0
  unsigned __int64 v13; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  int v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v16 = 0;
  if ( (unsigned int)ipa3_nat_get_sram_info(&v16) )
    goto LABEL_6;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v3 = a1, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v3 = a1 & ((__int64)(a1 << 8) >> 8);
  if ( v3 > 0x7FFFFFFFF4LL )
  {
LABEL_6:
    result = 4294967282LL;
  }
  else
  {
    v5 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v11 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v11 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v11);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v5);
    v12 = _arch_copy_to_user(a1 & 0xFF7FFFFFFFFFFFFFLL, &v16, 12);
    v13 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v15 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v15 - 4096);
    _WriteStatusReg(TTBR1_EL1, v15);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v13);
    if ( v12 )
      result = 4294967282LL;
    else
      result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
