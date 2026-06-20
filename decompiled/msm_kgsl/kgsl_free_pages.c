__int64 __fastcall kgsl_free_pages(__int64 a1)
{
  int v2; // w8
  int v3; // w8
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x8
  unsigned __int64 v9; // x10
  unsigned __int64 v16; // x10

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
        v16 = __ldxr((unsigned __int64 *)&qword_3A8A8);
      while ( __stxr(v16 - v4, (unsigned __int64 *)&qword_3A8A8) );
      *(_QWORD *)(a1 + 8) = 0;
    }
  }
  else if ( v2 )
  {
    __break(0x800u);
  }
  result = mutex_unlock(&kernel_map_global_lock);
  if ( *(_QWORD *)(a1 + 8) )
  {
    __break(0x800u);
    if ( (*(_DWORD *)(a1 + 48) & 8) != 0 )
      return result;
  }
  else if ( (*(_DWORD *)(a1 + 48) & 8) != 0 )
  {
    return result;
  }
  v6 = *(_QWORD *)(a1 + 40);
  _X9 = &qword_3A8B8;
  __asm { PRFM            #0x11, [X9] }
  do
    v9 = __ldxr((unsigned __int64 *)&qword_3A8B8);
  while ( __stxr(v9 - v6, (unsigned __int64 *)&qword_3A8B8) );
  return kgsl_free_pages(a1);
}
