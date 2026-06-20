__int64 __fastcall drm_dp_pcon_dsc_bpp_incr(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_BYTE *)(a1 + 12) & 7;
  if ( (unsigned int)v1 > 4 )
    return 0;
  else
    return dword_1D7D8[v1];
}
