_QWORD *__fastcall gen8_set_gmem_protect(_QWORD *result)
{
  _QWORD *v1; // x19
  unsigned int v2; // w8
  _DWORD *v3; // x12
  char v4; // w9
  unsigned __int64 v5; // x9
  unsigned int v6; // w21
  unsigned __int64 v7; // x27
  unsigned int v8; // w22

  v1 = result;
  v2 = gen8_set_gmem_protect_gmem_protect;
  if ( gen8_set_gmem_protect_gmem_protect )
  {
LABEL_6:
    v4 = 0;
    do
    {
      v5 = (unsigned __int8)((-1LL << v4) & *(_DWORD *)(gen8_set_gmem_protect_gmem_protect + 8));
      if ( !v5 )
        break;
      v6 = *(_DWORD *)(gen8_set_gmem_protect_gmem_protect + 4);
      v7 = __clz(__rbit64(v5));
      v8 = (v7 & 0xF) << 12;
      if ( *((_DWORD *)v1 + 6136) != v8 )
      {
        kgsl_regmap_write(v1 + 1650, v8);
        __dsb(0xFu);
        *((_DWORD *)v1 + 6136) = v8;
      }
      result = (_QWORD *)kgsl_regmap_write(v1 + 1650, v6);
      v4 = v7 + 1;
    }
    while ( v7 < 7 );
    if ( *((_DWORD *)v1 + 6136) )
    {
      result = (_QWORD *)kgsl_regmap_write(v1 + 1650, 0);
      __dsb(0xFu);
      *((_DWORD *)v1 + 6136) = 0;
    }
  }
  else
  {
    while ( 1 )
    {
      v3 = (_DWORD *)(*(_QWORD *)(result[1783] + 168LL) + 12LL * v2);
      if ( *v3 == 36361 )
        break;
      if ( !*v3 )
        return (_QWORD *)dev_err(*result, "RB_GC_GMEM_PROTECT is not defined\n");
      ++v2;
    }
    gen8_set_gmem_protect_gmem_protect = *(_QWORD *)(result[1783] + 168LL) + 12LL * v2;
    if ( v3 )
      goto LABEL_6;
    return (_QWORD *)dev_err(*result, "RB_GC_GMEM_PROTECT is not defined\n");
  }
  return result;
}
