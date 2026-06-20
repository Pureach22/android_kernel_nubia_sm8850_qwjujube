__int64 __fastcall dms_new_server(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  int v3; // w19
  int v4; // w20
  __int64 v6; // x0
  unsigned int v7; // w0
  unsigned int v8; // w22
  unsigned __int64 v15; // x9
  _DWORD v16[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v3 = *(_DWORD *)(a2 + 12);
    v4 = *(_DWORD *)(a2 + 16);
    v6 = *a1;
    v16[0] = 42;
    v16[1] = v3;
    v16[2] = v4;
    v7 = kernel_connect(v6, v16, 12, 0);
    if ( (v7 & 0x80000000) != 0 )
    {
      v8 = v7;
      printk("%sicnss2_qmi: Failed to connect to QMI DMS remote service Node: %d Port: %d\n", byte_130B32, v3, v4);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: Failed to connect to QMI DMS remote service Node: %d Port: %d\n",
        (const char *)&unk_12DBF3,
        v3,
        v4);
    }
    else
    {
      _X8 = a1 + 113;
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 | 0x400000, _X8) );
      v8 = v7;
      printk("%sicnss2_qmi: QMI DMS service connected, state: 0x%lx\n", byte_13289B, a1[113]);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: QMI DMS service connected, state: 0x%lx\n",
        (const char *)&unk_12DBF3,
        a1[113]);
    }
    result = v8;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
