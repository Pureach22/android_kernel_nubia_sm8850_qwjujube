__int64 __fastcall rmnet_mem_cache_add(__int64 result, char a2)
{
  _QWORD *v2; // x9
  __int64 v3; // x14
  int v4; // w8
  __int64 v5; // x15
  _QWORD *v6; // x11
  int v7; // w20
  _QWORD *v8; // x10
  unsigned __int64 v9; // x21
  int v10; // w23
  _QWORD *v11; // x13
  _QWORD *v12; // x25
  _QWORD *v13; // x12
  _QWORD *v14; // x8
  _QWORD *v15; // x1
  _QWORD *v16; // x2
  _QWORD *v17; // x8
  _QWORD *v18; // x10
  _QWORD *v19; // x11
  _QWORD *v20; // x1

  if ( (unsigned int)result >= 4 )
  {
    __break(0x5512u);
    goto LABEL_44;
  }
  v3 = (unsigned int)result;
  v4 = *((_DWORD *)&static_pool_size + (unsigned int)result);
  if ( v4 && ((a2 & 1) != 0 || !*((_DWORD *)&cache_pool_size + (unsigned int)result)) )
  {
    v5 = 16LL * (unsigned int)result;
    v2 = (_QWORD *)((char *)&rmnet_mem_pool + v5);
    v6 = *(_QWORD **)((char *)&rmnet_mem_pool + v5);
    if ( (_QWORD *)*v2 == v2 )
    {
      v11 = nullptr;
      goto LABEL_32;
    }
    v7 = 0;
    v8 = (_QWORD *)((char *)&rmnet_mem_cache + 16 * (unsigned int)result);
    v9 = v5 | 8;
    v10 = -1;
    do
    {
      v11 = v6 - 1;
      v12 = (_QWORD *)*v6;
      v13 = v6 + 2;
      if ( (_QWORD *)v6[2] == v6 + 2 && *(_DWORD *)(*v11 + 52LL) == 1 )
      {
        v14 = (_QWORD *)v6[1];
        if ( (_QWORD *)*v14 == v6 && (_QWORD *)v12[1] == v6 )
        {
          v12[1] = v14;
          *v14 = v12;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v6);
        }
        *v6 = v6;
        v6[1] = v6;
        if ( v9 > 0x40 )
          goto LABEL_44;
        v15 = (_QWORD *)v2[1];
        if ( v6 == v2 || v15 == v6 || (_QWORD *)*v15 != v2 )
        {
          result = _list_add_valid_or_report(v6);
        }
        else
        {
          v2[1] = v6;
          *v6 = v2;
          v6[1] = v15;
          *v15 = v6;
        }
        v16 = (_QWORD *)*v8;
        ++*((_DWORD *)&cache_pool_size + v3);
        if ( (_QWORD *)v16[1] != v8 || v13 == v8 || v16 == v13 )
        {
          result = _list_add_valid_or_report(v13);
        }
        else
        {
          v16[1] = v13;
          v6[2] = v16;
          v6[3] = v8;
          *v8 = v13;
        }
        v4 = *((_DWORD *)&static_pool_size + v3);
        ++v7;
        ++rmnet_mem_cache_adds[v3];
      }
      if ( ++v10 > v4 >> 3 )
        break;
      if ( *((_DWORD *)&cache_pool_size + v3) > v4 >> 3 )
        break;
      v6 = v12;
    }
    while ( v12 != v2 );
    if ( !v7 )
    {
LABEL_32:
      ++rmnet_mem_cache_add_fails[v3];
      if ( (_QWORD *)v11[2] == v2 )
        return result;
      if ( (v5 | 8uLL) <= 0x40 )
      {
        v17 = (_QWORD *)v2[1];
        v18 = v11 + 1;
        if ( (_QWORD *)*v17 == v2 && (v19 = (_QWORD *)*v2, *(_QWORD **)(*v2 + 8LL) == v2) )
        {
          v19[1] = v17;
          *v17 = v19;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v2);
        }
        v20 = (_QWORD *)v11[2];
        if ( v2 != v18 && v20 != v2 && (_QWORD *)*v20 == v18 )
        {
          v11[2] = v2;
          *v2 = v18;
          v2[1] = v20;
          *v20 = v2;
          return result;
        }
        return _list_add_valid_or_report(v2);
      }
LABEL_44:
      __break(1u);
      return _list_add_valid_or_report(v2);
    }
  }
  return result;
}
