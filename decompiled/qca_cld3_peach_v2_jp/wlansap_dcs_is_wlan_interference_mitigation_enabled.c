__int64 __fastcall wlansap_dcs_is_wlan_interference_mitigation_enabled(
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
  unsigned __int64 v12; // x8
  char v13; // w8
  const char *v14; // x2

  if ( !a1 )
  {
    v14 = "%s: Invalid SAP context pointer";
LABEL_7:
    qdf_trace_msg(0x39u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "wlansap_dcs_is_wlan_interference_mitigation_enabled");
    v13 = 0;
    return v13 & 1;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v14 = "%s: Invalid MAC context";
    goto LABEL_7;
  }
  v12 = *(unsigned __int8 *)(a1 + 12);
  if ( v12 < 6 )
  {
    v13 = *((_BYTE *)context + v12 + 14915);
    return v13 & 1;
  }
  __break(0x5512u);
  __asm { LDTR            H20, [X28,#0x8E] }
  return wlansap_dcs_get_freq();
}
