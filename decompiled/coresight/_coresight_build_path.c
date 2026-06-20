__int64 __fastcall coresight_build_path(__int64 *a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 (*v8)(void); // x8
  unsigned int v9; // w0
  __int64 v10; // x8
  __int64 v11; // x23
  _QWORD *v12; // x9
  __int64 v13; // x0
  __int64 result; // x0
  _QWORD *v16; // x0
  __int64 **v17; // x0
  __int64 *v18; // x2
  __int64 *v19; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v21; // x22
  __int64 v22; // x0

  if ( a1 == (__int64 *)a3 )
  {
LABEL_28:
    result = coresight_grab_device(a1);
    if ( (_DWORD)result )
      return result;
    v17 = (__int64 **)_kmalloc_cache_noprof(put_device, 3520, 24);
    if ( v17 )
      goto LABEL_30;
    return 4294967284LL;
  }
  if ( !a1 || *((_DWORD *)a1 + 2) != 3 || *((_DWORD *)a1 + 3) || *(_DWORD *)(a3 + 8) || *(_DWORD *)(a3 + 12) != 4 )
    goto LABEL_12;
  v8 = **(__int64 (***)(void))(a1[3] + 16);
  if ( *((_DWORD *)v8 - 1) != 335626315 )
    __break(0x8228u);
  v9 = v8();
  if ( v9 < 0x20 )
  {
    if ( *(_QWORD *)((char *)&csdev_sink + _per_cpu_offset[v9]) == a3 && !(unsigned int)coresight_grab_device(a3) )
    {
      v16 = (_QWORD *)_kmalloc_cache_noprof(put_device, 3520, 24);
      if ( v16 )
      {
        *v16 = a3;
        list_add(v16 + 1, a4);
        goto LABEL_28;
      }
    }
LABEL_12:
    v10 = *a1;
    if ( *(int *)(*a1 + 4) < 1 )
      return 4294967277LL;
    v11 = 0;
    while ( 1 )
    {
      v12 = *(_QWORD **)(*(_QWORD *)(v10 + 8) + 8 * v11);
      v13 = v12[2];
      if ( v12[5] )
      {
        if ( v12[6] == a2 && v13 != 0 )
        {
LABEL_15:
          if ( !(unsigned int)coresight_build_path(v13, a2, a3) )
            goto LABEL_28;
          v10 = *a1;
        }
      }
      else if ( v13 )
      {
        goto LABEL_15;
      }
      if ( ++v11 >= *(int *)(v10 + 4) )
        return 4294967277LL;
    }
  }
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  v21 = *(_QWORD *)(StatusReg + 80);
  v22 = put_device;
  *(_QWORD *)(StatusReg + 80) = &coresight_build_path__alloc_tag;
  v17 = (__int64 **)_kmalloc_cache_noprof(v22, 3520, 24);
  *(_QWORD *)(StatusReg + 80) = v21;
  if ( !v17 )
    return 4294967284LL;
LABEL_30:
  v18 = (__int64 *)*a4;
  *v17 = a1;
  v19 = (__int64 *)(v17 + 1);
  if ( (__int64 *)v18[1] != a4 || v19 == a4 || v18 == v19 )
  {
    _list_add_valid_or_report(v17 + 1, a4);
    return 0;
  }
  else
  {
    v18[1] = (__int64)v19;
    v17[1] = v18;
    v17[2] = a4;
    *a4 = (__int64)v19;
    return 0;
  }
}
