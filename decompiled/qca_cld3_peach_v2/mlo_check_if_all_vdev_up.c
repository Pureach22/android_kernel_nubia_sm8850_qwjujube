__int64 __fastcall mlo_check_if_all_vdev_up(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  _QWORD *v20; // x19
  _QWORD *v21; // x21
  __int64 *v22; // x20
  __int64 *v23; // x19
  __int64 v24; // t1
  __int64 v25; // x20
  __int64 v26; // x21
  __int64 v27; // x20

  if ( !a1 || !*(_QWORD *)(a1 + 1360) )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "mlo_check_if_all_vdev_up");
    return 0;
  }
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    v18 = jiffies;
    if ( mlo_check_if_all_vdev_up___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Vdev id %d is not in up state",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "mlo_check_if_all_vdev_up",
        *(unsigned __int8 *)(a1 + 168));
      mlo_check_if_all_vdev_up___last_ticks = v18;
      return 0;
    }
    return 0;
  }
  v20 = *(_QWORD **)(a1 + 1360);
  v21 = (_QWORD *)v20[278];
  if ( !v21 )
  {
    v25 = jiffies;
    if ( mlo_check_if_all_vdev_up___last_ticks_27 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: mlo sta ctx is null",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "mlo_check_if_all_vdev_up");
      mlo_check_if_all_vdev_up___last_ticks_27 = v25;
      return 0;
    }
    return 0;
  }
  v22 = v20 + 3;
  if ( v20[3]
    && ((v21[1] & 1) != 0 || (*v21 & 1) != 0)
    && ((unsigned int)wlan_vdev_is_up() || wlan_cm_is_vdev_disconnecting(*v22, v10, v11, v12, v13, v14, v15, v16, v17)) )
  {
    goto LABEL_23;
  }
  v24 = v20[4];
  v23 = v20 + 4;
  if ( v24 )
  {
    if ( (v21[1] & 2) != 0 || (*v21 & 2) != 0 )
    {
      if ( (unsigned int)wlan_vdev_is_up() )
      {
        v22 = v23;
        goto LABEL_23;
      }
      v22 = v23;
      if ( wlan_cm_is_vdev_disconnecting(*v23, v10, v11, v12, v13, v14, v15, v16, v17) )
      {
LABEL_23:
        v26 = jiffies;
        if ( mlo_check_if_all_vdev_up___last_ticks_28 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Vdev id %d is not in up state",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "mlo_check_if_all_vdev_up",
            *(unsigned __int8 *)(*v22 + 168));
          mlo_check_if_all_vdev_up___last_ticks_28 = v26;
          return 0;
        }
        return 0;
      }
    }
  }
  v27 = jiffies;
  if ( mlo_check_if_all_vdev_up___last_ticks_29 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x8Fu, 8u, "%s: all links are up", v10, v11, v12, v13, v14, v15, v16, v17, "mlo_check_if_all_vdev_up");
    mlo_check_if_all_vdev_up___last_ticks_29 = v27;
  }
  return 1;
}
