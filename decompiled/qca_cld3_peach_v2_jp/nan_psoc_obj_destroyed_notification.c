__int64 __fastcall nan_psoc_obj_destroyed_notification(
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
  __int64 comp_private_obj; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: nan_psoc_delete_notif called",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "nan_psoc_obj_destroyed_notification");
    goto LABEL_7;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: nan_psoc_delete_notif called",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "nan_psoc_obj_destroyed_notification");
  if ( !comp_private_obj )
  {
LABEL_7:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan_obj is NULL",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "nan_psoc_obj_destroyed_notification");
    return 5;
  }
  v27 = wlan_objmgr_psoc_component_obj_detach(a1, 0xFu, comp_private_obj);
  if ( v27 )
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan_obj detach failed",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "nan_psoc_obj_destroyed_notification");
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: nan_obj deleted with status %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "nan_psoc_obj_destroyed_notification",
    v27);
  _qdf_mem_free(comp_private_obj);
  return v27;
}
