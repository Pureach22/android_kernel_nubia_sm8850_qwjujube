__int64 __fastcall hdd_config_phy_mode(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x9
  __int64 v11; // x8
  unsigned int v12; // w1
  __int64 v13; // x0
  __int64 v15; // x20

  v10 = *(_QWORD *)(a2 + 496);
  if ( !v10 )
    return 0;
  v11 = *(_QWORD *)(a2 + 192);
  v12 = *(_DWORD *)(v10 + 4);
  if ( !v11 )
    return hdd_set_phy_mode(*a1, v12, a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = *a1;
  if ( *(_DWORD *)(v11 + 4) == *(_DWORD *)(*(_QWORD *)(v13 + 32) + 224LL) )
    return hdd_set_vdev_phy_mode(v13, v12);
  v15 = jiffies;
  if ( hdd_config_phy_mode___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: ifindex %d, expected ifindex %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_phy_mode");
    hdd_config_phy_mode___last_ticks = v15;
  }
  return 4294967274LL;
}
