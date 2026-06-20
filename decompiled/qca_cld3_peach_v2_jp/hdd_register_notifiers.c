__int64 __fastcall hdd_register_notifiers(_QWORD *a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w20
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  a1[143] = wlan_hdd_ipv6_changed;
  v2 = register_inet6addr_notifier(a1 + 143);
  if ( !v2 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Registered IPv6 notifier",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_wlan_register_ip6_notifier");
    a1[147] = wlan_hdd_ipv4_changed;
    v12 = register_inetaddr_notifier(a1 + 147);
    if ( v12 )
    {
      v11 = v12;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to register IPv4 notifier: %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hdd_register_notifiers",
        v12);
    }
    else
    {
      v11 = osif_dp_nud_register_netevent_notifier(*a1);
      if ( !v11 )
        return v11;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to register netevent notifier: %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "hdd_register_notifiers",
        v11);
      unregister_inetaddr_notifier(a1 + 147);
    }
    unregister_inet6addr_notifier(a1 + 143);
    return v11;
  }
  v11 = v2;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Failed to register IPv6 notifier: %d",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "hdd_wlan_register_ip6_notifier",
    v2);
  return v11;
}
