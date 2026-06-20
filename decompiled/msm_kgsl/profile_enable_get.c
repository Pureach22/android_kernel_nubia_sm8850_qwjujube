__int64 __fastcall profile_enable_get(__int64 a1, _QWORD *a2)
{
  rt_mutex_lock(a1 + 11088);
  *a2 = *(unsigned __int8 *)(a1 + 19728);
  rt_mutex_unlock(a1 + 11088);
  return 0;
}
