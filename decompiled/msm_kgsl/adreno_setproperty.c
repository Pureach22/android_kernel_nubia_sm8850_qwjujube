__int64 __fastcall adreno_setproperty(__int64 *a1, int a2, int a3, int a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x24
  int v10; // w22
  char v11; // w0
  size_t v12; // x22
  unsigned int v14; // w21
  __int64 v15; // x22
  __int64 v16; // x20
  unsigned int v18; // w24
  unsigned int v20; // w8
  __int64 v23; // x22
  int v24; // w23
  size_t v25; // x21
  unsigned int (__fastcall *v26)(_QWORD); // x8
  __int64 v27; // x8
  __int64 v28; // x1
  __int64 v29; // x0
  __int64 v30; // x2
  unsigned int v31; // w19
  __int64 v32; // x1
  void (__fastcall *v33)(__int64, __int64, __int64); // x8
  void (__fastcall *v34)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v35)(__int64, __int64); // x8
  int v37; // w8
  unsigned __int64 v44; // x10
  int v46; // w8
  unsigned int v47; // w19
  unsigned __int64 v50; // x9
  __int64 v51; // [xsp+0h] [xbp-20h] BYREF
  __int64 v52; // [xsp+8h] [xbp-18h]
  __int64 v53; // [xsp+10h] [xbp-10h]
  __int64 v54; // [xsp+18h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  if ( a2 != 18 )
  {
    if ( a2 != 51 )
    {
      if ( a2 == 34 )
        goto LABEL_4;
      if ( a2 != 14 )
      {
        result = 4294967277LL;
        goto LABEL_49;
      }
      if ( a4 != 4 )
      {
LABEL_34:
        result = 4294967274LL;
        goto LABEL_49;
      }
      LODWORD(v51) = 0;
      if ( inline_copy_from_user((int)&v51, a3, 4u) )
        goto LABEL_6;
      rt_mutex_lock(v4 + 11088);
      v10 = v51;
      v11 = gmu_core_isenabled(v4);
      if ( v10 )
      {
        if ( (v11 & 1) != 0 )
        {
          _X8 = (unsigned __int64 *)(v4 + 1528);
          __asm { PRFM            #0x11, [X8] }
          do
            v44 = __ldxr(_X8);
          while ( __stxr(v44 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
        }
        else
        {
          *(_QWORD *)(v4 + 9136) = 0;
        }
        if ( *(_BYTE *)(v4 + 14232) == 1 )
        {
          kgsl_pwrscale_tz_enable(v4);
LABEL_71:
          rt_mutex_unlock(v4 + 11088);
          result = 0;
          goto LABEL_49;
        }
        v27 = *(_QWORD *)(v4 + 8752);
        v28 = (unsigned int)v51;
        v29 = v4;
        v30 = 5;
      }
      else
      {
        if ( (v11 & 1) != 0 )
        {
          _X8 = (unsigned __int64 *)(v4 + 1528);
          __asm { PRFM            #0x11, [X8] }
          do
            v50 = __ldxr(_X8);
          while ( __stxr(v50 | 0x40, _X8) );
          v26 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 14264) + 40LL) + 160LL)
                                                      + 16LL);
          if ( *((_DWORD *)v26 - 1) != -83892780 )
            __break(0x8228u);
          if ( !v26(v4) )
            adreno_active_count_put(v4);
        }
        else
        {
          kgsl_pwrctrl_change_state(v4, 2);
          *(_QWORD *)(v4 + 9136) = 63;
        }
        if ( *(_BYTE *)(v4 + 14232) == 1 )
        {
          kgsl_pwrscale_tz_disable(v4, 1);
          goto LABEL_71;
        }
        v32 = (unsigned int)v51;
        v33 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v4 + 8752) + 304LL);
        if ( *((_DWORD *)v33 - 1) != -227291694 )
          __break(0x8228u);
        v33(v4, v32, 5);
        v27 = *(_QWORD *)(v4 + 8752);
        v29 = v4;
        v28 = 0;
        v30 = 3;
      }
      v34 = *(void (__fastcall **)(__int64, __int64, __int64))(v27 + 304);
      if ( *((_DWORD *)v34 - 1) != -227291694 )
        __break(0x8228u);
      v34(v29, v28, v30);
      goto LABEL_71;
    }
    v7 = *(_QWORD *)(v4 + 14264);
    v8 = a1[1];
    v9 = *(_QWORD *)(v4 + 22784);
    v51 = 0;
    v52 = 0;
    if ( (*(_BYTE *)(v7 + 35) & 4) == 0 )
    {
      result = 4294967201LL;
      goto LABEL_49;
    }
    LODWORD(v12) = a4;
    mutex_lock(v8 + 904);
    if ( (*(_BYTE *)(v8 + 689) & 1) != 0 )
    {
      v14 = -22;
    }
    else if ( *(_QWORD *)(v8 + 704) && *(_QWORD *)(v8 + 736) >= 0x70u )
    {
      if ( (unsigned int)v12 >= 0x10 )
        v12 = 16;
      else
        v12 = (unsigned int)v12;
      _check_object_size(&v51, v12, 0);
      if ( !inline_copy_from_user((int)&v51, a3, v12) )
      {
        v23 = *(_QWORD *)(v8 + 704);
        v24 = v51;
        if ( (unsigned int)v52 >= 0x38 )
          v25 = 56;
        else
          v25 = (unsigned int)v52;
        _check_object_size(*(_QWORD *)(v8 + 704), v25, 0);
        if ( !inline_copy_from_user(v23, v24, v25) )
        {
          if ( *(_QWORD *)(v9 + 32) && *(_BYTE *)(v4 + 24528) == 1 )
          {
            rt_mutex_lock(v4 + 11088);
            v35 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 32);
            if ( *((_DWORD *)v35 - 1) != 636997689 )
              __break(0x8228u);
            v14 = v35(v4, v8);
            rt_mutex_unlock(v4 + 11088);
          }
          else
          {
            v14 = 0;
          }
          goto LABEL_48;
        }
        memset(*(void **)(v8 + 704), 255, v25);
      }
      v14 = -14;
    }
    else
    {
      v14 = -12;
    }
