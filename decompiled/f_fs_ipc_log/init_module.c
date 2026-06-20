__int64 init_module()
{
  __int64 v0; // x2
  _QWORD *v1; // x19
  __int64 v2; // x21
  unsigned int v3; // w0

  ipc_wq = alloc_workqueue("ipc_wq", 131074, 1);
  if ( ipc_wq )
  {
    v1 = &ffsprobes;
    v2 = 31;
    do
    {
      v3 = register_kretprobe(v1);
      if ( (v3 & 0x80000000) != 0 )
        printk(&unk_BD31, v1[6], v3);
      --v2;
      v1 += 21;
    }
    while ( v2 );
    return 0;
  }
  else
  {
    printk(&unk_C13D, "kretprobe_init", v0);
    return 4294967284LL;
  }
}
