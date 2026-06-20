_DWORD *__fastcall ieee80211_disable_rssi_reports(_DWORD *result)
{
  if ( *result == 2 )
    *((_QWORD *)result - 274) = 0;
  else
    __break(0x800u);
  return result;
}
