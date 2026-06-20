__int64 __fastcall dfs_getnol(__int64 a1, int *a2)
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
  int *v13; // x8
  __int64 v14; // x9
  int v15; // w11
  __int64 v16; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 14968);
  }
  else
  {
    raw_spin_lock_bh(a1 + 14968);
    *(_QWORD *)(a1 + 14976) |= 1uLL;
  }
  *a2 = 0;
  v13 = a2 + 2;
  if ( a1 )
  {
    v14 = *(_QWORD *)(a1 + 64);
    if ( v14 )
    {
      v15 = 0;
      do
      {
        LOWORD(v13[6 * v15]) = *(_DWORD *)(v14 + 24);
        HIWORD(v13[6 * *a2]) = *(_DWORD *)(v14 + 28);
        *(_QWORD *)&v13[6 * *a2 + 2] = *(_QWORD *)(v14 + 32);
        v13[6 * *a2 + 4] = *(_DWORD *)(v14 + 40);
        v15 = *a2 + 1;
        *a2 = v15;
        v14 = *(_QWORD *)(v14 + 136);
      }
      while ( v14 );
    }
  }
  else
  {
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
      "dfs_get_nol");
  }
  v16 = *(_QWORD *)(a1 + 14976);
  if ( (v16 & 1) == 0 )
    return raw_spin_unlock(a1 + 14968);
  *(_QWORD *)(a1 + 14976) = v16 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 14968);
}
