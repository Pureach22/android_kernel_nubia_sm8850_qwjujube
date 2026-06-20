unsigned __int64 __fastcall kgsl_ioctl_gpuobj_alloc(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 result; // x0
  unsigned int v5; // w8
  unsigned __int8 *v6; // x20
  size_t v7; // x21
  __int64 v8; // x22
  unsigned __int64 v9; // x23
  unsigned __int64 v10; // x8
  int v16; // w8

  result = gpumem_alloc_entry(a1, *(_QWORD *)a3, *(_QWORD *)(a3 + 8));
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = *(_DWORD *)(a3 + 36);
    if ( v5 )
    {
      v6 = (unsigned __int8 *)(result + 268);
      if ( v5 >= 0x40 )
        v7 = 64;
      else
        v7 = v5;
      v8 = *(_QWORD *)(a3 + 40);
      v9 = result;
      _check_object_size(result + 268, v7, 0);
      if ( inline_copy_from_user_0((int)v6, v8, v7) )
      {
        v6[64] = 0;
        result = v9;
        *((_QWORD *)v6 + 6) = 0;
        *((_QWORD *)v6 + 7) = 0;
        *((_QWORD *)v6 + 4) = 0;
        *((_QWORD *)v6 + 5) = 0;
        *((_QWORD *)v6 + 2) = 0;
        *((_QWORD *)v6 + 3) = 0;
        *(_QWORD *)v6 = 0;
        *((_QWORD *)v6 + 1) = 0;
      }
      else
      {
        result = v9;
        do
        {
          if ( !*v6 )
            break;
          if ( (*((_BYTE *)&ctype + *v6) & 0x97) == 0 )
            *v6 = 63;
          --v7;
          ++v6;
        }
        while ( v7 );
      }
    }
    *(_QWORD *)a3 = *(_QWORD *)(result + 48);
    *(_QWORD *)(a3 + 8) = *(_QWORD *)(result + 80);
    if ( (*(_DWORD *)(result + 56) & 1) != 0 )
      v10 = (*(_QWORD *)(result + 48) + 0x1FFFLL) & 0xFFFFFFFFFFFFF000LL;
    else
      v10 = *(_QWORD *)(result + 48);
    *(_QWORD *)(a3 + 24) = v10;
    *(_DWORD *)(a3 + 32) = *(_DWORD *)(result + 248);
    if ( result )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v16 = __ldxr((unsigned int *)result);
      while ( __stlxr(v16 - 1, (unsigned int *)result) );
      if ( v16 == 1 )
      {
        __dmb(9u);
        kgsl_mem_entry_destroy((_QWORD *)result);
      }
      else if ( v16 <= 0 )
      {
        refcount_warn_saturate(result, 3);
      }
      return 0;
    }
  }
  return result;
}
