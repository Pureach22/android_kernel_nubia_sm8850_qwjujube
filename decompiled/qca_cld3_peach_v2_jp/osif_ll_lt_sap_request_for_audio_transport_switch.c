__int64 __fastcall osif_ll_lt_sap_request_for_audio_transport_switch(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10)
{
  if ( a10 >= 2 )
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid %d req type",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "osif_convert_audio_transport_switch_req_type_from_qca_type");
  return ucfg_ll_lt_sap_request_for_audio_transport_switch();
}
