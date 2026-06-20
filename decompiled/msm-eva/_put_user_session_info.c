__int64 __fastcall put_user_session_info(int *a1, unsigned __int64 a2)
{
  unsigned __int64 StatusReg; // x9
  __int64 v3; // x11
  unsigned __int64 v4; // x8
  unsigned int v6; // w8
  unsigned __int64 v8; // x13
  unsigned __int64 v13; // x14
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x12
  __int64 v17; // x11
  __int64 i; // x12
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x14
  unsigned __int64 v23; // x15
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x13

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a2 << 8;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = a2 & (v3 >> 8);
  _CF = v4 >= 0x7FFFFFFFFDLL;
  v6 = -14;
  if ( !_CF )
  {
    _W12 = *a1;
    v8 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v13 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v13);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v8);
    __asm { STTR            W12, [X8] }
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v16 - 4096);
    _WriteStatusReg(TTBR1_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    v17 = v3 + 1024;
    for ( i = 1; i != 11; ++i )
    {
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v19 = a2 + i * 4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v19 = (a2 + i * 4) & (v17 >> 8);
      _CF = v19 >= 0x7FFFFFFFFDLL;
      v6 = -14;
      if ( _CF )
        break;
      _W13 = a1[i];
      v21 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v21);
      __asm { STTR            W13, [X8] }
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v26 - 4096);
      _WriteStatusReg(TTBR1_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
      v6 = 0;
      v17 += 1024;
    }
  }
  return v6;
}
