__int64 __fastcall hw_trace_override_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x6
  __int64 v7; // x7
  __int64 v8; // x0
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8
  char v14; // [xsp+0h] [xbp-10h]
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v15 = 0;
  if ( sscanf(s, "%du", &v15) == 1 )
  {
    v8 = cnss_ipc_log_context;
    *(_DWORD *)(v5 + 7572) = v15;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v12;
    }
    cnss_debug_ipc_log_print(
      v8,
      v10,
      "hw_trace_override_store",
      7u,
      7u,
      "Received QDSS hw_trc_override indication\n",
      v6,
      v7,
      v14);
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
