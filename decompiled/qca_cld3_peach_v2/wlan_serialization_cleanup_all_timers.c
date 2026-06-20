__int64 __fastcall wlan_serialization_cleanup_all_timers(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 StatusReg; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x24
  unsigned __int64 v20; // x25
  _QWORD *v21; // x26
  __int64 v22; // x8
  __int64 v23; // x8

  if ( a1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 14976);
    }
    else
    {
      raw_spin_lock_bh(a1 + 14976);
      *(_QWORD *)(a1 + 14984) |= 1uLL;
    }
    if ( *(_BYTE *)(a1 + 14968) )
    {
      v19 = 0;
      v20 = 0;
      do
      {
        v22 = *(_QWORD *)(a1 + 14960);
        if ( *(_QWORD *)(v22 + v19) )
        {
          if ( v22 + v19 )
          {
            v21 = (_QWORD *)(v22 + v19);
            timer_delete_sync(v22 + v19 + 8);
            *v21 = 0;
          }
          else
          {
            qdf_trace_msg(
              0x4Cu,
              8u,
              "%s: Invalid ser_timer",
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              "wlan_serialization_timer_destroy");
          }
        }
        ++v20;
        v19 += 64;
      }
      while ( v20 < *(unsigned __int8 *)(a1 + 14968) );
    }
    v23 = *(_QWORD *)(a1 + 14984);
    if ( (v23 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 14984) = v23 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 14976);
    }
    else
    {
      raw_spin_unlock(a1 + 14976);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Invalid psoc_ser_obj",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_serialization_cleanup_all_timers");
    return 16;
  }
}
