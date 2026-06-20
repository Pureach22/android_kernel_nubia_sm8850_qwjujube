__int64 __fastcall cfg80211_tx_mlme_mgmt(__int64 a1, _WORD *a2, unsigned __int64 a3, char a4)
{
  __int64 result; // x0
  char v5; // w3

  result = *(_QWORD *)(a1 + 992);
  if ( a3 <= 1 )
  {
    __break(0x800u);
  }
  else
  {
    v5 = a4 & 1;
    if ( (*a2 & 0xFC) == 0xC0 )
      return cfg80211_process_deauth(result, (__int64)a2, a3, v5);
    else
      return ((__int64 (__fastcall *)(__int64))cfg80211_process_disassoc)(result);
  }
  return result;
}
