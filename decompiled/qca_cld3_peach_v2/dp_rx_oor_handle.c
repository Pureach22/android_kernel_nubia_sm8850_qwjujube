__int64 __fastcall dp_rx_oor_handle(__int64 a1, __int64 a2, unsigned __int16 a3, __int64 a4)
{
  char special_frame_cfg; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x23
  __int64 v11; // x8
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 **v21; // x8
  __int64 *v22; // x1
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  unsigned int v32; // w8
  unsigned int v39; // w10
  unsigned int v42; // w9

  special_frame_cfg = wlan_cfg_get_special_frame_cfg(*(_QWORD *)(a1 + 40));
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
  if ( *(_DWORD *)(a1 + 13324) > (unsigned int)a3 )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * a3);
    if ( !v10 )
      goto LABEL_9;
    if ( *(unsigned __int8 *)(v10 + 388) <= 2u )
    {
      v32 = *(_DWORD *)(v10 + 40);
      while ( v32 )
      {
        _X12 = (unsigned int *)(v10 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v39 = __ldxr(_X12);
          if ( v39 != v32 )
            break;
          if ( !__stlxr(v32 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v39 == v32;
        v32 = v39;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v10 + 280);
          __asm { PRFM            #0x11, [X8] }
          do
            v42 = __ldxr(_X8);
          while ( __stxr(v42 + 1, _X8) );
          goto LABEL_9;
        }
      }
    }
  }
  v10 = 0;
LABEL_9:
  v11 = *(_QWORD *)(a1 + 13312);
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13312) = v11 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 13304);
    if ( !v10 )
    {
LABEL_20:
      v31 = jiffies;
      if ( dp_rx_oor_handle___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: peer not found",
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   "dp_rx_oor_handle");
        dp_rx_oor_handle___last_ticks = v31;
      }
      if ( !a1 )
        goto LABEL_24;
      goto LABEL_23;
    }
  }
  else
  {
    result = raw_spin_unlock(a1 + 13304);
    if ( !v10 )
      goto LABEL_20;
  }
  if ( *(_DWORD *)(v10 + 408) == 1 )
  {
    v21 = *(__int64 ***)(v10 + 416);
    if ( v21 )
    {
      v22 = *v21;
      if ( *v21 )
        goto LABEL_14;
      goto LABEL_19;
    }
  }
  v22 = *(__int64 **)v10;
  if ( !*(_QWORD *)v10 )
  {
LABEL_19:
    result = dp_peer_unref_delete(v10, 4u, v13, v14, v15, v16, v17, v18, v19, v20);
    goto LABEL_20;
  }
LABEL_14:
  if ( (dp_rx_deliver_special_frame(a1, v22, a2, special_frame_cfg, a4) & 1) != 0 )
  {
    if ( a1 )
      ++*(_DWORD *)(a1 + 14140);
    return dp_txrx_peer_unref_delete(v10, 4u, v23, v24, v25, v26, v27, v28, v29, v30);
  }
  result = dp_txrx_peer_unref_delete(v10, 4u, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( a1 )
LABEL_23:
    ++*(_DWORD *)(a1 + 14136);
LABEL_24:
  if ( a2 )
    return _qdf_nbuf_free(a2);
  return result;
}
