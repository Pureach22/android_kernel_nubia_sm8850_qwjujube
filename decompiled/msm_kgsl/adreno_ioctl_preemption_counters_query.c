__int64 __fastcall adreno_ioctl_preemption_counters_query(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  unsigned int v5; // w9
  unsigned int v6; // w9
  __int64 v7; // x8
  unsigned __int64 v9; // x23
  __int64 v10; // x20
  int v11; // w21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9

  v3 = *a1;
  if ( (unsigned int)(**(_DWORD **)(*a1 + 14264) - 600) < 0xFFFFFF9C || (*(_QWORD *)(v3 + 14240) & 0x200) == 0 )
    return -95;
  v5 = *(_DWORD *)(a3 + 8);
  if ( v5 < 0x40 )
    return -22;
  v6 = v5 >> 6;
  v7 = *(_QWORD *)(v3 + 20496);
  v9 = *(_QWORD *)a3;
  v10 = *(_QWORD *)(v7 + 8);
  if ( v6 >= 4 )
    v11 = 4;
  else
    v11 = v6;
  _check_object_size(*(_QWORD *)(v7 + 8), (unsigned int)(v11 << 6), 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = v9, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v13 = v9 & ((__int64)(v9 << 8) >> 8);
  if ( 0x8000000000LL - (unsigned __int64)(unsigned int)(v11 << 6) < v13 )
    return -14;
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v20 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v20);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  result = _arch_copy_to_user(v9 & 0xFF7FFFFFFFFFFFFFLL, v10, (unsigned int)(v11 << 6));
  v21 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v23 - 4096);
  _WriteStatusReg(TTBR1_EL1, v23);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v21);
  if ( result )
    return -14;
  *(_DWORD *)(a3 + 12) = 64;
  *(_DWORD *)(a3 + 16) = v11;
  return result;
}
