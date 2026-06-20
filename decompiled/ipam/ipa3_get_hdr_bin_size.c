__int64 __fastcall ipa3_get_hdr_bin_size(unsigned int a1)
{
  if ( a1 <= 5 )
    return (unsigned int)ipa_hdr_bin_sz[a1];
  else
    return 0xFFFFFFFFLL;
}
