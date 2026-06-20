__int64 __fastcall sub_49C10(__int64 a1)
{
  __int64 v1; // x14

  if ( (v1 & 0x1000000000LL) != 0 )
    JUMPOUT(0x4AA18);
  return walt_lb_tick(a1);
}
