bool __fastcall wiphy_delayed_work_pending(__int64 a1, __int64 a2)
{
  return *(_QWORD *)(a2 + 40) != 0;
}
