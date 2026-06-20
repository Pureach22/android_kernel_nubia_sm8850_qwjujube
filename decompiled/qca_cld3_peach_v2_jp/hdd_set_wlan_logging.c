__int64 __fastcall hdd_set_wlan_logging(__int64 a1)
{
  wlan_set_console_log_levels(*(unsigned int *)(*(_QWORD *)(a1 + 104) + 40LL));
  return wlan_logging_set_active(*(unsigned __int8 *)(*(_QWORD *)(a1 + 104) + 38LL));
}
