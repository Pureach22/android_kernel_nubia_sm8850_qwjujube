__int64 __fastcall osif_twt_get_capabilities(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  unsigned int capabilities_response; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  unsigned int v15; // w21

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  v3 = *(_QWORD *)(v1 + 80);
  if ( !v3 )
    return 4294967274LL;
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return 4294967201LL;
  capabilities_response = osif_twt_send_get_capabilities_response(v3, a1);
  if ( capabilities_response )
  {
    v14 = jiffies;
    if ( osif_twt_get_capabilities___last_ticks - jiffies + 125 < 0 )
    {
      v15 = capabilities_response;
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: TWT: Get capabilities failed",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "osif_twt_get_capabilities");
      capabilities_response = v15;
      osif_twt_get_capabilities___last_ticks = v14;
    }
  }
  return qdf_status_to_os_return(capabilities_response);
}
