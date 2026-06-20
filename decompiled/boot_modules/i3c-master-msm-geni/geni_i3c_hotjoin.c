void __fastcall geni_i3c_hotjoin(_BYTE *a1)
{
  __int64 v2; // x21
  unsigned __int64 v3; // x20
  int v4; // w0
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  unsigned int v8; // w21
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x0

  v2 = *((_QWORD *)a1 - 2370);
  if ( v2 )
  {
    if ( *((_DWORD *)a1 - 4738) )
    {
      v3 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_hotjoin", v3, v3 / 0x3E8);
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = -22;
  }
  pm_stay_awake(*((_QWORD *)a1 - 2686));
  v4 = i3c_master_do_daa(a1 - 21384);
  if ( v4 )
  {
    v8 = v4;
    ipc_log_string(*((_QWORD *)a1 - 2371), "hotjoin:daa failed %d\n", v4);
    v11 = *((_QWORD *)a1 - 2686);
    if ( v11 )
      dev_err(v11, "hotjoin:daa failed %d\n", v8);
    else
      printk(&unk_13505, v8, v9, v10);
    if ( *((_QWORD *)a1 - 2686) )
      i3c_trace_log();
  }
  if ( a1[145] == 1 )
  {
    a1[155] = 0;
    complete(a1 - 18912);
  }
  v5 = pm_relax(*((_QWORD *)a1 - 2686));
  if ( a1[145] == 1 )
  {
    if ( a1[154] == 1 )
    {
      ipc_log_string(*((_QWORD *)a1 - 2371), "%s: Client must vote, debug from client\n", "geni_i3c_hotjoin");
      if ( *((_QWORD *)a1 - 2686) )
        i3c_trace_log();
      return;
    }
    pm_runtime_set_autosuspend_delay(*((_QWORD *)a1 - 2686), 0);
    _pm_runtime_use_autosuspend(*((_QWORD *)a1 - 2686), 1);
    ipc_log_string(
      *((_QWORD *)a1 - 2371),
      "%s: autosuspend timer only once for client, suspend done by i3c\n",
      "geni_i3c_hotjoin");
    v5 = *((_QWORD *)a1 - 2686);
    if ( v5 )
      i3c_trace_log();
    a1[154] = 1;
  }
  v6 = *((_QWORD *)a1 - 2370);
  if ( v6 && v3 && *((_DWORD *)a1 - 4738) )
  {
    v7 = sched_clock(v5);
    ipc_log_string(v6, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_hotjoin", v7 - v3, (v7 - v3) / 0x3E8);
  }
}
