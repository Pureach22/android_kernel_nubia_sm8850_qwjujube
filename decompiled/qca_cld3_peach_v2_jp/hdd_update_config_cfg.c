bool hdd_update_config_cfg()
{
  int updated; // w19
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  updated = hdd_update_he_cap_in_cfg();
  if ( updated )
    qdf_trace_msg(0x33u, 2u, "%s: Couldn't set HE CAP in cfg", v1, v2, v3, v4, v5, v6, v7, v8, "hdd_update_config_cfg");
  return updated == 0;
}
