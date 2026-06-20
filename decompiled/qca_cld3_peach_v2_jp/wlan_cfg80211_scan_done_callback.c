__int64 __fastcall wlan_cfg80211_scan_done_callback(__int64 a1, unsigned int *a2)
{
  unsigned int v2; // w21
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x19
  __int64 v8; // x24
  char v9; // w21
  __int64 v10; // x20
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 v13; // x8
  __int64 v14; // x19
  __int64 v15; // x25
  __int64 v16; // x0
  __int64 v17; // x8
  int v18; // w27
  __int64 v19; // x25
  __int64 v20; // x26
  __int64 v21; // x0
  __int64 v22; // x23
  __int64 v23; // x24
  int v24; // w23
  __int64 ev_type_name; // x0
  unsigned int v26; // w24
  const char *v27; // x25
  const char *ev_reason_name; // x0
  _BYTE v29[4]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v30; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v31[2]; // [xsp+20h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v29[0] = 0;
  if ( !a2 )
  {
    result = qdf_trace_msg(72, 2, "Invalid scan event received");
    goto LABEL_22;
  }
  v2 = a2[5];
  qdf_mtrace(21, 72, a2[1], *a2, v2);
  if ( !a2[1] )
    qdf_trace_msg(72, 4, "scan start scan id %d", v2);
  result = util_is_scan_completed(a2, v29);
  if ( (result & 1) != 0 )
  {
    v6 = *(_QWORD *)(a1 + 152);
    v31[0] = 0;
    v7 = *(_QWORD *)(v6 + 24);
    if ( v7 )
    {
      v8 = *(_QWORD *)(v7 + 16);
      qdf_mutex_acquire(v8 + 24);
      if ( (qdf_list_empty(v8) & 1) != 0 )
      {
        qdf_trace_msg(72, 4, "%s: Scan List is empty", "wlan_scan_request_dequeue");
        qdf_mutex_release(v8 + 24);
      }
      else
      {
        if ( !(unsigned int)qdf_list_peek_front(v8, v31) )
        {
          while ( *(_DWORD *)(v31[0] + 24LL) != v2 )
          {
            if ( (unsigned int)qdf_list_peek_next(v8, v31[0], v31) )
            {
              qdf_mutex_release(v8 + 24);
              qdf_trace_msg(72, 8, "%s: Failed to find scan id %d", "wlan_scan_request_dequeue", v2);
              goto LABEL_12;
            }
          }
          v15 = v31[0];
          if ( (unsigned int)qdf_list_remove_node(v8, v31[0]) )
          {
            qdf_mutex_release(v8 + 24);
            qdf_trace_msg(
              72,
              2,
              "%s: Failed to remove scan id %d, pending scans %d",
              "wlan_scan_request_dequeue",
              v2,
              *(_DWORD *)(v8 + 16));
            goto LABEL_12;
          }
          v16 = v15;
          v17 = *(_QWORD *)(v15 + 16);
          v18 = *(unsigned __int8 *)(v15 + 28);
          v19 = *(_QWORD *)(v15 + 32);
          v20 = *(_QWORD *)(v16 + 40);
          v30 = v17;
          _qdf_mem_free(v16);
          qdf_mutex_release(v8 + 24);
          qdf_trace_msg(
            72,
            8,
            "%s: removed Scan id: %d, req = %pK, pending scans %d",
            "wlan_scan_request_dequeue",
            v2,
            &v30,
            *(_DWORD *)(v8 + 16));
          if ( v19 )
          {
            if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(a1, 6) )
            {
              if ( v18 )
                wlan_vendor_scan_callback(v30, (v29[0] ^ 1) & 1);
              else
                wlan_cfg80211_scan_done(v19, v30, (v29[0] ^ 1) & 1, v7);
              wlan_objmgr_vdev_release_ref(a1, 6);
              if ( v20 )
              {
                v21 = _qdf_mem_malloc(720, "wlan_scan_get_bss_count_for_scan", 1077);
                if ( v21
                  && (v22 = v21,
                      *(_WORD *)v21 |= 8u,
                      *(_QWORD *)(v21 + 8) = qdf_get_time_of_the_day_ms() - v20,
                      v23 = ucfg_scan_get_result(v6, v22),
                      _qdf_mem_free(v22),
                      v23) )
                {
                  LODWORD(v20) = *(_DWORD *)(v23 + 16);
                  ucfg_scan_purge_results(v23);
                }
                else
                {
                  LODWORD(v20) = 0;
                }
              }
              v24 = *a2;
              ev_type_name = util_scan_get_ev_type_name(a2[1]);
              v26 = a2[1];
              v27 = (const char *)ev_type_name;
              ev_reason_name = (const char *)util_scan_get_ev_reason_name(a2[2]);
              qdf_trace_msg(
                72,
                4,
                "vdev %d, scan id %d type %s(%d) reason %s(%d) scan found %d bss",
                v24,
                v2,
                v27,
                v26,
                ev_reason_name,
                a2[2],
                v20);
              goto LABEL_13;
            }
            qdf_trace_msg(
              72,
              2,
              "%s: Failed to get vdev reference: scan Id: %d",
              "wlan_cfg80211_scan_done_callback",
              v2);
          }
          else
          {
            qdf_trace_msg(72, 2, "%s: net dev is NULL,Drop scan event Id: %d", "wlan_cfg80211_scan_done_callback", v2);
          }
          if ( v18 == 1 )
            _qdf_mem_free(v30);
LABEL_13:
          qdf_mutex_acquire(*(_QWORD *)(v7 + 16) + 24LL);
          v9 = qdf_list_empty(*(_QWORD *)(v7 + 16));
          result = qdf_mutex_release(*(_QWORD *)(v7 + 16) + 24LL);
          if ( (v9 & 1) != 0 )
          {
            result = qdf_runtime_pm_allow_suspend(*(_QWORD *)(v7 + 16) + 96LL);
            v10 = *(_QWORD *)(v6 + 80);
            if ( v10 )
            {
              v11 = *(_QWORD *)(v7 + 16);
              v12 = v11 + 104;
              if ( v11 != -104 )
              {
                result = ucfg_scan_wake_lock_in_user_scan(v10);
                if ( (result & 1) != 0 )
                  result = qdf_wake_lock_release(v12, 3);
              }
            }
            if ( v10 )
            {
              v13 = *(_QWORD *)(v7 + 16);
              v14 = v13 + 104;
              if ( v13 != -104 )
              {
                result = ucfg_scan_wake_lock_in_user_scan(v10);
                if ( (result & 1) != 0 )
                  result = qdf_wake_lock_timeout_acquire(v14, 1000);
              }
            }
          }
          goto LABEL_22;
        }
        qdf_mutex_release(v8 + 24);
        qdf_trace_msg(72, 2, "%s: Failed to remove Scan Req from queue", "wlan_scan_request_dequeue");
      }
    }
    else
    {
      qdf_trace_msg(72, 2, "%s: Failed to retrieve osif context", "wlan_scan_request_dequeue");
    }
LABEL_12:
    qdf_trace_msg(72, 2, "%s: Dequeue of scan request failed ID: %d", "wlan_cfg80211_scan_done_callback", v2);
    goto LABEL_13;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
