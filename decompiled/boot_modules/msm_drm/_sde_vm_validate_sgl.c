__int64 __fastcall sde_vm_validate_sgl(unsigned int *a1, _DWORD *a2)
{
  __int64 v3; // x1
  __int64 v5; // x10
  _QWORD *v6; // x8
  _QWORD *i; // x9
  __int64 v8; // x4
  __int64 v9; // x6

  v3 = *a1;
  if ( (_DWORD)v3 != *a2 )
    return 4294967289LL;
  sort((char *)a2 + 6, v3, 16, _sgl_cmp, 0);
  v5 = *a1;
  if ( !(_DWORD)v5 )
    return 0;
  v6 = (_QWORD *)((char *)a1 + 14);
  for ( i = (_QWORD *)((char *)a2 + 14); ; i += 2 )
  {
    v8 = *(v6 - 1);
    v9 = *(i - 1);
    if ( v8 != v9 )
      break;
    if ( *v6 != *i )
    {
      v9 = *(v6 - 1);
      break;
    }
    --v5;
    v6 += 2;
    if ( !v5 )
      return 0;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "sgl mismatch: (%llu - %llu) vs (%llu - %llu)\n", v8, *v6, v9, *i);
  return 4294967274LL;
}
