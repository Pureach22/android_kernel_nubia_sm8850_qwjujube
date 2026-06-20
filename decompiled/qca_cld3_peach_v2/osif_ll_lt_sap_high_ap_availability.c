__int64 __fastcall osif_ll_lt_sap_high_ap_availability(
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
  if ( a10 >= 5 )
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid operation value %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "osif_convert_high_ap_availability_oper_from_qca",
      a10);
  return ucfg_ll_lt_sap_high_ap_availability();
}
