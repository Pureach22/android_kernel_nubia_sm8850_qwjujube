__int64 __fastcall hal_get_reo_qdesc_size_peach(unsigned int a1, int a2)
{
  if ( a2 != 16 )
    return 1536;
  if ( a1 < 2 )
    return 128;
  if ( a1 < 0x6A )
    return 256;
  if ( a1 < 0xD3 )
    return 384;
  if ( a1 >= 0x101 )
    return 1536;
  return 512;
}
