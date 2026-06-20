__int64 __fastcall hdd_tdls_register_peer(
        __int64 a1,
        int a2,
        const void *a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *link_info_by_vdev; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( a1 )
  {
    link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(a1, a2);
    if ( link_info_by_vdev )
    {
      return hdd_roam_register_tdlssta(*link_info_by_vdev, a3, a4, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    else
    {
      qdf_trace_msg(0x33u, 2u, "%s: Invalid vdev", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_tdls_register_peer");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid hddctx", a5, a6, a7, a8, a9, a10, a11, a12, "hdd_tdls_register_peer");
    return 4;
  }
}
