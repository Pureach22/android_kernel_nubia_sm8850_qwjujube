__int64 __fastcall dp_tx_latency_stats_update_cca(__int64 a1, unsigned __int16 a2, int a3, _DWORD *a4, int a5)
{
  __int64 v7; // x22
  unsigned __int64 StatusReg; // x8
  unsigned int v11; // w24
  __int64 v12; // x19
  __int64 v13; // x8
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int64 *v24; // x8
  unsigned __int8 peer_link_id; // w0
  unsigned int v27; // w9
  _DWORD *v28; // x12
  unsigned int v29; // w9
  _DWORD *v30; // x10
  unsigned int v31; // w8
  unsigned int v38; // w10
  __int64 v39; // x21
  __int64 v40; // x20
  __int64 v41; // x21
  unsigned int v43; // w9

  LODWORD(v7) = a3;
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
  v11 = a2;
  if ( *(_DWORD *)(a1 + 13324) > (unsigned int)a2 )
  {
    v12 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * a2);
    if ( !v12 )
      goto LABEL_9;
    if ( *(unsigned __int8 *)(v12 + 388) <= 2u )
    {
      v31 = *(_DWORD *)(v12 + 40);
      while ( v31 )
      {
        _X12 = (unsigned int *)(v12 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v38 = __ldxr(_X12);
          if ( v38 != v31 )
            break;
          if ( !__stlxr(v31 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v38 == v31;
        v31 = v38;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v12 + 316);
          goto LABEL_42;
        }
      }
    }
  }
  v12 = 0;
LABEL_9:
  while ( 1 )
  {
    v13 = *(_QWORD *)(a1 + 13312);
    if ( (v13 & 1) != 0 )
      break;
    result = raw_spin_unlock(a1 + 13304);
    if ( !v12 )
      goto LABEL_35;
LABEL_11:
    v23 = *(_DWORD *)(v12 + 408);
    if ( v23 == 2 || !*(_DWORD *)(*(_QWORD *)(v12 + 24) + 46176LL) )
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( *(_DWORD *)(*(_QWORD *)(v12 + 24) + 46196LL) / 1000 != (_DWORD)v7 )
    {
      v39 = jiffies;
      if ( dp_tx_latency_stats_update_cca___last_ticks_3 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: invalid granularity, cur %d report %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "dp_tx_latency_stats_update_cca");
        dp_tx_latency_stats_update_cca___last_ticks_3 = v39;
      }
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    if ( v23 != 1 || (v24 = *(__int64 **)(v12 + 416)) == nullptr )
      v24 = (__int64 *)v12;
    v7 = *v24;
    if ( !*v24 )
    {
      v41 = jiffies;
      if ( dp_tx_latency_stats_update_cca___last_ticks_5 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: txrx_peer NULL for MAC: %02x:%02x:%02x:**:**:%02x",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "dp_tx_latency_stats_update_cca",
          *(unsigned __int8 *)(v12 + 44),
          *(unsigned __int8 *)(v12 + 45),
          *(unsigned __int8 *)(v12 + 46),
          *(unsigned __int8 *)(v12 + 49));
        dp_tx_latency_stats_update_cca___last_ticks_5 = v41;
      }
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    peer_link_id = dp_get_peer_link_id(v12);
    if ( *(unsigned __int8 *)(v7 + 2281) <= (unsigned int)peer_link_id )
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    _X8 = (unsigned int *)(v7 + 4072LL * peer_link_id + 6160);
    v27 = *(unsigned __int8 *)_X8;
    if ( v27 <= 1 )
    {
      v28 = (_DWORD *)(v7 + 4072LL * peer_link_id + 6164 + 96LL * *(unsigned __int8 *)_X8);
      v28[18] = a5;
      v28[19] = a5 != 0;
      v28[20] = *a4;
      v28[21] = a4[1];
      v28[22] = a4[2];
      v29 = 1 - v27;
      v30 = (_DWORD *)(v7 + 4072LL * peer_link_id + 6164 + 96LL * v29);
      v28[23] = a4[3];
      *(_BYTE *)_X8 = v29;
      v30[1] = 0;
      *v30 = 0;
      v30[2] = 0;
      v30[3] = 0;
      v30[4] = 0;
      v30[5] = 0;
      v30[7] = 0;
      v30[6] = 0;
      v30[8] = 0;
      v30[9] = 0;
      v30[10] = 0;
      v30[11] = 0;
      v30[13] = 0;
      v30[12] = 0;
      v30[14] = 0;
      v30[15] = 0;
      v30[16] = 0;
      v30[17] = 0;
      v30[19] = 0;
      v30[18] = 0;
      v30[20] = 0;
      v30[21] = 0;
      v30[22] = 0;
      v30[23] = 0;
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    __break(0x5512u);
LABEL_42:
    __asm { PRFM            #0x11, [X8] }
    do
      v43 = __ldxr(_X8);
    while ( __stxr(v43 + 1, _X8) );
  }
  *(_QWORD *)(a1 + 13312) = v13 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(a1 + 13304);
  if ( v12 )
    goto LABEL_11;
LABEL_35:
  v40 = jiffies;
  if ( dp_tx_latency_stats_update_cca___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Peer not found peer id %d",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "dp_tx_latency_stats_update_cca",
               v11);
    dp_tx_latency_stats_update_cca___last_ticks = v40;
  }
  return result;
}
