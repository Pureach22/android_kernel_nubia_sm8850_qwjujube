unsigned __int64 __fastcall hdd_sysfs_monitor_mode_channel_store(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4)
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
  __int64 v24; // x21
  int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w22
  __int64 v53; // x20
  char *v54; // x0
  char *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w1
  char *v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  char *v82; // x0
  unsigned int v83; // w1
  __int64 *v84; // [xsp+0h] [xbp-70h] BYREF
  __int64 v85; // [xsp+8h] [xbp-68h] BYREF
  __int64 v86; // [xsp+10h] [xbp-60h] BYREF
  char *stringp; // [xsp+18h] [xbp-58h] BYREF
  _QWORD v88[2]; // [xsp+20h] [xbp-50h] BYREF
  unsigned __int64 v89; // [xsp+30h] [xbp-40h]
  __int64 v90; // [xsp+38h] [xbp-38h]
  _QWORD v91[4]; // [xsp+40h] [xbp-30h] BYREF
  char v92; // [xsp+60h] [xbp-10h]
  __int64 v93; // [xsp+68h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v84, (__int64)"hdd_sysfs_monitor_mode_channel_store");
  if ( !v7 )
  {
    v92 = 0;
    memset(v91, 0, sizeof(v91));
    v89 = 0;
    v90 = 0;
    v88[0] = 0;
    v88[1] = 0;
    v85 = 0;
    v86 = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_monitor_mode_channel_store",
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15) )
    {
      v24 = *(_QWORD *)(a1 + 1336);
      v25 = _wlan_hdd_validate_context(
              v24,
              (__int64)"__hdd_sysfs_monitor_mode_channel_store",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23);
      if ( v25 )
      {
        a4 = v25;
        goto LABEL_7;
      }
      if ( wlan_hdd_validate_modules_state(v24, v26, v27, v28, v29, v30, v31, v32, v33) )
      {
        v43 = hdd_sysfs_validate_and_copy_buf((__int64)v91, 33, a3, a4, v35, v36, v37, v38, v39, v40, v41, v42);
        if ( v43 )
        {
          v52 = v43;
          v53 = jiffies;
          if ( _hdd_sysfs_monitor_mode_channel_store___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "__hdd_sysfs_monitor_mode_channel_store");
            _hdd_sysfs_monitor_mode_channel_store___last_ticks = v53;
          }
          a4 = v52;
          goto LABEL_7;
        }
        stringp = (char *)v91;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: set_mon_chan: count %zu buf_local:(%s) net_devname %s",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "__hdd_sysfs_monitor_mode_channel_store",
          a4,
          v91,
          a1 - 1080);
        v54 = strsep(&stringp, " ");
        if ( v54 )
        {
          if ( !(unsigned int)kstrtouint(v54, 0, (char *)&v86 + 4) )
          {
            v55 = strsep(&stringp, " ");
            if ( v55 )
            {
              if ( !(unsigned int)kstrtouint(v55, 0, &v86) )
              {
                v64 = HIDWORD(v86);
                if ( HIDWORD(v86) )
                {
                  if ( HIDWORD(v86) <= 0x100 )
                    v64 = wlan_reg_legacy_chan_to_freq(
                            *(_QWORD *)(v24 + 8),
                            HIDWORD(v86),
                            v56,
                            v57,
                            v58,
                            v59,
                            v60,
                            v61,
                            v62,
                            v63);
                  v88[0] = __PAIR64__(v86, v64);
                  v65 = strsep(&stringp, " ");
                  if ( !v65 )
                    goto LABEL_23;
                  if ( (unsigned int)kstrtouint(v65, 0, (char *)&v85 + 4) )
                    goto LABEL_23;
                  v82 = strsep(&stringp, " ");
                  if ( !v82 || (unsigned int)kstrtouint(v82, 0, &v85) )
                    goto LABEL_23;
                  v83 = HIDWORD(v85);
                  if ( HIDWORD(v85) )
                  {
                    if ( HIDWORD(v85) <= 0x100 )
                      v83 = wlan_reg_legacy_chan_to_freq(
                              *(_QWORD *)(v24 + 8),
                              HIDWORD(v85),
                              v66,
                              v67,
                              v68,
                              v69,
                              v70,
                              v71,
                              v72,
                              v73);
                    v89 = __PAIR64__(v85, v83);
LABEL_23:
                    if ( !(unsigned int)wlan_hdd_validate_mon_params(
                                          a1 + 1312,
                                          (unsigned int *)v88,
                                          2u,
                                          v66,
                                          v67,
                                          v68,
                                          v69,
                                          v70,
                                          v71,
                                          v72,
                                          v73) )
                      wlan_hdd_set_mon_chan(a1 + 1312, v74, v75, v76, v77, v78, v79, v80, v81);
                    goto LABEL_7;
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
    _osif_vdev_sync_op_stop((__int64)v84, (__int64)"hdd_sysfs_monitor_mode_channel_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
