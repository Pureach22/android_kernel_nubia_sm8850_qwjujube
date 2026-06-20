__int64 __fastcall kgsl_ioctl_gpuobj_free(__int64 *a1, __int64 a2, __int64 a3)
{
  unsigned int *id; // x0
  __int64 result; // x0
  int v8; // w8
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x21
  size_t v12; // x22
  __int64 v13; // x8
  __int64 owner; // x0
  __int64 v16; // x20
  __int64 v17; // x9
  unsigned __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x20
  size_t v21; // x21
  __int64 v22; // x8
  unsigned __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x8
  int v31; // w8
  __int64 v32; // x20
  int v34; // w8
  _QWORD v35[2]; // [xsp+0h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  id = kgsl_sharedmem_find_id(a1[1], *(_DWORD *)(a3 + 16));
  if ( !id )
  {
    result = -22;
    goto LABEL_60;
  }
  _X19 = (unsigned __int64)id;
  if ( (*(_BYTE *)a3 & 1) == 0 )
  {
    result = gpumem_free_entry((unsigned __int64)id);
    if ( _X19 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_60;
    goto LABEL_54;
  }
  v8 = *(_DWORD *)(a3 + 20);
  if ( v8 != 2 )
  {
    if ( v8 == 1 )
    {
      v9 = *(unsigned int *)(a3 + 24);
      v10 = 8;
      v11 = *(_QWORD *)(a3 + 8);
      v35[0] = 0;
      if ( v9 >= 8 )
        v12 = 8;
      else
        v12 = v9;
      if ( v9 > 8 )
        v10 = v9;
      if ( (unsigned int)v9 > 7 )
      {
        if ( (_DWORD)v9 != 8 && (int)check_zeroed_user(v11 + v12, v10 - v12) < 1 )
          goto LABEL_36;
      }
      else
      {
        memset((char *)v35 + v12, 0, v10 - v12);
      }
      _check_object_size(v35, v12, 0);
      if ( !inline_copy_from_user_0((int)v35, v11, v12) )
      {
        if ( LODWORD(v35[0]) )
        {
          owner = kgsl_context_get_owner(a1, v35[0]);
          if ( owner )
          {
            _X21 = (unsigned int *)owner;
            result = gpumem_free_entry_on_timestamp(*a1, _X19, owner, HIDWORD(v35[0]));
            __asm { PRFM            #0x11, [X21] }
            do
              v31 = __ldxr(_X21);
            while ( __stlxr(v31 - 1, _X21) );
            if ( v31 == 1 )
            {
              __dmb(9u);
              v16 = result;
              kgsl_context_destroy((__int64)_X21);
            }
            else
            {
              if ( v31 > 0 )
              {
                if ( _X19 > 0xFFFFFFFFFFFFF000LL )
                  goto LABEL_60;
                goto LABEL_54;
              }
              v16 = result;
              refcount_warn_saturate(_X21, 3);
            }
            goto LABEL_41;
          }
        }
        goto LABEL_44;
      }
LABEL_36:
      result = -14;
      if ( _X19 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_60;
      goto LABEL_54;
    }
LABEL_44:
    result = -22;
    if ( _X19 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_60;
    goto LABEL_54;
  }
  v13 = *((_QWORD *)id + 32);
  LODWORD(v35[0]) = 0;
  raw_spin_lock(v13 + 32);
  if ( *(_DWORD *)(_X19 + 264) )
  {
    raw_spin_unlock(*(_QWORD *)(_X19 + 256) + 32LL);
    result = -16;
    if ( _X19 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_60;
    goto LABEL_54;
  }
  v17 = *(_QWORD *)(_X19 + 256);
  *(_DWORD *)(_X19 + 264) = 1;
  raw_spin_unlock(v17 + 32);
  v18 = *(unsigned int *)(a3 + 24);
  v19 = 4;
  v20 = *(_QWORD *)(a3 + 8);
  if ( v18 >= 4 )
    v21 = 4;
  else
    v21 = *(unsigned int *)(a3 + 24);
  if ( v18 > 4 )
    v19 = v18;
  if ( (unsigned int)v18 > 3 )
  {
    if ( (_DWORD)v18 != 4 && (int)check_zeroed_user(v20 + v21, v19 - v21) < 1 )
      goto LABEL_35;
  }
  else
  {
    memset((char *)v35 + v21, 0, v19 - v21);
  }
  _check_object_size(v35, v21, 0);
  if ( inline_copy_from_user_0((int)v35, v20, v21) )
  {
LABEL_35:
    raw_spin_lock(*(_QWORD *)(_X19 + 256) + 32LL);
    v22 = *(_QWORD *)(_X19 + 256);
    *(_DWORD *)(_X19 + 264) = 0;
    raw_spin_unlock(v22 + 32);
    goto LABEL_36;
  }
  if ( (v35[0] & 0x80000000) != 0 )
  {
    raw_spin_lock(*(_QWORD *)(_X19 + 256) + 32LL);
    v25 = *(_QWORD *)(_X19 + 256);
    *(_DWORD *)(_X19 + 264) = 0;
    raw_spin_unlock(v25 + 32);
    goto LABEL_44;
  }
  v23 = kgsl_sync_fence_async_wait();
  if ( v23 >= 0xFFFFFFFFFFFFF001LL )
  {
    v16 = v23;
    raw_spin_lock(*(_QWORD *)(_X19 + 256) + 32LL);
    v24 = *(_QWORD *)(_X19 + 256);
    *(_DWORD *)(_X19 + 264) = 0;
    raw_spin_unlock(v24 + 32);
LABEL_41:
    result = v16;
    if ( _X19 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_60;
    goto LABEL_54;
  }
  if ( !v23 )
    gpuobj_free_fence_func(_X19);
  result = 0;
  if ( _X19 <= 0xFFFFFFFFFFFFF000LL )
  {
LABEL_54:
    __asm { PRFM            #0x11, [X19] }
    do
      v34 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v34 - 1, (unsigned int *)_X19) );
    v32 = result;
    if ( v34 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy((_QWORD *)_X19);
    }
    else if ( v34 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
    result = v32;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
