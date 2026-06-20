__int64 __fastcall wlan_serialization_add_cmd_to_pdev_queue(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x9
  __int64 v12; // x8

  if ( a1 )
  {
    v11 = 24;
    v12 = 104;
    if ( !*(_DWORD *)(a2 + 32) )
      v12 = 0;
    if ( a3 )
      v11 = 0;
    return wlan_serialization_add_cmd_to_queue(a1 + v11 + v12);
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid serialization pdev",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_serialization_add_cmd_to_pdev_queue");
    return 6;
  }
}
