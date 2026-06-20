__int64 __fastcall trigger_dump_enable_get(__int64 a1, _QWORD *a2)
{
  mutex_lock(a1 + 48);
  *a2 = *(unsigned __int8 *)(a1 + 136);
  mutex_unlock(a1 + 48);
  return 0;
}
