__int64 __fastcall wiphy_delayed_work_cancel(__int64 a1, _QWORD *a2)
{
  timer_delete_sync(a2 + 4);
  return wiphy_work_cancel(a1, a2);
}
