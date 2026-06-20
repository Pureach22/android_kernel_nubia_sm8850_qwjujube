__int64 __fastcall wlan_mlme_get_curr_6g_power_type(
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
  __int64 cmpt_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( cmpt_obj )
    return *(unsigned __int8 *)(cmpt_obj + 548);
  qdf_trace_msg(
    0x1Fu,
    2u,
    "%s: vdev component object is NULL",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_mlme_get_curr_6g_power_type");
  return 9;
}
