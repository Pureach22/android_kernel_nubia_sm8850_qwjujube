__int64 __fastcall root_ioctl(__int64 a1, int a2, __int64 a3)
{
  __int64 v4; // x0
  __int64 v5; // x19
  unsigned int unused_fd_flags; // w0
  unsigned int v7; // w20
  unsigned __int64 v8; // x21

  if ( a2 == -1072654333 )
  {
    v4 = _kmalloc_cache_noprof(trace_event_buffer_commit, 3520, 64);
    v5 = v4;
    if ( v4 )
    {
      *(_DWORD *)(v4 + 16) = 1;
      *(_QWORD *)(v4 + 24) = v4 + 24;
      *(_QWORD *)(v4 + 32) = v4 + 24;
      _init_waitqueue_head(v4 + 40, "&si->Q", &process_server_req___key);
      _get_task_comm(v5, 16, _ReadStatusReg(SP_EL0));
      unused_fd_flags = get_unused_fd_flags(2);
      if ( (unused_fd_flags & 0x80000000) == 0 )
      {
        v7 = unused_fd_flags;
        v8 = anon_inode_getfile(v5, &server_fops, v5, 2);
        if ( v8 <= 0xFFFFFFFFFFFFF000LL )
        {
          fd_install(v7, v8);
          return v7;
        }
        put_unused_fd(v7);
      }
      kfree(v5);
      return -9;
    }
    return -12;
  }
  else if ( a2 == -1071605759 )
  {
    return process_invoke_req(a1, a3);
  }
  else
  {
    return -515;
  }
}
