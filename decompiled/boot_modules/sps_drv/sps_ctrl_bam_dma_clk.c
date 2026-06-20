__int64 __fastcall sps_ctrl_bam_dma_clk(char a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  unsigned int v5; // w0
  __int64 result; // x0
  unsigned int v7; // w22
  unsigned int v8; // w19
  __int64 v9; // x8
  __int64 v10; // x19

  if ( sps && *(_DWORD *)(sps + 48) )
  {
    if ( (a1 & 1) != 0 )
    {
      if ( (unsigned __int8)logging_option >= 2u
        && (unsigned __int8)debug_level_option >= 3u
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_ctrl_bam_dma_clk__rs_147, "sps_ctrl_bam_dma_clk")) )
      {
        printk(&unk_2919C, "sps_ctrl_bam_dma_clk", "sps:vote for bam dma clk\n");
      }
      v3 = sps;
      if ( sps && *(_DWORD *)(sps + 288) <= 1u )
      {
        ipc_log_string(*(_QWORD *)(sps + 256), "%s: %s", "sps_ctrl_bam_dma_clk", "sps:vote for bam dma clk\n");
        v3 = sps;
      }
      v4 = *(_QWORD *)(v3 + 32);
      v5 = clk_prepare(v4);
      if ( !v5 )
      {
        result = clk_enable(v4);
        if ( !(_DWORD)result )
          return result;
        v7 = result;
        clk_unprepare(v4);
        v5 = v7;
      }
      v8 = v5;
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_ctrl_bam_dma_clk__rs_151, "sps_ctrl_bam_dma_clk")) )
      {
        printk(&unk_29DEE, "sps_ctrl_bam_dma_clk", v8);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:fail to enable bamdma_clk:ret=%d\n", "sps_ctrl_bam_dma_clk", v8);
      return v8;
    }
    else
    {
      if ( (unsigned __int8)logging_option >= 2u
        && (unsigned __int8)debug_level_option >= 3u
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_ctrl_bam_dma_clk__rs_154, "sps_ctrl_bam_dma_clk")) )
      {
        printk(&unk_2919C, "sps_ctrl_bam_dma_clk", "sps:relinquish bam dma clk\n");
      }
      v9 = sps;
      if ( sps && *(_DWORD *)(sps + 288) <= 1u )
      {
        ipc_log_string(*(_QWORD *)(sps + 256), "%s: %s", "sps_ctrl_bam_dma_clk", "sps:relinquish bam dma clk\n");
        v9 = sps;
      }
      v10 = *(_QWORD *)(v9 + 32);
      clk_disable(v10);
      clk_unprepare(v10);
      return 0;
    }
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && debug_level_option
      && (!print_limit_option || (unsigned int)__ratelimit(&sps_ctrl_bam_dma_clk__rs, "sps_ctrl_bam_dma_clk")) )
    {
      printk(&unk_24F08, "sps_ctrl_bam_dma_clk", a3);
    }
    if ( sps && *(_DWORD *)(sps + 288) <= 3u )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver is not ready\n", "sps_ctrl_bam_dma_clk");
    return 4294966779LL;
  }
}
