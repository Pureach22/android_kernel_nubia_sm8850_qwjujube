unsigned __int64 __fastcall hdd_sysfs_rts_cts_store(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
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
  __int64 *v24; // x21
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
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w4
  unsigned int rts_threshold; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x20
  unsigned int v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w20
  __int64 v84; // x21
  __int64 v85; // x20
  unsigned int v86; // w0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x20
  __int64 *v96; // [xsp+8h] [xbp-48h] BYREF
  __int64 v97; // [xsp+10h] [xbp-40h] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v99[4]; // [xsp+20h] [xbp-30h] BYREF
  char v100; // [xsp+40h] [xbp-10h]
  __int64 v101; // [xsp+48h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v96 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v96, (__int64)"hdd_sysfs_rts_cts_store");
  if ( !v7 )
  {
    v100 = 0;
    memset(v99, 0, sizeof(v99));
    v97 = 0;
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_rts_cts_store",
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15) )
      goto LABEL_4;
    v24 = *(__int64 **)(a1 + 1336);
    v25 = _wlan_hdd_validate_context(
            (__int64)v24,
            (__int64)"__hdd_sysfs_rts_cts_store",
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
    if ( !wlan_hdd_validate_modules_state((__int64)v24, v26, v27, v28, v29, v30, v31, v32, v33) )
      goto LABEL_4;
    v43 = hdd_sysfs_validate_and_copy_buf((__int64)v99, 33, a3, a4, v35, v36, v37, v38, v39, v40, v41, v42);
    if ( v43 )
    {
      v52 = v43;
      v53 = jiffies;
      if ( _hdd_sysfs_rts_cts_store___last_ticks - jiffies + 125 < 0 )
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
          "__hdd_sysfs_rts_cts_store");
        _hdd_sysfs_rts_cts_store___last_ticks = v53;
      }
      a4 = v52;
      goto LABEL_7;
    }
    stringp = (char *)v99;
    v54 = strsep(&stringp, " ");
    if ( !v54 || (unsigned int)kstrtouint(v54, 0, &v97) )
      goto LABEL_4;
    v63 = v97;
    if ( !(_DWORD)v97 || (_DWORD)v97 == 2 )
    {
      HIDWORD(v97) = 0x100000;
    }
    else
    {
      if ( (_DWORD)v97 != 1 )
      {
        v85 = jiffies;
        if ( _hdd_sysfs_rts_cts_store___last_ticks_7 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid value %d",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "__hdd_sysfs_rts_cts_store");
          _hdd_sysfs_rts_cts_store___last_ticks_7 = v85;
        }
        goto LABEL_4;
      }
      rts_threshold = wlan_mlme_get_rts_threshold(*v24, (_DWORD *)&v97 + 1);
      if ( rts_threshold )
      {
        v73 = jiffies;
        if ( _hdd_sysfs_rts_cts_store___last_ticks_5 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Get rts threshold failed, status %d",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "__hdd_sysfs_rts_cts_store",
            rts_threshold);
          _hdd_sysfs_rts_cts_store___last_ticks_5 = v73;
        }
        goto LABEL_4;
      }
      v63 = v97;
    }
    v74 = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 54144) + 8LL), 44, v63, 1);
    if ( v74 )
    {
      v83 = v74;
      v84 = jiffies;
      if ( _hdd_sysfs_rts_cts_store___last_ticks_9 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to set firmware, ret %d",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "__hdd_sysfs_rts_cts_store",
          v74);
        _hdd_sysfs_rts_cts_store___last_ticks_9 = v84;
      }
      a4 = (int)v83;
      goto LABEL_7;
    }
    v86 = wlan_mlme_set_rts_threshold(*v24, HIDWORD(v97));
    if ( !v86 )
    {
LABEL_7:
      _osif_vdev_sync_op_stop((__int64)v96, (__int64)"hdd_sysfs_rts_cts_store");
      goto LABEL_8;
    }
    v95 = jiffies;
    if ( _hdd_sysfs_rts_cts_store___last_ticks_11 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Set rts threshold failed, status %d",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "__hdd_sysfs_rts_cts_store",
        v86);
      _hdd_sysfs_rts_cts_store___last_ticks_11 = v95;
    }
LABEL_4:
    a4 = -22;
    goto LABEL_7;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
