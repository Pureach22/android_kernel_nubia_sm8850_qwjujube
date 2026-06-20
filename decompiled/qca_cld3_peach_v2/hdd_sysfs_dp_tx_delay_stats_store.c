__int64 __fastcall hdd_sysfs_dp_tx_delay_stats_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
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
  _QWORD *context; // x21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w0
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
  __int64 *v64; // [xsp+8h] [xbp-48h] BYREF
  _BYTE v65[4]; // [xsp+14h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v67[4]; // [xsp+20h] [xbp-30h] BYREF
  char v68; // [xsp+40h] [xbp-10h]
  __int64 v69; // [xsp+48h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = nullptr;
  v7 = _osif_vdev_sync_op_start(a1 - 1376, &v64, (__int64)"hdd_sysfs_dp_tx_delay_stats_store");
  if ( v7 )
  {
    v16 = v7;
  }
  else
  {
    v68 = 0;
    memset(v67, 0, sizeof(v67));
    context = _cds_get_context(71, (__int64)"__hdd_sysfs_dp_tx_delay_stats_store", v8, v9, v10, v11, v12, v13, v14, v15);
    v65[0] = 0;
    v16 = -22;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__hdd_sysfs_dp_tx_delay_stats_store",
                          v18,
                          v19,
                          v20,
                          v21,
                          v22,
                          v23,
                          v24,
                          v25)
      && context )
    {
      v34 = _wlan_hdd_validate_context(
              *(_QWORD *)(a1 + 1336),
              (__int64)"__hdd_sysfs_dp_tx_delay_stats_store",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33);
      if ( v34 )
      {
        v16 = v34;
      }
      else if ( wlan_hdd_validate_modules_state(*(_QWORD *)(a1 + 1336), v35, v36, v37, v38, v39, v40, v41, v42) )
      {
        v43 = hdd_sysfs_validate_and_copy_buf(v67, 33, a3, a4);
        if ( v43 )
        {
          v52 = v43;
          v53 = jiffies;
          if ( _hdd_sysfs_dp_tx_delay_stats_store___last_ticks - jiffies + 125 < 0 )
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
              "__hdd_sysfs_dp_tx_delay_stats_store");
            _hdd_sysfs_dp_tx_delay_stats_store___last_ticks = v53;
          }
          v16 = v52;
        }
        else
        {
          stringp = (char *)v67;
          v54 = strsep(&stringp, " ");
          if ( v54 && !(unsigned int)kstrtou8(v54, 0, v65) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: vdev_id: %d tx_delay_stats: %d",
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              "__hdd_sysfs_dp_tx_delay_stats_store",
              *(unsigned __int8 *)(*(_QWORD *)(a1 + 54144) + 8LL),
              v65[0]);
            cdp_enable_disable_vdev_tx_delay_stats(context, *(unsigned __int8 *)(*(_QWORD *)(a1 + 54144) + 8LL), v65[0]);
            v16 = a4;
          }
          else
          {
            v16 = -22;
          }
        }
      }
    }
    _osif_vdev_sync_op_stop((__int64)v64, (__int64)"hdd_sysfs_dp_tx_delay_stats_store");
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
