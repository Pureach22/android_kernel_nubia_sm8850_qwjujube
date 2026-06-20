__int64 __fastcall target_if_rx_reorder_queue_setup(
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
  __int64 v9; // x19
  __int64 pdev_by_id; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 pdev_wmi_handle; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int *v29; // x8
  unsigned int v30; // w21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)(a1 + 8);
  if ( v9 )
  {
    pdev_by_id = wlan_objmgr_get_pdev_by_id(*(_QWORD *)v9, *(_BYTE *)(v9 + 9), 0x2Du);
    if ( pdev_by_id )
    {
      v19 = pdev_by_id;
      pdev_wmi_handle = lmac_get_pdev_wmi_handle(pdev_by_id, v11, v12, v13, v14, v15, v16, v17, v18);
      if ( pdev_wmi_handle )
      {
        v30 = wmi_unified_peer_rx_reorder_queue_setup_send(pdev_wmi_handle);
      }
      else
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: pdev wmi handle NULL",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "target_if_rx_reorder_queue_setup");
        v30 = 16;
      }
      wlan_objmgr_pdev_release_ref(v19, 0x2Du, v29, v31, v32, v33, v34, v35, v36, v37, v38);
      _qdf_mem_free(v9);
      result = v30;
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: pdev with id %d is NULL",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "target_if_rx_reorder_queue_setup",
        *(unsigned __int8 *)(v9 + 9));
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: rx_reorder: Invalid message body",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_rx_reorder_queue_setup");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
