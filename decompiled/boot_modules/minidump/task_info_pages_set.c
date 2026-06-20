__int64 task_info_pages_set()
{
  int v0; // w20
  int v1; // w8
  __int64 result; // x0

  v0 = task_info_pages;
  v1 = param_set_int();
  result = 4294967274LL;
  if ( v1 || (unsigned int)task_info_pages > 0x400 )
    goto LABEL_6;
  if ( v0 == task_info_pages )
    return 0;
  result = update_task_info_entry((__int64)task_info_pages << 12);
  if ( (_DWORD)result )
LABEL_6:
    task_info_pages = v0;
  return result;
}
