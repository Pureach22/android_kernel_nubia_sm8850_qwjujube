__int64 __fastcall rmnet_mem_add_page(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  int v5; // w11
  char *v6; // x8
  char *v7; // x1
  __int64 v8; // x2
  __int64 v9; // x9
  unsigned __int64 StatusReg; // x21
  __int64 v11; // x22
  __int64 v12; // x0

  result = _kmalloc_cache_noprof(page_pinner_inited, 2336, 48);
  if ( !result )
  {
LABEL_11:
    ++rmnet_mem_err;
    return result;
  }
  while ( 1 )
  {
    if ( a2 > 4u )
    {
      __break(0x5512u);
      goto LABEL_10;
    }
    if ( a2 != 4 )
      break;
LABEL_10:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = *(_QWORD *)(StatusReg + 80);
    v12 = page_pinner_inited;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    result = _kmalloc_cache_noprof(v12, 2336, 48);
    *(_QWORD *)(StatusReg + 80) = v11;
    if ( !result )
      goto LABEL_11;
  }
  v5 = *((_DWORD *)&static_pool_size + a2);
  v6 = (char *)(result + 8);
  *(_BYTE *)(result + 40) = a2;
  *(_QWORD *)result = a1;
  *((_DWORD *)&static_pool_size + a2) = v5 + 1;
  *(_QWORD *)(result + 8) = result + 8;
  v7 = (char *)&rmnet_mem_pool + 16 * a2;
  *(_QWORD *)(result + 16) = result + 8;
  *(_QWORD *)(result + 24) = result + 24;
  *(_QWORD *)(result + 32) = result + 24;
  v8 = *(_QWORD *)v7;
  if ( *(char **)(*(_QWORD *)v7 + 8LL) != v7 || v6 == v7 || (char *)v8 == v6 )
  {
    _list_add_valid_or_report(result + 8);
    return v9;
  }
  else
  {
    *(_QWORD *)(v8 + 8) = v6;
    *(_QWORD *)(result + 8) = v8;
    *(_QWORD *)(result + 16) = v7;
    *(_QWORD *)v7 = v6;
  }
  return result;
}
