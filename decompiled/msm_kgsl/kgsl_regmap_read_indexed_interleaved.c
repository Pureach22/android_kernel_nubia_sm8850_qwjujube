__int64 __fastcall kgsl_regmap_read_indexed_interleaved(
        _DWORD *a1,
        __int64 a2,
        unsigned int a3,
        _DWORD *a4,
        unsigned int a5,
        int a6)
{
  __int64 v6; // x24
  int v10; // w22
  __int64 result; // x0
  __int64 v13; // x23
  __int64 (__fastcall **v14)(_QWORD); // x8
  __int64 (__fastcall *v15)(_QWORD); // x8

  LODWORD(v6) = a6;
  v10 = a2;
  result = kgsl_regmap_get_region(a1, a2);
  if ( result )
  {
    v13 = result;
    result = kgsl_regmap_get_region(a1, a3);
    if ( result == v13 )
    {
      v14 = *(__int64 (__fastcall ***)(_QWORD))(v13 + 16);
      if ( v14 )
      {
        v15 = *v14;
        if ( v15 )
        {
          if ( *((_DWORD *)v15 - 1) != -664046789 )
            __break(0x8228u);
          result = v15(v13);
        }
      }
      if ( (int)v6 >= 1 )
      {
        v6 = (unsigned int)v6;
        do
        {
          writel_relaxed_1(a5, (unsigned int *)(*(_QWORD *)v13 + (unsigned int)(4 * (v10 - *(_DWORD *)(v13 + 8)))));
          __dsb(0xEu);
          result = readl_relaxed_0((unsigned int *)(*(_QWORD *)v13 + 4 * (a3 - *(_DWORD *)(v13 + 8))));
          *a4++ = result;
          --v6;
          __dsb(0xDu);
          ++a5;
        }
        while ( v6 );
      }
    }
  }
  return result;
}
