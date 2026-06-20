unsigned __int64 __fastcall drm_dp_mst_root_conn_atomic_check(_QWORD *a1)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x8
  unsigned __int64 result; // x0
  __int64 v8; // x8
  unsigned int v9; // w8
  __int64 v10; // x9

  v1 = a1[4];
  v2 = *(_DWORD *)(*a1 + 152LL);
  if ( v2 >= *(_DWORD *)(v1 + 40) )
  {
    v3 = 0;
    v4 = a1[1];
    if ( !v4 )
      goto LABEL_10;
  }
  else
  {
    v3 = *(_QWORD *)(*(_QWORD *)(v1 + 48) + 40LL * v2 + 16);
    v4 = a1[1];
    if ( !v4 )
      goto LABEL_10;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(v1 + 32) + 56LL * *(unsigned int *)(v4 + 160) + 24);
  if ( !v5 || (*(_BYTE *)(v5 + 10) & 0xE) == 0 )
  {
LABEL_10:
    result = 0;
    v8 = *(_QWORD *)(v3 + 8);
    if ( !v8 )
      return 0;
    goto LABEL_11;
  }
  result = drm_atomic_get_private_obj_state(a1[4]);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  *(_DWORD *)(result + 24) |= 1 << *(_DWORD *)(a1[1] + 160LL);
  v8 = *(_QWORD *)(v3 + 8);
  if ( !v8 )
    return 0;
LABEL_11:
  v9 = *(_DWORD *)(v8 + 160);
  v10 = *(_QWORD *)(*(_QWORD *)(v1 + 32) + 56LL * v9 + 24);
  if ( v10 && (*(_BYTE *)(v10 + 10) & 0xE) != 0 )
  {
    if ( !result )
    {
      result = drm_atomic_get_private_obj_state(v1);
      if ( result > 0xFFFFFFFFFFFFF000LL )
        return result;
      v9 = *(_DWORD *)(*(_QWORD *)(v3 + 8) + 160LL);
    }
    *(_DWORD *)(result + 24) |= 1 << v9;
  }
  return 0;
}
