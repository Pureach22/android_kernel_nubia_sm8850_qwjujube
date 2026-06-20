__int64 __fastcall ucfg_tdls_link_vdev_is_matching(__int64 a1)
{
  __int64 tdls_link_vdev; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  tdls_link_vdev = tdls_mlo_get_tdls_link_vdev(a1);
  if ( tdls_link_vdev )
  {
    if ( tdls_link_vdev != a1 )
    {
      qdf_trace_msg(
        0,
        8u,
        "%s: tdls vdev has been created on vdev %d",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "ucfg_tdls_link_vdev_is_matching",
        *(unsigned __int8 *)(tdls_link_vdev + 168));
      return 0;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 60) |= 0x10u;
    tdls_set_remain_links_unforce(a1, v3, v4, v5, v6, v7, v8, v9, v10);
  }
  return 1;
}
