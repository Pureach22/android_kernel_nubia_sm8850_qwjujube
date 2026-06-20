__int64 __fastcall inline_copy_from_user_0(unsigned __int64 a1, size_t n)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x9
  size_t v5; // x20
  size_t v6; // x1
  unsigned __int64 v7; // x9
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x9
  __int64 v18; // x0
  __int64 v19; // x1

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a1, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = a1 & ((__int64)(a1 << 8) >> 8);
  v5 = n;
  if ( 0x8000000000LL - n >= v4 )
  {
    v7 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v13 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v13);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v7);
    v5 = _arch_copy_from_user(dbg_buff, a1 & 0xFF7FFFFFFFFFFFFFLL, n);
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v16 - 4096);
    _WriteStatusReg(TTBR1_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    if ( !v5 )
      return v5;
  }
  if ( n - v5 <= 0x1001 )
    v6 = 4097 - (n - v5);
  else
    v6 = 0;
  if ( v6 >= v5 )
  {
    memset(&dbg_buff[n - v5], 0, v5);
    return v5;
  }
  v18 = _fortify_panic(15, v6, v5);
  return ipa3_attrib_dump(v18, v19);
}
