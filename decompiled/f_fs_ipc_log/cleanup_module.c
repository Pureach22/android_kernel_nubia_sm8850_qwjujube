__int64 cleanup_module()
{
  int v0; // w8
  __int64 v1; // x20
  __int64 v2; // x21
  _QWORD *v3; // x19
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x1

  destroy_workqueue(ipc_wq);
  v0 = num_devices;
  if ( num_devices >= 1 )
  {
    v1 = 0;
    v2 = 0;
    while ( 1 )
    {
      if ( v1 == 72 )
        goto LABEL_14;
      if ( (unsigned __int64)(v1 * 8 + 8) > 0x240 )
        break;
      if ( ipc_log_s[v1 + 1] )
      {
        ipc_log_context_destroy(ipc_log_s[v1]);
        v0 = num_devices;
        ipc_log_s[v1] = 0;
      }
      ++v2;
      v1 += 8;
      if ( v2 >= v0 )
        goto LABEL_8;
    }
    __break(1u);
LABEL_14:
    __break(0x5512u);
    JUMPOUT(0xBAA0);
  }
LABEL_8:
  v3 = &ffsprobes;
  v4 = 31;
  do
  {
    result = unregister_kretprobe(v3);
    v6 = *((unsigned int *)v3 + 37);
    if ( (int)v6 >= 1 )
      result = printk(&unk_BC76, v6, v3[6]);
    --v4;
    v3 += 21;
  }
  while ( v4 );
  return result;
}
