__int64 __fastcall icnss_vreg_off_single(__int64 a1)
{
  const char *v2; // x2
  __int64 result; // x0
  int v4; // w21
  int v5; // w21
  int v6; // w21

  v2 = *(const char **)(a1 + 24);
  if ( !*(_DWORD *)(a1 + 56) )
    return ipc_log_string(icnss_ipc_log_context, "Regulator %s is already disabled\n", v2);
  ipc_log_string(icnss_ipc_log_context, "Regulator %s is being disabled\n", v2);
  result = regulator_disable(*(_QWORD *)(a1 + 16));
  if ( (_DWORD)result )
  {
    v4 = result;
    printk("%sFailed to disable regulator %s, err = %d\n", byte_130B32, *(const char **)(a1 + 24), result);
    result = ipc_log_string(
               icnss_ipc_log_context,
               "%sFailed to disable regulator %s, err = %d\n",
               (const char *)&unk_12DBF3,
               *(const char **)(a1 + 24),
               v4);
    if ( *(_DWORD *)(a1 + 40) )
    {
LABEL_4:
      result = regulator_set_load(*(_QWORD *)(a1 + 16), 0);
      if ( (result & 0x80000000) != 0 )
      {
        v5 = result;
        printk("%sFailed to set load for regulator %s, err = %d\n", byte_130B32, *(const char **)(a1 + 24), result);
        result = ipc_log_string(
                   icnss_ipc_log_context,
                   "%sFailed to set load for regulator %s, err = %d\n",
                   (const char *)&unk_12DBF3,
                   *(const char **)(a1 + 24),
                   v5);
      }
    }
  }
  else if ( *(_DWORD *)(a1 + 40) )
  {
    goto LABEL_4;
  }
  if ( *(_DWORD *)(a1 + 32) && *(_DWORD *)(a1 + 36) )
  {
    result = regulator_set_voltage(*(_QWORD *)(a1 + 16), 0);
    if ( (_DWORD)result )
    {
      v6 = result;
      printk("%sFailed to set voltage for regulator %s, err = %d\n", byte_130B32, *(const char **)(a1 + 24), result);
      result = ipc_log_string(
                 icnss_ipc_log_context,
                 "%sFailed to set voltage for regulator %s, err = %d\n",
                 (const char *)&unk_12DBF3,
                 *(const char **)(a1 + 24),
                 v6);
    }
  }
  *(_DWORD *)(a1 + 56) = 0;
  return result;
}
