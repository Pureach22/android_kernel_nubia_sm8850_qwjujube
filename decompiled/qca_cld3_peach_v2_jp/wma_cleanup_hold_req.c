__int64 __fastcall wma_cleanup_hold_req(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  __int64 result; // x0
  unsigned __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // [xsp+0h] [xbp-10h] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 600);
      *(_QWORD *)(a1 + 608) |= 1uLL;
      if ( *(_DWORD *)(a1 + 592) )
        goto LABEL_5;
LABEL_21:
      v17 = *(_QWORD *)(a1 + 608);
      if ( (v17 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 608) = v17 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 600);
      }
      else
      {
        raw_spin_unlock(a1 + 600);
      }
      result = qdf_trace_msg(
                 0x36u,
                 8u,
                 "%s: request queue is empty",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "wma_cleanup_hold_req",
                 v26,
                 v27);
      goto LABEL_24;
    }
  }
  raw_spin_lock(a1 + 600);
  if ( !*(_DWORD *)(a1 + 592) )
    goto LABEL_21;
LABEL_5:
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 576), &v26) )
  {
    v5 = _ReadStatusReg(SP_EL0);
    do
    {
      v6 = *(_QWORD *)(a1 + 608);
      v7 = v26;
      if ( (v6 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 608) = v6 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 600);
      }
      else
      {
        raw_spin_unlock(a1 + 600);
      }
      v8 = v7 - 168;
      qdf_mc_timer_stop(v8);
      wma_hold_req_timer(v8, v9, v10, v11, v12, v13, v14, v15, v16);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v5 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 600);
      }
      else
      {
        raw_spin_lock_bh(a1 + 600);
        *(_QWORD *)(a1 + 608) |= 1uLL;
      }
    }
    while ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 576), &v26) );
  }
  v3 = *(_QWORD *)(a1 + 608);
  if ( (v3 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 608) = v3 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 600);
  }
  else
  {
    result = raw_spin_unlock(a1 + 600);
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
