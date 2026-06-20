__int64 __fastcall _icnss_register_driver(_QWORD *a1)
{
  __int64 v1; // x20
  __int64 v3; // x2
  int v4; // w9
  unsigned __int16 *v5; // x10
  int v6; // t1
  __int64 result; // x0

  v1 = penv;
  if ( penv && *(_QWORD *)(penv + 8) )
  {
    ipc_log_string(icnss_ipc_log_context, "icnss2: Registering driver, state: 0x%lx\n", *(_QWORD *)(penv + 1832));
    if ( *(_QWORD *)(v1 + 16) )
    {
      printk("%sicnss2: Driver already registered\n", byte_130B32);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Driver already registered\n", (const char *)&unk_12DBF3);
      return 4294967279LL;
    }
    else
    {
      v3 = a1[1];
      if ( v3 )
      {
        v4 = *(unsigned __int16 *)(v3 + 10);
        if ( *(_WORD *)(v3 + 10) )
        {
          v5 = (unsigned __int16 *)(v3 + 22);
          while ( *(_QWORD *)(v1 + 304) != v4 )
          {
            v6 = *v5;
            v5 += 6;
            v4 = v6;
            if ( !v6 )
              goto LABEL_9;
          }
          if ( a1[25] && a1[26] )
          {
            LODWORD(result) = icnss_driver_event_post(v1, 3u, 0, (__int64)a1);
            if ( (_DWORD)result == -4 )
              return 0;
            else
              return (unsigned int)result;
          }
          else
          {
            return 4294967274LL;
          }
        }
        else
        {
LABEL_9:
          printk(
            "%sicnss2: WLAN driver dev name is %s, not supported by platform driver\n",
            byte_130B32,
            (const char *)v3);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2: WLAN driver dev name is %s, not supported by platform driver\n",
            (const char *)&unk_12DBF3,
            (const char *)a1[1]);
          return 4294967277LL;
        }
      }
      else
      {
        printk("%sicnss2: WLAN driver devinfo is null, Reject wlan driver loading", byte_130B32);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: WLAN driver devinfo is null, Reject wlan driver loading",
          (const char *)&unk_12DBF3);
        return 4294967274LL;
      }
    }
  }
  else
  {
    ipc_log_string(icnss_ipc_log_long_context, "icnss2: icnss2 is not ready for register driver\n");
    return 4294967285LL;
  }
}
