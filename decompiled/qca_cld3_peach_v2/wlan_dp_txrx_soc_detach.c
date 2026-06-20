__int64 __fastcall wlan_dp_txrx_soc_detach(__int64 **a1)
{
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x8
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x8
  void (__fastcall *v14)(_QWORD); // x8
  __int64 result; // x0

  v2 = gp_dp_ctx;
  wlan_dp_resource_mgr_detach(gp_dp_ctx);
  if ( a1 && *a1 )
  {
    v11 = **a1;
    if ( v11 )
    {
      v12 = *(void (__fastcall **)(_QWORD))(v11 + 392);
      if ( v12 )
      {
        if ( *((_DWORD *)v12 - 1) != -1106481425 )
          __break(0x8228u);
        v12(a1);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v3, v4, v5, v6, v7, v8, v9, v10, "cdp_soc_deinit");
  }
  if ( *(_QWORD *)(v2 + 1520) )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Inactive dp links still present!",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_dp_check_inactive_dp_links");
  if ( a1 && *a1 )
  {
    v13 = **a1;
    if ( v13 )
    {
      v14 = *(void (__fastcall **)(_QWORD))(v13 + 384);
      if ( v14 )
      {
        if ( *((_DWORD *)v14 - 1) != -1106481425 )
          __break(0x8228u);
        v14(a1);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v3, v4, v5, v6, v7, v8, v9, v10, "cdp_soc_detach");
  }
  result = wlan_dp_svc_deinit(v2);
  *(_QWORD *)(v2 + 240) = 0;
  return result;
}
