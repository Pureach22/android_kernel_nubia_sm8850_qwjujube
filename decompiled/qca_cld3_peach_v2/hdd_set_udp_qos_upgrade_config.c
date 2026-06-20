__int64 __fastcall hdd_set_udp_qos_upgrade_config(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 v11; // x20

  if ( *(_DWORD *)(a1 + 40) )
  {
    v10 = jiffies;
    if ( hdd_set_udp_qos_upgrade_config___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Data priority upgrade only allowed in STA mode:%d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "hdd_set_udp_qos_upgrade_config");
      hdd_set_udp_qos_upgrade_config___last_ticks = v10;
    }
  }
  else
  {
    if ( a2 < 4u )
    {
      *(_BYTE *)(a1 + 42083) = a2;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: UDP packets qos upgrade to: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "hdd_set_udp_qos_upgrade_config");
      return 0;
    }
    v11 = jiffies;
    if ( hdd_set_udp_qos_upgrade_config___last_ticks_1 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid data priority: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "hdd_set_udp_qos_upgrade_config");
      hdd_set_udp_qos_upgrade_config___last_ticks_1 = v11;
    }
  }
  return 4294967274LL;
}
