__int64 __fastcall sap_dnw_request_handler(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  unsigned int v13; // w20
  __int64 v18; // x8
  __int64 v19; // x0

  if ( a1 && (v12 = *(_QWORD *)(a1 + 16)) != 0 )
  {
    v13 = *(unsigned __int8 *)(v12 + 168);
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: dnw request vdev %d bw ori %d down %d, request %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sap_dnw_request_handler",
      *(unsigned __int8 *)(v12 + 168),
      a2,
      a3,
      a4);
    if ( a4 == 1 )
    {
      sap_dnw_downgrade_channel_width(a1, a3);
    }
    else if ( !a4 )
    {
      v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 216LL);
      if ( v18 )
        v19 = *(_QWORD *)(v18 + 80);
      else
        v19 = 0;
      sme_sap_update_ch_width(v19, v13, a2, 8, 0, 0);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: NULL vdev", a5, a6, a7, a8, a9, a10, a11, a12, "sap_dnw_request_handler");
    return 4;
  }
}
