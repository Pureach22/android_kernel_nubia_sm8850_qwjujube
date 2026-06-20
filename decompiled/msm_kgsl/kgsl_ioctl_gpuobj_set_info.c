__int64 __fastcall kgsl_ioctl_gpuobj_set_info(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w1
  unsigned int v6; // w8
  unsigned __int8 *v7; // x20
  size_t v8; // x21
  __int64 v9; // x22
  unsigned int *v10; // x23
  __int64 v11; // x20
  __int64 v13; // x8
  int v19; // w8

  v3 = *(_DWORD *)(a3 + 16);
  if ( !v3 )
    return -22;
  _X0 = kgsl_sharedmem_find_id(*(_QWORD *)(a1 + 8), v3);
  if ( !_X0 )
    return -22;
  if ( (*(_BYTE *)a3 & 1) != 0 )
  {
    v6 = *(_DWORD *)(a3 + 20);
    if ( v6 )
    {
      v7 = (unsigned __int8 *)(_X0 + 67);
      if ( v6 >= 0x40 )
        v8 = 64;
      else
        v8 = v6;
      v9 = *(_QWORD *)(a3 + 8);
      v10 = _X0;
      _check_object_size(_X0 + 67, v8, 0);
      if ( inline_copy_from_user_0((int)v7, v9, v8) )
      {
        v7[64] = 0;
        _X0 = v10;
        *((_QWORD *)v7 + 6) = 0;
        *((_QWORD *)v7 + 7) = 0;
        *((_QWORD *)v7 + 4) = 0;
        *((_QWORD *)v7 + 5) = 0;
        *((_QWORD *)v7 + 2) = 0;
        *((_QWORD *)v7 + 3) = 0;
        *(_QWORD *)v7 = 0;
        *((_QWORD *)v7 + 1) = 0;
      }
      else
      {
        _X0 = v10;
        do
        {
          if ( !*v7 )
            break;
          if ( (*((_BYTE *)&ctype + *v7) & 0x97) == 0 )
            *v7 = 63;
          --v8;
          ++v7;
        }
        while ( v8 );
      }
    }
  }
  if ( (*(_BYTE *)a3 & 2) != 0 )
  {
    if ( *(_WORD *)(a3 + 25) )
    {
      v11 = -22;
      if ( (unsigned __int64)_X0 > 0xFFFFFFFFFFFFF000LL )
        return v11;
    }
    else
    {
      v13 = *((_QWORD *)_X0 + 10);
      v11 = 0;
      *((_QWORD *)_X0 + 10) = v13 & 0xFFFFFFFFFFFF00FFLL;
      *((_QWORD *)_X0 + 10) = v13 & 0xFFFFFFFFFFFF00FFLL
                            | ((unsigned __int64)(unsigned __int8)*(_DWORD *)(a3 + 24) << 8);
      if ( (unsigned __int64)_X0 > 0xFFFFFFFFFFFFF000LL )
        return v11;
    }
  }
  else
  {
    v11 = 0;
    if ( (unsigned __int64)_X0 > 0xFFFFFFFFFFFFF000LL )
      return v11;
  }
  __asm { PRFM            #0x11, [X0] }
  do
    v19 = __ldxr(_X0);
  while ( __stlxr(v19 - 1, _X0) );
  if ( v19 == 1 )
  {
    __dmb(9u);
    kgsl_mem_entry_destroy(_X0);
  }
  else if ( v19 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  return v11;
}
