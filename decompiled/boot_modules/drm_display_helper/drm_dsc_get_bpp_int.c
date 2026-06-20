__int64 __fastcall drm_dsc_get_bpp_int(__int64 a1)
{
  unsigned int v1; // w8

  v1 = *(unsigned __int16 *)(a1 + 16);
  if ( (v1 & 0xF) == 0 )
    return v1 >> 4;
  __break(0x800u);
  return *(unsigned __int16 *)(a1 + 16) >> 4;
}
