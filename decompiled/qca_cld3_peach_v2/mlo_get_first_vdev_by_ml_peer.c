__int64 __fastcall mlo_get_first_vdev_by_ml_peer(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x20

  qdf_mutex_acquire(a1 + 120);
  v10 = *(_QWORD *)(a1 + 16);
  if ( v10 && !(unsigned int)wlan_objmgr_vdev_try_get_ref(*(_QWORD *)(v10 + 96), 0x5Au, v2, v3, v4, v5, v6, v7, v8, v9) )
    goto LABEL_6;
  v10 = *(_QWORD *)(a1 + 56);
  if ( v10 )
  {
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(*(_QWORD *)(v10 + 96), 0x5Au, v2, v3, v4, v5, v6, v7, v8, v9) )
    {
      v10 = 0;
      goto LABEL_7;
    }
LABEL_6:
    v10 = *(_QWORD *)(v10 + 96);
  }
LABEL_7:
  qdf_mutex_release(a1 + 120);
  return v10;
}
