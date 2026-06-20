__int64 __fastcall kgsl_hw_fence_create(_QWORD *a1, __int64 a2)
{
  int v4; // w0
  int v5; // w21
  __int64 result; // x0
  __int64 v8; // x0
  _QWORD *v9; // x1
  __int64 v11; // x1
  __int64 v12; // x1
  unsigned int v18; // w8
  unsigned int v20; // w8
  _QWORD v21[3]; // [xsp+8h] [xbp-28h] BYREF
  int v22; // [xsp+20h] [xbp-10h]
  int v23; // [xsp+24h] [xbp-Ch]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[2] = a2;
  v23 = 0;
  v21[0] = 0;
  v21[1] = a2 + 104;
  v22 = 4;
  v4 = synx_create(kgsl_synx, v21);
  if ( !v4 )
  {
    raw_spin_lock(&hw_fence_list_lock);
    _X0 = (unsigned int *)(a2 + 128);
    __asm { PRFM            #0x11, [X0] }
    do
      v18 = __ldxr(_X0);
    while ( __stxr(v18 + 1, _X0) );
    if ( v18 )
    {
      if ( (((v18 + 1) | v18) & 0x80000000) == 0 )
      {
LABEL_7:
        v8 = a2 + 112;
        v9 = (_QWORD *)qword_17D230;
        if ( (__int64 *)(a2 + 112) == &hw_fence_list
          || qword_17D230 == v8
          || *(__int64 **)qword_17D230 != &hw_fence_list )
        {
          _list_add_valid_or_report(v8, qword_17D230);
          if ( !a2 )
            goto LABEL_13;
        }
        else
        {
          qword_17D230 = a2 + 112;
          *(_QWORD *)(a2 + 112) = &hw_fence_list;
          *(_QWORD *)(a2 + 120) = v9;
          *v9 = v8;
          if ( !a2 )
            goto LABEL_13;
        }
        _X0 = (unsigned int *)(a2 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v20 = __ldxr(_X0);
        while ( __stxr(v20 + 1, _X0) );
        if ( !v20 )
        {
          v12 = 2;
          goto LABEL_26;
        }
        if ( (((v20 + 1) | v20) & 0x80000000) != 0 )
        {
          v12 = 1;
LABEL_26:
          refcount_warn_saturate(_X0, v12);
        }
LABEL_13:
        raw_spin_unlock(&hw_fence_list_lock);
        result = 0;
        goto LABEL_14;
      }
      v11 = 1;
    }
    else
    {
      v11 = 2;
    }
    refcount_warn_saturate(_X0, v11);
    goto LABEL_7;
  }
  v5 = v4;
  if ( (unsigned int)__ratelimit(&rs, "kgsl_hw_fence_create") )
    dev_err(*a1, "Failed to create ctx:%d ts:%d hardware fence:%d\n", *(_DWORD *)(a2 + 96), *(_DWORD *)(a2 + 100), v5);
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
