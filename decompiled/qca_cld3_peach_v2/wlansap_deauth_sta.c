__int64 __fastcall wlansap_deauth_sta(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  const char *v14; // x2

  if ( a1 )
  {
    context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
    if ( context )
      return sme_roam_deauth_sta(context, *(unsigned __int8 *)(a1 + 12), a2);
    v14 = "%s: Invalid MAC context";
  }
  else
  {
    v14 = "%s: Invalid SAP pointer";
  }
  qdf_trace_msg(0x39u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_deauth_sta");
  return 5;
}
