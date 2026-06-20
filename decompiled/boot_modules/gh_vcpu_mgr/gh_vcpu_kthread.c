__int64 __fastcall gh_vcpu_kthread(unsigned __int16 **a1)
{
  __int64 v2; // x26
  unsigned __int16 *v3; // x25
  __int64 v4; // x0
  unsigned int v5; // w24
  _QWORD *StatusReg; // x21
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // w24
  __int64 v10; // x2
  __int64 v11; // x0
  __int64 v12; // x0
  _QWORD v14[4]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v15; // [xsp+20h] [xbp-20h] BYREF
  __int64 v16; // [xsp+28h] [xbp-18h]
  __int64 v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (__int64)*a1;
  v3 = a1[9];
  v16 = 0;
  v17 = 0;
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  v4 = set_freezable();
  if ( (kthread_should_stop(v4) & 1) == 0 )
  {
    StatusReg = (_QWORD *)_ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v7 = mutex_lock(v3 + 8);
      if ( **((_BYTE **)v3 + 9) )
      {
        mutex_unlock(v3 + 8);
        v5 = -4;
        goto LABEL_43;
      }
      android_rvh_gh_before_vcpu_run(v7, **a1, *((_DWORD *)v3 + 47));
      v8 = gunyah_hypercall_vcpu_run(*(_QWORD *)(*((_QWORD *)v3 + 1) + 8LL), &v15, v14);
      v9 = v8;
      android_rvh_gh_after_vcpu_run(v8, **a1, *((_DWORD *)v3 + 47), v8, (int *)v14);
      if ( v9 > 9 )
      {
        if ( (unsigned int)v9 <= 0x3D )
        {
          if ( ((1LL << v9) & 0x3C000040000000LL) != 0 )
          {
            v5 = -13;
            goto LABEL_39;
          }
          if ( ((1LL << v9) & 0x3000030000000000LL) != 0 )
          {
            v5 = -5;
            goto LABEL_39;
          }
          if ( ((1LL << v9) & 0x40000180000000LL) != 0 )
          {
            v5 = -16;
            goto LABEL_39;
          }
        }
        if ( v9 == 10 )
        {
          v5 = -12;
          goto LABEL_39;
        }
LABEL_24:
        v5 = -22;
        goto LABEL_39;
      }
      if ( v9 == -2 )
        goto LABEL_37;
      if ( v9 == -1 )
      {
        v5 = -95;
        goto LABEL_39;
      }
      if ( v9 )
        goto LABEL_24;
      v16 = 0;
      v17 = 0;
      v15 = 0;
      if ( SLODWORD(v14[0]) > 3 )
        break;
      if ( SLODWORD(v14[0]) > 1 )
      {
        if ( LODWORD(v14[0]) == 2 )
          goto LABEL_33;
        goto LABEL_37;
      }
      if ( LODWORD(v14[0]) )
      {
        if ( LODWORD(v14[0]) == 1 )
          goto LABEL_35;
        goto LABEL_31;
      }
      if ( (*StatusReg & 2) != 0 )
        goto LABEL_37;
LABEL_38:
      v5 = 0;
LABEL_39:
      v11 = mutex_unlock(v3 + 8);
      if ( (kthread_should_stop(v11) & 1) != 0 || v5 )
        goto LABEL_43;
    }
    v5 = 0;
    if ( (unsigned int)(LODWORD(v14[0]) - 4) < 2 || LODWORD(v14[0]) == 7 )
      goto LABEL_39;
    if ( LODWORD(v14[0]) == 256 )
    {
LABEL_33:
      if ( **((_BYTE **)v3 + 9) )
      {
        v5 = -4;
        goto LABEL_39;
      }
LABEL_35:
      v5 = wait_for_completion_interruptible(v3 + 48);
      *((_DWORD *)v3 + 24) = 0;
      goto LABEL_39;
    }
LABEL_31:
    if ( (unsigned int)__ratelimit(&gh_vcpu_kthread__rs, "gh_vcpu_kthread") )
      printk(&unk_7BE2, v14[0], v10);
LABEL_37:
    schedule();
    goto LABEL_38;
  }
  v5 = 0;
LABEL_43:
  mutex_lock(&gh_vm_mutex);
  if ( v2 )
  {
    v12 = xa_load(v2 + 8, *((unsigned int *)v3 + 47));
    if ( v12 )
      *(_QWORD *)(v12 + 72) = 0;
  }
  mutex_unlock(&gh_vm_mutex);
  gunyah_vm_put(*((_QWORD *)v3 + 8));
  _ReadStatusReg(SP_EL0);
  return v5;
}
