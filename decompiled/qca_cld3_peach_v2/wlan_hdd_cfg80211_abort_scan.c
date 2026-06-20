__int64 __fastcall wlan_hdd_cfg80211_abort_scan(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w1
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _QWORD v33[2]; // [xsp+0h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 488);
  v33[0] = 0;
  result = _osif_psoc_sync_op_start(v4, v33, "wlan_hdd_cfg80211_abort_scan");
  if ( (_DWORD)result )
    goto LABEL_9;
  if ( a1 )
  {
    v14 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "__wlan_hdd_cfg80211_abort_scan",
      v14 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v23 = "%s: Command not allowed in FTM mode";
      v24 = 2;
    }
    else
    {
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                           *(_BYTE *)(*(_QWORD *)(v14 + 55520) + 8LL),
                           (__int64)"__wlan_hdd_cfg80211_abort_scan",
                           v15,
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22)
        || (unsigned int)_wlan_hdd_validate_context(
                           a1 + 1536,
                           (__int64)"__wlan_hdd_cfg80211_abort_scan",
                           v25,
                           v26,
                           v27,
                           v28,
                           v29,
                           v30,
                           v31,
                           v32) )
      {
        goto LABEL_8;
      }
      wlan_cfg80211_abort_scan(*(_QWORD *)(a1 + 1544));
      v23 = "%s: exit";
      v24 = 8;
    }
    qdf_trace_msg(0x33u, v24, v23, v15, v16, v17, v18, v19, v20, v21, v22, "__wlan_hdd_cfg80211_abort_scan");
LABEL_8:
    result = _osif_psoc_sync_op_stop(v33[0], "wlan_hdd_cfg80211_abort_scan");
LABEL_9:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return hdd_scan_context_destroy(result);
}
