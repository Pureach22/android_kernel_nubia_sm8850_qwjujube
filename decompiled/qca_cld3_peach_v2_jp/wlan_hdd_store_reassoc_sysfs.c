__int64 __fastcall wlan_hdd_store_reassoc_sysfs(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int operation_chan_freq; // w22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 *v51; // [xsp+8h] [xbp-18h] BYREF
  int v52; // [xsp+10h] [xbp-10h] BYREF
  __int16 v53; // [xsp+14h] [xbp-Ch]
  __int64 v54; // [xsp+18h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = nullptr;
  v6 = _osif_vdev_sync_op_start(a1 - 1376, &v51, (__int64)"wlan_hdd_store_reassoc_sysfs");
  if ( !v6 )
  {
    v53 = 0;
    v52 = 0;
    if ( !(unsigned int)_hdd_validate_adapter(
                          a1 + 1312,
                          (__int64)"__wlan_hdd_store_reassoc_sysfs",
                          v7,
                          v8,
                          v9,
                          v10,
                          v11,
                          v12,
                          v13,
                          v14) )
    {
      v23 = *(_QWORD *)(a1 + 1336);
      v24 = _wlan_hdd_validate_context(
              v23,
              (__int64)"__wlan_hdd_store_reassoc_sysfs",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22);
      if ( v24 )
      {
        a4 = v24;
        goto LABEL_9;
      }
      if ( wlan_hdd_validate_modules_state(v23, v25, v26, v27, v28, v29, v30, v31, v32) )
      {
        operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq(*(unsigned __int16 **)(*(_QWORD *)(a1 + 54136)
                                                                                              + 32LL));
        wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(v23 + 8), *(_BYTE *)(*(_QWORD *)(a1 + 54136) + 8LL), &v52);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: reassoc: net_devname %s",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "__wlan_hdd_store_reassoc_sysfs",
          a1 - 1080);
        ucfg_wlan_cm_roam_invoke(
          *(_QWORD *)(v23 + 8),
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 54136) + 8LL),
          (unsigned __int8 *)&v52,
          operation_chan_freq,
          0x13u,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49);
        goto LABEL_9;
      }
    }
    a4 = -22;
LABEL_9:
    _osif_vdev_sync_op_stop((__int64)v51, (__int64)"wlan_hdd_store_reassoc_sysfs");
    goto LABEL_10;
  }
  a4 = v6;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return a4;
}
