__int64 __fastcall p2p_psoc_object_close(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  __int64 v19; // x1
  __int64 v20; // x1
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v18 = comp_private_obj;
      qdf_idr_destroy(comp_private_obj + 224);
      qdf_runtime_lock_deinit((__int64 *)(v18 + 176));
      qdf_event_destroy(v18 + 136, v19);
      qdf_event_destroy(v18 + 96, v20);
      if ( *(_DWORD *)(v18 + 72) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "qdf_list_destroy");
      if ( *(_DWORD *)(v18 + 48) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "qdf_list_destroy");
      if ( *(_DWORD *)(v18 + 24) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "qdf_list_destroy");
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: p2p psoc object close successful",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "p2p_psoc_object_close");
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: p2p soc object is NULL",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "p2p_psoc_object_close");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: psoc context passed is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_psoc_object_close");
    return 4;
  }
}
