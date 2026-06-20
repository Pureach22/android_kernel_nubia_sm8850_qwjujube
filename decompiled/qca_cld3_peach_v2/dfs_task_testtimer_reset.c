__int64 __fastcall dfs_task_testtimer_reset(__int64 result)
{
  __int64 v1; // x19

  if ( (*(_BYTE *)(result + 152) & 4) != 0 )
  {
    v1 = result;
    result = timer_delete_sync(result + 168);
    *(_BYTE *)(v1 + 152) &= ~4u;
  }
  return result;
}
