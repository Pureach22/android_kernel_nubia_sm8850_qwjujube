__int64 __fastcall spf_core_exit(__int64 a1)
{
  __int64 v1; // x19

  if ( spf_core_priv )
  {
    v1 = *(_QWORD *)(a1 + 152);
    mutex_lock(spf_core_priv + 8);
    *(_QWORD *)(spf_core_priv + 56) = 0;
    kfree(v1);
    mutex_unlock(spf_core_priv + 8);
    return 0;
  }
  else
  {
    printk(&unk_6E27, "spf_core_exit");
    return 0xFFFFFFFFLL;
  }
}
