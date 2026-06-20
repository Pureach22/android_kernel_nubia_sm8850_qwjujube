__int64 __fastcall wlan_hdd_sar_unsolicited_timer_start(__int64 result)
{
  __int64 v1; // x29
  __int64 v2; // x30
  __int64 v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(result + 104);
  if ( (*(_BYTE *)(v3 + 172) & 1) != 0 && *(int *)(result + 4208) <= 0 )
  {
    v12 = v2;
    _qdf_delayed_work_start(result + 4048, *(_DWORD *)(v3 + 152));
    return qdf_trace_msg(0x33u, 8u, "sar safety unsolicited work started", v4, v5, v6, v7, v8, v9, v10, v11, v1, v12);
  }
  return result;
}
