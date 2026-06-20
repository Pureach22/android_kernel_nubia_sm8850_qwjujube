__int64 __fastcall aw22xxx_set_brightness(__int64 a1, int a2)
{
  *(_DWORD *)(a1 + 8) = a2;
  return queue_work_on(32, system_wq, a1 + 448);
}
