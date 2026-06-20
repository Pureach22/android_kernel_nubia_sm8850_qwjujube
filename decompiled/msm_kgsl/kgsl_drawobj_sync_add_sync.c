unsigned __int64 __fastcall kgsl_drawobj_sync_add_sync(_QWORD *a1, __int64 a2, int *a3)
{
  int v5; // w8
  unsigned __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x9
  size_t v9; // x22
  unsigned __int64 v10; // x8
  __int64 v11; // x20
  __int64 v12; // x9
  size_t v13; // x22
  unsigned __int64 result; // x0
  unsigned int v16; // w8
  unsigned int *v17; // x22
  __int64 v18; // x21
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x20
  unsigned __int64 v23; // x22
  unsigned __int64 v24; // x8
  __int64 v25; // x20
  __int64 v26; // x9
  size_t v27; // x22
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x9
  __int64 v30; // x8
  unsigned __int64 v31; // x20
  unsigned int v34; // w8
  unsigned int *v35; // x27
  unsigned __int64 v36; // x21
  int v37; // w28
  __int64 v38; // x24
  unsigned __int64 v39; // x20
  unsigned __int64 v40; // x23
  __int64 v41; // x22
  __int64 v42; // x8
  size_t v43; // x25
  __int64 v44; // x8
  __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x9
  __int64 v48; // x8
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x9
  __int64 v52; // x8
  __int64 v53; // x21
  __int64 (__fastcall *v54)(_QWORD); // x8
  unsigned __int64 v55; // x20
  __int64 v56; // x0
  char v57; // w8
  __int64 v58; // x8
  __int64 v60; // x8
  __int64 v61; // x19
  __int64 *v62; // x22
  int v63; // w21
  int v64; // w23
  __int64 (*v65)(void); // x8
  const char *v66; // x0
  __int64 v68; // x1
  unsigned __int64 v69; // x20
  __int64 v70; // x1
  __int64 v71; // x1
  unsigned __int64 v78; // x9
  unsigned int v80; // w8
  unsigned __int64 v83; // x10
  unsigned __int64 v86; // x10
  int v88; // w8
  unsigned __int64 v89; // x21
  unsigned int v91; // w8
  unsigned __int64 v94; // x10
  __int64 v95; // x8
  int v97; // w8
  void (__fastcall *v98)(_QWORD); // x8
  unsigned int v100; // w8
  unsigned __int64 v103; // x10
  int v105; // w8
  __int64 v106; // x8
  unsigned __int64 v108; // x20
  int v110; // w9
  unsigned __int64 v111; // x20
  int v114; // w8
  unsigned __int64 v115; // x19
  int v117; // w8
  int v119; // w8
  void (__fastcall *v120)(_QWORD); // x8
  __int64 v121; // [xsp+10h] [xbp-70h] BYREF
  __int64 v122; // [xsp+18h] [xbp-68h]
  __int64 v123; // [xsp+20h] [xbp-60h] BYREF
  char s[8]; // [xsp+28h] [xbp-58h] BYREF
  __int64 v125; // [xsp+30h] [xbp-50h]
  __int64 v126; // [xsp+38h] [xbp-48h]
  __int64 v127; // [xsp+40h] [xbp-40h]
  __int64 v128; // [xsp+48h] [xbp-38h]
  __int64 v129; // [xsp+50h] [xbp-30h]
  __int64 v130; // [xsp+58h] [xbp-28h]
  __int64 v131; // [xsp+60h] [xbp-20h]
  __int64 v132; // [xsp+68h] [xbp-18h]
  __int16 v133; // [xsp+70h] [xbp-10h]
  __int64 v134; // [xsp+78h] [xbp-8h]

  v134 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a3 == 1 )
    goto LABEL_13;
  _X8 = (unsigned __int64 *)(a2 + 128);
  __asm { PRFM            #0x11, [X8] }
  do
    v78 = __ldxr(_X8);
  while ( __stxr(v78 | 1, _X8) );
  v5 = *a3;
  if ( *a3 == 2 )
  {
    v25 = *((_QWORD *)a3 + 1);
    v24 = *((_QWORD *)a3 + 2);
    v26 = 16;
    v121 = 0;
    v122 = 0;
    if ( v24 >= 0x10 )
      v27 = 16;
    else
      v27 = v24;
    if ( v24 > 0x10 )
      v26 = v24;
    if ( v24 > 0xF )
    {
      if ( v24 != 16 && (int)check_zeroed_user(v25 + v27, v26 - v27) < 1 )
        goto LABEL_23;
    }
    else
    {
      memset((char *)&v121 + v27, 0, v26 - v27);
    }
    _check_object_size(&v121, v27, 0);
    if ( inline_copy_from_user_1((int)&v121, v25, v27) )
      goto LABEL_23;
    result = kgsl_timelines_to_fence_array(a1, v121, (unsigned int)v122, HIDWORD(v122), 0);
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_143;
    _X26 = (unsigned int *)(a2 + 32);
    __asm { PRFM            #0x11, [X26] }
    do
      v91 = __ldxr(_X26);
    while ( __stxr(v91 + 1, _X26) );
    if ( v91 )
    {
      if ( (((v91 + 1) | v91) & 0x80000000) == 0 )
        goto LABEL_56;
      v69 = result;
      v70 = 1;
    }
    else
    {
      v69 = result;
      v70 = 2;
    }
    refcount_warn_saturate(a2 + 32, v70);
    result = v69;
LABEL_56:
    v34 = *(_DWORD *)(a2 + 64);
    v35 = (unsigned int *)(*(_QWORD *)(a2 + 56) + 120LL * v34);
    *(_DWORD *)(a2 + 64) = v34 + 1;
    *v35 = v34;
    v35[1] = 2;
    *((_QWORD *)v35 + 11) = 0xFFFFFFFE00000LL;
    *((_QWORD *)v35 + 5) = a1;
    v36 = (unsigned __int64)(v35 + 16);
    *((_QWORD *)v35 + 1) = a2;
    *((_QWORD *)v35 + 2) = 0;
    *((_QWORD *)v35 + 7) = result;
    *((_QWORD *)v35 + 12) = v35 + 24;
    *((_QWORD *)v35 + 13) = v35 + 24;
    *((_QWORD *)v35 + 14) = drawobj_sync_timeline_fence_work;
    *((_QWORD *)v35 + 8) = v35 + 16;
    *((_QWORD *)v35 + 9) = v35 + 16;
    v37 = v122;
    if ( (_DWORD)v122 != -1 )
    {
      v38 = v121;
      v39 = HIDWORD(v122);
      v40 = 16LL * (unsigned int)v122 + 16;
      v41 = _kmalloc_noprof(v40, 3520);
      if ( !v41 )
      {
LABEL_81:
        v46 = *v35;
        *((_QWORD *)v35 + 6) = v41;
        v47 = v46 >> 6;
        v48 = 1LL << v46;
        _X9 = (unsigned __int64 *)(a2 + 72 + 8 * v47);
        __asm { PRFM            #0x11, [X9] }
        do
          v94 = __ldxr(_X9);
        while ( __stxr(v94 | v48, _X9) );
        v95 = *((_QWORD *)v35 + 7);
        if ( v95 )
        {
          _X0 = (unsigned int *)(v95 + 56);
          __asm { PRFM            #0x11, [X0] }
          do
            v100 = __ldxr(_X0);
          while ( __stxr(v100 + 1, _X0) );
          if ( v100 )
          {
            if ( (((v100 + 1) | v100) & 0x80000000) == 0 )
              goto LABEL_84;
            v71 = 1;
          }
          else
          {
            v71 = 2;
          }
          refcount_warn_saturate(_X0, v71);
        }
LABEL_84:
        result = dma_fence_add_callback(*((_QWORD *)v35 + 7), v36, drawobj_sync_timeline_fence_callback);
        if ( (_DWORD)result )
        {
          v50 = *v35;
          v51 = v50 >> 6;
          v52 = 1LL << v50;
          _X9 = (unsigned __int64 *)(a2 + 72 + 8 * v51);
          __asm { PRFM            #0x11, [X9] }
          do
            v103 = __ldxr(_X9);
          while ( __stxr(v103 & ~v52, _X9) );
          v53 = *((_QWORD *)v35 + 7);
          if ( (*(_QWORD *)(v53 + 48) & 1) == 0 )
          {
            v54 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v53 + 8) + 32LL);
            if ( !v54 )
              goto LABEL_155;
            v55 = result;
            v56 = *((_QWORD *)v35 + 7);
            if ( *((_DWORD *)v54 - 1) != 1879296680 )
              __break(0x8228u);
            v57 = v54(v56);
            result = v55;
            if ( (v57 & 1) == 0 )
              goto LABEL_155;
            dma_fence_signal(v53);
          }
          log_kgsl_syncpoint_fence_expire_event(*(unsigned int *)(*(_QWORD *)(a2 + 8) + 4LL), "signaled");
          v58 = *((_QWORD *)v35 + 7);
          if ( !v58 )
          {
            result = 0;
            goto LABEL_162;
          }
          _X0 = (unsigned int *)(v58 + 56);
          __asm { PRFM            #0x11, [X0] }
          do
            v105 = __ldxr(_X0);
          while ( __stlxr(v105 - 1, _X0) );
          if ( v105 == 1 )
          {
            __dmb(9u);
            ((void (*)(void))dma_fence_release)();
          }
          else if ( v105 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
          result = 0;
LABEL_155:
          v106 = *((_QWORD *)v35 + 7);
          if ( !v106 )
            goto LABEL_162;
          _X8 = (unsigned int *)(v106 + 56);
          __asm { PRFM            #0x11, [X8] }
          do
            v110 = __ldxr(_X8);
          while ( __stlxr(v110 - 1, _X8) );
          if ( v110 == 1 )
          {
            __dmb(9u);
            v108 = result;
            dma_fence_release(_X8);
          }
          else
          {
            if ( v110 > 0 )
            {
LABEL_162:
              if ( a2 )
              {
                __asm { PRFM            #0x11, [X26] }
                do
                  v114 = __ldxr(_X26);
                while ( __stlxr(v114 - 1, _X26) );
                if ( v114 == 1 )
                {
                  __dmb(9u);
                  v111 = result;
                  _X0 = *(unsigned int **)(a2 + 8);
                  if ( _X0 )
                  {
                    __asm { PRFM            #0x11, [X0] }
                    do
                      v119 = __ldxr(_X0);
                    while ( __stlxr(v119 - 1, _X0) );
                    if ( v119 == 1 )
                    {
                      __dmb(9u);
                      kgsl_context_destroy((__int64)_X0);
                    }
                    else if ( v119 <= 0 )
                    {
                      refcount_warn_saturate(_X0, 3);
                    }
                  }
                  v120 = *(void (__fastcall **)(_QWORD))(a2 + 48);
                  if ( *((_DWORD *)v120 - 1) != 287870130 )
                    __break(0x8228u);
                  v120(a2);
                  result = v111;
                }
                else if ( v114 <= 0 )
                {
                  v115 = result;
                  refcount_warn_saturate(_X26, 3);
                  result = v115;
                }
              }
              goto LABEL_143;
            }
            v108 = result;
            refcount_warn_saturate(_X8, 3);
          }
          result = v108;
          goto LABEL_162;
        }
        v60 = *((_QWORD *)v35 + 7);
        v61 = *((_QWORD *)v35 + 1);
        v123 = v60;
        if ( v60 && *(_UNKNOWN **)(v60 + 8) == &dma_fence_array_ops )
        {
          v63 = *(_DWORD *)(v60 + 68);
          if ( !v63 )
          {
LABEL_103:
            _X0 = (unsigned int *)(v60 + 56);
            __asm { PRFM            #0x11, [X0] }
            do
              v117 = __ldxr(_X0);
            while ( __stlxr(v117 - 1, _X0) );
            if ( v117 == 1 )
            {
              __dmb(9u);
              ((void (*)(void))dma_fence_release)();
            }
            else if ( v117 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
            }
            goto LABEL_142;
          }
          v62 = *(__int64 **)(v60 + 80);
        }
        else
        {
          v62 = &v123;
          v63 = 1;
        }
        v64 = 0;
        _ReadStatusReg(SP_EL0);
        do
        {
          v133 = 0;
          v131 = 0;
          v132 = 0;
          v129 = 0;
          v130 = 0;
          v127 = 0;
          v128 = 0;
          v125 = 0;
          v126 = 0;
          *(_QWORD *)s = 0;
          v65 = *(__int64 (**)(void))(*(_QWORD *)(v62[v64] + 8) + 16LL);
          if ( *((_DWORD *)v65 - 1) != -352706110 )
            __break(0x8228u);
          v66 = (const char *)v65();
          snprintf(s, 0x4Au, "%s:%llu", v66, *(_QWORD *)(v62[v64] + 40));
          ((void (__fastcall *)(_QWORD, char *))log_kgsl_syncpoint_fence_event)(
            *(unsigned int *)(*(_QWORD *)(v61 + 8) + 4LL),
            s);
          ++v64;
        }
        while ( v63 != v64 );
        v60 = *((_QWORD *)v35 + 7);
        if ( !v60 )
          goto LABEL_142;
        goto LABEL_103;
      }
      if ( v37 )
      {
        v42 = 16;
        if ( v39 >= 0x10 )
          v43 = 16;
        else
          v43 = v39;
        if ( v39 > 0x10 )
          v42 = v39;
        v36 = 0;
        _X26 = (unsigned int *)(v42 - v43);
        while ( 1 )
        {
          *(_QWORD *)s = 0;
          v125 = 0;
          if ( (unsigned int)v39 <= 0xF )
            break;
          if ( (unsigned int)v39 < 0x11 || (int)check_zeroed_user(v38 + v43, _X26) >= 1 )
            goto LABEL_71;
LABEL_66:
          v36 = (unsigned int)(v36 + 1);
          v38 += v39;
          if ( v37 == (_DWORD)v36 )
          {
            v36 = (unsigned __int64)(v35 + 16);
            _X26 = (unsigned int *)(a2 + 32);
            v45 = v37;
            goto LABEL_79;
          }
        }
        memset(&s[v43], 0, (size_t)_X26);
LABEL_71:
        _check_object_size(s, v43, 0);
        if ( !inline_copy_from_user_1((int)s, v38, v43) )
        {
          if ( v40 < ((16LL * (int)v36) | 8uLL) )
            goto LABEL_74;
          v44 = v41 + 16LL * (int)v36;
          *(_DWORD *)(v44 + 8) = v125;
          if ( v40 <= 16LL * (int)v36 )
            goto LABEL_74;
          *(_QWORD *)v44 = *(_QWORD *)s;
        }
        goto LABEL_66;
      }
      v45 = 0;
LABEL_79:
      if ( v40 >= ((16 * v45) | 8uLL) )
      {
        *(_DWORD *)(v41 + 16 * v45 + 8) = 0;
        goto LABEL_81;
      }
LABEL_74:
      __break(1u);
    }
    v41 = 0;
    goto LABEL_81;
  }
  if ( v5 != 1 )
  {
    if ( v5 )
    {
      dev_err(*a1, "bad syncpoint type %d for ctxt %u\n", v5, *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL));
      result = 4294967274LL;
      goto LABEL_143;
    }
    v7 = *((_QWORD *)a3 + 1);
    v6 = *((_QWORD *)a3 + 2);
    v8 = 8;
    *(_QWORD *)s = 0;
    if ( v6 >= 8 )
      v9 = 8;
    else
      v9 = v6;
    if ( v6 > 8 )
      v8 = v6;
    if ( v6 <= 7 )
    {
      memset(&s[v9], 0, v8 - v9);
      goto LABEL_48;
    }
    if ( v6 == 8 || (int)check_zeroed_user(v7 + v9, v8 - v9) >= 1 )
    {
LABEL_48:
      _check_object_size(s, v9, 0);
      if ( !inline_copy_from_user_1((int)s, v7, v9) )
      {
        result = drawobj_add_sync_timestamp(a1, a2, s);
        goto LABEL_143;
      }
      goto LABEL_23;
    }
    goto LABEL_23;
  }
LABEL_13:
  v11 = *((_QWORD *)a3 + 1);
  v10 = *((_QWORD *)a3 + 2);
  v12 = 4;
  *(_DWORD *)s = 0;
  if ( v10 >= 4 )
    v13 = 4;
  else
    v13 = v10;
  if ( v10 > 4 )
    v12 = v10;
  if ( v10 > 3 )
  {
    if ( v10 != 4 && (int)check_zeroed_user(v11 + v13, v12 - v13) < 1 )
      goto LABEL_23;
  }
  else
  {
    memset(&s[v13], 0, v12 - v13);
  }
  _check_object_size(s, v13, 0);
  if ( inline_copy_from_user_1((int)s, v11, v13) )
  {
LABEL_23:
    result = 4294967282LL;
    goto LABEL_143;
  }
  _X20 = (unsigned int *)(a2 + 32);
  __asm { PRFM            #0x11, [X20] }
  do
    v80 = __ldxr(_X20);
  while ( __stxr(v80 + 1, _X20) );
  if ( v80 )
  {
    if ( (((v80 + 1) | v80) & 0x80000000) == 0 )
      goto LABEL_26;
    v68 = 1;
  }
  else
  {
    v68 = 2;
  }
  refcount_warn_saturate(a2 + 32, v68);
LABEL_26:
  v16 = *(_DWORD *)(a2 + 64);
  v17 = (unsigned int *)(*(_QWORD *)(a2 + 56) + 120LL * v16);
  *(_DWORD *)(a2 + 64) = v16 + 1;
  *v17 = v16;
  v17[1] = 1;
  *((_QWORD *)v17 + 5) = a1;
  *((_QWORD *)v17 + 1) = a2;
  *((_QWORD *)v17 + 2) = 0;
  v18 = _kmalloc_cache_noprof(raw_read_lock, 3520, 16);
  v19 = *v17;
  v20 = v19 >> 6;
  v21 = 1LL << v19;
  _X9 = (unsigned __int64 *)(a2 + 72 + 8 * v20);
  __asm { PRFM            #0x11, [X9] }
  do
    v83 = __ldxr(_X9);
  while ( __stxr(v83 | v21, _X9) );
  result = kgsl_sync_fence_async_wait(*(unsigned int *)s, drawobj_sync_fence_func, v17);
  *((_QWORD *)v17 + 6) = v18;
  *((_QWORD *)v17 + 4) = result;
  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    kgsl_get_fence_info(v17);
    if ( v18 && *(_DWORD *)(v18 + 8) )
    {
      v22 = 0;
      v23 = 0;
      _ReadStatusReg(SP_EL0);
      do
      {
        ((void (__fastcall *)(_QWORD, __int64))log_kgsl_syncpoint_fence_event)(
          *(unsigned int *)(*(_QWORD *)(a2 + 8) + 4LL),
          *(_QWORD *)v18 + v22);
        ++v23;
        v22 += 74;
      }
      while ( v23 < *(unsigned int *)(v18 + 8) );
    }
    goto LABEL_142;
  }
  v28 = *v17;
  v29 = v28 >> 6;
  v30 = 1LL << v28;
  _X9 = (unsigned __int64 *)(a2 + 72 + 8 * v29);
  __asm { PRFM            #0x11, [X9] }
  do
    v86 = __ldxr(_X9);
  while ( __stxr(v86 & ~v30, _X9) );
  *((_QWORD *)v17 + 4) = 0;
  if ( a2 )
  {
    __asm { PRFM            #0x11, [X20] }
    do
      v88 = __ldxr(_X20);
    while ( __stlxr(v88 - 1, _X20) );
    if ( v88 == 1 )
    {
      __dmb(9u);
      v31 = result;
      _X0 = *(unsigned int **)(a2 + 8);
      if ( _X0 )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v97 = __ldxr(_X0);
        while ( __stlxr(v97 - 1, _X0) );
        if ( v97 == 1 )
        {
          __dmb(9u);
          kgsl_context_destroy((__int64)_X0);
        }
        else if ( v97 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      v98 = *(void (__fastcall **)(_QWORD))(a2 + 48);
      if ( *((_DWORD *)v98 - 1) != 287870130 )
        __break(0x8228u);
      v98(a2);
      result = v31;
    }
    else if ( v88 <= 0 )
    {
      v89 = result;
      refcount_warn_saturate(a2 + 32, 3);
      result = v89;
    }
  }
  if ( !(_DWORD)result )
  {
    log_kgsl_syncpoint_fence_expire_event(*(unsigned int *)(*(_QWORD *)(a2 + 8) + 4LL), "signaled");
LABEL_142:
    result = 0;
  }
LABEL_143:
  _ReadStatusReg(SP_EL0);
  return result;
}
