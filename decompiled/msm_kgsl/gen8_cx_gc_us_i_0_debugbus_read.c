__int64 __fastcall gen8_cx_gc_us_i_0_debugbus_read(__int64 a1, __int16 a2, unsigned __int8 a3, _DWORD *a4)
{
  unsigned int v4; // w21
  __int64 result; // x0

  v4 = a3 | ((a2 & 0x1FF) << 16);
  kgsl_regmap_write(a1 + 13200, v4);
  kgsl_regmap_write(a1 + 13200, v4);
  kgsl_regmap_write(a1 + 13200, v4);
  kgsl_regmap_write(a1 + 13200, v4);
  _const_udelay(4295);
  kgsl_regmap_write(a1 + 13200, 6424);
  _const_udelay(4295);
  *a4 = kgsl_regmap_read(a1 + 13200);
  kgsl_regmap_write(a1 + 13200, 6683);
  _const_udelay(4295);
  result = kgsl_regmap_read(a1 + 13200);
  a4[1] = result;
  return result;
}
