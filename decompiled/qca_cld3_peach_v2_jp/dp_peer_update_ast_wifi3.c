__int64 __fastcall dp_peer_update_ast_wifi3(__int64 a1, int a2, int a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x29
  __int64 v6; // x30
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v22; // x0
  int updated; // w0
  __int64 v24; // x8
  unsigned int v25; // w21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // [xsp+8h] [xbp-38h]

  if ( (*(_BYTE *)(a1 + 17650) & 1) != 0 )
    return 0xFFFFFFFFLL;
  v34 = v6;
  v11 = dp_peer_find_hash_find(a1, a3);
  if ( v11 )
  {
    v20 = v11;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 17576);
    }
    else
    {
      raw_spin_lock_bh(a1 + 17576);
      *(_QWORD *)(a1 + 17584) |= 1uLL;
    }
    v22 = dp_peer_ast_hash_find_by_pdevid(a1, a4, **(unsigned __int8 **)(*(_QWORD *)(v20 + 24) + 24LL));
    if ( v22 )
      updated = dp_peer_update_ast(a1, v20, v22, a5);
    else
      updated = -1;
    v24 = *(_QWORD *)(a1 + 17584);
    v25 = updated;
    if ( (v24 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 17584) = v24 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 17576);
    }
    else
    {
      raw_spin_unlock(a1 + 17576);
    }
    dp_peer_unref_delete(v20, 7u, v26, v27, v28, v29, v30, v31, v32, v33);
    return v25;
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: Peer is NULL!",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_peer_update_ast_wifi3",
      v5,
      v34);
    return 0xFFFFFFFFLL;
  }
}
