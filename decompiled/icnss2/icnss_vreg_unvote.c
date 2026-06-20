__int64 __fastcall icnss_vreg_unvote(__int64 a1)
{
  __int64 v1; // x26
  __int64 v2; // x27
  unsigned __int64 v3; // x8
  const char *v4; // x2
  int v5; // w0
  int v6; // w0
  int v7; // w25
  int v8; // w25

  v1 = *(_QWORD *)(a1 + 224);
  v2 = a1 + 216;
  while ( v1 != v2 )
  {
    v3 = *(_QWORD *)(v1 + 16);
    if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL && *(_DWORD *)(v1 + 48) )
    {
      v4 = *(const char **)(v1 + 24);
      if ( *(_DWORD *)(v1 + 56) )
      {
        ipc_log_string(icnss_ipc_log_context, "Removing vote for Regulator %s\n", v4);
        if ( *(_DWORD *)(v1 + 40) && (v5 = regulator_set_load(*(_QWORD *)(v1 + 16), 0), v5 < 0) )
        {
          v8 = v5;
          printk("%sFailed to set load for regulator %s, err = %d\n", byte_130B32, *(const char **)(v1 + 24), v5);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sFailed to set load for regulator %s, err = %d\n",
            (const char *)&unk_12DBF3,
            *(const char **)(v1 + 24),
            v8);
          if ( *(_DWORD *)(v1 + 32) )
          {
LABEL_12:
            if ( *(_DWORD *)(v1 + 36) )
            {
              v6 = regulator_set_voltage(*(_QWORD *)(v1 + 16), 0);
              if ( v6 )
              {
                v7 = v6;
                printk(
                  "%sFailed to set voltage for regulator %s, err = %d\n",
                  byte_130B32,
                  *(const char **)(v1 + 24),
                  v6);
                ipc_log_string(
                  icnss_ipc_log_context,
                  "%sFailed to set voltage for regulator %s, err = %d\n",
                  (const char *)&unk_12DBF3,
                  *(const char **)(v1 + 24),
                  v7);
              }
            }
          }
        }
        else if ( *(_DWORD *)(v1 + 32) )
        {
          goto LABEL_12;
        }
      }
      else
      {
        ipc_log_string(icnss_ipc_log_context, "Regulator %s is already disabled\n", v4);
      }
    }
    v1 = *(_QWORD *)(v1 + 8);
  }
  return 0;
}
