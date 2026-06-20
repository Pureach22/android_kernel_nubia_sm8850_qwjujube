__int64 __fastcall copy_pkt_from_user(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x9
  unsigned __int64 v5; // x11
  unsigned __int64 v6; // x10
  __int64 v7; // x12
  __int64 v8; // x14
  unsigned __int64 StatusReg; // x15
  __int64 v10; // x13
  __int64 v11; // x16
  unsigned __int64 v12; // x17
  unsigned __int64 v14; // x2
  unsigned __int64 v20; // x3
  unsigned __int64 v22; // x2
  unsigned __int64 v24; // x3
  unsigned __int64 v25; // x9
  __int64 v26; // x10
  unsigned __int64 v27; // x11
  unsigned __int64 v29; // x10
  unsigned __int64 v31; // x9
  unsigned __int64 v33; // x9
  unsigned __int64 v35; // x10
  unsigned __int64 v37; // x8
  unsigned __int64 v39; // x11

  if ( a4 )
  {
    v4 = a1 + 16;
    v5 = a4 + a3;
    v6 = a3;
    v7 = a2 + 4LL * a3 + 16;
    if ( a3 <= 0x259 )
      v8 = 601;
    else
      v8 = a3;
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = v7 << 8;
    v11 = a2 + 4LL * a3 + 16;
    while ( v8 != v6 )
    {
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v12 = v11, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v12 = v7 & (v10 >> 8);
      if ( v12 >= 0x7FFFFFFFFDLL )
        goto LABEL_18;
      _X17 = v11 & 0xFF7FFFFFFFFFFFFFLL;
      v14 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v20 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v20);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v14);
      __asm { LDTR            W17, [X17] }
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v24 - 4096);
      _WriteStatusReg(TTBR1_EL1, v24);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
      *(_DWORD *)(v4 + 4 * v6++) = _X17;
      v11 += 4;
      v7 += 4;
      v10 += 1024;
      if ( v6 >= v5 )
        goto LABEL_12;
    }
    __break(0x5512u);
    v37 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v39 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v39 - 4096);
    _WriteStatusReg(TTBR1_EL1, v39);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v37);
LABEL_18:
    *(_DWORD *)(v4 + 4 * v6) = 0;
    return 4294967282LL;
  }
  else
  {
LABEL_12:
    v25 = _ReadStatusReg(SP_EL0);
    v26 = a2 + 2416;
    if ( (*(_BYTE *)(v25 + 70) & 0x20) != 0 || (v27 = a2 + 2416, (*(_QWORD *)v25 & 0x4000000) != 0) )
      v27 = v26 & (v26 << 8 >> 8);
    if ( v27 >= 0x7FFFFFFFF9LL )
    {
      *(_QWORD *)(a1 + 2416) = 0;
      return 4294967282LL;
    }
    else
    {
      _X8 = v26 & 0xFF7FFFFFFFFFFFFFLL;
      v29 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v31 = *(_QWORD *)(v25 + 8);
      _WriteStatusReg(TTBR1_EL1, v31 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v31);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v29);
      __asm { LDTR            X8, [X8] }
      v33 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v35 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v35 - 4096);
      _WriteStatusReg(TTBR1_EL1, v35);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v33);
      *(_QWORD *)(a1 + 2416) = _X8;
      return 0;
    }
  }
}
