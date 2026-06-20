__int64 __fastcall wlan_cfg80211_cleanup_scan_queue(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v4; // x20
  __int64 result; // x0
  const char *v6; // x2
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x22
  __int64 v11; // x25
  int v12; // w8
  __int64 i; // x1
  __int64 v14; // x22
  __int64 v15; // x0
  __int64 v16; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v17[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h] BYREF
  _QWORD v20[3]; // [xsp+28h] [xbp-18h] BYREF

  v20[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  if ( !a1 )
  {
    v6 = "%s: pdev is Null";
    goto LABEL_30;
  }
  v2 = *(_QWORD *)(a1 + 24);
  v17[0] = v17;
  v17[1] = v17;
  v18 = 0x800000000LL;
  v19 = 0;
  v4 = *(_QWORD *)(v2 + 16);
  v20[0] = 0;
  qdf_mutex_acquire(v4 + 24);
  if ( !(unsigned int)qdf_list_peek_front(v4, v20) )
  {
    for ( i = v20[0]; i; v20[0] = i )
    {
      qdf_list_peek_next(v4, i, &v19);
      v14 = v20[0];
      if ( !a2 || *(_QWORD *)(v20[0] + 32LL) == a2 )
      {
        v15 = _qdf_mem_malloc(48, "wlan_cfg80211_enqueue_for_cleanup", 1389);
        if ( !v15 )
          break;
        *(_QWORD *)(v15 + 16) = *(_QWORD *)(v14 + 16);
        *(_DWORD *)(v15 + 24) = *(_DWORD *)(v14 + 24);
        *(_BYTE *)(v15 + 28) = *(_BYTE *)(v14 + 28);
        *(_QWORD *)(v15 + 32) = *(_QWORD *)(v14 + 32);
        qdf_list_insert_back(v17, v15);
        if ( (unsigned int)qdf_list_remove_node(v4, v20[0]) )
        {
          qdf_mutex_release(v4 + 24);
          qdf_trace_msg(72, 2, "%s: Failed to remove scan request", "wlan_cfg80211_enqueue_for_cleanup");
          goto LABEL_4;
        }
        _qdf_mem_free(v14);
      }
      i = v19;
      v19 = 0;
    }
  }
  qdf_mutex_release(v4 + 24);
LABEL_4:
  result = qdf_list_empty(v17);
  if ( (result & 1) != 0 )
  {
LABEL_5:
    if ( (_DWORD)v18 )
      result = qdf_trace_msg(51, 2, "%s: list length not equal to zero", "qdf_list_destroy");
    goto LABEL_31;
  }
  while ( !(unsigned int)qdf_list_remove_front(v17, &v16) )
  {
    v7 = v16;
    v8 = *(_QWORD *)(v16 + 16);
    if ( *(_BYTE *)(v16 + 28) )
    {
      wlan_vendor_scan_callback(v8, 1, 255);
    }
    else
    {
      v9 = *(__int64 (__fastcall **)(_QWORD))(v2 + 32);
      v10 = *(_QWORD *)(v16 + 32);
      v20[0] = 0;
      v20[1] = 0x1000000000000LL;
      if ( v9 )
      {
        v11 = v8;
        if ( *((_DWORD *)v9 - 1) != -1466421336 )
          __break(0x8228u);
        v12 = v9(v10);
        v8 = v11;
        if ( !v12 )
        {
LABEL_19:
          qdf_trace_msg(
            72,
            8,
            "%s: scan done callback has been dropped :%s",
            "wlan_cfg80211_scan_done",
            (const char *)(v10 + 296));
          goto LABEL_10;
        }
      }
      else if ( (*(_DWORD *)(v10 + 176) & 1) == 0 )
      {
        goto LABEL_19;
      }
      cfg80211_scan_done(v8, v20);
    }
LABEL_10:
    _qdf_mem_free(v7);
    result = qdf_list_empty(v17);
    if ( (result & 1) != 0 )
      goto LABEL_5;
  }
  v6 = "%s: Failed to remove scan request";
LABEL_30:
  result = qdf_trace_msg(72, 2, v6, "wlan_cfg80211_cleanup_scan_queue");
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
