__int64 __fastcall geni_i3c_err(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  __int64 v4; // x0
  int v5; // w3
  __int64 v7; // x0
  char *v8; // x22

  v2 = a1 + 20480;
  v4 = *(_QWORD *)(a1 + 2528);
  v5 = *(_DWORD *)(v2 + 796);
  if ( *(_DWORD *)(v2 + 792) )
  {
    ipc_log_string(v4, "%s:Error: Read, len:%d\n", "geni_i3c_err", v5);
    v7 = *(_QWORD *)(a1 + 8);
    if ( v7 )
      goto LABEL_5;
  }
  else
  {
    ipc_log_string(v4, "%s:Error: Write, len:%d\n", "geni_i3c_err", v5);
    v7 = *(_QWORD *)(a1 + 8);
    if ( v7 )
LABEL_5:
      i3c_trace_log();
  }
  if ( ((16LL * a2) | 8uLL) > 0xA0 )
    goto LABEL_11;
  v8 = (char *)&gi3c_log + 16 * a2;
  ipc_log_string(*(_QWORD *)(a1 + 2528), "%s\n", *((_QWORD *)v8 + 1));
  v7 = *(_QWORD *)(a1 + 8);
  if ( v7 )
    i3c_trace_log();
  if ( a2 > 9 )
  {
LABEL_11:
    __break(1u);
    return geni_i3c_err_prep_sg(v7);
  }
  else
  {
    *(_DWORD *)(a1 + 104) = *(_DWORD *)v8;
    return geni_i3c_dump_dbg_regs(a1);
  }
}
