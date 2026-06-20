__int64 __fastcall synx_cdsp_restart_notifier(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x19
  __int64 result; // x0

  v6 = synx_dev;
  if ( synx_dev + 416 == a1 )
  {
    result = 0;
    if ( a2 > 1 )
    {
      if ( a2 == 2 )
        return result;
      if ( a2 == 3 )
      {
        if ( *(_QWORD *)(synx_dev + 400) )
        {
          if ( (synx_debug & 4) != 0 )
            printk(&unk_27A72, "info", "synx_cdsp_restart_notifier", 4053, a5, a6);
          synx_global_recover(1);
        }
        return 0;
      }
    }
    else
    {
      if ( !a2 )
        return result;
      if ( a2 == 1 )
      {
        if ( (synx_debug & 8) != 0 )
        {
          printk(&unk_292E3, &unk_2A972, "synx_cdsp_restart_notifier", 4060, a5, a6);
          if ( !*(_QWORD *)(v6 + 400) )
            goto LABEL_10;
        }
        else if ( !*(_QWORD *)(synx_dev + 400) )
        {
LABEL_10:
          *(_QWORD *)(v6 + 400) = 1;
          return 0;
        }
        return 0;
      }
    }
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2858E, &unk_29207, "synx_cdsp_restart_notifier", 4065, a5, a6);
    return 0;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_25E2C, &unk_29207, "synx_cdsp_restart_notifier", 4044, a5, a6);
  return 32770;
}
