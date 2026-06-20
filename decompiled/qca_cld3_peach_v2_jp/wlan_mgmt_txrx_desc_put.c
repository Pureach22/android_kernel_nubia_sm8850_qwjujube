__int64 __fastcall wlan_mgmt_txrx_desc_put(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  unsigned __int64 StatusReg; // x8
  int v6; // w20
  int v7; // w21
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v3 = *(_QWORD *)(a1 + 32) + 72LL * a2;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 40);
    if ( (*(_BYTE *)(v3 + 65) & 1) != 0 )
      goto LABEL_5;
LABEL_11:
    v10 = *(_QWORD *)(a1 + 48);
    if ( (v10 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 48) = v10 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 40);
    }
    else
    {
      raw_spin_unlock(a1 + 40);
    }
    return qdf_trace_msg(
             0x4Bu,
             2u,
             "%s: desc %d is freed",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "wlan_mgmt_txrx_desc_put",
             a2);
  }
  raw_spin_lock_bh(a1 + 40);
  *(_QWORD *)(a1 + 48) |= 1uLL;
  if ( (*(_BYTE *)(v3 + 65) & 1) == 0 )
    goto LABEL_11;
LABEL_5:
  *(_QWORD *)(v3 + 16) = 0;
  *(_QWORD *)(v3 + 24) = 0;
  *(_QWORD *)(v3 + 32) = 0;
  *(_QWORD *)(v3 + 48) = 0;
  *(_QWORD *)(v3 + 56) = 0;
  *(_WORD *)(v3 + 64) = 255;
  qdf_list_insert_front((_QWORD *)(a1 + 8), (_QWORD *)v3);
  v6 = *(_DWORD *)(a1 + 24);
  v7 = *(_DWORD *)(a1 + 28);
  v8 = *(_QWORD *)(a1 + 48);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 48) = v8 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 40);
    if ( v6 == v7 )
      goto LABEL_7;
  }
  else
  {
    result = raw_spin_unlock(a1 + 40);
    if ( v6 == v7 )
    {
LABEL_7:
      qdf_runtime_pm_allow_suspend((__int64 *)(a1 + 264));
      return qdf_wake_lock_release(a1 + 64, 0);
    }
  }
  return result;
}
