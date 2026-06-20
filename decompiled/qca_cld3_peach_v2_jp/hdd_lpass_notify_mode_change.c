__int64 __fastcall hdd_lpass_notify_mode_change(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  _BYTE *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( !*(_DWORD *)(*(_QWORD *)result + 40LL) )
  {
    v11 = (_BYTE *)result;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Sending Lpass mode change notification",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_lpass_notify_mode_change",
      v9,
      v10);
    return wlan_hdd_send_status_pkg(v11, 0, 1, 0, v12, v13, v14, v15, v16, v17, v18, v19);
  }
  return result;
}
