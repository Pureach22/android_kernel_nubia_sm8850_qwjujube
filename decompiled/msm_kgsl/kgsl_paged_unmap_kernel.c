__int64 __fastcall kgsl_paged_unmap_kernel(__int64 a1)
{
  int v2; // w8
  int v3; // w8
  __int64 v4; // x8
  unsigned __int64 v12; // x10

  mutex_lock(&kernel_map_global_lock);
  v2 = *(_DWORD *)(a1 + 16);
  if ( *(_QWORD *)(a1 + 8) )
  {
    v3 = v2 - 1;
    *(_DWORD *)(a1 + 16) = v3;
    if ( !v3 )
    {
      vunmap();
      v4 = *(_QWORD *)(a1 + 40);
      _X9 = &qword_3A8A8;
      __asm { PRFM            #0x11, [X9] }
      do
        v12 = __ldxr((unsigned __int64 *)&qword_3A8A8);
      while ( __stxr(v12 - v4, (unsigned __int64 *)&qword_3A8A8) );
      *(_QWORD *)(a1 + 8) = 0;
    }
  }
  else if ( v2 )
  {
    __break(0x800u);
  }
  return mutex_unlock(&kernel_map_global_lock);
}
