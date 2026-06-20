__int64 __fastcall dp_delba_process_wifi3(__int64 a1, unsigned __int16 *a2, unsigned __int8 a3, int a4, char a5)
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
  __int64 v17; // x19
  __int64 v18; // x22
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
  unsigned int v29; // w20
  int v30; // w8
  __int64 v31; // x8

  v8 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( v8 )
  {
    v17 = v8;
    v18 = *(_QWORD *)(v8 + 88) + 144LL * a4;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v18 + 88);
    }
    else
    {
      raw_spin_lock_bh(v18 + 88);
      *(_QWORD *)(v18 + 96) |= 1uLL;
    }
    if ( (*(_DWORD *)(v18 + 68) | 2) == 2 )
    {
      v20 = *(_QWORD *)(v18 + 96);
      if ( (v20 & 1) != 0 )
      {
        *(_QWORD *)(v18 + 96) = v20 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v18 + 88);
      }
      else
      {
        raw_spin_unlock(v18 + 88);
      }
      v29 = 16;
    }
    else
    {
      v30 = *(_DWORD *)(v18 + 12) + 1;
      *(_BYTE *)(v18 + 120) = a5;
      *(_DWORD *)(v18 + 12) = v30;
      dp_rx_tid_update_wifi3(v17, a4, 1u, 0x1000u, 0);
      *(_DWORD *)(v18 + 68) = 0;
      --*(_WORD *)(v17 + 224);
      v31 = *(_QWORD *)(v18 + 96);
      if ( (v31 & 1) != 0 )
      {
        *(_QWORD *)(v18 + 96) = v31 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v18 + 88);
      }
      else
      {
        raw_spin_unlock(v18 + 88);
      }
      v29 = 0;
    }
    dp_peer_unref_delete(v17, 7u, v21, v22, v23, v24, v25, v26, v27, v28);
  }
  else
  {
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
      "dp_delba_process_wifi3",
      a1);
    return 16;
  }
  return v29;
}
