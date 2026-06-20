__int64 __fastcall msm_gem_dumb_map_offset(__int64 a1, __int64 a2, unsigned int a3, _QWORD *a4)
{
  __int64 v5; // x0
  __int64 v7; // x21
  __int64 v8; // x21
  int v15; // w8

  v5 = drm_gem_object_lookup(a1, a3);
  if ( !v5 )
    return 4294967294LL;
  _X19 = v5;
  mutex_lock(v5 + 544);
  v7 = *(_QWORD *)(_X19 + 8);
  if ( (mutex_is_locked(_X19 + 544) & 1) == 0 )
    __break(0x800u);
  if ( (unsigned int)drm_gem_create_mmap_offset(_X19) )
  {
    dev_err(*(_QWORD *)(v7 + 8), "[%s:%d] could not allocate mmap offset\n", "mmap_offset", 334);
    v8 = 0;
  }
  else
  {
    v8 = *(_QWORD *)(_X19 + 40) << 12;
  }
  mutex_unlock(_X19 + 544);
  *a4 = v8;
  __asm { PRFM            #0x11, [X19] }
  do
    v15 = __ldxr((unsigned int *)_X19);
  while ( __stlxr(v15 - 1, (unsigned int *)_X19) );
  if ( v15 == 1 )
  {
    __dmb(9u);
    drm_gem_object_free(_X19);
  }
  else if ( v15 <= 0 )
  {
    refcount_warn_saturate(_X19, 3);
  }
  return 0;
}
