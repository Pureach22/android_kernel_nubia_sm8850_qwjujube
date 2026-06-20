__int64 __fastcall st21nfc_dev_power_stats_handler(__int64 a1, __int64 a2)
{
  queue_work_on(32, *(_QWORD *)(a2 + 712), a2 + 720);
  return 1;
}
