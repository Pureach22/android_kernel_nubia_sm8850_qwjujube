__int64 __fastcall dsc_psoc_create(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x1
  _QWORD *v7; // x0
  _QWORD *v8; // x21

  result = 4;
  if ( a1 && a2 )
  {
    *a2 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    {
      v6 = 2336;
    }
    else
    {
      v6 = 2336;
      if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      {
        if ( *(_DWORD *)(StatusReg + 16) )
          v6 = 2336;
        else
          v6 = 3520;
      }
    }
    v7 = (_QWORD *)_kmalloc_cache_noprof(dma_alloc_attrs, v6, 128);
    if ( v7 )
    {
      v7[2] = a1;
      v8 = v7;
      v7[3] = v7 + 3;
      v7[4] = v7 + 3;
      v7[5] = 0;
      _dsc_trans_init(v7 + 6);
      _dsc_ops_init((_DWORD *)v8 + 20);
      _dsc_lock(v8[2]);
      qdf_list_insert_back((_QWORD *)(a1 + 16), v8);
      _dsc_unlock(v8[2]);
      *a2 = v8;
      return 0;
    }
    else
    {
      return 2;
    }
  }
  return result;
}
