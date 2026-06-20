__int64 __fastcall wlansap_start_beacon_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  const char *v12; // x2
  _QWORD *v13; // x20

  if ( !a1 )
  {
    v12 = "%s: Invalid SAP pointer";
LABEL_7:
    qdf_trace_msg(0x39u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlansap_start_beacon_req");
    return 5;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v12 = "%s: Invalid MAC context";
    goto LABEL_7;
  }
  if ( *(_BYTE *)(a1 + 13) )
    return 0;
  v13 = context;
  wlan_pre_cac_complete_set(*(_QWORD *)(a1 + 16), 0);
  return sme_roam_start_beacon_req(
           v13,
           *(unsigned int *)(a1 + 816) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 820) << 32),
           1);
}
