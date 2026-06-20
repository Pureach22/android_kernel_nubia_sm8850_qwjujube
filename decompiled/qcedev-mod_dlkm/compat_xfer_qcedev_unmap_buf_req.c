__int64 __fastcall compat_xfer_qcedev_unmap_buf_req(__int64 a1, int *a2, char a3)
{
  __int64 v3; // x12
  __int64 v4; // x11
  unsigned int v5; // w10
  int *v6; // x13
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x16
  unsigned __int64 v9; // x15
  int v12; // w15
  unsigned __int64 v14; // x15
  unsigned __int64 v19; // x16
  unsigned __int64 v20; // x15
  unsigned __int64 v22; // x16
  __int64 v24; // t1
  unsigned __int64 v25; // x16
  int v26; // w16
  unsigned __int64 v27; // x16
  unsigned __int64 v29; // x17
  unsigned __int64 v30; // x14
  unsigned __int64 v32; // x15
  __int64 v33; // x12
  unsigned __int64 v34; // x13
  int v36; // w9
  unsigned __int64 v38; // x11
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v43; // x9
  unsigned __int64 v46; // x13
  int v47; // w9
  unsigned __int64 v48; // x12
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  unsigned __int64 v53; // x9

  v3 = a1 << 8;
  v4 = 0;
  v5 = 0;
  v6 = a2;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (a3 & 1) != 0 )
  {
    do
    {
      v8 = a1 + v4;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a1 + v4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v9 = v8 & (v3 >> 8);
      LODWORD(_X14) = 0;
      _CF = v9 >= 0x7FFFFFFFF9LL;
      v12 = -14;
      if ( !_CF )
      {
        _X14 = v8 & 0xFF7FFFFFFFFFFFFFLL;
        v14 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v19 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v19);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v14);
        __asm { LDTR            X14, [X14] }
        v20 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v22 - 4096);
        _WriteStatusReg(TTBR1_EL1, v22);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v20);
        v12 = 0;
      }
      v4 += 8;
      v5 |= v12;
      v3 += 2048;
      *v6++ = _X14;
    }
    while ( v4 != 128 );
    v33 = a1 + 128;
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v34 = a1 + 128, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v34 = v33 & (v33 << 8 >> 8);
    LODWORD(_X11) = 0;
    v36 = -14;
    if ( v34 < 0x7FFFFFFFF9LL )
    {
      _X9 = v33 & 0xFF7FFFFFFFFFFFFFLL;
      v38 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v40 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v40 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v40);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v38);
      __asm { LDTR            X11, [X9] }
      v41 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v43 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v43 - 4096);
      _WriteStatusReg(TTBR1_EL1, v43);
      __isb(0xFu);
      v36 = 0;
      _WriteStatusReg(DAIF, v41);
    }
    a2[16] = _X11;
    return v36 | v5;
  }
  else
  {
    do
    {
      v24 = *v6++;
      _X14 = v24;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v25 = a1 + v4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v25 = (a1 + v4) & (v3 >> 8);
      _CF = v25 >= 0x7FFFFFFFF9LL;
      v26 = -14;
      if ( !_CF )
      {
        v27 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v29 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v29 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v29);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v27);
        __asm { STTR            X14, [X15] }
        v30 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v32 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v32 - 4096);
        _WriteStatusReg(TTBR1_EL1, v32);
        __isb(0xFu);
        v26 = 0;
        _WriteStatusReg(DAIF, v30);
      }
      v4 += 8;
      v5 |= v26;
      v3 += 2048;
    }
    while ( v4 != 128 );
    _X11 = (unsigned int)a2[16];
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v46 = a1 + 128, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v46 = (a1 + 128) & ((a1 + 128) << 8 >> 8);
    v47 = -14;
    if ( v46 < 0x7FFFFFFFF9LL )
    {
      v48 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v50 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v50 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v50);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v48);
      __asm { STTR            X11, [X9] }
      v51 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v53 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v53 - 4096);
      _WriteStatusReg(TTBR1_EL1, v53);
      __isb(0xFu);
      v47 = 0;
      _WriteStatusReg(DAIF, v51);
    }
    return v47 | v5;
  }
}
