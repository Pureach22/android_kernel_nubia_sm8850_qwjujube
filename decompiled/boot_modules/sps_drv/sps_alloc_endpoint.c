__int64 __fastcall sps_alloc_endpoint(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x2
  __int64 v4; // x19

  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_alloc_endpoint__rs, "sps_alloc_endpoint")) )
  {
    printk(&unk_299F7, "sps_alloc_endpoint", a3);
  }
  if ( sps && !*(_DWORD *)(sps + 288) )
    ipc_log_string(*(_QWORD *)(sps + 248), "%s: sps: Enter\n", "sps_alloc_endpoint");
  v4 = _kmalloc_cache_noprof(ipc_log_context_destroy, 3520, 648);
  if ( v4 )
  {
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 4u
      && (!print_limit_option || (unsigned int)__ratelimit(&sps_client_init__rs, "sps_client_init")) )
    {
      printk(&unk_26A3F, "sps_client_init", v3);
    }
    if ( sps && !*(_DWORD *)(sps + 288) )
      ipc_log_string(*(_QWORD *)(sps + 248), "%s: Enter\n", "sps_client_init");
    memset((void *)v4, 0, 0x288u);
    sps_rm_config_init(v4 + 32);
    *(_DWORD *)(v4 + 16) = 0;
    *(_QWORD *)(v4 + 24) = 0;
  }
  return v4;
}
