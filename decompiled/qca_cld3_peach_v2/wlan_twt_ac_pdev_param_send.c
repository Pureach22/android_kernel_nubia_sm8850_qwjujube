__int64 wlan_twt_ac_pdev_param_send()
{
  unsigned int v0; // w19
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  v0 = tgt_twt_ac_pdev_param_send();
  if ( v0 )
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: failed (status=%d)",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "wlan_twt_ac_pdev_param_send",
      v0);
  return v0;
}
