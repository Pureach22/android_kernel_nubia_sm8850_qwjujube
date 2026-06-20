__int64 __fastcall sub_6C4478(__int64 a1)
{
  char v1; // w16

  if ( (v1 & 4) != 0 )
    JUMPOUT(0x6BF340);
  return wlan_t2lm_timer_stop(a1);
}
