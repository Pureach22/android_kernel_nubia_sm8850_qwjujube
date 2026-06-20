__int64 __fastcall target_if_green_ap_register_ll_ps_event_handler(
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
  _QWORD **v9; // x8
  _QWORD *v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2
  unsigned int v20; // w1
  const char *v21; // x2

  if ( !a1 )
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: pdev is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_green_ap_register_ll_ps_event_handler");
    return 4;
  }
  v9 = *(_QWORD ***)(a1 + 1240);
  if ( !v9 || (v10 = *v9) == nullptr )
  {
    v21 = "%s: null wmi_hdl";
LABEL_8:
    qdf_trace_msg(0x5Du, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_green_ap_register_ll_ps_event_handler");
    return 16;
  }
  if ( !wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u) )
  {
    v21 = "%s: green ap context obtained is NULL";
    goto LABEL_8;
  }
  if ( (unsigned int)wmi_unified_register_event_handler(
                       v10,
                       0x10Eu,
                       (__int64)target_if_green_ap_ll_ps_event,
                       1u,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9) )
  {
    v19 = "%s: Failed to register Enhance Green AP event";
    v20 = 2;
  }
  else
  {
    v19 = "%s: Set the Enhance Green AP event handler";
    v20 = 8;
  }
  qdf_trace_msg(
    0x5Du,
    v20,
    v19,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "target_if_green_ap_register_ll_ps_event_handler");
  return 0;
}
