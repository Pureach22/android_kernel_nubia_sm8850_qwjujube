__int64 __fastcall hdd_set_link_reconfig_support(
        unsigned __int8 *a1,
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
  int v10; // w20
  __int64 *v12; // x22
  __int64 v13; // x23
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0

  if ( !a2 )
    return 4294967274LL;
  v10 = *(unsigned __int8 *)(a2 + 4);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Multi-link reconfiguration support: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_set_link_reconfig_support",
    *(unsigned __int8 *)(a2 + 4));
  v12 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  v13 = v12[2];
  wlan_mlme_set_link_recfg_support(*v12, v10 != 0);
  result = 0;
  if ( v10 )
  {
    if ( (*(_BYTE *)(v13 + 21785) & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: clear user disabled roaming for eht testbed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_set_link_reconfig_support");
      ucfg_clear_user_disabled_roaming(*v12, a1[8]);
      return 0;
    }
  }
  return result;
}
