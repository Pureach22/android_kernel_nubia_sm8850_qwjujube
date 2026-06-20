__int64 __fastcall copy_sysprop_to_user(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x11
  __int64 v4; // x10
  __int64 v5; // x12
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v7; // x15
  __int64 result; // x0
  unsigned __int64 v10; // x16
  unsigned __int64 v16; // x17
  unsigned __int64 v17; // x14
  unsigned __int64 v19; // x15

  v2 = 0;
  v3 = a2 + 24;
  v4 = (a2 << 8) + 6144;
  v5 = a1 + 24;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v7 = v3 + v2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v7 = (v3 + v2) & (v4 >> 8);
    result = 4294967282LL;
    if ( v7 > 0x7FFFFFFFFCLL )
      break;
    _W15 = *(_DWORD *)(v5 + v2);
    v10 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v16 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v10);
    __asm { STTR            W15, [X14] }
    v17 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v19 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v19 - 4096);
    _WriteStatusReg(TTBR1_EL1, v19);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v17);
    v2 += 8;
    result = 0;
    v4 += 2048;
  }
  while ( v2 != 64 );
  return result;
}
