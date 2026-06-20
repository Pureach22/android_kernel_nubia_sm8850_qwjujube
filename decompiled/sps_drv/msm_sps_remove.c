__int64 __fastcall msm_sps_remove(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x8

  if ( (unsigned __int8)logging_option >= 2u
    && debug_level_option
    && (!print_limit_option || (unsigned int)__ratelimit(&msm_sps_remove__rs, "msm_sps_remove")) )
  {
    printk(&unk_299F7, "msm_sps_remove", a3);
  }
  v3 = sps;
  if ( sps && *(_DWORD *)(sps + 288) <= 3u )
  {
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: Enter\n", "msm_sps_remove");
    v3 = sps;
  }
  device_destroy(*(_QWORD *)v3, *(unsigned int *)(v3 + 8));
  unregister_chrdev_region(*(unsigned int *)(sps + 8), 1);
  v4 = class_destroy(*(_QWORD *)sps);
  if ( (unsigned __int8)logging_option >= 2u )
  {
    if ( debug_level_option )
    {
      if ( !print_limit_option || (v4 = __ratelimit(&sps_device_de_init__rs, "sps_device_de_init"), (_DWORD)v4) )
        v4 = printk(&unk_26A3F, "sps_device_de_init", v5);
    }
  }
  v6 = sps;
  if ( sps )
  {
    if ( *(_DWORD *)(sps + 288) > 3u
      || (v4 = ipc_log_string(*(_QWORD *)(sps + 272), "%s: Enter\n", "sps_device_de_init"), (v6 = sps) != 0) )
    {
      if ( *(_QWORD *)(v6 + 160) != v6 + 160 )
      {
        if ( logging_option != 1 )
        {
          if ( (unsigned __int8)print_limit_option < 3u
            || (v4 = __ratelimit(&sps_device_de_init__rs_397, "sps_device_de_init"), (_DWORD)v4) )
          {
            v4 = printk(&unk_285DF, "sps_device_de_init", v5);
          }
        }
        if ( sps )
          v4 = ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAMs are still registered\n", "sps_device_de_init");
      }
      v4 = sps_map_de_init(v4);
    }
  }
  sps_mem_de_init(v4);
  clk_put(*(_QWORD *)(sps + 40));
  if ( !d_type )
    clk_put(*(_QWORD *)(sps + 24));
  return clk_put(*(_QWORD *)(sps + 32));
}
