__int64 __fastcall kgsl_regmap_write(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 region; // x0
  void (**v7)(void); // x8
  __int64 v8; // x21
  void (*v9)(void); // x8
  __int64 result; // x0

  region = kgsl_regmap_get_region((_DWORD *)a1, a3);
  if ( region )
  {
    v7 = *(void (***)(void))(region + 16);
    v8 = region;
    if ( v7 )
    {
      v9 = *v7;
      if ( v9 )
      {
        if ( *((_DWORD *)v9 - 1) != -664046789 )
          __break(0x8228u);
        v9();
      }
    }
    if ( *(_BYTE *)(a1 + 172) == 1 )
    {
      __dsb(0xEu);
      return writel_relaxed_1(a2, *(_QWORD *)v8 + 4 * (a3 - *(_DWORD *)(v8 + 8)));
    }
    else
    {
      return writel_0(a2, *(_QWORD *)v8 + 4 * (a3 - *(_DWORD *)(v8 + 8)));
    }
  }
  else
  {
    result = _warn_printk("Out of bounds register write offset: 0x%x\n", a3);
    __break(0x800u);
  }
  return result;
}
