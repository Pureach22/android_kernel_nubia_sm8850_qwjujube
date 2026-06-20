__int64 __fastcall compat_xfer_qcedev_map_buf_req(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x9
  __int64 v4; // x13
  unsigned int v5; // w11
  __int64 v6; // x14
  __int64 v7; // x15
  unsigned __int64 StatusReg; // x12
  __int64 v9; // x3
  unsigned __int64 v10; // x17
  int v13; // w17
  unsigned __int64 v15; // x2
  unsigned __int64 v20; // x3
  unsigned __int64 v21; // x17
  unsigned __int64 v23; // x3
  __int64 v24; // x4
  unsigned __int64 v25; // x2
  int v27; // w2
  unsigned __int64 v29; // x3
  unsigned __int64 v31; // x4
  unsigned __int64 v32; // x2
  unsigned __int64 v34; // x4
  __int64 v35; // x5
  unsigned __int64 v36; // x3
  int v38; // w3
  unsigned __int64 v40; // x4
  unsigned __int64 v42; // x5
  unsigned __int64 v43; // x3
  unsigned __int64 v45; // x5
  __int64 v46; // x6
  unsigned __int64 v47; // x5
  int v49; // w5
  unsigned __int64 v51; // x5
  unsigned __int64 v53; // x6
  unsigned __int64 v54; // x5
  unsigned __int64 v56; // x6
  unsigned int *v57; // x14
  unsigned __int64 v58; // x12
  unsigned __int64 v60; // x17
  int v61; // w17
  unsigned __int64 v62; // x3
  unsigned __int64 v64; // x4
  unsigned __int64 v65; // x17
  unsigned __int64 v67; // x2
  unsigned __int64 v69; // x2
  int v70; // w2
  unsigned __int64 v71; // x4
  unsigned __int64 v73; // x5
  unsigned __int64 v74; // x2
  unsigned __int64 v76; // x3
  unsigned __int64 v78; // x3
  int v79; // w3
  unsigned __int64 v80; // x5
  unsigned __int64 v82; // x6
  unsigned __int64 v83; // x3
  unsigned __int64 v85; // x4
  unsigned __int64 v87; // x5
  int v88; // w5
  unsigned __int64 v89; // x6
  unsigned __int64 v91; // x7
  unsigned __int64 v92; // x4
  unsigned __int64 v94; // x5
  __int64 v95; // x10
  unsigned __int64 v96; // x13
  int v98; // w8
  unsigned __int64 v100; // x9
  unsigned __int64 v102; // x10
  unsigned __int64 v103; // x8
  unsigned __int64 v105; // x10
  unsigned __int64 v108; // x13
  int v109; // w8
  unsigned __int64 v110; // x10
  unsigned __int64 v112; // x12
  unsigned __int64 v113; // x8
  unsigned __int64 v115; // x9

  v3 = a1 << 8;
  v4 = 0;
  v5 = 0;
  if ( (a3 & 1) != 0 )
  {
    v6 = a2 + 200;
    v7 = -64;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v9 = a1 + v4;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v10 = a1 + v4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v10 = v9 & (v3 >> 8);
      LODWORD(_X2) = 0;
      _CF = v10 >= 0x7FFFFFFFF9LL;
      v13 = -14;
      if ( !_CF )
      {
        _X17 = v9 & 0xFF7FFFFFFFFFFFFFLL;
        v15 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v20 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v20);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v15);
        __asm { LDTR            X2, [X17] }
        v21 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v23 - 4096);
        _WriteStatusReg(TTBR1_EL1, v23);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v21);
        v13 = 0;
      }
      *(_DWORD *)(v6 + v7 - 136) = _X2;
      v24 = a1 + v4 + 136;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v25 = a1 + v4 + 136, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v25 = v24 & ((v3 + 34816) >> 8);
      LODWORD(_X3) = 0;
      _CF = v25 >= 0x7FFFFFFFF9LL;
      v27 = -14;
      if ( !_CF )
      {
        _X2 = v24 & 0xFF7FFFFFFFFFFFFFLL;
        v29 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v31 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v31 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v31);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v29);
        __asm { LDTR            X3, [X2] }
        v32 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v34 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v34 - 4096);
        _WriteStatusReg(TTBR1_EL1, v34);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v32);
        v27 = 0;
      }
      *(_DWORD *)(v6 + v7 - 68) = _X3;
      v35 = a1 + v4 + 264;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v36 = a1 + v4 + 264, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v36 = v35 & ((v3 + 67584) >> 8);
      LODWORD(_X4) = 0;
      _CF = v36 >= 0x7FFFFFFFF9LL;
      v38 = -14;
      if ( !_CF )
      {
        _X3 = v35 & 0xFF7FFFFFFFFFFFFFLL;
        v40 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v42 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v42 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v42);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v40);
        __asm { LDTR            X4, [X3] }
        v43 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v45 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v45 - 4096);
        _WriteStatusReg(TTBR1_EL1, v45);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v43);
        v38 = 0;
      }
      *(_DWORD *)(v6 + v7 - 4) = _X4;
      v46 = a1 + v4 + 392;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v47 = a1 + v4 + 392, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v47 = v46 & ((v3 + 100352) >> 8);
      LODWORD(_X4) = 0;
      _CF = v47 >= 0x7FFFFFFFF9LL;
      v49 = -14;
      if ( !_CF )
      {
        _X4 = v46 & 0xFF7FFFFFFFFFFFFFLL;
        v51 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v53 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v53 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v53);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v51);
        __asm { LDTR            X4, [X4] }
        v54 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v56 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v56 - 4096);
        _WriteStatusReg(TTBR1_EL1, v56);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v54);
        v49 = 0;
      }
      *(_DWORD *)(v6 + v4) = _X4;
      v4 += 8;
      v3 += 2048;
      v5 |= v13 | v27 | v38 | v49;
      v7 += 4;
    }
    while ( v4 != 128 );
    v95 = a1 + 128;
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v96 = a1 + 128, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v96 = v95 & (v95 << 8 >> 8);
    LODWORD(_X9) = 0;
    v98 = -14;
    if ( v96 < 0x7FFFFFFFF9LL )
    {
      _X8 = v95 & 0xFF7FFFFFFFFFFFFFLL;
      v100 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v102 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v102 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v102);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v100);
      __asm { LDTR            X9, [X8] }
      v103 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v105 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v105 - 4096);
      _WriteStatusReg(TTBR1_EL1, v105);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v103);
      v98 = 0;
    }
    *(_DWORD *)(a2 + 64) = _X9;
    return v98 | v5;
  }
  else
  {
    v57 = (unsigned int *)(a2 + 132);
    v58 = _ReadStatusReg(SP_EL0);
    do
    {
      _X2 = (int)*(v57 - 33);
      if ( (*(_BYTE *)(v58 + 70) & 0x20) != 0 || (v60 = a1 + v4, (*(_QWORD *)v58 & 0x4000000) != 0) )
        v60 = (a1 + v4) & (v3 >> 8);
      _CF = v60 >= 0x7FFFFFFFF9LL;
      v61 = -14;
      if ( !_CF )
      {
        v62 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v64 = *(_QWORD *)(v58 + 8);
        _WriteStatusReg(TTBR1_EL1, v64 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v64);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v62);
        __asm { STTR            X2, [X17] }
        v65 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v67 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v67 - 4096);
        _WriteStatusReg(TTBR1_EL1, v67);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v65);
        v61 = 0;
      }
      _X3 = *(v57 - 16);
      if ( (*(_BYTE *)(v58 + 70) & 0x20) != 0 || (v69 = a1 + v4 + 136, (*(_QWORD *)v58 & 0x4000000) != 0) )
        v69 = (a1 + v4 + 136) & ((v3 + 34816) >> 8);
      _CF = v69 >= 0x7FFFFFFFF9LL;
      v70 = -14;
      if ( !_CF )
      {
        v71 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v73 = *(_QWORD *)(v58 + 8);
        _WriteStatusReg(TTBR1_EL1, v73 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v73);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v71);
        __asm { STTR            X3, [X2] }
        v74 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v76 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v76 - 4096);
        _WriteStatusReg(TTBR1_EL1, v76);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v74);
        v70 = 0;
      }
      _X4 = *v57;
      if ( (*(_BYTE *)(v58 + 70) & 0x20) != 0 || (v78 = a1 + v4 + 264, (*(_QWORD *)v58 & 0x4000000) != 0) )
        v78 = (a1 + v4 + 264) & ((v3 + 67584) >> 8);
      _CF = v78 >= 0x7FFFFFFFF9LL;
      v79 = -14;
      if ( !_CF )
      {
        v80 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v82 = *(_QWORD *)(v58 + 8);
        _WriteStatusReg(TTBR1_EL1, v82 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v82);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v80);
        __asm { STTR            X4, [X3] }
        v83 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v85 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v85 - 4096);
        _WriteStatusReg(TTBR1_EL1, v85);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v83);
        v79 = 0;
      }
      _X4 = *(unsigned int *)(a2 + 200 + v4);
      if ( (*(_BYTE *)(v58 + 70) & 0x20) != 0 || (v87 = a1 + v4 + 392, (*(_QWORD *)v58 & 0x4000000) != 0) )
        v87 = (a1 + v4 + 392) & ((v3 + 100352) >> 8);
      _CF = v87 >= 0x7FFFFFFFF9LL;
      v88 = -14;
      if ( !_CF )
      {
        v89 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v91 = *(_QWORD *)(v58 + 8);
        _WriteStatusReg(TTBR1_EL1, v91 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v91);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v89);
        __asm { STTR            X4, [X5] }
        v92 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v94 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v94 - 4096);
        _WriteStatusReg(TTBR1_EL1, v94);
        __isb(0xFu);
        v88 = 0;
        _WriteStatusReg(DAIF, v92);
      }
      v4 += 8;
      v3 += 2048;
      v5 |= v61 | v70 | v79 | v88;
      ++v57;
    }
    while ( v4 != 128 );
    _X9 = *(unsigned int *)(a2 + 64);
    if ( (*(_BYTE *)(v58 + 70) & 0x20) != 0 || (v108 = a1 + 128, (*(_QWORD *)v58 & 0x4000000) != 0) )
      v108 = (a1 + 128) & ((a1 + 128) << 8 >> 8);
    v109 = -14;
    if ( v108 < 0x7FFFFFFFF9LL )
    {
      v110 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v112 = *(_QWORD *)(v58 + 8);
      _WriteStatusReg(TTBR1_EL1, v112 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v112);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v110);
      __asm { STTR            X9, [X8] }
      v113 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v115 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v115 - 4096);
      _WriteStatusReg(TTBR1_EL1, v115);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v113);
      v109 = 0;
    }
    return v109 | v5;
  }
}
