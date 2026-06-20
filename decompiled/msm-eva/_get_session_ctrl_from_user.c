__int64 __fastcall get_session_ctrl_from_user(_DWORD *a1, unsigned __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x12
  unsigned __int64 v4; // x10
  unsigned __int64 v6; // x11
  unsigned __int64 v12; // x13
  unsigned __int64 v14; // x10
  unsigned __int64 v16; // x13
  __int64 v17; // x10
  _DWORD *v18; // x0
  __int64 i; // x12
  unsigned __int64 v20; // x13
  unsigned __int64 v21; // x14
  unsigned __int64 v23; // x14
  unsigned __int64 v25; // x15
  unsigned __int64 v27; // x14
  unsigned __int64 v29; // x15

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a2 << 8;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = a2 & (v3 >> 8);
  if ( v4 < 0x7FFFFFFFFDLL )
  {
    _X10 = a2 & 0xFF7FFFFFFFFFFFFFLL;
    v6 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v12 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v12 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v12);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v6);
    __asm { LDTR            W11, [X10] }
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v16 - 4096);
    _WriteStatusReg(TTBR1_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    v17 = 0;
    *a1 = _X11;
    v18 = a1 + 1;
    for ( i = v3 + 1024; ; i += 1024 )
    {
      v20 = a2 + 4 + v17 * 4;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v21 = a2 + 4 + v17 * 4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v21 = v20 & (i >> 8);
      if ( v21 >= 0x7FFFFFFFFDLL )
        break;
      _X13 = v20 & 0xFF7FFFFFFFFFFFFFLL;
      v23 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v25 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v25);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v23);
      __asm { LDTR            W13, [X13] }
      v27 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v29 - 4096);
      _WriteStatusReg(TTBR1_EL1, v29);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v27);
      v18[v17++] = _X13;
      if ( v17 == 8 )
        return 0;
    }
    a1 = &v18[v17];
  }
  *a1 = 0;
  return 4294967282LL;
}
