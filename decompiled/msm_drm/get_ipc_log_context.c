__int64 get_ipc_log_context()
{
  __int64 result; // x0

  if ( !g_dp_display )
    return 0;
  result = *(_QWORD *)(g_dp_display + 56);
  if ( !result )
    return 0;
  return result;
}
