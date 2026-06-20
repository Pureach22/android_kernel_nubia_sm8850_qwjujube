__int64 __fastcall dp_rx_hw_stats_cb(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x1
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  char v16; // w22
  unsigned int v22; // w9
  unsigned int v23; // w9
  int v24; // w9
  __int64 v25; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18616);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18616);
    *(_QWORD *)(a1 + 18624) |= 1uLL;
  }
  _X8 = *(_QWORD *)(a1 + 18640);
  v16 = *(_BYTE *)(_X8 + 4);
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v22 = __ldxr((unsigned int *)_X8);
    v23 = v22 - 1;
  }
  while ( __stlxr(v23, (unsigned int *)_X8) );
  __dmb(0xBu);
  if ( !v23 )
  {
    if ( (v16 & 1) == 0 )
    {
      qdf_event_set(a1 + 18576, v6);
      *(_BYTE *)(a1 + 18632) = 0;
    }
    _qdf_mem_free(*(_QWORD *)(a1 + 18640));
    *(_QWORD *)(a1 + 18640) = 0;
    if ( !*(_DWORD *)(a3 + 4) )
      goto LABEL_14;
LABEL_7:
    qdf_trace_msg(0x45u, 5u, "%s: REO stats failure %d", v7, v8, v9, v10, v11, v12, v13, v14, "dp_rx_hw_stats_cb");
    goto LABEL_16;
  }
  if ( *(_DWORD *)(a3 + 4) )
    goto LABEL_7;
LABEL_14:
  if ( (v16 & 1) == 0 )
  {
    v24 = *(_DWORD *)(a1 + 18572);
    *(_DWORD *)(a1 + 18568) += *(_DWORD *)(a3 + 88);
    *(_DWORD *)(a1 + 18572) = v24 + *(unsigned __int16 *)(a3 + 104);
  }
LABEL_16:
  v25 = *(_QWORD *)(a1 + 18624);
  if ( (v25 & 1) == 0 )
    return raw_spin_unlock(a1 + 18616);
  *(_QWORD *)(a1 + 18624) = v25 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 18616);
}
