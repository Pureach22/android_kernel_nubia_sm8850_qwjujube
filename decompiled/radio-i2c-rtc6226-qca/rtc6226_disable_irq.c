__int64 __fastcall rtc6226_disable_irq(__int64 a1)
{
  unsigned int v1; // w20

  v1 = *(_DWORD *)(a1 + 1856);
  irq_set_irq_wake(v1, 0);
  free_irq(v1, a1);
  cancel_delayed_work_sync(a1 + 2312);
  _flush_workqueue(*(_QWORD *)(a1 + 2032));
  cancel_work_sync(a1 + 2056);
  _flush_workqueue(*(_QWORD *)(a1 + 2048));
  cancel_delayed_work_sync(a1 + 2416);
  return _flush_workqueue(*(_QWORD *)(a1 + 2040));
}
