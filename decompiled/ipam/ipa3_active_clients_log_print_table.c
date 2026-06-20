__int64 __fastcall ipa3_active_clients_log_print_table(__int64 a1, int a2)
{
  int v4; // w20
  __int64 i; // x25
  __int64 *j; // x26
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  int v10; // w8
  int v11; // w0
  int v12; // w19
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = raw_spin_lock_irqsave(ipa3_ctx + 30560);
  v4 = scnprintf(a1, a2, "\n---- Active Clients Table ----\n");
  for ( i = 0; i != 50; ++i )
  {
    for ( j = *(__int64 **)(ipa3_ctx + 8 * i + 31544); j; j = (__int64 *)*j )
    {
      v10 = *((_DWORD *)j + 15);
      if ( v10 > 1 )
      {
        if ( v10 == 2 )
        {
          v11 = scnprintf(a1 + v4, a2 - v4, "%-40s %-3d RESOURCE\n", j + 2, *((unsigned int *)j + 14));
        }
        else
        {
          if ( v10 != 3 )
          {
LABEL_5:
            printk(&unk_3F6EE5, "ipa3_active_clients_log_print_table");
            v7 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v8 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v8 )
              {
                ipc_log_string(
                  v8,
                  "ipa %s:%d Trying to print illegal active_clients type",
                  "ipa3_active_clients_log_print_table",
                  792);
                v7 = ipa3_ctx;
              }
              v9 = *(_QWORD *)(v7 + 34160);
              if ( v9 )
                ipc_log_string(
                  v9,
                  "ipa %s:%d Trying to print illegal active_clients type",
                  "ipa3_active_clients_log_print_table",
                  792);
            }
            continue;
          }
          v11 = scnprintf(a1 + v4, a2 - v4, "%-40s %-3d SPECIAL\n", j + 2, *((unsigned int *)j + 14));
        }
      }
      else if ( v10 )
      {
        if ( v10 != 1 )
          goto LABEL_5;
        v11 = scnprintf(a1 + v4, a2 - v4, "%-40s %-3d SIMPLE\n", j + 2, *((unsigned int *)j + 14));
      }
      else
      {
        v11 = scnprintf(a1 + v4, a2 - v4, "%-40s %-3d ENDPOINT\n", j + 2, *((unsigned int *)j + 14));
      }
      v4 += v11;
    }
  }
  v12 = scnprintf(a1 + v4, a2 - v4, "\nTotal active clients count: %d\n", *(_DWORD *)(ipa3_ctx + 30552));
  raw_spin_unlock_irqrestore(ipa3_ctx + 30560, v14);
  return (unsigned int)(v12 + v4);
}
