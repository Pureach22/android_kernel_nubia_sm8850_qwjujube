__int64 __fastcall dp_rx_desc_pool_init(__int64 a1, unsigned int a2, int a3, __int64 a4)
{
  __int64 v8; // x20
  unsigned __int64 StatusReg; // x8
  _QWORD *v10; // x8
  _DWORD *v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8

  *(_DWORD *)(a4 + 56) = 0;
  v8 = a4 + 56;
  *(_QWORD *)(a4 + 64) = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a4 + 56);
  }
  else
  {
    raw_spin_lock_bh(a4 + 56);
    *(_QWORD *)(a4 + 64) |= 1uLL;
  }
  v10 = *(_QWORD **)(a4 + 24);
  *(_DWORD *)a4 = a3;
  *(_QWORD *)(a4 + 48) = *v10;
  v11 = *(_DWORD **)(a1 + 1368);
  if ( *(v11 - 1) != -1908621656 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD))v11)(a1, a4, a2) )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: RX desc pool initialization failed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_rx_desc_pool_init");
  v20 = *(_QWORD *)(a4 + 64);
  if ( (v20 & 1) == 0 )
    return raw_spin_unlock(v8);
  *(_QWORD *)(a4 + 64) = v20 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v8);
}
