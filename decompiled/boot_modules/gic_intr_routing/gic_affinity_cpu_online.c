__int64 __fastcall gic_affinity_cpu_online(unsigned int a1)
{
  unsigned __int64 v2; // x21
  unsigned int *v3; // x20
  int v4; // w0
  unsigned __int64 v12; // x10

  if ( (byte_7B4C & 1) != 0 || !dword_7B68 )
  {
    v2 = a1;
  }
  else
  {
    v2 = a1;
    v3 = (unsigned int *)(qword_7B58 + qword_7B60 * a1);
    v4 = readl_relaxed(v3);
    writel_relaxed(v4 & 0xFDFFFFFF, v3);
  }
  if ( ((*(unsigned __int64 *)((char *)&gic_routing_data[1] + ((v2 >> 3) & 0x1FFFFFF8)) >> v2) & 1) != 0 )
  {
    if ( !dword_7B40 )
      queue_delayed_work_on(32, system_wq, &affinity_initialize_work, 1250);
    _X9 = (unsigned __int64 *)&gic_routing_data[(a1 >> 6) + 3];
    __asm { PRFM            #0x11, [X9] }
    do
      v12 = __ldxr(_X9);
    while ( __stxr(v12 | (1LL << a1), _X9) );
  }
  return 0;
}
