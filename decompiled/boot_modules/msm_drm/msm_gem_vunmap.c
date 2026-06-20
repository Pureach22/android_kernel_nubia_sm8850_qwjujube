__int64 __fastcall msm_gem_vunmap(__int64 a1)
{
  mutex_lock(a1 + 544);
  msm_gem_vunmap_locked(a1);
  return mutex_unlock(a1 + 544);
}
