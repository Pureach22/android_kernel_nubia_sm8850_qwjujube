__int64 __fastcall osif_cm_mac_to_qca_connect_fail_reason(unsigned int a1)
{
  if ( a1 < 0xFFF8 )
    return 0;
  if ( a1 - 65528 < 7 )
    return a1 - 65527;
  qdf_trace_msg(
    72,
    8,
    "%s: QCA code not present for internal status code %d",
    "osif_cm_mac_to_qca_connect_fail_reason",
    a1);
  return 0;
}
