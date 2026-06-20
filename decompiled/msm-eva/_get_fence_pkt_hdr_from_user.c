__int64 __fastcall get_fence_pkt_hdr_from_user(__int64 a1, _DWORD *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x10
  unsigned __int64 v4; // x11
  unsigned __int64 v6; // x11
  unsigned __int64 v12; // x12
  unsigned __int64 v14; // x11
  unsigned __int64 v16; // x12
  __int64 v17; // x10
  unsigned __int64 v18; // x11
  unsigned __int64 v20; // x10
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  unsigned __int64 v26; // x10

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a1 + 16;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a1 + 16, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = v3 & (v3 << 8 >> 8);
  if ( v4 >= 0x7FFFFFFFFDLL )
  {
    *a2 = 0;
    return 4294967282LL;
  }
  else
  {
    _X10 = v3 & 0xFF7FFFFFFFFFFFFFLL;
    v6 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v12 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v12 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v12);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v6);
    __asm { LDTR            W10, [X10] }
    v14 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v16 - 4096);
    _WriteStatusReg(TTBR1_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v14);
    *a2 = _X10;
    v17 = a1 + 20;
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v18 = a1 + 20, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v18 = v17 & (v17 << 8 >> 8);
    if ( v18 >= 0x7FFFFFFFFDLL )
    {
      a2[1] = 0;
      return 4294967282LL;
    }
    else
    {
      _X9 = v17 & 0xFF7FFFFFFFFFFFFFLL;
      v20 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v22 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v22);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v20);
      __asm { LDTR            W8, [X9] }
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v26 - 4096);
      _WriteStatusReg(TTBR1_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
      LODWORD(v24) = *a2;
      a2[1] = _X8;
      if ( (unsigned int)v24 <= 0x960 )
        return 0;
      else
        return 4294967274LL;
    }
  }
}
