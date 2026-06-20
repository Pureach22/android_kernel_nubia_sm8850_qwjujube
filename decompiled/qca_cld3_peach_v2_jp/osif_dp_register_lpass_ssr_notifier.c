__int64 __fastcall osif_dp_register_lpass_ssr_notifier(__int64 a1)
{
  unsigned __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  dp_lpass_ssr_nb_params = a1;
  v2 = qcom_register_ssr_notifier("lpass", &off_14DB8);
  if ( v2 && v2 < 0xFFFFFFFFFFFFF001LL )
    return ucfg_dp_set_lpass_ssr_notif_hdl(a1, v2);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: LPASS SSR notifier registration failed",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "osif_dp_register_lpass_ssr_notifier");
  return 16;
}
