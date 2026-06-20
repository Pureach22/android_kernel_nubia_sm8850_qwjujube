__int64 __fastcall get_session_info_from_user(_DWORD *a1, unsigned __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x10
  unsigned __int64 v4; // x11
  unsigned __int64 v6; // x12
  unsigned __int64 v12; // x13
  unsigned __int64 v14; // x12
  unsigned __int64 v16; // x13
  __int64 v17; // x11
  __int64 v18; // x10
  unsigned __int64 v19; // x12
  unsigned __int64 v20; // x13
  unsigned __int64 v22; // x13
  unsigned __int64 v24; // x14
  unsigned __int64 v26; // x13
  unsigned __int64 v28; // x14

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a2 << 8;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = a2 & (v3 >> 8);
  if ( v4 < 0x7FFFFFFFFDLL )
  {
    _X11 = a2 & 0xFF7FFFFFFFFFFFFFLL;
    v6 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v12 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v12 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v12);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v6);
    __asm { LDTR            W11, [X11] }
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v16 - 4096);
    _WriteStatusReg(TTBR1_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    *a1 = _X11;
    v17 = v3 + 1024;
    v18 = 1;
    while ( 1 )
    {
      v19 = a2 + v18 * 4;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v20 = a2 + v18 * 4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v20 = v19 & (v17 >> 8);
      if ( v20 >= 0x7FFFFFFFFDLL )
        break;
      _X12 = v19 & 0xFF7FFFFFFFFFFFFFLL;
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v24 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v24);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
      __asm { LDTR            W12, [X12] }
      v26 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v28 - 4096);
      _WriteStatusReg(TTBR1_EL1, v28);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v26);
      a1[v18++] = _X12;
      v17 += 1024;
      if ( v18 == 11 )
        return 0;
    }
    a1 = (_DWORD *)((char *)a1 + v18 * 4);
  }
  *a1 = 0;
  return 4294967282LL;
}
