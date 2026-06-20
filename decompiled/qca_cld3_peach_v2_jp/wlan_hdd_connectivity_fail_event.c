void *__fastcall wlan_hdd_connectivity_fail_event(__int64 a1, _DWORD *a2)
{
  void *result; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w8
  int v19; // w9
  unsigned int v20; // w8
  __int16 v21; // w8
  __int64 v22; // [xsp+0h] [xbp-70h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-68h]
  __int64 v24; // [xsp+10h] [xbp-60h]
  __int64 v25; // [xsp+18h] [xbp-58h]
  __int64 v26; // [xsp+20h] [xbp-50h]
  __int64 v27; // [xsp+28h] [xbp-48h]
  __int64 v28; // [xsp+30h] [xbp-40h]
  __int64 v29; // [xsp+38h] [xbp-38h]
  __int64 v30; // [xsp+40h] [xbp-30h]
  __int64 v31; // [xsp+48h] [xbp-28h]
  __int64 v32; // [xsp+50h] [xbp-20h]
  __int64 v33; // [xsp+58h] [xbp-18h]
  __int64 v34; // [xsp+60h] [xbp-10h]
  __int64 v35; // [xsp+68h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  time_of_the_day_us = 0;
  v24 = 0;
  v22 = 0;
  result = qdf_mem_set(&v22, 0x68u, 0);
  if ( !*(_DWORD *)(a1 + 16) )
  {
    HIWORD(v22) = *(unsigned __int8 *)(a1 + 104);
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    v9 = ktime_get(time_of_the_day_us, v5, v6, v7, v8);
    LODWORD(v32) = 1;
    v25 = v9 / 1000;
    qdf_mem_copy(&v22, a2 + 2, 6u);
    v18 = a2[14];
    v19 = a2[12];
    LOBYTE(v26) = 1;
    v20 = v18 - 1;
    HIDWORD(v32) = v19;
    if ( v20 >= 0xF )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid connect fail reason code",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_hdd_convert_con_fail_reason_to_diag_reason");
      v21 = 0;
    }
    else
    {
      v21 = v20 + 1;
    }
    WORD1(v31) = v21;
    result = (void *)host_diag_event_report_payload(3351, 104, &v22);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
