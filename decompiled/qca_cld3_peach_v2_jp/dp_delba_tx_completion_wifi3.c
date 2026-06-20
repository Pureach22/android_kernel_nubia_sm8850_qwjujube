__int64 __fastcall dp_delba_tx_completion_wifi3(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned int a4,
        int a5)
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
  __int64 v18; // x19
  unsigned __int64 StatusReg; // x8
  unsigned int v20; // w8
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char v31; // w9
  __int64 v32; // x8
  __int64 v33; // x9
  __int64 v34; // x10
  _DWORD *v35; // x8
  __int64 v36; // x0
  __int64 v37; // x4
  __int64 v38; // x1
  int v39; // w9
  int v40; // w8

  v8 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( !v8 )
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
      "dp_delba_tx_completion_wifi3",
      a1);
    return 16;
  }
  v17 = *(_QWORD *)(v8 + 88) + 144LL * (unsigned __int8)a4;
  v18 = v8;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v17 + 88);
    if ( a5 )
      goto LABEL_6;
  }
  else
  {
    raw_spin_lock_bh(v17 + 88);
    *(_QWORD *)(v17 + 96) |= 1uLL;
    if ( a5 )
    {
LABEL_6:
      v20 = *(unsigned __int8 *)(v17 + 109);
      ++*(_DWORD *)(v17 + 116);
      if ( v20 < 3 )
      {
        v31 = v20 + 1;
        v32 = *(_QWORD *)(v17 + 96);
        *(_BYTE *)(v17 + 109) = v31;
        *(_BYTE *)(v17 + 108) = 1;
        if ( (v32 & 1) != 0 )
        {
          *(_QWORD *)(v17 + 96) = v32 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v17 + 88);
        }
        else
        {
          raw_spin_unlock(v17 + 88);
        }
        v33 = *(_QWORD *)(v18 + 24);
        v34 = *(_QWORD *)(*(_QWORD *)(v33 + 24) + 8LL);
        v35 = *(_DWORD **)(*(_QWORD *)(v34 + 8) + 168LL);
        if ( v35 )
        {
          v36 = *(_QWORD *)(v34 + 16);
          v37 = *(unsigned __int8 *)(v17 + 120);
          v38 = *(unsigned __int8 *)(v33 + 59);
          if ( *(v35 - 1) != -1677196783 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _QWORD))v35)(v36, v38, v18 + 44, a4, v37, 0);
        }
        goto LABEL_22;
      }
      v21 = *(_QWORD *)(v17 + 96);
      *(_WORD *)(v17 + 108) = 0;
      if ( (v21 & 1) != 0 )
        goto LABEL_8;
LABEL_21:
      raw_spin_unlock(v17 + 88);
      goto LABEL_22;
    }
  }
  v39 = *(_DWORD *)(v17 + 112);
  v40 = *(_DWORD *)(v17 + 68);
  *(_WORD *)(v17 + 108) = 0;
  *(_DWORD *)(v17 + 112) = v39 + 1;
  if ( v40 != 1 )
  {
    if ( v40 != 2 )
      goto LABEL_20;
LABEL_25:
    dp_rx_tid_update_wifi3(v18, (unsigned __int8)a4, 1u, 0x1000u, 0);
    *(_DWORD *)(v17 + 68) = 0;
    v21 = *(_QWORD *)(v17 + 96);
    if ( (v21 & 1) == 0 )
      goto LABEL_21;
    goto LABEL_8;
  }
  dp_rx_tid_update_wifi3(v18, (unsigned __int8)a4, 1u, 0x1000u, 0);
  *(_DWORD *)(v17 + 68) = 0;
  --*(_WORD *)(v18 + 224);
  if ( *(_DWORD *)(v17 + 68) == 2 )
    goto LABEL_25;
LABEL_20:
  v21 = *(_QWORD *)(v17 + 96);
  if ( (v21 & 1) == 0 )
    goto LABEL_21;
LABEL_8:
  *(_QWORD *)(v17 + 96) = v21 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v17 + 88);
LABEL_22:
  dp_peer_unref_delete(v18, 7u, v22, v23, v24, v25, v26, v27, v28, v29);
  return 0;
}
