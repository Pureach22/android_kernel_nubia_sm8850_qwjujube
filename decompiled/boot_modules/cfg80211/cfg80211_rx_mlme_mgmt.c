_QWORD *__fastcall cfg80211_rx_mlme_mgmt(__int64 a1, _WORD *a2, unsigned __int64 a3)
{
  _QWORD *result; // x0
  int v4; // w8
  _QWORD *v7; // x19

  result = *(_QWORD **)(a1 + 992);
  if ( a3 <= 1 )
  {
    __break(0x800u);
  }
  else
  {
    v4 = *a2 & 0xFC;
    switch ( v4 )
    {
      case 160:
        return (_QWORD *)((__int64 (__fastcall *)(_QWORD *))cfg80211_process_disassoc)(result);
      case 192:
        return (_QWORD *)cfg80211_process_deauth(result);
      case 176:
        if ( *result )
        {
          v7 = result;
          nl80211_send_rx_auth(*result - 992LL, result[4], a2, a3, 3264);
          return (_QWORD *)cfg80211_sme_rx_auth(v7, a2, a3);
        }
        else
        {
          __break(0x800u);
          return (_QWORD *)cfg80211_process_deauth(result);
        }
    }
  }
  return result;
}
