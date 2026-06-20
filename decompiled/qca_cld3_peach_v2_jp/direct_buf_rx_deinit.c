__int64 __fastcall direct_buf_rx_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int handler; // w19
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  if ( (unsigned int)wlan_objmgr_unregister_pdev_destroy_handler(
                       8u,
                       (__int64)target_if_direct_buf_rx_pdev_destroy_handler,
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8) )
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: Failed to unregister pdev destroy handler",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "direct_buf_rx_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_pdev_create_handler(
                       8u,
                       (__int64)&target_if_direct_buf_rx_pdev_create_handler,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15) )
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: Failed to unregister pdev create handler",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "direct_buf_rx_deinit");
  if ( (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(
                       8u,
                       (__int64)target_if_direct_buf_rx_psoc_destroy_handler,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23) )
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: Failed to unregister psoc destroy handler",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "direct_buf_rx_deinit");
  handler = wlan_objmgr_unregister_psoc_create_handler(
              8u,
              (__int64)target_if_direct_buf_rx_psoc_create_handler,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31);
  if ( handler )
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: Failed to unregister psoc create handler",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "direct_buf_rx_deinit");
  qdf_trace_msg(
    0x5Bu,
    8u,
    "%s: Direct Buffer RX pdev,psoc create and destroy handlers unregistered",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "direct_buf_rx_deinit");
  return handler;
}
