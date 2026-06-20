__int64 __fastcall icnss_get_ce_id(__int64 a1, int a2)
{
  __int64 result; // x0

  if ( !penv )
    return 4294967277LL;
  result = 4294967277LL;
  if ( a1 && *(_QWORD *)(penv + 8) )
  {
    if ( *(_DWORD *)(penv + 348) == a2 )
    {
      return 0;
    }
    else if ( *(_DWORD *)(penv + 352) == a2 )
    {
      return 1;
    }
    else if ( *(_DWORD *)(penv + 356) == a2 )
    {
      return 2;
    }
    else if ( *(_DWORD *)(penv + 360) == a2 )
    {
      return 3;
    }
    else if ( *(_DWORD *)(penv + 364) == a2 )
    {
      return 4;
    }
    else if ( *(_DWORD *)(penv + 368) == a2 )
    {
      return 5;
    }
    else if ( *(_DWORD *)(penv + 372) == a2 )
    {
      return 6;
    }
    else if ( *(_DWORD *)(penv + 376) == a2 )
    {
      return 7;
    }
    else if ( *(_DWORD *)(penv + 380) == a2 )
    {
      return 8;
    }
    else if ( *(_DWORD *)(penv + 384) == a2 )
    {
      return 9;
    }
    else if ( *(_DWORD *)(penv + 388) == a2 )
    {
      return 10;
    }
    else if ( *(_DWORD *)(penv + 392) == a2 )
    {
      return 11;
    }
    else
    {
      printk("%sicnss2: No matching CE id for irq %d\n", byte_130B32, a2);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: No matching CE id for irq %d\n", (const char *)&unk_12DBF3, a2);
      return 4294967274LL;
    }
  }
  return result;
}
