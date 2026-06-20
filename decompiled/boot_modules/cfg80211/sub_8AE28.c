__int64 __fastcall sub_8AE28(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x24

  if ( (v4 & 0x200000000000000LL) == 0 )
    JUMPOUT(0x8BF50);
  return _traceiter_rdev_external_auth(a1, a2, a3, a4);
}
