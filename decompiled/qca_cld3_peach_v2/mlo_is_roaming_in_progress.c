__int64 __fastcall mlo_is_roaming_in_progress(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w21
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 v14; // x19
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x8
  __int64 v18; // x1
  unsigned int v19; // w20

  v2 = a2;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v4 )
  {
    v13 = *(_QWORD *)(v4 + 1360);
    v14 = v4;
    if ( !v13 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: mlo_dev_ctx object is NULL for vdev %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "mlo_is_roaming_in_progress",
        v2);
      goto LABEL_13;
    }
    v15 = *(_QWORD *)(v13 + 24);
    if ( v15 )
    {
      v16 = *(unsigned __int8 *)(v15 + 168);
      if ( (_DWORD)v16 == 255 )
        goto LABEL_12;
      if ( wlan_cm_is_roam_sync_in_progress(a1, v16) )
      {
LABEL_9:
        v19 = 1;
LABEL_14:
        wlan_objmgr_vdev_release_ref(v14, 0x43u, (unsigned int *)v17, v5, v6, v7, v8, v9, v10, v11, v12);
        return v19;
      }
    }
    v17 = *(_QWORD *)(v13 + 32);
    if ( !v17 )
      goto LABEL_13;
    v18 = *(unsigned __int8 *)(v17 + 168);
    if ( (_DWORD)v18 != 255 )
    {
      if ( wlan_cm_is_roam_sync_in_progress(a1, v18) )
        goto LABEL_9;
LABEL_13:
      v19 = 0;
      goto LABEL_14;
    }
LABEL_12:
    qdf_trace_msg(0x68u, 2u, "%s: invalid vdev id", v5, v6, v7, v8, v9, v10, v11, v12, "mlo_is_roaming_in_progress");
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev object is NULL for vdev %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "mlo_is_roaming_in_progress",
    v2);
  return 0;
}
