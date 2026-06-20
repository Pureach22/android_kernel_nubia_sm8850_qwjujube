__int64 __fastcall dp_mlo_peer_find_hash_remove_be(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v4; // w8
  __int64 v5; // x22
  unsigned __int64 StatusReg; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x10
  _QWORD *v18; // x11
  _QWORD *v19; // x9
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  int v23; // w9
  __int64 v24; // x8

  if ( result )
  {
    v2 = result;
    v4 = *(unsigned __int16 *)(a2 + 46) ^ *(unsigned __int16 *)(a2 + 44) ^ *(unsigned __int16 *)(a2 + 48);
    v5 = ((v4 >> *(_DWORD *)(result + 23444)) ^ v4) & *(_DWORD *)(result + 23440);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 23424);
    }
    else
    {
      raw_spin_lock_bh(result + 23424);
      *(_QWORD *)(v2 + 23432) |= 1uLL;
    }
    v15 = *(_QWORD *)(v2 + 23448);
    v16 = *(_QWORD *)(v15 + 16 * v5);
    if ( v16 )
    {
      while ( v16 != a2 )
      {
        v16 = *(_QWORD *)(v16 + 72);
        if ( !v16 )
          goto LABEL_11;
      }
      LODWORD(v16) = 1;
    }
LABEL_11:
    v17 = *(_QWORD *)(a2 + 72);
    v18 = *(_QWORD **)(a2 + 80);
    v19 = (_QWORD *)(v15 + 16 * v5 + 8);
    if ( v17 )
      v19 = (_QWORD *)(v17 + 80);
    *v19 = v18;
    *v18 = *(_QWORD *)(a2 + 72);
    v20 = *(unsigned __int8 *)(a2 + 44);
    v21 = *(unsigned __int8 *)(a2 + 45);
    v22 = *(unsigned __int8 *)(a2 + 46);
    v23 = *(unsigned __int8 *)(a2 + 49);
    *(_QWORD *)(a2 + 72) = 0;
    *(_QWORD *)(a2 + 80) = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Peer %pK (%02x:%02x:%02x:**:**:%02x) removed. (found %u)",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_mlo_peer_find_hash_remove_be",
      a2,
      v20,
      v21,
      v22,
      v23,
      v16);
    dp_peer_unref_delete(a2, 12);
    v24 = *(_QWORD *)(v2 + 23432);
    if ( (v24 & 1) != 0 )
    {
      *(_QWORD *)(v2 + 23432) = v24 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v2 + 23424);
    }
    else
    {
      return raw_spin_unlock(v2 + 23424);
    }
  }
  return result;
}
