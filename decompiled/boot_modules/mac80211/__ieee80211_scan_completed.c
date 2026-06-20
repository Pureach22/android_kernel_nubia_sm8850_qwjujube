_QWORD *__fastcall _ieee80211_scan_completed(_QWORD *result, char a2)
{
  __int64 v2; // x22
  __int64 v3; // x19
  __int64 v4; // x20
  char v5; // w23
  __int64 v6; // x0
  __int64 v7; // x21
  void (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x1
  _QWORD *i; // x20

  v2 = result[587];
  v3 = (__int64)result;
  if ( !v2 && (a2 & 1) == 0 )
  {
    __break(0x800u);
    if ( result[594] )
      goto LABEL_4;
LABEL_29:
    __break(0x800u);
    return result;
  }
  if ( !result[594] )
    goto LABEL_29;
LABEL_4:
  v4 = result[621];
  v5 = (v2 == 0) | a2;
  if ( !((v2 == 0) | a2 & 1) && (v2 & 2) != 0 )
  {
    if ( (result[12] & 0x10000000) != 0 || (ieee80211_prep_hw_scan(result[621]) & 1) == 0 )
    {
      v5 = 0;
    }
    else
    {
      result = (_QWORD *)drv_hw_scan(v3, *(_QWORD *)(v3 + 4968), *(_QWORD *)(v3 + 4760));
      if ( !(_DWORD)result )
        return result;
      v5 = 1;
      *(_QWORD *)(v3 + 4824) = 0;
      *(_QWORD *)(v3 + 4816) = 0;
    }
  }
  v6 = kfree(*(_QWORD *)(v3 + 4760));
  v7 = *(_QWORD *)(v3 + 4752);
  *(_QWORD *)(v3 + 4760) = 0;
  *(_QWORD *)(v3 + 4752) = 0;
  *(_QWORD *)(v3 + 4968) = 0;
  *(_QWORD *)(v3 + 4696) = 0;
  *(_QWORD *)(v3 + 4768) = 0;
  synchronize_rcu(v6);
  if ( v7 != *(_QWORD *)(v3 + 4744) )
  {
    *(_BYTE *)(v3 + 4830) = v5 & 1;
    cfg80211_scan_done(v7, v3 + 4816);
  }
  ieee80211_hw_conf_chan(v3);
  if ( v2 && (v2 & 2) == 0 )
  {
    ieee80211_configure_filter(v3);
    v8 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v3 + 464) + 224LL);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != 1098857213 )
        __break(0x8228u);
      v8(v3, v4 + 4720);
    }
    ieee80211_offchannel_return(v3);
  }
  ieee80211_recalc_idle(v3);
  ieee80211_mlme_notify_scan_completed(v3, v9);
  result = (_QWORD *)ieee80211_ibss_notify_scan_completed(v3);
  for ( i = *(_QWORD **)(v3 + 4616); i != (_QWORD *)(v3 + 4616); i = (_QWORD *)*i )
  {
    if ( (i[204] & 1) != 0 )
      result = (_QWORD *)wiphy_work_queue(*(_QWORD *)(i[202] + 72LL), i + 245);
  }
  if ( v2 )
    return (_QWORD *)ieee80211_start_next_roc(v3);
  return result;
}
