__int64 __fastcall osif_ll_lt_sap_deliver_audio_transport_switch_resp(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v13; // x2
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  int v23; // w2

  if ( a3 == 1 )
  {
    v13 = "vdev %d Transport switch request %d completed";
  }
  else
  {
    if ( a3 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: vdev %d Invalid transport switch status %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "osif_ll_lt_sap_deliver_audio_transport_switch_resp",
        *(unsigned __int8 *)(a1 + 104),
        a3);
      return 4;
    }
    v13 = "vdev %d Transport switch request %d rejected";
  }
  qdf_trace_msg(0x48u, 8u, v13, a4, a5, a6, a7, a8, a9, a10, a11, *(unsigned __int8 *)(a1 + 104), a2);
  if ( a3 == 1 )
    v22 = 1;
  else
    v22 = 3;
  if ( a3 )
    v23 = v22;
  else
    v23 = 0;
  osif_ll_lt_sap_deliver_audio_transport_switch_resp_bs_status = v23;
  if ( a2 >= 2 )
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid %d req type",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "osif_convert_audio_transport_switch_req_type_from_qca_type",
      a2);
  ucfg_ll_lt_sap_deliver_audio_transport_switch_resp();
  return 0;
}
