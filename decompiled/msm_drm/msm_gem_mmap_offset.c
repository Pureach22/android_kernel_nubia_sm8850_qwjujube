__int64 __fastcall msm_gem_mmap_offset(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x20

  mutex_lock(a1 + 544);
  v2 = *(_QWORD *)(a1 + 8);
  if ( (mutex_is_locked(a1 + 544) & 1) == 0 )
    __break(0x800u);
  if ( (unsigned int)drm_gem_create_mmap_offset(a1) )
  {
    dev_err(*(_QWORD *)(v2 + 8), "[%s:%d] could not allocate mmap offset\n", "mmap_offset", 334);
    v3 = 0;
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 40) << 12;
  }
  mutex_unlock(a1 + 544);
  return v3;
}
