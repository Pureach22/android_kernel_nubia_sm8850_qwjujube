_DWORD *__fastcall ieee80211_enable_rssi_reports(_DWORD *result, int a2, int a3)
{
  if ( a2 >= a3 )
    __break(0x800u);
  if ( *result == 2 )
  {
    *(result - 548) = 16 * a2;
    *(result - 547) = 16 * a3;
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
