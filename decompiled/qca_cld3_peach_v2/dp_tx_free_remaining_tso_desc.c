__int64 __fastcall dp_tx_free_remaining_tso_desc(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *v12; // x24
  __int64 *v13; // x25
  __int64 v15; // x20
  _QWORD *v16; // x23
  _QWORD *v17; // x26
  int v18; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v20; // x27
  __int64 *v21; // x26
  __int16 v22; // w9
  __int64 v23; // x8
  unsigned __int64 v24; // x22
  __int64 v25; // x20
  __int64 v26; // x25
  _QWORD *v27; // x23
  __int16 v28; // w9
  __int64 v29; // x8

  v12 = *(_QWORD **)(a2 + 24);
  v13 = *(__int64 **)(a2 + 40);
  v15 = result;
  if ( (a3 & 1) != 0 )
  {
    if ( !v13 )
    {
      result = qdf_trace_msg(0x45u, 2u, "TSO number seg desc is NULL!", a5, a6, a7, a8, a9, a10, a11, a12);
      goto LABEL_22;
    }
    if ( !v12 )
      goto LABEL_9;
    v16 = *(_QWORD **)(a2 + 24);
    do
    {
      v17 = (_QWORD *)*v16;
      result = qdf_trace_msg(
                 0x45u,
                 0,
                 "%s: Unmap the tso segment",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "dp_tx_tso_unmap_segment");
      v18 = *((_DWORD *)v13 + 2);
      if ( v18 )
      {
        result = _qdf_nbuf_unmap_tso_segment(*(_QWORD *)(v15 + 24), (__int64)v16, v18 == 1);
        --*((_DWORD *)v13 + 2);
      }
      v16 = v17;
    }
    while ( v17 );
  }
  if ( v13 )
  {
LABEL_9:
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( *(unsigned __int8 *)(a2 + 4) < 6uLL )
    {
      v20 = v15 + 5328 + 72LL * *(unsigned __int8 *)(a2 + 4);
      v21 = (__int64 *)*v13;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v20 + 56);
      }
      else
      {
        raw_spin_lock_bh(v20 + 56);
        *(_QWORD *)(v20 + 64) |= 1uLL;
      }
      *v13 = *(_QWORD *)(v20 + 8);
      v22 = *(_WORD *)(v20 + 2);
      v23 = *(_QWORD *)(v20 + 64);
      *(_QWORD *)(v20 + 8) = v13;
      *(_WORD *)(v20 + 2) = v22 + 1;
      if ( (v23 & 1) != 0 )
      {
        *(_QWORD *)(v20 + 64) = v23 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v20 + 56);
        v13 = v21;
        if ( !v21 )
          goto LABEL_22;
      }
      else
      {
        result = raw_spin_unlock(v20 + 56);
        v13 = v21;
        if ( !v21 )
          goto LABEL_22;
      }
    }
    goto LABEL_36;
  }
LABEL_22:
  if ( v12 )
  {
    v24 = _ReadStatusReg(SP_EL0);
    v25 = v15 + 4896;
    while ( *(unsigned __int8 *)(a2 + 4) < 6uLL )
    {
      v26 = v25 + 72LL * *(unsigned __int8 *)(a2 + 4);
      v27 = (_QWORD *)*v12;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v24 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v24 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v26 + 56);
      }
      else
      {
        raw_spin_lock_bh(v26 + 56);
        *(_QWORD *)(v26 + 64) |= 1uLL;
      }
      *v12 = *(_QWORD *)(v26 + 8);
      v28 = *(_WORD *)(v26 + 2);
      v29 = *(_QWORD *)(v26 + 64);
      *(_QWORD *)(v26 + 8) = v12;
      *(_WORD *)(v26 + 2) = v28 + 1;
      if ( (v29 & 1) != 0 )
      {
        *(_QWORD *)(v26 + 64) = v29 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v26 + 56);
        v12 = v27;
        if ( !v27 )
          return result;
      }
      else
      {
        result = raw_spin_unlock(v26 + 56);
        v12 = v27;
        if ( !v27 )
          return result;
      }
    }
LABEL_36:
    __break(0x5512u);
    return dp_tx_send_traffic_end_indication_pkt(result, a2, a3, a4);
  }
  return result;
}
