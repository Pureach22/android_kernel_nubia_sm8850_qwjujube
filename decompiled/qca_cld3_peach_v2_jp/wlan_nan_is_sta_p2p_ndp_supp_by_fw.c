__int64 __fastcall wlan_nan_is_sta_p2p_ndp_supp_by_fw(
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
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( comp_private_obj )
      return (*(unsigned __int16 *)(comp_private_obj + 232) >> 10) & 1;
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
  }
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: psoc_nan_obj is null",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_nan_is_sta_p2p_ndp_supp_by_fw");
  return 0;
}
