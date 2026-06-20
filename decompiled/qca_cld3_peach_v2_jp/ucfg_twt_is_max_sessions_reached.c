__int64 ucfg_twt_is_max_sessions_reached()
{
  return ((__int64 (*)(void))wlan_twt_is_max_sessions_reached)() & 1;
}
