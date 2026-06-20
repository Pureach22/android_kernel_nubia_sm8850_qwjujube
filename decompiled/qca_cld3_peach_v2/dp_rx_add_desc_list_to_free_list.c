__int64 __fastcall dp_rx_add_desc_list_to_free_list(__int64 a1, _QWORD *a2, __int64 **a3, __int64 a4, __int64 a5)
{
  unsigned __int64 StatusReg; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  __int64 v18; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a5 + 56);
  }
  else
  {
    raw_spin_lock_bh(a5 + 56);
    *(_QWORD *)(a5 + 64) |= 1uLL;
  }
  v17 = *(_QWORD *)(a5 + 48);
  qdf_trace_msg(
    0x45u,
    8u,
    "temp_list: %pK, *local_desc_list: %pK, *tail: %pK (*tail)->next: %pK",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    *a2,
    *a3,
    **a3);
  *(_QWORD *)(a5 + 48) = *a2;
  **a3 = v17;
  *a3 = nullptr;
  *a2 = 0;
  v18 = *(_QWORD *)(a5 + 64);
  if ( (v18 & 1) == 0 )
    return raw_spin_unlock(a5 + 56);
  *(_QWORD *)(a5 + 64) = v18 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a5 + 56);
}
