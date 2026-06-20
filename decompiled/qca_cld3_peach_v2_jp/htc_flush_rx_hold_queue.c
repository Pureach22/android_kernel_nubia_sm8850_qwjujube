__int64 __fastcall htc_flush_rx_hold_queue(__int64 a1, _DWORD *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 *v5; // x26
  unsigned __int64 v6; // x23
  __int64 v7; // x8
  _QWORD *v8; // x9
  __int64 v9; // x8
  __int16 v10; // w8
  void (__fastcall *v11)(__int64, __int64 *); // x9
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2976);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2976);
    *(_QWORD *)(a1 + 2984) |= 1uLL;
  }
  v5 = *((__int64 **)a2 + 32);
  if ( v5 != (__int64 *)(a2 + 62) )
  {
    v6 = _ReadStatusReg(SP_EL0);
    do
    {
      v7 = *v5;
      v8 = (_QWORD *)v5[1];
      if ( v8 )
        *v8 = v7;
      if ( v7 )
        *(_QWORD *)(v7 + 8) = v5[1];
      *v5 = (__int64)v5;
      v5[1] = (__int64)v5;
      if ( !v5 )
        break;
      --a2[66];
      v9 = *(_QWORD *)(a1 + 2984);
      if ( (v9 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 2984) = v9 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2976);
      }
      else
      {
        raw_spin_unlock(a1 + 2976);
      }
      *((_DWORD *)v5 + 13) = 9;
      *((_DWORD *)v5 + 11) = 0;
      v10 = dword_B0B4;
      if ( (dword_B0B4 & 0x200) != 0 )
      {
        qdf_trace_msg(
          56,
          2,
          "%s: Flushing RX packet:%pK, length:%d, ep:%d\n",
          "htc_flush_rx_hold_queue",
          v5,
          *((_DWORD *)v5 + 10),
          *((_DWORD *)v5 + 12));
        v10 = dword_B0B4;
      }
      v11 = *((void (__fastcall **)(__int64, __int64 *))a2 + 3);
      if ( v11 )
      {
        if ( (v10 & 0x200) != 0 )
        {
          qdf_trace_msg(56, 2, "%s: HTC calling ep %d recv callback on packet %pK\n", "do_recv_completion_pkt", *a2, v5);
          v11 = *((void (__fastcall **)(__int64, __int64 *))a2 + 3);
        }
        v12 = *((_QWORD *)a2 + 1);
        if ( *((_DWORD *)v11 - 1) != 1226475842 )
          __break(0x8229u);
        v11(v12, v5);
      }
      else
      {
        if ( (v10 & 1) != 0 )
          qdf_trace_msg(
            56,
            2,
            "%s: HTC ep %d has NULL recv callback on packet %pK\n",
            "do_recv_completion_pkt",
            *a2,
            v5);
        v13 = v5[2];
        if ( v13 )
          _qdf_nbuf_free(v13);
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v6 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v6 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 2976);
      }
      else
      {
        raw_spin_lock_bh(a1 + 2976);
        *(_QWORD *)(a1 + 2984) |= 1uLL;
      }
      v5 = *((__int64 **)a2 + 32);
    }
    while ( v5 != (__int64 *)(a2 + 62) );
  }
  v14 = *(_QWORD *)(a1 + 2984);
  if ( (v14 & 1) == 0 )
    return raw_spin_unlock(a1 + 2976);
  *(_QWORD *)(a1 + 2984) = v14 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 2976);
}
