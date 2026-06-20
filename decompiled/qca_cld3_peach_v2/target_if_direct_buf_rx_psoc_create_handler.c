__int64 __fastcall target_if_direct_buf_rx_psoc_create_handler(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x19
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w20

  qdf_trace_msg(0x5Bu, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_direct_buf_rx_psoc_create_handler");
  if ( a1 )
  {
    v18 = _qdf_mem_malloc(0x20u, "target_if_direct_buf_rx_psoc_create_handler", 827);
    if ( v18 )
    {
      v27 = v18;
      qdf_trace_msg(
        0x5Bu,
        8u,
        "%s: Dbr psoc obj %pK",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "target_if_direct_buf_rx_psoc_create_handler",
        v18);
      result = wlan_objmgr_psoc_component_obj_attach(a1, 8u, v27, 0);
      if ( (_DWORD)result )
      {
        v37 = result;
        qdf_trace_msg(
          0x5Bu,
          2u,
          "%s: Failed to attach dir buf rx component %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "target_if_direct_buf_rx_psoc_create_handler",
          (unsigned int)result);
        _qdf_mem_free(v27);
        return v37;
      }
      else
      {
        *(_DWORD *)(v27 + 24) = 1;
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
      0x5Bu,
      2u,
      "%s: psoc context passed is null",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "target_if_direct_buf_rx_psoc_create_handler");
    return 4;
  }
  return result;
}
