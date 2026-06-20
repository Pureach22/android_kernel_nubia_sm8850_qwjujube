__int64 __fastcall hdd_sar_unsolicited_work_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  const char *v20; // x2
  unsigned int v21; // w23
  int v22; // w24
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x28
  __int64 v41; // x8
  __int64 v42[2]; // [xsp+0h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42[0] = 0;
  qdf_trace_msg(0x33u, 8u, "Sar unsolicited timer expired", a2, a3, a4, a5, a6, a7, a8, a9);
  v10 = _osif_psoc_sync_op_start(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 488LL), v42, (__int64)"hdd_sar_unsolicited_work_cb");
  if ( v10 )
  {
    if ( v10 != -11 )
    {
      v20 = "%s: cannot handle sar unsolicited work";
      goto LABEL_17;
    }
    qdf_trace_msg(0x33u, 8u, "rescheduling sar unsolicited work", v11, v12, v13, v14, v15, v16, v17, v18);
    result = _qdf_delayed_work_create((_QWORD *)(a1 + 4024), (__int64)hdd_sar_unsolicited_work_cb, a1);
    if ( (_DWORD)result )
    {
      v20 = "%s: failed to create sar safety unsolicited work";
LABEL_17:
      result = qdf_trace_msg(0x33u, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "hdd_sar_unsolicited_work_cb");
    }
  }
  else
  {
    *(_DWORD *)(a1 + 4184) = 1;
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 104) + 160LL) )
    {
      v21 = 0;
      v22 = 0;
      do
      {
        qdf_event_reset(a1 + 4144);
        if ( a1 )
        {
          v31 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 41, 16, 3264);
          if ( v31 )
            _cfg80211_send_event_skb(v31, 3264);
          else
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: wlan_cfg80211_vendor_event_alloc failed",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "hdd_send_sar_unsolicited_event");
        }
        else
        {
          v40 = jiffies;
          if ( hdd_send_sar_unsolicited_event___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: hdd context is null",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "hdd_send_sar_unsolicited_event");
            hdd_send_sar_unsolicited_event___last_ticks = v40;
          }
        }
        if ( !(unsigned int)qdf_wait_for_event_completion(a1 + 4144, *(_DWORD *)(*(_QWORD *)(a1 + 104) + 156LL)) )
          break;
        v21 = (unsigned __int8)++v22;
      }
      while ( *(_DWORD *)(*(_QWORD *)(a1 + 104) + 160LL) > (unsigned int)(unsigned __int8)v22 );
    }
    else
    {
      v21 = 0;
    }
    *(_DWORD *)(a1 + 4184) = 0;
    v41 = *(_QWORD *)(a1 + 104);
    if ( *(_DWORD *)(v41 + 160) <= v21 )
      hdd_configure_sar_index(a1, *(_DWORD *)(v41 + 164), v11, v12, v13, v14, v15, v16, v17, v18);
    result = _osif_psoc_sync_op_stop(v42[0], (__int64)"hdd_sar_unsolicited_work_cb");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
