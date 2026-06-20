__int64 __fastcall hdd_cancel_ip_notifier_work(__int64 a1)
{
  cancel_work_sync(a1 + 48);
  return cancel_work_sync(a1 + 80);
}
