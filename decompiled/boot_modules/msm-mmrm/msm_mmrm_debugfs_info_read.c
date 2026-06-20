__int64 __fastcall msm_mmrm_debugfs_info_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  __int64 v8; // x19

  v7 = _kmalloc_cache_noprof(clk_set_rate, 3520, 4096);
  if ( v7 )
  {
    v8 = simple_read_from_buffer(a2, a3, a4, v7, 0);
    kfree(v7);
  }
  else
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_C2BA, "err ", "msm_mmrm_debugfs_info_read");
    return -12;
  }
  return v8;
}
