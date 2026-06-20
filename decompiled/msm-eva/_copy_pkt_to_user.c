__int64 __fastcall copy_pkt_to_user(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x12
  __int64 v4; // x10
  unsigned __int64 StatusReg; // x14
  __int64 v6; // x15
  unsigned __int64 v7; // x8
  unsigned int v9; // w8
  unsigned __int64 v11; // x17
  unsigned __int64 v16; // x2
  unsigned __int64 v17; // x8
  unsigned __int64 v19; // x16
  unsigned __int64 v20; // x10
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x11
  unsigned __int64 v25; // x10
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  unsigned __int64 v30; // x8
  unsigned __int64 v32; // x9

  if ( a3 )
  {
    v3 = 4LL * a3;
    v4 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    v6 = (a2 << 8) + 4096;
    while ( 1 )
    {
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v7 = a2 + 16 + v4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v7 = (a2 + 16 + v4) & (v6 >> 8);
      _CF = v7 >= 0x7FFFFFFFFDLL;
      v9 = -14;
      if ( _CF )
        break;
      if ( v4 == 2400 )
      {
        __break(0x5512u);
        v30 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v32 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v32 - 4096);
        _WriteStatusReg(TTBR1_EL1, v32);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v30);
        return (unsigned int)-14;
      }
      _W16 = *(_DWORD *)(a1 + 16 + v4);
      v11 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v16 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v16 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v16);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v11);
      __asm { STTR            W16, [X8] }
      v17 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v19 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v19 - 4096);
      _WriteStatusReg(TTBR1_EL1, v19);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v17);
      v4 += 4;
      v6 += 1024;
      if ( v3 == v4 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    v20 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v20 + 70) & 0x20) != 0 || (v21 = a2 + 2416, (*(_QWORD *)v20 & 0x4000000) != 0) )
      v21 = (a2 + 2416) & ((a2 + 2416) << 8 >> 8);
    _CF = v21 >= 0x7FFFFFFFF9LL;
    v9 = -14;
    if ( !_CF )
    {
      _X9 = *(_QWORD *)(a1 + 2416);
      v23 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v25 = *(_QWORD *)(v20 + 8);
      _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v25);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v23);
      __asm { STTR            X9, [X8] }
      v26 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v28 - 4096);
      _WriteStatusReg(TTBR1_EL1, v28);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v26);
      return 0;
    }
  }
  return v9;
}
