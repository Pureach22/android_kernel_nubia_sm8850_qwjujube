__int64 sub_2A3508()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AA4DC);
  return ucfg_mlme_get_wmi_wq_watchdog_timeout();
}
