__int64 __fastcall dp_reset_all_intfs_connectivity_stats(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 i; // x22
  size_t v12; // x1
  __int64 v13; // x1
  __int64 v14; // x8
  __int64 result; // x0
  __int64 v16; // [xsp+0h] [xbp-10h] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 264);
  }
  else
  {
    raw_spin_lock_bh(a1 + 264);
    *(_QWORD *)(a1 + 272) |= 1uLL;
  }
  dp_get_front_intf_no_lock(a1, &v16);
  for ( i = v16; v16; i = v16 )
  {
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: Clear txrx connectivity stats",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_clear_tx_rx_connectivity_stats",
      v16,
      v17);
    qdf_mem_set((void *)(i + 2720), 0x14u, 0);
    qdf_mem_set((void *)(i + 2740), 0x10u, 0);
    qdf_mem_set((void *)(i + 2756), 0x1Cu, 0);
    qdf_mem_set((void *)(i + 2784), 0x12u, 0);
    v12 = *(unsigned int *)(i + 3340);
    *(_QWORD *)(i + 3076) = 0;
    qdf_mem_set((void *)(i + 3084), v12, 0);
    v13 = v16;
    *(_QWORD *)(i + 3340) = 0;
    *(_QWORD *)(i + 3348) = 0;
    dp_get_next_intf_no_lock(a1, v13, &v16);
  }
  v14 = *(_QWORD *)(a1 + 272);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 272) = v14 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 264);
  }
  else
  {
    result = raw_spin_unlock(a1 + 264);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
