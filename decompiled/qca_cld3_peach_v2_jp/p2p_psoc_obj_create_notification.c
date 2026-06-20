__int64 __fastcall p2p_psoc_obj_create_notification(
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
  _QWORD *v10; // x0
  __int64 v11; // x19
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( a1 )
  {
    v10 = (_QWORD *)_qdf_mem_malloc(0x128u, "p2p_psoc_obj_create_notification", 127);
    if ( v10 )
    {
      v11 = (__int64)v10;
      *v10 = a1;
      v12 = wlan_objmgr_psoc_component_obj_attach(a1, 5u, (__int64)v10, 0);
      if ( v12 )
      {
        v21 = v12;
        _qdf_mem_free(v11);
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Failed to attach p2p component, %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "p2p_psoc_obj_create_notification",
          v21);
        return v21;
      }
      else
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: p2p soc object create successful, %pK",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "p2p_psoc_obj_create_notification",
          v11);
        return 0;
      }
    }
    else
    {
      return 2;
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
      "p2p_psoc_obj_create_notification");
    return 4;
  }
}
