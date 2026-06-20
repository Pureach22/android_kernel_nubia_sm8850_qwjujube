__int64 __fastcall regmap_debugfs_generate_cache(__int64 a1)
{
  _QWORD **v2; // x20
  unsigned int v3; // w20
  unsigned __int64 v4; // x25
  __int64 v5; // x22
  __int64 v6; // x23
  unsigned int v7; // w21
  __int64 *v8; // x1
  __int64 v9; // x0
  _QWORD *i; // x0
  _QWORD *v11; // x8
  __int64 v12; // x9
  _QWORD *v13; // x9

  mutex_lock(a1 + 328);
  v2 = (_QWORD **)(a1 + 312);
  if ( *(_QWORD *)(a1 + 312) != a1 + 312 )
  {
LABEL_2:
    v3 = 0;
    goto LABEL_32;
  }
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (regmap_printable(a1, v7) & 1) == 0 )
    {
      if ( v5 )
      {
        if ( v4 < 0x18 )
          goto LABEL_33;
        *(_QWORD *)(v5 + 24) = v6 - 1;
        *(_DWORD *)(v5 + 36) = v7 - *(_DWORD *)(a1 + 548);
        v8 = *(__int64 **)(a1 + 320);
        if ( (_QWORD **)v5 == v2 || v8 == (__int64 *)v5 || (_QWORD **)*v8 != v2 )
        {
          _list_add_valid_or_report(v5, v8);
          v4 = 0;
          v5 = 0;
        }
        else
        {
          *(_QWORD *)(a1 + 320) = v5;
          *(_QWORD *)v5 = v2;
          v4 = 0;
          *(_QWORD *)(v5 + 8) = v8;
          *v8 = v5;
          v5 = 0;
        }
      }
      else
      {
        v4 = 0;
      }
      goto LABEL_6;
    }
    if ( !v5 )
      break;
LABEL_5:
    v6 += *(unsigned int *)(a1 + 304);
LABEL_6:
    v7 += *(_DWORD *)(a1 + 548);
    if ( v7 > *(_DWORD *)(a1 + 376) )
    {
      if ( !v5 )
        goto LABEL_2;
      if ( v4 < 0x18 )
      {
LABEL_33:
        __break(1u);
      }
      else
      {
        *(_QWORD *)(v5 + 24) = v6 - 1;
        *(_DWORD *)(v5 + 36) = v7 - *(_DWORD *)(a1 + 548);
        v8 = *(__int64 **)(a1 + 320);
        if ( (_QWORD **)v5 != v2 && v8 != (__int64 *)v5 && (_QWORD **)*v8 == v2 )
        {
          *(_QWORD *)(a1 + 320) = v5;
          *(_QWORD *)v5 = v2;
          v3 = 0;
          *(_QWORD *)(v5 + 8) = v8;
          *v8 = v5;
          goto LABEL_32;
        }
      }
      _list_add_valid_or_report(v5, v8);
      v3 = 0;
      goto LABEL_32;
    }
  }
  v9 = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 40);
  v5 = v9;
  if ( v9 )
  {
    v4 = 40;
    *(_QWORD *)(v9 + 16) = v6;
    *(_DWORD *)(v9 + 32) = v7;
    goto LABEL_5;
  }
  for ( i = *v2; *v2 != v2; i = *v2 )
  {
    v11 = (_QWORD *)i[1];
    if ( (_QWORD *)*v11 == i && (v12 = *i, *(_QWORD **)(*i + 8LL) == i) )
    {
      *(_QWORD *)(v12 + 8) = v11;
      *v11 = v12;
    }
    else
    {
      _list_del_entry_valid_or_report(i);
      i = v13;
    }
    *i = 0xDEAD000000000100LL;
    i[1] = 0xDEAD000000000122LL;
    kfree(i);
  }
  v3 = -12;
LABEL_32:
  mutex_unlock(a1 + 328);
  return v3;
}
