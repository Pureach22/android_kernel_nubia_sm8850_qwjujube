__int64 __fastcall dcc_sram_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x23
  __int64 v5; // x10
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v9; // x10
  int v12; // w11
  int v13; // w8
  unsigned __int64 v14; // x19
  __int64 v15; // x21
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x10
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x0
  unsigned __int64 v22; // x9
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v30; // x9
  unsigned __int64 StatusReg; // x24
  __int64 v32; // x25

  v4 = *(_QWORD *)(a1 + 32);
  v5 = *a4;
  v6 = *(unsigned int *)(v4 + 80);
  v7 = v6 - *a4;
  if ( (__int64)v6 <= *a4 )
    return 0;
  _CF = __CFADD__(v5, a3);
  v9 = v5 + a3;
  v12 = _CF;
  if ( v9 > v6 )
    v13 = 1;
  else
    v13 = v12;
  if ( v13 )
    v14 = v7;
  else
    v14 = a3;
  v15 = _kmalloc_noprof(v14, 3520);
  if ( !v15 )
    return -12;
  while ( 1 )
  {
    if ( !v14 || (v16 = *(_QWORD *)(v4 + 72) + *a4, (((unsigned __int8)v14 | (unsigned __int8)v16) & 3) != 0) )
    {
      dev_err(*(_QWORD *)(v4 + 16), "Target address or size not aligned with 4 bytes\n");
      v14 = -22;
      goto LABEL_29;
    }
    if ( v14 < 4 )
      break;
    v17 = 0;
    v18 = v14;
    while ( (v17 & 0x8000000000000000LL) == 0 )
    {
      if ( v14 < v17 )
        break;
      _CF = v18 >= 4;
      v18 -= 4LL;
      if ( !_CF )
        break;
      *(_DWORD *)(v15 + v17) = *(_DWORD *)(v16 + v17);
      v17 += 4LL;
      if ( v18 <= 3 )
        goto LABEL_21;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v15 = _kmalloc_noprof(v14, 3520);
    *(_QWORD *)(StatusReg + 80) = v32;
    if ( !v15 )
      return -12;
  }
LABEL_21:
  if ( v14 >> 31 )
  {
    __break(0x800u);
  }
  else
  {
    _check_object_size(v15, v14, 1);
    v19 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v19 + 70) & 0x20) != 0 || (v20 = a2, (*(_QWORD *)v19 & 0x4000000) != 0) )
      v20 = a2 & ((__int64)(a2 << 8) >> 8);
    v21 = 1;
    if ( 0x8000000000LL - v14 >= v20 )
    {
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v27 = *(_QWORD *)(v19 + 8);
      _WriteStatusReg(TTBR1_EL1, v27 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v27);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
      v21 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v15, v14);
      v28 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v30 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v30 - 4096);
      _WriteStatusReg(TTBR1_EL1, v30);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v28);
    }
    if ( !v21 )
    {
      *a4 += v14;
      goto LABEL_29;
    }
  }
  dev_err(*(_QWORD *)(v4 + 16), "DCC: Couldn't copy all data to user\n");
  v14 = -14;
LABEL_29:
  kfree(v15);
  return v14;
}
