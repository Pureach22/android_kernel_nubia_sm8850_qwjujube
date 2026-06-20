__int64 __fastcall sps_connect(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w9
  const void **v7; // x23
  __int64 v8; // x8
  _QWORD *v9; // x21
  _QWORD *v10; // x0
  _QWORD *v11; // x20
  const void **v12; // x1
  const char *v13; // x6
  unsigned int v14; // w0
  unsigned int v15; // w21

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_connect__rs, "sps_connect")) )
    {
      printk(&unk_228D4, "sps_connect", a3);
    }
    if ( sps )
    {
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_connect");
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  if ( !a2 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_connect__rs_35, "sps_connect")) )
    {
      printk(&unk_288B0, "sps_connect", a3);
    }
    if ( sps )
    {
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: connection is NULL\n", "sps_connect");
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  if ( !sps )
    return 4294967277LL;
  if ( *(_DWORD *)(sps + 48) )
  {
    v3 = *(_DWORD *)(a2 + 124);
    if ( v3 != -858993460 && v3 >= 0x20 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_connect__rs_40, "sps_connect")) )
      {
        printk(&unk_2A9B4, "sps_connect", a3);
      }
      if ( sps )
      {
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: The value of pipe lock group is invalid\n", "sps_connect");
        return 0xFFFFFFFFLL;
      }
      return 0xFFFFFFFFLL;
    }
    mutex_lock(sps + 112);
    v7 = (const void **)a2;
    v8 = 24;
    if ( !*(_DWORD *)(a2 + 44) )
      v8 = 0;
    v9 = *(_QWORD **)(a2 + v8);
    v10 = sps_h2bam(v9);
    if ( v10 )
    {
      v11 = v10;
      mutex_lock(v10 + 21);
      if ( (unsigned __int8)logging_option >= 2u
        && (unsigned __int8)debug_level_option >= 2u
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_connect__rs_46, "sps_connect")) )
      {
        printk(&unk_253E8, "sps_connect", v11 + 3);
      }
      v12 = v7;
      if ( *((_DWORD *)v11 + 142) <= 2u )
      {
        if ( *((_DWORD *)v7 + 11) )
          v13 = "DEST";
        else
          v13 = (const char *)&unk_2A9E8;
        ipc_log_string(
          v11[68],
          "%s: sps: bam %pa src 0x%pK dest 0x%pK mode %s\n",
          "sps_connect",
          v11 + 3,
          *v7,
          v7[3],
          v13);
        v12 = v7;
      }
      memcpy((void *)(a1 + 32), v12, 0x90u);
      v14 = sps_rm_state_change(a1, 22237267);
      if ( v14 )
      {
        v15 = v14;
        mutex_unlock(v11 + 21);
      }
      else
      {
        v15 = sps_rm_state_change(a1, 39014483);
        mutex_unlock(v11 + 21);
        if ( v15 )
          sps_disconnect(a1);
      }
    }
    else
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_connect__rs_43, "sps_connect")) )
      {
        printk(&unk_2A129, "sps_connect", v9);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:Invalid BAM device handle: 0x%pK\n", "sps_connect", v9);
      v15 = -1;
    }
    mutex_unlock(sps + 112);
    return v15;
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_connect__rs_38, "sps_connect")) )
    {
      printk(&unk_28D16, "sps_connect", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver is not ready\n", "sps_connect");
    return 4294967285LL;
  }
}
