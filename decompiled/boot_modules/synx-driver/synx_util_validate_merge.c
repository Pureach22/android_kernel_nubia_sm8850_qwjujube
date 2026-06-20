__int64 __fastcall synx_util_validate_merge(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int64 *a4,
        unsigned int *a5,
        __int64 a6)
{
  __int64 v8; // x21
  unsigned __int64 v10; // x22
  unsigned __int64 v11; // x0
  __int64 v12; // x4
  __int64 v13; // x5
  unsigned __int64 v14; // x20
  unsigned __int64 v15; // x23
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x25
  __int64 v18; // x24
  unsigned int v19; // w28
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x21
  unsigned __int64 v24; // x1
  __int64 v25; // x25
  __int64 v26; // x8
  __int64 v28; // x1
  unsigned int v30; // w8
  unsigned int v36; // w8
  unsigned __int64 v37; // x19
  unsigned __int64 v38; // x24
  unsigned __int64 v40; // x21
  __int64 v41; // x8
  int v44; // w8
  int v46; // w8
  unsigned __int64 v47; // x25
  unsigned __int64 v48; // x0
  unsigned __int64 v49; // x26
  __int64 v50; // x19
  unsigned int v51; // w28
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x9
  unsigned __int64 v54; // x10
  unsigned int v55; // w9
  __int64 v56; // x12
  int v57; // w23
  unsigned int v58; // w19
  unsigned __int64 v59; // x21
  __int64 v60; // x8
  int v61; // w27
  int v64; // w8
  void *v65; // x0
  __int64 v66; // x3
  unsigned __int64 v69; // [xsp+20h] [xbp-10h]

  if ( a3 <= 1 )
  {
    if ( (synx_debug & 1) == 0 )
      return 4294967274LL;
LABEL_97:
    printk(&unk_28CEA, &unk_29207, "synx_util_validate_merge", 776, a5, a6);
    return 4294967274LL;
  }
  v8 = a2;
  v10 = 8LL * a3;
  v11 = _kmalloc_noprof(v10, 3520);
  v14 = v11;
  if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) == 0 )
      return 4294967284LL;
    v65 = &unk_286AE;
    v66 = 782;
