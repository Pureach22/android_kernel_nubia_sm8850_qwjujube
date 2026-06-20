_QWORD *__fastcall ieee80211_sta_ps_deliver_uapsd(_QWORD *result)
{
  unsigned int v1; // w1

  if ( *((_BYTE *)result + 2699) )
  {
    v1 = *((unsigned __int8 *)result + 2700);
    if ( v1 <= 3 )
      v1 = dword_C1540[*((unsigned __int8 *)result + 2700)];
    return ieee80211_sta_ps_deliver_response(result, v1, ~*((_BYTE *)result + 2699), 1u);
  }
  return result;
}
