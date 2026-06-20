_QWORD *__fastcall sme_store_nss_chains_cfg_in_vdev(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *ini_vdev_config; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x9
  __int64 v32; // x8
  __int64 v33; // x10
  __int64 v34; // x11
  __int64 v35; // x8
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x8
  __int64 v39; // x9

  if ( !a1 )
    return (_QWORD *)qdf_trace_msg(
                       0x34u,
                       2u,
                       "%s: Invalid vdev",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       "sme_store_nss_chains_cfg_in_vdev");
  ini_vdev_config = (_QWORD *)mlme_get_ini_vdev_config(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  result = (_QWORD *)mlme_get_dynamic_vdev_config(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !ini_vdev_config || !result )
    return (_QWORD *)qdf_trace_msg(
                       0x34u,
                       2u,
                       "%s: Nss chains ini/dynamic config NULL vdev_id %d",
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       "sme_store_nss_chains_cfg_in_vdev",
                       *(unsigned __int8 *)(a1 + 168));
  v31 = a2[1];
  v30 = a2[2];
  *ini_vdev_config = *a2;
  ini_vdev_config[1] = v31;
  ini_vdev_config[2] = v30;
  v32 = a2[6];
  v33 = a2[3];
  v34 = a2[4];
  ini_vdev_config[5] = a2[5];
  ini_vdev_config[6] = v32;
  ini_vdev_config[3] = v33;
  ini_vdev_config[4] = v34;
  v35 = a2[6];
  v37 = a2[3];
  v36 = a2[4];
  result[5] = a2[5];
  result[6] = v35;
  result[3] = v37;
  result[4] = v36;
  v39 = a2[1];
  v38 = a2[2];
  *result = *a2;
  result[1] = v39;
  result[2] = v38;
  return result;
}
