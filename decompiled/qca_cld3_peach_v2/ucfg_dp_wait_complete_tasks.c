__int64 ucfg_dp_wait_complete_tasks()
{
  __int64 context; // x0

  context = dp_get_context();
  return dp_wait_complete_tasks(context);
}
