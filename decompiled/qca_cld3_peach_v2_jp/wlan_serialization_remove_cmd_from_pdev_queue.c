__int64 __fastcall wlan_serialization_remove_cmd_from_pdev_queue(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x10
  __int64 v13; // x9

  if ( a1 )
  {
    v12 = 24;
    v13 = 104;
    if ( !*a3 )
      v13 = 0;
    if ( a4 )
      v12 = 0;
    return wlan_serialization_remove_cmd_from_queue(a1 + v12 + v13, a3, a2, a1, 0);
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Invalid pdev",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_serialization_remove_cmd_from_pdev_queue");
    return 16;
  }
}
