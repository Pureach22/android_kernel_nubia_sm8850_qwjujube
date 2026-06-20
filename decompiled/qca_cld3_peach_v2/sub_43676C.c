__int64 __fastcall sub_43676C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  if ( (a6 & 0x80000000000LL) == 0 )
    JUMPOUT(0x4363B4);
  return dot11f_unpack_link_measurement_report();
}
