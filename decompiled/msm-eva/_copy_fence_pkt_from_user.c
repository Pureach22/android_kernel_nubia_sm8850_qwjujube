__int64 __fastcall copy_fence_pkt_from_user(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x11
  __int64 i; // x10
  __int64 v5; // x12
  unsigned __int64 v6; // x13
  unsigned __int64 v8; // x13
  unsigned __int64 v14; // x14
  unsigned __int64 v16; // x13
  unsigned __int64 v18; // x14
  __int64 v19; // x10
  unsigned __int64 v20; // x11
  unsigned __int64 v22; // x12
  unsigned __int64 v24; // x13
  unsigned __int64 v26; // x11
  unsigned __int64 v28; // x13
  __int64 v29; // x14
  __int64 v30; // x13
  __int64 v31; // x11
  __int64 v32; // x12
  unsigned __int64 v33; // x16
  unsigned __int64 v35; // x16
  unsigned __int64 v37; // x17
  unsigned __int64 v39; // x16
  unsigned __int64 v41; // x17
  __int64 v42; // x10
  unsigned __int64 v43; // x11
  unsigned __int64 v45; // x10
  unsigned __int64 v47; // x8
  unsigned __int64 v49; // x9
  unsigned __int64 v51; // x10
  __int64 result; // x0
  unsigned __int64 v53; // x16
  unsigned __int64 v55; // x16
  unsigned __int64 v57; // x17
  unsigned __int64 v59; // x16
  unsigned __int64 v61; // x17
  __int64 v62; // x10
  unsigned __int64 v63; // x11
  unsigned __int64 v65; // x10
  unsigned __int64 v67; // x11
  unsigned __int64 v69; // x8
  unsigned __int64 v71; // x10

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = (a2 << 8) + 4096;
  for ( i = 16; i != 2416; i += 4 )
  {
    v5 = a2 + i;
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v6 = a2 + i, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v6 = v5 & (v3 >> 8);
    if ( v6 >= 0x7FFFFFFFFDLL )
    {
      *(_DWORD *)(a1 + i) = 0;
      return 4294967282LL;
    }
    _X12 = v5 & 0xFF7FFFFFFFFFFFFFLL;
    v8 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v14 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v14);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v8);
    __asm { LDTR            W12, [X12] }
    v16 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v18 - 4096);
    _WriteStatusReg(TTBR1_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v16);
    *(_DWORD *)(a1 + i) = _X12;
    v3 += 1024;
  }
  v19 = a2 + 2416;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v20 = a2 + 2416, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v20 = v19 & (v19 << 8 >> 8);
  if ( v20 >= 0x7FFFFFFFFDLL )
  {
    *(_DWORD *)(a1 + 2416) = 0;
  }
  else
  {
    _X11 = v19 & 0xFF7FFFFFFFFFFFFFLL;
    v22 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v24 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v24);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v22);
    __asm { LDTR            W12, [X11] }
    v26 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v28 - 4096);
    _WriteStatusReg(TTBR1_EL1, v28);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v26);
    *(_DWORD *)(a1 + 2416) = _X12;
    v29 = a2 + 2416;
    v30 = (a2 << 8) + 618496;
    _ZF = (_DWORD)_X12 == -17958194;
    v31 = a1 + 2416;
    v32 = 0;
    if ( _ZF )
    {
      while ( 1 )
      {
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v33 = v19 + v32, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v33 = (v29 + v32) & (v30 >> 8);
        if ( v33 >= 0x7FFFFFFFFDLL )
          break;
        _X15 = (v19 + v32) & 0xFF7FFFFFFFFFFFFFLL;
        v35 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v37 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v37 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v37);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v35);
        __asm { LDTR            W15, [X15] }
        v39 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v41 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v41 - 4096);
        _WriteStatusReg(TTBR1_EL1, v41);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v39);
        *(_DWORD *)(v31 + v32) = _X15;
        v32 += 4;
        v30 += 1024;
        if ( v32 == 280 )
        {
          v42 = a2 + 2696;
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v43 = a2 + 2696, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v43 = v42 & (v42 << 8 >> 8);
          if ( v43 < 0x7FFFFFFFF9LL )
          {
            _X9 = v42 & 0xFF7FFFFFFFFFFFFFLL;
            v45 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v47 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v47 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v47);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v45);
            __asm { LDTR            X8, [X9] }
            v49 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v51 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v51 - 4096);
            _WriteStatusReg(TTBR1_EL1, v51);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v49);
            *(_QWORD *)(a1 + 2696) = _X8;
            return 0;
          }
          *(_QWORD *)(a1 + 2696) = 0;
          return 4294967282LL;
        }
      }
    }
    else
    {
      while ( 1 )
      {
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v53 = v19 + v32, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v53 = (v29 + v32) & (v30 >> 8);
        if ( v53 >= 0x7FFFFFFFFDLL )
          break;
        _X15 = (v19 + v32) & 0xFF7FFFFFFFFFFFFFLL;
        v55 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v57 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v57 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v57);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v55);
        __asm { LDTR            W15, [X15] }
        v59 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v61 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v61 - 4096);
        _WriteStatusReg(TTBR1_EL1, v61);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v59);
        *(_DWORD *)(v31 + v32) = _X15;
        v32 += 4;
        v30 += 1024;
        if ( v32 == 256 )
        {
          v62 = a2 + 2672;
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v63 = a2 + 2672, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v63 = v62 & (v62 << 8 >> 8);
          if ( v63 < 0x7FFFFFFFF9LL )
          {
            _X9 = v62 & 0xFF7FFFFFFFFFFFFFLL;
            v65 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v67 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v67 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v67);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v65);
            __asm { LDTR            X9, [X9] }
            v69 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v71 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v71 - 4096);
            _WriteStatusReg(TTBR1_EL1, v71);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v69);
            *(_QWORD *)(a1 + 2672) = _X9;
            return 0;
          }
          *(_QWORD *)(a1 + 2672) = 0;
          result = 4294967282LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_86765, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            return 4294967282LL;
          }
          return result;
        }
      }
    }
    *(_DWORD *)(v31 + v32) = 0;
  }
  return 4294967282LL;
}
