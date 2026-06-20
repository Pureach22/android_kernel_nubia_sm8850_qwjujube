__int64 __fastcall cm_roam_reject_reassoc_event(int a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned int v6; // w19
  __int64 result; // x0
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x21
  int v11; // w8
  __int64 entry_by_bssid; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x23
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned __int16 *v24; // x8
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x0
  _BYTE v30[4]; // [xsp+Ch] [xbp-54h] BYREF
  _QWORD v31[4]; // [xsp+10h] [xbp-50h] BYREF
  __int64 v32; // [xsp+30h] [xbp-30h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+38h] [xbp-28h]
  __int64 v34; // [xsp+40h] [xbp-20h]
  __int64 v35; // [xsp+48h] [xbp-18h]
  int v36; // [xsp+50h] [xbp-10h]
  __int64 v37; // [xsp+58h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a2 + 104);
  memset(v31, 0, sizeof(v31));
  v30[0] = 0;
  result = _qdf_mem_malloc(0xD0u, "cm_roam_reject_reassoc_event", 7337);
  if ( result )
  {
    v8 = result;
    v9 = _qdf_mem_malloc(0x2A8u, "cm_roam_reject_reassoc_event", 7341);
    if ( v9 )
    {
      v10 = v9;
      *(_BYTE *)v8 = 1;
      *(_DWORD *)(v8 + 4) = 9;
      cm_get_rssi_snr_by_bssid(*(_QWORD *)(a2 + 152), a3, v30, 0);
      v11 = v30[0];
      if ( v30[0] < 0 )
        v11 = -v30[0];
      *(_DWORD *)(v8 + 12) = v11;
      wlan_cm_roam_cfg_get_value(a1, v6, 13, (int)v31);
      *(_DWORD *)(v8 + 20) = v31[0];
      entry_by_bssid = wlan_scan_get_entry_by_bssid(*(_QWORD *)(a2 + 152), a3);
      if ( entry_by_bssid )
      {
        v21 = entry_by_bssid;
        *(_DWORD *)(v10 + 108) = *(unsigned __int8 *)(entry_by_bssid + 83);
        v22 = *(_QWORD *)(entry_by_bssid + 1192);
        if ( v22 )
          _qdf_mem_free(v22);
        v23 = *(_QWORD *)(v21 + 1712);
        if ( v23 )
          _qdf_mem_free(v23);
        _qdf_mem_free(v21);
        v24 = *(unsigned __int16 **)(a2 + 32);
        if ( v24 )
          goto LABEL_11;
      }
      else
      {
        *(_DWORD *)(v10 + 108) = 0;
        v24 = *(unsigned __int16 **)(a2 + 32);
        if ( v24 )
        {
LABEL_11:
          *(_BYTE *)(v10 + 677) = wlan_convert_freq_to_diag_band(*v24);
LABEL_15:
          cm_roam_trigger_info_event(v8, (unsigned __int8 *)v10, v6, 0);
          _qdf_mem_free(v8);
          _qdf_mem_free(v10);
          v36 = 0;
          v34 = 0;
          v35 = 0;
          v32 = 0;
          time_of_the_day_us = 0;
          qdf_mem_set(&v32, 0x24u, 0);
          HIWORD(v32) = v6;
          time_of_the_day_us = qdf_get_time_of_the_day_us();
          v29 = ktime_get(time_of_the_day_us, v25, v26, v27, v28);
          LOBYTE(v36) = 2;
          v34 = 0;
          v35 = v29 / 1000;
          HIWORD(v36) = 39;
          result = host_diag_event_report_payload(3360, 36, &v32);
          goto LABEL_16;
        }
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev:%d bss_chan is null",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "cm_roam_reject_reassoc_event",
        v6);
      goto LABEL_15;
    }
    result = _qdf_mem_free(v8);
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
