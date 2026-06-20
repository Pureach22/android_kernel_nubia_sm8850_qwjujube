__int64 __fastcall mlo_sync_disconnect(
        __int64 a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *v11; // x23
  __int64 v14; // x22
  void *v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  __int64 v26; // x21
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 result; // x0
  void *v31; // x0

  if ( !a1 )
    return 16;
  v11 = *(_QWORD **)(a1 + 1360);
  if ( !v11 )
    return wlan_cm_disconnect_sync(a1, a2, a3);
  v14 = v11[278];
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0 )
  {
    result = wlan_cm_disconnect_sync(a1, a2, a3);
    if ( (_DWORD)result )
      return result;
    goto LABEL_31;
  }
  qdf_mutex_acquire((__int64)(v11 + 207));
  if ( v14 )
  {
    v16 = *(void **)(v14 + 24);
    if ( v16 )
    {
      wlan_cm_free_connect_req(v16);
      *(_QWORD *)(v14 + 24) = 0;
    }
  }
  qdf_mutex_release((__int64)(v11 + 207));
  v25 = v11[3];
  if ( v25 )
  {
    if ( (wlan_vdev_mlme_is_mlo_vdev(v25, v17, v18, v19, v20, v21, v22, v23, v24) & 1) != 0 )
    {
      v26 = v11[3];
      if ( (*(_BYTE *)(v26 + 60) & 2) == 0 )
        goto LABEL_23;
    }
  }
  v27 = v11[4];
  if ( !v27
    || (wlan_vdev_mlme_is_mlo_vdev(v27, v17, v18, v19, v20, v21, v22, v23, v24) & 1) == 0
    || (v26 = v11[4], (*(_BYTE *)(v26 + 60) & 2) != 0) )
  {
    v26 = v11[3];
    goto LABEL_23;
  }
  v28 = v11[3];
  if ( !v28 || v28 == v26 )
  {
LABEL_23:
    v29 = v11[4];
    if ( !v29 )
      goto LABEL_29;
    goto LABEL_24;
  }
  if ( v26 )
  {
    wlan_cm_disconnect(v28, a2, a3, nullptr);
    v29 = v11[4];
    if ( !v29 )
      goto LABEL_29;
  }
  else
  {
    v26 = v11[3];
    v29 = v11[4];
    if ( !v29 )
      goto LABEL_29;
  }
LABEL_24:
  if ( v29 != v26 )
  {
    if ( v26 )
      wlan_cm_disconnect(v29, a2, a3, nullptr);
    else
      v26 = v29;
    goto LABEL_30;
  }
LABEL_29:
  if ( v26 )
LABEL_30:
    wlan_cm_disconnect_sync(v26, a2, a3);
LABEL_31:
  if ( v14 )
  {
    qdf_trace_msg(0x8Fu, 8u, "%s: enter", v17, v18, v19, v20, v21, v22, v23, v24, "mlo_free_copied_conn_req");
    qdf_mutex_acquire(v14 + 40);
    v31 = *(void **)(v14 + 32);
    if ( v31 )
    {
      wlan_cm_free_connect_req(v31);
      *(_QWORD *)(v14 + 32) = 0;
    }
    qdf_mutex_release(v14 + 40);
  }
  return 0;
}
