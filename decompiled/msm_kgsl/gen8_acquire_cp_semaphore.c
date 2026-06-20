bool __fastcall gen8_acquire_cp_semaphore(__int64 a1)
{
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  kgsl_regmap_write(a1 + 13200, 256);
  __dsb(0xFu);
  if ( (unsigned int)kgsl_regmap_read(a1 + 13200) )
    return 1;
  _const_udelay(42950);
  return (unsigned int)kgsl_regmap_read(a1 + 13200) != 0;
}
