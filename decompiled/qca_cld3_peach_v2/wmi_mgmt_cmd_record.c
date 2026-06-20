__int64 __fastcall wmi_mgmt_cmd_record(__int64 a1, int a2, unsigned __int8 *a3, int a4, int a5)
{
  unsigned int v7; // w8
  unsigned __int64 StatusReg; // x8
  unsigned int *v9; // x9
  unsigned int v10; // w8
  __int64 v11; // x8
  __int64 result; // x0
  _DWORD v13[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *a3;
  v13[2] = a4;
  v13[3] = a5;
  v13[0] = (v7 >> 2) & 3;
  v13[1] = v7 >> 4;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 664);
  }
  else
  {
    raw_spin_lock_bh(a1 + 664);
    *(_QWORD *)(a1 + 672) |= 1uLL;
  }
  v9 = *(unsigned int **)(a1 + 552);
  v10 = *v9;
  if ( wmi_mgmt_tx_log_max_entry <= *v9 )
  {
    *v9 = 0;
    v10 = **(_DWORD **)(a1 + 552);
  }
  *(_DWORD *)(*(_QWORD *)(a1 + 536) + 32LL * v10) = a2;
  qdf_mem_copy(
    (void *)(*(_QWORD *)(a1 + 536) + 32LL * **(unsigned int **)(a1 + 552) + 4),
    v13,
    (unsigned int)wmi_record_max_length);
  __isb(0xFu);
  *(_QWORD *)(*(_QWORD *)(a1 + 536) + 32LL * (unsigned int)(**(_DWORD **)(a1 + 552))++ + 24) = _ReadStatusReg(CNTVCT_EL0);
  v11 = *(_QWORD *)(a1 + 672);
  ++*(_DWORD *)(a1 + 544);
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 672) = v11 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 664);
  }
  else
  {
    result = raw_spin_unlock(a1 + 664);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
