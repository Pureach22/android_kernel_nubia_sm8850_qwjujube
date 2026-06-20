__int64 __fastcall msm_pcie_debugfs_parse_input(unsigned __int64 a1, size_t a2, __int64 a3)
{
  size_t v6; // x22
  __int64 v7; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  size_t v10; // x24
  size_t v11; // x1
  __int64 result; // x0
  unsigned __int64 v13; // x9
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9
  int option; // w19
  unsigned __int64 v24; // x24
  __int64 v25; // x25
  _QWORD v26[2]; // [xsp+0h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v6 = a2 + 1;
  v7 = _kmalloc_noprof(a2 + 1, 3264);
  if ( !v7 )
  {
LABEL_21:
    result = 4294967284LL;
    goto LABEL_22;
  }
  while ( 1 )
  {
    if ( a2 >> 31 )
    {
      __break(0x800u);
LABEL_12:
      kfree(v7);
      result = 4294967282LL;
      goto LABEL_22;
    }
    _check_object_size(v7, a2, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a1, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v9 = a1 & ((__int64)(a1 << 8) >> 8);
    v10 = a2;
    if ( 0x8000000000LL - a2 < v9 )
      goto LABEL_7;
    v13 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v19 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v19);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v13);
    v10 = _arch_copy_from_user(v7, a1 & 0xFF7FFFFFFFFFFFFFLL, a2);
    v20 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v22 - 4096);
    _WriteStatusReg(TTBR1_EL1, v22);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v20);
    if ( v10 )
    {
LABEL_7:
      if ( v6 >= a2 - v10 )
        v11 = v6 - (a2 - v10);
      else
        v11 = 0;
      if ( v11 < v10 )
        goto LABEL_20;
      memset((void *)(v7 + a2 - v10), 0, v10);
      if ( v10 )
        goto LABEL_12;
    }
    if ( v6 >= a2 )
      break;
    __break(1u);
LABEL_20:
    _fortify_panic(15, v11, v10);
    v6 = a2 + 1;
    v24 = _ReadStatusReg(SP_EL0);
    v25 = *(_QWORD *)(v24 + 80);
    *(_QWORD *)(v24 + 80) = &msm_pcie_debugfs_parse_input__alloc_tag;
    v7 = _kmalloc_noprof(a2 + 1, 3264);
    *(_QWORD *)(v24 + 80) = v25;
    if ( !v7 )
      goto LABEL_21;
  }
  *(_BYTE *)(v7 + a2) = 0;
  v26[0] = v7;
  option = get_option(v26, a3);
  kfree(v7);
  if ( option == 1 )
    result = 0;
  else
    result = 4294967274LL;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
