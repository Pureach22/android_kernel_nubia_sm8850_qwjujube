__int64 __fastcall sde_kms_init(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  int v4; // w0
  int v5; // w21

  if ( a1 && *(_QWORD *)(a1 + 56) )
  {
    v2 = _kmalloc_cache_noprof(kthread_unpark, 3520, 6944);
    if ( v2 )
    {
      v3 = (_QWORD *)v2;
      v4 = hfi_kms_init(v2);
      if ( v4 )
      {
        v5 = v4;
        kfree(v3);
        return v5;
      }
      else
      {
        *v3 = kms_funcs;
        v3[17] = a1;
        return (__int64)v3;
      }
    }
    else
    {
      printk(&unk_25EBDB, "sde_kms_init");
      return -12;
    }
  }
  else
  {
    printk(&unk_23F6B8, "sde_kms_init");
    return -22;
  }
}
