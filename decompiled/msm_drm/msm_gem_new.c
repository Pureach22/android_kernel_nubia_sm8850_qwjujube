__int64 __fastcall msm_gem_new(__int64 a1, int a2, unsigned int a3)
{
  __int64 v6; // x25
  _BOOL4 v7; // w23
  __int64 v8; // x21
  int v9; // w0
  _QWORD *v11; // x22
  __int64 result; // x0
  __int64 v13; // x0
  _QWORD *v14; // x0
  __int64 v15; // x2
  _QWORD *v16; // x1
  __int64 v17; // x23
  unsigned __int64 pages; // x0
  _QWORD *v19; // x0
  __int64 v20; // x2
  _QWORD *v21; // x1
  int v27; // w8
  _QWORD v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 56);
  v28[0] = 0;
  if ( (mdss_iommu_present() & 1) != 0 )
  {
    v7 = (a3 & 0x10000001) != 0 && *(_QWORD *)(v6 + 5232) != 0;
  }
  else
  {
    if ( !*(_QWORD *)(v6 + 5232) )
    {
      __break(0x800u);
      result = -22;
      goto LABEL_40;
    }
    v7 = 1;
  }
  v8 = (a2 + 4095) & 0xFFFFF000;
  if ( !(_DWORD)v8 )
  {
    result = -22;
    goto LABEL_40;
  }
  v9 = msm_gem_new_impl(a1, a3, 0, v28);
  _X19 = v28[0];
  if ( v9 )
    goto LABEL_9;
  if ( v7 )
  {
    mutex_lock(v28[0] + 544LL);
    if ( (mutex_is_locked(_X19 + 544) & 1) == 0 )
      __break(0x800u);
    v13 = _kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 208);
    v11 = (_QWORD *)v13;
    if ( !v13 )
    {
      mutex_unlock(_X19 + 544);
      LODWORD(v11) = -12;
      goto LABEL_10;
    }
    *(_QWORD *)(v13 + 176) = 0;
    v14 = (_QWORD *)(v13 + 184);
    v15 = _X19 + 440;
    v16 = *(_QWORD **)(_X19 + 448);
    *(_QWORD *)(_X19 + 608) = 0;
    if ( v11 + 23 == (_QWORD *)(_X19 + 440) || v16 == v14 || *v16 != v15 )
    {
      _list_add_valid_or_report(v14, v16);
      v17 = v28[0];
    }
    else
    {
      v17 = _X19;
      *(_QWORD *)(_X19 + 448) = v14;
      v11[23] = v15;
      v11[24] = v16;
      *v16 = v14;
    }
    mutex_unlock(_X19 + 544);
    if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
    {
      _X19 = v17;
      goto LABEL_10;
    }
    *(_QWORD *)(v17 + 536) = v11;
    drm_gem_private_object_init(a1, v17, v8);
    pages = get_pages(v17);
    if ( pages >= 0xFFFFFFFFFFFFF001LL )
    {
      LODWORD(v11) = pages;
      _X19 = v17;
      goto LABEL_10;
    }
    v11[21] = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v17 + 8) + 56LL) + 5240LL)
            + (*(_QWORD *)(*(_QWORD *)(v17 + 536) + 8LL) << 12);
LABEL_29:
    mutex_lock(v6 + 640);
    v19 = (_QWORD *)(_X19 + 376);
    v20 = v6 + 624;
    v21 = *(_QWORD **)(v6 + 632);
    if ( _X19 + 376 == v6 + 624 || v21 == v19 || *v21 != v20 )
    {
      _list_add_valid_or_report(v19, v21);
    }
    else
    {
      *(_QWORD *)(v6 + 632) = v19;
      *(_QWORD *)(_X19 + 376) = v20;
      *(_QWORD *)(_X19 + 384) = v21;
      *v21 = v19;
    }
    mutex_unlock(v6 + 640);
    result = v17;
    goto LABEL_40;
  }
  v9 = drm_gem_object_init(a1, v28[0], v8);
  if ( !v9 )
  {
    v17 = _X19;
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(_X19 + 16) + 24LL) + 88LL) = 1051842;
    goto LABEL_29;
  }
LABEL_9:
  LODWORD(v11) = v9;
LABEL_10:
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v27 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v27 - 1, (unsigned int *)_X19) );
    if ( v27 == 1 )
    {
      __dmb(9u);
      drm_gem_object_free(_X19);
    }
    else if ( v27 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
  }
  result = (int)v11;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
