__int64 __fastcall map_pcm_format(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x10 )
    return 0;
  else
    return dword_ABD0[a1 - 1];
}
