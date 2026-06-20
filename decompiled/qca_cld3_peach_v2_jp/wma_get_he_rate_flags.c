__int64 __fastcall wma_get_he_rate_flags(int a1)
{
  unsigned int v1; // w8

  if ( a1 )
    v1 = 768;
  else
    v1 = 256;
  if ( a1 == 2 )
    v1 = 1792;
  if ( (unsigned int)(a1 - 3) >= 2 )
    return v1;
  else
    return 3840;
}
