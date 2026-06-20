__int64 __fastcall wlan_cfg80211_scan_request_cached_scan_report(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x21
  __int64 result; // x0
  __int64 v7; // x27
  __int64 v8; // x0
  __int64 v9; // x23
  __int64 v10; // x21
  __int64 scan_cache_report_max_time_in_sec; // x22
  unsigned __int16 *v12; // x23
  int v13; // w22
  __int64 v14; // x8
  int v15; // w8
  __int64 v16; // x0
  __int64 v17; // x20
  __int64 v18; // x22
  __int64 v19; // x25
  _WORD *v20; // x25
  __int64 v21; // x22
  __int64 v22; // x22
  __int64 v23; // x25
  __int64 v24; // x22
  __int64 v25; // x10
  unsigned __int64 v26; // x8
  __int64 v27; // x21
  __int64 v28; // x24
  __int64 v29; // x21
  int nl80211_chwidth; // w0
  int v31; // w8
  __int64 v32; // x24
  __int64 v33; // x21
  int v34; // w8
  int v35; // w9
  int v36; // w10
  int v37; // w11
  unsigned int v44; // w8
  unsigned int v45; // w8
  unsigned int v48; // w10
  _WORD *v49; // [xsp+58h] [xbp-68h]
  int v50; // [xsp+64h] [xbp-5Ch]
  int v51; // [xsp+74h] [xbp-4Ch]
  _WORD *v52; // [xsp+78h] [xbp-48h]
  __int64 v53; // [xsp+80h] [xbp-40h]
  int v54; // [xsp+8Ch] [xbp-34h]
  char *v55; // [xsp+90h] [xbp-30h]
  __int64 v56; // [xsp+98h] [xbp-28h]
  int v57; // [xsp+A0h] [xbp-20h]
  _BYTE v58[4]; // [xsp+A4h] [xbp-1Ch] BYREF
  _QWORD v59[3]; // [xsp+A8h] [xbp-18h] BYREF

  v59[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    if ( (scm_scan_get_cached_scan_report_fw_cap(a3) & 1) != 0 )
    {
      v5 = *(_QWORD *)(a3 + 24);
      if ( v5 )
      {
        result = wlan_objmgr_pdev_try_get_ref(a3, 12);
        if ( !(_DWORD)result )
        {
          v7 = *(_QWORD *)(v5 + 16);
          v8 = ktime_get_with_offset(1);
          v9 = *(_QWORD *)(a3 + 80);
          v10 = v8 / 1000;
          if ( v9 )
          {
            scan_cache_report_max_time_in_sec = ucfg_scan_get_scan_cache_report_max_time_in_sec(*(_QWORD *)(a3 + 80));
            if ( (ucfg_pmo_tgt_psoc_get_runtime_pm_in_progress(v9) & 1) != 0 )
            {
              v12 = *(unsigned __int16 **)(v7 + 352);
              if ( v12 )
              {
                if ( v10 - *((_QWORD *)v12 + 1) < (unsigned __int64)(1000000 * scan_cache_report_max_time_in_sec) )
                {
                  v13 = 1;
                  goto LABEL_20;
                }
              }
            }
          }
          else
          {
            qdf_trace_msg(72, 2, "%s: Invalid psoc object", "wlan_if_cached_scan_reported_allowed");
          }
          qdf_trace_msg(72, 8, "%s: Get scan cache from FW", "wlan_cfg80211_send_scan_request_cached_report");
          qdf_wake_lock_acquire(v7 + 104, 3);
          qdf_runtime_pm_prevent_suspend(v7 + 96);
          qdf_event_reset(v7 + 312);
          _X9 = (unsigned int *)(v7 + 304);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v44 = __ldxr(_X9);
            v45 = v44 + 1;
          }
          while ( __stlxr(v45, _X9) );
          __dmb(0xBu);
          if ( v45 == 1 )
          {
            v14 = *(_QWORD *)(v7 + 352);
            if ( v14 )
            {
              _qdf_mem_free(*(_QWORD *)(v14 + 24));
              _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v7 + 352) + 16LL));
              _qdf_mem_free(*(_QWORD *)(v7 + 352));
              *(_QWORD *)(v7 + 352) = 0;
            }
            if ( (unsigned int)scm_scan_request_cached_scan_report(a3) )
              goto LABEL_73;
          }
          if ( (unsigned int)qdf_wait_for_event_completion(v7 + 312, 10000) )
            goto LABEL_73;
          v12 = *(unsigned __int16 **)(v7 + 352);
          v13 = 0;
LABEL_20:
          v15 = v12[1];
          v58[0] = 0;
          v16 = _cfg80211_alloc_reply_skb(a1, 103, 197, 108 * v15 + 8 * (unsigned int)*v12 + 24);
          if ( !v16 )
          {
            qdf_trace_msg(72, 8, "%s: SKB alloc failed", "wlan_scan_send_cached_scan_report");
            if ( (v13 & 1) == 0 )
              goto LABEL_73;
            goto LABEL_74;
          }
          v17 = v16;
          v57 = v13;
          if ( v13 )
            v59[0] = v10;
          else
            v59[0] = *((_QWORD *)v12 + 1);
          nla_put_64bit(v16, 1, 8, v59, 0);
          if ( *v12 )
          {
            v18 = *(_QWORD *)(v17 + 216);
            v19 = *(unsigned int *)(v17 + 208);
            if ( (nla_put(v17, 32770, 0, 0) & 0x80000000) != 0 )
              goto LABEL_71;
            v20 = (_WORD *)(v18 + v19);
            if ( !v20 )
              goto LABEL_71;
            if ( *v12 )
            {
              v21 = 0;
              do
              {
                LODWORD(v59[0]) = *(_DWORD *)(*((_QWORD *)v12 + 2) + 4 * v21);
                if ( (unsigned int)nla_put(v17, (unsigned int)v21, 4, v59) )
                  goto LABEL_71;
              }
              while ( ++v21 < (unsigned __int64)*v12 );
            }
            *v20 = *(_WORD *)(v17 + 216) + *(_DWORD *)(v17 + 208) - (_WORD)v20;
          }
          if ( !v12[1] )
            goto LABEL_70;
          v22 = *(_QWORD *)(v17 + 216);
          v23 = *(unsigned int *)(v17 + 208);
          if ( (nla_put(v17, 32771, 0, 0) & 0x80000000) == 0 )
          {
            v49 = (_WORD *)(v22 + v23);
            if ( v22 + v23 )
            {
              qdf_trace_msg(
                72,
                8,
                "%s: Scan cached report ts: %llu current ts: %llu",
                "wlan_scan_send_cached_scan_report",
                *((_QWORD *)v12 + 1),
                v10);
              if ( v12[1] )
              {
                v24 = 0;
                v25 = 0;
                v26 = (v10 - *((_QWORD *)v12 + 1)) / 0x3E8uLL;
                if ( !v57 )
                  LODWORD(v26) = 0;
                v50 = v26;
                do
                {
                  v27 = *(_QWORD *)(v17 + 216);
                  v28 = *(unsigned int *)(v17 + 208);
                  v53 = v25;
                  if ( (nla_put(v17, (unsigned int)v25 | 0x8000, 0, 0) & 0x80000000) != 0 )
                    goto LABEL_71;
                  v52 = (_WORD *)(v27 + v28);
                  if ( !(v27 + v28) )
                    goto LABEL_71;
                  v29 = *((_QWORD *)v12 + 3) + v24;
                  v56 = *((_QWORD *)v12 + 3);
                  nl80211_chwidth = wlan_cfg80211_get_nl80211_chwidth(*(unsigned int *)(v29 + 24));
                  v58[0] = 0;
                  v31 = *(_DWORD *)(v29 + 8);
                  v54 = nl80211_chwidth;
                  if ( !v31 )
                    goto LABEL_50;
                  if ( (v31 & 1) != 0 )
                  {
                    wlan_cfg80211_set_feature(v58, 0);
                    v31 = *(_DWORD *)(v29 + 8);
                    if ( (v31 & 2) == 0 )
                    {
LABEL_46:
                      if ( (v31 & 4) != 0 )
                        goto LABEL_64;
                      goto LABEL_47;
                    }
                  }
                  else if ( (v31 & 2) == 0 )
                  {
                    goto LABEL_46;
                  }
                  wlan_cfg80211_set_feature(v58, 1);
                  v31 = *(_DWORD *)(v29 + 8);
                  if ( (v31 & 4) != 0 )
                  {
LABEL_64:
                    wlan_cfg80211_set_feature(v58, 2);
                    v31 = *(_DWORD *)(v29 + 8);
                    if ( (v31 & 8) == 0 )
                    {
LABEL_48:
                      if ( (v31 & 0x10) == 0 )
                        goto LABEL_50;
LABEL_49:
                      wlan_cfg80211_set_feature(v58, 4);
                      goto LABEL_50;
                    }
                    goto LABEL_65;
                  }
LABEL_47:
                  if ( (v31 & 8) == 0 )
                    goto LABEL_48;
LABEL_65:
                  wlan_cfg80211_set_feature(v58, 3);
                  if ( (*(_DWORD *)(v29 + 8) & 0x10) != 0 )
                    goto LABEL_49;
LABEL_50:
                  v55 = (char *)v29;
                  v51 = *(_DWORD *)(v29 + 4) + v50;
                  LODWORD(v59[0]) = v51;
                  if ( (unsigned int)nla_put(v17, 1, 4, v59) )
                    goto LABEL_71;
                  v32 = v56 + v24;
                  if ( (unsigned int)nla_put(v17, 2, 6, v56 + v24 + 28) )
                    goto LABEL_71;
                  if ( (unsigned int)nla_put(v17, 3, *(unsigned __int8 *)(v32 + 34), v32 + 35) )
                    goto LABEL_71;
                  LOBYTE(v59[0]) = *(_BYTE *)v29;
                  if ( (unsigned int)nla_put(v17, 4, 1, v59) )
                    goto LABEL_71;
                  LOWORD(v59[0]) = *(_WORD *)(v56 + v24 + 2);
                  if ( (unsigned int)nla_put(v17, 5, 2, v59) )
                    goto LABEL_71;
                  if ( (unsigned int)nla_put(v17, 6, 1, v58) )
                    goto LABEL_71;
                  LODWORD(v59[0]) = *(_DWORD *)(v56 + v24 + 12);
                  if ( (unsigned int)nla_put(v17, 7, 4, v59) )
                    goto LABEL_71;
                  LOBYTE(v59[0]) = v54;
                  if ( (unsigned int)nla_put(v17, 8, 1, v59) )
                    goto LABEL_71;
                  v33 = v56 + v24;
                  LODWORD(v59[0]) = *(_DWORD *)(v56 + v24 + 16);
                  if ( (unsigned int)nla_put(v17, 9, 4, v59) )
                    goto LABEL_71;
                  LODWORD(v59[0]) = *(_DWORD *)(v33 + 20);
                  if ( (unsigned int)nla_put(v17, 10, 4, v59) )
                    goto LABEL_71;
                  *v52 = *(_WORD *)(v17 + 216) + *(_WORD *)(v17 + 208) - (_WORD)v52;
                  if ( v56 + v24 == -28 )
                  {
                    v36 = 0;
                    v34 = 0;
                    v35 = 0;
                    v37 = 0;
                  }
                  else
                  {
                    v34 = *(unsigned __int8 *)(v56 + v24 + 28);
                    v35 = *(unsigned __int8 *)(v56 + v24 + 29);
                    v36 = *(unsigned __int8 *)(v56 + v24 + 30);
                    v37 = *(unsigned __int8 *)(v56 + v24 + 33);
                  }
                  qdf_trace_msg(
                    72,
                    8,
                    "%s: age %d, cap 0x%x, flags 0x%x, rssi %d, freq %d, ccfs0 %d, ccfs1 %d, bw %d, BSSID: %02x:%02x:%02x"
                    ":**:**:%02x, SSID: %.*s",
                    "wlan_scan_send_cached_scan_report",
                    v51,
                    *(unsigned __int16 *)(v56 + v24 + 2),
                    v58[0],
                    *v55,
                    *(_DWORD *)(v56 + v24 + 12),
                    *(_DWORD *)(v33 + 16),
                    *(_DWORD *)(v33 + 20),
                    v54,
                    v34,
                    v35,
                    v36,
                    v37,
                    *(unsigned __int8 *)(v32 + 34),
                    (const char *)(v32 + 35));
                  v24 += 68;
                  v25 = v53 + 1;
                }
                while ( v53 + 1 < (unsigned __int64)v12[1] );
              }
              *v49 = *(_WORD *)(v17 + 216) + *(_WORD *)(v17 + 208) - (_WORD)v49;
LABEL_70:
              cfg80211_vendor_cmd_reply(v17);
              goto LABEL_72;
            }
          }
LABEL_71:
          qdf_trace_msg(72, 8, "%s: Failed to send event to userspace", "wlan_scan_send_cached_scan_report");
          sk_skb_reason_drop(0, v17, 2);
LABEL_72:
          if ( (v57 & 1) == 0 )
          {
LABEL_73:
            _X8 = (unsigned int *)(v7 + 304);
            __asm { PRFM            #0x11, [X8] }
            do
              v48 = __ldxr(_X8);
            while ( __stxr(v48 - 1, _X8) );
            qdf_runtime_pm_allow_suspend(v7 + 96);
            qdf_wake_lock_release(v7 + 104, 3);
          }
LABEL_74:
          wlan_objmgr_pdev_release_ref(a3, 12);
          result = 0;
        }
      }
      else
      {
        qdf_trace_msg(72, 8, "%s: Invalid osif priv object", "wlan_cfg80211_scan_request_cached_scan_report");
        result = 29;
      }
    }
    else
    {
      qdf_trace_msg(72, 8, "%s: No FW support", "wlan_cfg80211_scan_request_cached_scan_report");
      result = 11;
    }
  }
  else
  {
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
