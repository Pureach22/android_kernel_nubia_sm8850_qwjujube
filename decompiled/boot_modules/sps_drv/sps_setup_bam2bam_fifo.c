__int64 __fastcall sps_setup_bam2bam_fifo(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  unsigned int v4; // w19
  __int64 v5; // x22
  unsigned int v6; // w23
  int v7; // w24
  void *v8; // x0
  unsigned __int64 v10; // x10
  __int64 v11; // x8
  __int64 v12; // x20
  void *mem_ptr; // x0
  __int64 v14; // x20
  unsigned int v15; // w22
  int v16; // w23
  __int64 v17; // x20
  unsigned int v18; // w22
  int v19; // w23
  int v20; // w0
  int v21; // w8

  v4 = a3;
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 3u )
  {
    if ( !print_limit_option )
      goto LABEL_37;
    v17 = a1;
    v18 = a2;
    v19 = a4;
    v20 = __ratelimit(&sps_setup_bam2bam_fifo__rs, "sps_setup_bam2bam_fifo");
    a4 = v19;
    a2 = v18;
    v21 = v20;
    a1 = v17;
    if ( v21 )
    {
LABEL_37:
      v14 = a1;
      v15 = a2;
      v16 = a4;
      printk(&unk_26A3F, "sps_setup_bam2bam_fifo", a3);
      a4 = v16;
      a2 = v15;
      a1 = v14;
    }
  }
  if ( sps && *(_DWORD *)(sps + 288) <= 1u )
  {
    v5 = a1;
    v6 = a2;
    v7 = a4;
    ipc_log_string(*(_QWORD *)(sps + 256), "%s: Enter\n", "sps_setup_bam2bam_fifo");
    a4 = v7;
    a2 = v6;
    a1 = v5;
  }
  if ( !a1 || !v4 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_setup_bam2bam_fifo__rs_20, "sps_setup_bam2bam_fifo")) )
    {
      printk(&unk_26A4C, "sps_setup_bam2bam_fifo", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: invalid buffer address or size\n", "sps_setup_bam2bam_fifo");
    return 0xFFFFFFFFLL;
  }
  if ( sps && *(_DWORD *)(sps + 48) )
  {
    if ( a4 )
    {
      if ( v4 + a2 > *(_DWORD *)(sps + 64) )
      {
        if ( logging_option == 1 )
          goto LABEL_30;
        if ( (unsigned __int8)print_limit_option < 3u )
          goto LABEL_29;
        v8 = &sps_setup_bam2bam_fifo__rs_24;
LABEL_44:
        if ( !(unsigned int)__ratelimit(v8, "sps_setup_bam2bam_fifo") )
        {
LABEL_30:
          if ( sps )
            ipc_log_string(
              *(_QWORD *)(sps + 272),
              "%s: sps: requested mem is out of pipe mem range\n",
              "sps_setup_bam2bam_fifo");
          return 0xFFFFFFFFLL;
        }
LABEL_29:
        printk(&unk_26199, "sps_setup_bam2bam_fifo", a3);
        goto LABEL_30;
      }
      v11 = *(_QWORD *)(sps + 56) + a2;
    }
    else
    {
      v10 = *(_QWORD *)(sps + 56);
      v11 = a2;
      if ( v10 > a2 || v10 + *(unsigned int *)(sps + 64) < v4 + a2 )
      {
        if ( logging_option == 1 )
          goto LABEL_30;
        if ( (unsigned __int8)print_limit_option < 3u )
          goto LABEL_29;
        v8 = &sps_setup_bam2bam_fifo__rs_27;
        goto LABEL_44;
      }
    }
    *(_QWORD *)(a1 + 8) = v11;
    v12 = a1;
    mem_ptr = (void *)spsi_get_mem_ptr(v11);
    *(_DWORD *)(v12 + 24) = v4;
    *(_QWORD *)v12 = mem_ptr;
    memset(mem_ptr, 0, v4);
    return 0;
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && debug_level_option
      && (!print_limit_option || (unsigned int)__ratelimit(&sps_setup_bam2bam_fifo__rs_23, "sps_setup_bam2bam_fifo")) )
    {
      printk(&unk_24F08, "sps_setup_bam2bam_fifo", a3);
    }
    if ( sps && *(_DWORD *)(sps + 288) <= 3u )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver is not ready\n", "sps_setup_bam2bam_fifo");
    return 4294966779LL;
  }
}
