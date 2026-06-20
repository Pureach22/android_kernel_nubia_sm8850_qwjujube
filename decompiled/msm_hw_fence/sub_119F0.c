__int64 sub_119F0()
{
  __int64 v0; // x23

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x123AC);
  return hw_fence_lookup_and_create_range();
}
