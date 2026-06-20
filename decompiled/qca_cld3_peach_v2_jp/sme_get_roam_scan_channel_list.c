__int64 __fastcall sme_get_roam_scan_channel_list(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w21
  __int64 result; // x0
  _QWORD *vdev_by_id_from_pdev; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  __int64 rso_config_fl; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int64 v37; // x8
  bool v38; // cc
  unsigned int v39; // w21
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w9
  unsigned __int64 v50; // x9
  _BYTE *v51; // x10
  __int64 v52; // x12
  char v53; // w14

  v12 = a4;
  if ( a4 >= 6u )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid sme vdev %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sme_get_roam_scan_channel_list",
      a4);
    return 4;
  }
  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21560), a4, 0xBu);
    if ( !vdev_by_id_from_pdev )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: vdev object is NULL for vdev %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "sme_get_roam_scan_channel_list",
        v12);
      qdf_mutex_release(a1 + 12776);
      return 4;
    }
    v27 = (__int64)vdev_by_id_from_pdev;
    rso_config_fl = wlan_cm_get_rso_config_fl(
                      (__int64)vdev_by_id_from_pdev,
                      (__int64)"sme_get_roam_scan_channel_list",
                      0x1DB5u,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23,
                      v24,
                      v25,
                      v26);
    if ( !rso_config_fl )
    {
      qdf_mutex_release(a1 + 12776);
      wlan_objmgr_vdev_release_ref(v27, 0xBu, v40, v41, v42, v43, v44, v45, v46, v47, v48);
      return 4;
    }
    if ( *(_BYTE *)(rso_config_fl + 112) )
    {
      v37 = 0;
      *a3 = *(_BYTE *)(rso_config_fl + 112);
      do
      {
        v38 = v37 > 0x62;
        *(_DWORD *)(a2 + 4 * v37) = *(_DWORD *)(*(_QWORD *)(rso_config_fl + 120) + 4 * v37);
        ++v37;
      }
      while ( !v38 && v37 < (unsigned __int8)*a3 );
      v39 = 0;
      goto LABEL_12;
    }
    v49 = *(unsigned __int8 *)(rso_config_fl + 168);
    *a3 = v49;
    if ( v49 )
    {
      v50 = 0;
      do
      {
        v38 = v50 > 0x62;
        *(_DWORD *)(a2 + 4 * v50) = *(_DWORD *)(*(_QWORD *)(rso_config_fl + 176) + 4 * v50);
        ++v50;
      }
      while ( !v38 && v50 < (unsigned __int8)*a3 );
      v51 = (_BYTE *)(rso_config_fl + 272);
      if ( !*(_BYTE *)(rso_config_fl + 272) )
        goto LABEL_29;
      if ( (unsigned int)v50 > 0x63 )
      {
        LOBYTE(v50) = 100;
        goto LABEL_29;
      }
    }
    else
    {
      LOBYTE(v50) = *(_BYTE *)(rso_config_fl + 272);
      v51 = (_BYTE *)(rso_config_fl + 272);
      if ( !(_BYTE)v50 )
      {
LABEL_29:
        *a3 = v50;
        v37 = *(unsigned __int8 *)(rso_config_fl + 168);
        if ( *(_BYTE *)(rso_config_fl + 168) || (v37 = (unsigned __int8)*v51, *v51) )
        {
          v39 = 0;
          goto LABEL_32;
        }
        qdf_trace_msg(
          0x34u,
          4u,
          "%s: Roam Scan channel list is NOT yet initialized",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "sme_get_roam_scan_channel_list");
        v39 = 4;
        v37 = 0;
LABEL_12:
        *a3 = v37;
LABEL_32:
        wlan_objmgr_vdev_release_ref(v27, 0xBu, (unsigned int *)v37, v29, v30, v31, v32, v33, v34, v35, v36);
        qdf_mutex_release(a1 + 12776);
        return v39;
      }
      v50 = 0;
    }
    v52 = 0;
    do
    {
      *(_DWORD *)(a2 + 4 * v50 + 4 * v52) = *(_DWORD *)(rso_config_fl + 276 + 4 * v52);
      v53 = v52 + 1;
      if ( v52 + 1 >= (unsigned __int64)(unsigned __int8)*v51 )
        break;
    }
    while ( v50 + v52++ < 0x63 );
    LOBYTE(v50) = v50 + v53;
    goto LABEL_29;
  }
  return result;
}
