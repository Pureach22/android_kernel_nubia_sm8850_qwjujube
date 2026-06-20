__int64 __fastcall ipa3_nat_ipv6ct_free_mem(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0

  v1 = result;
  if ( *(_BYTE *)(result + 221) == 1 )
  {
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d In: v6\n", "ipa3_nat_ipv6ct_free_mem", 2120);
        v2 = ipa3_ctx;
      }
      result = *(_QWORD *)(v2 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d In: v6\n", "ipa3_nat_ipv6ct_free_mem", 2120);
    }
    if ( *(_QWORD *)(v1 + 248) )
    {
      v4 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v5 )
        {
          ipc_log_string(
            v5,
            "ipa %s:%d Freeing dma memory for %s\n",
            "ipa3_nat_ipv6ct_free_mem",
            2123,
            (const char *)v1);
          v4 = ipa3_ctx;
        }
        v6 = *(_QWORD *)(v4 + 34160);
        if ( v6 )
        {
          ipc_log_string(
            v6,
            "ipa %s:%d Freeing dma memory for %s\n",
            "ipa3_nat_ipv6ct_free_mem",
            2123,
            (const char *)v1);
          v4 = ipa3_ctx;
        }
      }
      result = dma_free_attrs(
                 *(_QWORD *)(v4 + 34216),
                 *(_QWORD *)(v1 + 240),
                 *(_QWORD *)(v1 + 248),
                 *(_QWORD *)(v1 + 256),
                 0);
    }
    *(_WORD *)(v1 + 223) = 0;
    *(_QWORD *)(v1 + 240) = 0;
    *(_QWORD *)(v1 + 248) = 0;
    *(_QWORD *)(v1 + 256) = 0;
    *(_QWORD *)(v1 + 272) = 0;
    *(_QWORD *)(v1 + 280) = 0;
    *(_QWORD *)(v1 + 288) = 0;
  }
  else if ( *(_BYTE *)(result + 220) == 1 )
  {
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d In: v4\n", "ipa3_nat_ipv6ct_free_mem", 2145);
        v7 = ipa3_ctx;
      }
      result = *(_QWORD *)(v7 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d In: v4\n", "ipa3_nat_ipv6ct_free_mem", 2145);
    }
    if ( *(_BYTE *)(v1 + 356) == 1 )
    {
      v9 = *(_QWORD *)(v1 + 376);
      *(_BYTE *)(v1 + 356) = 0;
      if ( v9 )
      {
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v11 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v11 )
          {
            ipc_log_string(
              v11,
              "ipa %s:%d Freeing dma memory for %s\n",
              "ipa3_nat_ipv6ct_free_mem",
              2157,
              (const char *)v1);
            v10 = ipa3_ctx;
          }
          v12 = *(_QWORD *)(v10 + 34160);
          if ( v12 )
          {
            ipc_log_string(
              v12,
              "ipa %s:%d Freeing dma memory for %s\n",
              "ipa3_nat_ipv6ct_free_mem",
              2157,
              (const char *)v1);
            v10 = ipa3_ctx;
          }
        }
        result = dma_free_attrs(
                   *(_QWORD *)(v10 + 34216),
                   *(_QWORD *)(v1 + 400),
                   *(_QWORD *)(v1 + 376),
                   *(_QWORD *)(v1 + 384),
                   0);
      }
      *(_QWORD *)(v1 + 376) = 0;
      *(_QWORD *)(v1 + 384) = 0;
      *(_QWORD *)(v1 + 400) = 0;
      *(_QWORD *)(v1 + 408) = 0;
      *(_QWORD *)(v1 + 424) = 0;
      *(_QWORD *)(v1 + 432) = 0;
      *(_QWORD *)(v1 + 440) = 0;
      *(_QWORD *)(v1 + 448) = 0;
    }
    if ( *(_BYTE *)(v1 + 357) == 1 )
    {
      v13 = *(_QWORD *)(v1 + 464);
      *(_BYTE *)(v1 + 357) = 0;
      if ( v13 )
      {
        v14 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v15 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v15 )
          {
            ipc_log_string(
              v15,
              "ipa %s:%d Unmappung sram memory for %s\n",
              "ipa3_nat_ipv6ct_free_mem",
              2185,
              (const char *)v1);
            v14 = ipa3_ctx;
          }
          v16 = *(_QWORD *)(v14 + 34160);
          if ( v16 )
            ipc_log_string(
              v16,
              "ipa %s:%d Unmappung sram memory for %s\n",
              "ipa3_nat_ipv6ct_free_mem",
              2185,
              (const char *)v1);
        }
        result = iounmap(*(_QWORD *)(v1 + 464));
      }
      *(_QWORD *)(v1 + 472) = 0;
      *(_QWORD *)(v1 + 480) = 0;
      *(_QWORD *)(v1 + 464) = 0;
      *(_QWORD *)(v1 + 496) = 0;
      *(_QWORD *)(v1 + 504) = 0;
      *(_QWORD *)(v1 + 520) = 0;
      *(_QWORD *)(v1 + 528) = 0;
      *(_QWORD *)(v1 + 536) = 0;
      *(_QWORD *)(v1 + 544) = 0;
    }
    *(_WORD *)(v1 + 223) = 0;
    *(_QWORD *)(v1 + 360) = 0;
    *(_QWORD *)(v1 + 368) = 0;
    *(_QWORD *)(v1 + 376) = 0;
    *(_QWORD *)(v1 + 384) = 0;
    *(_QWORD *)(v1 + 392) = 0;
    *(_QWORD *)(v1 + 400) = 0;
    *(_QWORD *)(v1 + 408) = 0;
    *(_QWORD *)(v1 + 416) = 0;
    *(_QWORD *)(v1 + 424) = 0;
    *(_QWORD *)(v1 + 432) = 0;
    *(_QWORD *)(v1 + 440) = 0;
    *(_QWORD *)(v1 + 448) = 0;
    *(_QWORD *)(v1 + 456) = 0;
    *(_QWORD *)(v1 + 464) = 0;
    *(_QWORD *)(v1 + 472) = 0;
    *(_QWORD *)(v1 + 480) = 0;
    *(_QWORD *)(v1 + 488) = 0;
    *(_QWORD *)(v1 + 496) = 0;
    *(_QWORD *)(v1 + 504) = 0;
    *(_QWORD *)(v1 + 512) = 0;
    *(_QWORD *)(v1 + 520) = 0;
    *(_QWORD *)(v1 + 528) = 0;
    *(_QWORD *)(v1 + 536) = 0;
    *(_QWORD *)(v1 + 544) = 0;
  }
  v17 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v18 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_free_mem", 2207);
      v17 = ipa3_ctx;
    }
    result = *(_QWORD *)(v17 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_free_mem", 2207);
  }
  return result;
}
