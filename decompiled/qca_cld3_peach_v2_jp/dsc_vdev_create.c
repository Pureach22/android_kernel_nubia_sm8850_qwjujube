__int64 __fastcall dsc_vdev_create(__int64 a1, __int64 *a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 v8; // x21

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
    v7 = _kmalloc_cache_noprof(dma_alloc_attrs, v6, 112);
    if ( v7 )
    {
      *(_QWORD *)(v7 + 16) = a1;
      v8 = v7;
      _dsc_trans_init((_QWORD *)(v7 + 24));
      _dsc_ops_init((_DWORD *)(v8 + 56));
      _dsc_lock(*(_QWORD *)(*(_QWORD *)(v8 + 16) + 16LL));
      qdf_list_insert_back((_QWORD *)(a1 + 24), (_QWORD *)v8);
      _dsc_unlock(*(_QWORD *)(*(_QWORD *)(v8 + 16) + 16LL));
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
