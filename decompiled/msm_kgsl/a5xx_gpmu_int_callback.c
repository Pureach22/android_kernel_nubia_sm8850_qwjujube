__int64 __fastcall a5xx_gpmu_int_callback(_QWORD *a1)
{
  __int64 result; // x0
  int v3; // w20
  __int64 v4; // x21
  __int64 i; // x26
  unsigned int v6; // w8
  unsigned __int64 v13; // x8

  result = kgsl_regmap_read(a1 + 1650);
  v3 = result;
  v4 = result & 0x7FFFFFC0;
  if ( (result & 0x7FFFFFC0) != 0 )
  {
    result = __ratelimit(&a5xx_gpmu_int_callback__rs, "a5xx_gpmu_int_callback");
    if ( (_DWORD)result )
      result = dev_crit(*a1, "GPMU: Unknown IRQ mask 0x%08lx in 0x%08x\n", v4, v3);
  }
  for ( i = 0; i != 32; ++i )
  {
    v6 = v3 & (1LL << i);
    if ( v6 > 0x20 || ((1LL << ((unsigned __int8)v3 & (unsigned __int8)(1LL << i))) & 0x100010116LL) == 0 )
    {
      if ( v6 != 0x80000000 )
        continue;
      _X9 = a1 + 1780;
      __asm { PRFM            #0x11, [X9] }
      do
        v13 = __ldxr(_X9);
      while ( __stlxr(v13 & 0xFFFFFFFFFFFFF7FFLL, _X9) );
      __dmb(0xBu);
      if ( (v13 & 0x800) != 0 )
      {
        kgsl_regmap_write(a1 + 1650, 1);
        queue_work_on(32, qword_3A900, a1 + 2575);
      }
    }
    result = __ratelimit(&a5xx_gpmu_int_callback__rs_36, "a5xx_gpmu_int_callback");
    if ( (_DWORD)result )
      result = dev_crit(*a1, "GPMU: interrupt %s(%08lx)\n", gpmu_int_msg[i], 1LL << i);
  }
  return result;
}
