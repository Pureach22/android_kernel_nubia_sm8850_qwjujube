__int64 __fastcall spf_core_probe(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x21
  __int64 v4; // x8
  int v5; // w9

  printk(&unk_6F1B, "spf_core_probe");
  if ( spf_core_priv )
  {
    mutex_lock(spf_core_priv + 8);
    v2 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
    if ( v2 )
    {
      *(_QWORD *)(a1 + 152) = v2;
      v3 = (_QWORD *)v2;
      _mutex_init(v2 + 32, "&core->lock", &spf_core_probe___key);
      *v3 = a1;
      _init_waitqueue_head(v3 + 1, "&core->wait", &spf_core_probe___key_27);
      v4 = spf_core_priv;
      v5 = *(unsigned __int8 *)(spf_core_priv + 64);
      *(_QWORD *)(spf_core_priv + 56) = v3;
      if ( v5 == 1 )
      {
        queue_work_on(32, system_wq, v4 + 72);
        v4 = spf_core_priv;
      }
      mutex_unlock(v4 + 8);
      return 0;
    }
    else
    {
      mutex_unlock(spf_core_priv + 8);
      return 4294967284LL;
    }
  }
  else
  {
    printk(&unk_6E27, "spf_core_probe");
    return 4294966779LL;
  }
}
