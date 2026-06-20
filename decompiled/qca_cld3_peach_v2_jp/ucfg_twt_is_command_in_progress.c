__int64 ucfg_twt_is_command_in_progress()
{
  return ((__int64 (*)(void))wlan_twt_is_command_in_progress)() & 1;
}
