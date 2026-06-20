__int64 __fastcall mlo_ap_link_down_cmpl_notify(
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
  if ( a1 && *(_QWORD *)(a1 + 1360) )
    return wlan_vdev_mlme_clear_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  else
    return qdf_trace_msg(0x8Fu, 2u, "%s: Invalid input", a2, a3, a4, a5, a6, a7, a8, a9, "mlo_ap_vdev_detach");
}
