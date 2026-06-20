__int64 __fastcall msm_smmu_new(void *a1, unsigned int a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x21
  const char *v6; // x22
  __int64 v7; // x19
  __int64 v8; // x8
  _UNKNOWN **i; // x23
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v14; // x22
  __int64 v15; // x0

  v4 = _kmalloc_cache_noprof(_drm_debug, 3520, 48);
  if ( !v4 )
    return -12;
  while ( a2 > 4 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = *(_QWORD *)(StatusReg + 80);
    v15 = _drm_debug;
    *(_QWORD *)(StatusReg + 80) = &msm_smmu_new__alloc_tag;
    v4 = _kmalloc_cache_noprof(v15, 3520, 48);
    *(_QWORD *)(StatusReg + 80) = v14;
    if ( !v4 )
      return -12;
  }
  v5 = (_QWORD *)v4;
  if ( a2 == 4 )
  {
    if ( &smmu_list_lock )
      goto LABEL_6;
    v6 = (const char *)&unk_293238;
    if ( !&unk_293238 )
      goto LABEL_6;
  }
  else
  {
    v8 = (__int64)*(&off_293340 + a2);
    v6 = (const char *)(v8 + 64);
    if ( v8 == -64 )
    {
LABEL_6:
      _drm_dev_dbg(0, 0, 0, "unable to find matching domain for %d\n", a2);
      v7 = -2;
LABEL_21:
      kfree(v5);
      return v7;
    }
  }
  _drm_dev_dbg(0, 0, 0, "found domain %d compat: %s\n", a2, v6);
  mutex_lock(&smmu_list_lock);
  for ( i = (_UNKNOWN **)sde_smmu_list; i != &sde_smmu_list; i = (_UNKNOWN **)*i )
  {
    if ( !strcasecmp(v6, (const char *)*(i - 4)) && *(i - 5) == a1 )
    {
      v10 = (unsigned __int64)(i - 6);
      _drm_dev_dbg(0, 0, 0, "found msm_smmu_client for %s\n", v6);
      goto LABEL_15;
    }
  }
  v10 = -19;
LABEL_15:
  mutex_unlock(&smmu_list_lock);
  v5[5] = v10;
  if ( !v10 || v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    _drm_dev_dbg(0, 0, 0, "unable to find domain %d compat: %s\n", a2, v6);
    v7 = -19;
    goto LABEL_21;
  }
  v11 = *(_QWORD *)v10;
  result = (__int64)v5;
  if ( *(_QWORD *)v10 && v11 < 0xFFFFFFFFFFFFF001LL )
  {
    v5[4] = v11;
    *v5 = funcs;
    v5[1] = a1;
  }
  else
  {
    kfree(v5);
    if ( v11 )
      return v11;
    else
      return -19;
  }
  return result;
}
