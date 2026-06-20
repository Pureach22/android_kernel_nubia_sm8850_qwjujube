__int64 __fastcall hdd_close_ndi(
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
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w0
  const char *v27; // x2
  unsigned int v28; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_close_ndi");
  if ( *(_DWORD *)(a1 + 40) == 11 )
  {
    wlan_hdd_netif_queue_control(a1, 4u, 1u, v10, v11, v12, v13, v14, v15, v16, v17);
    hdd_cancel_ip_notifier_work(a1);
    hdd_adapter_deregister_fc();
    v26 = hdd_vdev_destroy(*(_QWORD *)(a1 + 52824), v18, v19, v20, v21, v22, v23, v24, v25);
    if ( v26 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to destroy vdev: %d",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "hdd_close_ndi",
        v26);
    v27 = "%s: exit";
    v28 = 8;
    *(_BYTE *)(a1 + 52797) = 1;
  }
  else
  {
    v27 = "%s: Interface is not in NDI mode";
    v28 = 2;
  }
  return qdf_trace_msg(0x33u, v28, v27, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_close_ndi");
}
