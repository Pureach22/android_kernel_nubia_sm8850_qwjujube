__int64 __fastcall hdd_register_get_port_status_notifier(__int64 a1)
{
  unsigned int v1; // w0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  *(_QWORD *)(a1 + 8464) = wlan_hdd_get_port_status_notify;
  v1 = netlink_register_notifier(a1 + 8464);
  if ( v1 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Failed to register get sta user notifier: %d",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "hdd_register_get_port_status_notifier",
             v1);
  else
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: Registered GET_STA user application notifier",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "hdd_register_get_port_status_notifier");
}
