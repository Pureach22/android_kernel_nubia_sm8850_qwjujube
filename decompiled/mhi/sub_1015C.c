__int64 sub_1015C()
{
  __int64 v0; // x15

  if ( (v0 & 0x8000000000LL) != 0 )
    JUMPOUT(0x164D0);
  return mhi_get_mhi_state();
}
