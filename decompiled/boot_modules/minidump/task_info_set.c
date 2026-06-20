__int64 task_info_set()
{
  int v0; // w20
  __int64 result; // x0
  int v2; // w21

  v0 = task_info;
  if ( (unsigned int)param_set_int() || (unsigned int)task_info >= 2 )
  {
    task_info = v0;
    return 4294967274LL;
  }
  else if ( v0 == task_info )
  {
    return 0;
  }
  else
  {
    if ( task_info == 1 )
      v2 = 150;
    else
      v2 = 8;
    result = update_task_info_entry((unsigned int)(v2 << 12));
    if ( (_DWORD)result )
      task_info = v0;
    else
      task_info_pages = v2;
  }
  return result;
}
