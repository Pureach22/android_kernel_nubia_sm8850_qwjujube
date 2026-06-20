__int64 __fastcall wlansap_dcs_set_vdev_starting(
        __int64 a1,
        char a2,
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
  unsigned __int64 v13; // x9
  const char *v15; // x2

  if ( !a1 )
  {
    v15 = "%s: Invalid SAP context pointer";
LABEL_7:
    qdf_trace_msg(0x39u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_dcs_set_vdev_starting");
    return 5;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v15 = "%s: Invalid MAC context";
    goto LABEL_7;
  }
  v13 = *(unsigned __int8 *)(a1 + 12);
  if ( v13 >= 6 )
  {
    __break(0x5512u);
    return wlansap_dcs_is_wlan_interference_mitigation_enabled(context);
  }
  else
  {
    *((_BYTE *)context + v13 + 14993) = a2 & 1;
    return 0;
  }
}
