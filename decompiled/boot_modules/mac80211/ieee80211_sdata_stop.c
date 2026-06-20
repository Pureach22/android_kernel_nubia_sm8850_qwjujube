__int64 __fastcall ieee80211_sdata_stop(__int64 result)
{
  if ( (*(_QWORD *)(result + 1632) & 1) != 0 )
    return ieee80211_do_stop(result, 1);
  __break(0x800u);
  return result;
}
