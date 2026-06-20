__int64 __fastcall ieee80211_assign_tid_tx(__int64 result, unsigned int a2, unsigned __int64 a3)
{
  if ( a2 >= 0x11 )
  {
    __break(0x5512u);
    return _ieee80211_stop_tx_ba_session();
  }
  else
  {
    atomic_store(a3, (unsigned __int64 *)(result + 8LL * a2 + 904));
  }
  return result;
}
