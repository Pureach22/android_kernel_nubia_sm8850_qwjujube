bool __fastcall wlan_vdev_p2p_is_wfd_r2_mode(
        __int64 a1,
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
  unsigned __int8 v10; // w19
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w19

  if ( a1 )
  {
    v10 = a2;
    v11 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
    if ( v11 )
    {
      v20 = *(unsigned __int8 *)(v11 + 164);
      wlan_objmgr_vdev_release_ref(v11, 67);
      return (unsigned int)(v20 - 1) < 2;
    }
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: vdev is NULL for id%d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_vdev_p2p_is_wfd_r2_mode",
      v10);
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: psoc is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_p2p_is_wfd_r2_mode");
  }
  return 0;
}
