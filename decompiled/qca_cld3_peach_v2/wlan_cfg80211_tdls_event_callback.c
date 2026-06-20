_DWORD *__fastcall wlan_cfg80211_tdls_event_callback(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        char *a11)
{
  _QWORD *v11; // x8
  _DWORD *result; // x0

  if ( !a11 || !*(_QWORD *)a11 )
    return (_DWORD *)qdf_trace_msg(
                       0x48u,
                       2u,
                       "%s: ind: %pK",
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       "wlan_cfg80211_tdls_event_callback",
                       a11);
  v11 = *(_QWORD **)(*(_QWORD *)a11 + 680LL);
  if ( !v11 )
    return (_DWORD *)qdf_trace_msg(
                       0x48u,
                       2u,
                       "%s: osif priv or tdls priv is NULL",
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       "wlan_cfg80211_tdls_event_callback",
                       a11);
  result = (_DWORD *)v11[2];
  if ( !result )
    return (_DWORD *)qdf_trace_msg(
                       0x48u,
                       2u,
                       "%s: osif priv or tdls priv is NULL",
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       "wlan_cfg80211_tdls_event_callback",
                       a11);
  if ( (int)a10 <= 5 )
  {
    if ( (int)a10 > 3 )
    {
      if ( (_DWORD)a10 != 4 )
        return (_DWORD *)cfg80211_tdls_oper_request(*(_QWORD *)(*v11 + 32LL), a11 + 10, 0, 0, 3264);
      result += 8;
    }
    else if ( (_DWORD)a10 == 1 )
    {
      result[57] = *((_DWORD *)a11 + 4);
      result += 16;
    }
    else
    {
      if ( (_DWORD)a10 != 3 )
        return result;
      result[56] = *((_DWORD *)a11 + 4);
    }
    return (_DWORD *)complete(result, a10);
  }
  if ( (int)a10 > 8 )
  {
    if ( (_DWORD)a10 == 9 )
    {
      result[58] = *((_DWORD *)a11 + 4);
      result += 40;
    }
    else
    {
      if ( (_DWORD)a10 != 10 )
        return result;
      result[59] = *((_DWORD *)a11 + 4);
      result += 48;
    }
    return (_DWORD *)complete(result, a10);
  }
  if ( (_DWORD)a10 == 6 )
    return (_DWORD *)wlan_cfg80211_tdls_indicate_teardown(a11);
  if ( (_DWORD)a10 == 7 )
    return (_DWORD *)wlan_cfg80211_tdls_indicate_setup(a11);
  return result;
}
