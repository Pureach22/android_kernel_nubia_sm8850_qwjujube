__int64 __fastcall sde_vm_msgq_listener(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 i; // x21
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _ReadStatusReg(SP_EL0);
  v8[1] = v2;
  v3 = a1[8];
  v8[0] = 0;
  for ( i = *(_QWORD *)(*(_QWORD *)(v3 + 136) + 56LL); ; kthread_queue_work(i + 2432, a1 + 24) )
  {
    v5 = _kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 240);
    if ( !v5 )
    {
      result = 4294967284LL;
      goto LABEL_6;
    }
    if ( (gh_msgq_recv(a1[32], v5, 240, v8, 0) & 0x80000000) != 0 )
      break;
    v6 = v8[0];
    a1[31] = a1;
    a1[29] = v5;
    a1[30] = v6;
  }
  kfree(v5);
  printk(&unk_210C80, "_sde_vm_msgq_listener");
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
