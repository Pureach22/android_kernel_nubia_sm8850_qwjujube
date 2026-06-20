__int64 __fastcall ipa_psoc_obj_destroy_notification(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  qdf_trace_msg(
    0x61u,
    8u,
    "%s: ipa psoc destroyed",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "ipa_psoc_obj_destroy_notification");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Au);
  if ( comp_private_obj )
  {
    v19 = comp_private_obj;
    v20 = wlan_objmgr_psoc_component_obj_detach(a1, 0x1Au, comp_private_obj);
    if ( v20 )
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Failed to detach ipa psoc object",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "ipa_psoc_obj_destroy_notification");
    _qdf_mem_free(v19);
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Failed to get ipa psoc object",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ipa_psoc_obj_destroy_notification");
    return 16;
  }
  return v20;
}
