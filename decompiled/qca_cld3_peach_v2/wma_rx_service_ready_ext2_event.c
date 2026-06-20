__int64 __fastcall wma_rx_service_ready_ext2_event(
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
  __int64 v19; // x20

  qdf_trace_msg(0x36u, 8u, "%s: Enter", a2, a3, a4, a5, a6, a7, a8, a9, "wma_rx_service_ready_ext2_event");
  if ( a1 )
  {
    v18 = *(_QWORD *)(a1 + 24);
    if ( v18 && (v19 = *(_QWORD *)(v18 + 2800)) != 0 )
    {
      if ( (wlan_mlme_is_multipass_sap(v18, v10, v11, v12, v13, v14, v15, v16, v17) & 1) != 0 )
        *(_DWORD *)(v19 + 344) = 16;
      if ( !(unsigned int)policy_mgr_update_sbs_freq(*(_QWORD *)(a1 + 24), v19) )
      {
        wma_update_hw_mode_config(a1, v19);
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: target psoc info is NULL",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wma_rx_service_ready_ext2_event");
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wma_validate_handle",
      "wma_rx_service_ready_ext2_event");
  }
  return 4294967274LL;
}
