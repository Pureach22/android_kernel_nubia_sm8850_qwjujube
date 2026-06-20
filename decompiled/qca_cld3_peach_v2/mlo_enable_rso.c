__int64 __fastcall mlo_enable_rso(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x20
  char v13; // w0
  __int64 assoc_link_vdev; // x0
  const char *v16; // x2

  if ( a3 )
  {
    if ( *(_BYTE *)(a3 + 160) )
    {
      if ( (*(_BYTE *)(a2 + 60) & 2) == 0 )
        return 0;
      v12 = a2;
      v13 = mlo_check_if_all_links_up(a2);
      a2 = v12;
      if ( (v13 & 1) == 0 )
        return 0;
    }
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(a2, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( assoc_link_vdev )
    {
      cm_roam_start_init_on_connect(a1, *(_BYTE *)(assoc_link_vdev + 168));
      return 0;
    }
    v16 = "%s: Assoc vdev is null";
  }
  else
  {
    v16 = "%s: Connect resp is null";
  }
  qdf_trace_msg(0x8Fu, 2u, v16, a4, a5, a6, a7, a8, a9, a10, a11, "mlo_enable_rso");
  return 29;
}
