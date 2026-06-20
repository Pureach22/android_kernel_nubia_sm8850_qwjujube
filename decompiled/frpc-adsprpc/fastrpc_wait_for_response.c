__int64 __fastcall fastrpc_wait_for_response(__int64 a1, int a2)
{
  __int64 v2; // x19
  unsigned int *v3; // x20
  int v4; // w8
  unsigned int v6; // w8
  __int64 v8; // x0
  __int64 v9; // x0
  int v11; // w8

  v2 = *(_QWORD *)(a1 + 184);
  v3 = *(unsigned int **)(v2 + 128);
  if ( a2 )
  {
    if ( *(_DWORD *)(*((_QWORD *)v3 + 3) + 60LL) == 1
      && ((v4 = *(_DWORD *)(v2 + 268), v4 == 9) || v4 == 7)
      && *(_BYTE *)(v2 + 636) == 1
      && (byte_27530 & 1) == 0
      && !v3[16034] )
    {
      init_timer_key(a1 + 256, ssr_timer_callback, 0, 0, 0);
      mod_timer(a1 + 256, jiffies + 1250LL);
      wait_for_completion(a1 + 112);
      timer_delete_sync(a1 + 256);
    }
    else
    {
      wait_for_completion(a1 + 112);
    }
    return 0;
  }
  else if ( *(_DWORD *)(a1 + 40) >= 0x15u
         && *(_DWORD *)(*((_QWORD *)v3 + 3) + 60LL) == 1
         && (v6 = *(_DWORD *)(v2 + 632)) != 0 )
  {
    v8 = _msecs_to_jiffies(v6);
    v9 = wait_for_completion_interruptible_timeout(a1 + 112, v8);
    if ( v9 )
    {
      return (unsigned int)v9 & (unsigned int)(v9 >> 63);
    }
    else
    {
      dev_err(
        *((_QWORD *)v3 + 21),
        "%s: user-call timed out after %ums for domain %d, handle 0x%x, sc 0x%x, pid %d, tid %d\n",
        "fastrpc_wait_for_response",
        *(_DWORD *)(v2 + 632),
        *v3,
        *(_DWORD *)(a1 + 40),
        *(_DWORD *)(a1 + 36),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 28));
      fastrpc_queue_pd_status(v2, *v3, 6, *(_DWORD *)(v2 + 284));
      if ( (unsigned int)fastrpc_release_current_dsp_process(v2) == -62 )
        printk(
          &unk_256FE,
          "fastrpc_wait_for_response",
          5000,
          *v3,
          *(unsigned int *)(a1 + 40),
          *(unsigned int *)(a1 + 36));
      *(_DWORD *)(v2 + 628) = 4;
      v11 = *(_DWORD *)(v2 + 268);
      if ( v11 == 9 || v11 == 7 )
        fastrpc_sysfs_notify_pids(*((_QWORD *)v3 + 3));
      return 4294967234LL;
    }
  }
  else
  {
    return wait_for_completion_interruptible(a1 + 112);
  }
}
