__int64 __fastcall dp_peer_delete_wifi3(_QWORD *a1, int a2, unsigned __int8 *a3)
{
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x21
  void (__fastcall *v28)(_QWORD); // x8
  __int64 v29; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v31; // x8
  unsigned __int64 v32; // x8
  __int64 *v33; // x8
  __int64 v34; // x8

  v5 = dp_peer_find_hash_find((int)a1, (int)a3);
  if ( !v5 )
  {
    qdf_trace_msg(0x3Fu, 8u, "%s: Invalid peer\n", v6, v7, v8, v9, v10, v11, v12, v13, "dp_peer_delete_wifi3");
    return 16;
  }
  v14 = v5;
  if ( (*(_BYTE *)(v5 + 120) & 4) == 0 )
  {
    dp_peer_unref_delete(v5, 7);
    if ( a3 )
    {
      v23 = *a3;
      v24 = a3[1];
      v25 = a3[2];
      v26 = a3[5];
    }
    else
    {
      v25 = 0;
      v23 = 0;
      v24 = 0;
      v26 = 0;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Invalid peer: %02x:%02x:%02x:**:**:%02x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_peer_delete_wifi3",
      v23,
      v24,
      v25,
      v26);
    return 6;
  }
  v27 = *(_QWORD *)(v5 + 24);
  if ( !v27 )
  {
    dp_peer_unref_delete(v5, 7);
    return 16;
  }
  *(_BYTE *)(v5 + 120) &= ~4u;
  v28 = *(void (__fastcall **)(_QWORD))(a1[1] + 368LL);
  if ( v28 )
  {
    v29 = *(unsigned __int16 *)(v5 + 16);
    if ( *((_DWORD *)v28 - 1) != 1311034697 )
      __break(0x8228u);
    v28(v29);
  }
  qdf_trace_msg(
    0x7Cu,
    5u,
    "%s: %pK: peer %pK (%02x:%02x:%02x:**:**:%02x) pending-refs %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "dp_peer_delete_wifi3",
    a1,
    v14,
    *(unsigned __int8 *)(v14 + 44),
    *(unsigned __int8 *)(v14 + 45),
    *(unsigned __int8 *)(v14 + 46),
    *(unsigned __int8 *)(v14 + 49),
    *(_DWORD *)(v14 + 40));
  dp_local_peer_id_free(*(_QWORD *)(*(_QWORD *)(v14 + 24) + 24LL), v14);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v14 + 128);
    v31 = *(_QWORD *)(v14 + 136);
  }
  else
  {
    raw_spin_lock_bh(v14 + 128);
    v31 = *(_QWORD *)(v14 + 136) | 1LL;
    *(_QWORD *)(v14 + 136) = v31;
  }
  *(_DWORD *)(v14 + 124) = 1;
  if ( (v31 & 1) != 0 )
  {
    *(_QWORD *)(v14 + 136) = v31 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v14 + 128);
  }
  else
  {
    raw_spin_unlock(v14 + 128);
  }
  dp_rx_flush_rx_cached(v14, 1);
  dp_peer_multipass_list_remove(v14);
  dp_peer_find_hash_remove(a1, v14);
  dp_peer_vdev_list_remove(a1, v27, v14);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v32 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v32 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v32 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2360);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2360);
    a1[2361] |= 1uLL;
  }
  *(_QWORD *)(v14 + 240) = 0;
  v33 = (__int64 *)a1[2359];
  *(_QWORD *)(v14 + 248) = v33;
  *v33 = v14;
  v34 = a1[2361];
  a1[2359] = v14 + 240;
  if ( (v34 & 1) != 0 )
  {
    a1[2361] = v34 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2360);
  }
  else
  {
    raw_spin_unlock(a1 + 2360);
  }
  dp_peer_unref_delete(v14, 12);
  dp_peer_unref_delete(v14, 7);
  return 0;
}
