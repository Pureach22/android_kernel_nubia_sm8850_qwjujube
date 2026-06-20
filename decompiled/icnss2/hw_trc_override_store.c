__int64 __fastcall hw_trc_override_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( sscanf(s, "%du", &v8) == 1 )
  {
    v6 = icnss_ipc_log_context;
    *(_DWORD *)(v5 + 5644) = v8;
    ipc_log_string(v6, "icnss2: Received QDSS hw_trc_override indication\n");
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
