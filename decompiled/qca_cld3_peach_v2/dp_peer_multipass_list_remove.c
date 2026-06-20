__int64 __fastcall dp_peer_multipass_list_remove(_QWORD *a1)
{
  _QWORD *v1; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v8; // x8
  __int64 v9; // x9
  _QWORD *v10; // x8
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v1 = (_QWORD *)a1[3];
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v1 + 5414);
    v4 = v1[5412];
    if ( v4 )
      goto LABEL_5;
LABEL_8:
    v6 = v1[5415];
    if ( (v6 & 1) == 0 )
      return raw_spin_unlock(v1 + 5414);
    v1[5415] = v6 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(v1 + 5414);
  }
  raw_spin_lock_bh(v1 + 5414);
  v1[5415] |= 1uLL;
  v4 = v1[5412];
  if ( !v4 )
    goto LABEL_8;
LABEL_5:
  v5 = *a1;
  while ( v4 != v5 )
  {
    v4 = *(_QWORD *)(v4 + 152);
    if ( !v4 )
      goto LABEL_8;
  }
  v8 = *(_QWORD *)(v5 + 152);
  v9 = *(_QWORD *)(v5 + 160);
  if ( v8 )
    v10 = (_QWORD *)(v8 + 160);
  else
    v10 = v1 + 5413;
  *v10 = v9;
  **(_QWORD **)(*a1 + 160LL) = *(_QWORD *)(*a1 + 152LL);
  *(_QWORD *)(*a1 + 152LL) = 0;
  *(_QWORD *)(*a1 + 160LL) = 0;
  v11 = v1[5415];
  if ( (v11 & 1) != 0 )
  {
    v1[5415] = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v1 + 5414);
  }
  else
  {
    raw_spin_unlock(v1 + 5414);
  }
  return dp_peer_unref_delete((__int64)a1, 9u, v12, v13, v14, v15, v16, v17, v18, v19);
}
