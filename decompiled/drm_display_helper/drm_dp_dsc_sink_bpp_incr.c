__int64 __fastcall drm_dp_dsc_sink_bpp_incr(__int64 a1)
{
  unsigned __int64 v1; // x8

  v1 = *(unsigned __int8 *)(a1 + 15);
  if ( v1 >= 5 )
    return 0;
  else
    return (unsigned int)(0x102040810uLL >> (8 * (unsigned __int8)v1));
}
