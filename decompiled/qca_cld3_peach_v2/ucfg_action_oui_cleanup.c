__int64 __fastcall ucfg_action_oui_cleanup(
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
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 comp_private_obj; // x0
  unsigned int v29; // w19
  const char *v30; // x2

  qdf_trace_msg(0x63u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_action_oui_cleanup");
  if ( a2 >= 0x1C )
  {
    qdf_trace_msg(
      0x63u,
      2u,
      "%s: Invalid action_oui id: %u",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_action_oui_cleanup",
      a2);
LABEL_9:
    v29 = 4;
    goto LABEL_10;
  }
  if ( !a1 )
  {
    v30 = "%s: psoc is NULL";
LABEL_8:
    qdf_trace_msg(0x63u, 2u, v30, v12, v13, v14, v15, v16, v17, v18, v19, "ucfg_action_oui_cleanup");
    goto LABEL_9;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !comp_private_obj )
  {
    v30 = "%s: psoc priv is NULL";
    goto LABEL_8;
  }
  v29 = wlan_action_oui_cleanup(comp_private_obj, a2);
LABEL_10:
  qdf_trace_msg(0x63u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "ucfg_action_oui_cleanup");
  return v29;
}
