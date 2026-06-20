__int64 __fastcall target_if_direct_buf_rx_pdev_destroy_handler(
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
  _BYTE *comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x22
  __int64 v20; // x19
  __int64 v21; // x21
  __int64 v22; // x23
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  if ( a1 )
  {
    comp_private_obj = (_BYTE *)wlan_objmgr_pdev_get_comp_private_obj(a1, 8u);
    if ( comp_private_obj )
    {
      v19 = (unsigned __int8)*comp_private_obj;
      v20 = (__int64)comp_private_obj;
      if ( *comp_private_obj )
      {
        v21 = 0;
        v22 = 49;
        do
        {
          if ( *(_BYTE *)(*(_QWORD *)(v20 + 8) + v22) == 1 )
          {
            target_if_deinit_dbr_ring(a1, v20, (unsigned int)v21, 0);
            target_if_deinit_dbr_ring(a1, v20, (unsigned int)v21, 1);
          }
          ++v21;
          v22 += 112;
        }
        while ( v19 != v21 );
      }
      _qdf_mem_free(*(_QWORD *)(v20 + 8));
      *(_QWORD *)(v20 + 8) = 0;
      v23 = wlan_objmgr_pdev_component_obj_detach(a1, 8u, v20);
      if ( v23 )
        qdf_trace_msg(
          0x5Bu,
          2u,
          "%s: failed to detach dir buf rx component %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "target_if_direct_buf_rx_pdev_destroy_handler",
          v23);
      _qdf_mem_free(v20);
    }
    else
    {
      qdf_trace_msg(
        0x5Bu,
        2u,
        "%s: dir buf rx object is null",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "target_if_direct_buf_rx_pdev_destroy_handler");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: pdev context passed is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_direct_buf_rx_pdev_destroy_handler");
    return 4;
  }
  return v23;
}
