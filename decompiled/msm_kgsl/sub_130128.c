__int64 __fastcall sub_130128(long double a1, long double a2, long double a3, float a4)
{
  LOWORD(a4) = STACK[0x1D92];
  return kgsl_hw_fence_tx_slot_available(a1, a2, a3, a4);
}
