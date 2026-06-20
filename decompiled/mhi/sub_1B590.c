__int64 __fastcall sub_1B590(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  if ( (a8 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x1AA2C);
  return mhi_controller_get_numeric_id();
}
