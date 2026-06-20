__int64 __fastcall tgt_mgmt_txrx_process_rx_frame(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 (*v15)(void); // x8
  unsigned int v16; // w20
  const char *v17; // x2
  const char *v18; // x3
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  if ( a1 )
  {
    v13 = *(_QWORD *)(a1 + 80);
    if ( v13 )
    {
      v14 = *(_QWORD *)(v13 + 2128);
      if ( v14 )
      {
        v15 = *(__int64 (**)(void))(v14 + 48);
        if ( *((_DWORD *)v15 - 1) != 1585425754 )
          __break(0x8228u);
        v16 = v15();
        if ( !a3 )
          goto LABEL_16;
LABEL_15:
        _qdf_mem_free(*(_QWORD *)(a3 + 80));
        _qdf_mem_free(*(_QWORD *)(a3 + 200));
        goto LABEL_16;
      }
      v17 = "%s: tx_ops is NULL";
    }
    else
    {
      v17 = "%s: psoc is null";
    }
    v18 = "wlan_psoc_get_mgmt_txrx_txops";
  }
  else
  {
    v17 = "%s: pdev is null";
    v18 = "wlan_pdev_get_mgmt_txrx_txops";
  }
  qdf_trace_msg(0x4Bu, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, v18);
  qdf_trace_msg(
    0x4Bu,
    2u,
    "%s: txops is null for mgmt txrx module",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "tgt_mgmt_txrx_process_rx_frame");
  if ( a2 )
    _qdf_nbuf_free(a2);
  v16 = 29;
  if ( a3 )
    goto LABEL_15;
LABEL_16:
  _qdf_mem_free(a3);
  return v16;
}
