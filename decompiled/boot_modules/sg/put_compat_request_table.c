__int64 __fastcall put_compat_request_table(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x23
  __int64 v5; // x21
  unsigned __int64 StatusReg; // x24
  __int64 v7; // x8
  unsigned __int64 v8; // x9
  __int64 result; // x0
  unsigned __int64 v10; // x9
  unsigned __int64 v16; // x10
  __int64 v17; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v20; // x10
  unsigned __int64 v21; // x9
  unsigned __int64 v23; // x10
  unsigned __int64 v25; // x11
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x9
  unsigned __int64 v31; // x10
  unsigned __int64 v33; // x11
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x9
  unsigned __int64 v39; // x10
  unsigned __int64 v41; // x11
  unsigned __int64 v42; // x8
  unsigned __int64 v44; // x9

  v2 = a1 << 8;
  v5 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    v7 = a1 + v5;
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a1 + v5, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v8 = v7 & (v2 >> 8);
    result = 4294967282LL;
    if ( v8 > 0x7FFFFFFFF8LL )
      break;
    v10 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v16 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v16 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v16);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v10);
    v17 = _arch_copy_to_user(v7 & 0xFF7FFFFFFFFFFFFFLL, a2, 8);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    result = 4294967282LL;
    if ( v17 )
      break;
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) == 0 )
    {
      v21 = a1 + v5 + 8;
      if ( (*(_QWORD *)StatusReg & 0x4000000) == 0 )
        goto LABEL_10;
    }
    v21 = (a1 + v5 + 8) & ((v2 + 2048) >> 8);
LABEL_10:
    if ( v21 >= 0x7FFFFFFFFDLL )
      break;
    _W9 = a2[2];
    v23 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v25 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v25);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v23);
    __asm { STTR            W9, [X8] }
    v26 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v28 - 4096);
    _WriteStatusReg(TTBR1_EL1, v28);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v26);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) == 0 )
    {
      v29 = a1 + v5 + 12;
      if ( (*(_QWORD *)StatusReg & 0x4000000) == 0 )
        goto LABEL_22;
    }
    v29 = (a1 + v5 + 12) & ((v2 + 3072) >> 8);
LABEL_22:
    result = 4294967282LL;
    if ( v29 >= 0x7FFFFFFFFDLL )
      break;
    _W9 = a2[4];
    v31 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v33 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v33 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v33);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v31);
    __asm { STTR            W9, [X8] }
    v34 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v36 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v36 - 4096);
    _WriteStatusReg(TTBR1_EL1, v36);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v34);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) == 0 )
    {
      v37 = a1 + v5 + 16;
      if ( (*(_QWORD *)StatusReg & 0x4000000) == 0 )
        goto LABEL_23;
    }
    v37 = (a1 + v5 + 16) & ((v2 + 4096) >> 8);
LABEL_23:
    result = 4294967282LL;
    if ( v37 >= 0x7FFFFFFFFDLL )
      break;
    _W9 = a2[5];
    v39 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v41 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v41 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v41);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v39);
    __asm { STTR            W9, [X8] }
    v42 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v44 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v44 - 4096);
    _WriteStatusReg(TTBR1_EL1, v44);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v42);
    v5 += 20;
    result = 0;
    a2 += 6;
    v2 += 5120;
  }
  while ( v5 != 320 );
  return result;
}
