__int64 __fastcall time_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x21
  int remote_time_sync; // w0
  __int64 result; // x0
  int v8; // w3
  __int64 v9; // x21
  __int64 v10; // x0
  int v11; // w20
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 - 24);
  v12 = 0;
  v13[0] = 0;
  remote_time_sync = mhi_get_remote_time_sync(a1 - 40, v13, &v12);
  if ( remote_time_sync )
  {
    v8 = remote_time_sync;
    v9 = *(_QWORD *)(*(_QWORD *)(v5 + 16) + 192LL);
    v10 = a1;
    v11 = v8;
    dev_err(v10, "[E][%s] Failed to obtain time, ret:%d\n", "time_show", v8);
    if ( v9 && *(_DWORD *)(v9 + 24) <= 2u )
      ipc_log_string(*(_QWORD *)(v9 + 32), "[E][%s] Failed to obtain time, ret:%d\n", "time_show", v11);
    LODWORD(result) = scnprintf(a3, 4096, "Request failed or feature unsupported\n");
  }
  else
  {
    LODWORD(result) = scnprintf(a3, 4096, "local: %llu remote: %llu (ticks)\n", v13[0], v12);
  }
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
