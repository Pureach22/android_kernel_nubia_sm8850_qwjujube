__int64 __fastcall wlan_hdd_sar_timers_reset(__int64 result)
{
  __int64 v1; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x1
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  if ( (*(_BYTE *)(*(_QWORD *)(result + 104) + 172LL) & 1) != 0 )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 3688) )
    {
      if ( (unsigned int)qdf_mc_timer_get_current_state(result + 3856) == 21
        && !(unsigned int)qdf_mc_timer_stop(v1 + 3856) )
      {
        qdf_trace_msg(0x33u, 8u, "sar safety timer stopped", v2, v3, v4, v5, v6, v7, v8, v9);
      }
      if ( !(unsigned int)qdf_mc_timer_start(v1 + 3856, *(_DWORD *)(*(_QWORD *)(v1 + 104) + 148LL)) )
        qdf_trace_msg(0x33u, 8u, "sar safety timer started", v11, v12, v13, v14, v15, v16, v17, v18);
      qdf_event_set(v1 + 4144, v10);
      _qdf_delayed_work_stop_sync();
      return qdf_trace_msg(0x33u, 8u, "sar safety unsolicited work stopped", v19, v20, v21, v22, v23, v24, v25, v26);
    }
  }
  return result;
}
