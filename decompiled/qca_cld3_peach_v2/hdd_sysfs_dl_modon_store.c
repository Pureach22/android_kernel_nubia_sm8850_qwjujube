__int64 __fastcall hdd_sysfs_dl_modon_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
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
  int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w21
  __int64 v45; // x20
  char *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w20
  __int64 v65; // x21
  __int64 *v66; // [xsp+8h] [xbp-48h] BYREF
  unsigned int v67; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v69[4]; // [xsp+20h] [xbp-30h] BYREF
  char v70; // [xsp+40h] [xbp-10h]
  __int64 v71; // [xsp+48h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v66, (__int64)"hdd_sysfs_dl_modon_store");
  if ( !v7 )
  {
    v70 = 0;
    memset(v69, 0, sizeof(v69));
    v67 = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_dl_modon_store",
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
              (__int64)"__hdd_sysfs_dl_modon_store",
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
        v35 = hdd_sysfs_validate_and_copy_buf(v69, 33, a3, a4);
        if ( v35 )
        {
          v44 = v35;
          v45 = jiffies;
          if ( _hdd_sysfs_dl_modon_store___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid input",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              "__hdd_sysfs_dl_modon_store");
            _hdd_sysfs_dl_modon_store___last_ticks = v45;
          }
          a4 = v44;
          goto LABEL_7;
        }
        stringp = (char *)v69;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: dl_modon: count %zu buf_local:(%s) net_devname %s",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "__hdd_sysfs_dl_modon_store",
          a4,
          v69,
          a1 - 1080);
        v46 = strsep(&stringp, " ");
        if ( v46 && !(unsigned int)kstrtouint(v46, 0, &v67) )
        {
          v55 = hdd_sysfs_set_dbg(
                  a1 + 1312,
                  4,
                  (__int64)"WMI_DBGLOG_MODULE_ENABLE",
                  v67,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54);
          if ( v55 )
          {
            v64 = v55;
            v65 = jiffies;
            if ( _hdd_sysfs_dl_modon_store___last_ticks_30 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: failed dl_modon: %d",
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                "__hdd_sysfs_dl_modon_store",
                v55);
              _hdd_sysfs_dl_modon_store___last_ticks_30 = v65;
            }
            a4 = (int)v64;
          }
          goto LABEL_7;
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v66, (__int64)"hdd_sysfs_dl_modon_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
