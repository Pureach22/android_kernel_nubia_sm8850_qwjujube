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
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  __int16 v29; // w10
  size_t v30; // x2
  char *v31; // x0
  __int64 *v32; // x1
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w8
  __int64 *v42; // x9
  __int64 v43; // x8
  __int64 v44; // x0
  char bt_profile_con; // w0
  __int64 v46; // [xsp+10h] [xbp-450h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+18h] [xbp-448h]
  __int64 v48; // [xsp+20h] [xbp-440h]
  __int64 v49; // [xsp+28h] [xbp-438h]
  _QWORD v50[4]; // [xsp+30h] [xbp-430h] BYREF
  __int64 v51; // [xsp+50h] [xbp-410h] BYREF
  __int64 v52; // [xsp+58h] [xbp-408h]
  __int64 v53; // [xsp+60h] [xbp-400h] BYREF
  __int64 v54; // [xsp+68h] [xbp-3F8h] BYREF
  __int64 v55; // [xsp+70h] [xbp-3F0h]
  __int64 s[125]; // [xsp+78h] [xbp-3E8h] BYREF

  s[124] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 16) )
    goto LABEL_2;
  v2 = result;
  memset(s, 0, 0x3E0u);
  v46 = 0;
  time_of_the_day_us = 0;
  v48 = 0;
  v49 = 0;
  memset(v50, 0, sizeof(v50));
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  result = wlan_vdev_mlme_is_mlo_vdev(v2, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( (result & 1) != 0 && ((*(_BYTE *)(v2 + 67) & 2) != 0 || (*(_BYTE *)(v2 + 60) & 2) != 0) )
    goto LABEL_2;
  result = wlan_cm_is_first_candidate_connect_attempt(v2, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( (result & 1) == 0 )
    goto LABEL_2;
  if ( a2 )
  {
    memcpy(s, a2, 0x3E0u);
    qdf_mem_set(&s[21], 0x10u, 0);
    qdf_mem_set(&s[19], 0x10u, 0);
  }
  else if ( (unsigned int)wlan_cm_get_active_connect_req_param(v2, s, v20, v21, v22, v23, v24, v25, v26, v27) )
  {
    result = qdf_trace_msg(
               0x38u,
               2u,
               "%s: vdev: %d failed to get active cmd request",
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               "wlan_connectivity_connecting_event",
               *(unsigned __int8 *)(v2 + 168));
    goto LABEL_2;
  }
  LOBYTE(v50[0]) = 1;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v28 = ktime_get(time_of_the_day_us);
  v29 = *(unsigned __int8 *)(v2 + 168);
  LODWORD(v53) = 0;
  HIWORD(v46) = v29;
  if ( BYTE4(s[2]) >= 0x20u )
    v30 = 32;
  else
    v30 = BYTE4(s[2]);
  v49 = v28 / 1000;
  BYTE3(v50[0]) = v30;
  qdf_mem_copy((char *)v50 + 4, (char *)&s[2] + 5, v30);
  if ( LODWORD(s[1]) | WORD2(s[1]) )
  {
    v31 = (char *)&v46;
    v32 = &s[1];
  }
  else
  {
    if ( !(*(_DWORD *)((char *)&s[6] + 5) | *(unsigned __int16 *)((char *)&s[7] + 1)) )
      goto LABEL_19;
    v32 = (__int64 *)((char *)&s[6] + 5);
    v31 = (char *)&v51 + 4;
  }
  qdf_mem_copy(v31, v32, 6u);
LABEL_19:
  v41 = HIDWORD(s[7]);
  if ( HIDWORD(s[7]) )
  {
    v42 = (__int64 *)((char *)&v53 + 4);
LABEL_23:
    *(_DWORD *)v42 = v41;
    goto LABEL_24;
  }
  v41 = s[8];
  if ( LODWORD(s[8]) )
  {
    v42 = &v54;
    goto LABEL_23;
  }
LABEL_24:
  HIDWORD(v54) = s[18];
  HIDWORD(v52) = HIDWORD(s[17]);
  LODWORD(v55) = s[17];
  BYTE1(v50[0]) = BYTE4(s[16]);
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
  v43 = *(_QWORD *)(v2 + 216);
  if ( v43 )
    v44 = *(_QWORD *)(v43 + 80);
  else
    v44 = 0;
  bt_profile_con = wlan_mlme_get_bt_profile_con(v44);
  BYTE2(v50[0]) = BYTE2(v50[0]) & 0xFE | bt_profile_con & 1;
  result = host_diag_event_report_payload(3351, 104, &v46);
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
