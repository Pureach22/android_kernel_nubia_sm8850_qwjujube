_QWORD *__fastcall hdd_cm_update_rssi_snr_by_bssid(
        _QWORD *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  _BYTE *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x5
  __int64 v21; // x21
  char v22; // w8
  char v23; // w9
  __int64 v24; // x20
  __int64 v25; // x20
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *result;
  v26[0] = 0;
  if ( v9 )
  {
    v10 = *(_QWORD *)(v9 + 24);
    if ( v10 && (v11 = result, (result = *(_QWORD **)(v10 + 16)) != nullptr) )
    {
      hdd_get_rssi_snr_by_bssid(result, v11 + 300, v11 + 2416, v26);
      v20 = (unsigned int)(char)v11[2416];
      if ( (int)v20 >= 1 )
      {
        v21 = jiffies;
        if ( hdd_cm_update_rssi_snr_by_bssid___last_ticks_6 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: RSSI invalid %d",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "hdd_cm_update_rssi_snr_by_bssid",
            (unsigned int)v20);
          hdd_cm_update_rssi_snr_by_bssid___last_ticks_6 = v21;
        }
        v20 = 0;
        v11[2416] = 0;
      }
      result = (_QWORD *)qdf_trace_msg(
                           0x33u,
                           8u,
                           "%s: snr: %d, rssi: %d",
                           v12,
                           v13,
                           v14,
                           v15,
                           v16,
                           v17,
                           v18,
                           v19,
                           "hdd_cm_update_rssi_snr_by_bssid",
                           v26[0],
                           v20);
      v22 = v11[2416];
      v23 = v22 - v26[0];
      v11[832] = v22;
      v11[1512] = v22;
      v11[724] = v23;
      v11[1404] = v23;
    }
    else
    {
      v24 = jiffies;
      if ( hdd_cm_update_rssi_snr_by_bssid___last_ticks_4 - jiffies + 125 < 0 )
      {
        result = (_QWORD *)qdf_trace_msg(
                             0x33u,
                             2u,
                             "%s: null mac_handle pointer",
                             a2,
                             a3,
                             a4,
                             a5,
                             a6,
                             a7,
                             a8,
                             a9,
                             "hdd_cm_update_rssi_snr_by_bssid");
        hdd_cm_update_rssi_snr_by_bssid___last_ticks_4 = v24;
      }
    }
  }
  else
  {
    v25 = jiffies;
    if ( hdd_cm_update_rssi_snr_by_bssid___last_ticks - jiffies + 125 < 0 )
    {
      result = (_QWORD *)qdf_trace_msg(
                           0x33u,
                           2u,
                           "%s: null hdd_adapter pointer",
                           a2,
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           "hdd_cm_update_rssi_snr_by_bssid");
      hdd_cm_update_rssi_snr_by_bssid___last_ticks = v25;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
