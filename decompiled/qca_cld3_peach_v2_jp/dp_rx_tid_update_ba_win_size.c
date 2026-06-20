__int64 __fastcall dp_rx_tid_update_ba_win_size(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int16 a5)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  unsigned __int8 *v18; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v8 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( v8 )
  {
    v17 = *(_QWORD *)(v8 + 88) + 144LL * a4;
    v18 = (unsigned __int8 *)v8;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v17 + 88);
      v20 = *(_QWORD *)(v17 + 96);
      *(_WORD *)(v17 + 72) = a5;
      if ( (v20 & 1) == 0 )
      {
LABEL_6:
        raw_spin_unlock(v17 + 88);
LABEL_7:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: peer %02x:%02x:%02x:**:**:%02x, tid %d, update BA win size to %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "dp_rx_tid_update_ba_win_size",
          v18[44],
          v18[45],
          v18[46],
          v18[49],
          a4,
          a5);
        dp_peer_unref_delete((__int64)v18, 7u, v29, v30, v31, v32, v33, v34, v35, v36);
        return 0;
      }
    }
    else
    {
      raw_spin_lock_bh(v17 + 88);
      v20 = *(_QWORD *)(v17 + 96) | 1LL;
      *(_QWORD *)(v17 + 96) = v20;
      *(_WORD *)(v17 + 72) = a5;
      if ( (v20 & 1) == 0 )
        goto LABEL_6;
    }
    *(_QWORD *)(v17 + 96) = v20 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v17 + 88);
    goto LABEL_7;
  }
  qdf_trace_msg(
    0x81u,
    8u,
    "%s: %pK: Peer is NULL!",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "dp_rx_tid_update_ba_win_size",
    a1);
  return 16;
}
