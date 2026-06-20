__int64 __fastcall ieee80211_ave_rssi(_DWORD *a1)
{
  if ( *a1 == 2 )
    return (unsigned int)-(*((_QWORD *)a1 - 32) >> 4);
  __break(0x800u);
  return 0;
}
