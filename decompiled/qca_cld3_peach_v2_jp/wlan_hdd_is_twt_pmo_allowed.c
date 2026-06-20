__int64 __fastcall wlan_hdd_is_twt_pmo_allowed(__int64 *a1)
{
  char pmo_allowed; // w19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  pmo_allowed = ucfg_twt_get_pmo_allowed(*a1);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: twt_disabled_allowed %d ",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "wlan_hdd_is_twt_pmo_allowed",
    pmo_allowed & 1);
  return pmo_allowed & 1;
}
