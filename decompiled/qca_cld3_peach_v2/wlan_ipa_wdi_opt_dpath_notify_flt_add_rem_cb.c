__int64 __fastcall wlan_ipa_wdi_opt_dpath_notify_flt_add_rem_cb(
        int a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w4
  __int64 v11; // x19
  __int64 v13; // x1

  v10 = 49;
  v11 = gp_ipa;
  if ( a1 || *(_BYTE *)(gp_ipa + 7580) != 1 )
  {
    if ( *(_BYTE *)(gp_ipa + 7684) == 1 && a2 == 0 )
      v10 = 49;
    else
      v10 = 0;
  }
  *(_DWORD *)(gp_ipa + 7524) = v10;
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp: ipa_flt_event_response set status: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_ipa_wdi_opt_dpath_notify_flt_add_rem_cb");
  return qdf_event_set(v11 + 8072, v13);
}
