__int64 __fastcall q6v5_write_debugfs(__int64 a1, unsigned __int64 a2, size_t a3)
{
  _QWORD *v3; // x25
  size_t v4; // x19
  unsigned __int64 v6; // x20
  _QWORD *v7; // x21
  _QWORD *v8; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v10; // x9
  size_t v11; // x24
  unsigned __int64 v12; // x9
  unsigned __int64 v14; // x9
  _QWORD *v15; // x1
  unsigned __int64 v16; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  _QWORD *v25; // x2
  size_t v26; // x10
  _QWORD **v27; // x8
  _QWORD *v28; // x0
  _QWORD *v29; // x8
  _QWORD *v30; // x21
  _QWORD *v31; // x9
  unsigned __int64 v32; // x22
  __int64 v33; // x24

  v3 = *(_QWORD **)(a1 + 32);
  v4 = a3;
  v6 = a3 + 17;
  v7 = (_QWORD *)_kmalloc_noprof(a3 + 17, 3264);
  if ( !v7 )
    return -12;
  while ( 1 )
  {
    if ( v4 >> 31 )
    {
      __break(0x800u);
LABEL_12:
      kfree(v7);
      return -14;
    }
    v8 = v7 + 2;
    _check_object_size(v7 + 2, v4, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v10 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v10 = a2 & ((__int64)(a2 << 8) >> 8);
    v11 = v4;
    if ( 0x8000000000LL - v4 < v10 )
      goto LABEL_7;
    v16 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v16);
    v11 = _arch_copy_from_user(v7 + 2, a2 & 0xFF7FFFFFFFFFFFFFLL, v4);
    v22 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v24 - 4096);
    _WriteStatusReg(TTBR1_EL1, v24);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v22);
    if ( v11 )
    {
LABEL_7:
      v12 = v4 - v11 + 16;
      _CF = v6 >= v12;
      v14 = v6 - v12;
      if ( _CF )
        v15 = (_QWORD *)v14;
      else
        v15 = nullptr;
      if ( (unsigned __int64)v15 < v11 )
        goto LABEL_35;
      memset((char *)v8 + v4 - v11, 0, v11);
      if ( v11 )
        goto LABEL_12;
    }
    v15 = (_QWORD *)v3[41];
    v25 = (_QWORD *)*v15;
    if ( *(_QWORD **)(*v15 + 8LL) != v15 || v7 == v15 || v25 == v7 )
      break;
    v25[1] = v7;
    if ( v6 >= 8 )
    {
      *v7 = v25;
      if ( (v6 & 0xFFFFFFFFFFFFFFF8LL) != 8 )
      {
        v7[1] = v15;
        *v15 = v7;
        goto LABEL_20;
      }
    }
LABEL_34:
    __break(1u);
LABEL_35:
    _fortify_panic(15, v15);
    v6 = v4 + 17;
    v32 = _ReadStatusReg(SP_EL0);
    v33 = *(_QWORD *)(v32 + 80);
    *(_QWORD *)(v32 + 80) = &q6v5_write_debugfs__alloc_tag;
    v7 = (_QWORD *)_kmalloc_noprof(v4 + 17, 3264);
    *(_QWORD *)(v32 + 80) = v33;
    if ( !v7 )
      return -12;
  }
  _list_add_valid_or_report(v7);
LABEL_20:
  if ( v6 <= v4 + 15 )
    goto LABEL_34;
  v26 = v4;
  if ( *((_BYTE *)v8 + v4 - 1) != 10 )
    goto LABEL_24;
  if ( v6 <= v4 + 15 )
    goto LABEL_34;
  v26 = v4 - 1;
  *((_BYTE *)v8 + v4 - 1) = 0;
LABEL_24:
  if ( !v26 )
  {
    dev_info(*v3, "Empty string entered, clearing always SSR list\n");
    v27 = (_QWORD **)v3[41];
    v28 = *v27;
    if ( *v27 != v27 )
    {
      do
      {
        v30 = (_QWORD *)*v28;
        v29 = (_QWORD *)v28[1];
        if ( (_QWORD *)*v29 == v28 && (_QWORD *)v30[1] == v28 )
        {
          v30[1] = v29;
          *v29 = v30;
        }
        else
        {
          _list_del_entry_valid_or_report();
          v28 = v31;
        }
        *v28 = 0xDEAD000000000100LL;
        v28[1] = 0xDEAD000000000122LL;
        kfree(v28);
        v28 = v30;
      }
      while ( v30 != (_QWORD *)v3[41] );
    }
  }
  return v4;
}
