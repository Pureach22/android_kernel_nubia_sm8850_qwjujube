__int64 __fastcall wlan_cp_stats_cstats_qmi_event_handler(__int64 a1, __int16 a2, __int64 a3, unsigned int a4)
{
  if ( a2 == 1 )
    wlan_cp_stats_cstats_write_to_buff(1, a3, a4);
  return 0;
}
