__int64 __fastcall drm_dp_downstream_mode(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  int v3; // w8
  unsigned int v4; // w8
  unsigned int v5; // w8

  if ( (a2[5] & 1) != 0
    && *a2 >= 0x11u
    && (v3 = *a3, (v3 & 7) == 4)
    && (v4 = v3 - 16, v4 <= 0x6F)
    && (v5 = v4 >> 4, ((0x5Fu >> v5) & 1) != 0) )
  {
    return drm_display_mode_from_cea_vic(a1, 0x13060414051506uLL >> (8 * (unsigned __int8)v5));
  }
  else
  {
    return 0;
  }
}
