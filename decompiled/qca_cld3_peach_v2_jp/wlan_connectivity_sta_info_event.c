__int64 __fastcall wlan_connectivity_sta_info_event(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w19
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int *is_first_candidate_connect_attempt; // x8
  __int64 v15; // x20
  __int64 v16; // x20
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x21
  __int64 v22; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+8h] [xbp-38h]
  __int64 v24; // [xsp+10h] [xbp-30h]
  __int64 v25; // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  int v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v4 = a2;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  time_of_the_day_us = 0;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( result )
  {
    is_first_candidate_connect_attempt = (unsigned int *)*(unsigned int *)(result + 16);
    if ( !(_DWORD)is_first_candidate_connect_attempt )
    {
      if ( (a3 & 1) != 0
        || (v15 = result,
            is_first_candidate_connect_attempt = (unsigned int *)wlan_cm_is_first_candidate_connect_attempt(
                                                                   result,
                                                                   v6,
                                                                   v7,
                                                                   v8,
                                                                   v9,
                                                                   v10,
                                                                   v11,
                                                                   v12,
                                                                   v13),
            result = v15,
            ((unsigned __int8)is_first_candidate_connect_attempt & 1) != 0) )
      {
        v16 = result;
        time_of_the_day_us = qdf_get_time_of_the_day_us();
        HIWORD(v22) = v4;
        BYTE1(v26) = 0;
        v25 = ktime_get(time_of_the_day_us, v17, v18, v19, v20) / 1000;
        qdf_mem_copy(&v22, (const void *)(v16 + 74), 6u);
        host_diag_event_report_payload(3414, 52, &v22);
        result = v16;
      }
    }
    result = wlan_objmgr_vdev_release_ref(
               result,
               0x43u,
               is_first_candidate_connect_attempt,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13);
  }
  else
  {
    v21 = jiffies;
    if ( wlan_connectivity_sta_info_event___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x1Fu,
                 2u,
                 "%s: Invalid vdev:%d",
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 "wlan_connectivity_sta_info_event",
                 v4);
      wlan_connectivity_sta_info_event___last_ticks = v21;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
