__int64 __fastcall walt_detach_task(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v10; // x0

  v3 = *(unsigned __int8 *)(a1 + 273);
  v6 = a2;
  if ( !v3 || (unsigned int)sysctl_panic_on_walt_bug >> 8 != 4539614 )
    goto LABEL_8;
  if ( (sysctl_panic_on_walt_bug & 0x10) == 0 )
  {
    if ( (sysctl_panic_on_walt_bug & 2) != 0 )
      goto LABEL_5;
LABEL_8:
    deactivate_task(v6, a1, 0);
    return set_task_cpu(a1, *(unsigned int *)(a3 + 3632));
  }
  printk_deferred(
    "WALT-BUG Dequeuing when task is delayed: src_cpu=%d dst_cpu=%d\n",
    *(_DWORD *)(a2 + 3632),
    *(_DWORD *)(a3 + 3632));
  v6 = a2;
  if ( (sysctl_panic_on_walt_bug & 2) == 0 )
    goto LABEL_8;
LABEL_5:
  if ( a1 )
  {
    v7 = v6;
    walt_task_dump((unsigned __int64 *)a1);
    v6 = v7;
  }
  if ( in_sched_bug )
    goto LABEL_8;
  in_sched_bug = 1;
  v10 = walt_dump();
  __break(0x800u);
  return walt_attach_task(v10);
}
