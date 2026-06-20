__int64 __fastcall rtc6226_isr(__int64 a1, __int64 a2)
{
  queue_delayed_work_on(32, *(_QWORD *)(a2 + 2032), a2 + 2312, 3);
  return 1;
}
