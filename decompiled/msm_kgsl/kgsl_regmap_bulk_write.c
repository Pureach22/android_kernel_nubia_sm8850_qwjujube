__int64 __fastcall kgsl_regmap_bulk_write(_DWORD *a1, __int64 a2, __int64 a3, int a4)
{
  int v6; // w20
  __int64 region; // x0
  void (**v8)(void); // x8
  __int64 v9; // x22
  void (*v10)(void); // x8
  __int64 result; // x0

  v6 = a2;
  region = kgsl_regmap_get_region(a1, a2);
  if ( region )
  {
    v8 = *(void (***)(void))(region + 16);
    v9 = region;
    if ( v8 )
    {
      v10 = *v8;
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != -664046789 )
          __break(0x8228u);
        v10();
      }
    }
    if ( (unsigned int)(a4 + v6 - *(_DWORD *)(v9 + 8)) > *(_DWORD *)(v9 + 12) )
    {
      result = _warn_printk("OUt of bounds bulk write size: 0x%x\n", a4 + v6);
      __break(0x800u);
    }
    else
    {
      __dsb(0xEu);
      return _memcpy_toio(*(_QWORD *)v9 + (unsigned int)(4 * (v6 - *(_DWORD *)(v9 + 8))), a3, 4 * a4);
    }
  }
  else
  {
    result = _warn_printk("Out of bounds register bulk write offset: 0x%x\n", v6);
    __break(0x800u);
  }
  return result;
}
