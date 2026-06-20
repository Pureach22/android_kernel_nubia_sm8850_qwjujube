__int64 __fastcall kgsl_regmap_multi_write(__int64 result, unsigned int *a2, int a3)
{
  _DWORD *v4; // x20
  __int64 v5; // x26
  __int64 v6; // x23
  __int64 region; // x0
  __int64 v8; // x22
  void (**v9)(void); // x8
  void (*v10)(void); // x8

  __dsb(0xEu);
  if ( a3 >= 1 )
  {
    v4 = (_DWORD *)result;
    v5 = 0;
    v6 = (unsigned int)a3;
    _ReadStatusReg(SP_EL0);
    do
    {
      region = kgsl_regmap_get_region(v4, *a2);
      if ( region )
      {
        v8 = region;
        if ( region != v5 )
        {
          v9 = *(void (***)(void))(region + 16);
          if ( v9 )
          {
            v10 = *v9;
            if ( v10 )
            {
              if ( *((_DWORD *)v10 - 1) != -664046789 )
                __break(0x8228u);
              v10();
            }
          }
        }
        result = writel_relaxed_1(a2[1], (unsigned int *)(*(_QWORD *)v8 + 4 * (*a2 - *(_DWORD *)(v8 + 8))));
      }
      else
      {
        result = _warn_printk("Out of bounds register write offset: 0x%x\n", *a2);
        __break(0x800u);
        v8 = v5;
      }
      --v6;
      a2 += 2;
      v5 = v8;
    }
    while ( v6 );
  }
  return result;
}
