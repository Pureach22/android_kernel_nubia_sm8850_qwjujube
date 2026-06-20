__int64 __fastcall mlme_set_roam_state(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int8 v4; // w20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 ext_hdl; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x5
  __int64 v25; // x22
  char *v26; // x4
  char *v27; // x6
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( !v5 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev%d: vdev object is NULL",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "mlme_set_roam_state",
             v4);
  v14 = v5;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v5, v6, v7, v8, v9, v10, v11, v12, v13);
  if ( ext_hdl )
  {
    v24 = *(unsigned int *)(ext_hdl + 152);
    v25 = ext_hdl;
    if ( (unsigned int)v24 > 6 )
    {
      v26 = (char *)&unk_8B9E43;
      if ( a3 > 6 )
        goto LABEL_5;
    }
    else
    {
      v26 = off_9FD8C8[v24];
      if ( a3 > 6 )
      {
LABEL_5:
        v27 = (char *)&unk_8B9E43;
LABEL_10:
        qdf_trace_msg(
          0x68u,
          8u,
          "CM_RSO: vdev%d: [%s(%d)] --> [%s(%d)]",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v4,
          v26,
          v24,
          v27,
          a3);
        *(_DWORD *)(v25 + 152) = a3;
        return wlan_objmgr_vdev_release_ref(v14, 0x43u, v29, v30, v31, v32, v33, v34, v35, v36, v37);
      }
    }
    v27 = off_9FD8C8[a3];
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev%d: vdev legacy private object is NULL",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "mlme_set_roam_state",
    v4);
  return wlan_objmgr_vdev_release_ref(v14, 0x43u, v29, v30, v31, v32, v33, v34, v35, v36, v37);
}
