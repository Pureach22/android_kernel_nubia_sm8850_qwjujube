__int64 __fastcall charger_policy_timeout_alarm_cb(__int64 a1)
{
  alarm_start_relative();
  if ( (*(_QWORD *)(a1 + 128) & 1) == 0 )
    queue_delayed_work_on(32, *(_QWORD *)(a1 + 120), a1 + 128, 25);
  return 1;
}
