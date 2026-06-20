unsigned int *__fastcall msm_gem_import(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v5; // x2
  __int64 v6; // x23
  __int64 v7; // x24
  int v8; // w0
  int v10; // w20
  int v11; // w8
  unsigned int *v12; // x0
  __int64 v13; // x2
  unsigned int *v14; // x1
  int v20; // w8
  __int64 v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a2[15];
  v6 = *(_QWORD *)(a1 + 56);
  v7 = *a2;
  v22[0] = 0;
  v8 = msm_gem_new_impl(a1, 0x20000, v5, v22);
  _X19 = (unsigned int *)v22[0];
  if ( v8 )
  {
    v10 = v8;
    if ( v22[0] )
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v20 = __ldxr(_X19);
      while ( __stlxr(v20 - 1, _X19) );
      if ( v20 == 1 )
      {
        __dmb(9u);
        drm_gem_object_free(_X19);
      }
      else if ( v20 <= 0 )
      {
        refcount_warn_saturate(_X19, 3);
      }
    }
    _X19 = (unsigned int *)v10;
  }
  else
  {
    drm_gem_private_object_init(a1, v22[0], ((_DWORD)v7 + 4095) & 0xFFFFF000);
    mutex_lock(_X19 + 136);
    v11 = *(int *)((char *)&dword_170 + (_QWORD)_X19);
    *(_QWORD *)((char *)&unk_1A0 + (_QWORD)_X19) = 0;
    *(_QWORD *)((char *)&unk_1A0 + (_QWORD)_X19 + 8) = a3;
    *(int *)((char *)&dword_170 + (_QWORD)_X19) = v11 | 0x40000000;
    mutex_unlock(_X19 + 136);
    mutex_lock(v6 + 640);
    v12 = _X19 + 94;
    v13 = v6 + 624;
    v14 = *(unsigned int **)(v6 + 632);
    if ( _X19 + 94 == (unsigned int *)(v6 + 624) || v14 == v12 || *(_QWORD *)v14 != v13 )
    {
      _list_add_valid_or_report(v12, v14);
    }
    else
    {
      *(_QWORD *)(v6 + 632) = v12;
      *(__int64 *)((char *)&qword_178 + (_QWORD)_X19) = v13;
      *(__int64 *)((char *)&qword_178 + (_QWORD)_X19 + 8) = (__int64)v14;
      *(_QWORD *)v14 = v12;
    }
    mutex_unlock(v6 + 640);
  }
  _ReadStatusReg(SP_EL0);
  return _X19;
}
