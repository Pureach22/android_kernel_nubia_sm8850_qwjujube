__int64 __fastcall sub_60C090(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x613064);
  return cfg_nan_get_max_ndi(a1, a2);
}
