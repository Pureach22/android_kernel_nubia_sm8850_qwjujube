__int64 __fastcall kgsl_reclaim_to_pinned_state(__int64 a1)
{
  unsigned __int64 folio_gfp; // x0
  __int64 next; // x0
  unsigned int v5; // w8
  unsigned int v6; // w22
  unsigned int v12; // w9
  unsigned int v13; // w8
  int v14; // w9
  unsigned int v17; // w9
  __int64 v18; // x23
  __int64 v19; // x24
  unsigned int v20; // w0
  unsigned __int64 v21; // x22
  __int64 v22; // x8
  __int64 v23; // x8
  unsigned __int64 v24; // x0
  unsigned int v27; // w24
  unsigned int v28; // w24
  int v29; // w22
  int v31; // w8
  unsigned int v34; // w9
  unsigned int v35; // w20
  unsigned __int64 v39; // x9
  int v40; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+18h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  mutex_lock(a1 + 440);
  LODWORD(folio_gfp) = 0;
  if ( (*(_QWORD *)(a1 + 392) & 1) == 0 )
  {
    raw_spin_lock(a1 + 32);
    next = idr_get_next(a1 + 40, &v40);
    if ( next )
    {
      _X21 = next;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( _X21 > 0xFFFFFFFFFFFFF000LL || (*(_DWORD *)(_X21 + 56) & 0x800) == 0 )
        {
LABEL_4:
          raw_spin_unlock(a1 + 32);
          goto LABEL_5;
        }
        v5 = *(_DWORD *)_X21;
        if ( *(_DWORD *)_X21 )
        {
          do
          {
            __asm { PRFM            #0x11, [X21] }
            do
              v12 = __ldxr((unsigned int *)_X21);
            while ( v12 == v5 && __stxr(v5 + 1, (unsigned int *)_X21) );
            v6 = v5;
            if ( v12 == v5 )
              break;
            v6 = 0;
            v5 = v12;
          }
          while ( v12 );
        }
        else
        {
          v6 = 0;
        }
        if ( (((v6 + 1) | v6) & 0x80000000) != 0 )
        {
          refcount_warn_saturate(_X21, 0);
          if ( !v6 )
            goto LABEL_4;
        }
        else if ( !v6 )
        {
          goto LABEL_4;
        }
        raw_spin_unlock(a1 + 32);
        v13 = *(_DWORD *)(_X21 + 112);
        if ( v13 )
        {
          v14 = 0;
          do
          {
            v18 = v14;
            if ( !*(_QWORD *)(*(_QWORD *)(_X21 + 104) + 8LL * v14) )
            {
              v19 = *(_QWORD *)(*(_QWORD *)(_X21 + 120) + 24LL);
              v20 = kgsl_gfp_mask(0);
              folio_gfp = shmem_read_folio_gfp(v19, v18, v20);
              if ( folio_gfp >= 0xFFFFFFFFFFFFF001LL )
                goto LABEL_42;
              v21 = folio_gfp;
              ((void (__fastcall *)(_QWORD, unsigned __int64, __int64, _QWORD))kgsl_page_sync)(
                *(_QWORD *)(_X21 + 88),
                folio_gfp,
                4096,
                0);
              raw_spin_lock(_X21 + 116);
              v22 = *(_QWORD *)(_X21 + 104);
              if ( *(_QWORD *)(v22 + 8 * v18) )
              {
                v23 = *(_QWORD *)(v21 + 8);
                v24 = v21;
                if ( (v23 & 1) != 0 )
                  v24 = v23 - 1;
                _X8 = (unsigned int *)(v24 + 52);
                __asm { PRFM            #0x11, [X8] }
                do
                {
                  v27 = __ldxr(_X8);
                  v28 = v27 - 1;
                }
                while ( __stlxr(v28, _X8) );
                __dmb(0xBu);
                if ( !v28 )
                  _folio_put(v24);
              }
              else
              {
                *(_QWORD *)(v22 + 8 * v18) = v21;
                _X8 = (unsigned int *)(*(_QWORD *)(_X21 + 256) + 400LL);
                __asm { PRFM            #0x11, [X8] }
                do
                  v17 = __ldxr(_X8);
                while ( __stxr(v17 - 1, _X8) );
              }
              raw_spin_unlock(_X21 + 116);
              v13 = *(_DWORD *)(_X21 + 112);
            }
            v14 = v18 + 1;
          }
          while ( (int)v18 + 1 < v13 );
        }
        LODWORD(folio_gfp) = kgsl_mmu_map(*(_QWORD *)(_X21 + 8), _X21 + 8);
        if ( !(_DWORD)folio_gfp )
        {
          _X8 = (unsigned int *)(_X21 + 56);
          __asm { PRFM            #0x11, [X8] }
          do
            v34 = __ldxr(_X8);
          while ( __stxr(v34 & 0xFFFFE7FF, _X8) );
          LODWORD(folio_gfp) = 0;
        }
LABEL_42:
        __asm { PRFM            #0x11, [X21] }
        do
          v31 = __ldxr((unsigned int *)_X21);
        while ( __stlxr(v31 - 1, (unsigned int *)_X21) );
        if ( v31 == 1 )
          break;
        if ( v31 <= 0 )
        {
          v29 = folio_gfp;
          refcount_warn_saturate(_X21, 3);
          goto LABEL_41;
        }
LABEL_46:
        if ( (_DWORD)folio_gfp )
          goto LABEL_52;
LABEL_5:
        ++v40;
        raw_spin_lock(a1 + 32);
        _X21 = idr_get_next(a1 + 40, &v40);
        if ( !_X21 )
          goto LABEL_51;
      }
      __dmb(9u);
      v29 = folio_gfp;
      kgsl_mem_entry_destroy((_QWORD *)_X21);
LABEL_41:
      LODWORD(folio_gfp) = v29;
      goto LABEL_46;
    }
LABEL_51:
    raw_spin_unlock(a1 + 32);
    _X8 = (unsigned __int64 *)(a1 + 392);
    __asm { PRFM            #0x11, [X8] }
    do
      v39 = __ldxr(_X8);
    while ( __stxr(v39 | 1, _X8) );
    LODWORD(folio_gfp) = 0;
  }
LABEL_52:
  v35 = folio_gfp;
  mutex_unlock(a1 + 440);
  _ReadStatusReg(SP_EL0);
  return v35;
}
