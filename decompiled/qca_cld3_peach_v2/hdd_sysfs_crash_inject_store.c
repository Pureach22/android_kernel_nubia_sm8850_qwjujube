__int64 __fastcall hdd_sysfs_crash_inject_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
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
  __int64 v25; // x22
  int v26; // w0
  int v28; // w0
  int v29; // w21
  __int64 v30; // x20
  char *v31; // x0
  char *v32; // x0
  unsigned int v33; // w0
  __int64 v34; // x20
  __int64 *v35; // [xsp+8h] [xbp-48h] BYREF
  __int64 v36; // [xsp+10h] [xbp-40h] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v38[4]; // [xsp+20h] [xbp-30h] BYREF
  char v39; // [xsp+40h] [xbp-10h]
  __int64 v40; // [xsp+48h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v35, (__int64)"hdd_sysfs_crash_inject_store");
  if ( !v7 )
  {
    v39 = 0;
    memset(v38, 0, sizeof(v38));
    v36 = 0;
    if ( (unsigned int)_hdd_validate_adapter(
                         a1 + 1312,
                         (__int64)"__hdd_sysfs_crash_inject_store",
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15) )
    {
LABEL_4:
      a4 = -22;
      goto LABEL_5;
    }
    v25 = *(_QWORD *)(a1 + 1336);
    v26 = _wlan_hdd_validate_context(
            v25,
            (__int64)"__hdd_sysfs_crash_inject_store",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23);
    if ( v26 )
    {
      a4 = v26;
    }
    else
    {
      if ( !wlan_hdd_validate_modules_state(v25, v16, v17, v18, v19, v20, v21, v22, v23) )
        goto LABEL_4;
      v28 = hdd_sysfs_validate_and_copy_buf(v38, 33, a3, a4);
      if ( v28 )
      {
        v29 = v28;
        v30 = jiffies;
        if ( _hdd_sysfs_crash_inject_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "__hdd_sysfs_crash_inject_store");
          _hdd_sysfs_crash_inject_store___last_ticks = v30;
        }
        a4 = v29;
        if ( (v29 & 0x8000000000000000LL) == 0 )
          goto LABEL_10;
        goto LABEL_5;
      }
      qdf_trace_msg(
        0x33u,
        4u,
        "crash_inject: count %zu buf_local:(%s) net_devname %s",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        a4,
        v38,
        a1 - 1080);
      stringp = (char *)v38;
      v31 = strsep(&stringp, " ");
      if ( !v31 )
        goto LABEL_4;
      if ( (unsigned int)kstrtouint(v31, 0, (char *)&v36 + 4) )
        goto LABEL_4;
      v32 = strsep(&stringp, " ");
      if ( !v32 || (unsigned int)kstrtouint(v32, 0, &v36) )
        goto LABEL_4;
      v33 = hdd_crash_inject(a1 + 1312, HIDWORD(v36), v36, v16, v17, v18, v19, v20, v21, v22, v23);
      if ( v33 )
      {
        v34 = jiffies;
        if ( _hdd_sysfs_crash_inject_store___last_ticks_7 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: hdd_crash_inject returned %d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "__hdd_sysfs_crash_inject_store",
            v33);
          _hdd_sysfs_crash_inject_store___last_ticks_7 = v34;
        }
        goto LABEL_4;
      }
    }
    if ( (a4 & 0x8000000000000000LL) == 0 )
    {
LABEL_10:
      _osif_vdev_sync_op_stop((__int64)v35, (__int64)"hdd_sysfs_crash_inject_store");
      goto LABEL_11;
    }
LABEL_5:
    v24 = jiffies;
    if ( hdd_sysfs_crash_inject_store___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: errno_size %zd",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_sysfs_crash_inject_store",
        a4);
      hdd_sysfs_crash_inject_store___last_ticks = v24;
    }
    goto LABEL_10;
  }
  a4 = v7;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return a4;
}
