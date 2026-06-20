__int64 __fastcall debugfs_read_cmd_scheduling_params(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  _QWORD *v4; // x22
  unsigned __int64 v5; // x23
  __int64 v6; // x24
  __int64 v7; // x8
  unsigned __int64 v8; // x20
  unsigned int v9; // w9
  unsigned __int64 v10; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v12; // x25
  unsigned int v13; // w21
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int64 v17; // x0
  _QWORD *v19; // x9
  unsigned __int64 v20; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x10

  v7 = *(_QWORD *)(a1 + 32);
  if ( a3 >= 0x1000 )
    v8 = 4096;
  else
    v8 = a3;
  if ( !v7 )
    return -19;
  if ( *a4 )
    return 0;
  v9 = *(_DWORD *)(v7 + 840);
  if ( v9 >= 3 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &debugfs_read_cmd_scheduling_params__alloc_tag;
    v10 = _kmalloc_noprof(v8, 3520);
    *(_QWORD *)(StatusReg + 80) = v12;
    if ( v10 < 0x11 )
      return -12;
  }
  else
  {
    v5 = a2;
    v4 = a4;
    v6 = *(_QWORD *)(v7 + 48LL * v9 + 168);
    v10 = _kmalloc_noprof(v8, 3520);
    if ( v10 < 0x11 )
      return -12;
  }
  v13 = scnprintf(v10, v8, "Schedule command window start: %d\n", *(_DWORD *)(v6 + 2524));
  v14 = (unsigned int)scnprintf(v10 + v13, v8 - v13, "Schedule command window width: %d\n", *(_DWORD *)(v6 + 2528))
      + v13;
  if ( v8 >= v14 )
    v8 = (unsigned int)v14;
  else
    v8 = (unsigned int)v8;
  if ( (v8 & 0x80000000) != 0 )
  {
    __break(0x800u);
  }
  else
  {
    _check_object_size(v10, v8, 1);
    v15 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v15 + 70) & 0x20) != 0 || (v16 = v5, (*(_QWORD *)v15 & 0x4000000) != 0) )
      v16 = v5 & ((__int64)(v5 << 8) >> 8);
    v17 = v8;
    _CF = 0x8000000000LL - v8 >= v16;
    v19 = v4;
    if ( _CF )
    {
      v20 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v25 = *(_QWORD *)(v15 + 8);
      _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v25);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v20);
      v17 = _arch_copy_to_user(v5 & 0xFF7FFFFFFFFFFFFFLL);
      v19 = v4;
      v26 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v28 - 4096);
      _WriteStatusReg(TTBR1_EL1, v28);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v26);
    }
    if ( !v17 )
      *v19 += v8;
  }
  kfree(v10);
  return v8;
}
