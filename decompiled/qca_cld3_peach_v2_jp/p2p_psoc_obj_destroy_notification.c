__int64 __fastcall p2p_psoc_obj_destroy_notification(
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
  _QWORD *comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19

  if ( a1 )
  {
    comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v19 = (__int64)comp_private_obj;
      *comp_private_obj = 0;
      v20 = wlan_objmgr_psoc_component_obj_detach(a1, 5u, (__int64)comp_private_obj);
      if ( v20 )
      {
        v29 = v20;
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Failed to detach p2p component, %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "p2p_psoc_obj_destroy_notification",
          v20);
        return v29;
      }
      else
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: destroy p2p soc object, %pK",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "p2p_psoc_obj_destroy_notification",
          v19);
        _qdf_mem_free(v19);
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: p2p soc private object is NULL",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "p2p_psoc_obj_destroy_notification");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: psoc context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_psoc_obj_destroy_notification");
    return 4;
  }
}
