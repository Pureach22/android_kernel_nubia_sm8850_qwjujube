__int64 sub_2F4E90()
{
  __int64 v0; // x28

  if ( (v0 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x2EEFF0);
  return cm_update_wait_for_key_timer();
}
