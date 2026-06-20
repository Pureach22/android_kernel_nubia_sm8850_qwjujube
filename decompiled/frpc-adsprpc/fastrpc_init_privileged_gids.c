__int64 __fastcall fastrpc_init_privileged_gids(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w8
  unsigned __int64 v9; // x23
  __int64 v10; // x22
  unsigned __int64 v11; // x27
  unsigned __int64 v12; // x24
  unsigned int u32_index; // w0
  __int64 v14; // x1
  unsigned int v15; // w8
  unsigned int v16; // w19
  __int64 v17; // x8
  unsigned __int64 StatusReg; // x24
  __int64 v19; // x25
  unsigned int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 744);
  v20 = 0;
  result = of_find_property(v6, a2, &v20);
  if ( result )
  {
    v8 = v20;
    if ( v20 )
    {
      v20 >>= 2;
      v9 = 4LL * (v8 >> 2);
      v10 = _kmalloc_noprof(v9, 3520);
      if ( v10 )
      {
        while ( v20 )
        {
          v11 = 0;
          v12 = 0;
          while ( 1 )
          {
            u32_index = of_property_read_u32_index(*(_QWORD *)(a1 + 744), a2, (unsigned int)v12, v10 + v11);
            if ( u32_index )
            {
              v16 = u32_index;
              dev_err(a1, "%s: failed to read GID %u\n", "fastrpc_init_privileged_gids", v12);
              kfree(v10);
              result = v16;
              goto LABEL_16;
            }
            if ( v9 <= v11 )
              break;
            dev_info(a1, "adsprpc: %s: privileged GID: %u\n", "fastrpc_init_privileged_gids", *(_DWORD *)(v10 + v11));
            v14 = v20;
            ++v12;
            v11 += 4LL;
            if ( v12 >= v20 )
              goto LABEL_12;
          }
          __break(1u);
          v17 = v20;
          StatusReg = _ReadStatusReg(SP_EL0);
          v19 = *(_QWORD *)(StatusReg + 80);
          v9 = 4 * v17;
          *(_QWORD *)(StatusReg + 80) = &fastrpc_init_privileged_gids__alloc_tag;
          v10 = _kmalloc_noprof(4 * v17, 3520);
          *(_QWORD *)(StatusReg + 80) = v19;
          if ( !v10 )
            goto LABEL_15;
        }
        v14 = 0;
LABEL_12:
        sort(v10, v14, 4, uint_cmp_func, 0);
        v15 = v20;
        result = 0;
        *(_QWORD *)a3 = v10;
        *(_DWORD *)(a3 + 8) = v15;
      }
      else
      {
LABEL_15:
        result = 4294967284LL;
      }
    }
    else
    {
      result = 0;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
