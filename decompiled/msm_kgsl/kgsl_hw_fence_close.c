__int64 kgsl_hw_fence_close()
{
  __int64 *v0; // x19
  __int64 *v1; // x23
  __int64 **v2; // x8
  __int64 *v3; // x9
  unsigned __int64 v10; // x9

  raw_spin_lock(&hw_fence_list_lock);
  v0 = (__int64 *)hw_fence_list;
  if ( (__int64 *)hw_fence_list != &hw_fence_list )
  {
    do
    {
      v1 = (__int64 *)*v0;
      synx_release(kgsl_synx, *((unsigned int *)v0 - 2));
      _X8 = (unsigned __int64 *)(v0 - 8);
      __asm { PRFM            #0x11, [X8] }
      do
        v10 = __ldxr(_X8);
      while ( __stxr(v10 & 0xFFFFFFFF7FFFFFFFLL, _X8) );
      v2 = (__int64 **)v0[1];
      if ( *v2 == v0 && (v3 = (__int64 *)*v0, *(__int64 **)(*v0 + 8) == v0) )
      {
        v3[1] = (__int64)v2;
        *v2 = v3;
      }
      else
      {
        _list_del_entry_valid_or_report(v0);
      }
      *v0 = (__int64)v0;
      v0[1] = (__int64)v0;
      v0 = v1;
    }
    while ( v1 != &hw_fence_list );
  }
  raw_spin_unlock(&hw_fence_list_lock);
  return synx_uninitialize(kgsl_synx);
}
