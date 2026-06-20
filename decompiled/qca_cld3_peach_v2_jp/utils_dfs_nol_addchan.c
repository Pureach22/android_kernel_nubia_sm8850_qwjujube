__int64 __fastcall utils_dfs_nol_addchan(__int64 a1, unsigned __int16 a2, int a3)
{
  __int64 dfs_obj; // x0
  __int64 v6; // x19
  unsigned __int64 StatusReg; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return 16;
  v6 = dfs_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(dfs_obj + 14968);
  }
  else
  {
    raw_spin_lock_bh(dfs_obj + 14968);
    *(_QWORD *)(v6 + 14976) |= 1uLL;
  }
  dfs_nol_addchan(v6, a2, a3, v8, v9, v10, v11, v12, v13, v14, v15);
  v16 = *(_QWORD *)(v6 + 14976);
  if ( (v16 & 1) != 0 )
  {
    *(_QWORD *)(v6 + 14976) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v6 + 14968);
  }
  else
  {
    raw_spin_unlock(v6 + 14968);
  }
  return 0;
}
