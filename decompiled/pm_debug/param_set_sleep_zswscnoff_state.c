__int64 __fastcall param_set_sleep_zswscnoff_state(__int64 a1, __int64 a2)
{
  int v4; // w20
  unsigned int v5; // w19
  __int64 v6; // x0
  __int64 (__fastcall *v7)(__int64); // x8
  void *v8; // x0
  __int64 (__fastcall *v9)(__int64); // x8
  unsigned __int64 v10; // x0
  __int64 v11; // x0

  v4 = sleep_zswscnoff_state;
  printk(&unk_9C66);
  v5 = param_set_int(a1, a2);
  v6 = printk(&unk_9B5A);
  if ( sleep_zswscnoff_state == 3 )
  {
    sleep_zswscnoff_state = v4;
    sleep_zswresumeparam_mask = 99;
    printk(&unk_A196);
  }
  else if ( zswsceenoff_state == (sleep_zswscnoff_state != 0) )
  {
    printk(&unk_9A49);
  }
  else
  {
    zswsceenoff_state = sleep_zswscnoff_state != 0;
    if ( sleep_zswscnoff_state )
    {
      v7 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
      zswscreenoffcounter_time = 0;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      zswscreenoffcounter_startpoint = v7(v6);
      screenofftime_delta = 0;
      screenofftime_startpoint = ktime_get_real_seconds(zswscreenoffcounter_startpoint);
      v8 = &unk_A026;
      screenofftime_endpoint = 0;
    }
    else
    {
      v9 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v10 = v9(v6);
      if ( v10 > zswscreenoffcounter_startpoint )
        zswscreenoffcounter_time = v10 - zswscreenoffcounter_startpoint;
      v11 = printk(&unk_A238);
      screenofftime_endpoint = ktime_get_real_seconds(v11);
      if ( screenofftime_endpoint > (unsigned __int64)screenofftime_startpoint )
        screenofftime_delta = screenofftime_endpoint - screenofftime_startpoint;
      v8 = &unk_978F;
    }
    printk(v8);
  }
  return v5;
}
