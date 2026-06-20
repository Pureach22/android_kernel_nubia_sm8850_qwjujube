__int64 __fastcall dp_tx_vdev_multipass_deinit(__int64 a1)
{
  _QWORD *v2; // x22
  unsigned __int64 StatusReg; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x24
  __int64 v13; // x8
  __int64 result; // x0

  v2 = (_QWORD *)(a1 + 40960);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 42488);
    v12 = v2[189];
    if ( !v12 )
      goto LABEL_6;
  }
  else
  {
    raw_spin_lock_bh(a1 + 42488);
    v2[192] |= 1uLL;
    v12 = v2[189];
    if ( !v12 )
      goto LABEL_6;
  }
  do
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Peers present in mpass list : %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_tx_vdev_multipass_deinit",
      *(unsigned __int16 *)(v12 + 8));
    v12 = *(_QWORD *)(v12 + 152);
  }
  while ( v12 );
LABEL_6:
  v13 = v2[192];
  if ( (v13 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 42488);
    result = v2[188];
    if ( !result )
      return result;
    goto LABEL_8;
  }
  v2[192] = v13 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 42488);
  result = v2[188];
  if ( result )
  {
LABEL_8:
    result = _qdf_mem_free(result);
    v2[188] = 0;
  }
  return result;
}
