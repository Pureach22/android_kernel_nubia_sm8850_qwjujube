__int64 __fastcall sub_20164(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x17

  if ( (v3 & 0x100000000LL) != 0 )
    JUMPOUT(0x235A4);
  return rmnet_vnd_dellink(a1, a2, a3);
}
