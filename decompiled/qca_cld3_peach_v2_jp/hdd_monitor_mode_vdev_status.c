__int64 __fastcall hdd_monitor_mode_vdev_status(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x23
  unsigned int v13; // w24
  __int64 v14; // x21
  unsigned int v15; // w22
  __int64 v16; // x21
  unsigned int v17; // w19

  v1 = a1 + 49152;
  if ( *(_BYTE *)(a1 + 52194) != 1 )
    return 0;
  result = qdf_wait_for_event_completion(a1 + 1664, 0x2EE0u);
  if ( (_DWORD)result )
  {
    v12 = jiffies;
    if ( hdd_monitor_mode_vdev_status___last_ticks - jiffies + 125 < 0 )
    {
      v13 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: monitor mode vdev up event time out vdev id: %d",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "hdd_monitor_mode_vdev_status",
        *(unsigned __int8 *)(*(_QWORD *)(v1 + 3672) + 8LL));
      result = v13;
      hdd_monitor_mode_vdev_status___last_ticks = v12;
    }
    if ( *(_BYTE *)(a1 + 1701) == 1 )
    {
      v14 = jiffies;
      if ( hdd_monitor_mode_vdev_status___last_ticks_413 - jiffies + 125 < 0 )
      {
        v15 = result;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: monitor mode vdev up event forcefully set",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "hdd_monitor_mode_vdev_status");
        result = v15;
        hdd_monitor_mode_vdev_status___last_ticks_413 = v14;
      }
    }
    else
    {
      v16 = jiffies;
      if ( (_DWORD)result == 15 )
      {
        if ( hdd_monitor_mode_vdev_status___last_ticks_415 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: mode vdev up event timed out",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            "hdd_monitor_mode_vdev_status");
          result = 15;
          hdd_monitor_mode_vdev_status___last_ticks_415 = v16;
        }
      }
      else if ( hdd_monitor_mode_vdev_status___last_ticks_417 - jiffies + 125 < 0 )
      {
        v17 = result;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to wait for monitor vdev up(status-%d)",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "hdd_monitor_mode_vdev_status",
          (unsigned int)result);
        result = v17;
        hdd_monitor_mode_vdev_status___last_ticks_417 = v16;
      }
    }
    *(_BYTE *)(v1 + 3042) = 0;
  }
  return result;
}
