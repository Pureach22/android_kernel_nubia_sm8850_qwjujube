__int64 __fastcall sps_free_endpoint(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w8
  __int64 v5; // x2

  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_free_endpoint__rs, "sps_free_endpoint")) )
  {
    printk(&unk_299F7, "sps_free_endpoint", a3);
  }
  if ( sps && !*(_DWORD *)(sps + 288) )
  {
    ipc_log_string(*(_QWORD *)(sps + 248), "%s: sps: Enter\n", "sps_free_endpoint");
    v4 = (unsigned __int8)logging_option;
    if ( a1 )
      goto LABEL_5;
LABEL_15:
    if ( v4 != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_free_endpoint__rs_256, "sps_free_endpoint")) )
    {
      printk(&unk_228D4, "sps_free_endpoint", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_free_endpoint");
    return 0xFFFFFFFFLL;
  }
  v4 = (unsigned __int8)logging_option;
  if ( !a1 )
    goto LABEL_15;
LABEL_5:
  if ( v4 >= 2
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_client_de_init__rs, "sps_client_de_init")) )
  {
    printk(&unk_26A3F, "sps_client_de_init", a3);
  }
  if ( sps && !*(_DWORD *)(sps + 288) )
  {
    ipc_log_string(*(_QWORD *)(sps + 248), "%s: Enter\n", "sps_client_de_init");
    v5 = *(unsigned int *)(a1 + 16);
    if ( (_DWORD)v5 )
    {
LABEL_9:
      if ( logging_option == 1 )
        goto LABEL_12;
      if ( (unsigned __int8)print_limit_option >= 3u )
      {
        if ( !(unsigned int)__ratelimit(&sps_client_de_init__rs_280, "sps_client_de_init") )
        {
LABEL_12:
          if ( sps )
            ipc_log_string(
              *(_QWORD *)(sps + 272),
              "%s: sps:De-init client in connected state: 0x%x\n",
              "sps_client_de_init",
              *(_DWORD *)(a1 + 16));
          return 0xFFFFFFFFLL;
        }
        v5 = *(unsigned int *)(a1 + 16);
      }
      printk(&unk_2730C, "sps_client_de_init", v5);
      goto LABEL_12;
    }
  }
  else
  {
    v5 = *(unsigned int *)(a1 + 16);
    if ( (_DWORD)v5 )
      goto LABEL_9;
  }
  *(_QWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 64) = 0;
  *(_QWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  *(_QWORD *)(a1 + 88) = 0;
  *(_QWORD *)(a1 + 96) = 0;
  *(_QWORD *)(a1 + 104) = 0;
  *(_QWORD *)(a1 + 112) = 0;
  *(_QWORD *)(a1 + 120) = 0;
  *(_QWORD *)(a1 + 128) = 0;
  *(_QWORD *)(a1 + 136) = 0;
  *(_QWORD *)(a1 + 144) = 0;
  *(_QWORD *)(a1 + 152) = 0;
  *(_QWORD *)(a1 + 160) = 0;
  *(_QWORD *)(a1 + 168) = 0;
  *(_QWORD *)(a1 + 176) = 0;
  kfree(a1);
  return 0;
}
