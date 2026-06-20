__int64 __fastcall kgsl_regmap_read_indexed(_DWORD *a1, __int64 a2, unsigned int a3, _DWORD *a4, int a5)
{
  __int64 v5; // x22
  int v8; // w23
  __int64 result; // x0
  __int64 v11; // x21
  void (__fastcall **v12)(_QWORD); // x8
  void (__fastcall *v13)(_QWORD); // x8

  LODWORD(v5) = a5;
  v8 = a2;
  result = kgsl_regmap_get_region(a1, a2);
  if ( result )
  {
    v11 = result;
    result = kgsl_regmap_get_region(a1, a3);
    if ( result == v11 )
    {
      v12 = *(void (__fastcall ***)(_QWORD))(v11 + 16);
      if ( v12 )
      {
        v13 = *v12;
        if ( v13 )
        {
          if ( *((_DWORD *)v13 - 1) != -664046789 )
            __break(0x8228u);
          v13(v11);
        }
      }
      result = writel_relaxed_1(0, (unsigned int *)(*(_QWORD *)v11 + (unsigned int)(4 * (v8 - *(_DWORD *)(v11 + 8)))));
      __dsb(0xEu);
      if ( (int)v5 >= 1 )
      {
        v5 = (unsigned int)v5;
        do
        {
          result = readl_relaxed_0((unsigned int *)(*(_QWORD *)v11 + 4 * (a3 - *(_DWORD *)(v11 + 8))));
          --v5;
          *a4++ = result;
        }
        while ( v5 );
      }
      __dsb(0xDu);
    }
  }
  return result;
}
