__int64 __fastcall icnss_vreg_on_single(__int64 a1)
{
  const char *v2; // x2
  __int64 result; // x0
  __int64 v4; // x1
  int v5; // w0
  __int64 v6; // x1
  int v7; // w0
  unsigned int v8; // w20
  unsigned int v9; // w20
  unsigned int v10; // w20

  v2 = *(const char **)(a1 + 24);
  if ( *(_DWORD *)(a1 + 56) )
  {
    ipc_log_string(icnss_ipc_log_context, "Regulator %s is already enabled\n", v2);
    return 0;
  }
  else
  {
    ipc_log_string(icnss_ipc_log_context, "Regulator %s is being enabled\n", v2);
    v4 = *(unsigned int *)(a1 + 32);
    if ( (_DWORD)v4 && *(_DWORD *)(a1 + 36) && (v5 = regulator_set_voltage(*(_QWORD *)(a1 + 16), v4)) != 0 )
    {
      v10 = v5;
      printk(
        "%sFailed to set voltage for regulator %s, min_uv: %u, max_uv: %u, err = %d\n",
        byte_130B32,
        *(const char **)(a1 + 24),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 36),
        v5);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sFailed to set voltage for regulator %s, min_uv: %u, max_uv: %u, err = %d\n",
        (const char *)&unk_12DBF3,
        *(const char **)(a1 + 24),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 36),
        v10);
      return v10;
    }
    else
    {
      v6 = *(unsigned int *)(a1 + 40);
      if ( (_DWORD)v6 && (v7 = regulator_set_load(*(_QWORD *)(a1 + 16), v6), v7 < 0) )
      {
        v9 = v7;
        printk(
          "%sFailed to set load for regulator %s, load: %u, err = %d\n",
          byte_130B32,
          *(const char **)(a1 + 24),
          *(_DWORD *)(a1 + 40),
          v7);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sFailed to set load for regulator %s, load: %u, err = %d\n",
          (const char *)&unk_12DBF3,
          *(const char **)(a1 + 24),
          *(_DWORD *)(a1 + 40),
          v9);
        return v9;
      }
      else
      {
        if ( *(_DWORD *)(a1 + 44) )
          _udelay();
        result = regulator_enable(*(_QWORD *)(a1 + 16));
        if ( (_DWORD)result )
        {
          v8 = result;
          printk("%sFailed to enable regulator %s, err = %d\n", byte_130B32, *(const char **)(a1 + 24), result);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sFailed to enable regulator %s, err = %d\n",
            (const char *)&unk_12DBF3,
            *(const char **)(a1 + 24),
            v8);
          return v8;
        }
        else
        {
          *(_DWORD *)(a1 + 56) = 1;
        }
      }
    }
  }
  return result;
}
