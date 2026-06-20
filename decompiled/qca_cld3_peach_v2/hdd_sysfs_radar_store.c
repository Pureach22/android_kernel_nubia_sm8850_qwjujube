unsigned __int64 __fastcall hdd_sysfs_radar_store(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
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
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 *v25; // x20
  int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w22
  __int64 v54; // x20
  char *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x21
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 *v81; // [xsp+8h] [xbp-78h] BYREF
  unsigned int v82; // [xsp+14h] [xbp-6Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-68h] BYREF
  _QWORD v84[6]; // [xsp+20h] [xbp-60h] BYREF
  _QWORD v85[4]; // [xsp+50h] [xbp-30h] BYREF
  char v86; // [xsp+70h] [xbp-10h]
  __int64 v87; // [xsp+78h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v81, (__int64)"hdd_sysfs_radar_store");
  if ( !v7 )
  {
    v16 = *(_QWORD *)(a1 + 54144);
    v86 = 0;
    memset(v85, 0, sizeof(v85));
    memset(v84, 0, sizeof(v84));
    v82 = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_radar_store",
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15) )
    {
      v25 = *(__int64 **)(a1 + 1336);
      v26 = _wlan_hdd_validate_context(
              (__int64)v25,
              (__int64)"__hdd_sysfs_radar_store",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24);
      if ( v26 )
      {
        a4 = v26;
        goto LABEL_7;
      }
      if ( wlan_hdd_validate_modules_state((__int64)v25, v27, v28, v29, v30, v31, v32, v33, v34) )
      {
        v44 = hdd_sysfs_validate_and_copy_buf((__int64)v85, 33, a3, a4, v36, v37, v38, v39, v40, v41, v42, v43);
        if ( v44 )
        {
          v53 = v44;
          v54 = jiffies;
          if ( _hdd_sysfs_radar_store___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "__hdd_sysfs_radar_store");
            _hdd_sysfs_radar_store___last_ticks = v54;
          }
          a4 = v53;
          goto LABEL_7;
        }
        stringp = (char *)v85;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: set_radar: count %zu buf_local:(%s) net_devname %s",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "__hdd_sysfs_radar_store",
          a4,
          v85,
          a1 - 1080);
        v55 = strsep(&stringp, " ");
        if ( v55 )
        {
          if ( !(unsigned int)kstrtouint(v55, 0, &v82) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Set QCASAP_SET_RADAR_CMD val %d",
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              "__hdd_sysfs_radar_store",
              v82);
            v72 = v25[1];
            if ( v72 )
            {
              qdf_mem_set(v84, 0x30u, 0);
              if ( (unsigned int)policy_mgr_get_dfs_beaconing_session_id(*v25) == 255 )
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Ignore set radar, op ch_freq(%d) is not dfs",
                  v73,
                  v74,
                  v75,
                  v76,
                  v77,
                  v78,
                  v79,
                  v80,
                  "__hdd_sysfs_radar_store",
                  *(unsigned int *)(v16 + 2424));
              else
                tgt_dfs_process_radar_ind(v72, (__int64)v84, v73, v74, v75, v76, v77, v78, v79, v80);
              goto LABEL_7;
            }
            qdf_trace_msg(0x33u, 2u, "%s: null pdev", v64, v65, v66, v67, v68, v69, v70, v71, "__hdd_sysfs_radar_store");
          }
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v81, (__int64)"hdd_sysfs_radar_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