LABEL_48:
    mutex_unlock(v8 + 904);
    result = v14;
    goto LABEL_49;
  }
LABEL_4:
  v52 = 0;
  v53 = 0;
  v51 = 0;
  if ( a4 != 24 )
    goto LABEL_34;
  if ( inline_copy_from_user((int)&v51, a3, 0x18u) )
  {
LABEL_6:
    result = 4294967282LL;
    goto LABEL_49;
  }
  v15 = *a1;
  v16 = HIDWORD(v51);
  raw_read_lock(*a1 + 11208);
  _X0 = idr_find(v15 + 11184, v16);
  if ( !_X0 || (*(_QWORD *)(_X0 + 32) & 2) != 0 )
  {
    raw_read_unlock(v15 + 11208);
    goto LABEL_34;
  }
  v18 = *(_DWORD *)_X0;
  if ( *(_DWORD *)_X0 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v20 = __ldxr((unsigned int *)_X0);
      while ( v20 == v18 && __stxr(v18 + 1, (unsigned int *)_X0) );
      if ( v20 == v18 )
        break;
      v18 = v20;
    }
    while ( v20 );
  }
  _X20 = _X0;
  if ( (((v18 + 1) | v18) & 0x80000000) != 0 )
    refcount_warn_saturate(_X0, 0);
  raw_read_unlock(v15 + 11208);
  if ( !v18 )
    goto LABEL_34;
  _X0 = _X20;
  if ( *(__int64 **)(_X20 + 16) != a1 )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v37 = __ldxr((unsigned int *)_X20);
    while ( __stlxr(v37 - 1, (unsigned int *)_X20) );
    if ( v37 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy(_X20);
    }
    else if ( v37 <= 0 )
    {
      refcount_warn_saturate(_X20, 3);
    }
    goto LABEL_34;
  }
  result = adreno_set_constraint(v4, (unsigned int *)_X20, (__int64)&v51);
  __asm { PRFM            #0x11, [X20] }
  do
    v46 = __ldxr((unsigned int *)_X20);
  while ( __stlxr(v46 - 1, (unsigned int *)_X20) );
  if ( v46 == 1 )
  {
    __dmb(9u);
    v31 = result;
    kgsl_context_destroy(_X20);
    result = v31;
  }
  else if ( v46 <= 0 )
  {
    v47 = result;
    refcount_warn_saturate(_X20, 3);
    result = v47;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
