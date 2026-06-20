__int64 __fastcall mhi_sat_error_worker(__int64 a1)
{
  _QWORD *v1; // x22
  bool v3; // zf
  int v4; // w23
  __int64 result; // x0
  __int16 v6; // w8
  __int64 v7; // x21
  int v8; // w10
  __int16 v9; // w8
  __int64 v10; // x8
  int v11; // w20
  const char *v12; // x5

  v1 = *(_QWORD **)(a1 - 176);
  v3 = a1 == 200 || v1 == nullptr;
  v4 = !v3;
  if ( !v3 )
    ipc_log_string(
      v1[11],
      "%s[I][%s][%x] Entered\n",
      (const char *)&unk_8360,
      "mhi_sat_error_worker",
      *(_DWORD *)(a1 + 32));
  flush_work(a1 - 64);
  flush_work(a1 - 32);
  result = _kmalloc_cache_noprof(_mhi_driver_register, 3264, 40);
  if ( result )
  {
    v6 = *(_WORD *)(a1 + 56);
    v7 = result;
    *(_QWORD *)(result + 24) = 0;
    *(_QWORD *)(result + 32) = 0x200000FF000000LL;
    v8 = *(_DWORD *)(a1 + 32);
    *(_DWORD *)result = 1;
    if ( v6 == -2 )
      v9 = 0;
    else
      v9 = v6 + 1;
    *(_WORD *)(a1 + 56) = v9;
    *(_WORD *)(result + 6) = v9;
    v10 = *(_QWORD *)(a1 - 176);
    *(_WORD *)(result + 4) = 14;
    *(_DWORD *)(result + 8) = 1114111;
    *(_DWORD *)(result + 12) = v8;
    v11 = rpmsg_send(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 968LL), result, 40);
    result = kfree(v7);
    if ( v4 )
    {
      if ( v11 )
        v12 = "failure";
      else
        v12 = "success";
      return ipc_log_string(
               v1[11],
               "%s[I][%s][%x] SYS_ERROR state change event send %s!\n",
               &unk_8360,
               "mhi_sat_error_worker",
               *(unsigned int *)(a1 + 32),
               v12);
    }
  }
  else if ( v4 )
  {
    printk(&unk_8901, "mhi_sat_error_worker", *v1, *(unsigned int *)(a1 + 32));
    return ipc_log_string(
             v1[11],
             "%s[E][%s][%x] Unable to malloc for SYS_ERR message!\n",
             (const char *)&unk_8360,
             "mhi_sat_error_worker",
             *(_DWORD *)(a1 + 32));
  }
  return result;
}
