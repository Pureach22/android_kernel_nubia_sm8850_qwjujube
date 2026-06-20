__int64 __fastcall ucfg_action_oui_send_by_id(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  const char *v30; // x2

  qdf_trace_msg(0x63u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_action_oui_send_by_id");
  if ( !a1 )
  {
    v30 = "%s: psoc is NULL";
LABEL_7:
    qdf_trace_msg(0x63u, 2u, v30, v12, v13, v14, v15, v16, v17, v18, v19, "ucfg_action_oui_send_by_id");
    v29 = 4;
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !comp_private_obj )
  {
    v30 = "%s: psoc priv is NULL";
    goto LABEL_7;
  }
  if ( a2 < 0x13 )
  {
    v29 = action_oui_send(comp_private_obj, a2, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( v29 )
      qdf_trace_msg(
        0x63u,
        8u,
        "%s: Failed to send: %u",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "ucfg_action_oui_send_by_id",
        a2);
  }
  else
  {
    qdf_trace_msg(
      0x63u,
      2u,
      "%s: id %d not for firmware",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_action_oui_send_by_id",
      a2);
    v29 = 0;
  }
LABEL_8:
  qdf_trace_msg(0x63u, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "ucfg_action_oui_send_by_id");
  return v29;
}
