__int64 __fastcall dfs_main_task_testtimer_init(__int64 a1)
{
  *(_QWORD *)(a1 + 208) = dfs_testtimer_task;
  *(_QWORD *)(a1 + 216) = a1;
  return init_timer_key(a1 + 168, _os_timer_shim_16, 0, 0, 0);
}
