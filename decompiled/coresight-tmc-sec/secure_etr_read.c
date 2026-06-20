unsigned __int64 __fastcall secure_etr_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x22
  __int64 *v8; // x24
  __int64 v9; // x23
  unsigned __int64 v10; // x8
  bool v11; // cc
  unsigned __int64 v12; // x8
  int v13; // w9
  __int64 v14; // x24
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x9
  unsigned __int64 v23; // x8
  __int64 v24; // x0
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9

  v4 = *(_QWORD *)(a1 + 32);
  v8 = *(__int64 **)(v4 + 248);
  mutex_lock(v4 + 192);
  v9 = *a4;
  v10 = v8[2];
  v11 = *a4 + a3 > v10;
  v12 = v10 - *a4;
  v13 = v11;
  if ( __CFADD__(v9, a3) )
    v13 = 1;
  if ( v13 )
    a3 = v12;
  if ( a3 )
  {
    if ( a3 >> 31 )
    {
      __break(0x800u);
      a3 = -14;
    }
    else
    {
      v14 = *v8;
      _check_object_size(v14 + v9, a3, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v16 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v16 = a2 & ((__int64)(a2 << 8) >> 8);
      if ( 0x8000000000LL - a3 < v16 )
        goto LABEL_16;
      v17 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v17);
      v24 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v14 + v9, a3);
      v25 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v27 - 4096);
      _WriteStatusReg(TTBR1_EL1, v27);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v25);
      if ( v24 )
LABEL_16:
        a3 = -14;
      else
        *a4 += a3;
    }
  }
  mutex_unlock(v4 + 192);
  return a3;
}
