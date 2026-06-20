__int64 sub_2C14D0()
{
  __int64 v0; // x28

  if ( (v0 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x2BB630);
  return cm_update_wait_for_key_timer();
}
