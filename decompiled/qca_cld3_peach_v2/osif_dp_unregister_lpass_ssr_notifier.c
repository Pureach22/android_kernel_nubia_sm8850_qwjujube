__int64 __fastcall osif_dp_unregister_lpass_ssr_notifier(__int64 a1)
{
  __int64 lpass_ssr_notif_hdl; // x0
  unsigned int v3; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  lpass_ssr_notif_hdl = ucfg_dp_get_lpass_ssr_notif_hdl(a1);
  v3 = qcom_unregister_ssr_notifier(lpass_ssr_notif_hdl, &off_156B0);
  if ( v3 )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: LPASS SSR notifier unregister failed %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "osif_dp_unregister_lpass_ssr_notifier",
      v3);
  dp_lpass_ssr_nb_params = 0;
  return ucfg_dp_set_lpass_ssr_notif_hdl(a1, 0);
}
