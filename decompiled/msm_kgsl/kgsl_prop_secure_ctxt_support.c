__int64 __fastcall kgsl_prop_secure_ctxt_support(__int64 *a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x9
  char v4; // w11
  int v5; // w10
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x10
  unsigned __int64 v14; // x9
  __int64 v15; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9
  __int64 result; // x0
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a2 + 16) == 4 )
  {
    v2 = *a1;
    StatusReg = _ReadStatusReg(SP_EL0);
    v4 = *(_BYTE *)(StatusReg + 70);
    v5 = *(unsigned __int8 *)(v2 + 96);
    v6 = *(_QWORD *)(a2 + 8);
    v20 = v5;
    if ( (v4 & 0x20) != 0 || (v7 = v6, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v7 = v6 & ((__int64)(v6 << 8) >> 8);
    if ( v7 > 0x7FFFFFFFFCLL )
    {
      result = -14;
    }
    else
    {
      v8 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v14 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v14);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v8);
      v15 = _arch_copy_to_user(v6 & 0xFF7FFFFFFFFFFFFFLL, &v20, 4);
      v16 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v18 - 4096);
      _WriteStatusReg(TTBR1_EL1, v18);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v16);
      if ( v15 )
        result = -14;
      else
        result = 0;
    }
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
