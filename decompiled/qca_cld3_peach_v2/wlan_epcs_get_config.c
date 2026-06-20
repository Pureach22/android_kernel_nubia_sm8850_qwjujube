__int64 __fastcall wlan_epcs_get_config(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  char epcs_capability; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x4

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 216);
    if ( v1 )
      v2 = *(_QWORD *)(v1 + 80);
    else
      v2 = 0;
    epcs_capability = wlan_mlme_get_epcs_capability(v2);
    if ( (epcs_capability & 1) != 0 )
      v12 = "Enabled";
    else
      v12 = "Disabled";
    qdf_trace_msg(0x68u, 8u, "%s: EPCS %s", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_epcs_get_config", v12);
  }
  else
  {
    epcs_capability = 0;
  }
  return epcs_capability & 1;
}
