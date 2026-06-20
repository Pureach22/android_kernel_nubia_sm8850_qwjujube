__int64 __fastcall time_async_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 v6; // x22
  unsigned int random_u32; // w0
  int v8; // w20
  int remote_time; // w0
  __int64 result; // x0
  int v11; // w4
  __int64 v12; // x22
  __int64 v13; // x0
  int v14; // w21

  v3 = *(_QWORD *)(a1 - 24);
  v6 = a1 - 40;
  random_u32 = get_random_u32(a1);
  if ( random_u32 <= 1 )
    v8 = 1;
  else
    v8 = random_u32;
  remote_time = mhi_get_remote_time(v6, v8, (__int64)mhi_time_async_cb);
  if ( remote_time )
  {
    v11 = remote_time;
    v12 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
    v13 = a1;
    v14 = v11;
    dev_err(v13, "[E][%s] Failed to request time, seq:%x, ret:%d\n", "time_async_show", v8, v11);
    if ( v12 && *(_DWORD *)(v12 + 24) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v12 + 32),
        "[E][%s] Failed to request time, seq:%x, ret:%d\n",
        "time_async_show",
        v8,
        v14);
    LODWORD(result) = scnprintf(a3, 4096, "Request failed or feature unsupported\n");
  }
  else
  {
    LODWORD(result) = scnprintf(a3, 4096, "Requested time asynchronously with seq:%x\n", v8);
  }
  return (int)result;
}
