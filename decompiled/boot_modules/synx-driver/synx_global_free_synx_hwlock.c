__int64 synx_global_free_synx_hwlock()
{
  __int64 v0; // x4
  __int64 v1; // x5

  if ( (get_ipclite_feature(4) & 1) != 0 )
    return 0;
  if ( synx_hwlock )
  {
    hwspin_lock_free();
    return 0;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_28CA9, &unk_29207, "synx_global_free_synx_hwlock", 199, v0, v1);
  return 4294967274LL;
}
