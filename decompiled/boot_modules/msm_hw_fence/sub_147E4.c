__int64 __fastcall sub_147E4(__int64 _X0)
{
  __asm { LDUMIN          X8, X0, [X29] }
  return hw_fence_utils_reset_queues_helper();
}
