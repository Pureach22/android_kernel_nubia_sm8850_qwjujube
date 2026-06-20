__int64 sub_787A8()
{
  __asm { PRFM            #0x1B, unk_14F60C }
  return adreno_regmap_op_preaccess();
}
