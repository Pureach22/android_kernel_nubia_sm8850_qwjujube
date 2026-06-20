__int64 __fastcall dp_peer_find_id_to_obj_remove(__int64 a1, unsigned __int16 a2)
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
  __int64 v13; // x0
  __int64 v14; // x9
  __int64 v15; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13304);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13304);
    *(_QWORD *)(a1 + 13312) |= 1uLL;
  }
  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * a2);
  if ( v13 )
  {
    v14 = *(_QWORD *)v13;
    *(_WORD *)(v13 + 16) = -1;
    if ( v14 )
      *(_WORD *)(v14 + 8) = -1;
    *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * a2) = 0;
    dp_peer_unref_delete(v13, 0xCu, v5, v6, v7, v8, v9, v10, v11, v12);
    v15 = *(_QWORD *)(a1 + 13312);
    if ( (v15 & 1) == 0 )
      return raw_spin_unlock(a1 + 13304);
LABEL_12:
    *(_QWORD *)(a1 + 13312) = v15 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(a1 + 13304);
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: unable to get peer during peer id obj map remove",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "dp_peer_find_id_to_obj_remove");
  v15 = *(_QWORD *)(a1 + 13312);
  if ( (v15 & 1) != 0 )
    goto LABEL_12;
  return raw_spin_unlock(a1 + 13304);
}
