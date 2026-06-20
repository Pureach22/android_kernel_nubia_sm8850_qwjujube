__int64 __fastcall hdd_update_vdev_nss_chains_config(__int64 *a1)
{
  __int64 v1; // x21
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  __int64 vdev_by_user; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  __int64 dynamic_vdev_config; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 *v31; // x20
  __int64 v32; // x21
  __int64 v33; // x27
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x26
  _QWORD *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  __int64 v54; // x10
  __int64 v55; // x8
  __int64 v56; // x10
  __int64 v57; // x11

  v1 = *a1;
  if ( (unsigned int)_hdd_validate_adapter(*a1, "hdd_update_vdev_nss_chains_config") )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: adapter is null. Unable to update vdev nss chains",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "hdd_update_vdev_nss_chains_config");
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_update_vdev_nss_chains_config");
  if ( !vdev_by_user )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Null vdev[%u]. Can't update nss chains",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "hdd_update_vdev_nss_chains_config",
             *((unsigned __int8 *)a1 + 8));
  v21 = vdev_by_user;
  dynamic_vdev_config = mlme_get_dynamic_vdev_config(vdev_by_user, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( dynamic_vdev_config )
  {
    v31 = (__int64 *)dynamic_vdev_config;
    result = _hdd_objmgr_put_vdev_by_user(v21, 6, "hdd_update_vdev_nss_chains_config");
    if ( v1 )
    {
      v32 = v1 + 52840;
      if ( v32 )
      {
        v33 = 0;
        do
        {
          if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v33 >> 3)) > 2 )
            break;
          if ( *(unsigned __int8 *)(v32 + 8) != *((unsigned __int8 *)a1 + 8) )
          {
            result = hdd_is_vdev_in_conn_state(v32);
            if ( (result & 1) != 0 )
            {
              v34 = _hdd_objmgr_get_vdev_by_user(v32, 6, "hdd_update_vdev_nss_chains_config");
              if ( v34 )
              {
                v43 = v34;
                v44 = (_QWORD *)mlme_get_dynamic_vdev_config(v34, v35, v36, v37, v38, v39, v40, v41, v42);
                if ( v44 )
                {
                  v53 = v31[2];
                  v54 = *v31;
                  v44[1] = v31[1];
                  v44[2] = v53;
                  *v44 = v54;
                  v55 = v31[6];
                  v56 = v31[3];
                  v57 = v31[4];
                  v44[5] = v31[5];
                  v44[6] = v55;
                  v44[3] = v56;
                  v44[4] = v57;
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "Updated nss chains config for vdev[%u]",
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    *(unsigned __int8 *)(v32 + 8));
                }
                else
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Unable to get dynamic cfg for vdev[%u]",
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    "hdd_update_vdev_nss_chains_config",
                    *(unsigned __int8 *)(v32 + 8));
                }
                result = _hdd_objmgr_put_vdev_by_user(v43, 6, "hdd_update_vdev_nss_chains_config");
              }
              else
              {
                result = qdf_trace_msg(
                           0x33u,
                           2u,
                           "%s: Null vdev[%u]. Can't update nss chains",
                           v35,
                           v36,
                           v37,
                           v38,
                           v39,
                           v40,
                           v41,
                           v42,
                           "hdd_update_vdev_nss_chains_config",
                           *(unsigned __int8 *)(v32 + 8));
              }
            }
          }
          v32 += 6088;
          v33 += 6088;
        }
        while ( v32 );
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to get user updated cfg for vdev[%u]",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_update_vdev_nss_chains_config",
      *((unsigned __int8 *)a1 + 8));
    return _hdd_objmgr_put_vdev_by_user(v21, 6, "hdd_update_vdev_nss_chains_config");
  }
  return result;
}
