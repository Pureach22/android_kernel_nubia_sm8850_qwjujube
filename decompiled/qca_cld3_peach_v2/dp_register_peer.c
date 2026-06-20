__int64 __fastcall dp_register_peer(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  unsigned int v18; // w5
  unsigned int v19; // w21
  __int64 v20; // x4
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int8 *v30; // x8
  __int64 v31; // x20
  unsigned __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x9

  v5 = dp_peer_find_hash_find(a1, (unsigned __int16 *)(a3 + 2), 0, 0xFFu, 7u);
  if ( !v5 )
    return 5;
  v6 = v5;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v5 + 136);
    v8 = *(_QWORD *)(v6 + 144);
  }
  else
  {
    raw_spin_lock_bh(v5 + 136);
    v8 = *(_QWORD *)(v6 + 144) | 1LL;
    *(_QWORD *)(v6 + 144) = v8;
  }
  *(_DWORD *)(v6 + 124) = 2;
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(v6 + 144) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v6 + 136);
    v17 = *(_QWORD *)v6;
    if ( *(_QWORD *)v6 )
    {
LABEL_8:
      v18 = *(_DWORD *)(a3 + 8);
      if ( *(_DWORD *)(*(_QWORD *)v17 + 32LL) == 6 && *(_BYTE *)(*(_QWORD *)(a1 + 40) + 834LL) == 1 )
      {
        v19 = *(_DWORD *)(a3 + 8);
        dp_tx_ndp_update_bw_thresholds(v17, *(unsigned int *)(v17 + 2216), v18);
        v18 = v19;
      }
      *(_DWORD *)(v17 + 2216) = v18;
      v20 = *(unsigned __int16 *)(v17 + 8);
      v21 = 809;
      if ( v18 - 3 < 2 )
        v21 = 810;
      *(_BYTE *)(v17 + 2220) = *(_BYTE *)(*(_QWORD *)(a1 + 40) + v21);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Peer id: %u: BW: %u, mpdu retry threshold: %u",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_peer_set_bw",
        v20);
    }
  }
  else
  {
    raw_spin_unlock(v6 + 136);
    v17 = *(_QWORD *)v6;
    if ( *(_QWORD *)v6 )
      goto LABEL_8;
  }
  dp_rx_flush_rx_cached(v6, 0);
  if ( *(_DWORD *)(v6 + 408) == 1 )
  {
    v30 = *(unsigned __int8 **)(v6 + 416);
    if ( v30 )
    {
      if ( (*(_BYTE *)(v6 + 128) & 1) != 0 )
      {
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: register for mld peer%02x:%02x:%02x:**:**:%02x",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "dp_register_peer",
          v30[44],
          v30[45],
          v30[46],
          v30[49]);
        v31 = *(_QWORD *)(v6 + 416);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v32 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v32 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v32 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v31 + 136);
        }
        else
        {
          raw_spin_lock_bh(v31 + 136);
          *(_QWORD *)(v31 + 144) |= 1uLL;
        }
        *(_DWORD *)(*(_QWORD *)(v6 + 416) + 124LL) = *(_DWORD *)(v6 + 124);
        v33 = *(_QWORD *)(v6 + 416);
        v34 = *(_QWORD *)(v33 + 144);
        if ( (v34 & 1) != 0 )
        {
          *(_QWORD *)(v33 + 144) = v34 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v33 + 136);
        }
        else
        {
          raw_spin_unlock(v33 + 136);
        }
        dp_rx_flush_rx_cached(*(_QWORD *)(v6 + 416), 0);
      }
    }
  }
  dp_peer_unref_delete(v6, 7u, v22, v23, v24, v25, v26, v27, v28, v29);
  return 0;
}
