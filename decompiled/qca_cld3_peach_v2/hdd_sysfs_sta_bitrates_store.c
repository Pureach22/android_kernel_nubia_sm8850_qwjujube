unsigned __int64 __fastcall hdd_sysfs_sta_bitrates_store(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
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
  __int64 v24; // x22
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
  int v52; // w21
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
  int v64; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int v73; // w20
  __int64 v74; // x21
  int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x21
  int v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x21
  __int64 *v95; // [xsp+8h] [xbp-48h] BYREF
  __int64 v96; // [xsp+10h] [xbp-40h] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v98[4]; // [xsp+20h] [xbp-30h] BYREF
  char v99; // [xsp+40h] [xbp-10h]
  __int64 v100; // [xsp+48h] [xbp-8h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v95, (__int64)"hdd_sysfs_sta_bitrates_store");
  if ( !v7 )
  {
    v99 = 0;
    memset(v98, 0, sizeof(v98));
    v96 = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_sta_bitrates_store",
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
              (__int64)"__hdd_sysfs_sta_bitrates_store",
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
        v43 = hdd_sysfs_validate_and_copy_buf((__int64)v98, 33, a3, a4, v35, v36, v37, v38, v39, v40, v41, v42);
        if ( v43 )
        {
          v52 = v43;
          v53 = jiffies;
          if ( _hdd_sysfs_sta_bitrates_store___last_ticks - jiffies + 125 < 0 )
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
              "__hdd_sysfs_sta_bitrates_store");
            _hdd_sysfs_sta_bitrates_store___last_ticks = v53;
          }
          a4 = v52;
          goto LABEL_7;
        }
        stringp = (char *)v98;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: sta_bitrates: count %zu buf_local:(%s)",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "__hdd_sysfs_sta_bitrates_store",
          a4,
          v98);
        v54 = strsep(&stringp, " ");
        if ( v54 )
        {
          if ( !(unsigned int)kstrtoint(v54, 0, (char *)&v96 + 4) )
          {
            v55 = strsep(&stringp, " ");
            if ( v55 )
            {
              if ( !(unsigned int)kstrtoint(v55, 0, &v96) )
              {
                switch ( HIDWORD(v96) )
                {
                  case 2:
                    v85 = hdd_set_11ax_rate(a1 + 1312, v96, 0, v56, v57, v58, v59, v60, v61, v62, v63);
                    if ( !v85 )
                      goto LABEL_7;
                    v73 = v85;
                    v94 = jiffies;
                    if ( _hdd_sysfs_sta_bitrates_store___last_ticks_11 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to set 11ax rates",
                        v86,
                        v87,
                        v88,
                        v89,
                        v90,
                        v91,
                        v92,
                        v93,
                        "__hdd_sysfs_sta_bitrates_store");
                      _hdd_sysfs_sta_bitrates_store___last_ticks_11 = v94;
                    }
                    goto LABEL_30;
                  case 1:
                    v75 = wlan_hdd_sta_set_vht_rate(a1 + 1312, (unsigned int)v96);
                    if ( !v75 )
                      goto LABEL_7;
                    v73 = v75;
                    v84 = jiffies;
                    if ( _hdd_sysfs_sta_bitrates_store___last_ticks_9 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to set 11ac rates",
                        v76,
                        v77,
                        v78,
                        v79,
                        v80,
                        v81,
                        v82,
                        v83,
                        "__hdd_sysfs_sta_bitrates_store");
                      _hdd_sysfs_sta_bitrates_store___last_ticks_9 = v84;
                    }
                    goto LABEL_30;
                  case 0:
                    v64 = wlan_hdd_sta_set_11n_rate(a1 + 1312, (unsigned int)v96);
                    if ( !v64 )
                      goto LABEL_7;
                    v73 = v64;
                    v74 = jiffies;
                    if ( _hdd_sysfs_sta_bitrates_store___last_ticks_7 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to set 11n rates",
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        v71,
                        v72,
                        "__hdd_sysfs_sta_bitrates_store");
                      _hdd_sysfs_sta_bitrates_store___last_ticks_7 = v74;
                    }
LABEL_30:
                    a4 = v73;
                    goto LABEL_7;
                }
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Invalid rate mode %u",
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  "__hdd_sysfs_sta_bitrates_store");
              }
            }
          }
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v95, (__int64)"hdd_sysfs_sta_bitrates_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
