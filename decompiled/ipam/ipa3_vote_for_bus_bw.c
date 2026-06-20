__int64 __fastcall ipa3_vote_for_bus_bw(unsigned int *a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w20
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0

  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v3, "ipa-wan %s:%d Bus BW is %d\n", "ipa3_vote_for_bus_bw", 2556, *a1);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v5, "ipa-wan %s:%d Bus BW is %d\n", "ipa3_vote_for_bus_bw", 2556, *a1);
  }
  if ( a1 )
  {
    v6 = ipa3_wwan_set_modem_perf_profile(*a1);
    if ( (_DWORD)v6 )
    {
      v16 = v6;
      v17 = printk(&unk_3C7431, "ipa3_vote_for_bus_bw");
      v18 = ipa3_get_ipc_logbuf(v17);
      if ( v18 )
      {
        v19 = ipa3_get_ipc_logbuf(v18);
        v18 = ipc_log_string(
                v19,
                "ipa-wan %s:%d Failed to set perf profile to BW %u\n",
                "ipa3_vote_for_bus_bw",
                2566,
                *a1);
      }
      v20 = ipa3_get_ipc_logbuf_low(v18);
      if ( v20 )
      {
        v21 = ipa3_get_ipc_logbuf_low(v20);
        ipc_log_string(v21, "ipa-wan %s:%d Failed to set perf profile to BW %u\n", "ipa3_vote_for_bus_bw", 2566, *a1);
      }
      return v16;
    }
    else
    {
      v7 = ipa3_get_ipc_logbuf(v6);
      if ( v7 )
      {
        v8 = ipa3_get_ipc_logbuf(v7);
        v7 = ipc_log_string(
               v8,
               "ipa-wan %s:%d Succeeded to set perf profile to BW %u\n",
               "ipa3_vote_for_bus_bw",
               2569,
               *a1);
      }
      result = ipa3_get_ipc_logbuf_low(v7);
      if ( result )
      {
        v10 = ipa3_get_ipc_logbuf_low(result);
        ipc_log_string(v10, "ipa-wan %s:%d Succeeded to set perf profile to BW %u\n", "ipa3_vote_for_bus_bw", 2569, *a1);
        return 0;
      }
    }
  }
  else
  {
    v11 = printk(&unk_3E406C, "ipa3_vote_for_bus_bw");
    v12 = ipa3_get_ipc_logbuf(v11);
    if ( v12 )
    {
      v13 = ipa3_get_ipc_logbuf(v12);
      v12 = ipc_log_string(v13, "ipa-wan %s:%d Bus BW is invalid\n", "ipa3_vote_for_bus_bw", 2559);
    }
    v14 = ipa3_get_ipc_logbuf_low(v12);
    if ( v14 )
    {
      v15 = ipa3_get_ipc_logbuf_low(v14);
      ipc_log_string(v15, "ipa-wan %s:%d Bus BW is invalid\n", "ipa3_vote_for_bus_bw", 2559);
    }
    return 4294967274LL;
  }
  return result;
}
