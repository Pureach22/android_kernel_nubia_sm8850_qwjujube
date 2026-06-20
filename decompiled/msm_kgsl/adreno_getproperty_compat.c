__int64 __fastcall adreno_getproperty_compat(__int64 a1, __int64 a2)
{
  int v2; // w9
  unsigned __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x10
  char v6; // w11
  __int64 v7; // x10
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x10
  unsigned __int64 v16; // x9
  __int64 v17; // x0
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v24; // x8
  unsigned __int64 v25; // x10
  __int64 result; // x0
  __int64 (*v27)(void); // x8
  unsigned __int64 v28; // x10
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x8
  unsigned __int64 v33; // x9
  __int64 v34; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v35[12]; // [xsp+8h] [xbp-18h]
  int v36; // [xsp+14h] [xbp-Ch]
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)a2 == 2 )
  {
    if ( *(_QWORD *)(a2 + 16) == 12 )
    {
      v21 = *(_QWORD *)(a1 + 40);
      *(_DWORD *)v35 = 0;
      v34 = 0;
      if ( *(_QWORD *)(v21 + 8) )
      {
        v22 = *(_QWORD *)(v21 + 40);
        LODWORD(v34) = -268439552;
        HIDWORD(v34) = v22;
        *(_DWORD *)v35 = 516;
      }
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_QWORD *)(a2 + 8);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0
        || (v25 = *(_QWORD *)(a2 + 8), (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      {
        v25 = v24 & (v24 << 8 >> 8);
      }
      if ( v25 <= 0x7FFFFFFFF4LL )
      {
        v28 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v30 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v30 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v30);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v28);
        v17 = _arch_copy_to_user(v24 & 0xFF7FFFFFFFFFFFFFLL, &v34, 12);
        v31 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v33 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v33 - 4096);
        _WriteStatusReg(TTBR1_EL1, v33);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v31);
LABEL_22:
        if ( v17 )
          result = 4294967282LL;
        else
          result = 0;
        goto LABEL_25;
      }
LABEL_16:
      result = 4294967282LL;
      goto LABEL_25;
    }
LABEL_17:
    result = 4294967274LL;
    goto LABEL_25;
  }
  if ( *(_DWORD *)a2 == 1 )
  {
    if ( *(_QWORD *)(a2 + 16) == 24 )
    {
      v2 = *(_DWORD *)(a1 + 14248);
      LODWORD(v34) = *(_DWORD *)(a1 + 16) + 1;
      HIDWORD(v34) = v2;
      v3 = _ReadStatusReg(SP_EL0);
      v4 = *(_QWORD *)(a1 + 104);
      v5 = *(_QWORD *)(a1 + 14264);
      v6 = *(_BYTE *)(v3 + 70);
      *(_QWORD *)&v35[4] = 0;
      v7 = *(_QWORD *)(v5 + 64);
      *(_QWORD *)v35 = ((unsigned int)v4 >> 1) & 1;
      v8 = *(_QWORD *)(a2 + 8);
      v36 = v7;
      if ( (v6 & 0x20) != 0 || (v9 = v8, (*(_QWORD *)v3 & 0x4000000) != 0) )
        v9 = v8 & ((__int64)(v8 << 8) >> 8);
      if ( v9 <= 0x7FFFFFFFE8LL )
      {
        v10 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v16 = *(_QWORD *)(v3 + 8);
        _WriteStatusReg(TTBR1_EL1, v16 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v16);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v10);
        v17 = _arch_copy_to_user(v8 & 0xFF7FFFFFFFFFFFFFLL, &v34, 24);
        v18 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v20 - 4096);
        _WriteStatusReg(TTBR1_EL1, v20);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v18);
        goto LABEL_22;
      }
      goto LABEL_16;
    }
    goto LABEL_17;
  }
  v27 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8752) + 40LL);
  if ( *((_DWORD *)v27 - 1) != -477936819 )
    __break(0x8228u);
  result = v27();
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
