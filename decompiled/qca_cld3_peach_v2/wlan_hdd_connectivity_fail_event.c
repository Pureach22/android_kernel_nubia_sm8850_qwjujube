__int64 __fastcall wlan_hdd_connectivity_fail_event(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  int v23; // w9
  unsigned int v24; // w8
  __int16 v25; // w8
  __int64 v26; // [xsp+0h] [xbp-70h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-68h]
  __int64 v28; // [xsp+10h] [xbp-60h]
  __int64 v29; // [xsp+18h] [xbp-58h]
  __int64 v30; // [xsp+20h] [xbp-50h]
  __int64 v31; // [xsp+28h] [xbp-48h]
  __int64 v32; // [xsp+30h] [xbp-40h]
  __int64 v33; // [xsp+38h] [xbp-38h]
  __int64 v34; // [xsp+40h] [xbp-30h]
  __int64 v35; // [xsp+48h] [xbp-28h]
  __int64 v36; // [xsp+50h] [xbp-20h]
  __int64 v37; // [xsp+58h] [xbp-18h]
  __int64 v38; // [xsp+60h] [xbp-10h]
  __int64 v39; // [xsp+68h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  time_of_the_day_us = 0;
  v28 = 0;
  v26 = 0;
  result = (__int64)qdf_mem_set(&v26, 0x68u, 0);
  if ( !*(_DWORD *)(a1 + 16) )
  {
    result = wlan_vdev_mlme_is_mlo_vdev(a1, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( (result & 1) == 0 || (*(_BYTE *)(a1 + 67) & 2) == 0 && (*(_BYTE *)(a1 + 60) & 2) == 0 )
    {
      HIWORD(v26) = *(unsigned __int8 *)(a1 + 168);
      time_of_the_day_us = qdf_get_time_of_the_day_us();
      v13 = ktime_get(time_of_the_day_us);
      LODWORD(v36) = 1;
      v29 = v13 / 1000;
      qdf_mem_copy(&v26, a2 + 2, 6u);
      v22 = a2[14];
      v23 = a2[12];
      LOBYTE(v30) = 1;
      v24 = v22 - 1;
      HIDWORD(v36) = v23;
      if ( v24 >= 0xF )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid connect fail reason code",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_hdd_convert_con_fail_reason_to_diag_reason");
        v25 = 0;
      }
      else
      {
        v25 = v24 + 1;
      }
      WORD1(v35) = v25;
      result = host_diag_event_report_payload(3351, 104, &v26);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
