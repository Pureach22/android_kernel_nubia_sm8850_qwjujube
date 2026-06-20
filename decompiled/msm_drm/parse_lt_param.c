__int64 __fastcall parse_lt_param(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 744);
  v11 = 0;
  result = of_property_count_elems_of_size(v6, a3, 4);
  if ( (_DWORD)result == 16 )
  {
    v8 = devm_kmalloc(a1, 16, 3520);
    *a2 = v8;
    if ( v8 )
    {
      v9 = 0;
      while ( 1 )
      {
        result = of_property_read_u32_index(*(_QWORD *)(a1 + 744), a3, (unsigned int)v9, &v11);
        if ( (_DWORD)result )
          break;
        *(_BYTE *)(*a2 + v9) = v11;
        result = of_property_read_u32_index(*(_QWORD *)(a1 + 744), a3, (unsigned int)(v9 + 1), &v11);
        if ( (_DWORD)result )
          break;
        *(_BYTE *)(*a2 + v9 + 1) = v11;
        result = of_property_read_u32_index(*(_QWORD *)(a1 + 744), a3, (unsigned int)(v9 + 2), &v11);
        if ( (_DWORD)result )
          break;
        *(_BYTE *)(*a2 + v9 + 2) = v11;
        result = of_property_read_u32_index(*(_QWORD *)(a1 + 744), a3, (unsigned int)(v9 + 3), &v11);
        if ( (_DWORD)result )
          break;
        v10 = *a2 + v9;
        v9 += 4;
        *(_BYTE *)(v10 + 3) = v11;
        if ( v9 == 16 )
        {
          result = 0;
          break;
        }
      }
    }
    else
    {
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
