__int64 __fastcall stm_char_policy_get_ioctl(_DWORD *a1, unsigned __int64 a2)
{
  int v2; // w8
  int v3; // w9
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x9
  __int64 result; // x0
  unsigned __int64 v7; // x9
  unsigned __int64 v13; // x8
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9
  int v18; // [xsp+8h] [xbp-18h] BYREF
  __int16 v19; // [xsp+Ch] [xbp-14h]
  __int16 v20; // [xsp+Eh] [xbp-12h]
  __int16 v21; // [xsp+10h] [xbp-10h]
  __int16 v22; // [xsp+12h] [xbp-Eh]
  int v23; // [xsp+14h] [xbp-Ch]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 16;
  v3 = a1[3];
  v2 = a1[4];
  v22 = 0;
  v23 = 0;
  v19 = v3;
  LOWORD(v3) = a1[5];
  v20 = v2;
  StatusReg = _ReadStatusReg(SP_EL0);
  v21 = v3;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v5 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v5 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v5 <= 0x7FFFFFFFF0LL )
  {
    v7 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v13 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v13);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v7);
    v14 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, &v18, 16);
    v15 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v17 - 4096);
    _WriteStatusReg(TTBR1_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v15);
    if ( v14 )
      result = 4294967282LL;
    else
      result = 0;
  }
  else
  {
    result = 4294967282LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
