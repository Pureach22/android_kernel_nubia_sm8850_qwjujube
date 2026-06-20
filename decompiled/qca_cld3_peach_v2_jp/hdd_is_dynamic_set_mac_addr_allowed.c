__int64 __fastcall hdd_is_dynamic_set_mac_addr_allowed(
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
  __int64 v10; // x9
  __int64 v11; // x0
  __int64 v12; // x10
  int v13; // w4
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  char is_p2p_device_dynamic_set_mac_addr_supported; // w0
  __int64 v24; // x20
  __int64 v25; // x20
  __int64 v26; // x20

  v10 = *(_QWORD *)(a1 + 52824);
  v11 = *(_QWORD *)(v10 + 32);
  if ( !v11 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: VDEV is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_is_dynamic_set_mac_addr_allowed");
    is_p2p_device_dynamic_set_mac_addr_supported = 0;
    return is_p2p_device_dynamic_set_mac_addr_supported & 1;
  }
  v12 = *(_QWORD *)(a1 + 24);
  if ( (*(_BYTE *)(v12 + 7097) & 1) == 0 )
  {
    v24 = jiffies;
    if ( hdd_is_dynamic_set_mac_addr_allowed___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: On iface up, set mac address change isn't supported",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "hdd_is_dynamic_set_mac_addr_allowed");
      is_p2p_device_dynamic_set_mac_addr_supported = 0;
      hdd_is_dynamic_set_mac_addr_allowed___last_ticks = v24;
      return is_p2p_device_dynamic_set_mac_addr_supported & 1;
    }
    goto LABEL_11;
  }
  v13 = *(_DWORD *)(a1 + 40);
  if ( v13 == 7 )
  {
    is_p2p_device_dynamic_set_mac_addr_supported = ucfg_is_p2p_device_dynamic_set_mac_addr_supported(
                                                     *(_QWORD *)v12,
                                                     a2,
                                                     a3,
                                                     a4,
                                                     a5,
                                                     a6,
                                                     a7,
                                                     a8,
                                                     a9);
    return is_p2p_device_dynamic_set_mac_addr_supported & 1;
  }
  if ( v13 == 1 )
  {
    if ( (*(_QWORD *)(v10 + 4416) & 2) != 0 )
    {
      v26 = jiffies;
      if ( hdd_is_dynamic_set_mac_addr_allowed___last_ticks_117 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: SAP is in up state, set mac address isn't supported",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "hdd_is_dynamic_set_mac_addr_allowed");
        is_p2p_device_dynamic_set_mac_addr_supported = 0;
        hdd_is_dynamic_set_mac_addr_allowed___last_ticks_117 = v26;
        return is_p2p_device_dynamic_set_mac_addr_supported & 1;
      }
      goto LABEL_11;
    }
LABEL_14:
    is_p2p_device_dynamic_set_mac_addr_supported = 1;
    return is_p2p_device_dynamic_set_mac_addr_supported & 1;
  }
  if ( v13 )
  {
    v25 = jiffies;
    if ( hdd_is_dynamic_set_mac_addr_allowed___last_ticks_119 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Dynamic set mac address isn't supported for opmode:%d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "hdd_is_dynamic_set_mac_addr_allowed");
      is_p2p_device_dynamic_set_mac_addr_supported = 0;
      hdd_is_dynamic_set_mac_addr_allowed___last_ticks_119 = v25;
      return is_p2p_device_dynamic_set_mac_addr_supported & 1;
    }
    goto LABEL_11;
  }
  if ( cm_is_vdev_disconnected(v11, a2, a3, a4, a5, a6, a7, a8, a9) )
    goto LABEL_14;
  v22 = jiffies;
  if ( hdd_is_dynamic_set_mac_addr_allowed___last_ticks_115 - jiffies + 125 >= 0 )
  {
LABEL_11:
    is_p2p_device_dynamic_set_mac_addr_supported = 0;
    return is_p2p_device_dynamic_set_mac_addr_supported & 1;
  }
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: VDEV is not in disconnected state, set mac address isn't supported",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "hdd_is_dynamic_set_mac_addr_allowed");
  is_p2p_device_dynamic_set_mac_addr_supported = 0;
  hdd_is_dynamic_set_mac_addr_allowed___last_ticks_115 = v22;
  return is_p2p_device_dynamic_set_mac_addr_supported & 1;
}
