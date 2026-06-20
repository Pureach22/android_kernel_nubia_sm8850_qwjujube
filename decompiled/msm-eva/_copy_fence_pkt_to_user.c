__int64 __fastcall copy_fence_pkt_to_user(__int64 a1, __int64 a2)
{
  __int64 v2; // x12
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x11
  unsigned __int64 v5; // x8
  unsigned int v7; // w8
  unsigned __int64 v9; // x14
  unsigned __int64 v14; // x15
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x13
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x11
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v25; // x9

  v2 = 16;
  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = (a2 << 8) + 4096;
  while ( 1 )
  {
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v5 = a2 + v2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v5 = (a2 + v2) & (v4 >> 8);
    _CF = v5 >= 0x7FFFFFFFFDLL;
    v7 = -14;
    if ( _CF )
      break;
    _W13 = *(_DWORD *)(a1 + v2);
    v9 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v14 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v14);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v9);
    __asm { STTR            W13, [X8] }
    v15 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v17 - 4096);
    _WriteStatusReg(TTBR1_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v15);
    v2 += 4;
    v4 += 1024;
    if ( v2 == 2416 )
    {
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v18 = a2 + 2696, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v18 = (a2 + 2696) & ((a2 + 2696) << 8 >> 8);
      _CF = v18 >= 0x7FFFFFFFF9LL;
      v7 = -14;
      if ( !_CF )
      {
        _X10 = *(_QWORD *)(a1 + 2696);
        v20 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v22 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v22);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v20);
        __asm { STTR            X10, [X8] }
        v23 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v25 - 4096);
        _WriteStatusReg(TTBR1_EL1, v25);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v23);
        return 0;
      }
      return v7;
    }
  }
  return v7;
}
