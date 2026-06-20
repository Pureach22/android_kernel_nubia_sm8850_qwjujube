__int64 __fastcall qdss_trace_start_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x6
  __int64 v6; // x7
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  char v12; // [xsp+0h] [xbp+0h]

  wlfw_qdss_trace_start(*(_QWORD *)(a1 + 152));
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v8 = "irq";
  }
  else
  {
    v9 = *(_DWORD *)(StatusReg + 16);
    v10 = (const char *)(StatusReg + 2320);
    if ( (v9 & 0xFF00) != 0 )
      v8 = "soft_irq";
    else
      v8 = v10;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v8,
    "qdss_trace_start_store",
    7u,
    7u,
    "Received QDSS start command\n",
    v5,
    v6,
    v12);
  return a4;
}
