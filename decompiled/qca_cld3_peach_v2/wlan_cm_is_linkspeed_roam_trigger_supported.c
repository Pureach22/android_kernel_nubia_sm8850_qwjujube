__int64 __fastcall wlan_cm_is_linkspeed_roam_trigger_supported(
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
  __int64 v9; // x8
  __int64 v10; // x0
  char v11; // w0

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    v11 = wmi_service_enabled(v10, 0x11Cu, a2, a3, a4, a5, a6, a7, a8, a9);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Invalid WMI handle",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cm_is_linkspeed_roam_trigger_supported");
    v11 = 0;
  }
  return v11 & 1;
}
