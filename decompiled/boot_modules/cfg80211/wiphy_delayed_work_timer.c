__int64 __fastcall wiphy_delayed_work_timer(__int64 a1)
{
  return wiphy_work_queue(*(_QWORD *)(a1 - 8), (_QWORD *)(a1 - 32));
}
