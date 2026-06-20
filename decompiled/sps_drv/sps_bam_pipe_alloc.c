__int64 __fastcall sps_bam_pipe_alloc(__int64 a1, unsigned int a2)
{
  unsigned int v3; // w20
  __int64 v4; // x9
  unsigned __int64 v5; // x8
  int v6; // w12

  if ( a2 != -1 )
  {
    v3 = a2;
    if ( a2 > 0x1E || *(_DWORD *)(a1 + 48) <= a2 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_alloc__rs_98, "sps_bam_pipe_alloc")) )
      {
        printk(&unk_281F7, "sps_bam_pipe_alloc", v3);
      }
      if ( a1 )
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:Invalid pipe %d for allocate on BAM %pa\n",
          "sps_bam_pipe_alloc",
          v3,
          a1 + 24);
    }
    else if ( (((unsigned __int64)*(unsigned int *)(a1 + 124) >> a2) & 1) != 0 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_alloc__rs_101, "sps_bam_pipe_alloc")) )
      {
        printk(&unk_279FC, "sps_bam_pipe_alloc", a1 + 24);
      }
      if ( a1 )
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:BAM %pa pipe %d is not local\n",
          "sps_bam_pipe_alloc",
          (const void *)(a1 + 24),
          v3);
    }
    else
    {
      v5 = a2;
      if ( !*(_QWORD *)(a1 + 8LL * a2 + 256) )
      {
LABEL_42:
        *(_QWORD *)(a1 + 8 * v5 + 256) = -2290649225LL;
        return v3;
      }
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_alloc__rs_104, "sps_bam_pipe_alloc")) )
      {
        printk(&unk_2AEDB, "sps_bam_pipe_alloc", v3);
      }
      if ( a1 )
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:Pipe %d already allocated on BAM %pa\n",
          "sps_bam_pipe_alloc",
          v3,
          a1 + 24);
    }
    return (unsigned int)-1;
  }
  if ( (*(_BYTE *)(a1 + 120) & 4) != 0 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_alloc__rs, "sps_bam_pipe_alloc")) )
    {
      printk(&unk_24C8D, "sps_bam_pipe_alloc", a1 + 24);
    }
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 552),
        "%s: sps:Restricted from allocating pipes on BAM %pa\n",
        "sps_bam_pipe_alloc",
        a1 + 24);
    return (unsigned int)-1;
  }
  v4 = *(unsigned int *)(a1 + 48);
  if ( !(_DWORD)v4 )
  {
LABEL_29:
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_alloc__rs_95, "sps_bam_pipe_alloc")) )
    {
      printk(&unk_27026, "sps_bam_pipe_alloc", a1 + 24);
    }
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 552), "%s: sps:Fail to allocate pipe on BAM %pa\n", "sps_bam_pipe_alloc", a1 + 24);
    return (unsigned int)-1;
  }
  v5 = 0;
  v6 = 1;
  while ( 1 )
  {
    if ( (*(_DWORD *)(a1 + 124) & v6) != 0 )
      goto LABEL_13;
    if ( v5 >= 0x1F )
      break;
    if ( !*(_QWORD *)(a1 + 256 + 8 * v5) )
    {
      v3 = v5;
      goto LABEL_42;
    }
LABEL_13:
    ++v5;
    v6 *= 2;
    if ( v4 == v5 )
      goto LABEL_29;
  }
  __break(0x5512u);
  return sps_bam_pipe_free();
}
