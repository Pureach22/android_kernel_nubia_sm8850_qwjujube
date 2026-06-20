__int64 __fastcall altmode_callback(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w8
  _QWORD *v7; // x20
  int v8; // w21
  int v9; // t1
  unsigned int v10; // w22
  __int64 v11; // x23
  __int64 v12; // x9
  __int64 v13; // x1
  __int64 v15; // x1

  ipc_log_string(
    altmode_ipc_log,
    "len: %zu owner: %u type: %u opcode %04x\n",
    a3,
    *(_DWORD *)a2,
    *(_DWORD *)(a2 + 4),
    *(_DWORD *)(a2 + 8));
  v6 = *(_DWORD *)(a2 + 8);
  if ( (unsigned __int8)v6 == 22 )
  {
    if ( a3 != 32 )
    {
      ipc_log_string(altmode_ipc_log, "Expected length %zu, got: %zu\n", 0x20u, a3);
      return 4294967274LL;
    }
    v9 = *(unsigned __int8 *)(a2 + 12);
    v7 = (_QWORD *)(a2 + 12);
    v8 = v9;
    v10 = HIWORD(v6);
    mutex_lock(a1 + 40);
    v11 = idr_find(a1 + 16, v9 | (v10 << 8));
    mutex_unlock(a1 + 40);
    ipc_log_string(altmode_ipc_log, "Payload: %*ph\n", 16, v7);
    if ( v11 )
    {
      cancel_work_sync(v11 + 64);
      v12 = v7[1];
      v13 = system_wq;
      *(_QWORD *)(v11 + 96) = *v7;
      *(_QWORD *)(v11 + 104) = v12;
      queue_work_on(32, v13, v11 + 64);
    }
    else
    {
      ipc_log_string(altmode_ipc_log, "No client associated with SVID %#x port %u\n", v10, v8);
      v15 = system_wq;
      *(_BYTE *)(a1 + 376) = v8;
      queue_delayed_work_on(32, v15, a1 + 232, 5);
    }
  }
  else if ( (unsigned __int8)v6 == 21 )
  {
    complete(a1 + 344);
  }
  return 0;
}
