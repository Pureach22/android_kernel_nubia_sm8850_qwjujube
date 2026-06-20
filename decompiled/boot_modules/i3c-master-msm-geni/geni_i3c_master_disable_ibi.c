__int64 __fastcall geni_i3c_master_disable_ibi(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x22
  unsigned __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x21
  unsigned int v7; // w19
  __int64 v8; // x0
  unsigned int v9; // w21
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x0

  v1 = *(_QWORD *)(a1 + 16);
  v3 = *(_QWORD *)(v1 + 2424);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 2432) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_disable_ibi", v4, v4 / 0x3E8);
      if ( (*(_BYTE *)(v1 + 21208) & 1) != 0 )
        goto LABEL_9;
    }
    else
    {
      v4 = 0;
      if ( (*(_BYTE *)(v1 + 21208) & 1) != 0 )
        goto LABEL_9;
    }
  }
  else
  {
    v4 = -22;
    if ( (*(_BYTE *)(v1 + 21208) & 1) != 0 )
      goto LABEL_9;
  }
  if ( *(_BYTE *)(v1 + 21209) != 1 )
    return 0xFFFFFFFFLL;
LABEL_9:
  result = i3c_master_disec_locked(v1, *(unsigned __int8 *)(a1 + 43), 1);
  if ( (_DWORD)result )
  {
    v9 = result;
    ipc_log_string(*(_QWORD *)(v1 + 2416), "%s: error while i3c_master_disec_locked\n", "geni_i3c_master_disable_ibi");
    v12 = *(_QWORD *)(v1 - 104);
    if ( v12 )
      dev_err(v12, "%s: error while i3c_master_disec_locked\n", "geni_i3c_master_disable_ibi");
    else
      printk(&unk_1406B, "geni_i3c_master_disable_ibi", v10, v11);
    result = v9;
    if ( *(_QWORD *)(v1 - 104) )
    {
      i3c_trace_log();
      result = v9;
    }
  }
  v6 = *(_QWORD *)(v1 + 2424);
  if ( v6 && v4 )
  {
    if ( *(_DWORD *)(v1 + 2432) )
    {
      v7 = result;
      v8 = sched_clock(result);
      ipc_log_string(v6, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_master_disable_ibi", v8 - v4, (v8 - v4) / 0x3E8);
      return v7;
    }
  }
  return result;
}
