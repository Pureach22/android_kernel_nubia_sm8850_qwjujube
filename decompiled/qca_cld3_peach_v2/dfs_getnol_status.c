__int64 __fastcall dfs_getnol_status(__int64 a1, _BYTE *a2)
{
  unsigned __int64 StatusReg; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  int v14; // w9
  __int64 v15; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 14968);
    *a2 = 0;
    if ( a1 )
      goto LABEL_5;
LABEL_10:
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "dfs_get_radar_status");
    goto LABEL_11;
  }
  raw_spin_lock_bh(a1 + 14968);
  *(_QWORD *)(a1 + 14976) |= 1uLL;
  *a2 = 0;
  if ( !a1 )
    goto LABEL_10;
LABEL_5:
  v13 = *(_QWORD *)(a1 + 64);
  if ( v13 )
  {
    v14 = 0;
    do
    {
      *a2 = ++v14;
      v13 = *(_QWORD *)(v13 + 136);
    }
    while ( v13 );
  }
LABEL_11:
  v15 = *(_QWORD *)(a1 + 14976);
  if ( (v15 & 1) == 0 )
    return raw_spin_unlock(a1 + 14968);
  *(_QWORD *)(a1 + 14976) = v15 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 14968);
}
