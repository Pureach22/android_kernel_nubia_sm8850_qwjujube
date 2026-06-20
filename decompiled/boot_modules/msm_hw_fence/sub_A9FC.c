__int64 __fastcall sub_A9FC(__int64 a1, unsigned __int64 *a2)
{
  __ldxp(a2);
  return hw_fence_debug_wait_val();
}
