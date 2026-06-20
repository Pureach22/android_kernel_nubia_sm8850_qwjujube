__int64 __fastcall sub_4014DC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22

  if ( (v4 & 0x20000000000000LL) != 0 )
    JUMPOUT(0x4038C4);
  return lim_send_frame(a1, a2, a3, a4);
}
