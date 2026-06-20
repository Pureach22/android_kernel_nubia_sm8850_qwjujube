__int64 ucfg_twt_is_setup_done()
{
  return ((__int64 (*)(void))wlan_twt_is_setup_done)() & 1;
}
