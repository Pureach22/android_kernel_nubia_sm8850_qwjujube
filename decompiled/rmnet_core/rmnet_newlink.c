__int64 __fastcall rmnet_newlink(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v8; // x23
  __int64 v9; // x24
  unsigned int v10; // w25
  __int64 v11; // x22
  unsigned int v12; // w0
  unsigned __int64 *v13; // x9
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // t1
  unsigned __int64 v16; // x23
  __int64 v17; // x8
  __int64 v18; // x8
  unsigned __int64 v19; // x9
  unsigned __int64 StatusReg; // x22
  __int64 v21; // x24
  __int64 v22; // x0

  v6 = _dev_get_by_index(a1, *(unsigned int *)(*(_QWORD *)(a3 + 40) + 4LL));
  result = 4294967277LL;
  if ( a2 && v6 )
  {
    if ( a4[1] )
    {
      v8 = _kmalloc_cache_noprof(nla_put, 2336, 32);
      if ( v8 )
      {
        while ( 1 )
        {
          v9 = *(unsigned __int16 *)(a4[1] + 4LL);
          v10 = rmnet_register_real_device(v6);
          if ( v10 )
            goto LABEL_8;
          v11 = *(_QWORD *)(v6 + 272);
          v12 = rmnet_vnd_newlink((unsigned int)v9, a2, v11, v6, v8);
          if ( v12 )
          {
            v10 = v12;
            rmnet_unregister_real_device(v6, v11);
LABEL_8:
            kfree(v8);
            return v10;
          }
          *(_BYTE *)(v11 + 13) = 1;
          if ( (unsigned int)v9 < 0x100 )
          {
            v13 = (unsigned __int64 *)(v11 + 8 * v9);
            v15 = v13[2];
            v13 += 2;
            v14 = v15;
            *(_QWORD *)(v8 + 16) = v15;
            v16 = v8 + 16;
            *(_QWORD *)(v16 + 8) = v13;
            atomic_store(v16, v13);
            if ( v15 )
              *(_QWORD *)(v14 + 8) = v16;
            v17 = a4[2];
            if ( v17 )
              *(_DWORD *)(v11 + 8) = *(_DWORD *)(v11 + 8) & 0x8000000 | *(_DWORD *)(v17 + 8) & *(_DWORD *)(v17 + 4);
            v18 = a4[4];
            if ( !v18 )
              return 0;
            v19 = a4[5];
            if ( !v19 )
              break;
            v19 = *(unsigned __int8 *)(v19 + 4);
            if ( v19 <= 2 )
              break;
          }
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v21 = *(_QWORD *)(StatusReg + 80);
          v22 = nla_put;
          *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
          v8 = _kmalloc_cache_noprof(v22, 2336, 32);
          *(_QWORD *)(StatusReg + 80) = v21;
          if ( !v8 )
            return 4294967284LL;
        }
        rmnet_map_update_ul_agg_config(
          v11 + 200LL * (unsigned int)v19 + 2072,
          *(unsigned __int16 *)(v18 + 4),
          *(unsigned __int8 *)(v18 + 6),
          *(unsigned __int8 *)(v18 + 7),
          *(unsigned int *)(v18 + 8));
        return 0;
      }
      else
      {
        return 4294967284LL;
      }
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
