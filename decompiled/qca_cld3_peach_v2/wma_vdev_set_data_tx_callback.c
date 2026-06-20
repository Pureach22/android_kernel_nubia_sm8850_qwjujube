__int64 __fastcall wma_vdev_set_data_tx_callback(
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
  __int64 **context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  _DWORD *v29; // x8
  __int64 v30; // x1

  context = (__int64 **)_cds_get_context(71, (__int64)"wma_vdev_set_data_tx_callback", a2, a3, a4, a5, a6, a7, a8, a9);
  v19 = _cds_get_context(54, (__int64)"wma_vdev_set_data_tx_callback", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( a1 && v19 && context )
  {
    if ( *context )
    {
      v28 = **context;
      if ( v28 )
      {
        v29 = *(_DWORD **)(v28 + 304);
        if ( v29 )
        {
          v30 = *(unsigned __int8 *)(a1 + 168);
          if ( *(v29 - 1) != 1836103893 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 **, __int64, __int64 (__fastcall *)(__int64 *, __int64, int), _QWORD *))v29)(
            context,
            v30,
            wma_data_tx_ack_comp_hdlr,
            v19);
        }
      }
    }
    else
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v20, v21, v22, v23, v24, v25, v26, v27, "cdp_data_tx_cb_set");
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: null vdev, wma_handle or soc",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wma_vdev_set_data_tx_callback");
    return 16;
  }
}
