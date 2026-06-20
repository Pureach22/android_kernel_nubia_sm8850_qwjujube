__int64 __fastcall dp_peer_update_tid_stats_from_reo(
        __int64 a1,
        int a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x22
  __int64 v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  __int64 v27; // x11
  unsigned int v28; // w8
  unsigned int v35; // w10
  unsigned int v38; // w9

  if ( a3[1] )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: REO stats failure %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "dp_peer_update_tid_stats_from_reo");
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
  if ( *(_DWORD *)(a1 + 13324) > (unsigned int)(unsigned __int16)a2 )
  {
    v16 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * (unsigned __int16)a2);
    if ( !v16 )
      goto LABEL_11;
    if ( *(unsigned __int8 *)(v16 + 388) <= 2u )
    {
      v28 = *(_DWORD *)(v16 + 40);
      while ( v28 )
      {
        _X12 = (unsigned int *)(v16 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v35 = __ldxr(_X12);
          if ( v35 != v28 )
            break;
          if ( !__stlxr(v28 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v35 == v28;
        v28 = v35;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v16 + 296);
          __asm { PRFM            #0x11, [X8] }
          do
            v38 = __ldxr(_X8);
          while ( __stxr(v38 + 1, _X8) );
          goto LABEL_11;
        }
      }
    }
  }
  v16 = 0;
LABEL_11:
  v17 = *(_QWORD *)(a1 + 13312);
  if ( (v17 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13312) = v17 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 13304);
    if ( !v16 )
      return result;
  }
  else
  {
    result = raw_spin_unlock(a1 + 13304);
    if ( !v16 )
      return result;
  }
  v26 = *(_QWORD *)(v16 + 88) + 144LL * HIWORD(a2);
  if ( v26 )
  {
    v27 = *(_QWORD *)(v26 + 128);
    *(_QWORD *)(v26 + 136) += (unsigned int)a3[24];
    *(_QWORD *)(v26 + 128) = v27 + (unsigned int)a3[23];
  }
  return dp_peer_unref_delete(v16, 8u, v18, v19, v20, v21, v22, v23, v24, v25);
}
