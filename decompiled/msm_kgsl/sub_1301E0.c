__int64 __fastcall sub_1301E0(__int64 a1)
{
  __asm { LDTRSB          X1, [X10,#0x8E] }
  return kgsl_hw_fence_trigger_cpu(a1, _X1);
}
