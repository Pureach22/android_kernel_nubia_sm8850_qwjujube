__int64 __fastcall dp_tx_latency_stats_update_cca(__int64 a1, unsigned __int16 a2, int a3, _DWORD *a4, int a5)
{
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
  unsigned int v24; // w10
  _DWORD *v25; // x13
  unsigned int v26; // w10
  _DWORD *v27; // x11
  __int64 v28; // x21
  unsigned int v29; // w8
  unsigned int v36; // w10
  __int64 v37; // x20
  __int64 v38; // x21
  unsigned int v40; // w9

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  v11 = a2;
  if ( *(_DWORD *)(a1 + 13276) > (unsigned int)a2 )
  {
    v12 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8LL * a2);
    if ( !v12 )
      goto LABEL_9;
    if ( *(unsigned __int8 *)(v12 + 380) <= 2u )
    {
      v29 = *(_DWORD *)(v12 + 40);
      while ( v29 )
      {
        _X12 = (unsigned int *)(v12 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v36 = __ldxr(_X12);
          if ( v36 != v29 )
            break;
          if ( !__stlxr(v29 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v36 == v29;
        v29 = v36;
        if ( _ZF )
        {
          _X8 = v12 + 308;
          goto LABEL_38;
        }
      }
    }
  }
  v12 = 0;
LABEL_9:
  while ( 1 )
  {
    v13 = *(_QWORD *)(a1 + 13264);
    if ( (v13 & 1) != 0 )
      break;
    result = raw_spin_unlock(a1 + 13256);
    if ( !v12 )
      goto LABEL_31;
LABEL_11:
    if ( !*(_DWORD *)(*(_QWORD *)(v12 + 24) + 45352LL) )
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( *(_DWORD *)(*(_QWORD *)(v12 + 24) + 45372LL) / 1000 != a3 )
    {
      v28 = jiffies;
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
        dp_tx_latency_stats_update_cca___last_ticks_3 = v28;
      }
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    _X8 = *(_QWORD *)v12;
    if ( !*(_QWORD *)v12 )
    {
      v38 = jiffies;
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
        dp_tx_latency_stats_update_cca___last_ticks_5 = v38;
      }
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    if ( !*(_BYTE *)(_X8 + 2221) )
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    v24 = *(unsigned __int8 *)(_X8 + 5280);
    if ( v24 <= 1 )
    {
      v25 = (_DWORD *)(_X8 + 5284 + 96LL * *(unsigned __int8 *)(_X8 + 5280));
      v25[18] = a5;
      v25[19] = a5 != 0;
      v25[20] = *a4;
      v25[21] = a4[1];
      v25[22] = a4[2];
      v26 = 1 - v24;
      v27 = (_DWORD *)(_X8 + 5284 + 96LL * v26);
      v25[23] = a4[3];
      *(_BYTE *)(_X8 + 5280) = v26;
      v27[1] = 0;
      *v27 = 0;
      v27[2] = 0;
      v27[3] = 0;
      v27[4] = 0;
      v27[5] = 0;
      v27[7] = 0;
      v27[6] = 0;
      v27[8] = 0;
      v27[9] = 0;
      v27[10] = 0;
      v27[11] = 0;
      v27[13] = 0;
      v27[12] = 0;
      v27[14] = 0;
      v27[15] = 0;
      v27[16] = 0;
      v27[17] = 0;
      v27[19] = 0;
      v27[18] = 0;
      v27[20] = 0;
      v27[21] = 0;
      v27[22] = 0;
      v27[23] = 0;
      return dp_peer_unref_delete(v12, 0xDu, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    __break(0x5512u);
LABEL_38:
    __asm { PRFM            #0x11, [X8] }
    do
      v40 = __ldxr((unsigned int *)_X8);
    while ( __stxr(v40 + 1, (unsigned int *)_X8) );
  }
  *(_QWORD *)(a1 + 13264) = v13 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(a1 + 13256);
  if ( v12 )
    goto LABEL_11;
LABEL_31:
  v37 = jiffies;
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
    dp_tx_latency_stats_update_cca___last_ticks = v37;
  }
  return result;
}
