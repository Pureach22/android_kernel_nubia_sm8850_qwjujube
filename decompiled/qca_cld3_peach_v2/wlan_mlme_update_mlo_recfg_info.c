__int64 __fastcall wlan_mlme_update_mlo_recfg_info(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x19
  __int64 v15; // x21
  unsigned int *v16; // x8
  __int64 v17; // x0
  const char *v19; // x2
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( !v4 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: get vdev failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_mlme_update_mlo_recfg_info");
    return 16;
  }
  v13 = *(_QWORD *)(v4 + 1360);
  v14 = v4;
  if ( !v13 )
  {
    v19 = "%s: get vdev mlo dev ctx failed";
LABEL_13:
    qdf_trace_msg(0x68u, 2u, v19, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_mlme_update_mlo_recfg_info");
    wlan_objmgr_vdev_release_ref(v14, 0x43u, v20, v21, v22, v23, v24, v25, v26, v27, v28);
    return 16;
  }
  v15 = *(_QWORD *)(v13 + 3888);
  if ( !v15 )
  {
    v19 = "%s: get Link reconfig ctx failed";
    goto LABEL_13;
  }
  v16 = (unsigned int *)*a3;
  if ( !*a3 )
    goto LABEL_9;
  *(_WORD *)(v15 + 3250) = *((_WORD *)a3 + 1);
  *(_WORD *)(v15 + 3258) = *((_WORD *)a3 + 5);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: frame: %d, add link bm: %d, delete link bm: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_mlme_update_mlo_recfg_info",
    0,
    *((unsigned __int16 *)a3 + 1));
  v16 = (unsigned int *)*a3;
  if ( (unsigned int)v16 <= 1 )
    goto LABEL_9;
  *(_WORD *)(v15 + 3252) = *((_WORD *)a3 + 2);
  *(_WORD *)(v15 + 3260) = *((_WORD *)a3 + 6);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: frame: %d, add link bm: %d, delete link bm: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_mlme_update_mlo_recfg_info",
    1,
    *((unsigned __int16 *)a3 + 2));
  v16 = (unsigned int *)*a3;
  if ( (unsigned int)v16 < 3 )
    goto LABEL_9;
  *(_WORD *)(v15 + 3254) = *((_WORD *)a3 + 3);
  *(_WORD *)(v15 + 3262) = *((_WORD *)a3 + 7);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: frame: %d, add link bm: %d, delete link bm: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_mlme_update_mlo_recfg_info",
    2,
    *((unsigned __int16 *)a3 + 3));
  v16 = (unsigned int *)*a3;
  if ( (unsigned int)v16 < 4 )
    goto LABEL_9;
  *(_WORD *)(v15 + 3256) = *((_WORD *)a3 + 4);
  *(_WORD *)(v15 + 3264) = *((_WORD *)a3 + 8);
  v17 = qdf_trace_msg(
          0x68u,
          8u,
          "%s: frame: %d, add link bm: %d, delete link bm: %d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "wlan_mlme_update_mlo_recfg_info",
          3,
          *((unsigned __int16 *)a3 + 4));
  v16 = (unsigned int *)*a3;
  if ( (unsigned int)v16 > 4 )
  {
    __break(0x5512u);
    return wlan_mlme_set_btm_abridge_flag(v17);
  }
  else
  {
LABEL_9:
    *(_BYTE *)(v15 + 3248) = (_BYTE)v16;
    wlan_objmgr_vdev_release_ref(v14, 0x43u, v16, v5, v6, v7, v8, v9, v10, v11, v12);
    return 0;
  }
}
