__int64 __fastcall target_if_peer_rx_reorder_queue_remove(__int64 a1, unsigned __int8 a2)
{
  __int64 pdev_by_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 pdev_wmi_handle; // x0
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  _ReadStatusReg(SP_EL0);
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, a2, 0x2Du);
  if ( pdev_by_id )
  {
    v12 = pdev_by_id;
    pdev_wmi_handle = lmac_get_pdev_wmi_handle(pdev_by_id, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( pdev_wmi_handle )
    {
      v23 = wmi_unified_peer_rx_reorder_queue_remove_send(pdev_wmi_handle);
      wlan_objmgr_pdev_release_ref(v12, 0x2Du, v24, v25, v26, v27, v28, v29, v30, v31, v32);
      result = v23;
    }
    else
    {
      wlan_objmgr_pdev_release_ref(v12, 0x2Du, v14, v15, v16, v17, v18, v19, v20, v21, v22);
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: pdev wmi handle NULL",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "target_if_peer_rx_reorder_queue_remove");
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: pdev with id %d is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "target_if_peer_rx_reorder_queue_remove",
      a2);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
