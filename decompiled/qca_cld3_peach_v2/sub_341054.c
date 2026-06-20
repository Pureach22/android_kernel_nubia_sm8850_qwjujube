__int64 __fastcall sub_341054(__int64 a1)
{
  if ( (a1 & 0x20000000000000LL) == 0 )
    JUMPOUT(0x33BF68);
  return hdd_cm_disconnect_complete();
}
