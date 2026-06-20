__int64 __fastcall dfs_task_testtimer_detach(__int64 a1)
{
  __int64 result; // x0

  result = timer_delete_sync(a1 + 168);
  *(_BYTE *)(a1 + 152) &= ~4u;
  return result;
}
