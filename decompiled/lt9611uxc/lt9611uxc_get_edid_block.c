__int64 __fastcall lt9611uxc_get_edid_block(__int64 a1, void *dest, int a3, size_t n)
{
  if ( (unsigned int)(a3 << 7) >= 0x101 )
  {
    __break(0x5512u);
    JUMPOUT(0xA478);
  }
  memcpy(dest, (const void *)(a1 + (unsigned int)(a3 << 7) + 3504), n);
  return 0;
}
