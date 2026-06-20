__int64 __fastcall wlansap_filter_vendor_unsafe_ch_freq(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD *context; // x0
  _QWORD *v17; // x19

  if ( _cds_get_context(64, (__int64)"wlansap_filter_vendor_unsafe_ch_freq", a1, a2, a3, a4, a5, a6, a7, a8) )
  {
    context = _cds_get_context(53, (__int64)"sap_get_mac_context", v8, v9, v10, v11, v12, v13, v14, v15);
    if ( context )
    {
      v17 = context;
      policy_mgr_get_sap_mode_count(context[2703], nullptr);
      policy_mgr_get_connection_count(v17[2703]);
    }
  }
  return 0;
}
