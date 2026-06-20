__int64 __fastcall wlan_mlo_dev_t2lm_notify_link_update(
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
  __int64 v11; // x19
  bool is_vdev_connected; // w8
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x9
  void (__fastcall *v24)(__int64, __int64); // x10

  if ( !a1 || !*(_QWORD *)(a1 + 1360) )
    return 16;
  if ( *(_DWORD *)(a1 + 16)
    || (v11 = a1,
        is_vdev_connected = wlan_cm_is_vdev_connected(a1, a3, a4, a5, a6, a7, a8, a9, a10),
        a1 = v11,
        is_vdev_connected) )
  {
    v13 = a1;
    if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
    {
      v22 = 0;
      v23 = *(_QWORD *)(v13 + 1360) + 3000LL;
      while ( 1 )
      {
        if ( *(_BYTE *)(v23 + v22) == 1 )
        {
          v24 = *(void (__fastcall **)(__int64, __int64))(v23 + 8 * v22 - 400);
          if ( v24 )
            break;
        }
        if ( ++v22 == 50 )
          return 0;
      }
      if ( *((_DWORD *)v24 - 1) != 1533165245 )
        __break(0x822Au);
      v24(v13, a2);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: failed due to non-ML connection",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_mlo_dev_t2lm_notify_link_update");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Not associated!",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlo_dev_t2lm_notify_link_update");
    return 3;
  }
}
