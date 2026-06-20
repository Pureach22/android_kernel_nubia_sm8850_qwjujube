__int64 __fastcall cfg80211_autodisconnect_wk(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w8
  __int64 *v4; // x0

  v1 = *(_QWORD *)(a1 - 104);
  if ( v1 )
  {
    mutex_lock(*(_QWORD *)(a1 - 104));
    if ( *(_DWORD *)(a1 - 4) )
    {
      v3 = *(_DWORD *)(a1 - 96);
      v4 = (__int64 *)(v1 - 992);
      if ( v3 <= 6 )
      {
        if ( v3 == 1 )
        {
          cfg80211_leave_ibss(v4, *(_QWORD *)(a1 - 72));
          return mutex_unlock(*(_QWORD *)(a1 - 104));
        }
        if ( v3 != 2 )
        {
          if ( v3 != 3 )
            return mutex_unlock(*(_QWORD *)(a1 - 104));
          goto LABEL_11;
        }
LABEL_12:
        if ( *(_QWORD *)(*v4 + 384) || (*(_BYTE *)(a1 + 60) & 1) != 0 )
          cfg80211_disconnect(v4, *(_QWORD *)(a1 - 72), 3u);
        else
          cfg80211_mlme_deauth(v4, *(_QWORD *)(a1 - 72), (int *)(a1 + 32), 0, 0, 3, 0);
        return mutex_unlock(*(_QWORD *)(a1 - 104));
      }
      switch ( v3 )
      {
        case 7:
          cfg80211_leave_mesh(v4, *(_QWORD *)(a1 - 72));
          return mutex_unlock(*(_QWORD *)(a1 - 104));
        case 8:
          goto LABEL_12;
        case 9:
LABEL_11:
          cfg80211_stop_ap((__int64)v4, *(_QWORD *)(a1 - 72), 0xFFFFFFFFLL, 0);
          break;
      }
    }
    return mutex_unlock(*(_QWORD *)(a1 - 104));
  }
  __break(0x800u);
  return cfg80211_conn_scan(a1);
}
