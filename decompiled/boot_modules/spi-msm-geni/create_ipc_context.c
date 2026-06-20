__int64 __fastcall create_ipc_context(_QWORD *a1, __int64 a2)
{
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 v6; // x0
  const char **v7; // x8
  const char *v8; // x3
  __int64 result; // x0
  _QWORD v10[4]; // [xsp+0h] [xbp-30h] BYREF
  int v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (__int64 *)a1[25];
  v11 = 0;
  v5 = v4[14];
  memset(v10, 0, sizeof(v10));
  if ( !v5 )
    v5 = *v4;
  v6 = ipc_log_context_create(4, v5, 0);
  a1[59] = v6;
  if ( !v6 )
    dev_err(a2, "Error creating IPC logs\n");
  v7 = (const char **)a1[25];
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  scnprintf(v10, 36, "%s%s", v8, "_tx_rx");
  result = ipc_log_context_create(4, v10, 0);
  a1[60] = result;
  if ( !result )
    result = dev_err(a2, "Error creating IPC TX/RX logs\n");
  _ReadStatusReg(SP_EL0);
  return result;
}
