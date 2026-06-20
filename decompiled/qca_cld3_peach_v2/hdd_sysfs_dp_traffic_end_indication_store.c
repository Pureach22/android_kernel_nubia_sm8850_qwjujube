__int64 __fastcall hdd_sysfs_dp_traffic_end_indication_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w21
  char *v44; // x0
  char *v45; // x0
  char *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x21
  __int64 vdev_by_user; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w6
  __int64 v66; // x20
  __int64 v67; // x7
  __int64 v68; // x9
  bool v69; // zf
  unsigned __int64 v70; // x8
  unsigned __int64 v71; // x21
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int *v80; // x8
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 *v89; // [xsp+0h] [xbp-50h] BYREF
  _BYTE v90[4]; // [xsp+Ch] [xbp-44h] BYREF
  _BYTE v91[4]; // [xsp+10h] [xbp-40h] BYREF
  _BYTE v92[4]; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v94[4]; // [xsp+20h] [xbp-30h] BYREF
  char v95; // [xsp+40h] [xbp-10h]
  __int64 v96; // [xsp+48h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v89 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v89, (__int64)"hdd_sysfs_dp_traffic_end_indication_store");
  if ( !v7 )
  {
    v95 = 0;
    memset(v94, 0, sizeof(v94));
    v92[0] = 0;
    v91[0] = 0;
    v90[0] = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_dp_traffic_end_indication_store",
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15) )
    {
      v24 = _wlan_hdd_validate_context(
              *(_QWORD *)(a1 + 1336),
              (__int64)"__hdd_sysfs_dp_traffic_end_indication_store",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23);
      if ( v24 )
      {
        a4 = v24;
        goto LABEL_7;
      }
      if ( wlan_hdd_validate_modules_state(*(_QWORD *)(a1 + 1336), v25, v26, v27, v28, v29, v30, v31, v32) )
      {
        v34 = hdd_sysfs_validate_and_copy_buf(v94, 33, a3, a4);
        if ( v34 )
        {
          v43 = v34;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "__hdd_sysfs_dp_traffic_end_indication_store");
          a4 = v43;
          goto LABEL_7;
        }
        stringp = (char *)v94;
        v44 = strsep(&stringp, " ");
        if ( v44 )
        {
          if ( !(unsigned int)kstrtou8(v44, 0, v92) )
          {
            v45 = strsep(&stringp, " ");
            if ( v45 )
            {
              if ( !(unsigned int)kstrtou8(v45, 0, v91) )
              {
                v46 = strsep(&stringp, " ");
                if ( v46 )
                {
                  if ( !(unsigned int)kstrtou8(v46, 0, v90) )
                  {
                    if ( v91[0] > 0x3Fu || v90[0] >= 0x40u )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: invalid dscp value",
                        v47,
                        v48,
                        v49,
                        v50,
                        v51,
                        v52,
                        v53,
                        v54,
                        "__hdd_sysfs_dp_traffic_end_indication_store");
                    }
                    else
                    {
                      v55 = a1 + 53248;
                      vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                                       *(_QWORD *)(a1 + 54144),
                                       0x61u,
                                       (__int64)"__hdd_sysfs_dp_traffic_end_indication_store");
                      if ( vdev_by_user )
                      {
                        v65 = v91[0];
                        v66 = vdev_by_user;
                        v67 = v90[0];
                        v68 = *(_QWORD *)(v55 + 896);
                        v69 = v92[0] == 0;
                        *(_BYTE *)(v55 + 888) = v92[0] != 0;
                        v70 = ((unsigned __int64)v65 << 8) | (v67 << 16);
                        if ( v69 )
                          v70 = 0;
                        if ( v69 )
                          v71 = v70;
                        else
                          v71 = v70 + 1;
                        qdf_trace_msg(
                          0x33u,
                          8u,
                          "%s: vdev_id:%u traffic end indication:%u defdscp:%u spldscp:%u",
                          v57,
                          v58,
                          v59,
                          v60,
                          v61,
                          v62,
                          v63,
                          v64,
                          "__hdd_sysfs_dp_traffic_end_indication_store",
                          *(unsigned __int8 *)(v68 + 8));
                        ucfg_dp_traffic_end_indication_set(v66, v71, v72, v73, v74, v75, v76, v77, v78, v79);
                        wlan_objmgr_vdev_release_ref(v66, 0x61u, v80, v81, v82, v83, v84, v85, v86, v87, v88);
                        goto LABEL_7;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v89, (__int64)"hdd_sysfs_dp_traffic_end_indication_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
