__int64 __fastcall dfs_nol_timer_cleanup(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v4; // x20
  int v5; // w9
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 result; // x0
  __int16 v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = v2;
  v9 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    goto LABEL_2;
LABEL_4:
  while ( 1 )
  {
    raw_spin_lock(a1 + 14968);
    v4 = *(_QWORD *)(a1 + 64);
    if ( !v4 )
      break;
    while ( 1 )
    {
      v5 = *(_DWORD *)(a1 + 84);
      *(_QWORD *)(a1 + 64) = *(_QWORD *)(v4 + 136);
      *(_DWORD *)(a1 + 84) = v5 - 1;
      v6 = *(_QWORD *)(a1 + 14976);
      v9 = *(_DWORD *)(v4 + 24);
      if ( (v6 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 14976) = v6 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 14968);
      }
      else
      {
        raw_spin_unlock(a1 + 14968);
      }
      utils_dfs_reg_update_nol_chan_for_freq(*(_QWORD *)(a1 + 14936), &v9, 1, 0);
      hrtimer_cancel(v4 + 48);
      _qdf_mem_free(v4);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        break;
LABEL_2:
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        goto LABEL_4;
      raw_spin_lock_bh(a1 + 14968);
      *(_QWORD *)(a1 + 14976) |= 1uLL;
      v4 = *(_QWORD *)(a1 + 64);
      if ( !v4 )
        goto LABEL_11;
    }
  }
LABEL_11:
  v7 = *(_QWORD *)(a1 + 14976);
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 14976) = v7 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 14968);
  }
  else
  {
    result = raw_spin_unlock(a1 + 14968);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
