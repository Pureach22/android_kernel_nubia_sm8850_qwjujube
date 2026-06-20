__int64 __fastcall hdd_hostapd_deinit_sap_session(
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
  int v11; // w21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  __int64 v21; // x0
  __int64 v22; // x22

  v9 = *(_QWORD *)(a1 + 272);
  if ( v9 )
  {
    wlan_hdd_undo_acs(a1);
    wlansap_release_vdev_ref(v9);
    v11 = sap_deinit_ctx(v9);
    if ( v11 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Error stopping the sap session",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "hdd_hostapd_deinit_sap_session");
      LODWORD(v9) = -22;
    }
    else
    {
      LODWORD(v9) = 0;
    }
    v21 = *(_QWORD *)(a1 + 2160);
    v22 = *(_QWORD *)(a1 + 272);
    if ( v21 )
    {
      _qdf_mem_free(v21);
      *(_QWORD *)(a1 + 2160) = 0;
    }
    if ( v22 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: destroying sap context",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "hdd_sap_destroy_ctx");
      if ( (unsigned int)sap_destroy_ctx(v22) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Error closing the sap session",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "hdd_hostapd_deinit_sap_session");
        LODWORD(v9) = -22;
        v20 = "%s: sap has issue closing the session";
        goto LABEL_16;
      }
      *(_QWORD *)(a1 + 272) = 0;
    }
    else
    {
      qdf_trace_msg(0x33u, 8u, "%s: sap context is NULL", v12, v13, v14, v15, v16, v17, v18, v19, "hdd_sap_destroy_ctx");
    }
    if ( v11 )
      v20 = "%s: sap has issue closing the session";
    else
      v20 = "%s: sap has been closed successfully";
  }
  else
  {
    v20 = "%s: sap context already released, nothing to be done";
  }
LABEL_16:
  qdf_trace_msg(0x33u, 8u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_hostapd_deinit_sap_session");
  return (unsigned int)v9;
}
