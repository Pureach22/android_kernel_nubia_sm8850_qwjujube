__int64 sub_1ACC0()
{
  __int64 v0; // x15

  if ( (v0 & 0x2000000000000000LL) != 0 )
    JUMPOUT(0x1FE1C);
  return msm_hw_fence_update_txq();
}
