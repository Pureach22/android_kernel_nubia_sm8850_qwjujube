__int64 __fastcall dp_local_peer_id_alloc(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  v4 = a1 + 90112;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v6 = raw_spin_lock(a1 + 93552);
  }
  else
  {
    v6 = raw_spin_lock_bh(a1 + 93552);
    *(_QWORD *)(v4 + 3448) |= 1uLL;
  }
  v8 = *(unsigned __int8 *)(v4 + 3436);
  if ( (unsigned int)v8 >= 0x24 )
    goto LABEL_15;
  if ( *(unsigned __int8 *)(a1 + 93512 + v8) != (_DWORD)v8 )
  {
    *(_WORD *)(a2 + 122) = v8;
    *(_BYTE *)(v4 + 3436) = *(_BYTE *)(a1 + 93512 + v8);
    if ( (_DWORD)v8 != 35 )
    {
      *(_QWORD *)(a1 + 8 * v8 + 93568) = a2;
      goto LABEL_10;
    }
LABEL_15:
    __break(0x5512u);
    return dp_local_peer_id_free(v6, v7);
  }
  *(_WORD *)(a2 + 122) = -1;
LABEL_10:
  v9 = *(_QWORD *)(v4 + 3448);
  if ( (v9 & 1) != 0 )
  {
    *(_QWORD *)(v4 + 3448) = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 93552);
  }
  else
  {
    raw_spin_unlock(a1 + 93552);
  }
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: peer %pK, local id %d",
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           "dp_local_peer_id_alloc",
           a2,
           *(unsigned __int16 *)(a2 + 122));
}
