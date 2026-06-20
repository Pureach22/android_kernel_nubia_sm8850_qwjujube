__int64 __fastcall target_if_green_ap_register_egap_event_handler(
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
  _QWORD *v10; // x20
  __int64 comp_private_obj; // x0
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  char v21; // w8
  const char *v22; // x2

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
      "target_if_green_ap_register_egap_event_handler");
    return 4;
  }
  v9 = *(_QWORD ***)(a1 + 1232);
  if ( !v9 || (v10 = *v9) == nullptr )
  {
    v22 = "%s: null wmi_hdl";
LABEL_8:
    qdf_trace_msg(0x5Du, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_green_ap_register_egap_event_handler");
    return 16;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !comp_private_obj )
  {
    v22 = "%s: green ap context obtained is NULL";
    goto LABEL_8;
  }
  v12 = comp_private_obj;
  if ( (unsigned int)wmi_unified_register_event_handler(
                       v10,
                       0xA9u,
                       (__int64)target_if_green_ap_egap_status_info_event,
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
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: Failed to register Enhance Green AP event",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_green_ap_register_egap_event_handler");
    v21 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x5Du,
      4u,
      "%s: Set the Enhance Green AP event handler",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_green_ap_register_egap_event_handler");
    v21 = 1;
  }
  *(_BYTE *)(v12 + 136) = v21;
  return 0;
}
