__int64 __fastcall ipa3_read_wstats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w27
  unsigned int v5; // w19
  unsigned int ep_mapping; // w0
  __int64 v7; // x20
  _DWORD *v8; // x20
  int v9; // t1
  unsigned int v10; // w19
  unsigned int v11; // w19
  unsigned int v12; // w19
  unsigned int v13; // w19
  unsigned int v14; // w19
  unsigned int v15; // w19
  int v16; // w0
  const char *v17; // x3
  int v18; // w20
  unsigned int v19; // w0
  __int64 v20; // x19
  __int64 v21; // x19
  int v22; // t1
  unsigned int v23; // w8
  int v24; // w0
  _DWORD *v25; // x8
  int v26; // w0
  unsigned int v27; // w19
  unsigned int v28; // w20
  unsigned int v29; // w20
  int v30; // w0

  v5 = scnprintf(dbg_buff, 4096, "%25s\n", "Client IPA_CLIENT_WLAN1_PROD Stats:");
  ep_mapping = ipa_get_ep_mapping(10);
  if ( ep_mapping == -1 )
    goto LABEL_13;
  if ( ep_mapping > 0x24 )
    goto LABEL_41;
  v7 = ipa3_ctx + 480LL * ep_mapping;
  v9 = *(_DWORD *)(v7 + 168);
  v8 = (_DWORD *)(v7 + 168);
  if ( v9 != 1 )
  {
LABEL_13:
    if ( v5 >> 1 > 0x800 )
      goto LABEL_41;
    v16 = scnprintf(&dbg_buff[v5], (int)(4096 - v5), "%25s\n", "Not up");
  }
  else
  {
    if ( v5 >> 1 > 0x800 )
      goto LABEL_41;
    v10 = scnprintf(&dbg_buff[v5], (int)(4096 - v5), "%25s %10u\n", "Avail Fifo Desc:", v8[96]) + v5;
    if ( v10 >> 1 > 0x800 )
      goto LABEL_41;
    v11 = scnprintf(&dbg_buff[v10], (int)(4096 - v10), "%25s %10u\n", "Rx Pkts Rcvd:", v8[102]) + v10;
    if ( v11 >> 1 > 0x800 )
      goto LABEL_41;
    v12 = scnprintf(&dbg_buff[v11], (int)(4096 - v11), "%25s %10u\n", "Rx Pkts Status Rcvd:", v8[103]) + v11;
    if ( v12 >> 1 > 0x800 )
      goto LABEL_41;
    v13 = scnprintf(&dbg_buff[v12], (int)(4096 - v12), "%25s %10u\n", "Rx DH Rcvd:", v8[106]) + v12;
    if ( v13 >> 1 > 0x800 )
      goto LABEL_41;
    v14 = scnprintf(&dbg_buff[v13], (int)(4096 - v13), "%25s %10u\n", "Rx DH Processed:", v8[104]) + v13;
    if ( v14 >> 1 > 0x800 )
      goto LABEL_41;
    v15 = scnprintf(&dbg_buff[v14], (int)(4096 - v14), "%25s %10u\n", "Rx DH Sent Back:", v8[105]) + v14;
    if ( v15 >> 1 > 0x800 )
      goto LABEL_41;
    v5 = scnprintf(&dbg_buff[v15], (int)(4096 - v15), "%25s %10u\n", "Rx Pkt Leak:", v8[107]) + v15;
    if ( v5 >> 1 > 0x800 )
      goto LABEL_41;
    v16 = scnprintf(&dbg_buff[v5], (int)(4096 - v5), "%25s %10u\n\n", "Rx DP Fail:", v8[108]);
  }
  v4 = v16 + v5;
  if ( (v16 + v5) >> 1 <= 0x800 )
  {
    v17 = "Client IPA_CLIENT_WLAN1_CONS Stats:";
    v18 = 11;
    while ( 1 )
    {
      v4 += scnprintf(&dbg_buff[v4], (int)(4096 - v4), "%25s\n", v17);
      v19 = ipa_get_ep_mapping((unsigned int)v18);
      if ( v19 == -1 )
        break;
      if ( v19 > 0x24 )
        goto LABEL_41;
      v20 = ipa3_ctx + 480LL * v19;
      v22 = *(_DWORD *)(v20 + 168);
      v21 = v20 + 168;
      v23 = v4 >> 1;
      if ( v22 != 1 )
        goto LABEL_29;
      if ( v23 > 0x800 )
        goto LABEL_41;
      v4 += scnprintf(&dbg_buff[v4], (int)(4096 - v4), "%25s %10u\n", "Tx Pkts Received:", *(_DWORD *)(v21 + 436));
      if ( v4 >> 1 > 0x800 )
        goto LABEL_41;
      v4 += scnprintf(&dbg_buff[v4], (int)(4096 - v4), "%25s %10u\n", "Tx Pkts Sent:", *(_DWORD *)(v21 + 440));
      if ( v4 >> 1 > 0x800 )
        goto LABEL_41;
      v24 = scnprintf(&dbg_buff[v4], (int)(4096 - v4), "%25s %10u\n\n", "Tx Pkts Dropped:", *(_DWORD *)(v21 + 444));
      v25 = *(_DWORD **)(v21 + 472);
      v4 += v24;
      if ( !v25 )
        goto LABEL_32;
      if ( v4 >> 1 > 0x800 )
        goto LABEL_41;
      v4 += scnprintf(&dbg_buff[v4], (int)(4096 - v4), "%25s %10u\n\n", "sys len:", *v25);
      if ( v4 >> 1 > 0x800 )
        goto LABEL_41;
      v26 = scnprintf(
              &dbg_buff[v4],
              (int)(4096 - v4),
              "%25s %10u\n\n",
              "rx_pool_sz:",
              *(_DWORD *)(*(_QWORD *)(v21 + 472) + 164LL));
LABEL_31:
      v4 += v26;
LABEL_32:
      if ( v18 > 14 )
      {
        if ( v18 == 15 )
        {
          v18 = 17;
          v17 = "Client IPA_CLIENT_WLAN4_CONS Stats:";
          if ( v4 >> 1 >= 0x801 )
            goto LABEL_41;
        }
        else
        {
          if ( v18 != 119 )
            goto LABEL_42;
          v18 = 15;
          v17 = "Client IPA_CLIENT_WLAN3_CONS Stats:";
          if ( v4 >> 1 >= 0x801 )
            goto LABEL_41;
        }
      }
      else if ( v18 == 11 )
      {
        v18 = 13;
        v17 = "Client IPA_CLIENT_WLAN2_CONS Stats:";
        if ( v4 >> 1 >= 0x801 )
          goto LABEL_41;
      }
      else
      {
        v18 = 119;
        v17 = "Client IPA_CLIENT_WLAN2_CONS1 Stats:";
        if ( v4 >> 1 >= 0x801 )
          goto LABEL_41;
      }
    }
    v23 = v4 >> 1;
LABEL_29:
    if ( v23 > 0x800 )
      goto LABEL_41;
    v26 = scnprintf(&dbg_buff[v4], (int)(4096 - v4), "%25s\n", "Not up");
    goto LABEL_31;
  }
  while ( 1 )
  {
LABEL_41:
    __break(0x5512u);
LABEL_42:
    if ( v4 >> 1 <= 0x800 )
    {
      v27 = scnprintf(&dbg_buff[v4], (int)(4096 - v4), "\n%25s\n", "All Wlan Consumer pipes stats:") + v4;
      if ( v27 >> 1 <= 0x800 )
      {
        v28 = scnprintf(
                &dbg_buff[v27],
                (int)(4096 - v27),
                "%25s %10u\n",
                "Tx Comm Buff Allocated:",
                *(_DWORD *)(ipa3_ctx + 34616))
            + v27;
        if ( v28 >> 1 <= 0x800 )
        {
          v29 = scnprintf(
                  &dbg_buff[v28],
                  (int)(4096 - v28),
                  "%25s %10u\n",
                  "Tx Comm Buff Avail:",
                  *(_DWORD *)(ipa3_ctx + 34620))
              + v28;
          if ( v29 >> 1 <= 0x800 )
            break;
        }
      }
    }
  }
  v30 = scnprintf(
          &dbg_buff[v29],
          (int)(4096 - v29),
          "%25s %10u\n\n",
          "Total Tx Pkts Freed:",
          *(_DWORD *)(ipa3_ctx + 34624));
  return simple_read_from_buffer(a2, a3, a4, dbg_buff, (int)(v30 + v29));
}
