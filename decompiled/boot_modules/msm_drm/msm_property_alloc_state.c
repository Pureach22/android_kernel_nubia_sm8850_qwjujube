__int64 __fastcall msm_property_alloc_state(__int64 a1)
{
  unsigned int v2; // w9
  __int64 v3; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x21

  if ( !a1 )
  {
    _drm_err("invalid property info\n");
    return 0;
  }
  mutex_lock(a1 + 80);
  v2 = *(_DWORD *)(a1 + 76);
  if ( !v2 )
  {
    mutex_unlock(a1 + 80);
    if ( *(_DWORD *)(a1 + 72) )
      goto LABEL_9;
    goto LABEL_10;
  }
  *(_DWORD *)(a1 + 76) = v2 - 1;
  if ( v2 < 3 )
  {
    v3 = *(_QWORD *)(a1 + 8LL * (v2 - 1) + 56);
    mutex_unlock(a1 + 80);
    result = v3;
    if ( v3 )
      return result;
    if ( !*(_DWORD *)(a1 + 72) )
      goto LABEL_10;
LABEL_9:
    result = _kmalloc_noprof(*(unsigned int *)(a1 + 72), 3520);
    if ( result )
      return result;
    goto LABEL_10;
  }
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &msm_property_alloc_state__alloc_tag;
  result = _kmalloc_noprof(*(unsigned int *)(a1 + 72), 3520);
  *(_QWORD *)(StatusReg + 80) = v6;
  if ( !result )
  {
LABEL_10:
    _drm_err("failed to allocate state\n");
    return 0;
  }
  return result;
}
