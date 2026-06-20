__int64 __fastcall dp_peer_flush_frags(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3)
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
  __int64 v15; // x8
  unsigned int v16; // w9
  unsigned int v23; // w11
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  __int64 v29; // x20
  __int64 result; // x0
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  __int64 v35; // x21
  __int64 v36; // x20
  unsigned __int64 StatusReg; // x23
  __int64 v38; // x22
  __int64 v39; // x8
  unsigned int v41; // w9

  v5 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v5 )
  {
    v14 = v5;
    if ( *(_DWORD *)(v5 + 408) == 1 && (v15 = *(_QWORD *)(v5 + 416)) != 0 )
    {
      v16 = *(_DWORD *)(v15 + 40);
      while ( v16 )
      {
        _X13 = (unsigned int *)(v15 + 40);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v23 = __ldxr(_X13);
          if ( v23 != v16 )
            break;
          if ( !__stlxr(v16 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v23 == v16;
        v16 = v23;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v15 + 292);
          __asm { PRFM            #0x11, [X8] }
          do
            v41 = __ldxr(_X8);
          while ( __stxr(v41 + 1, _X8) );
          v29 = *(_QWORD *)(v5 + 416);
          result = dp_peer_unref_delete(v5, 7u, v6, v7, v8, v9, v10, v11, v12, v13);
          v14 = v29;
          if ( !v29 )
            return result;
          goto LABEL_17;
        }
      }
    }
    else
    {
LABEL_17:
      if ( *(_QWORD *)v14 )
      {
        if ( v14 == -44 )
        {
          v33 = 0;
          v31 = 0;
          v32 = 0;
          v34 = 0;
        }
        else
        {
          v31 = *(unsigned __int8 *)(v14 + 44);
          v32 = *(unsigned __int8 *)(v14 + 45);
          v33 = *(unsigned __int8 *)(v14 + 46);
          v34 = *(unsigned __int8 *)(v14 + 49);
        }
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Flushing fragments for peer %02x:%02x:%02x:**:**:%02x",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "dp_peer_flush_frags",
          v31,
          v32,
          v33,
          v34);
        v35 = *(_QWORD *)v14;
        v36 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        v38 = v35 + 248;
        do
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v38);
          }
          else
          {
            raw_spin_lock_bh(v38);
            *(_QWORD *)(v38 + 8) |= 1uLL;
          }
          dp_rx_defrag_waitlist_remove(v35, (unsigned int)v36);
          dp_rx_reorder_flush_frag(v35, (unsigned int)v36);
          v39 = *(_QWORD *)(v38 + 8);
          if ( (v39 & 1) != 0 )
          {
            *(_QWORD *)(v38 + 8) = v39 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v38);
          }
          else
          {
            raw_spin_unlock(v38);
          }
          ++v36;
          v38 += 120;
        }
        while ( v36 != 17 );
      }
    }
    return dp_peer_unref_delete(v14, 7u, v6, v7, v8, v9, v10, v11, v12, v13);
  }
  else
  {
    if ( a3 )
    {
      v24 = *(unsigned __int8 *)a3;
      v25 = *((unsigned __int8 *)a3 + 1);
      v26 = *((unsigned __int8 *)a3 + 2);
      v27 = *((unsigned __int8 *)a3 + 5);
    }
    else
    {
      v26 = 0;
      v24 = 0;
      v25 = 0;
      v27 = 0;
    }
    return qdf_trace_msg(
             0x81u,
             5u,
             "%s: fail to find peer:%02x:%02x:%02x:**:**:%02x vdev_id: %u",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "dp_peer_get_tgt_peer_hash_find",
             v24,
             v25,
             v26,
             v27,
             a2);
  }
}
