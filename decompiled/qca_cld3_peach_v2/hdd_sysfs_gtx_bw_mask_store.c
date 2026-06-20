__int64 __fastcall hdd_sysfs_gtx_bw_mask_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
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
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w20
  __int64 v57; // x21
  __int64 *v58; // [xsp+8h] [xbp-48h] BYREF
  unsigned int v59; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v61[4]; // [xsp+20h] [xbp-30h] BYREF
  char v62; // [xsp+40h] [xbp-10h]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v58, (__int64)"hdd_sysfs_gtx_bw_mask_store");
  if ( !v7 )
  {
    v62 = 0;
    memset(v61, 0, sizeof(v61));
    v59 = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_gtx_bw_mask_store",
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
              (__int64)"__hdd_sysfs_gtx_bw_mask_store",
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
        v35 = hdd_sysfs_validate_and_copy_buf(v61, 33, a3, a4);
        if ( v35 )
        {
          v44 = v35;
          v45 = jiffies;
          if ( _hdd_sysfs_gtx_bw_mask_store___last_ticks - jiffies + 125 < 0 )
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
              "__hdd_sysfs_gtx_bw_mask_store");
            _hdd_sysfs_gtx_bw_mask_store___last_ticks = v45;
          }
          a4 = v44;
          goto LABEL_7;
        }
        stringp = (char *)v61;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: gtx_bw_mask: count %zu buf_local:(%s) net_devname %s",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "__hdd_sysfs_gtx_bw_mask_store",
          a4,
          v61,
          a1 - 1080);
        v46 = strsep(&stringp, " ");
        if ( v46 && !(unsigned int)kstrtouint(v46, 0, &v59) )
        {
          v47 = hdd_sysfs_set_green_tx_param(a1 + 1312, v59);
          if ( v47 )
          {
            v56 = v47;
            v57 = jiffies;
            if ( _hdd_sysfs_gtx_bw_mask_store___last_ticks_10 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: failed to set green tx BW Mask: %d",
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                "__hdd_sysfs_gtx_bw_mask_store",
                v47);
              _hdd_sysfs_gtx_bw_mask_store___last_ticks_10 = v57;
            }
            a4 = (int)v56;
          }
          goto LABEL_7;
        }
      }
    }
    a4 = -22;
LABEL_7:
    _osif_vdev_sync_op_stop((__int64)v58, (__int64)"hdd_sysfs_gtx_bw_mask_store");
    goto LABEL_8;
  }
  a4 = v7;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
