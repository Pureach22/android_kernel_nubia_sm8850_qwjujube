__int64 __fastcall kgsl_regmap_rmw(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  int v6; // w19
  __int64 region; // x0
  void (**v9)(void); // x8
  __int64 v10; // x21
  void (*v11)(void); // x8
  int v12; // w22
  unsigned int *v13; // x0
  int v14; // w0
  __int64 result; // x0
  int v16; // w0

  v6 = a2;
  region = kgsl_regmap_get_region((_DWORD *)a1, a2);
  if ( region )
  {
    v9 = *(void (***)(void))(region + 16);
    v10 = region;
    if ( v9 )
    {
      v11 = *v9;
      if ( v11 )
      {
        if ( *((_DWORD *)v11 - 1) != -664046789 )
          __break(0x8228u);
        v11();
      }
    }
    v12 = ~a3;
    v13 = (unsigned int *)(*(_QWORD *)v10 + (unsigned int)(4 * (v6 - *(_DWORD *)(v10 + 8))));
    if ( *(_BYTE *)(a1 + 172) == 1 )
    {
      v14 = readl_relaxed_0(v13);
      __dsb(0xFu);
      return writel_relaxed_1(
               v14 & v12 | a4,
               (unsigned int *)(*(_QWORD *)v10 + (unsigned int)(4 * (v6 - *(_DWORD *)(v10 + 8)))));
    }
    else
    {
      v16 = readl_4(v13);
      __dsb(0xFu);
      return writel_0(
               v16 & v12 | a4,
               (unsigned int *)(*(_QWORD *)v10 + (unsigned int)(4 * (v6 - *(_DWORD *)(v10 + 8)))));
    }
  }
  else
  {
    result = _warn_printk("Out of bounds register read-modify-write offset: 0x%x\n", v6);
    __break(0x800u);
  }
  return result;
}
