__int64 __fastcall dfs_nol_elem_free_work_cb(__int64 a1)
{
  __int64 v2; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v4; // x20
  _QWORD *v5; // x9
  _QWORD *v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8

  v2 = a1 + 14648;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    goto LABEL_2;
LABEL_4:
  while ( 1 )
  {
    raw_spin_lock(a1 + 14968);
    v4 = *(_QWORD **)(a1 + 14640);
    if ( !v4 )
      break;
    while ( 1 )
    {
      v5 = (_QWORD *)v4[1];
      v6 = (_QWORD *)(*v4 ? *v4 + 8LL : v2);
      *v6 = v5;
      *v5 = *v4;
      *v4 = 0;
      v4[1] = 0;
      v7 = *(_QWORD *)(a1 + 14976);
      if ( (v7 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 14976) = v7 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 14968);
      }
      else
      {
        raw_spin_unlock(a1 + 14968);
      }
      hrtimer_cancel(v4 + 6);
      _qdf_mem_free((__int64)v4);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        break;
LABEL_2:
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        goto LABEL_4;
      raw_spin_lock_bh(a1 + 14968);
      *(_QWORD *)(a1 + 14976) |= 1uLL;
      v4 = *(_QWORD **)(a1 + 14640);
      if ( !v4 )
        goto LABEL_14;
    }
  }
LABEL_14:
  v8 = *(_QWORD *)(a1 + 14976);
  if ( (v8 & 1) == 0 )
    return raw_spin_unlock(a1 + 14968);
  *(_QWORD *)(a1 + 14976) = v8 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 14968);
}
