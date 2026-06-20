__int64 __fastcall sps_device_reset(_QWORD *a1, __int64 a2, __int64 a3)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x20
  unsigned int v6; // w21

  if ( a1 )
  {
    if ( sps && *(_DWORD *)(sps + 48) )
    {
      mutex_lock(sps + 112);
      v4 = sps_h2bam(a1);
      if ( v4 )
      {
        v5 = v4;
        mutex_lock(v4 + 21);
        v6 = sps_bam_reset(v5);
        mutex_unlock(v5 + 21);
        if ( v6 )
        {
          if ( logging_option != 1
            && ((unsigned __int8)print_limit_option < 3u
             || (unsigned int)__ratelimit(&sps_device_reset__rs_96, "sps_device_reset")) )
          {
            printk(&unk_2668A, "sps_device_reset", a1);
          }
          if ( sps )
            ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:Fail to reset BAM device: 0x%pK\n", "sps_device_reset", a1);
        }
      }
      else
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_device_reset__rs_95, "sps_device_reset")) )
        {
          printk(&unk_2A129, "sps_device_reset", a1);
        }
        v6 = -1;
        if ( sps )
          ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:Invalid BAM device handle: 0x%pK\n", "sps_device_reset", a1);
      }
      mutex_unlock(sps + 112);
      return v6;
    }
    else
    {
      if ( (unsigned __int8)logging_option >= 2u
        && debug_level_option
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_device_reset__rs_94, "sps_device_reset")) )
      {
        printk(&unk_24F08, "sps_device_reset", a3);
      }
      if ( sps && *(_DWORD *)(sps + 288) <= 3u )
      {
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver is not ready\n", "sps_device_reset");
        return 4294966779LL;
      }
      else
      {
        return 4294966779LL;
      }
    }
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_device_reset__rs, "sps_device_reset")) )
    {
      printk(&unk_292C5, "sps_device_reset", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: device handle should not be 0\n", "sps_device_reset");
    return 0xFFFFFFFFLL;
  }
}
