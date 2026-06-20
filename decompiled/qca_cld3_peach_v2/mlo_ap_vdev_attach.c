__int64 __fastcall mlo_ap_vdev_attach(
        __int64 a1,
        char a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19

  if ( a1 && (v11 = *(_QWORD *)(a1 + 1360)) != 0 && *(_QWORD *)(v11 + 2232) )
  {
    *(_BYTE *)(a1 + 93) = a2;
    wlan_vdev_mlme_set_mlo_vdev(a1, a4, a5, a6, a7, a8, a9, a10, a11);
    qdf_mutex_acquire(v11 + 1656);
    **(_BYTE **)(v11 + 2232) = a3;
    qdf_mutex_release(v11 + 1656);
    return 1;
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Invalid input", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_ap_vdev_attach");
    return 0;
  }
}
