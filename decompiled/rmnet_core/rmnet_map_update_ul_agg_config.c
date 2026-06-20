__int64 __fastcall rmnet_map_update_ul_agg_config(__int64 a1, unsigned __int16 a2, char a3, char a4, int a5)
{
  _QWORD *v10; // x20
  _QWORD *v11; // x22
  _QWORD *v12; // x8
  _QWORD *v13; // x24
  __int64 v14; // x0
  char v15; // w9
  int v16; // w10
  char v17; // w8
  int v18; // w22
  _QWORD *v19; // x21
  __int64 pages_entry; // x0
  _QWORD *v21; // x1
  _QWORD *v22; // x8
  __int64 result; // x0
  int v24; // [xsp+0h] [xbp-10h] BYREF
  int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock_bh(a1 + 136);
  *(_BYTE *)(a1 + 2) = a3;
  v10 = (_QWORD *)(a1 + 168);
  v11 = *(_QWORD **)(a1 + 168);
  *(_DWORD *)(a1 + 4) = a5;
  *(_WORD *)a1 = a2;
  *(_BYTE *)(a1 + 3) = a4;
  if ( v11 != (_QWORD *)(a1 + 168) )
  {
    do
    {
      v13 = (_QWORD *)*v11;
      v12 = (_QWORD *)v11[1];
      if ( (_QWORD *)*v12 == v11 && (_QWORD *)v13[1] == v11 )
      {
        v13[1] = v12;
        *v12 = v13;
      }
      else
      {
        _list_del_entry_valid_or_report(v11);
      }
      v14 = v11[2];
      *v11 = 0xDEAD000000000100LL;
      v11[1] = 0xDEAD000000000122LL;
      rmnet_mem_put_page_entry(v14);
      kfree(v11);
      v11 = v13;
    }
    while ( v13 != v10 );
  }
  *(_QWORD *)(a1 + 184) = 0;
  if ( a2 >= 0x1000u )
  {
    v15 = 64 - __clz(((unsigned __int64)a2 - 1) >> 12);
    v16 = *(unsigned __int8 *)(a1 + 3);
    v17 = a2 == 4096 ? 0 : v15;
    *(_BYTE *)(a1 + 165) = v17;
    *(_WORD *)a1 = (4096LL << v17) - 384;
    if ( v16 == 1 )
    {
      v18 = 384;
      _ReadStatusReg(SP_EL0);
      do
      {
        v24 = 2;
        v25 = 0;
        v19 = (_QWORD *)_kmalloc_cache_noprof(nla_put, 2336, 24);
        if ( v19 )
        {
          pages_entry = rmnet_mem_get_pages_entry(2080, *(unsigned __int8 *)(a1 + 165), &v25, &v24, 2);
          if ( pages_entry )
          {
            v19[2] = pages_entry;
            *v19 = v19;
            v19[1] = v19;
            v21 = *(_QWORD **)(a1 + 176);
            if ( v19 == v10 || v21 == v19 || (_QWORD *)*v21 != v10 )
            {
              _list_add_valid_or_report(v19, v21, a1 + 168);
            }
            else
            {
              *(_QWORD *)(a1 + 176) = v19;
              *v19 = v10;
              v19[1] = v21;
              *v21 = v19;
            }
          }
          else
          {
            kfree(v19);
          }
        }
        --v18;
      }
      while ( v18 );
      v22 = *(_QWORD **)(a1 + 168);
      if ( v22 == v10 )
        v22 = nullptr;
      *(_QWORD *)(a1 + 184) = v22;
    }
  }
  result = raw_spin_unlock_bh(a1 + 136);
  _ReadStatusReg(SP_EL0);
  return result;
}
