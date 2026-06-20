__int64 __fastcall sps_bam_disable(__int64 result)
{
  unsigned int v1; // w8
  int v2; // w9
  __int64 v3; // x19
  __int64 v4; // x19
  int v5; // w9
  unsigned int v6; // w8
  unsigned int v7; // w9
  unsigned int v8; // w8
  __int64 v9; // x19
  __int64 v10; // x19
  int v11; // w8
  __int64 v12; // x19
  __int64 v13; // x19
  int v14; // w8

  v1 = *(_DWORD *)(result + 160);
  if ( (v1 & 8) == 0 )
    return 0;
  v2 = *(_DWORD *)(result + 120);
  if ( (~(_BYTE)v2 & 0x1D) != 0 )
  {
    if ( (v2 & 1) != 0 )
    {
      *(_DWORD *)(result + 160) = v1 & 0xFFFFFFF7;
      if ( (v1 & 4) != 0 )
      {
        v8 = *(_DWORD *)(result + 44);
        if ( v8 )
        {
          v9 = result;
          free_irq(v8, result);
          *(_DWORD *)(v9 + 160) &= ~4u;
          return 0;
        }
      }
      return 0;
    }
    if ( (v1 & 4) != 0 )
    {
      v4 = result;
      bam_exit(result + 216, *(_DWORD *)(result + 128));
      v5 = *(_DWORD *)(v4 + 160);
      result = v4;
      if ( (v5 & 4) != 0 )
      {
        v6 = *(_DWORD *)(v4 + 44);
        if ( v6 )
        {
          free_irq(v6, v4);
          v5 = *(_DWORD *)(v4 + 160);
          result = v4;
        }
      }
      v1 = v5 & 0xFFFFFFFB;
    }
    v7 = (unsigned __int8)logging_option;
    *(_DWORD *)(result + 160) = v1 & 0xFFFFFFF7;
    if ( v7 >= 2 )
    {
      if ( debug_level_option )
      {
        if ( !print_limit_option
          || (v13 = result, v14 = __ratelimit(&sps_bam_disable__rs_72, "sps_bam_disable"), result = v13, v14) )
        {
          v12 = result;
          printk(&unk_289E5, "sps_bam_disable", result + 24);
          result = v12;
        }
      }
    }
    if ( result )
    {
      if ( *(_DWORD *)(result + 568) <= 3u )
        ipc_log_string(
          *(_QWORD *)(result + 552),
          "%s: sps:BAM %pa disabled\n",
          "sps_bam_disable",
          (const void *)(result + 24));
      return 0;
    }
  }
  else
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (v10 = result, v11 = __ratelimit(&sps_bam_disable__rs, "sps_bam_disable"), result = v10, v11) )
      {
        v3 = result;
        printk(&unk_237FB, "sps_bam_disable", result + 24);
        result = v3;
      }
    }
    if ( result )
      ipc_log_string(
        *(_QWORD *)(result + 552),
        "%s: sps:No local access to BAM %pa\n",
        "sps_bam_disable",
        (const void *)(result + 24));
    return 0xFFFFFFFFLL;
  }
  return result;
}
