__int64 __fastcall copy_prop(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w8
  __int64 v4; // x19
  unsigned __int64 v6; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x9
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9

  v3 = *(_DWORD *)(a1 + 16);
  if ( a3 >= v3 )
    v4 = v3;
  else
    v4 = a3;
  if ( (v4 & 0x80000000) != 0 )
  {
    __break(0x800u);
    return 4294967282LL;
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 8);
    _check_object_size(a2, v4, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = v6, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v8 = v6 & ((__int64)(v6 << 8) >> 8);
    if ( 0x8000000000LL - v4 >= v8 )
    {
      v9 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v15 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v15 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v15);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v9);
      v4 = _arch_copy_to_user(v6 & 0xFF7FFFFFFFFFFFFFLL, a2, v4);
      v16 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v18 - 4096);
      _WriteStatusReg(TTBR1_EL1, v18);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v16);
    }
    if ( v4 )
      return 4294967282LL;
    else
      return 0;
  }
}
