unsigned __int64 __fastcall hdd_sysfs_txrx_stats_store(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
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
  _QWORD *context; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x23
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int8 *v44; // x25
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w22
  __int64 v63; // x20
  char *v64; // x0
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
  __int64 v82; // x4
  __int64 v83; // x5
  __int64 v84; // x6
  __int64 v85; // x7
  unsigned int v86; // w0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int v95; // w20
  __int64 v96; // x21
  __int64 *v97; // [xsp+0h] [xbp-70h] BYREF
  _BYTE v98[4]; // [xsp+8h] [xbp-68h] BYREF
  int v99; // [xsp+Ch] [xbp-64h] BYREF
  char *stringp; // [xsp+10h] [xbp-60h] BYREF
  _QWORD v101[3]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v102; // [xsp+30h] [xbp-40h]
  unsigned __int8 *v103; // [xsp+38h] [xbp-38h]
  _QWORD v104[4]; // [xsp+40h] [xbp-30h] BYREF
  char v105; // [xsp+60h] [xbp-10h]
  __int64 v106; // [xsp+68h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v97 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v97, (__int64)"hdd_sysfs_txrx_stats_store");
  if ( !v7 )
  {
    v105 = 0;
    memset(v104, 0, sizeof(v104));
    context = _cds_get_context(71, (__int64)"__hdd_sysfs_txrx_stats_store", v8, v9, v10, v11, v12, v13, v14, v15);
    v102 = 0;
    v103 = nullptr;
    memset(v101, 0, sizeof(v101));
    v99 = 0;
    v98[0] = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_txrx_stats_store",
                          v17,
                          v18,
                          v19,
                          v20,
                          v21,
                          v22,
                          v23,
                          v24) )
    {
      v33 = *(_QWORD *)(a1 + 1336);
      v34 = _wlan_hdd_validate_context(
              v33,
              (__int64)"__hdd_sysfs_txrx_stats_store",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32);
      if ( v34 )
      {
        a4 = v34;
        goto LABEL_7;
      }
      v44 = *(unsigned __int8 **)(a1 + 54144);
      if ( wlan_hdd_validate_modules_state(v33, v35, v36, v37, v38, v39, v40, v41, v42) )
      {
        v53 = hdd_sysfs_validate_and_copy_buf((__int64)v104, 33, a3, a4, v45, v46, v47, v48, v49, v50, v51, v52);
        if ( v53 )
        {
          v62 = v53;
          v63 = jiffies;
          if ( _hdd_sysfs_txrx_stats_store___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "__hdd_sysfs_txrx_stats_store");
            _hdd_sysfs_txrx_stats_store___last_ticks = v63;
          }
          a4 = v62;
          goto LABEL_7;
        }
        stringp = (char *)v104;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: txrx_stats: count %zu buf_local:(%s) net_devname %s",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "__hdd_sysfs_txrx_stats_store",
          a4,
          v104,
          a1 - 1080);
        v64 = strsep(&stringp, " ");
        if ( v64 )
        {
          if ( !(unsigned int)kstrtouint(v64, 0, &v99) )
          {
            v65 = strsep(&stringp, " ");
            if ( v65 )
            {
              if ( !(unsigned int)kstrtou8(v65, 0, v98) )
              {
                LODWORD(v101[0]) = v99;
                LOBYTE(v102) = v98[0];
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: WE_SET_TXRX_STATS stats cmd: %d mac_id: %d",
                  v66,
                  v67,
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  "__hdd_sysfs_txrx_stats_store");
                if ( context )
                {
                  if ( (v99 == 28 || v99 == 11) && v44[684] )
                  {
                    if ( v44 == (unsigned __int8 *)-308LL )
                    {
                      v84 = 0;
                      v82 = 0;
                      v83 = 0;
                      v85 = 0;
                    }
                    else
                    {
                      v82 = v44[308];
                      v83 = v44[309];
                      v84 = v44[310];
                      v85 = v44[313];
                    }
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: ap mac addr:%02x:%02x:%02x:**:**:%02x",
                      v74,
                      v75,
                      v76,
                      v77,
                      v78,
                      v79,
                      v80,
                      v81,
                      "__hdd_sysfs_txrx_stats_store",
                      v82,
                      v83,
                      v84,
                      v85);
                    v103 = v44 + 308;
                  }
                  v86 = cdp_txrx_stats_request(context, *(unsigned __int8 *)(*(_QWORD *)(a1 + 54144) + 8LL), v101);
                  if ( v86 )
                  {
                    v95 = v86;
                    v96 = jiffies;
                    if ( _hdd_sysfs_txrx_stats_store___last_ticks_8 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to set txrx stats: %d",
                        v87,
                        v88,
                        v89,
                        v90,
                        v91,
                        v92,
                        v93,
                        v94,
                        "__hdd_sysfs_txrx_stats_store",
                        v86);
                      _hdd_sysfs_txrx_stats_store___last_ticks_8 = v96;
                    }
                    a4 = (int)v95;
                  }
                  goto LABEL_7;
                }
              }
            }
          }
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v97, (__int64)"hdd_sysfs_txrx_stats_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
