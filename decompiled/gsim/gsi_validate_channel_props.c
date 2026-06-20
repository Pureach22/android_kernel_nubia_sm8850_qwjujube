__int64 __fastcall gsi_validate_channel_props(__int64 a1)
{
  unsigned int v1; // w4
  int v2; // w5
  __int64 v4; // x5
  unsigned __int64 v5; // x4
  char v6; // w8

  if ( *(_DWORD *)(gsi_ctx + 28608) <= (unsigned int)*(unsigned __int8 *)(a1 + 8) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d ch_id %u invalid\n", "gsi_validate_channel_props", 2840);
    return 4294967290LL;
  }
  v2 = *(_DWORD *)(a1 + 24);
  v1 = *(_DWORD *)(a1 + 28);
  if ( v2 <= 15 )
  {
    if ( v2 != 4 )
    {
      if ( v2 == 8 && (v1 & 7) != 0 )
        goto LABEL_25;
      goto LABEL_13;
    }
    if ( (v1 & 3) == 0 )
      goto LABEL_13;
LABEL_25:
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d bad params ring_len %u not a multiple of re size %u\n",
      "gsi_validate_channel_props",
      2855,
      v1,
      v2);
    return 4294967290LL;
  }
  if ( v2 == 16 )
  {
    if ( (v1 & 0xF) == 0 )
      goto LABEL_13;
    goto LABEL_25;
  }
  if ( v2 == 32 )
  {
    if ( (v1 & 0x1F) == 0 )
      goto LABEL_13;
    goto LABEL_25;
  }
  if ( v2 == 64 && (v1 & 0x3F) != 0 )
    goto LABEL_25;
LABEL_13:
  if ( (gsihal_check_ring_length_valid(v1, (unsigned int)v2) & 1) == 0 )
    return 4294967290LL;
  v4 = *(unsigned int *)(a1 + 28);
  v5 = *(_QWORD *)(a1 + 40);
  v6 = __clz(v4 - 1);
  if ( v5 != (v5 / (unsigned int)(1LL << -v6)) << -v6 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d bad params ring base not aligned 0x%llx align 0x%lx\n",
      "gsi_validate_channel_props",
      2868,
      v5,
      1LL << -v6);
    return 4294967290LL;
  }
  if ( ((v5 + v4 - *(unsigned int *)(a1 + 24)) ^ v5) >> 32 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d MSB is not fixed on ring base 0x%llx size 0x%x\n",
      "gsi_validate_channel_props",
      2879,
      v5,
      v4);
    return 4294967290LL;
  }
  if ( *(_DWORD *)a1 == 2 )
  {
    if ( !*(_QWORD *)(a1 + 56) )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d protocol %u requires ring base VA\n", "gsi_validate_channel_props", 2885);
      return 4294967290LL;
    }
    if ( *(unsigned __int8 *)(a1 + 72) <= 0xFu )
    {
      if ( !*(_QWORD *)(a1 + 88) )
      {
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d xfer callback must be provided\n", "gsi_validate_channel_props", 2895);
        return 4294967290LL;
      }
      goto LABEL_22;
    }
LABEL_31:
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid channel low weight %u\n", "gsi_validate_channel_props", 2890);
    return 4294967290LL;
  }
  if ( *(unsigned __int8 *)(a1 + 72) >= 0x10u )
    goto LABEL_31;
LABEL_22:
  if ( *(_QWORD *)(a1 + 96) )
    return 0;
  dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d err callback must be provided\n", "gsi_validate_channel_props", 2900);
  return 4294967290LL;
}
