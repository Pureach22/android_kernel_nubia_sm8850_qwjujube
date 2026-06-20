__int64 __fastcall gsi_validate_evt_ring_props(unsigned int *a1)
{
  unsigned int v1; // w4
  unsigned int v2; // w5
  int v4; // w8
  unsigned __int64 v5; // t2
  unsigned __int64 v6; // x4
  char v7; // w8
  __int64 v8; // x4
  int v9; // w4
  unsigned int v10; // w5

  v2 = a1[2];
  v1 = a1[3];
  HIDWORD(v5) = v2 - 4;
  LODWORD(v5) = v2 - 4;
  v4 = v5 >> 2;
  if ( v4 > 2 )
  {
    if ( v4 != 3 )
    {
      if ( v4 == 7 && (v1 & 0x1F) != 0 )
        goto LABEL_19;
      goto LABEL_9;
    }
    if ( (v1 & 0xF) == 0 )
      goto LABEL_9;
LABEL_19:
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d bad params ring_len %u not a multiple of RE size %u\n",
      "gsi_validate_evt_ring_props",
      2046,
      v1,
      v2);
    return 4294967290LL;
  }
  if ( !v4 )
  {
    if ( (v1 & 3) == 0 )
      goto LABEL_9;
    goto LABEL_19;
  }
  if ( v4 == 1 && (v1 & 7) != 0 )
    goto LABEL_19;
LABEL_9:
  if ( (gsihal_check_ring_length_valid(v1, v2) & 1) != 0 )
  {
    v6 = *((_QWORD *)a1 + 2);
    v7 = __clz(a1[3] - 1LL);
    if ( v6 != (v6 / (unsigned int)(1LL << -v7)) << -v7 )
    {
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d bad params ring base not aligned 0x%llx align 0x%lx\n",
        "gsi_validate_evt_ring_props",
        2059,
        v6,
        1LL << -v7);
      return 4294967290LL;
    }
    v8 = *a1;
    if ( (_DWORD)v8 )
    {
      if ( (_DWORD)v8 == 2 && !*((_QWORD *)a1 + 3) )
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d protocol %u requires ring base VA\n",
          "gsi_validate_evt_ring_props",
          2065,
          2);
        return 4294967290LL;
      }
      if ( *((_BYTE *)a1 + 112) == 1 )
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d protocol %u cannot specify evchid\n",
          "gsi_validate_evt_ring_props",
          2080,
          v8);
        return 4294967290LL;
      }
    }
    else
    {
      v9 = *((unsigned __int8 *)a1 + 112);
      v10 = *((unsigned __int8 *)a1 + 113);
      if ( v9 != 1 || *(_DWORD *)(gsi_ctx + 96) < v10 || *(_DWORD *)(gsi_ctx + 92) > v10 )
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d MHI requires evchid valid=%d val=%u\n",
          "gsi_validate_evt_ring_props",
          2074,
          v9,
          v10);
        return 4294967290LL;
      }
    }
    if ( *((_QWORD *)a1 + 12) )
      return 0;
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d err callback must be provided\n", "gsi_validate_evt_ring_props", 2085);
  }
  return 4294967290LL;
}
