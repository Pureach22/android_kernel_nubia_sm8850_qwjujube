bool __fastcall mlo_is_any_link_disconnecting(
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
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w21
  __int64 v18; // x20
  bool is_vdev_disconnecting; // w19
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int16 v49; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-18h] BYREF
  __int64 v51; // [xsp+10h] [xbp-10h]
  __int64 v52; // [xsp+18h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  if ( !a1
    || (v50 = 0,
        v51 = 0,
        mlo_sta_get_vdev_list(a1, &v49, (__int64)&v50, a2, a3, a4, a5, a6, a7, a8, a9),
        (v17 = v49) == 0) )
  {
    is_vdev_disconnecting = 0;
    goto LABEL_8;
  }
  v18 = v50;
  is_vdev_disconnecting = wlan_cm_is_vdev_disconnecting(v50, v9, v10, v11, v12, v13, v14, v15, v16);
  mlo_release_vdev_ref(v18, v20, v21, v22, v23, v24, v25, v26, v27, v28);
  if ( v17 != 1 )
  {
    v38 = v51;
    if ( is_vdev_disconnecting )
    {
      mlo_release_vdev_ref(v51, v29, v30, v31, v32, v33, v34, v35, v36, v37);
      if ( v17 == 2 )
      {
        is_vdev_disconnecting = 1;
        goto LABEL_8;
      }
    }
    else
    {
      is_vdev_disconnecting = wlan_cm_is_vdev_disconnecting(v51, v30, v31, v32, v33, v34, v35, v36, v37);
      mlo_release_vdev_ref(v38, v40, v41, v42, v43, v44, v45, v46, v47, v48);
      if ( v17 == 2 )
        goto LABEL_8;
    }
    __break(0x5512u);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return is_vdev_disconnecting;
}
