void *__fastcall ucfg_action_oui_get_config(__int64 a1, unsigned int a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x63u, 2u, "%s: psoc priv is NULL", v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_action_oui_get_config");
    return &unk_98C763;
  }
  if ( a2 >= 0x1C )
  {
    qdf_trace_msg(
      0x63u,
      2u,
      "%s: Invalid action_oui id: %u",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ucfg_action_oui_get_config",
      a2);
    return &unk_98C763;
  }
  return (void *)(comp_private_obj + 840LL * a2 + 9);
}
