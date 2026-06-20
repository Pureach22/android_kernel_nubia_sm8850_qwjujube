__int64 __fastcall kgsl_regmap_read(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 region; // x0
  void (**v5)(void); // x8
  __int64 v6; // x21
  void (*v7)(void); // x8
  __int64 v8; // x0
  __int64 result; // x0

  v2 = a2;
  region = kgsl_regmap_get_region((_DWORD *)a1, a2);
  if ( region )
  {
    v5 = *(void (***)(void))(region + 16);
    v6 = region;
    if ( v5 )
    {
      v7 = *v5;
      if ( v7 )
      {
        if ( *((_DWORD *)v7 - 1) != -664046789 )
          __break(0x8228u);
        v7();
      }
    }
    v8 = *(_QWORD *)v6 + (unsigned int)(4 * (v2 - *(_DWORD *)(v6 + 8)));
    if ( *(_BYTE *)(a1 + 172) == 1 )
    {
      result = readl_relaxed_0(v8);
      __dsb(0xDu);
    }
    else
    {
      return readl_4(v8);
    }
  }
  else
  {
    _warn_printk("Out of bounds register read offset: 0x%x\n", v2);
    __break(0x800u);
    return 0;
  }
  return result;
}
