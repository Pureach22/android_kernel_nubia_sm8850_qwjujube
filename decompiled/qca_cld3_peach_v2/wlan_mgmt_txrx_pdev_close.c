__int64 __fastcall wlan_mgmt_txrx_pdev_close(
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
  __int64 v9; // x8
  __int64 v11; // x24
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x20
  __int64 v23; // x25
  unsigned int v24; // w21
  __int64 v25; // x26
  void (__fastcall *v26)(__int64, __int64); // x8
  __int64 v27; // x27
  __int64 v28; // x1
  __int64 v29; // x27
  __int64 v30; // x0
  const char *v32; // x2

  if ( !a1 )
  {
    qdf_trace_msg(0x4Bu, 2u, "%s: pdev context is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mgmt_txrx_pdev_close");
    return 4;
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: psoc unavailable for pdev %pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_mgmt_txrx_pdev_close",
      a1);
    return 29;
  }
  v11 = *(_QWORD *)(v9 + 2128);
  if ( !v11 )
  {
    qdf_trace_msg(0x4Bu, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mgmt_txrx_pdev_close");
    return 29;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 1);
  if ( !comp_private_obj )
  {
    v32 = "%s: mgmt txrx context is NULL";
LABEL_22:
    qdf_trace_msg(0x4Bu, 2u, v32, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_mgmt_txrx_pdev_close");
    return 16;
  }
  v21 = *(unsigned int *)(comp_private_obj + 28);
  v22 = comp_private_obj;
  if ( !(_DWORD)v21 )
  {
    v32 = "%s: pool size is 0";
    goto LABEL_22;
  }
  v23 = 0;
  v24 = 0;
  v25 = 72 * v21;
  do
  {
    if ( *(_BYTE *)(*(_QWORD *)(v22 + 32) + v23 + 65) == 1 )
    {
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: mgmt descriptor with desc id: %d not in freelist",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_mgmt_txrx_pdev_close",
        v24);
      v26 = *(void (__fastcall **)(__int64, __int64))(v11 + 24);
      v27 = *(_QWORD *)(v22 + 32);
      if ( v26 )
      {
        v28 = *(_QWORD *)(v27 + v23 + 32);
        if ( *((_DWORD *)v26 - 1) != -461006629 )
          __break(0x8228u);
        v26(a1, v28);
      }
      v29 = v27 + v23;
      v30 = *(_QWORD *)(v29 + 32);
      if ( v30 )
        _qdf_nbuf_free(v30);
      wlan_objmgr_peer_release_ref(*(_QWORD *)(v29 + 48), 4);
      wlan_mgmt_txrx_desc_put(v22, v24);
    }
    v23 += 72;
    ++v24;
  }
  while ( v25 != v23 );
  return 0;
}
