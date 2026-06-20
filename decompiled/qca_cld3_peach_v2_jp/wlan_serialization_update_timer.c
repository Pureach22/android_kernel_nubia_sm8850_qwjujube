__int64 __fastcall wlan_serialization_update_timer(
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
  __int64 pdev_from_cmd; // x0
  __int64 v11; // x0
  const char *v13; // x2

  if ( a1 )
  {
    pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a1);
    if ( pdev_from_cmd )
    {
      v11 = *(_QWORD *)(pdev_from_cmd + 80);
      if ( v11 )
        return wlan_serialization_find_and_update_timer(v11, a1);
      v13 = "%s: invalid psoc";
    }
    else
    {
      v13 = "%s: invalid pdev";
    }
  }
  else
  {
    v13 = "%s: NULL command";
  }
  qdf_trace_msg(0x4Cu, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_serialization_update_timer");
  return 16;
}
