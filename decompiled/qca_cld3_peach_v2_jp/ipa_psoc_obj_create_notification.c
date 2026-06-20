__int64 __fastcall ipa_psoc_obj_create_notification(
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
  __int64 v10; // x0
  _QWORD *v11; // x20
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19

  qdf_trace_msg(0x61u, 8u, "%s: ipa psoc created", a2, a3, a4, a5, a6, a7, a8, a9, "ipa_psoc_obj_create_notification");
  v10 = _qdf_mem_malloc(0x2100u, "ipa_psoc_obj_create_notification", 115);
  if ( !v10 )
    return 2;
  v11 = (_QWORD *)v10;
  v12 = wlan_objmgr_psoc_component_obj_attach(a1, 0x1Au, v10, 0);
  if ( v12 )
  {
    v21 = v12;
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Failed to attach psoc ipa component",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ipa_psoc_obj_create_notification");
    _qdf_mem_free((__int64)v11);
    return v21;
  }
  else
  {
    *v11 = a1;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: ipa psoc attached",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ipa_psoc_obj_create_notification");
    return 0;
  }
}
