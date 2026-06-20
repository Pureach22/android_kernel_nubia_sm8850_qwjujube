__int64 __fastcall rmnet_perf_tether_state_notifier(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x2

  v3 = *a3;
  if ( *a3 && !strncmp((const char *)(v3 + 296), "rmnet_data", 0xAu) )
  {
    if ( a2 == 6 )
    {
      if ( rmnet_perf_tether )
      {
        if ( --*(_BYTE *)rmnet_perf_tether == 0 )
        {
          v7 = printk(&unk_743F, "rmnet_perf_tether_state_notifier", v3 + 296);
          rmnet_perf_tether_state_free(v7);
        }
      }
    }
    else if ( a2 == 5 )
    {
      if ( rmnet_perf_tether )
      {
        ++*(_BYTE *)rmnet_perf_tether;
      }
      else
      {
        v8 = printk(&unk_73C0, "rmnet_perf_tether_state_notifier", v3 + 296);
        if ( (unsigned int)rmnet_perf_tether_state_init(v8) )
          printk(&unk_73A1, "rmnet_perf_tether_state_notifier", v9);
      }
    }
  }
  return 0;
}
