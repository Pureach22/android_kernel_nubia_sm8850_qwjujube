__int64 __fastcall qcom_pdm_add_service_domain(__int64 a1, char *s2, const char *a3, int a4)
{
  _QWORD *v4; // x22
  _QWORD *v9; // x19
  _QWORD *v10; // x23
  _QWORD *v12; // x0
  _QWORD *v13; // x1
  __int64 v14; // x0
  _QWORD *v15; // x2
  __int64 *v16; // x1
  _QWORD *v17; // x8
  _QWORD *v18; // x9

  v4 = (_QWORD *)(a1 + 312);
  v9 = (_QWORD *)(a1 + 312);
  do
  {
    v9 = (_QWORD *)*v9;
    if ( v9 == v4 )
      goto LABEL_9;
  }
  while ( strcmp((const char *)v9[4], s2) );
  if ( v9 )
  {
    v10 = v9 + 2;
    while ( 1 )
    {
      v10 = (_QWORD *)*v10;
      if ( v10 == v9 + 2 )
        break;
      if ( !strcmp((const char *)v10[2], a3) )
        return 4294967280LL;
    }
  }
  else
  {
LABEL_9:
    v12 = (_QWORD *)_kmalloc_cache_noprof(qmi_add_server, 3520, 40);
    v9 = v12;
    if ( !v12 )
      return 4294967284LL;
    v12[2] = v12 + 2;
    v12[3] = v12 + 2;
    v13 = *(_QWORD **)(a1 + 320);
    v12[4] = s2;
    if ( v12 == v4 || v13 == v12 || (_QWORD *)*v13 != v4 )
    {
      _list_add_valid_or_report(v12, v13, v4);
    }
    else
    {
      *(_QWORD *)(a1 + 320) = v12;
      *v12 = v4;
      v12[1] = v13;
      *v13 = v12;
    }
  }
  v14 = _kmalloc_cache_noprof(printk, 3520, 32);
  if ( !v14 )
  {
    if ( (_QWORD *)v9[2] == v9 + 2 )
    {
      v17 = (_QWORD *)v9[1];
      if ( (_QWORD *)*v17 == v9 && (v18 = (_QWORD *)*v9, *(_QWORD **)(*v9 + 8LL) == v9) )
      {
        v18[1] = v17;
        *v17 = v18;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      *v9 = 0xDEAD000000000100LL;
      v9[1] = 0xDEAD000000000122LL;
      kfree(v9);
    }
    return 4294967284LL;
  }
  *(_QWORD *)(v14 + 16) = a3;
  v15 = v9 + 2;
  *(_DWORD *)(v14 + 24) = a4;
  v16 = (__int64 *)v9[3];
  if ( (_QWORD *)v14 == v9 + 2 || v16 == (__int64 *)v14 || (_QWORD *)*v16 != v15 )
  {
    _list_add_valid_or_report(v14, v16, v15);
  }
  else
  {
    v9[3] = v14;
    *(_QWORD *)v14 = v15;
    *(_QWORD *)(v14 + 8) = v16;
    *v16 = v14;
  }
  return 0;
}
