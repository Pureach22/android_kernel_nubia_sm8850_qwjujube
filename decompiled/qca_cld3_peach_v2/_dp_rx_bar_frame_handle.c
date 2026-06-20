__int64 __fastcall dp_rx_bar_frame_handle(__int64 a1, __int64 a2, unsigned int a3, unsigned __int8 a4, unsigned int a5)
{
  __int64 (*v6)(void); // x8
  unsigned __int16 v11; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x22
  __int64 v14; // x8
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  unsigned int v25; // w9
  unsigned int v32; // w11
  __int64 v33; // x25
  __int64 v34; // x27
  __int64 v35; // x23
  unsigned int v36; // w8
  unsigned int v39; // w10
  unsigned int v42; // w9
  unsigned int v45; // w9

  v6 = *(__int64 (**)(void))(a1 + 1432);
  if ( *((_DWORD *)v6 - 1) != 1020823628 )
    __break(0x8228u);
  v11 = v6();
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
  if ( *(_DWORD *)(a1 + 13324) > (unsigned int)v11 )
  {
    v13 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * v11);
    if ( !v13 )
      goto LABEL_11;
    if ( *(unsigned __int8 *)(v13 + 388) <= 2u )
    {
      v36 = *(_DWORD *)(v13 + 40);
      while ( v36 )
      {
        _X12 = (unsigned int *)(v13 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v39 = __ldxr(_X12);
          if ( v39 != v36 )
            break;
          if ( !__stlxr(v36 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v39 == v36;
        v36 = v39;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v13 + 280);
          __asm { PRFM            #0x11, [X8] }
          do
            v45 = __ldxr(_X8);
          while ( __stxr(v45 + 1, _X8) );
          goto LABEL_11;
        }
      }
    }
  }
  v13 = 0;
LABEL_11:
  v14 = *(_QWORD *)(a1 + 13312);
  if ( (v14 & 1) == 0 )
  {
    result = raw_spin_unlock(a1 + 13304);
    if ( !v13 )
      return result;
LABEL_13:
    if ( *(_DWORD *)(v13 + 408) == 1 )
    {
      v24 = *(_QWORD *)(v13 + 416);
      if ( v24 )
      {
        v25 = *(_DWORD *)(v24 + 40);
        while ( v25 )
        {
          _X13 = (unsigned int *)(v24 + 40);
          __asm { PRFM            #0x11, [X13] }
          while ( 1 )
          {
            v32 = __ldxr(_X13);
            if ( v32 != v25 )
              break;
            if ( !__stlxr(v25 + 1, _X13) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v32 == v25;
          v25 = v32;
          if ( _ZF )
          {
            _X8 = (unsigned int *)(v24 + 280);
            __asm { PRFM            #0x11, [X8] }
            do
              v42 = __ldxr(_X8);
            while ( __stxr(v42 + 1, _X8) );
            v33 = *(_QWORD *)(v13 + 416);
            result = dp_peer_unref_delete(v13, 4u, v16, v17, v18, v19, v20, v21, v22, v23);
            v13 = v33;
            if ( !v33 )
              return result;
            goto LABEL_26;
          }
        }
        return dp_peer_unref_delete(v13, 4u, v16, v17, v18, v19, v20, v21, v22, v23);
      }
    }
LABEL_26:
    v34 = jiffies;
    if ( dp_rx_bar_frame_handle___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: BAR frame:  peer_id = %d tid = %u SSN = %d error status = %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "_dp_rx_bar_frame_handle",
        *(unsigned __int16 *)(v13 + 16),
        a3,
        *(unsigned __int16 *)(a2 + 2),
        a4);
      dp_rx_bar_frame_handle___last_ticks = v34;
      if ( !a4 )
      {
LABEL_30:
        if ( a5 == 8 || a5 == 6 )
        {
          v35 = jiffies;
          if ( dp_rx_err_handle_bar___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: BAR update to H.W is skipped",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "dp_rx_err_handle_bar");
            dp_rx_err_handle_bar___last_ticks = v35;
          }
          if ( a1 )
          {
            ++*(_DWORD *)(a1 + 14180);
            ++*(_DWORD *)(a1 + 4LL * a5 + 13964);
          }
        }
        else if ( a1 )
        {
          ++*(_DWORD *)(a1 + 13704);
        }
      }
    }
    else if ( !a4 )
    {
      goto LABEL_30;
    }
    return dp_peer_unref_delete(v13, 4u, v16, v17, v18, v19, v20, v21, v22, v23);
  }
  *(_QWORD *)(a1 + 13312) = v14 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(a1 + 13304);
  if ( v13 )
    goto LABEL_13;
  return result;
}
