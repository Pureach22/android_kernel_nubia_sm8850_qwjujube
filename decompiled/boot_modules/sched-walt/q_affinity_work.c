__int64 __fastcall q_affinity_work(__int64 result, _DWORD *a2)
{
  int v3; // w19
  __int64 v4; // x9
  int v5; // w8
  __int64 v6; // x19
  __int64 v7; // x22
  void *v8; // x0

  if ( (int)result < 1 )
    return result;
  if ( !*a2 )
    return printk(&unk_63FC5);
  v3 = result;
  result = _kmalloc_cache_noprof(android_rvh_probe_register, 3520, 56);
  if ( sched_nbia_debug )
  {
    v7 = result;
    printk(&unk_642A1);
    result = v7;
    if ( v7 )
      goto LABEL_5;
LABEL_13:
    if ( sched_nbia_debug )
      return printk(&unk_6273F);
    return result;
  }
  if ( !result )
    goto LABEL_13;
LABEL_5:
  v4 = *(_QWORD *)a2;
  *(_DWORD *)result = v3;
  v5 = (unsigned __int8)kthread_running;
  *(_QWORD *)(result + 8) = v4;
  if ( v5 != 1 )
  {
    if ( !sched_nbia_debug )
      return kfree(result);
    v6 = result;
    v8 = &unk_642D5;
    goto LABEL_18;
  }
  *(_QWORD *)(result + 40) = 0;
  *(_QWORD *)(result + 48) = 0;
  v6 = result;
  *(_QWORD *)(result + 16) = result + 16;
  *(_QWORD *)(result + 24) = result + 16;
  *(_QWORD *)(result + 32) = nbia_affinity_ctrl_work;
  result = kthread_queue_work(&worker, result + 16);
  if ( (result & 1) == 0 )
  {
    if ( !sched_nbia_debug )
    {
LABEL_8:
      result = v6;
      return kfree(result);
    }
    v8 = &unk_61C50;
LABEL_18:
    printk(v8);
    goto LABEL_8;
  }
  return result;
}
