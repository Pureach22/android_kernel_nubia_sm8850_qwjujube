__int64 __fastcall osif_cm_mac_to_qca_reason(unsigned int a1)
{
  if ( a1 < 0xFFEB )
    return 0;
  if ( a1 - 65519 < 0x10 )
    return dword_ACFC58[a1 - 65519];
  qdf_trace_msg(72, 8, "%s: No QCA reason code for mac reason: %u", "osif_cm_mac_to_qca_reason", a1);
  return 0;
}
