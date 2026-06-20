__int64 __fastcall mlo_check_if_all_links_up(
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
  _QWORD *v9; // x20
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x0
  const char *v14; // x2
  __int64 v15; // x8

  if ( !a1 || (v9 = *(_QWORD **)(a1 + 1360)) == nullptr )
  {
    v14 = "%s: Vdev is null";
LABEL_12:
    qdf_trace_msg(0x8Fu, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_check_if_all_links_up");
    return 0;
  }
  v10 = v9[278];
  if ( !v10 )
  {
    v14 = "%s: mlo sta ctx is null";
    goto LABEL_12;
  }
  v11 = v9[3];
  if ( v11 && (*(_QWORD *)(v10 + 8) & 1) != 0 && !wlan_cm_is_vdev_connected(v11, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v15 = 0;
  }
  else
  {
    v12 = v9[4];
    if ( !v12 || (*(_QWORD *)(v10 + 8) & 2) == 0 || wlan_cm_is_vdev_connected(v12, a2, a3, a4, a5, a6, a7, a8, a9) )
    {
      qdf_trace_msg(0x8Fu, 8u, "%s: all links are up", a2, a3, a4, a5, a6, a7, a8, a9, "mlo_check_if_all_links_up");
      return 1;
    }
    v15 = 1;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Vdev id %d is not in connected state",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "mlo_check_if_all_links_up",
    *(unsigned __int8 *)(v9[v15 + 3] + 168LL));
  return 0;
}
