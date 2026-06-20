__int64 __fastcall sub_77988(__int64 a1)
{
  __asm { LDTRSB          X1, [X10,#0x8E] }
  return adreno_create_hw_fence(a1, _X1);
}
