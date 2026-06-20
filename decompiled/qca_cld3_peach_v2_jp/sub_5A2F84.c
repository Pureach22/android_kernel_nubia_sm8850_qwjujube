__int64 __fastcall sub_5A2F84(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x5A9F58);
  return cfg_nan_get_ndp_max_sessions(a1, a2);
}
