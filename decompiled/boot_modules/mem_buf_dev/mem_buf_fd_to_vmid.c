__int64 mem_buf_fd_to_vmid()
{
  __int64 v0; // x0
  __int64 v1; // x20
  __int64 v2; // x1
  __int64 v3; // x2
  unsigned int v4; // w19

  v0 = fget();
  if ( v0 )
  {
    if ( *(_UNKNOWN **)(v0 + 16) == &mem_buf_vm_fops )
    {
      v4 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 32) + 8LL);
    }
    else
    {
      v1 = v0;
      if ( (unsigned int)__ratelimit(&mem_buf_fd_to_vmid__rs, "mem_buf_fd_to_vmid") )
        printk(&unk_13801, v2, v3);
      v4 = -22;
      v0 = v1;
    }
    fput(v0);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v4;
}
