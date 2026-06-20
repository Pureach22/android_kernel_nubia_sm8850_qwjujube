__int64 __fastcall gi3c_ev_cb(__int64 a1, int *a2, __int64 a3)
{
  __int64 v3; // x19
  int v5; // w4
  __int64 result; // x0

  v3 = *(_QWORD *)(a3 + 24);
  ipc_log_string(*(_QWORD *)(v3 + 2528), "%s cb_str->cb_event=0x%x\n", "gi3c_ev_cb", *a2);
  if ( *(_QWORD *)(v3 + 8) )
    i3c_trace_log();
  v5 = *a2;
  if ( *a2 || (geni_i3c_handle_err(v3, a2[2]), result = complete_all(v3 + 2552), (v5 = *a2) != 0) )
  {
    ipc_log_string(*(_QWORD *)(v3 + 2528), "GSI QN err:0x%x, status:%llu, err:%d\n", a2[10], *((_QWORD *)a2 + 1), v5);
    if ( *(_QWORD *)(v3 + 8) )
      i3c_trace_log();
    *(_BYTE *)(v3 + 21240) = 1;
    return complete_all(v3 + 2552);
  }
  return result;
}
