__int64 __fastcall synx_table_write(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  _BYTE *v5; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x9
  unsigned __int64 v14; // x8
  size_t v15; // x2
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9
  int v19; // w8
  unsigned __int64 v20; // x10
  char v21; // w9
  int v22; // w11
  int v23; // w12
  unsigned __int64 v24; // x11
  int v25; // w12
  int v26; // w10
  int v27; // w13
  unsigned __int64 v28; // x22
  __int64 v29; // x23
  __int64 (__fastcall *v30)(_QWORD, _QWORD); // x0

  v5 = (_BYTE *)_kmalloc_cache_noprof(refcount_warn_saturate, 3520, 16);
  if ( !v5 )
    return -12;
  while ( 1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v7 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v7 = a2 & ((__int64)(a2 << 8) >> 8);
    if ( v7 > 0x7FFFFFFFF0LL )
      break;
    v8 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v14 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v14);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v8);
    v15 = _arch_copy_from_user(v5, a2 & 0xFF7FFFFFFFFFFFFFLL, 16);
    v16 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v18 - 4096);
    _WriteStatusReg(TTBR1_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v16);
    if ( v15 )
      goto LABEL_11;
    if ( *v5 == 48 && ((unsigned __int8)v5[1] | 0x20) == 0x78 )
    {
      v19 = 16;
      v20 = 2;
    }
    else
    {
      v20 = 0;
      v19 = 10;
    }
    v21 = 0;
    v22 = 0;
    do
    {
      if ( v20 > 0xF )
        goto LABEL_49;
      v23 = (unsigned __int8)v5[v20];
      if ( v23 == 10 || v23 == 45 )
        break;
      if ( (unsigned int)(v23 - 48) <= 9 )
      {
        v22 = v23 + v22 * v19 - 48;
      }
      else if ( (unsigned int)(v23 - 97) > 5 )
      {
        if ( (unsigned int)(v23 - 65) > 5 )
          v21 = 1;
        else
          v22 = v23 + v22 * v19 - 55;
      }
      else
      {
        v22 = v23 + v22 * v19 - 87;
      }
      ++v20;
    }
    while ( v20 != 8 );
    if ( (v21 & 1) == 0 )
      lower_handle_id = v22;
    v24 = (unsigned int)v20;
    v25 = (unsigned __int8)v5[(unsigned int)v20];
    if ( v25 == 10 )
    {
      v26 = lower_handle_id;
LABEL_34:
      upper_handle_id = v26;
      goto LABEL_35;
    }
    if ( v25 != 45 )
      goto LABEL_35;
    if ( (_DWORD)v20 == 15 )
    {
      v26 = 0;
      if ( (v21 & 1) != 0 )
        goto LABEL_35;
      goto LABEL_34;
    }
    v26 = 0;
    while ( v24 <= 0xE )
    {
      v27 = (unsigned __int8)v5[v24 + 1];
      if ( v27 != 10 )
      {
        if ( (unsigned int)(v27 - 48) <= 9 )
        {
          v26 = v27 + v26 * v19 - 48;
        }
        else if ( (unsigned int)(v27 - 97) > 5 )
        {
          if ( (unsigned int)(v27 - 65) > 5 )
            v21 = 1;
          else
            v26 = v27 + v26 * v19 - 55;
        }
        else
        {
          v26 = v27 + v26 * v19 - 87;
        }
        if ( ++v24 != 15 )
          continue;
      }
      if ( (v21 & 1) == 0 )
        goto LABEL_34;
      goto LABEL_35;
    }
LABEL_49:
    __break(1u);
LABEL_50:
    _fortify_panic(15);
    v28 = _ReadStatusReg(SP_EL0);
    v29 = *(_QWORD *)(v28 + 80);
    v30 = refcount_warn_saturate;
    *(_QWORD *)(v28 + 80) = &synx_table_write__alloc_tag;
    v5 = (_BYTE *)_kmalloc_cache_noprof(v30, 3520, 16);
    *(_QWORD *)(v28 + 80) = v29;
    if ( !v5 )
      return -12;
  }
  v15 = 16;
LABEL_11:
  if ( v15 >= 0x11 )
    goto LABEL_50;
  memset(&v5[-v15 + 16], 0, v15);
  a3 = -14;
LABEL_35:
  kfree(v5);
  return a3;
}
