__int64 __fastcall tmc_read(__int64 a1, unsigned __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v7; // x24
  int v8; // w8
  __int64 v9; // x1
  __int64 v10; // x20
  __int64 sysfs_trace; // x0
  __int64 v12; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x9
  unsigned __int64 v21; // x8
  __int64 v22; // x0
  unsigned __int64 v23; // x8
  unsigned __int64 v25; // x9
  _QWORD v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 32);
  v27[0] = 0;
  mutex_lock(v7 + 128);
  v8 = *(_DWORD *)(v7 + 116);
  v9 = *a4;
  if ( v8 == 2 )
  {
LABEL_4:
    sysfs_trace = tmc_etb_get_sysfs_trace(v7 - 24, v9, a3, v27);
    goto LABEL_6;
  }
  if ( v8 != 1 )
  {
    v10 = 0;
    if ( v8 )
      goto LABEL_16;
    goto LABEL_4;
  }
  sysfs_trace = tmc_etr_get_sysfs_trace(v7 - 24, v9, a3, v27);
LABEL_6:
  v10 = sysfs_trace;
  if ( sysfs_trace < 1 )
  {
    v10 = 0;
  }
  else if ( (unsigned __int64)sysfs_trace >> 31 )
  {
    __break(0x800u);
    v10 = -14;
  }
  else
  {
    v12 = v27[0];
    _check_object_size(v27[0], sysfs_trace, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v14 = a2 & ((__int64)(a2 << 8) >> 8);
    if ( 0x8000000000LL - v10 < v14 )
      goto LABEL_13;
    v15 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v15);
    v22 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v12, v10);
    v23 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v25 - 4096);
    _WriteStatusReg(TTBR1_EL1, v25);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v23);
    if ( v22 )
LABEL_13:
      v10 = -14;
    else
      *a4 += v10;
  }
LABEL_16:
  mutex_unlock(v7 + 128);
  _ReadStatusReg(SP_EL0);
  return v10;
}
