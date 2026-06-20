__int64 __fastcall msm_atomic_state_alloc(__int64 a1)
{
  __int64 v2; // x20

  v2 = _kmalloc_cache_noprof(_drm_dev_dbg, 3520, 128);
  if ( !v2 || (drm_atomic_state_init(a1, v2) & 0x80000000) != 0 )
  {
    kfree(v2);
    return 0;
  }
  return v2;
}
