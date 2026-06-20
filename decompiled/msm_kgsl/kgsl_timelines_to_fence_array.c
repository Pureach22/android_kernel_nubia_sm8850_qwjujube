__int64 __fastcall kgsl_timelines_to_fence_array(__int64 a1, __int64 a2, int a3, unsigned __int64 a4, char a5)
{
  unsigned __int64 v9; // x19
  __int64 *v10; // x20
  __int64 v11; // x8
  size_t v12; // x25
  __int64 v13; // x21
  unsigned __int64 v14; // x28
  size_t v15; // x26
  __int64 v16; // x0
  unsigned __int64 v17; // x27
  unsigned __int64 v18; // x0
  int v25; // w8
  __int64 result; // x0
  unsigned int v27; // w23
  __int64 v28; // x21
  unsigned __int64 v29; // x22
  unsigned int v30; // w8
  __int64 v31; // x23
  unsigned __int64 v32; // x8
  int v35; // w8
  __int64 v36; // x19
  __int64 v37; // x0
  unsigned int v39; // [xsp+10h] [xbp-20h]
  __int64 v40; // [xsp+18h] [xbp-18h] BYREF
  __int64 v41; // [xsp+20h] [xbp-10h]
  __int64 v42; // [xsp+28h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 1 )
  {
    v9 = 8LL * (unsigned int)a3;
    v10 = (__int64 *)_kmalloc_noprof(v9, 77248);
    if ( !v10 )
    {
      result = -12;
      goto LABEL_56;
    }
    v11 = 16;
    if ( a4 >= 0x10 )
      v12 = 16;
    else
      v12 = a4;
    if ( a4 > 0x10 )
      v11 = a4;
    v13 = 8LL * (unsigned int)a3;
    v14 = 0;
    v39 = a3;
    v15 = v11 - v12;
    while ( 1 )
    {
      v40 = 0;
      v41 = 0;
      if ( a4 > 0xF )
      {
        if ( a4 >= 0x11 && (int)check_zeroed_user(a2 + v12, v15) < 1 )
        {
LABEL_32:
          v27 = v39;
          v28 = -14;
          goto LABEL_36;
        }
      }
      else
      {
        memset((char *)&v40 + v12, 0, v15);
      }
      _check_object_size(&v40, v12, 0);
      if ( inline_copy_from_user_2((int)&v40, a2, v12) )
        goto LABEL_32;
      if ( HIDWORD(v41) )
      {
        v27 = v39;
        v28 = -22;
        goto LABEL_36;
      }
      v16 = kgsl_timeline_by_id(a1, (unsigned int)v41);
      if ( !v16 )
      {
        v27 = v39;
        v28 = -2;
        goto LABEL_36;
      }
      v17 = v16;
      v18 = kgsl_timeline_fence_alloc(v16, v40);
      if ( v9 <= v14 )
        goto LABEL_30;
      v10[v14 / 8] = v18;
      if ( v17 <= 0xFFFFFFFFFFFFF000LL )
      {
        _X0 = (unsigned int *)(v17 + 32);
        __asm { PRFM            #0x11, [X0] }
        do
          v25 = __ldxr(_X0);
        while ( __stlxr(v25 - 1, _X0) );
        if ( v25 == 1 )
        {
          __dmb(9u);
          kgsl_timeline_destroy();
          if ( v9 <= v14 )
            goto LABEL_30;
        }
        else if ( v25 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
          if ( v9 <= v14 )
            goto LABEL_30;
        }
        else if ( v9 <= v14 )
        {
          goto LABEL_30;
        }
        v18 = v10[v14 / 8];
      }
      if ( v18 >= 0xFFFFFFFFFFFFF001LL )
        break;
      v14 += 8LL;
      a2 += a4;
      if ( v13 == v14 )
      {
        v27 = v39;
        if ( v39 == 1 )
        {
          v36 = *v10;
          kfree(v10);
          result = v36;
          goto LABEL_56;
        }
        v37 = dma_fence_context_alloc(1);
        result = dma_fence_array_create(v39, v10, v37, 0, a5 & 1);
        if ( result )
          goto LABEL_56;
        v28 = -12;
LABEL_36:
        v29 = 0;
        if ( v27 <= 1 )
          v30 = 1;
        else
          v30 = v27;
        v31 = 8LL * v30;
        while ( v9 > v29 )
        {
          v32 = v10[v29 / 8];
          if ( v32 && v32 <= 0xFFFFFFFFFFFFF000LL )
          {
            _X0 = (unsigned int *)(v32 + 56);
            __asm { PRFM            #0x11, [X0] }
            do
              v35 = __ldxr(_X0);
            while ( __stlxr(v35 - 1, _X0) );
            if ( v35 == 1 )
            {
              __dmb(9u);
              dma_fence_release(_X0);
            }
            else if ( v35 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
            }
          }
          v29 += 8LL;
          if ( v31 == v29 )
          {
            kfree(v10);
            result = v28;
            goto LABEL_56;
          }
        }
LABEL_30:
        __break(1u);
        goto LABEL_31;
      }
    }
    v27 = v39;
    v28 = (int)v18;
    goto LABEL_36;
  }
LABEL_31:
  result = -22;
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
