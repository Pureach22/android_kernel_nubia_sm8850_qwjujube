__int64 __fastcall copy_session_ctrl_to_user(int *a1, unsigned __int64 a2)
{
  unsigned __int64 StatusReg; // x9
  __int64 v3; // x14
  unsigned __int64 v4; // x8
  unsigned int v6; // w8
  unsigned __int64 v8; // x12
  unsigned __int64 v13; // x13
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x11
  __int64 v17; // x11
  unsigned __int64 v18; // x12
  __int64 v19; // x14
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x16
  unsigned __int64 v24; // x17
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x15

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a2 << 8;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = a2 & (v3 >> 8);
  _CF = v4 >= 0x7FFFFFFFFDLL;
  v6 = -14;
  if ( !_CF )
  {
    _W11 = *a1;
    v8 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v13 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v13);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v8);
    __asm { STTR            W11, [X8] }
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v16 - 4096);
    _WriteStatusReg(TTBR1_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    v17 = 0;
    v18 = a2 + 4;
    v19 = v3 + 1024;
    do
    {
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v20 = v18 + v17 * 4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v20 = (v18 + v17 * 4) & (v19 >> 8);
      _CF = v20 >= 0x7FFFFFFFFDLL;
      v6 = -14;
      if ( _CF )
        break;
      _W15 = a1[v17 + 1];
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v24 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v24);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
      __asm { STTR            W15, [X8] }
      v25 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v27 - 4096);
      _WriteStatusReg(TTBR1_EL1, v27);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v25);
      ++v17;
      v6 = 0;
      v19 += 1024;
    }
    while ( v17 != 8 );
  }
  return v6;
}
