__int64 __fastcall sch_beacon_process(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x21
  char is_mld_sta; // w0
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x20
  __int64 v45; // x21

  if ( a3 && *(_DWORD *)(a3 + 88) == 2 )
  {
    v12 = result;
    result = wlan_cm_is_vdev_connected(*(_QWORD *)(a3 + 16), a4, a5, a6, a7, a8, a9, a10, a11);
    if ( (result & 1) != 0 && (result = mlo_mgr_is_link_switch_in_progress(*(_QWORD *)(a3 + 16)), (result & 1) == 0) )
    {
      result = sir_convert_beacon_frame2_struct(v12, a2, (int)&sch_beacon_process_bcn);
      if ( (_DWORD)result )
      {
        v31 = jiffies;
        if ( sch_beacon_process___last_ticks_4 - jiffies + 125 < 0 )
        {
          result = qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: beacon parsing failed",
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     "sch_beacon_process");
          sch_beacon_process___last_ticks_4 = v31;
        }
      }
      else
      {
        result = lim_cmp_ssid((unsigned __int8 *)&byte_91734C, a3);
        if ( (_DWORD)result )
        {
          v40 = jiffies;
          if ( sch_beacon_process___last_ticks_6 - jiffies + 125 < 0 )
          {
            result = qdf_trace_msg(
                       0x35u,
                       8u,
                       "%s: ssid mismatch, current %.*sRcvd %.*s from %02x:%02x:%02x:**:**:%02x",
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38,
                       v39,
                       "sch_beacon_process",
                       *(unsigned __int8 *)(a3 + 36),
                       a3 + 37,
                       (unsigned __int8)byte_91734C,
                       &unk_91734D,
                       *(unsigned __int8 *)(a3 + 24),
                       *(unsigned __int8 *)(a3 + 25),
                       *(unsigned __int8 *)(a3 + 26),
                       *(unsigned __int8 *)(a3 + 29));
            sch_beacon_process___last_ticks_6 = v40;
          }
        }
        else
        {
          result = lim_is_same_mld_addr(v12, a3, (__int64)&sch_beacon_process_bcn);
          if ( (result & 1) != 0 )
          {
            is_mld_sta = mlo_is_mld_sta(*(_QWORD *)(a3 + 16));
            v42 = a2;
            v43 = v12;
            if ( (is_mld_sta & 1) == 0
              || (result = mlo_check_if_all_peer_authenticated(*(_QWORD *)(a3 + 16)),
                  v42 = a2,
                  v43 = v12,
                  (result & 1) != 0) )
            {
              v44 = v43;
              v45 = v42;
              *(_BYTE *)(a3 + 251) = byte_917393;
              sch_send_beacon_report(v43, a3);
              return _sch_beacon_process_for_session(v44, v45, a3);
            }
          }
        }
      }
    }
    else
    {
      v22 = jiffies;
      if ( sch_beacon_process___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: vdev %d, drop beacon",
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "sch_beacon_process",
                   *(unsigned __int8 *)(a3 + 10));
        sch_beacon_process___last_ticks = v22;
      }
    }
  }
  return result;
}
