__int64 __fastcall wlan_connectivity_connecting_event(__int64 result, const void *a2)
{
  __int64 v2; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x0
  __int16 v25; // w10
  size_t v26; // x2
  char *v27; // x0
  __int64 *v28; // x1
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w8
  __int64 *v38; // x9
  __int64 v39; // x8
  __int64 v40; // x0
  char bt_profile_con; // w0
  __int64 v42; // [xsp+10h] [xbp-3A0h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+18h] [xbp-398h]
  __int64 v44; // [xsp+20h] [xbp-390h]
  __int64 v45; // [xsp+28h] [xbp-388h]
  _QWORD v46[4]; // [xsp+30h] [xbp-380h] BYREF
  __int64 v47; // [xsp+50h] [xbp-360h] BYREF
  __int64 v48; // [xsp+58h] [xbp-358h]
  __int64 v49; // [xsp+60h] [xbp-350h] BYREF
  __int64 v50; // [xsp+68h] [xbp-348h] BYREF
  __int64 v51; // [xsp+70h] [xbp-340h]
  __int64 s[103]; // [xsp+78h] [xbp-338h] BYREF

  s[102] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 16) )
    goto LABEL_28;
  v2 = result;
  memset(s, 0, 0x330u);
  v42 = 0;
  time_of_the_day_us = 0;
  v44 = 0;
  v45 = 0;
  memset(v46, 0, sizeof(v46));
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  result = wlan_cm_is_first_candidate_connect_attempt(v2, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( (result & 1) == 0 )
    goto LABEL_28;
  if ( a2 )
  {
    memcpy(s, a2, 0x330u);
    qdf_mem_set(&s[21], 0x10u, 0);
    qdf_mem_set(&s[19], 0x10u, 0);
  }
  else if ( (unsigned int)wlan_cm_get_active_connect_req_param(v2, s, v12, v13, v14, v15, v16, v17, v18, v19) )
  {
    result = qdf_trace_msg(
               0x38u,
               2u,
               "%s: vdev: %d failed to get active cmd request",
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               "wlan_connectivity_connecting_event",
               *(unsigned __int8 *)(v2 + 104));
    goto LABEL_28;
  }
  LOBYTE(v46[0]) = 1;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v24 = ktime_get(time_of_the_day_us, v20, v21, v22, v23);
  v25 = *(unsigned __int8 *)(v2 + 104);
  LODWORD(v49) = 0;
  HIWORD(v42) = v25;
  if ( BYTE4(s[2]) >= 0x20u )
    v26 = 32;
  else
    v26 = BYTE4(s[2]);
  v45 = v24 / 1000;
  BYTE3(v46[0]) = v26;
  qdf_mem_copy((char *)v46 + 4, (char *)&s[2] + 5, v26);
  if ( LODWORD(s[1]) | WORD2(s[1]) )
  {
    v27 = (char *)&v42;
    v28 = &s[1];
  }
  else
  {
    if ( !(*(_DWORD *)((char *)&s[6] + 5) | *(unsigned __int16 *)((char *)&s[7] + 1)) )
      goto LABEL_15;
    v28 = (__int64 *)((char *)&s[6] + 5);
    v27 = (char *)&v47 + 4;
  }
  qdf_mem_copy(v27, v28, 6u);
LABEL_15:
  v37 = HIDWORD(s[7]);
  if ( HIDWORD(s[7]) )
  {
    v38 = (__int64 *)((char *)&v49 + 4);
LABEL_19:
    *(_DWORD *)v38 = v37;
    goto LABEL_20;
  }
  v37 = s[8];
  if ( LODWORD(s[8]) )
  {
    v38 = &v50;
    goto LABEL_19;
  }
LABEL_20:
  HIDWORD(v50) = s[18];
  HIDWORD(v48) = HIDWORD(s[17]);
  LODWORD(v51) = s[17];
  BYTE1(v46[0]) = BYTE4(s[16]);
  if ( LODWORD(s[21]) )
  {
    _qdf_mem_free(s[22]);
    qdf_mem_set(&s[21], 0x10u, 0);
  }
  if ( LODWORD(s[19]) )
  {
    _qdf_mem_free(s[20]);
    qdf_mem_set(&s[19], 0x10u, 0);
  }
  v39 = *(_QWORD *)(v2 + 152);
  if ( v39 )
    v40 = *(_QWORD *)(v39 + 80);
  else
    v40 = 0;
  bt_profile_con = wlan_mlme_get_bt_profile_con(v40);
  BYTE2(v46[0]) = BYTE2(v46[0]) & 0xFE | bt_profile_con & 1;
  result = host_diag_event_report_payload(3351, 104, &v42);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
