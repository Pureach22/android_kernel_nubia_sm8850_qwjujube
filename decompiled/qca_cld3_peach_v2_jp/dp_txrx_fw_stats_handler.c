__int64 __fastcall dp_txrx_fw_stats_handler(_QWORD *a1, __int64 a2)
{
  _QWORD *v3; // x21
  int v4; // w23
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD *v14; // x20
  unsigned __int64 v15; // x8
  _QWORD *v16; // x8
  unsigned __int64 StatusReg; // x8
  int v18; // w8
  __int64 v19; // x8
  _QWORD *v20; // x0
  unsigned __int64 v21; // x8
  _QWORD *v22; // x0
  __int64 v23; // x8
  __int64 *v24; // x0
  __int64 *v25; // x9
  __int64 v26; // x8

  v3 = a1 + 2048;
  v4 = *(_DWORD *)(*(_QWORD *)(a2 + 224) + 12LL);
  v5 = _qdf_nbuf_clone(a2);
  if ( !v5 )
  {
    qdf_trace_msg(0x3Fu, 4u, "T2H message clone failed for HTT EXT STATS", v6, v7, v8, v9, v10, v11, v12, v13);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 2234);
    }
    else
    {
      raw_spin_lock_bh(a1 + 2234);
      a1[2235] |= 1uLL;
    }
    while ( 1 )
    {
      v24 = (__int64 *)a1[2242];
      if ( !v24 )
        break;
      v25 = (__int64 *)a1[2243];
      --*((_DWORD *)v3 + 392);
      if ( v24 == v25 )
      {
        v23 = 0;
        a1[2243] = 0;
      }
      else
      {
        v23 = *v24;
      }
      a1[2242] = v23;
      *v24 = 0;
      _qdf_nbuf_free((__int64)v24);
    }
    v26 = a1[2235];
    *((_DWORD *)v3 + 394) = 0;
    if ( (v26 & 1) == 0 )
    {
      v20 = a1 + 2234;
      return raw_spin_unlock(v20);
    }
    v21 = v26 & 0xFFFFFFFFFFFFFFFELL;
    v22 = a1 + 2234;
LABEL_30:
    a1[2235] = v21;
    return raw_spin_unlock_bh(v22);
  }
  v14 = (_QWORD *)v5;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v15 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v15 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2234);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2234);
    a1[2235] |= 1uLL;
  }
  *v14 = 0;
  if ( a1[2242] )
    v16 = (_QWORD *)a1[2243];
  else
    v16 = a1 + 2242;
  *v16 = v14;
  v18 = *((_DWORD *)v3 + 392);
  a1[2243] = v14;
  *((_DWORD *)v3 + 392) = v18 + 1;
  if ( (v4 & 0x800) != 0 )
  {
    ++*((_DWORD *)v3 + 394);
    queue_work_on(32, system_wq, a1 + 2236);
  }
  v19 = a1[2235];
  if ( (v19 & 1) != 0 )
  {
    v21 = v19 & 0xFFFFFFFFFFFFFFFELL;
    v22 = a1 + 2234;
    goto LABEL_30;
  }
  v20 = a1 + 2234;
  return raw_spin_unlock(v20);
}
