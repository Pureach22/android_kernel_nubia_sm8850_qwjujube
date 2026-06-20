__int64 __fastcall sub_60C008(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x612FDC);
  return cfg_nan_get_ndp_max_sessions(a1, a2);
}
