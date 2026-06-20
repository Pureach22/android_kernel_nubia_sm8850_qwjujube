__int64 __fastcall qdss_tr_stop_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( sscanf(s, "%du", &v7) == 1 )
  {
    wlfw_qdss_trace_stop(v5, v7);
    ipc_log_string(icnss_ipc_log_context, "icnss2: Received QDSS stop command\n");
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