LABEL_134:
    printk(v65, &unk_29207, "synx_util_validate_merge", v66, v12, v13);
    return 4294967284LL;
  }
  v15 = 8LL * a3;
  v16 = _kmalloc_noprof(v15, 3520);
  v17 = v16;
  if ( v16 && v16 <= 0xFFFFFFFFFFFFF000LL )
  {
    v18 = 0;
    v19 = 0;
    v69 = v16;
    while ( 1 )
    {
      v20 = synx_util_acquire_handle(a1, *(unsigned int *)(v8 + 4 * v18));
      if ( v10 <= 8 * v18 )
        goto LABEL_96;
      *(_QWORD *)(v14 + 8 * v18) = v20;
      if ( !v20 || v20 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( v15 <= 8 * v18 )
        {
LABEL_96:
          __break(1u);
          goto LABEL_97;
        }
        *(_QWORD *)(v17 + 8 * v18) = 0;
LABEL_41:
        if ( (synx_debug & 1) != 0 )
          printk(
            &unk_255A6,
            &unk_29207,
            "synx_util_validate_merge",
            800,
            *(_QWORD *)(a1 + 104),
            *(unsigned int *)(a2 + 4 * v18));
LABEL_43:
        *a5 = v18;
        if ( !(_DWORD)v18 )
        {
LABEL_74:
          *a5 = 0;
          kfree(v69);
          kfree(v14);
          return 4294967274LL;
        }
        v37 = 0;
        while ( 1 )
        {
          if ( v15 <= 8 * v37 )
            goto LABEL_96;
          v38 = *(_QWORD *)(*(_QWORD *)(v69 + 8 * v37) + 64LL);
          if ( *(_UNKNOWN **)(v38 + 8) == &dma_fence_array_ops )
          {
            if ( v38 && v38 <= 0xFFFFFFFFFFFFF000LL )
            {
              if ( *(_DWORD *)(v38 + 68) )
              {
                v40 = 0;
                do
                {
                  v41 = *(_QWORD *)(*(_QWORD *)(v38 + 80) + 8 * v40);
                  if ( v41 )
                  {
                    _X0 = (unsigned int *)(v41 + 56);
                    __asm { PRFM            #0x11, [X0] }
                    do
                      v44 = __ldxr(_X0);
                    while ( __stlxr(v44 - 1, _X0) );
                    if ( v44 == 1 )
                    {
                      __dmb(9u);
                      dma_fence_release(_X0);
                    }
                    else if ( v44 <= 0 )
                    {
                      refcount_warn_saturate(_X0, 3);
                    }
                  }
                  ++v40;
                }
                while ( v40 < *(unsigned int *)(v38 + 68) );
              }
LABEL_69:
              if ( v10 <= 8 * v37 )
                goto LABEL_96;
              goto LABEL_70;
            }
            if ( (synx_debug & 1) == 0 )
              goto LABEL_69;
            printk(&unk_29134, &unk_29207, "synx_util_put_references", 679, a5, a6);
            if ( v10 <= 8 * v37 )
              goto LABEL_96;
          }
          else
          {
            if ( !v38 )
              goto LABEL_69;
            _X0 = (unsigned int *)(v38 + 56);
            __asm { PRFM            #0x11, [X0] }
            do
              v46 = __ldxr(_X0);
            while ( __stlxr(v46 - 1, _X0) );
            if ( v46 == 1 )
            {
              __dmb(9u);
              dma_fence_release(_X0);
              if ( v10 <= 8 * v37 )
                goto LABEL_96;
            }
            else
            {
              if ( v46 > 0 )
                goto LABEL_69;
              refcount_warn_saturate(_X0, 3);
              if ( v10 <= 8 * v37 )
                goto LABEL_96;
            }
          }
LABEL_70:
          synx_util_release_handle(*(_QWORD *)(v14 + 8 * v37++));
          if ( v37 >= *a5 )
            goto LABEL_74;
        }
      }
      if ( v15 <= 8 * v18 )
        goto LABEL_96;
      v21 = *(_QWORD *)(v20 + 8);
      *(_QWORD *)(v17 + 8 * v18) = v21;
      if ( !v21 )
        goto LABEL_41;
      if ( v21 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_41;
      v22 = *(_QWORD *)(v21 + 64);
      if ( !v22 || v22 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_41;
      if ( *(_UNKNOWN **)(v22 + 8) == &dma_fence_array_ops )
        break;
      _X0 = (unsigned int *)(v22 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v36 = __ldxr(_X0);
      while ( __stxr(v36 + 1, _X0) );
      v8 = a2;
      if ( !v36 )
      {
        v24 = 2;
LABEL_38:
        refcount_warn_saturate(_X0, v24);
        LODWORD(v24) = 1;
        goto LABEL_10;
      }
      v24 = 1;
      if ( (((v36 + 1) | v36) & 0x80000000) != 0 )
        goto LABEL_38;
LABEL_10:
      ++v18;
      v19 += v24;
      if ( v18 == a3 )
      {
        v47 = 8LL * v19;
        v48 = _kmalloc_noprof(v47, 3520);
        v49 = v48;
        if ( v48 && v48 <= 0xFFFFFFFFFFFFF000LL )
        {
          v50 = 0;
          v51 = 0;
          *a4 = v48;
          while ( 1 )
          {
            if ( v15 <= 8 * v50 )
              goto LABEL_96;
            v52 = *(_QWORD *)(*(_QWORD *)(v69 + 8 * v50) + 64LL);
            if ( *(_UNKNOWN **)(v52 + 8) != &dma_fence_array_ops )
            {
              if ( v47 <= 8 * (unsigned __int64)v51 )
                goto LABEL_96;
              LODWORD(v53) = 1;
              *(_QWORD *)(v49 + 8LL * v51) = v52;
              if ( v10 <= 8 * v50 )
                goto LABEL_96;
              goto LABEL_93;
            }
            if ( v52 && v52 <= 0xFFFFFFFFFFFFF000LL )
            {
              LODWORD(v53) = *(_DWORD *)(v52 + 68);
              if ( (_DWORD)v53 )
              {
                v54 = 0;
                do
                {
                  v55 = v51 + v54;
                  if ( v47 <= 8 * (unsigned __int64)(v51 + (unsigned int)v54) )
                    goto LABEL_96;
                  v56 = *(_QWORD *)(*(_QWORD *)(v52 + 80) + 8 * v54++);
                  *(_QWORD *)(v49 + 8LL * v55) = v56;
                  v53 = *(unsigned int *)(v52 + 68);
                }
                while ( v54 < v53 );
              }
            }
            else
            {
              if ( (synx_debug & 1) != 0 )
              {
                printk(&unk_29134, &unk_29207, "synx_util_add_fence", 700, a5, a6);
                LODWORD(v53) = 0;
                if ( v10 <= 8 * v50 )
                  goto LABEL_96;
                goto LABEL_93;
              }
              LODWORD(v53) = 0;
            }
            if ( v10 <= 8 * v50 )
              goto LABEL_96;
LABEL_93:
            v51 += v53;
            synx_util_release_handle(*(_QWORD *)(v14 + 8 * v50++));
            if ( v50 == a3 )
            {
              if ( v51 < 2 )
              {
                v58 = 1;
              }
              else
              {
                v57 = 1;
                v58 = 1;
                do
                {
                  if ( v58 )
                  {
                    v59 = 8LL * v57;
                    if ( v47 <= v59 )
                      goto LABEL_96;
                    v60 = *(_QWORD *)(v49 + 8LL * v57);
                    v61 = 0;
                    while ( 1 )
                    {
                      if ( v47 <= 8LL * v61 )
                        goto LABEL_96;
                      if ( v60 == *(_QWORD *)(v49 + 8LL * v61) )
                        break;
                      if ( v58 == ++v61 )
                        goto LABEL_123;
                    }
                    if ( (synx_debug & 8) != 0 )
                    {
                      printk(&unk_26DD0, &unk_2A972, "synx_util_remove_duplicates", 729, a5, a6);
                      if ( v47 <= v59 )
                        goto LABEL_96;
                      v60 = *(_QWORD *)(v49 + 8LL * v57);
                      if ( !v60 )
                        goto LABEL_120;
                    }
                    else if ( !v60 )
                    {
                      goto LABEL_120;
                    }
                    _X0 = (unsigned int *)(v60 + 56);
                    __asm { PRFM            #0x11, [X0] }
                    do
                      v64 = __ldxr(_X0);
                    while ( __stlxr(v64 - 1, _X0) );
                    if ( v64 == 1 )
                    {
                      __dmb(9u);
                      dma_fence_release(_X0);
                      if ( v61 != v58 )
                        goto LABEL_100;
                      goto LABEL_121;
                    }
                    if ( v64 > 0 )
                    {
LABEL_120:
                      if ( v61 != v58 )
                        goto LABEL_100;
                      goto LABEL_121;
                    }
                    refcount_warn_saturate(_X0, 3);
                    if ( v61 != v58 )
                      goto LABEL_100;
                  }
LABEL_121:
                  if ( v47 <= 8LL * v57 )
                    goto LABEL_96;
                  v60 = *(_QWORD *)(v49 + 8LL * v57);
LABEL_123:
                  if ( v47 <= 8 * (unsigned __int64)v58 )
                    goto LABEL_96;
                  *(_QWORD *)(v49 + 8LL * v58++) = v60;
LABEL_100:
                  ++v57;
                }
                while ( v57 != v51 );
              }
              *a5 = v58;
              kfree(v69);
              kfree(v14);
              return 0;
            }
          }
        }
        LODWORD(v18) = a3;
        goto LABEL_43;
      }
    }
    if ( !*(_DWORD *)(v22 + 68) )
    {
      v8 = a2;
      LODWORD(v24) = 0;
      goto LABEL_10;
    }
    v25 = 0;
    while ( 1 )
    {
      v26 = *(_QWORD *)(*(_QWORD *)(v22 + 80) + 8 * v25);
      if ( v26 )
      {
        _X0 = (unsigned int *)(v26 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v30 = __ldxr(_X0);
        while ( __stxr(v30 + 1, _X0) );
        if ( v30 )
        {
          if ( (((v30 + 1) | v30) & 0x80000000) == 0 )
            goto LABEL_27;
          v28 = 1;
        }
        else
        {
          v28 = 2;
        }
        refcount_warn_saturate(_X0, v28);
      }
LABEL_27:
      v24 = *(unsigned int *)(v22 + 68);
      if ( ++v25 >= v24 )
      {
        v17 = v69;
        v8 = a2;
        goto LABEL_10;
      }
    }
  }
  kfree(v14);
  if ( (synx_debug & 1) != 0 )
  {
    v65 = &unk_26B4C;
    v66 = 789;
    goto LABEL_134;
  }
  return 4294967284LL;
}
