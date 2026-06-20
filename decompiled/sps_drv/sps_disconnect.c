__int64 __fastcall sps_disconnect(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  const char *v5; // x6
  __int64 v6; // x8
  __int64 result; // x0
  unsigned int v8; // w20

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_disconnect__rs, "sps_disconnect")) )
    {
      printk(&unk_23CA2, "sps_disconnect", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: Invalid pipe\n", "sps_disconnect");
    return 0xFFFFFFFFLL;
  }
  v3 = *(_QWORD *)(a1 + 24);
  if ( !v3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(
                                                                      &sps_disconnect__rs_53,
                                                                      "sps_disconnect")) )
    {
      printk(&unk_2930E, "sps_disconnect", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM device of this pipe is NULL\n", "sps_disconnect");
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 2u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_disconnect__rs_56, "sps_disconnect")) )
  {
    printk(&unk_253E8, "sps_disconnect", v3 + 24);
  }
  if ( *(_DWORD *)(v3 + 568) <= 2u )
  {
    if ( *(_DWORD *)(a1 + 76) )
      v5 = "DEST";
    else
      v5 = (const char *)&unk_2A9E8;
    ipc_log_string(
      *(_QWORD *)(v3 + 544),
      "%s: sps: bam %pa src 0x%pK dest 0x%pK mode %s\n",
      "sps_disconnect",
      (const void *)(v3 + 24),
      *(const void **)(a1 + 32),
      *(const void **)(a1 + 56),
      v5);
  }
  v6 = 176;
  if ( !*(_DWORD *)(a1 + 76) )
    v6 = 168;
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 176) + v6) != a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(
                                                                      &sps_disconnect__rs_57,
                                                                      "sps_disconnect")) )
    {
      printk(&unk_2933A, "sps_disconnect", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: Client context is corrupt\n", "sps_disconnect");
    return 0xFFFFFFFFLL;
  }
  mutex_lock(v3 + 168);
  v8 = sps_rm_state_change(a1, 0);
  mutex_unlock(v3 + 168);
  result = v8;
  if ( !v8 )
  {
    sps_rm_config_init(a1 + 32);
    return 0;
  }
  return result;
}
