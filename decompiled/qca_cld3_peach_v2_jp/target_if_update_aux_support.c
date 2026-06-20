__int64 __fastcall target_if_update_aux_support(
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
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 comp_private_obj; // x0
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
  const char *v29; // x2

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3);
    if ( comp_private_obj )
    {
      *(_BYTE *)(comp_private_obj + 23987) = wmi_service_enabled(v10, 292) & 1;
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: aux_mac_support:%d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "target_if_update_aux_support");
      return 0;
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_psoc_get_scan_obj_fl",
      "target_if_update_aux_support",
      58);
    v29 = "%s: Failed to get scan object";
  }
  else
  {
    v29 = "%s: null wmi handle";
  }
  qdf_trace_msg(0x49u, 2u, v29, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_update_aux_support");
  return 16;
}
